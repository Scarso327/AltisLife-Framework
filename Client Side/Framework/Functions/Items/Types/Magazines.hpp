class BaseMagazine { class Textures {}; };

class 6Rnd_RedSignal_F {
	displayName = "6Rnd Signal Cylinder";
	price = 200;
	reputation = true;
	class Textures {
		class 6Rnd_RedSignal_F {
			displayName = "Red";
			condition = "true";
		};
		class 6Rnd_GreenSignal_F : 6Rnd_RedSignal_F { displayName = "Green"; };
	};
};
class 6Rnd_GreenSignal_F : 6Rnd_RedSignal_F {};

// 9mm
class 10Rnd_9x21_Mag : BaseMagazine { price = 130; };
class 16Rnd_9x21_Mag : BaseMagazine { price = 170; };
class 30Rnd_9x21_Mag : BaseMagazine { price = 340; };
class 30Rnd_9x21_Mag_SMG_02 : BaseMagazine { price = 600; };

// .45 ACP
class 9Rnd_45ACP_Mag : BaseMagazine { price = 165; };
class 11Rnd_45ACP_Mag : BaseMagazine { price = 220; };
class 30Rnd_45ACP_Mag_SMG_01 : BaseMagazine { price = 860; };
class 6Rnd_45ACP_Cylinder : BaseMagazine { price = 190; };

// 50BW
class 10Rnd_50BW_Mag_F : BaseMagazine { price = 140000; };

// 12 Gauge
class 2Rnd_12Gauge_Pellets : BaseMagazine { price = 1200; };
class 6Rnd_12Gauge_Pellets : BaseMagazine { price = 12500; };
class 2Rnd_12Gauge_Slug : BaseMagazine { price = 1350; };
class 6Rnd_12Gauge_Slug : BaseMagazine { price = 13500; };

// 5.45mm
class 30Rnd_545x39_Mag_F : BaseMagazine { price = 2300; };

// 5.7mm
class 50Rnd_570x28_SMG_03 : BaseMagazine { price = 2640; };

// Rubber Bullets
class 30Rnd_556x45_Stanag_Tracer_Green : BaseMagazine { 
	price = 210;
	reputation = true; 
};

// 5.56mm
class 20Rnd_556x45_UW_mag : BaseMagazine { price = 25000; };
class 30Rnd_556x45_Stanag : BaseMagazine { price = 2300; };
class 150Rnd_556x45_Drum_Mag_F : BaseMagazine { price = 16300; };
class 200Rnd_556x45_Box_F : BaseMagazine { price = 21500; };

// 5.8mm
class 30Rnd_580x42_Mag_F : BaseMagazine { price = 2750; };
class 100Rnd_580x42_Mag_F : BaseMagazine { price = 18900; };

// 6.5mm
class 20Rnd_650x39_Cased_Mag_F : BaseMagazine { price = 2800; };
class 30Rnd_65x39_caseless_green : BaseMagazine { price = 3050; };
class 30Rnd_65x39_caseless_msbs_mag : BaseMagazine { price = 3070; };

class 30Rnd_65x39_caseless_black_mag {
	price = 3490;
	reputation = true;
	class Textures {
		class 30Rnd_65x39_caseless_black_mag {
			displayName = "Black";
			condition = "true";
		};
		class 30Rnd_65x39_caseless_mag : 30Rnd_65x39_caseless_black_mag { displayName = "Sand"; };
		class 30Rnd_65x39_caseless_khaki_mag : 30Rnd_65x39_caseless_black_mag { displayName = "Khaki"; };
	};
};
class 30Rnd_65x39_caseless_mag : 30Rnd_65x39_caseless_black_mag {};
class 30Rnd_65x39_caseless_khaki_mag : 30Rnd_65x39_caseless_black_mag {};

class 100Rnd_65x39_caseless_black_mag {
	price = 23600;
	reputation = true;
	class Textures {
		class 100Rnd_65x39_caseless_black_mag {
			displayName = "Black";
			condition = "true";
		};
		class 100Rnd_65x39_caseless_mag : 100Rnd_65x39_caseless_black_mag { displayName = "Sand"; };
		class 100Rnd_65x39_caseless_khaki_mag : 100Rnd_65x39_caseless_black_mag { displayName = "Khaki"; };
	};
};
class 100Rnd_65x39_caseless_mag : 100Rnd_65x39_caseless_black_mag {};
class 100Rnd_65x39_caseless_khaki_mag : 100Rnd_65x39_caseless_black_mag {};

class 200Rnd_65x39_cased_Box : BaseMagazine { price = 33050; };

// 7.62mm
class 10Rnd_762x54_Mag : BaseMagazine { price = 4800; };
class 10Rnd_Mk14_762x51_Mag : BaseMagazine { price = 5360; };
class 20Rnd_762x51_Mag : BaseMagazine { price = 9900; };
class 30Rnd_762x39_Mag_F : BaseMagazine { price = 14400; };
class 30Rnd_762x39_AK12_Mag_F : BaseMagazine { price = 14780; };
class 150Rnd_762x54_Box : BaseMagazine { price = 48900; };

// 9.3mm
class 10Rnd_93x64_DMR_05_Mag : BaseMagazine { price = 51200; };

// 12.7mm
class 10Rnd_127x54_Mag : BaseMagazine { price = 57650; };

// .338mm
class 10Rnd_338_Mag : BaseMagazine { price = 67150; };

// .408mm
class 7Rnd_408_Mag : BaseMagazine { price = 79000; };