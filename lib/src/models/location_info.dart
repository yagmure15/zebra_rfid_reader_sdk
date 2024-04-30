class LocationInfo {
  final String tag;
  final int distanceAsPercentage;
  final bool isAnyReaderConnected;

  LocationInfo({
    required this.tag,
    required this.distanceAsPercentage,
    required this.isAnyReaderConnected,
  });

  factory LocationInfo.fromJson(Map<Object?, Object?> json) {
    return LocationInfo(
      tag: json['tag'] as String,
      distanceAsPercentage: json['distanceAsPercentage'] as int,
      isAnyReaderConnected: json['isAnyReaderConnected'] as bool,
    );
  }

  Map<String, dynamic> toJson() {
    return {
      'tag': tag,
      'distanceAsPercentage': distanceAsPercentage,
      'isAnyReaderConnected': isAnyReaderConnected,
    };
  }
}
