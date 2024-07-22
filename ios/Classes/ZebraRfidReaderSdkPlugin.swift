import Flutter
import UIKit

public class ZebraRfidReaderSdkPlugin: NSObject, FlutterPlugin {
  var zebraConnectionHelper: ZebraConnectionHelper!
  var apiDelegate: SdkApiDelegate!
  var tagHandlerEvent: TagDataEventHandler!
  var readTagEvent: TagDataEventHandler!
  var tagFindingEvent: TagDataEventHandler!
  let api: srfidISdkApi = ZebraApi.shared

  public static func register(with registrar: FlutterPluginRegistrar) {
    let channel = FlutterMethodChannel(name: "borda/zebra_rfid_reader_sdk", binaryMessenger: registrar.messenger())
    let instance = ZebraRfidReaderSdkPlugin()
    registrar.addMethodCallDelegate(instance, channel: channel)
    instance.initializeSdkComponents()
    instance.setupEventChannels(with: registrar.messenger())
   
  }

  private func setupEventChannels(with messenger: FlutterBinaryMessenger) {
    let tagHandlerEventChannel = FlutterEventChannel(name: "tagHandlerEvent", binaryMessenger: messenger)
    tagHandlerEventChannel.setStreamHandler(tagHandlerEvent)
    
    let readTagEventChannel = FlutterEventChannel(name: "readTagEvent", binaryMessenger: messenger)
    readTagEventChannel.setStreamHandler(readTagEvent)

    let tagFindingEventChannel = FlutterEventChannel(name: "tagFindingEvent", binaryMessenger: messenger)
    tagFindingEventChannel.setStreamHandler(tagFindingEvent)
  }

  private func initializeSdkComponents() {
    tagHandlerEvent = TagDataEventHandler()
    readTagEvent = TagDataEventHandler()
    tagFindingEvent = TagDataEventHandler()
    
    apiDelegate = SdkApiDelegate(api: api, tagHandlerEvent: tagHandlerEvent, readTagEvent: readTagEvent, tagFindingEvent: tagFindingEvent)
    
    zebraConnectionHelper = ZebraConnectionHelper(api: api, delegate: apiDelegate, tagHandlerEvent: tagHandlerEvent, tagFindingEvent: tagFindingEvent, readTagEvent: readTagEvent)
  }

  public func handle(_ call: FlutterMethodCall, result: @escaping FlutterResult) {
    switch call.method {
 case "getAvailableReaderList":
                self.zebraConnectionHelper.getAvailableReaderList(api: self.api, result: result)
            case  "disconnect" :
                self.zebraConnectionHelper.disconnect()

            case "setAntennaPower":
                    if let transmitPowerIndex = call.arguments as? [String: Any],
                       let powerIndex = transmitPowerIndex["transmitPowerIndex"] as? Int {
                        self.zebraConnectionHelper.setAntennaPower(transmitPowerIndex: powerIndex)
                    } else {
                        result(FlutterError(code: "INVALID_ARGUMENT", message: "Missing or invalid argument: transmitPowerIndex", details: nil))
                    }

            case "setDynamicPower":
                    if let args = call.arguments as? [String: Any],
                       let isEnable = args["isEnable"] as? Bool {
                        self.zebraConnectionHelper.setDynamicPower(isEnable: isEnable)
                    } else {
                        result(FlutterError(code: "INVALID_ARGUMENT", message: "Missing or invalid argument: isEnable", details: nil))
                    }
                case "setBeeperVolume":
                    if let args = call.arguments as? [String: Any],
                       let level = args["level"] as? Int {
                        self.zebraConnectionHelper.setBeeperVolumeConfig(level:level)
                    } else {
                        result(FlutterError(code: "INVALID_ARGUMENT", message: "Missing or invalid argument: level", details: nil))
                    }
            case "connect":
                if let args = call.arguments as? [String: Any], let name = args["name"] as? String, let readerConfig = args["readerConfig"] as? [String: Any] {
                    print("Flutter -> connect called with name: \(name)")
                    print("Flutter -> USER CONFIG: \(readerConfig)")
                    self.zebraConnectionHelper.connect(name: name, readerConfig: readerConfig)
                } else {
                    result(FlutterError(code: "BAD_ARGS", message: "Required arguments 'name' or 'readerConfig' not provided", details: nil))
                }
            case "findTheTag":
                if let args = call.arguments as? [String: Any], let tag = args["tag"] as? String {
                    self.zebraConnectionHelper.findTheTag(tag: tag)
                } else {
                    result(FlutterError(code: "BAD_ARGS", message: "No tag provided", details: nil))
                }
            case "stopFindingTheTag":
                self.zebraConnectionHelper.stopFindingTheTag()
            default:
                result(FlutterMethodNotImplemented)
            }
  }
}
