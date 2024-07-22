
struct BordaReaderDevice: Codable {
    var connectionStatus: ConnectionStatus
    var name: String?
    var batteryLevel: String?
    var antennaRange: [Int]?
    var readerId: Int?

    enum CodingKeys: String, CodingKey {
        case connectionStatus, name, batteryLevel, antennaRange, readerId
    }
}

enum ConnectionStatus: String, Codable {
    case notConnected
    case connected
    case failed
    case connecting
}
