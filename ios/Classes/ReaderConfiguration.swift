class ReaderConfiguration {
    var api: srfidISdkApi
    var connectedReaderID: Int32?
    var tagHandlerEvent: TagDataEventHandler

    
    init(api: srfidISdkApi, connectedReaderID: Int32?, tagHandlerEvent: TagDataEventHandler
) {
        self.api = api
        self.connectedReaderID = connectedReaderID
        self.tagHandlerEvent = tagHandlerEvent
    }
    
    func configureAntenna(transmitPowerIndex: Int) {
        print("ZebraConnectionHelper -> configureAntenna called with reader ID: \(String(describing: connectedReaderID)) and power index: \(transmitPowerIndex)")
        
        var statusMessage: NSString? = nil
        var antennaConfig: srfidAntennaConfiguration? = srfidAntennaConfiguration() // Declare as optional
        
        // Fetch the current antenna configuration
        let getConfigResult = api.srfidGetAntennaConfiguration(connectedReaderID!, aAntennaConfiguration: &antennaConfig, aStatusMessage: &statusMessage)
        if getConfigResult != SRFID_RESULT_SUCCESS || antennaConfig == nil {
            print("Failed to get antenna configuration: \(statusMessage ?? "No status message")")
            return
        }
        
        
        // Update the configuration
        antennaConfig!.setPower(Int16(transmitPowerIndex))
        antennaConfig!.setLinkProfileIdx(0) // Example index, adjust as necessary
        antennaConfig!.setTari(0) // Example Tari, adjust as necessary
        
        // Set the updated configuration back to the reader
        let result = api.srfidSetAntennaConfiguration(connectedReaderID!, aAntennaConfiguration: antennaConfig!, aStatusMessage: &statusMessage)
        if result == SRFID_RESULT_SUCCESS {
            
            print("Antenna configuration Success!")
        } else {
            print("Antenna configuration Failed!: \(statusMessage ?? "No status message")")
        }
        
        // Optionally, handle setting the antenna range
        setAntennaRange(connectedReaderID!)
    }
    
    private func setAntennaRange(_ readerID: Int32) {
        var statusMessage: NSString? = nil
        var capabilities: srfidReaderCapabilitiesInfo? = srfidReaderCapabilitiesInfo()
        
        // Retrieve the reader capabilities
        let capResult = api.srfidGetReaderCapabilitiesInfo(readerID, aReaderCapabilitiesInfo: &capabilities, aStatusMessage: &statusMessage)
        if capResult != SRFID_RESULT_SUCCESS {
            print("Failed to get reader capabilities: \(statusMessage ?? "No status message")")
            return
        }
        
        
        let antennaRange = [Int(capabilities!.getMinPower()), Int(capabilities!.getMaxPower())]
        print("Antenna Range: \(antennaRange)")
        ReaderResponse.shared.setAntennaRange(antennaRange)
        self.tagHandlerEvent.sendEvent(json: ReaderResponse.shared.toJson())

    }
    
    func configureSingulation() {
        print("ZebraConnectionHelper -> configureSingulation called!");
        
        let singulationConfig = srfidSingulationConfig()
        var statusMessage: NSString? = nil
        
        singulationConfig.setSession(SRFID_SESSION_S0)
        singulationConfig.setTagPopulation(100)
        singulationConfig.setInventoryState(SRFID_INVENTORYSTATE_A)
        singulationConfig.setSlFlag(SRFID_SLFLAG_ALL)
        
        let result = api.srfidSetSingulationConfiguration(connectedReaderID!, aSingulationConfig: singulationConfig, aStatusMessage: &statusMessage)
        if result == SRFID_RESULT_SUCCESS {
            
            print("Singulation configuration Success!")
        } else {
            print("Singulation configuration Failed!: \(statusMessage ?? "No status message")")
        }
    }
    
    func configureDPO(isDynamicPowerEnable: Bool) {
        print("ZebraConnectionHelper -> configureDPO called");
        
        let dpoConfig = srfidDynamicPowerConfig()
        var statusMessage: NSString? = nil
        
        dpoConfig.setDynamicPowerOptimizationEnabled(isDynamicPowerEnable)
        
        let result = api.srfidSetDpoConfiguration(connectedReaderID!, aDpoConfiguration: dpoConfig, aStatusMessage: &statusMessage)
        if result == SRFID_RESULT_SUCCESS {
            
            print("DPO configuration Success!")
        } else {
            print("DPO configuration Failed!: \(statusMessage ?? "No status message")")
        }
    }
    
    func getMaxAntennaPower() -> Int {
        let capabilities: srfidReaderCapabilitiesInfo? = srfidReaderCapabilitiesInfo()
        return Int( (capabilities?.getMaxPower())!) - Int((capabilities?.getMinPower())!)
    }
    
    func configureReader(readerConfig: [String: Any]) {
        print("ZebraConnectionHelper ->  configureReader called!")
        let antennaPower: Int
        if let power = readerConfig["antennaPower"] as? Int {
            antennaPower = power
        } else {
            antennaPower = getMaxAntennaPower()
        }
        
        let beeperVolume: Int = readerConfig["beeperVolume"] as? Int ?? 3
        
        let isDynamicPowerEnable: Bool = readerConfig["isDynamicPowerEnable"] as? Bool ?? false
        
        // Sonuçları yazdır
        print("Antenna Power: \(antennaPower)")
        print("Beeper Volume: \(beeperVolume)")
        print("Is Dynamic Power Enabled: \(isDynamicPowerEnable)")
        print("\n\n ----------- \n\n")
        
        configureAntenna(transmitPowerIndex: antennaPower)
        configureSingulation()
        configureDPO(isDynamicPowerEnable: isDynamicPowerEnable)
        setBeeperVolumeConfig(level: beeperVolume);
        print("\n\n ----------- \n\n")
        
    }
    
    func setBeeperVolumeConfig(level: Int)  {
        print("ZebraConnectionHelper -> setBeeperVolumeConfig called!" )
        guard let volume = BeeperVolume(rawValue: level) else {
            print("Invalid beeper volume level provided.")
            return
        }
        
        let beeperConfig: SRFID_BEEPERCONFIG
        switch volume {
        case .quiet:
            beeperConfig = SRFID_BEEPERCONFIG_QUIET
        case .low:
            beeperConfig = SRFID_BEEPERCONFIG_LOW
        case .medium:
            beeperConfig = SRFID_BEEPERCONFIG_MEDIUM
        case .high:
            beeperConfig = SRFID_BEEPERCONFIG_HIGH
        }
        
        var statusMessage: NSString?
        guard let readerID = connectedReaderID else {
            print("No connected reader ID available.")
            return
        }
        let result = self.api.srfidSetBeeperConfig(readerID, aBeeperConfig: beeperConfig, aStatusMessage: &statusMessage)
        if result == SRFID_RESULT_SUCCESS {
            
            print("Beeper configuration Success!")
        } else {
            print("Beeper configuration Failed!: \(statusMessage ?? "No status message")")
        }
        
        
        
    }
}
