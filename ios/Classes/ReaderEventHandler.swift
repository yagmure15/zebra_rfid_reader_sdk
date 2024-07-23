import Foundation
import Flutter

class TagDataEventHandler: NSObject, FlutterStreamHandler {
    private var eventSink: FlutterEventSink?
    private let uiThreadHandler = DispatchQueue.main

    func onListen(withArguments arguments: Any?, eventSink events: @escaping FlutterEventSink) -> FlutterError? {
        self.eventSink = events
        print("Event channel listening")
        return nil
    }

    func onCancel(withArguments arguments: Any?) -> FlutterError? {
        self.eventSink = nil
        print("Event channel cancelled")
        return nil
    }

    func sendEvent(json: String) {
        guard let eventSink = eventSink else { return }
        uiThreadHandler.async {
            eventSink(json)
        }
    }
}
