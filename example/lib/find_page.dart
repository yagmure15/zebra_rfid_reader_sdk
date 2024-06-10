import 'dart:convert';
import 'dart:developer';

import 'package:flutter/material.dart';
import 'package:zebra_rfid_reader_sdk/zebra_rfid_reader_sdk.dart';

class FindPage extends StatefulWidget {
  const FindPage({super.key});

  @override
  State<FindPage> createState() => _FindPageState();
}

class _FindPageState extends State<FindPage> {
  final _zebraRfidReaderSdkPlugin = ZebraRfidReaderSdk();

  @override
  void initState() {
    super.initState();
    listenToEvent();
  }

  @override
  void dispose() {
    super.dispose();
    _zebraRfidReaderSdkPlugin.stopFindingTheTag();
  }

  void listenToEvent() {
    _zebraRfidReaderSdkPlugin.findTheTag('BDBD0134000000000013B747');
    _zebraRfidReaderSdkPlugin.findingTag.listen((event) {
      final result = jsonDecode(event.toString());

      log(result.toString());
    });
  }

  @override
  Widget build(BuildContext context) {
    return const Scaffold(
        body: Column(
      mainAxisAlignment: MainAxisAlignment.center,
      children: <Widget>[
        Text('Find Page'),
      ],
    ));
  }
}
