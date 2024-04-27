class LocationInfo {
  final String tag;
  final int distanceAsPercentage;

  LocationInfo({required this.tag, required this.distanceAsPercentage});

  factory LocationInfo.fromJson(Map<Object?, Object?> json) {
    return LocationInfo(
      tag: json['tag'] as String,
      distanceAsPercentage: json['distanceAsPercentage'] as int,
    );
  }

  Map<String, dynamic> toJson() {
    return {
      'tag': tag,
      'distanceAsPercentage': distanceAsPercentage,
    };
  }
}
