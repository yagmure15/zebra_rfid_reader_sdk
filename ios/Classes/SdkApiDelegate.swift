import UIKit

class SdkApiDelegate: NSObject, srfidISdkApiDelegate {
    
    
    let api: srfidISdkApi
    var tagHandlerEvent: TagDataEventHandler
    var readTagEvent: TagDataEventHandler
    var tagFindingEvent: TagDataEventHandler
    
    
    init(api: srfidISdkApi, tagHandlerEvent: TagDataEventHandler, readTagEvent: TagDataEventHandler, tagFindingEvent: TagDataEventHandler) {
        self.api = api
        self.tagHandlerEvent = tagHandlerEvent
        self.readTagEvent = readTagEvent
        self.tagFindingEvent = tagFindingEvent
        super.init()
        print("SdkApiDelegate const ")
    }
    
    func srfidEventMultiProximityNotify(_ readerID: Int32, aTagData tagData: srfidTagData!) {
        print("srfidEventMultiProximityNotify")
    }
    
    func srfidEventWifiScan(_ readerID: Int32, wlanSCanObject wlanScanObject: srfidWlanScanList!) {
        print("srfidEventWifiScan")
    }
    
    func srfidEventReaderAppeared(_ availableReader: srfidReaderInfo!) {
        print("srfidEventReaderAppeared")
    }
    
    func srfidEventReaderDisappeared(_ readerID: Int32) {
        print("srfidEventReaderDisappeared")
    }
    
    func srfidEventCommunicationSessionEstablished(_ activeReader: srfidReaderInfo!) {
        print("srfidEventCommunicationSessionEstablished")
        
        // Setup ASCII connection to get reader information
        asciiConnection(readerID: activeReader.getReaderID())
        
        // Request battery status
        requestBatteryStatus(readerID: activeReader.getReaderID())
        
        
        DispatchQueue.main.asyncAfter(deadline: .now() + 0.5) {
            let readerConfigurator = ReaderConfiguration(api: self.api, connectedReaderID: activeReader.getReaderID(), tagHandlerEvent: self.tagHandlerEvent)
            readerConfigurator.configureReader(readerConfig: ["antennaPower": 300, "beeperVolume": 3, "isDynamicPowerEnable": true])
            // Connection established
            ReaderResponse.shared.setConnectionStatus(.connected)
            ReaderResponse.shared.setName(activeReader.getReaderName())
            ReaderResponse.shared.setReaderId(Int(activeReader.getReaderID()))
            self.tagHandlerEvent.sendEvent(json: ReaderResponse.shared.toJson())
            
        }
    }
    
    func srfidEventCommunicationSessionTerminated(_ readerID: Int32) {
        print("srfidEventCommunicationSessionTerminated")
        
        ReaderResponse.shared.reset()
        tagHandlerEvent.sendEvent(json: ReaderResponse.shared.toJson())
    }
    
    func srfidEventReadNotify(_ readerID: Int32, aTagData tagData: srfidTagData!) {
        print("srfidEventReadNotify")
        
        // Process tag read data
        let tagId = tagData.getTagId() ?? ""
        let timestamp = Date().description
        
        // Print tag data
        print("Tag ID: \(tagId), Timestamp: \(timestamp)")
        
        // Create TagDataResponse object
        let tagDataResponse = TagDataResponse(tagId: tagId, lastSeenTime: timestamp)
        
        // Convert TagDataResponse to JSON and send to Flutter
        if let jsonString = tagDataResponse.toJson() {
            readTagEvent.sendEvent(json: jsonString)
        }
    }
    
    
    func srfidEventStatusNotify(_ readerID: Int32, aEvent event: SRFID_EVENT_STATUS, aNotification notificationData: Any!) {
        print("srfidEventStatusNotify")
    }
    
    func srfidEventProximityNotify(_ readerID: Int32, aProximityPercent proximityPercent: Int32) {
        print("srfidEventProximityNotify")
        TagLocationingResponse.shared.setDistancePercent(distancePercent: Int(proximityPercent))
        self.tagFindingEvent.sendEvent(json: TagLocationingResponse.shared.toJson()!)
    }
    
    func srfidEventTriggerNotify(_ readerID: Int32, aTriggerEvent triggerEvent: SRFID_TRIGGEREVENT) {
        print("srfidEventTriggerNotify")
        if triggerEvent == SRFID_TRIGGEREVENT_PRESSED {
            // Start inventory when the trigger is pressed
            startInventory(readerID: readerID)
        } else if triggerEvent == SRFID_TRIGGEREVENT_RELEASED {
            // Stop inventory when the trigger is released
            stopInventory(readerID: readerID)
        }
    }
    
    func asciiConnection(readerID: Int32){
        print("asciiConnection")
        let status = api.srfidEstablishAsciiConnection(readerID, aPassword: "")
        switch status {
        case SRFID_RESULT_SUCCESS:
            print("srfidEstablishAsciiConnection success")
            
        default:
            print("srfidEstablishAsciiConnection error")
        }
    }
    
    func srfidEventBatteryNotity(_ readerID: Int32, aBatteryEvent batteryEvent: srfidBatteryEvent!) {
        print("srfidEventBatteryNotity")
        
        // Process battery event data
        let batteryLevel = batteryEvent.getPowerLevel()
        let chargingStatus = batteryEvent.getIsCharging()
        
        ReaderResponse.shared.setBatteryLevel(String(batteryLevel))
        tagHandlerEvent.sendEvent(json: ReaderResponse.shared.toJson())
    }
    
    func startInventory(readerID: Int32) {
        
        DispatchQueue.global(qos: .userInitiated).async {
            print("SdkApiDelegate -> startInventory")
            
            var statusMessage: NSString? = nil
            let reportConfig = srfidReportConfig()
            let accessConfig = srfidAccessConfig()
            
            let triggerMode = BordaHandheldTrigger.shared.getMode()
            
            if triggerMode == .inventoryPerform {
                // Start inventory reading
                
                let result = self.api.srfidStartInventory(readerID, aMemoryBank: SRFID_MEMORYBANK_EPC, aReportConfig: reportConfig, aAccessConfig: accessConfig, aStatusMessage: &statusMessage)
                
                
                print("Start Inventory result: \(result.rawValue), status message: \(statusMessage ?? "No status message")")
                
            } else if triggerMode == .tagLocationingPerform {
                let tagLocationing = TagLocationingResponse.shared.getTag()
                let result = self.api.srfidStartTagLocationing(readerID, aTagEpcId: tagLocationing, aStatusMessage: &statusMessage)
                
                
                print("Start Tag Locationing result: \(result.rawValue), status message: \(statusMessage ?? "No status message")")
                
            }
            
        }
    }
    
    
    func stopInventory(readerID: Int32) {
        DispatchQueue.global(qos: .userInitiated).async {
            print("SdkApiDelegate -> stopInventory")
            
            var statusMessage: NSString? = nil
            let triggerMode = BordaHandheldTrigger.shared.getMode()
            
            if triggerMode == .inventoryPerform {
                // Stop inventory reading
                let result = self.api.srfidStopInventory(readerID, aStatusMessage: &statusMessage)
                
                
                print("Stop Inventory result: \(result.rawValue), status message: \(statusMessage ?? "No status message")")
                
            } else if triggerMode == .tagLocationingPerform {
                // Stop tag locationing
                let result = self.api.srfidStopTagLocationing(readerID, aStatusMessage: &statusMessage)
                
                
                print("Stop Tag Locationing result: \(result.rawValue), status message: \(statusMessage ?? "No status message")")
                
            }
        }
    }
    
    func getReaderCapabilities(readerID: Int32) {
        DispatchQueue.global(qos: .userInitiated).async {
            print("getReaderCapabilities")
            var readerCapabilities: srfidReaderCapabilitiesInfo? = srfidReaderCapabilitiesInfo()
            var statusMessage: NSString? = nil
            
            let status = self.api.srfidGetReaderCapabilitiesInfo(readerID, aReaderCapabilitiesInfo: &readerCapabilities, aStatusMessage: &statusMessage)
            DispatchQueue.main.async {
                print("Status: \(status)")
                print("Status: \(status.rawValue), Status Message: \(statusMessage ?? "No status message")")
                
                if status == SRFID_RESULT_SUCCESS, let capabilities = readerCapabilities {
                    let capabilitiesData = [
                        "getMaxPower": capabilities.getMaxPower(),
                        "getMinPower": capabilities.getMinPower()
                    ] as [String : Any]
                    
                    do {
                        let jsonData = try JSONSerialization.data(withJSONObject: capabilitiesData, options: [])
                        if let jsonString = String(data: jsonData, encoding: .utf8) {
                            print(jsonString)
                        } else {
                            print("JSON string conversion failed")
                        }
                    } catch {
                        print("JSON serialization failed: \(error.localizedDescription)")
                    }
                } else {
                    print("Failed to get reader capabilities: \(statusMessage ?? "No status message")")
                }
            }
        }
    }
    
    func requestBatteryStatus(readerID: Int32) {
        DispatchQueue.global(qos: .userInitiated).async {
            print("requestBatteryStatus")
            let result = self.api.srfidRequestBatteryStatus(readerID)
            DispatchQueue.main.async {
                print("RequestBatteryStatus result: \(result.rawValue)")
                if result == SRFID_RESULT_SUCCESS {
                    print("RequestBatteryStatus succeeded")
                } else {
                    print("RequestBatteryStatus failed")
                }
            }
        }
    }
}
