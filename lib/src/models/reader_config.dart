enum BeeperVolume { quiet, low, medium, high }

class ReaderConfig {
  final int? antennaPower;
  final BeeperVolume beeperVolume;
  final bool isDynamicPowerEnable;

  ReaderConfig({
    required this.antennaPower,
    required this.beeperVolume,
    required this.isDynamicPowerEnable,
  });

  factory ReaderConfig.fromJson(Map<Object?, Object?> json) {
    return ReaderConfig(
      antennaPower: json['antennaPower'] as int,
      beeperVolume: BeeperVolume.values[json['beeperVolume'] as int],
      isDynamicPowerEnable: json['isDynamicPowerEnable'] as bool,
    );
  }

  factory ReaderConfig.initial() {
    return ReaderConfig(
      antennaPower: null,
      beeperVolume: BeeperVolume.high,
      isDynamicPowerEnable: true,
    );
  }

  Map<String, dynamic> toJson() {
    return {
      'antennaPower': antennaPower,
      'beeperVolume': beeperVolume.index,
      'isDynamicPowerEnable': isDynamicPowerEnable,
    };
  }

  ReaderConfig copyWith({
    int? antennaPower,
    BeeperVolume? beeperVolume,
    bool? isDynamicPowerEnable,
  }) {
    return ReaderConfig(
      antennaPower: antennaPower ?? this.antennaPower,
      beeperVolume: beeperVolume ?? this.beeperVolume,
      isDynamicPowerEnable: isDynamicPowerEnable ?? this.isDynamicPowerEnable,
    );
  }

  @override
  bool operator ==(Object other) {
    if (identical(this, other)) return true;

    return other is ReaderConfig &&
        antennaPower == other.antennaPower &&
        beeperVolume == other.beeperVolume &&
        isDynamicPowerEnable == other.isDynamicPowerEnable;
  }

  @override
  int get hashCode {
    return antennaPower.hashCode ^ beeperVolume.hashCode ^ isDynamicPowerEnable.hashCode;
  }
}
