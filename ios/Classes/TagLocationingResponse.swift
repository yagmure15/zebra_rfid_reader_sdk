import Foundation

class TagLocationingResponse {
    static let shared = TagLocationingResponse()
    
    private var tag: String = ""
    private var distancePercent: Int? = nil
    private var isAnyReaderConnected: Bool = false

    private init() {}
    
    func setTag(tag: String) {
        self.tag = tag
    }
    
    func getTag() -> String {
        return tag
    }
    
    func setAnyReaderConnected(isAnyReaderConnected: Bool) {
        self.isAnyReaderConnected = isAnyReaderConnected
    }
    
    func setDistancePercent(distancePercent: Int?) {
        self.distancePercent = distancePercent
    }
    
    func reset() {
        self.tag = ""
        self.isAnyReaderConnected = false
        self.distancePercent = nil
    }
    
    func toJson() -> String? {
        let locationInfo = LocationInfo(tag: tag, distanceAsPercentage: distancePercent, isAnyReaderConnected: isAnyReaderConnected)
        let jsonEncoder = JSONEncoder()
        if let jsonData = try? jsonEncoder.encode(locationInfo) {
            return String(data: jsonData, encoding: .utf8)
        }
        return nil
    }
}
