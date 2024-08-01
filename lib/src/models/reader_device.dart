enum ConnectionStatus { connected, disconnected, connecting, notConnected, failed }

class ReaderDevice {
  final ConnectionStatus connectionStatus;
  final String? name;
  final String? batteryLevel;
  final List<dynamic>?  antennaRange;

  ReaderDevice({
    required this.connectionStatus,
    this.name,
    this.batteryLevel,
    this.antennaRange,
  });

  factory ReaderDevice.fromJson(Map<Object?, Object?> json) {
    return ReaderDevice(
      connectionStatus: ConnectionStatus.values.firstWhere(
          (e) =>
              e.name.toLowerCase() ==
              '${json['connectionStatus']}'.toString().toLowerCase(),
          orElse: () => ConnectionStatus.notConnected),
      name: json['name'] as String?,
      batteryLevel: json['batteryLevel'] as String?,
      antennaRange: json['antennaRange'] as List<dynamic>?,
    );
  }

  Map<String, dynamic> toJson() {
    return {
      'name': name,
      'connectionStatus': connectionStatus.name,
      'batteryLevel': batteryLevel,
      'antennaRange': antennaRange,
    };
  }

  factory ReaderDevice.initial() {
    return ReaderDevice(
      connectionStatus: ConnectionStatus.notConnected,
      name: '',
      batteryLevel: '',
      antennaRange: [120,300],
    );
  }
}
