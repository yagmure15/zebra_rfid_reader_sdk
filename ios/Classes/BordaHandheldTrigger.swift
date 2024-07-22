import Foundation

class BordaHandheldTrigger {
    static let shared = BordaHandheldTrigger()
    
    private var mode: TriggerMode = .inventoryPerform

    private init() {}
    
    func setMode(triggerMode: TriggerMode) {
        self.mode = triggerMode
    }
    
    func getMode() -> TriggerMode {
        return mode
    }
}

enum TriggerMode {
    case inventoryPerform
    case tagLocationingPerform
}
