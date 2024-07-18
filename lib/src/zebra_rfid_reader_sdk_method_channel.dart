import 'dart:convert';

import 'package:flutter/services.dart';
import 'package:zebra_rfid_reader_sdk/src/models/reader_config.dart';
import 'package:zebra_rfid_reader_sdk/src/models/reader_device.dart';

import 'zebra_rfid_reader_sdk_platform_interface.dart';

/// An implementation of [ZebraRfidReaderSdkPlatform] that uses method channels.
class MethodChannelZebraRfidReaderSdk extends ZebraRfidReaderSdkPlatform {
  final _methodChannel = const MethodChannel('borda/zebra_rfid_reader_sdk');
  final EventChannel _eventChannel = const EventChannel("tagHandlerEvent");
  final EventChannel _tagFindingEventChannel = const EventChannel("tagFindingEvent");
  final EventChannel _readTagsEventChannel = const EventChannel("readTagEvent");

  /// Returns a list of available readers.
  @override
  Future<List<ReaderDevice>> getAvailableReaderList() async {
    final result = await _methodChannel.invokeMethod<String>('getAvailableReaderList') ?? [];
    final json = jsonDecode(result.toString());
    List<ReaderDevice> readers = [];

    for (var i = 0; i < json.length; i++) {
      readers.add(ReaderDevice.fromJson(json[i] as Map<Object?, Object?>));
    }

    return readers;
  }

  /// Connects to a reader with the given [name] and [readerConfig].
  @override
  Future<void> connect(String name, ReaderConfig readerConfig) async {
    await _methodChannel.invokeMethod<String>('connect', {'name': name, 'readerConfig': readerConfig.toJson()});
  }

  /// Disconnects from the reader.
  @override
  Future<void> disconnect() async {
    await _methodChannel.invokeMethod<void>('disconnect');
  }

  /// Sets the antenna power to the given [value].
  @override
  Future<void> setAntennaPower(int value) async {
    await _methodChannel.invokeMethod<void>('setAntennaPower', {'transmitPowerIndex': value});
  }

  /// Sets the beeper volume to the given [value].
  @override
  Future<void> setBeeperVolume(int value) async {
    await _methodChannel.invokeMethod<void>('setBeeperVolume', {'level': value});
  }

  /// Sets the dynamic power to the given [value].
  @override
  Future<void> setDynamicPower(bool value) async {
    await _methodChannel.invokeMethod<void>('setDynamicPower', {'isEnable': value});
  }

  /// Returns a stream of connected reader devices.
  @override
  Stream<dynamic> get connectedReaderDevice {
    return _eventChannel.receiveBroadcastStream();
  }

  @override
  Future<void> findTheTag(String tag) async {
    await _methodChannel.invokeMethod<void>('findTheTag', {'tag': tag});
  }

  @override
  Future<void> stopFindingTheTag() async {
    await _methodChannel.invokeMethod<void>('stopFindingTheTag');
  }

  /// Returns a stream of connected reader devices.
  @override
  Stream<dynamic> get findingTag {
    return _tagFindingEventChannel.receiveBroadcastStream();
  }
  /// Returns a stream of read tags.
  @override
  Stream<dynamic> get readTags {
    return _readTagsEventChannel.receiveBroadcastStream();
  }
}
