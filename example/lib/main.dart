import 'dart:async';
import 'dart:convert';
import 'dart:developer';

import 'package:flutter/cupertino.dart';
import 'package:flutter/material.dart';
import 'package:permission_handler/permission_handler.dart';
import 'package:zebra_rfid_reader_sdk/zebra_rfid_reader_sdk.dart';

void main() {
  runApp(const MaterialApp(home: MyApp()));
}

class MyApp extends StatefulWidget {
  const MyApp({super.key});

  @override
  State<MyApp> createState() => _MyAppState();
}

class _MyAppState extends State<MyApp> {
  final _zebraRfidReaderSdkPlugin = ZebraRfidReaderSdk();
  List<ReaderDevice> availableReaderList = [];
  List<TagDataModel> readTags = [];
  ReaderDevice connectedReader = ReaderDevice.initial();
  double antennaPower = 270;
  double beeperVolume = 3;
  bool isDynamicPowerEnable = true;

  @override
  void initState() {
    super.initState();
    listenToEvent();
    listenToReadTags();
  }

  void listenToReadTags() {
    _zebraRfidReaderSdkPlugin.readTags.listen((event) {
      final result = jsonDecode(event.toString());
      final readTag = TagDataModel.fromJson(result);
      readTags.removeWhere((element) => element.tagId == readTag.tagId);
      setState(() {
        readTags.insert(0, readTag);
      });
    });
  }

  void listenToEvent() {
    _zebraRfidReaderSdkPlugin.connectedReaderDevice.listen((event) {
      final result = jsonDecode(event.toString());

      setState(() {
        connectedReader = ReaderDevice.fromJson(result);
      });
      log(result.toString());
    });
  }

  void stopListening() {
    _zebraRfidReaderSdkPlugin.connectedReaderDevice.listen(null);
  }

  String hexToFCode(String hex) {
    if (hex.startsWith('BDBD') && hex.length == 24) {
      return 'F-${int.parse(hex.substring(18, 24), radix: 16)}';
    }

    return hex;
  }

  void connectToZebra(String tagName) async {
    await requestAccess();
    _zebraRfidReaderSdkPlugin.connect(tagName);
  }

  void disconnectToZebra() async {
    await requestAccess();
    _zebraRfidReaderSdkPlugin.disconnect();
  }

  Future<void> requestAccess() async {
    await Permission.bluetoothScan.request().isGranted;
    await Permission.bluetoothConnect.request().isGranted;
  }

  Future<void> getAvailableReaderList() async {
    final result = await _zebraRfidReaderSdkPlugin.getAvailableReaderList();

    setState(() {
      availableReaderList = result;
    });
  }

  Future<void> setAntennaPower(int value) async {
    await _zebraRfidReaderSdkPlugin.setAntennaPower(value);
  }

  Future<void> setBeeperVolume(int value) async {
    await _zebraRfidReaderSdkPlugin.setBeeperVolume(value);
  }

  Future<void> setDynamicPower(bool value) async {
    await _zebraRfidReaderSdkPlugin.setDynamicPower(value);
  }

  Future<void> findTheTag(String tag) async {
    await _zebraRfidReaderSdkPlugin.findTheTag(tag);
  }

  Future<void> stopFindingTheTag() async {
    await _zebraRfidReaderSdkPlugin.stopFindingTheTag();
  }

  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      home: Scaffold(
        appBar: AppBar(
          title: const Text('Plugin example app'),
        ),
        body: Padding(
          padding: const EdgeInsets.all(16),
          child: Column(
            crossAxisAlignment: CrossAxisAlignment.start,
            children: [
              const Text('DEVICES'),
              Text(
                'Handheld Readers (${availableReaderList.length})',
                style: const TextStyle(fontSize: 24, fontWeight: FontWeight.bold),
              ),
              Expanded(
                child: ListView.builder(
                  itemBuilder: (context, index) => Padding(
                    padding: const EdgeInsets.symmetric(vertical: 4),
                    child: ListTile(
                      shape: RoundedRectangleBorder(borderRadius: BorderRadius.circular(10)),
                      selectedTileColor: Colors.orange[100],
                      tileColor: Colors.black12,
                      onTap: () => connectedReader.connectionStatus == ConnectionStatus.connecting
                          ? null
                          : connectedReader.name == availableReaderList[index].name &&
                                  connectedReader.connectionStatus == ConnectionStatus.connected
                              ? disconnectToZebra()
                              : connectToZebra(availableReaderList[index].name!),
                      contentPadding: const EdgeInsets.all(8),
                      selectedColor: Colors.amber,
                      title: Text(availableReaderList[index].name ?? "Unknown Device"),
                      subtitle: connectedReader.name == availableReaderList.elementAt(index).name &&
                              connectedReader.connectionStatus == ConnectionStatus.connected
                          ? Text('Battery ${connectedReader.batteryLevel ?? '0'}%')
                          : null,
                      trailing: Text(connectedReader.name == availableReaderList.elementAt(index).name
                          ? connectedReader.connectionStatus.name
                          : 'Not Connected'),
                    ),
                  ),
                  itemCount: availableReaderList.length,
                ),
              ),
              Text('Dynamic Power: ${isDynamicPowerEnable ? 'ON' : 'OFF'}'),
              CupertinoSwitch(
                value: isDynamicPowerEnable,
                onChanged: (value) {
                  setState(() {
                    isDynamicPowerEnable = value;
                  });
                  setDynamicPower(value);
                },
              ),
              const SizedBox(height: 16),
              Text('Beeper Volume: ${BeeperVolume.values[beeperVolume.toInt()].name.toUpperCase()}'),
              SizedBox(
                width: double.infinity,
                child: CupertinoSlider(
                  value: beeperVolume,
                  divisions: 3,
                  min: 0,
                  max: 3,
                  onChangeEnd: (value) => setBeeperVolume(value.round()),
                  onChanged: (value) {
                    setState(() {
                      beeperVolume = value;
                    });
                  },
                ),
              ),
              const SizedBox(height: 16),
              Text('Reading Power: ${antennaPower.ceil()}'),
              SizedBox(
                width: double.infinity,
                child: CupertinoSlider(
                  value: antennaPower.ceil().toDouble(),
                  divisions: 180,
                  min: 120,
                  max: 300,
                  onChangeEnd: (value) => setAntennaPower(value.round()),
                  onChanged: (value) {
                    setState(() {
                      antennaPower = value;
                    });
                  },
                ),
              ),
              Expanded(
                child: ListView.builder(
                  itemCount: readTags.length,
                  itemBuilder: (context, index) => Text(readTags[index].tagId),
                ),
              ),
              SizedBox(
                width: double.infinity,
                child: ElevatedButton(
                  onPressed: getAvailableReaderList,
                  child: const Text('Get Available ReaderDevice List'),
                ),
              ),
              SizedBox(
                width: double.infinity,
                child: ElevatedButton(
                  onPressed: () => findTheTag('BDBD0134000000000013B747'),
                  child: const Text('Find The Tag'),
                ),
              ),
            ],
          ),
        ),
      ),
    );
  }
}
