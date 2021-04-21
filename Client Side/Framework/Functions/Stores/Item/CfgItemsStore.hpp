class CfgItemsStore {
	onItemBuy = "_this call ULP_fnc_onBuyItems";
	toolBoxIDC = 3113;
	itemCfg = "CfgItems";

	class ItemBase { condition = "true"; };
	class FactionBase : ItemBase { price = 0; };

	class Police {
		storeName = "Police Equipment Store";
		condition = "[player, [""Police""]] call ULP_fnc_isFaction";
		class Rifles {
			// SPECIAL
			class arifle_Mk20C_plain_F : FactionBase {
				displayName = "Rubber Bullet Gun";
				condition = "[""Police_Main"", 2] call ULP_fnc_hasAccess"; 
				class textures { class arifle_Mk20C_plain_F {}; };
			};
			class arifle_SDAR_F : FactionBase { condition = "[""Police_MPU"", 1] call ULP_fnc_hasAccess"; };

			// SUB-MACHINE GUNS
			class SMG_05_F : FactionBase { condition = "[""Police_Main"", 2] call ULP_fnc_hasAccess"; }; 
			class SMG_01_F : FactionBase { condition = "[""Police_Main"", 10] call ULP_fnc_hasAccess || { [""Police_SCO"", 1] call ULP_fnc_hasAccess } || { [""Police_Main"", 9] call ULP_fnc_hasAccess && [""Police_AFO"", 1] call ULP_fnc_hasAccess }"; };
			class SMG_03C_black : FactionBase { condition = "[""Police_Main"", 5] call ULP_fnc_hasAccess || { [""Police_NCA"", 1] call ULP_fnc_hasAccess } || { [""Police_Main"", 4] call ULP_fnc_hasAccess && [""Police_AFO"", 1] call ULP_fnc_hasAccess }"; };
			class SMG_03_black : FactionBase { condition = "[""Police_Main"", 6] call ULP_fnc_hasAccess || { [""Police_NCA"", 1] call ULP_fnc_hasAccess } || { [""Police_Main"", 5] call ULP_fnc_hasAccess && [""Police_AFO"", 1] call ULP_fnc_hasAccess }"; };

			// ASSAULT RIFLES
			class arifle_SPAR_01_blk_F : FactionBase {
				condition = "[""Police_Main"", 2] call ULP_fnc_hasAccess";
				class textures { class arifle_SPAR_01_blk_F {}; };
			};
			class arifle_SPAR_01_GL_blk_F : FactionBase {
				condition = "[""Police_Main"", 10] call ULP_fnc_hasAccess || { [""Police_SCO"", 2] call ULP_fnc_hasAccess }";
				class textures { class arifle_SPAR_01_GL_blk_F {}; };
			};
			class arifle_SPAR_02_blk_F : FactionBase {
				condition = "[""Police_Main"", 8] call ULP_fnc_hasAccess || { [""Police_SCO"", 2] call ULP_fnc_hasAccess } || { [""Police_NCA"", 2] call ULP_fnc_hasAccess } || { [""Police_Main"", 7] call ULP_fnc_hasAccess && [""Police_AFO"", 1] call ULP_fnc_hasAccess }";
				class textures { class arifle_SPAR_02_blk_F {}; };
			};
			class arifle_CTAR_blk_F : FactionBase {
				condition = "[""Police_Main"", 2] call ULP_fnc_hasAccess";
				class textures { class arifle_CTAR_blk_F {}; };
			};
			class arifle_CTAR_GL_blk_F : FactionBase {
				condition = "[""Police_Main"", 10] call ULP_fnc_hasAccess || { [""Police_SCO"", 2] call ULP_fnc_hasAccess }";
				class textures { class arifle_CTAR_GL_blk_F {}; };
			};
			class arifle_CTARS_blk_F : FactionBase {
				condition = "[""Police_Main"", 9] call ULP_fnc_hasAccess || { [""Police_SCO"", 2] call ULP_fnc_hasAccess } || { [""Police_Main"", 8] call ULP_fnc_hasAccess && [""Police_AFO"", 1] call ULP_fnc_hasAccess }";
				class textures { class arifle_CTARS_blk_F {}; };
			};
			class arifle_MX_Black_F : FactionBase {
				condition = "[""Police_Main"", 5] call ULP_fnc_hasAccess || { [""Police_SCO"", 2] call ULP_fnc_hasAccess } || { [""Police_NCA"", 1] call ULP_fnc_hasAccess } || { ([""Police_Main"", 4] call ULP_fnc_hasAccess && [""Police_AFO"", 1] call ULP_fnc_hasAccess) }";
				class textures { class arifle_MX_Black_F {}; };
			};
			class arifle_MX_GL_Black_F : FactionBase {
				condition = "[""Police_Main"", 10] call ULP_fnc_hasAccess || { [""Police_SCO"", 2] call ULP_fnc_hasAccess }";
				class textures { class arifle_MX_GL_Black_F {}; };
			};
			class arifle_MXM_Black_F : FactionBase {
				condition = "[""Police_Main"", 6] call ULP_fnc_hasAccess || { [""Police_SCO"", 2] call ULP_fnc_hasAccess } || { [""Police_NCA"", 2] call ULP_fnc_hasAccess } || { ([""Police_Main"", 5] call ULP_fnc_hasAccess && [""Police_AFO"", 1] call ULP_fnc_hasAccess) }";
				class textures { class arifle_MXM_Black_F {}; };
			}; 
			class arifle_MX_SW_Black_F : FactionBase {
				condition = "[""Police_Main"", 10] call ULP_fnc_hasAccess || { [""Police_SCO"", 2] call ULP_fnc_hasAccess } || { [""Police_NCA"", 3] call ULP_fnc_hasAccess } || { ([""Police_Main"", 9] call ULP_fnc_hasAccess && [""Police_AFO"", 1] call ULP_fnc_hasAccess) }";
				class textures { class arifle_MX_SW_Black_F {}; };
			};
			class arifle_MSBS65_black_F : FactionBase {
				condition = "[""Police_Main"", 5] call ULP_fnc_hasAccess || { [""Police_SCO"", 2] call ULP_fnc_hasAccess } || { [""Police_NCA"", 1] call ULP_fnc_hasAccess } || { ([""Police_Main"", 4] call ULP_fnc_hasAccess && [""Police_AFO"", 1] call ULP_fnc_hasAccess) }";
				class textures { class arifle_MSBS65_black_F {}; };
			};
			class arifle_MSBS65_Mark_black_F : FactionBase {
				condition = "[""Police_Main"", 6] call ULP_fnc_hasAccess || { [""Police_SCO"", 2] call ULP_fnc_hasAccess } || { [""Police_NCA"", 1] call ULP_fnc_hasAccess } || { ([""Police_Main"", 5] call ULP_fnc_hasAccess && [""Police_AFO"", 1] call ULP_fnc_hasAccess) }";
				class textures { class arifle_MSBS65_Mark_black_F {}; };
			};
			class arifle_MSBS65_GL_black_F : FactionBase {
				condition = "[""Police_Main"", 10] call ULP_fnc_hasAccess || { [""Police_SCO"", 2] call ULP_fnc_hasAccess }";
				class textures { class arifle_MSBS65_GL_black_F {}; };
			};
			class arifle_MSBS65_UBS_black_F : FactionBase {
				condition = "[""Police_Main"", 10] call ULP_fnc_hasAccess || { [""Police_SCO"", 3] call ULP_fnc_hasAccess }";
				class textures { class arifle_MSBS65_UBS_black_F {}; };
			};
			class arifle_Katiba_C_F : FactionBase {
				condition = "[""Police_Main"", 6] call ULP_fnc_hasAccess || { [""Police_SCO"", 2] call ULP_fnc_hasAccess } || { ([""Police_Main"", 5] call ULP_fnc_hasAccess && [""Police_AFO"", 1] call ULP_fnc_hasAccess) }";
				class textures { class arifle_Katiba_C_F {}; };
			};
			class arifle_Katiba_GL_F : FactionBase {
				condition = "[""Police_Main"", 10] call ULP_fnc_hasAccess || { [""Police_SCO"", 2] call ULP_fnc_hasAccess }";
				class textures { class arifle_Katiba_GL_F {}; };
			};
			class arifle_ARX_blk_F : FactionBase {
				condition = "[""Police_Main"", 7] call ULP_fnc_hasAccess || { [""Police_SCO"", 2] call ULP_fnc_hasAccess } || { ([""Police_Main"", 6] call ULP_fnc_hasAccess && [""Police_AFO"", 1] call ULP_fnc_hasAccess) }";
				class textures { class arifle_ARX_blk_F {}; };
			};
			class arifle_SPAR_03_blk_F : FactionBase {
				condition = "[""Police_Main"", 9] call ULP_fnc_hasAccess || { [""Police_SCO"", 2] call ULP_fnc_hasAccess } || { ([""Police_Main"", 7] call ULP_fnc_hasAccess && [""Police_AFO"", 1] call ULP_fnc_hasAccess) }";
				class textures { class arifle_SPAR_03_blk_F {}; };
			};
			class srifle_EBR_F : FactionBase {
				condition = "[""Police_Main"", 10] call ULP_fnc_hasAccess || { [""Police_SCO"", 2] call ULP_fnc_hasAccess } || { [""Police_NCA"", 4] call ULP_fnc_hasAccess } || { ([""Police_Main"", 8] call ULP_fnc_hasAccess && [""Police_AFO"", 1] call ULP_fnc_hasAccess) }";
				class textures { class srifle_EBR_F {}; };
			};
			class srifle_DMR_03_F : FactionBase {
				condition = "[""Police_Main"", 10] call ULP_fnc_hasAccess || { [""Police_SCO"", 3] call ULP_fnc_hasAccess } || { ([""Police_Main"", 9] call ULP_fnc_hasAccess && [""Police_AFO"", 1] call ULP_fnc_hasAccess) }";
				class textures { class srifle_DMR_03_F {}; };
			};
		};
		class Pistols {
			class hgun_P07_F : FactionBase {};
			class hgun_ACPC2_F : FactionBase {  condition = "[""Police_Main"", 10] call ULP_fnc_hasAccess"; };
		};
		class Attachments {
			class bipod_01_F_blk : FactionBase { 
				condition = "[""Police_Main"", 2] call ULP_fnc_hasAccess"; 
				class textures {
					class bipod_01_F_blk {};
					class bipod_02_F_blk {};
					class bipod_03_F_blk {};
				};
			};
			class acc_flashlight : FactionBase {};
			class acc_pointer_IR : FactionBase {};

			// SIGHTS
			class optic_Aco : FactionBase {};
			class optic_Holosight : FactionBase {
				class textures {
					class optic_Holosight_blk_F {};
					class optic_Holosight_smg_blk_F {};
				};
			};
			class optic_Hamr : FactionBase {
				condition = "[""Police_Main"", 2] call ULP_fnc_hasAccess";
				class textures { class optic_Hamr {}; };
			};
			class optic_MRCO : FactionBase { condition = "[""Police_Main"", 2] call ULP_fnc_hasAccess"; };
			class optic_Arco : FactionBase {
				condition = "[""Police_Main"", 2] call ULP_fnc_hasAccess";
				class textures { class optic_Arco_blk_F {}; };
			};
			class optic_ERCO_blk_F : FactionBase { condition = "[""Police_Main"", 2] call ULP_fnc_hasAccess"; };
			class optic_DMS : FactionBase {
				condition = "[""Police_SCO"", 2] call ULP_fnc_hasAccess";
				class textures { class optic_DMS {}; };
			};
			class optic_AMS : FactionBase {
				condition = "[""Police_SCO"", 3] call ULP_fnc_hasAccess";
				class textures { class optic_AMS {}; };
			};
			class optic_NVS : FactionBase { condition = "[""Police_SCO"", 1] call ULP_fnc_hasAccess || { [""Police_NCA"", 1] call ULP_fnc_hasAccess }"; };
		};
		class Magazines {
			class 16Rnd_9x21_Mag : FactionBase { displayName = "Taser Cartridge"; };
			class 30Rnd_9x21_Mag_SMG_02 : FactionBase {};
			class 30Rnd_45ACP_Mag_SMG_01 : FactionBase {};
			class 9Rnd_45ACP_Mag : FactionBase {};
			class 50Rnd_570x28_SMG_03 : FactionBase {};
			class 30Rnd_556x45_Stanag_Tracer_Green : FactionBase { displayName = "Rubber Bullet Magazine"; };
			class 20Rnd_556x45_UW_mag : FactionBase {};
			class 30Rnd_556x45_Stanag : FactionBase {};
			class 150Rnd_556x45_Drum_Mag_F : FactionBase { condition = "[""Police_Main"", 8] call ULP_fnc_hasAccess || { [""Police_SCO"", 1] call ULP_fnc_hasAccess } || { [""Police_NCA"", 2] call ULP_fnc_hasAccess } || { [""Police_Main"", 7] call ULP_fnc_hasAccess && [""Police_AFO"", 1] call ULP_fnc_hasAccess }"; };
			class 30Rnd_580x42_Mag_F : FactionBase {};
			class 100Rnd_580x42_Mag_F : FactionBase { condition = "[""Police_Main"", 10] call ULP_fnc_hasAccess || { [""Police_SCO"", 2] call ULP_fnc_hasAccess } || { [""Police_NCA"", 3] call ULP_fnc_hasAccess } || { ([""Police_Main"", 9] call ULP_fnc_hasAccess && [""Police_AFO"", 1] call ULP_fnc_hasAccess) }"; };
			class 30Rnd_65x39_caseless_green : FactionBase {};
			class 30Rnd_65x39_caseless_msbs_mag : FactionBase {};
			class 30Rnd_65x39_caseless_black_mag : FactionBase {
				class textures { class 30Rnd_65x39_caseless_black_mag {}; }; 
			};
			class 100Rnd_65x39_caseless_black_mag : FactionBase {
				condition = "[""Police_Main"", 10] call ULP_fnc_hasAccess || { [""Police_SCO"", 2] call ULP_fnc_hasAccess } || { [""Police_NCA"", 3] call ULP_fnc_hasAccess }";
				class textures { class 100Rnd_65x39_caseless_black_mag {}; }; 
			};
			class 20Rnd_762x51_Mag : FactionBase {};
			class 6Rnd_12Gauge_Slug : FactionBase {};
			class UGL_FlareWhite_F : FactionBase {
				class textures { class UGL_FlareWhite_F {}; }; 
			};
			class 1Rnd_Smoke_Grenade_shell : FactionBase {
				class textures { class 1Rnd_Smoke_Grenade_shell {}; };
			};
		};
		class Items {
			class ItemMap : FactionBase {};
			class ItemCompass : FactionBase {};
			class ItemWatch : FactionBase {};
			class ItemGPS : FactionBase {};
			class B_UavTerminal : FactionBase { condition = "[""Police_Main"", 8] call ULP_fnc_hasAccess || { [""Police_NPAS"", 1] call ULP_fnc_hasAccess }"; };
			class ItemRadio : FactionBase {};
			class Rangefinder : FactionBase {};
			class ToolKit : FactionBase {};
			class Chemlight_green {};
			class SmokeShell : FactionBase { 
				class textures { class SmokeShell {}; }; 
			};
		};
	};

	class Medic {
		storeName = "Medic Equipment Store";
		default = 4;
		condition = "[player, [""Medic""]] call ULP_fnc_isFaction";
		class Rifles {};
		class Pistols {};
		class Attachments {};
		class Magazines {};
		class Items {
			class ItemMap : FactionBase {};
			class ItemCompass : FactionBase {};
			class ItemWatch : FactionBase {};
			class ItemGPS : FactionBase {};
			class ItemRadio : FactionBase {};
			class Rangefinder : FactionBase {};
			class ToolKit : FactionBase {};
			class Chemlight_green {};
		};
	};

	class Hato {
		storeName = "HATO Equipment Store";
		default = 4;
		condition = "[player, [""Hato""]] call ULP_fnc_isFaction";
		class Rifles {};
		class Pistols {};
		class Attachments {};
		class Magazines {};
		class Items {
			class ItemMap : FactionBase {};
			class ItemCompass : FactionBase {};
			class ItemWatch : FactionBase {};
			class ItemGPS : FactionBase {};
			class ItemRadio : FactionBase {};
			class Rangefinder : FactionBase {};
			class ToolKit : FactionBase {};
			class Chemlight_green {};
		};
	};

	class Civilian {
		storeName = "General Store";
		default = 4;
		condition = "true";
		class Rifles {};
		class Pistols {};
		class Attachments {};
		class Magazines {};
		class Items {
			class ItemMap : ItemBase {};
			class ItemCompass : ItemBase {};
			class ItemWatch : ItemBase {};
			class ItemGPS : ItemBase {};
			class ItemRadio : ItemBase {};
			class Binocular : ItemBase {};
			class ToolKit : ItemBase {};
		};
	};

	class Handgun {
		storeName = "Handgun Store";
		condition = "[""Handgun""] call ULP_fnc_hasLicense";
		class Rifles {};
		class Pistols {
			class hgun_Pistol_01_F : ItemBase {};
			class hgun_Rook40_F : ItemBase {};
			class hgun_ACPC2_F : ItemBase {};
			class hgun_Pistol_heavy_01_F : ItemBase {};
			class hgun_Pistol_heavy_02_F : ItemBase {};
		};
		class Attachments {};
		class Magazines {
			class 10Rnd_9x21_Mag : ItemBase {};
			class 16Rnd_9x21_Mag : ItemBase {};
			class 9Rnd_45ACP_Mag : ItemBase {};
			class 11Rnd_45ACP_Mag : ItemBase {};
			class 6Rnd_45ACP_Cylinder : ItemBase {};
		};
		class Items {};
	};

	class Hunting {
		storeName = "Hunting Store";
		condition = "[""Hunting""] call ULP_fnc_hasLicense";
		class Rifles {
			class sgun_HunterShotgun_01_F {};
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

	class Protection {
		storeName = "Govenor Protection Store";
		condition = "[] call ULP_fnc_isProtection";
		class Rifles {
			class hgun_PDW2000_F : ItemBase { price = 60100; };
			class SMG_05_F : ItemBase { price = 60075; };
			class SMG_02_F : ItemBase { price = 63825; };
			class SMG_01_F : ItemBase { price = 70125; };
			class SMG_03C_black : ItemBase {
				price = 67250;
				class textures {
					class SMG_03C_black {};
					class SMG_03C_TR_black {};
				};
			};
			class SMG_03_black : ItemBase {
				price = 83350;
				class textures {
					class SMG_03_black {};
					class SMG_03_TR_black {};
				};
			};
			class arifle_SPAR_01_blk_F : ItemBase {
				price = 127075;
				class textures {
					class arifle_SPAR_01_blk_F {};
				};
			};
		};
		class Pistols {
			class hgun_Rook40_F : ItemBase { price = 16550; };
			class hgun_ACPC2_F : ItemBase { price = 22500; };
		};
		class Attachments {
			class bipod_01_F_blk : FactionBase { 
				class textures {
					class bipod_01_F_blk {};
					class bipod_02_F_blk {};
					class bipod_03_F_blk {};
				};
			};
			class acc_flashlight : FactionBase {};

			// SIGHTS
			class optic_Aco : FactionBase {};
			class optic_Holosight : FactionBase {
				class textures {
					class optic_Holosight_blk_F {};
					class optic_Holosight_smg_blk_F {};
				};
			};
			class optic_Hamr : FactionBase {
				class textures { class optic_Hamr {}; };
			};
			class optic_MRCO : FactionBase {};
			class optic_Arco : FactionBase {
				class textures { class optic_Arco_blk_F {}; };
			};
			class optic_ERCO_blk_F : FactionBase {};
		};
		class Magazines {
			class 16Rnd_9x21_Mag {};
			class 30Rnd_9x21_Mag {};
			class 30Rnd_9x21_Mag_SMG_02 {};
			class 9Rnd_45ACP_Mag {};
			class 30Rnd_45ACP_Mag_SMG_01 {};
			class 50Rnd_570x28_SMG_03 {};
			// TODO (Rubber Bullets when rewritten)
			class 30Rnd_556x45_Stanag {};
		};
		class Items {
			class ItemMap {};
			class ItemCompass {};
			class ItemWatch {};
			class ItemGPS {};
			class ItemRadio {};
			class Binocular {};
			class ToolKit {};
			class Chemlight_green {};
			class SmokeShell : FactionBase { 
				class textures { class SmokeShellBlue {}; }; 
			};
		};
	};

	class Hideout {
		storeName = "Criminal Hideout";
		condition = "[""hideout_flag_1""] call ULP_fnc_ownsSite || { [""hideout_flag_2""] call ULP_fnc_ownsSite }";
		class Rifles {
			class hgun_PDW2000_F {};
			class SMG_02_F {};
			class SMG_01_F {};
			class sgun_HunterShotgun_01_sawedoff_F {};
			class arifle_AKS_F {};
			class arifle_TRG20_F {};
			class arifle_Mk20_plain_F {};
			class arifle_SPAR_01_blk_F {};
			class arifle_AKM_F {};
		};

		class Pistols {
			class hgun_Pistol_01_F {};
			class hgun_Rook40_F {};
			class hgun_ACPC2_F {};
			class hgun_Pistol_heavy_02_F {};
		};

		class Attachments {
			class acc_flashlight {};
			class acc_flashlight_pistol {};
			class acc_pointer_IR {};
			class optic_MRD {};
			class optic_Aco {};
			class optic_Holosight {};
		};

		class Magazines {
			class 10Rnd_9x21_Mag {};
			class 16Rnd_9x21_Mag {};
			class 30Rnd_9x21_Mag {};
			class 9Rnd_45ACP_Mag {};
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
			class Binocular {};
			class ToolKit {};
			class Chemlight_green {};
			class SmokeShell {};
		};
	};

	class Rebel {
		storeName = "Rebel Outpost";
		condition = "[""Rebel""] call ULP_fnc_hasLicense";
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
			class Chemlight_green {};
			class SmokeShell {};
		};
	};

	class Blackmarket {
		storeName = "Blackmarket";
		condition = "[""Blackmarket""] call ULP_fnc_hasLicense && { [""Blackmarketer""] call ULP_fnc_hasPerk }";
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
			class srifle_DMR_06_hunter_F {};
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
			class Chemlight_green {};
			class SmokeShell {};
		};
	};
};