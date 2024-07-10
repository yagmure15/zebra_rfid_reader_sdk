import 'package:zebra_rfid_reader_sdk/src/models/reader_config.dart';
import 'package:zebra_rfid_reader_sdk/src/models/reader_device.dart';

import 'zebra_rfid_reader_sdk_platform_interface.dart';

/// This class provides a convenient interface for interacting with Zebra RFID readers using the plugin.
///
/// It delegates calls to the platform-specific implementation via the `ZebraRfidReaderSdkPlatform`.
class ZebraRfidReaderSdk {
  /// Connects to a Zebra RFID reader with the specified name and configuration.
  ///
  /// [name] The name of the reader to connect to.
  /// [readerConfig] The configuration parameters for the connection.
  ///
  /// Returns a [Future] that completes with `null` on successful connection, or throws an exception on failure.
  Future<void> connect(String name, {ReaderConfig? readerConfig}) {
    return ZebraRfidReaderSdkPlatform.instance.connect(name, readerConfig ?? ReaderConfig.initial());
  }

  /// Disconnects from the currently connected Zebra RFID reader.
  ///
  /// Returns a [Future] that completes with `null` on successful disconnection, or throws an exception on failure.
  Future<void> disconnect() {
    return ZebraRfidReaderSdkPlatform.instance.disconnect();
  }

  /// Retrieves a list of available Zebra RFID readers within range.
  ///
  /// Returns a [Future] that provides a list of [ReaderDevice] objects representing the available readers.
  Future<List<ReaderDevice>> getAvailableReaderList() {
    return ZebraRfidReaderSdkPlatform.instance.getAvailableReaderList();
  }

  /// Sets the antenna power level for the connected Zebra RFID reader.
  ///
  /// [value] The desired antenna power level.
  Future<void> setAntennaPower(int value) async {
    await ZebraRfidReaderSdkPlatform.instance.setAntennaPower(value);
  }

  /// Sets the beeper volume for the connected Zebra RFID reader.
  ///
  /// [value] The desired beeper volume level.
  Future<void> setBeeperVolume(int value) async {
    await ZebraRfidReaderSdkPlatform.instance.setBeeperVolume(value);
  }

  /// Enables or disables dynamic power control for the connected Zebra RFID reader.
  ///
  /// [value] `true` to enable dynamic power control, `false` to disable.
  Future<void> setDynamicPower(bool value) async {
    await ZebraRfidReaderSdkPlatform.instance.setDynamicPower(value);
  }

  /// Returns a stream of connected reader devices.
  Stream<dynamic> get connectedReaderDevice {
    return ZebraRfidReaderSdkPlatform.instance.connectedReaderDevice;
  }

  Future<void> findTheTag(String tag) async {
    await ZebraRfidReaderSdkPlatform.instance.findTheTag(tag);
  }

  Future<void> stopFindingTheTag() async {
    await ZebraRfidReaderSdkPlatform.instance.stopFindingTheTag();
  }

  /// Returns a stream of connected reader devices.
  Stream<dynamic> get findingTag {
    return ZebraRfidReaderSdkPlatform.instance.findingTag;
  }

  Stream<dynamic> get readTags {
    return ZebraRfidReaderSdkPlatform.instance.readTags;
  }
}
