import 'package:plugin_platform_interface/plugin_platform_interface.dart';
import 'package:zebra_rfid_reader_sdk/src/models/reader_config.dart';
import 'package:zebra_rfid_reader_sdk/src/models/reader_device.dart';
import 'package:zebra_rfid_reader_sdk/src/zebra_rfid_reader_sdk_method_channel.dart';

/// This abstract class defines the platform-agnostic interface for the Zebra RFID Reader SDK plugin.
///
/// Concrete implementations for Android and iOS platforms should extend this class and provide platform-specific implementations
/// for the methods defined here.
abstract class ZebraRfidReaderSdkPlatform extends PlatformInterface {
  /// Creates a new instance of the `ZebraRfidReaderSdkPlatform`.
  ZebraRfidReaderSdkPlatform() : super(token: _token);

  static final Object _token = Object();
  static ZebraRfidReaderSdkPlatform _instance = MethodChannelZebraRfidReaderSdk();

  /// Singleton instance of the `ZebraRfidReaderSdkPlatform`.
  static ZebraRfidReaderSdkPlatform get instance => _instance;

  /// Allows setting a platform-specific implementation of `ZebraRfidReaderSdkPlatform`.
  /// This is used internally by the plugin to register the platform-specific instance.
  static set instance(ZebraRfidReaderSdkPlatform instance) {
    PlatformInterface.verifyToken(instance, _token);
    _instance = instance;
  }

  /// Establishes a connection to a Zebra RFID reader with the specified name and configuration.
  ///
  /// [name] The name of the reader to connect to.
  /// [readerConfig] The configuration parameters for the reader connection.
  ///
  /// @throws [NotImplementedError] if the platform-specific implementation has not implemented this method.
  Future<void> connect(String name, ReaderConfig readerConfig) {
    throw UnimplementedError('connect() has not been implemented.');
  }

  /// Disconnects from the currently connected Zebra RFID reader.
  ///
  /// @throws [NotImplementedError] if the platform-specific implementation has not implemented this method.
  Future<void> disconnect() {
    throw UnimplementedError('disconnect() has not been implemented.');
  }

  /// Retrieves a list of available Zebra RFID readers within range.
  ///
  /// @throws [NotImplementedError] if the platform-specific implementation has not implemented this method.
  Future<List<ReaderDevice>> getAvailableReaderList() {
    throw UnimplementedError('getAvailableReaderList() has not been implemented.');
  }

  /// Sets the antenna power level for the connected Zebra RFID reader.
  ///
  /// [value] The desired antenna power level.
  ///
  /// @throws [NotImplementedError] if the platform-specific implementation has not implemented this method.
  Future<void> setAntennaPower(int value) async {
    throw UnimplementedError('setAntennaPower() has not been implemented.');
  }

  /// Sets the beeper volume for the connected Zebra RFID reader.
  ///
  /// [value] The desired beeper volume level.
  ///
  /// @throws [NotImplementedError] if the platform-specific implementation has not been implemented.
  Future<void> setBeeperVolume(int value) async {
    throw UnimplementedError('setBeeperVolume() has not been implemented.');
  }

  /// Enables or disables dynamic power control for the connected Zebra RFID reader.
  ///
  /// [value] `true` to enable dynamic power control, `false` to disable.
  ///
  /// @throws [NotImplementedError] if the platform-specific implementation has not been implemented.
  Future<void> setDynamicPower(bool value) async {
    throw UnimplementedError('setDynamicPower() has not been implemented.');
  }

  /// Returns a stream of connected reader devices.
  Stream<dynamic> get connectedReaderDevice {
    throw UnimplementedError('disconnect() has not been implemented.');
  }

  Future<void> findTheTag(String tag) async {
    throw UnimplementedError('findTheTag() has not been implemented.');
  }

  Future<void> stopFindingTheTag() async {
    throw UnimplementedError('stopFindingTheTag() has not been implemented.');
  }

  /// Returns a stream of connected reader devices.
  Stream<dynamic> get findingTag {
    throw UnimplementedError('disconnect() has not been implemented.');
  }
}
