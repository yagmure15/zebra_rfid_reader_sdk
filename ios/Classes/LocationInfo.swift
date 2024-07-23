import Foundation

class LocationInfo: Codable {
    var tag: String?
    var distanceAsPercentage: Int?
    var isAnyReaderConnected: Bool?
    
    init(tag: String?, distanceAsPercentage: Int?, isAnyReaderConnected: Bool?) {
        self.tag = tag
        self.distanceAsPercentage = distanceAsPercentage
        self.isAnyReaderConnected = isAnyReaderConnected
    }
}
