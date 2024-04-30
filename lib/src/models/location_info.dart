class LocationInfo {
  final String tag;
  final bool isAnyReaderConnected;
  final int? distanceAsPercentage;

  LocationInfo({
    required this.tag,
    required this.isAnyReaderConnected,
    this.distanceAsPercentage,
  });

  factory LocationInfo.fromJson(Map<Object?, Object?> json) {
    return LocationInfo(
      tag: json['tag'] as String,
      distanceAsPercentage: json['distanceAsPercentage'] as int?,
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
