import UIKit
import Flutter

class ZebraConnectionHelper: NSObject {
    let api: srfidISdkApi
    let delegate: SdkApiDelegate
    var tagHandlerEvent: TagDataEventHandler
    var readTagEvent: TagDataEventHandler
    var tagFindingEvent: TagDataEventHandler
    
    var connectedReaderID: Int32?
    
    init(api: srfidISdkApi, delegate: SdkApiDelegate, tagHandlerEvent: TagDataEventHandler, tagFindingEvent: TagDataEventHandler, readTagEvent: TagDataEventHandler) {
        self.api = api
        self.delegate = delegate
        self.tagHandlerEvent = tagHandlerEvent
        self.readTagEvent = readTagEvent
        self.tagFindingEvent = tagFindingEvent
        
        super.init()
        
        self.subscribeSdkApi()
    }
    
    func disconnect(readerID: Int32) {
        print("ZebraConnectionHelper -> disconnect method called!" )
        let status = api.srfidTerminateCommunicationSession(readerID)
        switch status {
        case SRFID_RESULT_SUCCESS:
            print("Disconnected")
        default:
            print("Disconnection error")
        }
    }
    
    func disconnect() {
        print("ZebraConnectionHelper -> disconnect with no parameter method called!" )
        if connectedReaderID != nil {
            let status = api.srfidTerminateCommunicationSession(connectedReaderID!)
            switch status {
            case SRFID_RESULT_SUCCESS:
                print("Disconnected")
            default:
                print("Disconnection error")
            }
        }
    }
    
    func findTheTag(tag: String) {
        print("ZebraConnectionHelper -> findTheTag called!")
        
        DispatchQueue.global(qos: .userInitiated).async {
            if self.connectedReaderID != nil {
                BordaHandheldTrigger.shared.setMode(triggerMode: .tagLocationingPerform)
                TagLocationingResponse.shared.setTag(tag: tag)
                TagLocationingResponse.shared.setAnyReaderConnected(isAnyReaderConnected: true)
                self.tagFindingEvent.sendEvent(json: TagLocationingResponse.shared.toJson()!)
                
            } else {
                print("findTheTag error: Reader ID is nil")
            }
        }
    }
    
    
    func stopFindingTheTag() {
        print("ZebraConnectionHelper -> stopFindingTheTag called!")
        
        DispatchQueue.global(qos: .userInitiated).async {
            if self.connectedReaderID != nil {
                BordaHandheldTrigger.shared.setMode(triggerMode: .inventoryPerform)
                TagLocationingResponse.shared.reset()
                self.tagFindingEvent.sendEvent(json: TagLocationingResponse.shared.toJson()!)
                
                var statusMessage: NSString? = nil
                let status = self.api.srfidStopTagLocationing(self.connectedReaderID!, aStatusMessage: &statusMessage)
                
                switch status {
                case SRFID_RESULT_SUCCESS:
                    print("stopFindingTheTag stopped successfully")
                default:
                    print("stopFindingTheTag error: \(statusMessage ?? "No status message")")
                }
            } else {
                print("stopFindingTag error: Reader ID is nil")
            }
        }
    }
    
    func setAntennaPower(transmitPowerIndex: Int){
        let readerConfigurator = ReaderConfiguration(api: self.api, connectedReaderID: connectedReaderID, tagHandlerEvent: self.readTagEvent)
        readerConfigurator.configureAntenna(transmitPowerIndex: transmitPowerIndex)
    }
    func setDynamicPower(isEnable: Bool){
        let readerConfigurator = ReaderConfiguration(api: self.api, connectedReaderID: connectedReaderID, tagHandlerEvent: self.readTagEvent)
        readerConfigurator.configureDPO(isDynamicPowerEnable: isEnable)
    }
    
    func setBeeperVolumeConfig(level: Int){
        let readerConfigurator = ReaderConfiguration(api: self.api, connectedReaderID: connectedReaderID, tagHandlerEvent: self.readTagEvent)
        readerConfigurator.setBeeperVolumeConfig(level: level)
    }
    
    func connect(name: String, readerConfig: [String: Any]) {
        print("ZebraConnectionHelper -> connect method called!")
        
        // Existing connection check and disconnection
        if let connectedID = connectedReaderID {
            disconnect(readerID: connectedID)
            connectedReaderID = nil
        }
        let readerID = getReaderIdByName(name: name)
        
        ReaderResponse.shared.setConnectionStatus(.connecting)
        ReaderResponse.shared.setReaderId(Int(readerID))
        tagHandlerEvent.sendEvent(json: ReaderResponse.shared.toJson())
        
        
        let status = api.srfidEstablishCommunicationSession(Int32(readerID))
        
        switch status {
        case SRFID_RESULT_SUCCESS:
            print("Connected")
            // Save the connected reader ID
            connectedReaderID = Int32(readerID)
            // Send informations to flutter side
            ReaderResponse.shared.setConnectionStatus(.connected)
            ReaderResponse.shared.setReaderId(Int(readerID))
            tagHandlerEvent.sendEvent(json: ReaderResponse.shared.toJson())
            
        default:
            print("Connection error")
            print("trying to disconnect for any devices")
            disconnect(readerID: Int32(readerID))
            
        }
    }
    
    
    func getReaderIdByName(name: String) -> Int32 {
        var availableReaders: NSMutableArray? = NSMutableArray()
        var activeReaders: NSMutableArray? = NSMutableArray()
        
        api.srfidGetAvailableReadersList(&availableReaders)
        api.srfidGetActiveReadersList(&activeReaders)
        
        let combinedReaders = (availableReaders as? [srfidReaderInfo] ?? []) + (activeReaders as? [srfidReaderInfo] ?? [])
        
        for reader in combinedReaders {
            if reader.getReaderName() == name {
                return reader.getReaderID()
            }
        }
        return -1
    }
    
    func getAvailableReaderList(api: srfidISdkApi, result: @escaping FlutterResult) {
        print("ZebraConnectionHelper -> getAvailableReaderList called")
        var availableReaders: NSMutableArray? = NSMutableArray()
        var activeReaders: NSMutableArray? = NSMutableArray()
        
        let availableStatus = api.srfidGetAvailableReadersList(&availableReaders)
        let activeStatus = api.srfidGetActiveReadersList(&activeReaders)
        
        if availableStatus != SRFID_RESULT_SUCCESS || activeStatus != SRFID_RESULT_SUCCESS {
            result(FlutterError(code: "READER_ERROR", message: "Failed to get readers list", details: nil))
            return
        }
        
        let combinedReaders = (availableReaders as? [srfidReaderInfo] ?? []) + (activeReaders as? [srfidReaderInfo] ?? [])
        
        if combinedReaders.count > 0 {
            for reader in combinedReaders {
                print("Reader Name: \(reader.getReaderName() ?? "Unknown")")
                print("Reader ID: \(reader.getReaderID())")
            }
        } else {
            print("No readers found")
        }
        
        let bordaDevices = combinedReaders.map { readerInfo -> BordaReaderDevice in
            let connectionStatus = readerInfo.getConnectionType() == 0 ? ConnectionStatus.connected : ConnectionStatus.notConnected
            return BordaReaderDevice(connectionStatus: connectionStatus, name: readerInfo.getReaderName(), readerId: Int(readerInfo.getReaderID()))
        }
        
        do {
            let jsonData = try JSONEncoder().encode(bordaDevices)
            result(String(data: jsonData, encoding: .utf8))
        } catch {
            result(FlutterError(code: "ENCODING_ERROR", message: "Failed to encode reader data", details: nil))
        }
    }
    
    
    
    func subscribeSdkApi() {
        print("ZebraConnectionHelper -> subscribeSdkApi called!")
        api.srfidSetOperationalMode(Int32(SRFID_OPMODE_MFI))
        
        
        
        
        api.srfidSubsribe(forEvents: Int32(SRFID_EVENT_READER_APPEARANCE) | Int32(SRFID_EVENT_READER_DISAPPEARANCE) | Int32(SRFID_EVENT_SESSION_ESTABLISHMENT) | Int32(SRFID_EVENT_SESSION_TERMINATION))
        api.srfidSubsribe(forEvents: Int32(SRFID_EVENT_MASK_READ) | Int32(SRFID_EVENT_MASK_STATUS) | Int32(SRFID_EVENT_MASK_STATUS_OPERENDSUMMARY))
        api.srfidSubsribe(forEvents: Int32(SRFID_EVENT_MASK_TEMPERATURE) | Int32(SRFID_EVENT_MASK_POWER) | Int32(SRFID_EVENT_MASK_DATABASE))
        api.srfidSubsribe(forEvents: Int32(SRFID_EVENT_MASK_PROXIMITY) | Int32(SRFID_EVENT_MASK_TRIGGER) | Int32(SRFID_EVENT_MASK_BATTERY))
        api.srfidEnableAvailableReadersDetection(true)
        api.srfidEnableAutomaticSessionReestablishment(false)
        api.srfidSetDelegate(delegate)
    }
}

enum BeeperVolume: Int {
    case quiet = 0
    case low = 1
    case medium = 2
    case high = 3
}
