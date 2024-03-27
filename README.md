### zebra_rfid_reader_sdk

Zebra RFID Reader SDK plugin for Flutter.

<img src="https://github.com/yagmure15/zebra_rfid_reader_sdk/raw/main/site/zebra_rfd8500.png" alt="Zebra RFID Reader SDK Logo" width="300">

## Android Setup 🔧 

### Add RFIDAPI3Library Folder

After downloading [this](https://github.com/yagmure15/rfidapi3library/tree/main) file, copy it to the `android` directory.

### Gradle Setup

You must add the following code to `android/settings.gradle`.
```dart
include ':RFIDAPI3Library'
```

You should add the following code to the dependencies section under the directory `android/app/build.gradle`.
```dart
dependencies {
    implementation project(":RFIDAPI3Library")
}
```

### Manifest Setup
You should add below inside the **manifest** tag
```dart
xmlns:tools="http://schemas.android.com/tools"
```

and  inside the **application** tag 
 ```dart
 tools:replace="android:label"
```
within the `android/app/src/main/AndroidManifest.xml` directory.

The manifest file will look like this:
```dart
<manifest xmlns:android="http://schemas.android.com/apk/res/android"
    xmlns:tools="http://schemas.android.com/tools">
    ...
   <application
       ...
       tools:replace="android:label">
       ...
    </application>
</manifest>
```
### Be Sure minSdkVersion 19 or Higher
```dart
defaultConfig {
   minSdkVersion 19
}    
```
## IOS Setup 🔧 
Coming Soon

## Features
- Ability to connect to paired Zebra RFID reader.
- Ability to configure antenna power, beeper volume, and dynamic power.

## Usage

### Importing and Creating an Instance
```dart
import 'package:zebra_rfid_reader_sdk/zebra_rfid_reader_sdk.dart';
...
final _zebraRfidReaderSdkPlugin = ZebraRfidReaderSdk();
```

### Connection
The 'connect' function has two parameters. The 'tagName' parameter specifies the name of the device to be connected to. The 'readerConfig' parameter is optional and is used to set antenna, sound, and dynamic power data.

*Note 1: Antenna power value should be between **120** and **300**.*

*Note 2: Please check Bluetooth scan and connection permissions before calling the connection function.*


```dart
  Future<void> requestAccess() async {
    await Permission.bluetoothScan.request().isGranted;
    await Permission.bluetoothConnect.request().isGranted;
  }
```

```dart
_zebraRfidReaderSdkPlugin.connect(
      tagName,
      readerConfig: ReaderConfig(
        antennaPower: 300,
        beeperVolume: BeeperVolume.high,
        isDynamicPowerEnable: true,
      ),
    );
```
### Disconnection
```dart
 _zebraRfidReaderSdkPlugin.disconnect();
```
### Get Available Reader List 
It returns a list of paired devices, resulting in a list of **ReaderDevice**.
```dart
_zebraRfidReaderSdkPlugin.getAvailableReaderList();
```


### Anntenna Power
This function is used to set the antenna power value for the Zebra RFID reader. The value parameter should be an integer between 120 and 300, indicating the desired power level.
```dart
_zebraRfidReaderSdkPlugin.setAntennaPower(value);
```

### Beeper Volume
This function is used to adjust the volume of the beeper on the Zebra RFID reader. The value parameter represents the desired volume level, which should be an integer.
```dart
_zebraRfidReaderSdkPlugin.setBeeperVolume(value);
```

### Dynamic Power
This function is used to configure the dynamic power settings for the Zebra RFID reader. The value parameter should be an boolean representing the desired dynamic power level.
```dart
_zebraRfidReaderSdkPlugin.setDynamicPower(value);
```

### Listening Event
```dart
_zebraRfidReaderSdkPlugin.connectedReaderDevice.listen((event) {
      final result = jsonDecode(event.toString());
      log(result.toString());
    });
```




