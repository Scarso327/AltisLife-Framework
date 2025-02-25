class BaseMagazine { 
	reputation = false;
	class Textures {}; 
};
class RepMagazine { reputation = true; };

class 6Rnd_RedSignal_F {
	price = 120;
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
class 10Rnd_9x21_Mag : BaseMagazine { price = 78; };
class 16Rnd_9x21_Mag : BaseMagazine { price = 102; };
class 30Rnd_9x21_Mag : BaseMagazine { price = 204; };

class 30Rnd_9x21_Mag_SMG_02 : BaseMagazine { price = 360; };
class 30Rnd_9x21_Mag_SMG_02_Tracer_Red : BaseMagazine { 
	price = 360;
	class Textures {
		class 30Rnd_9x21_Mag_SMG_02_Tracer_Red {
			displayName = "Red";
			condition = "true";
		};
		class 30Rnd_9x21_Mag_SMG_02_Tracer_Yellow : 30Rnd_9x21_Mag_SMG_02_Tracer_Red { displayName = "Yellow"; };
		class 30Rnd_9x21_Mag_SMG_02_Tracer_Green : 30Rnd_9x21_Mag_SMG_02_Tracer_Red { displayName = "Green"; };
	};
};
class 30Rnd_9x21_Mag_SMG_02_Tracer_Yellow : 30Rnd_9x21_Mag_SMG_02_Tracer_Red {};
class 30Rnd_9x21_Mag_SMG_02_Tracer_Green : 30Rnd_9x21_Mag_SMG_02_Tracer_Red {};

// .45 ACP
class 9Rnd_45ACP_Mag : BaseMagazine { price = 99; };
class 11Rnd_45ACP_Mag : BaseMagazine { price = 132; };

class 30Rnd_45ACP_Mag_SMG_01 : BaseMagazine { price = 516; };
class 30Rnd_45ACP_Mag_SMG_01_Tracer_Green : RepMagazine { 
	price = 516;
	class Textures {
		class 30Rnd_45ACP_Mag_SMG_01_Tracer_Green {
			displayName = "Green";
			condition = "true";
		};
		class 30Rnd_45ACP_Mag_SMG_01_Tracer_Red : 30Rnd_45ACP_Mag_SMG_01_Tracer_Green { displayName = "Red"; };
		class 30Rnd_45ACP_Mag_SMG_01_Tracer_Yellow : 30Rnd_45ACP_Mag_SMG_01_Tracer_Green { displayName = "Yellow"; };
	};
};
class 30Rnd_45ACP_Mag_SMG_01_Tracer_Red : 30Rnd_45ACP_Mag_SMG_01_Tracer_Green {};
class 30Rnd_45ACP_Mag_SMG_01_Tracer_Yellow : 30Rnd_45ACP_Mag_SMG_01_Tracer_Green {};

class 6Rnd_45ACP_Cylinder : BaseMagazine { price = 114; };

// 50BW
class 10Rnd_50BW_Mag_F : RepMagazine { price = 112500; };

// 12 Gauge
class 2Rnd_12Gauge_Pellets : RepMagazine { price = 720; };
class 6Rnd_12Gauge_Pellets : RepMagazine { price = 9375; };
class 2Rnd_12Gauge_Slug : RepMagazine { price = 810; };
class 6Rnd_12Gauge_Slug : RepMagazine { price = 17625; };

// 5.45mm
class 30Rnd_545x39_Mag_F : RepMagazine { price = 1380; };

// 5.7mm
class 50Rnd_570x28_SMG_03 : RepMagazine { price = 1584; };

// 5.56mm
class 20Rnd_556x45_UW_mag : RepMagazine { price = 15000; };

class 30Rnd_556x45_Stanag : RepMagazine { price = 1380; };
class 30Rnd_556x45_Stanag_Tracer_Red : RepMagazine { 
	price = 1380;
	class Textures {
		class 30Rnd_556x45_Stanag_Tracer_Red {
			displayName = "Red";
			condition = "true";
		};
		class 30Rnd_556x45_Stanag_Tracer_Yellow : 30Rnd_556x45_Stanag_Tracer_Red { displayName = "Yellow"; };
		class 30Rnd_556x45_Stanag_Tracer_Green : 30Rnd_556x45_Stanag_Tracer_Red { displayName = "Rubber Bullets"; };
	};
};
class 30Rnd_556x45_Stanag_Tracer_Yellow : 30Rnd_556x45_Stanag_Tracer_Red {};
class 30Rnd_556x45_Stanag_Tracer_Green : 30Rnd_556x45_Stanag_Tracer_Red {};

class 150Rnd_556x45_Drum_Mag_F : RepMagazine { price = 9780; };
class 150Rnd_556x45_Drum_Mag_Tracer_F : RepMagazine { price = 9780; };

class 200Rnd_556x45_Box_F : RepMagazine { price = 17200; };

// 5.8mm
class 30Rnd_580x42_Mag_F : RepMagazine { price = 1650; };
class 30Rnd_580x42_Mag_Tracer_F : RepMagazine { price = 1650; };

class 100Rnd_580x42_Mag_F : RepMagazine { price = 11340; };
class 100Rnd_580x42_Mag_Tracer_F : RepMagazine { price = 11340; };

// 6.5mm
class 20Rnd_650x39_Cased_Mag_F : RepMagazine { price = 1680; };

class 30Rnd_65x39_caseless_green : RepMagazine { price = 1680; };
class 30Rnd_65x39_caseless_green_mag_Tracer : RepMagazine { price = 1680; };


class 30Rnd_65x39_caseless_msbs_mag : RepMagazine { price = 1842; };
class 30Rnd_65x39_caseless_msbs_mag_Tracer : RepMagazine { price = 1842; };

class 30Rnd_65x39_caseless_black_mag : RepMagazine {
	price = 2094;
	class Textures {
		class 30Rnd_65x39_caseless_black_mag {
			displayName = "Black";
			condition = "[] call ULP_fnc_donatorLevel > 0 || { [player, [""Police""]] call ULP_fnc_isFaction }";
		};
		class 30Rnd_65x39_caseless_mag : 30Rnd_65x39_caseless_black_mag { 
			displayName = "Sand"; 
			condition = "true";
		};
		class 30Rnd_65x39_caseless_khaki_mag : 30Rnd_65x39_caseless_mag { displayName = "Khaki"; };
	};
};
class 30Rnd_65x39_caseless_mag : 30Rnd_65x39_caseless_black_mag {};
class 30Rnd_65x39_caseless_khaki_mag : 30Rnd_65x39_caseless_black_mag {};

class 30Rnd_65x39_caseless_black_mag_Tracer : RepMagazine { 
	price = 2094;
	class Textures {
		class 30Rnd_65x39_caseless_black_mag_Tracer {
			displayName = "Black";
			condition = "[] call ULP_fnc_donatorLevel > 0 || { [player, [""Police""]] call ULP_fnc_isFaction }";
		};
		class 30Rnd_65x39_caseless_mag_Tracer : 30Rnd_65x39_caseless_black_mag_Tracer { 
			displayName = "Sand"; 
			condition = "true";
		 };
		 class 30Rnd_65x39_caseless_khaki_mag_Tracer : 30Rnd_65x39_caseless_mag_Tracer { displayName = "Khaki"; };
	};
};
class 30Rnd_65x39_caseless_mag_Tracer : 30Rnd_65x39_caseless_black_mag_Tracer {};
class 30Rnd_65x39_caseless_khaki_mag_Tracer : 30Rnd_65x39_caseless_black_mag_Tracer {};

class 100Rnd_65x39_caseless_black_mag : RepMagazine {
	price = 14160;
	class Textures {
		class 100Rnd_65x39_caseless_black_mag {
			displayName = "Black";
			condition = "[] call ULP_fnc_donatorLevel > 0 || { [player, [""Police""]] call ULP_fnc_isFaction }";
		};
		class 100Rnd_65x39_caseless_mag : 100Rnd_65x39_caseless_black_mag { 
			displayName = "Sand"; 
			condition = "true";
		};
		class 100Rnd_65x39_caseless_khaki_mag : 100Rnd_65x39_caseless_mag { displayName = "Khaki"; };
	};
};
class 100Rnd_65x39_caseless_mag : 100Rnd_65x39_caseless_black_mag {};
class 100Rnd_65x39_caseless_khaki_mag : 100Rnd_65x39_caseless_black_mag {};

class 100Rnd_65x39_caseless_black_mag_tracer : RepMagazine { 
	price = 14160;
	class Textures {
		class 100Rnd_65x39_caseless_black_mag_tracer {
			displayName = "Black";
			condition = "[] call ULP_fnc_donatorLevel > 0 || { [player, [""Police""]] call ULP_fnc_isFaction }";
		};
		class 100Rnd_65x39_caseless_mag_Tracer : 100Rnd_65x39_caseless_black_mag_tracer { 
			displayName = "Sand"; 
			condition = "true";
		 };
		 class 100Rnd_65x39_caseless_khaki_mag_tracer : 100Rnd_65x39_caseless_mag_Tracer { displayName = "Khaki"; };
	};
};
class 100Rnd_65x39_caseless_mag_Tracer : 100Rnd_65x39_caseless_black_mag_tracer {};
class 100Rnd_65x39_caseless_khaki_mag_tracer : 100Rnd_65x39_caseless_black_mag_tracer {};

class 200Rnd_65x39_cased_Box : RepMagazine { price = 19830; };
class 200Rnd_65x39_cased_Box_Tracer : RepMagazine { 
	price = 19830; 
	class Textures {
		class 200Rnd_65x39_cased_Box_Tracer {
			displayName = "Yellow";
			condition = "true";
		};
		class 200Rnd_65x39_cased_Box_Tracer_Red : 200Rnd_65x39_cased_Box_Tracer { displayName = "Red"; };
	};
};
class 200Rnd_65x39_cased_Box_Tracer_Red : 200Rnd_65x39_cased_Box_Tracer {};

// 7.62mm
class 10Rnd_762x54_Mag : RepMagazine { price = 2880; };
class 10Rnd_Mk14_762x51_Mag : RepMagazine { price = 3216; };
class 20Rnd_762x51_Mag : RepMagazine { price = 5940; };
class 30Rnd_762x39_Mag_F : RepMagazine { price = 8640; };

class 30Rnd_762x39_AK12_Mag_F : RepMagazine { price = 8868; };
class 30Rnd_762x39_AK12_Mag_Tracer_F : RepMagazine { price = 8868; };

class 75Rnd_762x39_Mag_F : RepMagazine { price = 29625; };
class 75Rnd_762x39_Mag_Tracer_F : RepMagazine { price = 29625; };

class 150Rnd_762x54_Box : RepMagazine { price = 36675; };

// 9.3mm
class 10Rnd_93x64_DMR_05_Mag : RepMagazine { price = 38400; };

// 12.7mm
class 10Rnd_127x54_Mag : RepMagazine { price = 43238; };

// .338mm
class 10Rnd_338_Mag : RepMagazine { price = 50363; };

// .408mm
class 7Rnd_408_Mag : RepMagazine { price = 59250; };

// Launchable Flares
class UGL_FlareWhite_F : BaseMagazine { 
	price = 5910; 
	class Textures {
		class UGL_FlareWhite_F {
			displayName = "White";
			condition = "true";
		};
		class UGL_FlareGreen_F : UGL_FlareWhite_F { 
			displayName = "Green";
			condition = "[] call ULP_fnc_donatorLevel > 0"; 
		};
		class UGL_FlareRed_F : UGL_FlareGreen_F { displayName = "Red"; };
		class UGL_FlareYellow_F : UGL_FlareGreen_F { displayName = "Yellow"; };
	};
};
class UGL_FlareGreen_F : UGL_FlareWhite_F {};
class UGL_FlareRed_F : UGL_FlareWhite_F {};
class UGL_FlareYellow_F : UGL_FlareWhite_F {};

// Launchable Smoke
class 1Rnd_Smoke_Grenade_shell : RepMagazine { 
	price = 7920; 
	class Textures {
		class 1Rnd_Smoke_Grenade_shell {
			displayName = "White";
			condition = "true";
		};
		class 1Rnd_SmokeGreen_Grenade_shell : 1Rnd_Smoke_Grenade_shell { 
			displayName = "Green";
			condition = "[] call ULP_fnc_donatorLevel > 0";  
		};
		class 1Rnd_SmokeYellow_Grenade_shell : 1Rnd_SmokeGreen_Grenade_shell { displayName = "Yellow"; };
		class 1Rnd_SmokePurple_Grenade_shell : 1Rnd_SmokeGreen_Grenade_shell { displayName = "Purple"; };
		class 1Rnd_SmokeBlue_Grenade_shell : 1Rnd_SmokeGreen_Grenade_shell { displayName = "Blue"; };
		class 1Rnd_SmokeOrange_Grenade_shell : 1Rnd_SmokeGreen_Grenade_shell { displayName = "Orange"; };
	};
};
class 1Rnd_SmokeRed_Grenade_shell : 1Rnd_Smoke_Grenade_shell {};
class 1Rnd_SmokeGreen_Grenade_shell : 1Rnd_Smoke_Grenade_shell {};
class 1Rnd_SmokeYellow_Grenade_shell : 1Rnd_Smoke_Grenade_shell {};
class 1Rnd_SmokePurple_Grenade_shell : 1Rnd_Smoke_Grenade_shell {};
class 1Rnd_SmokeBlue_Grenade_shell : 1Rnd_Smoke_Grenade_shell {};
class 1Rnd_SmokeOrange_Grenade_shell : 1Rnd_Smoke_Grenade_shell {};