class CfgItemsStore {
	onItemBuy = "_this call ULP_fnc_onBuyItems";
	toolBoxIDC = 3113;
	itemCfg = "CfgItems";

	class Police {
		storeName = "Police Equipment Store";
		condition = "[player, [""Police""]] call ULP_fnc_isFaction";
		class Rifles {
			// SPECIAL
			class arifle_Mk20C_plain_F {
				condition = "[""Police_Main"", 2] call ULP_fnc_hasAccess"; 
				class textures { class arifle_Mk20C_plain_F {}; };
			};
			class arifle_SDAR_F { 
				price = 0;
				condition = "[""Police_MPU"", 1] call ULP_fnc_hasAccess"; 
			};

			// SUB-MACHINE GUNS
			class SMG_05_F { 
				price = 0;
				condition = "[""Police_Main"", 2] call ULP_fnc_hasAccess"; 
			}; 
			class SMG_01_F { 
				price = 0;
				condition = "[""Police_Main"", 10] call ULP_fnc_hasAccess || { [""Police_SFO"", 1] call ULP_fnc_hasAccess }"; 
			};
			class SMG_03C_black { 
				price = 0;
				condition = "[""Police_Main"", 5] call ULP_fnc_hasAccess || { [""Police_SFO"", 1] call ULP_fnc_hasAccess }"; 
			};
			class SMG_03_black { 
				price = 0;
				condition = "[""Police_Main"", 6] call ULP_fnc_hasAccess || { [""Police_SFO"", 1] call ULP_fnc_hasAccess }"; 
			};

			// ASSAULT RIFLES
			class arifle_SPAR_01_blk_F {
				price = 0;
				condition = "[""Police_Main"", 2] call ULP_fnc_hasAccess";
				class textures { class arifle_SPAR_01_blk_F {}; };
			};
			class arifle_SPAR_02_blk_F {
				price = 0;
				condition = "[""Police_Main"", 3] call ULP_fnc_hasAccess";
				class textures { class arifle_SPAR_02_blk_F {}; };
			};
			class arifle_CTAR_blk_F {
				price = 0;
				condition = "[""Police_Main"", 2] call ULP_fnc_hasAccess";
				class textures { class arifle_CTAR_blk_F {}; };
			};
			class arifle_CTARS_blk_F {
				price = 0;
				condition = "[""Police_Main"", 8] call ULP_fnc_hasAccess || { [""Police_SFO"", 1] call ULP_fnc_hasAccess }";
				class textures { class arifle_CTARS_blk_F {}; };
			};
			class arifle_MX_Black_F {
				price = 0;
				condition = "[""Police_Main"", 5] call ULP_fnc_hasAccess || { [""Police_SFO"", 1] call ULP_fnc_hasAccess }";
				class textures { class arifle_MX_Black_F {}; };
			};
			class arifle_MXM_Black_F {
				price = 0;
				condition = "[""Police_Main"", 6] call ULP_fnc_hasAccess || { [""Police_SFO"", 1] call ULP_fnc_hasAccess }";
				class textures { class arifle_MXM_Black_F {}; };
			}; 
			class arifle_MX_SW_Black_F {
				price = 0;
				condition = "[""Police_Main"", 10] call ULP_fnc_hasAccess || { [""Police_SFO"", 3] call ULP_fnc_hasAccess }";
				class textures { class arifle_MX_SW_Black_F {}; };
			};
			class arifle_MSBS65_black_F {
				price = 0;
				condition = "[""Police_Main"", 5] call ULP_fnc_hasAccess || { [""Police_SFO"", 1] call ULP_fnc_hasAccess }";
				class textures { class arifle_MSBS65_black_F {}; };
			};
			class arifle_Katiba_C_F {
				price = 0;
				condition = "[""Police_Main"", 6] call ULP_fnc_hasAccess || { [""Police_SFO"", 1] call ULP_fnc_hasAccess }";
				class textures { class arifle_Katiba_C_F {}; };
			};
			class arifle_ARX_blk_F {
				price = 0;
				condition = "[""Police_Main"", 7] call ULP_fnc_hasAccess || { [""Police_SFO"", 1] call ULP_fnc_hasAccess }";
				class textures { class arifle_ARX_blk_F {}; };
			};
			class arifle_SPAR_03_blk_F {
				price = 0;
				condition = "[""Police_Main"", 8] call ULP_fnc_hasAccess || { [""Police_SFO"", 1] call ULP_fnc_hasAccess }";
				class textures { class arifle_SPAR_03_blk_F {}; };
			};
			class srifle_EBR_F {
				price = 0;
				condition = "[""Police_Main"", 9] call ULP_fnc_hasAccess || { [""Police_SFO"", 1] call ULP_fnc_hasAccess }";
				class textures { class srifle_EBR_F {}; };
			};
			class srifle_DMR_03_F {
				price = 0;
				condition = "[""Police_Main"", 10] call ULP_fnc_hasAccess || { [""Police_SFO"", 2] call ULP_fnc_hasAccess }";
				class textures { class srifle_DMR_03_F {}; };
			};
		};

		class Pistols {
			class hgun_P07_F {
				price = 0;
				condition = "true";
			};
			class hgun_ACPC2_F { 
				price = 0;
				condition = "[""Police_Main"", 10] call ULP_fnc_hasAccess || { [""Police_SFO"", 4] call ULP_fnc_hasAccess }"; 
			};
		};

		class Attachments {
			class bipod_01_F_blk { 
				price = 0;
				condition = "[""Police_Main"", 2] call ULP_fnc_hasAccess"; 
				class textures {
					class bipod_01_F_blk {};
					class bipod_02_F_blk {};
					class bipod_03_F_blk {};
				};
			};

			class acc_flashlight {
				price = 0;
				condition = "true";
			};
			class acc_pointer_IR {
				price = 0;
				condition = "true";
			};

			// SIGHTS
			class optic_Aco {
				price = 0;
				condition = "true";
			};
			class optic_Holosight {
				price = 0;
				condition = "true";
				class textures {
					class optic_Holosight_blk_F {};
					class optic_Holosight_smg_blk_F {};
				};
			};
			class optic_Hamr {
				price = 0;
				condition = "[""Police_Main"", 2] call ULP_fnc_hasAccess";
				class textures { class optic_Hamr {}; };
			};
			class optic_MRCO { 
				price = 0;
				condition = "[""Police_Main"", 2] call ULP_fnc_hasAccess";
			};
			class optic_Arco {
				price = 0;
				condition = "[""Police_Main"", 2] call ULP_fnc_hasAccess";
				class textures { class optic_Arco_blk_F {}; };
			};
			class optic_ERCO_blk_F { 
				price = 0;
				condition = "[""Police_Main"", 2] call ULP_fnc_hasAccess"; 
			};
			class optic_DMS {
				price = 0;
				condition = "[""Police_Main"", 10] call ULP_fnc_hasAccess || { [""Police_SFO"", 2] call ULP_fnc_hasAccess }";
				class textures { class optic_DMS {}; };
			};
			class optic_SOS {
				price = 0;
				condition = "[""Police_Main"", 10] call ULP_fnc_hasAccess || { [""Police_SFO"", 2] call ULP_fnc_hasAccess }";
				class textures { class optic_SOS {}; };
			};
			class optic_AMS {
				price = 0;
				condition = "[""Police_Main"", 10] call ULP_fnc_hasAccess || { [""Police_SFO"", 3] call ULP_fnc_hasAccess }";
				class textures { class optic_AMS {}; };
			};
			class optic_NVS { 
				price = 0;
				condition = "[""Police_Main"", 10] call ULP_fnc_hasAccess || { [""Police_SFO"", 1] call ULP_fnc_hasAccess }" ;
			};

			// SUPPRESSORS
			class muzzle_snds_L {
				price = 0;
				condition = "[""Police_Main"", 10] call ULP_fnc_hasAccess || { [""Police_SFO"", 1] call ULP_fnc_hasAccess }";
			};
			class muzzle_snds_acp { 
				price = 0;
				condition = "[""Police_Main"", 10] call ULP_fnc_hasAccess || { [""Police_SFO"", 1] call ULP_fnc_hasAccess }"; 
			};
			class muzzle_snds_M { 
				price = 0;
				condition = "[""Police_Main"", 3] call ULP_fnc_hasAccess || { [""Police_SFO"", 1] call ULP_fnc_hasAccess }"; 
				class textures { class muzzle_snds_M {}; };
			};
			class muzzle_snds_570 { 
				price = 0;
				condition = "[""Police_Main"", 10] call ULP_fnc_hasAccess || { [""Police_SFO"", 1] call ULP_fnc_hasAccess }"; 
			};
			class muzzle_snds_58_blk_F { 
				price = 0;
				condition = "[""Police_Main"", 10] call ULP_fnc_hasAccess || { [""Police_SFO"", 1] call ULP_fnc_hasAccess }"; 
				class textures { class muzzle_snds_58_blk_F {}; };
			};
			class muzzle_snds_H { 
				price = 0;
				condition = "[""Police_Main"", 10] call ULP_fnc_hasAccess || { [""Police_SFO"", 1] call ULP_fnc_hasAccess }"; 
				class textures { class muzzle_snds_H {}; };
			};
			class muzzle_snds_65_TI_blk_F { 
				price = 0;
				condition = "[""Police_Main"", 10] call ULP_fnc_hasAccess || { [""Police_SFO"", 1] call ULP_fnc_hasAccess }"; 
				class textures { class muzzle_snds_65_TI_blk_F {}; };
			};
			class muzzle_snds_B { 
				price = 0;
				condition = "[""Police_Main"", 10] call ULP_fnc_hasAccess || { [""Police_SFO"", 2] call ULP_fnc_hasAccess }"; 
				class textures { class muzzle_snds_B {}; };
			};
		};

		class Magazines {};

		class Items {
			class ItemMap {
				price = 0;
				condition = "true";
			};
			class ItemCompass {
				price = 0;
				condition = "true";
			};
			class ItemWatch {
				price = 0;
				condition = "true";
			};
			class ItemGPS {
				price = 0;
				condition = "true";
			};
			class B_UavTerminal { 
				price = 0;
				condition = "[""Police_Main"", 6] call ULP_fnc_hasAccess || { [""Police_ASO"", 1] call ULP_fnc_hasAccess } || { [""Police_SFO"", 1] call ULP_fnc_hasAccess }"; 
			};
			class ItemRadio {
				price = 0;
				condition = "true";
			};
			class Rangefinder {
				price = 0;
				condition = "true";
			};
			class ToolKit {
				price = 0;
				condition = "true";
			};
			class SmokeShell { 
				price = 0;
				condition = "true"; 
				class textures { class SmokeShell {}; };
			};
		};
	};

	class Medic {
		storeName = "Medic Equipment Store";
		condition = "[player, [""Medic""]] call ULP_fnc_isFaction";
		class Rifles {};
		class Pistols {};
		class Attachments {};
		class Magazines {};
		class Items {
			class ItemMap {};
			class ItemCompass {};
			class ItemWatch {};
			class ItemGPS {};
			class ItemRadio {};
			class Rangefinder {};
			class ToolKit {};
		};
	};

	class Civilian {
		storeName = "General Store";
		condition = "true";
		class Rifles {};
		class Pistols {};
		class Attachments {};
		class Magazines {};
		class Items {
			class ItemMap {};
			class ItemCompass {};
			class ItemWatch {};
			class ItemGPS {};
			class ItemRadio {};
			class Binocular {};
			class ToolKit {};
		};
	};

	class Handgun {
		storeName = "Handgun Store";
		condition = "true";
		class Rifles {};

		class Pistols {
			class hgun_Pistol_01_F {};
			class hgun_Rook40_F {};
			class hgun_ACPC2_F {};
			class hgun_Pistol_heavy_01_F {};
			class hgun_Pistol_heavy_02_F {};
		};

		class Attachments {};

		class Magazines {
			class 10Rnd_9x21_Mag {};
			class 16Rnd_9x21_Mag {};
			class 9Rnd_45ACP_Mag {};
			class 11Rnd_45ACP_Mag {};
			class 6Rnd_45ACP_Cylinder {};
		};

		class Items {};
	};

	class Hunting {
		storeName = "Hunting Store";
		condition = "true";
		class Rifles {
			class sgun_HunterShotgun_01_sawedoff_F {
				class textures { class sgun_HunterShotgun_01_F {}; };
			};
			class srifle_DMR_06_hunter_F {};
		};

		class Pistols {};
		class Attachments {};

		class Magazines {
			class 2Rnd_12Gauge_Slug {};
			class 10Rnd_Mk14_762x51_Mag {};
		};

		class Items {
			class ItemMap {};
			class ItemCompass {};
			class ItemWatch {};
			class ItemGPS {};
			class ItemRadio {};
			class Binocular {};
			class ToolKit {};
		};
	};

	class Rebel {
		storeName = "Rebel Outpost";
		condition = "true";
		class Rifles {
			class hgun_PDW2000_F {};
			class SMG_02_F {};
			class SMG_01_F {};
			class sgun_HunterShotgun_01_sawedoff_F {};
			class SMG_03C_black {};
			class SMG_03_black {};
			class arifle_AKS_F {};
			class arifle_SDAR_F {};
			class arifle_TRG20_F {};
			class arifle_Mk20_plain_F {};
			class arifle_SPAR_01_blk_F {};
			class arifle_CTAR_blk_F {};
			class srifle_DMR_07_blk_F {};
			class arifle_Katiba_C_F {};
			class arifle_MSBS65_black_F {};
			class arifle_MSBS65_Mark_black_F {};
			class arifle_MXC_Black_F {};
			class arifle_MX_Black_F {};
			class arifle_MXM_Black_F {};
			class arifle_AKM_F {};
		};

		class Pistols {
			class hgun_Pistol_01_F {};
			class hgun_Rook40_F {};
			class hgun_ACPC2_F {};
			class hgun_Pistol_heavy_01_F {};
			class hgun_Pistol_heavy_02_F {};
		};

		class Attachments {
			class bipod_01_F_blk {};
			class acc_flashlight {};
			class acc_flashlight_pistol {};
			class acc_pointer_IR {};
			class optic_MRD {};
			class optic_Aco {};
			class optic_Holosight {};
			class optic_Hamr {};
			class optic_MRCO {};
			class optic_Arco {};
			class optic_ERCO_blk_F {};
		};

		class Magazines {
			class 10Rnd_9x21_Mag {};
			class 16Rnd_9x21_Mag {};
			class 30Rnd_9x21_Mag {};
			class 30Rnd_9x21_Mag_SMG_02 {};
			class 9Rnd_45ACP_Mag {};
			class 11Rnd_45ACP_Mag {};
			class 6Rnd_45ACP_Cylinder {};
			class 30Rnd_45ACP_Mag_SMG_01 {};
			class 2Rnd_12Gauge_Pellets {};
			class 2Rnd_12Gauge_Slug {};
			class 30Rnd_545x39_Mag_F {};
			class 50Rnd_570x28_SMG_03 {};
			class 20Rnd_556x45_UW_mag  {};
			class 30Rnd_556x45_Stanag {};
			class 30Rnd_580x42_Mag_F {};
			class 20Rnd_650x39_Cased_Mag_F {};
			class 30Rnd_65x39_caseless_green {};
			class 30Rnd_65x39_caseless_msbs_mag {};
			class 30Rnd_65x39_caseless_black_mag {};
			class 30Rnd_762x39_Mag_F {};
		};

		class Items {
			class ItemMap {};
			class ItemCompass {};
			class ItemWatch {};
			class ItemGPS {};
			class ItemRadio {};
			class NVGoggles {};
			class Binocular {};
			class ToolKit {};
			class SmokeShell {};
		};
	};

	class Blackmarket {
		storeName = "Blackmarket";
		condition = "true";
		class Rifles {
			class hgun_PDW2000_F {};
			class SMG_02_F {};
			class SMG_01_F {};
			class sgun_HunterShotgun_01_sawedoff_F {};
			class SMG_03C_black {};
			class SMG_03_black {};
			class arifle_AKS_F {};
			class arifle_SDAR_F {};
			class arifle_TRG20_F {};
			class arifle_Mk20_plain_F {};
			class arifle_SPAR_01_blk_F {};
			class arifle_SPAR_02_blk_F {};
			class LMG_03_F {};
			class arifle_CTAR_blk_F {};
			class arifle_CTARS_blk_F {};
			class srifle_DMR_07_blk_F {};
			class arifle_Katiba_C_F {};
			class arifle_MSBS65_black_F {};
			class arifle_MSBS65_Mark_black_F {};
			class arifle_MXC_Black_F {};
			class arifle_MX_Black_F {};
			class arifle_MXM_Black_F {};
			class arifle_MX_SW_Black_F {};
			class arifle_ARX_blk_F {};
			class arifle_AKM_F {};
			class arifle_AK12_F {};
			class srifle_DMR_01_F {};
			class arifle_SPAR_03_blk_F {};
			class srifle_EBR_F {};
			class srifle_DMR_03_F {};
		};

		class Pistols {
			class hgun_Pistol_01_F {};
			class hgun_Rook40_F {};
			class hgun_ACPC2_F {};
			class hgun_Pistol_heavy_01_F {};
			class hgun_Pistol_heavy_02_F {};
		};

		class Attachments {
			class bipod_01_F_blk {};
			class acc_flashlight {};
			class acc_flashlight_pistol {};
			class acc_pointer_IR {};
			class optic_MRD {};
			class optic_Aco {};
			class optic_Holosight {};
			class optic_Hamr {};
			class optic_MRCO {};
			class optic_Arco {};
			class optic_ERCO_blk_F {};
			class optic_DMS {};
			class optic_SOS {};
		};

		class Magazines {
			class 10Rnd_9x21_Mag {};
			class 16Rnd_9x21_Mag {};
			class 30Rnd_9x21_Mag {};
			class 30Rnd_9x21_Mag_SMG_02 {};
			class 9Rnd_45ACP_Mag {};
			class 11Rnd_45ACP_Mag {};
			class 6Rnd_45ACP_Cylinder {};
			class 30Rnd_45ACP_Mag_SMG_01 {};
			class 2Rnd_12Gauge_Pellets {};
			class 2Rnd_12Gauge_Slug {};
			class 30Rnd_545x39_Mag_F {};
			class 50Rnd_570x28_SMG_03 {};
			class 20Rnd_556x45_UW_mag  {};
			class 30Rnd_556x45_Stanag {};
			class 150Rnd_556x45_Drum_Mag_F {};
			class 200Rnd_556x45_Box_F {};
			class 30Rnd_580x42_Mag_F {};
			class 100Rnd_580x42_Mag_F {};
			class 20Rnd_650x39_Cased_Mag_F {};
			class 30Rnd_65x39_caseless_green {};
			class 30Rnd_65x39_caseless_msbs_mag {};
			class 30Rnd_65x39_caseless_black_mag {};
			class 100Rnd_65x39_caseless_black_mag {};
			class 10Rnd_762x54_Mag {};
			class 20Rnd_762x51_Mag {};
			class 30Rnd_762x39_Mag_F {};
		};
		
		class Items {
			class ItemMap {};
			class ItemCompass {};
			class ItemWatch {};
			class ItemGPS {};
			class ItemRadio {};
			class NVGoggles {};
			class Binocular {};
			class ToolKit {};
			class SmokeShell {};
		};
	};

	class Supplier {
		storeName = "Blackmarket Supplier";
		condition = "true";
		class Rifles {
			class hgun_PDW2000_F {};
			class SMG_02_F {};
			class sgun_HunterShotgun_01_sawedoff_F {};
			class arifle_AKS_F {};
			class arifle_TRG20_F {};
			class arifle_Mk20_plain_F {};
			class arifle_AKM_F {};
		};

		class Pistols {
			class hgun_Pistol_01_F {};
			class hgun_Rook40_F {};
			class hgun_ACPC2_F {};
			class hgun_Pistol_heavy_01_F {};
			class hgun_Pistol_heavy_02_F {};
		};

		class Attachments {
			class optic_Aco {};
			class optic_Holosight {};
		};

		class Magazines {
			class 10Rnd_9x21_Mag {};
			class 16Rnd_9x21_Mag {};
			class 30Rnd_9x21_Mag {};
			class 30Rnd_9x21_Mag_SMG_02 {};
			class 9Rnd_45ACP_Mag {};
			class 11Rnd_45ACP_Mag {};
			class 6Rnd_45ACP_Cylinder {};
			class 30Rnd_45ACP_Mag_SMG_01 {};
			class 2Rnd_12Gauge_Pellets {};
			class 2Rnd_12Gauge_Slug {};
			class 30Rnd_545x39_Mag_F {};
			class 30Rnd_556x45_Stanag {};
			class 30Rnd_762x39_Mag_F {};
		};

		class Items {
			class ItemMap {};
			class ItemCompass {};
			class ItemWatch {};
			class ItemGPS {};
			class ItemRadio {};
			class NVGoggles {};
			class Binocular {};
			class ToolKit {};
			class SmokeShell {};
		};
	};
};