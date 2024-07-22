import Foundation

class ReaderResponse {
    static let shared = ReaderResponse()

    private var connectionStatus: ConnectionStatus = .notConnected
    private var name: String?
    private var batteryLevel: String?
    private var antennaRange: [Int]?
    private var readerId: Int?

    private init() {}

    func setConnectionStatus(_ connectionStatus: ConnectionStatus) {
        self.connectionStatus = connectionStatus
    }

    func setName(_ name: String?) {
        self.name = name
    }

    func setBatteryLevel(_ batteryLevel: String?) {
        self.batteryLevel = batteryLevel
    }

    func setAntennaRange(_ antennaRange: [Int]?) {
        self.antennaRange = antennaRange
    }

    func setReaderId(_ readerId: Int?) {
        self.readerId = readerId
    }

    func reset() {
        self.batteryLevel = nil
        self.connectionStatus = .notConnected
        self.name = nil
        self.antennaRange = nil
        self.readerId = nil
    }

    func setAsConnectionError() {
        self.batteryLevel = nil
        self.connectionStatus = .failed
    }

    func toJson() -> String {
        let bordaReaderDevice = BordaReaderDevice(
            connectionStatus: connectionStatus,
            name: name,
            batteryLevel: batteryLevel,
            antennaRange: antennaRange,
            readerId: readerId
        )
        let jsonData = try! JSONEncoder().encode(bordaReaderDevice)
        return String(data: jsonData, encoding: .utf8) ?? ""
    }
}
