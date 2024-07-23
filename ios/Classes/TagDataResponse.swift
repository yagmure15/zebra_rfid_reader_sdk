import Foundation

class TagDataResponse: Codable {
    var tagId: String
    var lastSeenTime: String

    init(tagId: String, lastSeenTime: String) {
        self.tagId = tagId
        self.lastSeenTime = lastSeenTime
    }

    func toJson() -> String? {
        let encoder = JSONEncoder()
        encoder.outputFormatting = .prettyPrinted
        if let jsonData = try? encoder.encode(self) {
            return String(data: jsonData, encoding: .utf8)
        }
        return nil
    }
}
