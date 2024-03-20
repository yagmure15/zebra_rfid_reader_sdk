enum ConnectionStatus { connected, connecting, notConnected, failed }

class ReaderDevice {
  final ConnectionStatus connectionStatus;
  final String? name;
  final String? batteryLevel;

  ReaderDevice({
    required this.connectionStatus,
    this.name,
    this.batteryLevel,
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
    );
  }

  Map<String, dynamic> toJson() {
    return {
      'name': name,
      'connectionStatus': connectionStatus.name,
      'batteryLevel': batteryLevel,
    };
  }

  factory ReaderDevice.initial() {
    return ReaderDevice(
      connectionStatus: ConnectionStatus.notConnected,
      name: '',
      batteryLevel: '',
    );
  }
}
