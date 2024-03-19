enum BeeperVolume { quiet, low, medium, high }

class ReaderConfig {
  final int antennaPower;
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
      antennaPower: 270,
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
}
