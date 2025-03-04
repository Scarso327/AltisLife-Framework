class CfgItemsStore {
	onItemBuy = "_this call ULP_fnc_onBuyItems";
	toolBoxIDC = 3113;
	itemCfg = "CfgItems";

	class Police {
		storeName = "Equipment Store";
		condition = "[player, [""Police""]] call ULP_fnc_isFaction";
		class Rifles {
			// SPECIAL
			class arifle_Mk20C_plain_F {
				displayName = "Rubber Bullet Gun";
				class textures { class arifle_Mk20C_plain_F {}; };
			};
			class arifle_SDAR_F { condition = "[""Police_MPU"", 1] call ULP_fnc_hasAccess || { [""Police_Main"", 2] call ULP_fnc_hasAccess && !(missionNamespace getVariable [""ULP_SRV_Crime_HMSLiberty"", false]) }"; };

			// SUB-MACHINE GUNS
			class SMG_05_F { condition = "[""Police_Main"", 2] call ULP_fnc_hasAccess"; }; 
			class SMG_01_F { condition = "[""Police_Main"", 2] call ULP_fnc_hasAccess"; };
			class SMG_03C_black { 
				condition = "[""Police_Main"", 2] call ULP_fnc_hasAccess"; 
				class textures { class SMG_03C_black {}; };
			};
			class SMG_03_black { 
				condition = "[""Police_Main"", 2] call ULP_fnc_hasAccess";
				class textures { class SMG_03_black {}; }; 
			};

			// ASSAULT RIFLES
			class arifle_SPAR_01_blk_F {
				condition = "[""Police_Main"", 2] call ULP_fnc_hasAccess";
				class textures { class arifle_SPAR_01_blk_F {}; };
			};
			class arifle_SPAR_01_GL_blk_F {
				condition = "[""Police_SCO"", 2] call ULP_fnc_hasAccess";
				class textures { class arifle_SPAR_01_GL_blk_F {}; };
			};
			class arifle_CTAR_blk_F {
				condition = "[""Police_Main"", 3] call ULP_fnc_hasAccess";
				class textures { class arifle_CTAR_blk_F {}; };
			};
			class arifle_CTAR_GL_blk_F {
				condition = "[""Police_SCO"", 2] call ULP_fnc_hasAccess";
				class textures { class arifle_CTAR_GL_blk_F {}; };
			};
			class arifle_MX_Black_F {
				condition = "[""Police_Main"", 4] call ULP_fnc_hasAccess || { [""Police_SCO"", 1] call ULP_fnc_hasAccess } || { [""Police_NCA"", 1] call ULP_fnc_hasAccess } || { [""Police_SEG"", 1] call ULP_fnc_hasAccess } || { ([""Police_Main"", 3] call ULP_fnc_hasAccess && [""Police_SFO"", 1] call ULP_fnc_hasAccess) }";
				class textures { class arifle_MX_Black_F {}; };
			};
			class arifle_MXM_Black_F {
				condition = "[""Police_Main"", 5] call ULP_fnc_hasAccess || { [""Police_SCO"", 1] call ULP_fnc_hasAccess } || { [""Police_NCA"", 2] call ULP_fnc_hasAccess } || { [""Police_MPU"", 2] call ULP_fnc_hasAccess } || { [""Police_SEG"", 2] call ULP_fnc_hasAccess } || { ([""Police_Main"", 4] call ULP_fnc_hasAccess && [""Police_SFO"", 1] call ULP_fnc_hasAccess) }";
				class textures { class arifle_MXM_Black_F {}; };
			}; 
			class arifle_MX_GL_Black_F {
				condition = "[""Police_SCO"", 2] call ULP_fnc_hasAccess";
				class textures { class arifle_MX_GL_Black_F {}; };
			};
			class arifle_MSBS65_black_F {
				condition = "[""Police_Main"", 3] call ULP_fnc_hasAccess";
				class textures { class arifle_MSBS65_black_F {}; };
			};
			class arifle_MSBS65_Mark_black_F {
				condition = "[""Police_Main"", 5] call ULP_fnc_hasAccess || { [""Police_SCO"", 1] call ULP_fnc_hasAccess } || { [""Police_NCA"", 2] call ULP_fnc_hasAccess } || { ([""Police_Main"", 4] call ULP_fnc_hasAccess && [""Police_SFO"", 1] call ULP_fnc_hasAccess) }";
				class textures { class arifle_MSBS65_Mark_black_F {}; };
			};
			class arifle_MSBS65_UBS_black_F {
				condition = "[""Police_SCO"", 3] call ULP_fnc_hasAccess";
				class textures { class arifle_MSBS65_UBS_black_F {}; };
			};
			class arifle_MSBS65_GL_black_F {
				condition = "[""Police_SCO"", 2] call ULP_fnc_hasAccess";
				class textures { class arifle_MSBS65_GL_black_F {}; };
			};
			class arifle_Katiba_C_F { condition = "[""Police_Main"", 3] call ULP_fnc_hasAccess"; };
			class arifle_Katiba_F { condition = "[""Police_Main"", 4] call ULP_fnc_hasAccess || { [""Police_SCO"", 1] call ULP_fnc_hasAccess } || { [""Police_NCA"", 2] call ULP_fnc_hasAccess } || { ([""Police_Main"", 3] call ULP_fnc_hasAccess && [""Police_SFO"", 1] call ULP_fnc_hasAccess) }"; };
			class arifle_Katiba_GL_F { condition = "[""Police_SCO"", 2] call ULP_fnc_hasAccess"; };
			class arifle_ARX_blk_F {
				condition = "[""Police_Main"", 6] call ULP_fnc_hasAccess || { [""Police_SCO"", 1] call ULP_fnc_hasAccess } || { [""Police_NCA"", 3] call ULP_fnc_hasAccess } || { ([""Police_Main"", 6] call ULP_fnc_hasAccess && [""Police_SFO"", 1] call ULP_fnc_hasAccess) }";
				class textures { class arifle_ARX_blk_F {}; };
			};

			// MARKSMAN RIFLES
			class arifle_SPAR_03_blk_F {
				condition = "[""Police_Main"", 7] call ULP_fnc_hasAccess || { [""Police_SCO"", 1] call ULP_fnc_hasAccess } || { [""Police_NCA"", 3] call ULP_fnc_hasAccess } || { [""Police_SEG"", 3] call ULP_fnc_hasAccess } || { ([""Police_Main"", 5] call ULP_fnc_hasAccess && [""Police_SFO"", 1] call ULP_fnc_hasAccess) }";
				class textures { class arifle_SPAR_03_blk_F {}; };
			};
			class srifle_EBR_F {
				condition = "[""Police_SCO"", 2] call ULP_fnc_hasAccess";
				class textures { class srifle_EBR_F {}; };
			};
			class srifle_DMR_03_F {
				condition = "[""Police_SCO"", 2] call ULP_fnc_hasAccess";
				class textures { class srifle_DMR_03_F {}; };
			};

			// SUPPORT RIFLES
			class arifle_SPAR_02_blk_F {
				condition = "[""Police_Main"", 6] call ULP_fnc_hasAccess || { [""Police_SCO"", 1] call ULP_fnc_hasAccess } || { [""Police_NCA"", 1] call ULP_fnc_hasAccess } || { [""Police_SEG"", 2] call ULP_fnc_hasAccess } || { [""Police_Main"", 5] call ULP_fnc_hasAccess && { [""Police_SFO"", 1] call ULP_fnc_hasAccess } }";
				class textures { class arifle_SPAR_02_blk_F {}; };
			};
			class arifle_CTARS_blk_F {
				condition = "[""Police_Main"", 6] call ULP_fnc_hasAccess || { [""Police_SCO"", 1] call ULP_fnc_hasAccess } || { [""Police_NCA"", 2] call ULP_fnc_hasAccess } || { [""Police_Main"", 5] call ULP_fnc_hasAccess && { [""Police_SFO"", 1] call ULP_fnc_hasAccess } }";
				class textures { class arifle_CTARS_blk_F {}; };
			};
			class arifle_MX_SW_Black_F {
				condition = "[""Police_Main"", 10] call ULP_fnc_hasAccess || { [""Police_SCO"", 2] call ULP_fnc_hasAccess } || { [""Police_NCA"", 3] call ULP_fnc_hasAccess } || { [""Police_SEG"", 3] call ULP_fnc_hasAccess } || { [""Police_Main"", 6] call ULP_fnc_hasAccess && { [""Police_SFO"", 1] call ULP_fnc_hasAccess } }";
				class textures { class arifle_MX_SW_Black_F {}; };
			};
		};
		class Pistols {
			class hgun_P07_F {};
			class hgun_ACPC2_F { condition = "[""Police_SCO"", 1] call ULP_fnc_hasAccess || { [""Police_NCA"", 1] call ULP_fnc_hasAccess } || { [""Police_NPAS"", 1] call ULP_fnc_hasAccess } || { [""Police_RPU"", 1] call ULP_fnc_hasAccess } || { [""Police_MPU"", 1] call ULP_fnc_hasAccess } || { [""Police_SEG"", 1] call ULP_fnc_hasAccess } || { [""Police_Main"", 2] call ULP_fnc_hasAccess && { [""Police_SFO"", 1] call ULP_fnc_hasAccess } }"; };
		};
		class Attachments {
			class bipod_01_F_blk { 
				class textures {
					class bipod_01_F_blk {};
					class bipod_02_F_blk {};
					class bipod_03_F_blk {};
				};
			};
			class acc_flashlight {};
			class acc_pointer_IR {};
			class optic_Aco {};
			class optic_Holosight {
				class textures {
					class optic_Holosight_blk_F {};
					class optic_Holosight_smg_blk_F {};
				};
			};
			class optic_ico_01_black_f {
				condition = "[""Police_Main"", 3] call ULP_fnc_hasAccess";
				class textures { class optic_ico_01_black_f {}; };
			};
			class optic_Hamr {
				condition = "[""Police_Main"", 2] call ULP_fnc_hasAccess";
				class textures { class optic_Hamr {}; };
			};
			class optic_MRCO { condition = "[""Police_Main"", 2] call ULP_fnc_hasAccess"; };
			class optic_Arco {
				condition = "[""Police_Main"", 2] call ULP_fnc_hasAccess";
				class textures { class optic_Arco_blk_F {}; };
			};
			class optic_ERCO_blk_F { condition = "[""Police_Main"", 2] call ULP_fnc_hasAccess"; };
			class optic_DMS {
				condition = "[""Police_SCO"", 1] call ULP_fnc_hasAccess || { [""Police_NCA"", 3] call ULP_fnc_hasAccess } || { [""Police_SEG"", 3] call ULP_fnc_hasAccess } || { [""Police_Main"", 7] call ULP_fnc_hasAccess && { [""Police_SFO"", 1] call ULP_fnc_hasAccess } }";
				class textures { class optic_DMS {}; };
			};
			class optic_AMS {
				condition = "[""Police_SCO"", 3] call ULP_fnc_hasAccess";
				class textures { class optic_AMS {}; };
			};
      		class optic_NVS { condition = "[""Police_SCO"", 1] call ULP_fnc_hasAccess || { [""Police_NCA"", 1] call ULP_fnc_hasAccess }"; };
			class muzzle_snds_L { condition = "[""Police_SCO"", 2] call ULP_fnc_hasAccess || { [""Police_NCA"", 2] call ULP_fnc_hasAccess }"; };
			class muzzle_snds_acp { condition = "[""Police_SCO"", 2] call ULP_fnc_hasAccess || { [""Police_NCA"", 2] call ULP_fnc_hasAccess }"; };
			class muzzle_snds_M { 
				condition = "[""Police_SCO"", 2] call ULP_fnc_hasAccess || { [""Police_NCA"", 2] call ULP_fnc_hasAccess }"; 
				class textures { class muzzle_snds_M {}; };
			};
			class muzzle_snds_570 { condition = "[""Police_SCO"", 2] call ULP_fnc_hasAccess || { [""Police_NCA"", 2] call ULP_fnc_hasAccess }"; };
			class muzzle_snds_58_blk_F { 
				condition = "[""Police_SCO"", 2] call ULP_fnc_hasAccess || { [""Police_NCA"", 2] call ULP_fnc_hasAccess }";
				class textures { class muzzle_snds_58_blk_F {}; };
			};
		};
		class Magazines {
			class 16Rnd_9x21_Mag { displayName = "Taser Cartridge"; };
			class 30Rnd_9x21_Mag_SMG_02 { condition = "[""Police_Main"", 2] call ULP_fnc_hasAccess"; };
			class 30Rnd_45ACP_Mag_SMG_01 : 30Rnd_9x21_Mag_SMG_02 {};
			class 9Rnd_45ACP_Mag { condition = "[""Police_SCO"", 1] call ULP_fnc_hasAccess || { [""Police_NCA"", 1] call ULP_fnc_hasAccess } || { [""Police_NPAS"", 1] call ULP_fnc_hasAccess } || { [""Police_RPU"", 1] call ULP_fnc_hasAccess } || { [""Police_MPU"", 1] call ULP_fnc_hasAccess } || { [""Police_Main"", 2] call ULP_fnc_hasAccess && { [""Police_SFO"", 1] call ULP_fnc_hasAccess } }"; };
			class 50Rnd_570x28_SMG_03 { condition = "[""Police_Main"", 2] call ULP_fnc_hasAccess"; };
			class 30Rnd_556x45_Stanag_Tracer_Red { 
				displayName = "Rubber Bullet Mag"; 
				class textures { class 30Rnd_556x45_Stanag_Tracer_Green {}; }; 
			};
			class 20Rnd_556x45_UW_mag { condition = "[""Police_MPU"", 1] call ULP_fnc_hasAccess || { [""Police_Main"", 2] call ULP_fnc_hasAccess && { missionNamespace getVariable [""ULP_SRV_Crime_HMSLiberty"", false] } }"; };
			class 30Rnd_556x45_Stanag { condition = "[""Police_Main"", 2] call ULP_fnc_hasAccess"; };
			class 150Rnd_556x45_Drum_Mag_F { condition = "[""Police_Main"", 6] call ULP_fnc_hasAccess || { [""Police_SCO"", 1] call ULP_fnc_hasAccess } || { [""Police_NCA"", 1] call ULP_fnc_hasAccess } || { [""Police_SEG"", 2] call ULP_fnc_hasAccess } || { [""Police_Main"", 5] call ULP_fnc_hasAccess && [""Police_SFO"", 1] call ULP_fnc_hasAccess }"; };
			class 150Rnd_556x45_Drum_Mag_Tracer_F : 150Rnd_556x45_Drum_Mag_F {};			
			class 30Rnd_580x42_Mag_F { condition = "[""Police_Main"", 3] call ULP_fnc_hasAccess"; };
			class 30Rnd_580x42_Mag_Tracer_F : 30Rnd_580x42_Mag_F {};
			class 100Rnd_580x42_Mag_F { condition = "[""Police_Main"", 6] call ULP_fnc_hasAccess || { [""Police_SCO"", 1] call ULP_fnc_hasAccess } || { [""Police_NCA"", 2] call ULP_fnc_hasAccess } || { [""Police_Main"", 5] call ULP_fnc_hasAccess && [""Police_SFO"", 1] call ULP_fnc_hasAccess }"; };
			class 100Rnd_580x42_Mag_Tracer_F : 100Rnd_580x42_Mag_F {};
			class 30Rnd_65x39_caseless_green { condition = "[""Police_Main"", 3] call ULP_fnc_hasAccess"; };
			class 30Rnd_65x39_caseless_green_mag_Tracer : 30Rnd_65x39_caseless_green {};
			class 30Rnd_65x39_caseless_msbs_mag { condition = "[""Police_Main"", 3] call ULP_fnc_hasAccess"; };
			class 30Rnd_65x39_caseless_msbs_mag_Tracer : 30Rnd_65x39_caseless_msbs_mag {};
			class 30Rnd_65x39_caseless_black_mag { 
				condition = "[""Police_Main"", 4] call ULP_fnc_hasAccess || { [""Police_SCO"", 1] call ULP_fnc_hasAccess } || { [""Police_NCA"", 1] call ULP_fnc_hasAccess } || { [""Police_MPU"", 2] call ULP_fnc_hasAccess } || { [""Police_SEG"", 1] call ULP_fnc_hasAccess } || { ([""Police_Main"", 3] call ULP_fnc_hasAccess && [""Police_SFO"", 1] call ULP_fnc_hasAccess) }";
				class textures { class 30Rnd_65x39_caseless_black_mag {}; }; 
			};
			class 30Rnd_65x39_caseless_black_mag_Tracer : 30Rnd_65x39_caseless_black_mag { class textures { class 30Rnd_65x39_caseless_black_mag_Tracer {}; }; };
			class 100Rnd_65x39_caseless_black_mag {
				condition = "[""Police_Main"", 7] call ULP_fnc_hasAccess || { [""Police_SCO"", 2] call ULP_fnc_hasAccess } || { [""Police_NCA"", 3] call ULP_fnc_hasAccess } || { [""Police_SEG"", 3] call ULP_fnc_hasAccess } || { ([""Police_Main"", 6] call ULP_fnc_hasAccess && [""Police_SFO"", 1] call ULP_fnc_hasAccess) }";
				class textures { class 100Rnd_65x39_caseless_black_mag {}; }; 
			};
			class 100Rnd_65x39_caseless_black_mag_tracer : 100Rnd_65x39_caseless_black_mag { class textures { class 100Rnd_65x39_caseless_black_mag_tracer {}; }; };
			class 20Rnd_762x51_Mag { condition = "[""Police_Main"", 7] call ULP_fnc_hasAccess || { [""Police_SCO"", 1] call ULP_fnc_hasAccess } || { [""Police_NCA"", 3] call ULP_fnc_hasAccess } || { [""Police_SEG"", 3] call ULP_fnc_hasAccess } || { ([""Police_Main"", 6] call ULP_fnc_hasAccess && [""Police_SFO"", 1] call ULP_fnc_hasAccess) }"; };
			class 6Rnd_12Gauge_Slug { condition = "[""Police_SCO"", 3] call ULP_fnc_hasAccess"; };
			class UGL_FlareWhite_F {
				condition = "[""Police_SCO"", 2] call ULP_fnc_hasAccess";
				class textures { class UGL_FlareWhite_F {}; }; 
			};
			class 1Rnd_Smoke_Grenade_shell : UGL_FlareWhite_F { class textures { class 1Rnd_Smoke_Grenade_shell {}; }; };
		};
		class Items {
			class ItemMap {};
			class ItemCompass {};
			class ItemWatch {};
			class ItemGPS {};
			//class B_UavTerminal { condition = "[""Police_Main"", 8] call ULP_fnc_hasAccess || { [""Police_NPAS"", 1] call ULP_fnc_hasAccess } || { [""Police_NCA"", 2] call ULP_fnc_hasAccess }"; };
			class ItemRadio {};
			class Rangefinder {};
			class ToolKit {};
			class NVGoggles {
				condition = "[""Police_SCO"", 1] call ULP_fnc_hasAccess || { [""Police_NCA"", 1] call ULP_fnc_hasAccess }";
				class textures { class NVGoggles_OPFOR {}; };
			};
			class Chemlight_green {};
			class SmokeShell { 
				condition = "[""Police_SCO"", 1] call ULP_fnc_hasAccess";
				class textures { class SmokeShell {}; }; 
			};
		};
	};

	class Medic : Police {
		condition = "[player, [""Medic""]] call ULP_fnc_isFaction";
		default = 4;
		class Rifles {};
		class Pistols {};
		class Attachments {};
		class Magazines {};
		class Items {
			class ItemMap {};
			class ItemCompass {};
			class ItemWatch {};
			class ItemGPS {};
			//class C_UavTerminal { condition = "[""Medic_HART"", 1] call ULP_fnc_hasAccess"; };
			class ItemRadio {};
			class Rangefinder {};
			class ToolKit {};
			class Chemlight_green {};
		};
	};

	class Hato : Medic {
		condition = "[player, [""Hato""]] call ULP_fnc_isFaction";
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
			class Chemlight_green {};
		};
	};

	class Dunamis {
		storeName = "Dunamis Equipment Store";
		condition = "[] call ULP_fnc_isDunamis";
		class Rifles {
			// SMGs
			class hgun_PDW2000_F { price = 48672; };
			class SMG_05_F { price = 50720; };
			class SMG_02_F { price = 55370; };
			class SMG_01_F { price = 57564; };
			class SMG_03C_black { price = 74120; };
			class SMG_03_black { price = 76664; };

			// Special
			class arifle_SDAR_F {};
			class sgun_HunterShotgun_01_sawedoff_F { price = 55283; };

			// Rifles
			class arifle_AKS_F { price = 68679; };
			class arifle_TRG20_F { price = 84474; };
			class arifle_Mk20C_plain_F { price = 82485; };
			class arifle_Mk20_plain_F { price = 85615; };
			class arifle_SPAR_01_blk_F { price = 100708; };
			class arifle_CTAR_hex_F { price = 115596; };
			class srifle_DMR_07_blk_F { price = 137633; };
			class arifle_MSBS65_black_F { 
				price = 160853;
				condition = "([] call ULP_fnc_getGroupRank) >= 3"; 
			};
			class arifle_MSBS65_Mark_F { 
				price = 160751;
				condition = "([] call ULP_fnc_getGroupRank) >= 3"; 
			};
			class arifle_MXC_Black_F { 
				price = 133130;
				condition = "([] call ULP_fnc_getGroupRank) >= 2"; 
			};
			class arifle_MX_Black_F { 
				price = 172395;
				condition = "([] call ULP_fnc_getGroupRank) >= 2"; 
			};
			class arifle_MXM_Black_F { 
				price = 188865;
				condition = "([] call ULP_fnc_getGroupRank) >= 3"; 
			};
			class arifle_Katiba_C_F { 
				price = 157667;
				condition = "([] call ULP_fnc_getGroupRank) >= 2"; 
			};
			class arifle_Katiba_F { 
				price = 163215;
				condition = "([] call ULP_fnc_getGroupRank) >= 2"; 
			};
			class arifle_ARX_blk_F { 
				price = 202905;
				condition = "([] call ULP_fnc_getGroupRank) >= 4 && { [""ParosCheckpoint""] call ULP_fnc_ownsSite }"; 
			};
			class srifle_DMR_01_F { 
				price = 232956;
				condition = "([] call ULP_fnc_getGroupRank) >= 5"; 
			};
			class arifle_AK12U_F { 
				price = 279045;
				condition = "([] call ULP_fnc_getGroupRank) >= 5"; 
			};
			class arifle_AK12_F { 
				price = 292005;
				condition = "([] call ULP_fnc_getGroupRank) >= 5"; 
			};
			class srifle_DMR_06_olive_F { 
				price = 301320;
				condition = "([] call ULP_fnc_getGroupRank) >= 5 && { [""ParosCheckpoint""] call ULP_fnc_ownsSite }"; 
			};
			class srifle_DMR_04_F { 
				price = 801405;
				condition = "([] call ULP_fnc_getGroupRank) >= 6 && { [""ParosCheckpoint""] call ULP_fnc_ownsSite }"; 
			};

			// Support Weapons
			class LMG_03_F { 
				price = 186586;
				condition = "([] call ULP_fnc_getGroupRank) >= 4 && { [""ParosCheckpoint""] call ULP_fnc_ownsSite }"; 
			};
			class arifle_SPAR_02_blk_F { 
				price = 117293;
				condition = "([] call ULP_fnc_getGroupRank) >= 3"; 
			};
			class arifle_CTARS_blk_F { 
				price = 128349;
				condition = "([] call ULP_fnc_getGroupRank) >= 4"; 
			};
			class arifle_MX_SW_Black_F { 
				price = 222548;
				condition = "([] call ULP_fnc_getGroupRank) >= 5"; 
			};
			class LMG_Mk200_F { 
				price = 314888;
				condition = "([] call ULP_fnc_getGroupRank) >= 6 && { [""ParosCheckpoint""] call ULP_fnc_ownsSite }"; 
			};
		};
		class Pistols {
			class hgun_Pistol_01_F { price = 12636; };
			class hgun_Rook40_F { price = 17609; };
			class hgun_ACPC2_F { price = 24570; };
			class hgun_Pistol_heavy_01_F { price = 25126; };
			class hgun_Pistol_heavy_02_F { 
				price = 35861;
				condition = "([] call ULP_fnc_getGroupRank) >= 7"; 
			};
		};
		class Attachments {
			// Rail
			class bipod_01_F_blk {};
			class acc_flashlight_pistol {};
			class acc_flashlight {};
			class acc_pointer_IR {};

			// Sights
			class optic_Yorris {};
			class optic_Aco {};
			class optic_Holosight {};
			class optic_ico_01_black_f {};
			class optic_Hamr {};
			class optic_MRCO {};
			class optic_Arco {};
			class optic_ERCO_blk_F {};
			class optic_DMS { condition = "[""ParosCheckpoint""] call ULP_fnc_ownsSite"; };

			// Barrel
			class muzzle_snds_L { condition = "[""GhostHotel""] call ULP_fnc_ownsSite"; };
			class muzzle_snds_acp { condition = "[""GhostHotel""] call ULP_fnc_ownsSite"; };
			class muzzle_snds_M { condition = "([] call ULP_fnc_getGroupRank) >= 3 &&  { [""GhostHotel""] call ULP_fnc_ownsSite }"; };
			class muzzle_snds_570 { condition = "([] call ULP_fnc_getGroupRank) >= 3 &&  { [""GhostHotel""] call ULP_fnc_ownsSite }"; };
			class muzzle_snds_58_blk_F { condition = "([] call ULP_fnc_getGroupRank) >= 3 &&  { [""GhostHotel""] call ULP_fnc_ownsSite }"; };
		};
		class Magazines {
			class 10Rnd_9x21_Mag { price = 39; };
			class 16Rnd_9x21_Mag { price = 51; };
			class 30Rnd_9x21_Mag { price = 102; };
			class 30Rnd_9x21_Mag_SMG_02 { price = 180; };
			class 30Rnd_9x21_Mag_SMG_02_Tracer_Red : 30Rnd_9x21_Mag_SMG_02 {};
			class 9Rnd_45ACP_Mag { price = 50; };
			class 11Rnd_45ACP_Mag { price = 66; };
			class 30Rnd_45ACP_Mag_SMG_01 { price = 258; };
			class 30Rnd_45ACP_Mag_SMG_01_Tracer_Green : 30Rnd_45ACP_Mag_SMG_01 {};
			class 6Rnd_45ACP_Cylinder { 
				price = 57; 
				condition = "([] call ULP_fnc_getGroupRank) >= 7";
			};
			class 2Rnd_12Gauge_Pellets { price = 360; };
			class 2Rnd_12Gauge_Slug { price = 405; };
			class 30Rnd_545x39_Mag_F { price = 690; };
			class 50Rnd_570x28_SMG_03 { price = 792; };
			class 20Rnd_556x45_UW_mag {};
			class 30Rnd_556x45_Stanag { price = 690; };
			class 30Rnd_556x45_Stanag_Tracer_Red : 30Rnd_556x45_Stanag {};
			class 150Rnd_556x45_Drum_Mag_F { 
				price = 4890; 
				condition = "([] call ULP_fnc_getGroupRank) >= 3";
			};
			class 150Rnd_556x45_Drum_Mag_Tracer_F : 150Rnd_556x45_Drum_Mag_F {};
			class 200Rnd_556x45_Box_F { 
				price = 6450; 
				condition = "([] call ULP_fnc_getGroupRank) >= 4 && { [""ParosCheckpoint""] call ULP_fnc_ownsSite }";
			};

			class 30Rnd_580x42_Mag_F { price = 825; };
			class 30Rnd_580x42_Mag_Tracer_F : 30Rnd_580x42_Mag_F {};
			class 100Rnd_580x42_Mag_F { 
				price = 5670;
				condition = "([] call ULP_fnc_getGroupRank) >= 4"; 
			};
			class 100Rnd_580x42_Mag_Tracer_F : 100Rnd_580x42_Mag_F {};

			class 20Rnd_650x39_Cased_Mag_F { price = 840; };
			class 30Rnd_65x39_caseless_green { 
				price = 915; 
				condition = "([] call ULP_fnc_getGroupRank) >= 2";
			};
			class 30Rnd_65x39_caseless_green_mag_Tracer : 30Rnd_65x39_caseless_green {};
			class 30Rnd_65x39_caseless_msbs_mag { 
				price = 921; 
				condition = "([] call ULP_fnc_getGroupRank) >= 3";
			};
			class 30Rnd_65x39_caseless_msbs_mag_Tracer : 30Rnd_65x39_caseless_msbs_mag {};
			class 30Rnd_65x39_caseless_black_mag { 
				price = 1047; 
				condition = "([] call ULP_fnc_getGroupRank) >= 2";
			};
			class 30Rnd_65x39_caseless_black_mag_Tracer : 30Rnd_65x39_caseless_black_mag {};
			class 100Rnd_65x39_caseless_black_mag { 
				price = 7080; 
				condition = "([] call ULP_fnc_getGroupRank) >= 5";
			};
			class 100Rnd_65x39_caseless_black_mag_tracer : 100Rnd_65x39_caseless_black_mag {};
			class 200Rnd_65x39_cased_Box { 
				price = 9915; 
				condition = "([] call ULP_fnc_getGroupRank) >= 6 && { [""ParosCheckpoint""] call ULP_fnc_ownsSite }";
			};
			class 200Rnd_65x39_cased_Box_Tracer : 200Rnd_65x39_cased_Box {};

			class 10Rnd_762x54_Mag { 
				price = 1440;
				condition = "([] call ULP_fnc_getGroupRank) >= 5"; 
			};
			class 10Rnd_Mk14_762x51_Mag { 
				price = 1608;
				condition = "([] call ULP_fnc_getGroupRank) >= 5 && { [""ParosCheckpoint""] call ULP_fnc_ownsSite }"; 
			};
			class 20Rnd_762x51_Mag {
				price = 2970;
				condition = "([] call ULP_fnc_getGroupRank) >= 5 && { [""ParosCheckpoint""] call ULP_fnc_ownsSite }"; 
			};
			class 30Rnd_762x39_AK12_Mag_F { 
				price = 4434;
				condition = "([] call ULP_fnc_getGroupRank) >= 5"; 
			};
			class 30Rnd_762x39_AK12_Mag_Tracer_F : 30Rnd_762x39_AK12_Mag_F {};

			class 10Rnd_127x54_Mag {
				price = 21619;
				condition = "([] call ULP_fnc_getGroupRank) >= 6 && { [""ParosCheckpoint""] call ULP_fnc_ownsSite }"; 
			};
		};
		class Items {
			class ItemMap {};
			class ItemCompass {};
			class ItemWatch {};
			class ItemGPS {};
			class ItemRadio {};
			class Binocular {};
			class Rangefinder {};
			class NVGoggles {};
			class O_NVGoggles_grn_F { condition = "[] call ULP_fnc_donatorLevel > 0"; };
			class Chemlight_green {};
			class SmokeShell { condition = "[""GhostHotel""] call ULP_fnc_ownsSite"; };
			class ToolKit {};
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
			class ItemMap {};
			class ItemCompass {};
			class ItemWatch {};
			class ItemGPS {};
			class ItemRadio {};
			class Binocular {};
			class ToolKit {};
		};
	};

	class Gun {
		storeName = "Gun Store";
		condition = "[""Handgun""] call ULP_fnc_hasLicense || { [""SMG""] call ULP_fnc_hasLicense }";
		class Rifles {
			class hgun_PDW2000_F { condition = "[""SMG""] call ULP_fnc_hasLicense"; };
			class SMG_05_F { condition = "[""SMG""] call ULP_fnc_hasLicense"; };
			class SMG_02_F { condition = "[""SMG""] call ULP_fnc_hasLicense"; };
		};
		class Pistols {
			class hgun_Pistol_01_F {};
			class hgun_Rook40_F {};
			class hgun_ACPC2_F {};
			class hgun_Pistol_heavy_01_F {};
			class hgun_Pistol_heavy_02_F {};
		};
		class Attachments {
			class optic_Aco { condition = "[""SMG""] call ULP_fnc_hasLicense"; };
			class optic_Holosight { condition = "[""SMG""] call ULP_fnc_hasLicense"; };
		};
		class Magazines {
			class 10Rnd_9x21_Mag {};
			class 16Rnd_9x21_Mag {};
			class 30Rnd_9x21_Mag { condition = "[""SMG""] call ULP_fnc_hasLicense"; };
			class 30Rnd_9x21_Mag_SMG_02 { condition = "[""SMG""] call ULP_fnc_hasLicense"; };
			class 9Rnd_45ACP_Mag {};
			class 11Rnd_45ACP_Mag {};
			class 6Rnd_45ACP_Cylinder {};
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

	class Security {
		storeName = "Company Security Store";
		condition = "[] call ULP_fnc_isSecurity";
		class Rifles {
			class hgun_PDW2000_F { price = 60100; };
			class SMG_05_F { price = 60075; };
			class SMG_02_F { price = 63825; };
			class SMG_01_F { price = 70125; };
			class SMG_03C_black {
				price = 67250;
				class textures {
					class SMG_03C_black {};
					class SMG_03C_TR_black {};
				};
			};
			class SMG_03_black {
				price = 83350;
				class textures {
					class SMG_03_black {};
					class SMG_03_TR_black {};
				};
			};
			class arifle_SPAR_01_blk_F {
				price = 127075;
				class textures {
					class arifle_SPAR_01_blk_F {};
				};
			};
		};
		class Pistols {
			class hgun_Rook40_F { price = 16550; };
			class hgun_ACPC2_F { price = 22500; };
		};
		class Attachments {
			class bipod_01_F_blk { 
				class textures {
					class bipod_01_F_blk {};
					class bipod_02_F_blk {};
					class bipod_03_F_blk {};
				};
			};
			class acc_flashlight {};

			// SIGHTS
			class optic_Aco {};
			class optic_Holosight {
				class textures {
					class optic_Holosight_blk_F {};
					class optic_Holosight_smg_blk_F {};
				};
			};
			class optic_Hamr {
				class textures { class optic_Hamr {}; };
			};
			class optic_MRCO {};
			class optic_Arco {
				class textures { class optic_Arco_blk_F {}; };
			};
			class optic_ERCO_blk_F {};
		};
		class Magazines {
			class 16Rnd_9x21_Mag {};
			class 30Rnd_9x21_Mag {};
			class 30Rnd_9x21_Mag_SMG_02 {};
			class 30Rnd_9x21_Mag_SMG_02_Tracer_Red {};
			class 9Rnd_45ACP_Mag {};
			class 30Rnd_45ACP_Mag_SMG_01 {};
			class 30Rnd_45ACP_Mag_SMG_01_Tracer_Green {};
			class 50Rnd_570x28_SMG_03 {};
			class 30Rnd_556x45_Stanag {};
			class 30Rnd_556x45_Stanag_Tracer_Red {};
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

	class Protection {
		storeName = "Govenor Protection Store";
		condition = "[] call ULP_fnc_isProtection";
		class Rifles {
			class hgun_PDW2000_F { price = 60100; };
			class SMG_05_F { price = 60075; };
			class SMG_02_F { price = 63825; };
			class SMG_01_F { price = 70125; };
			class SMG_03C_black {
				price = 67250;
				class textures {
					class SMG_03C_black {};
					class SMG_03C_TR_black {};
				};
			};
			class SMG_03_black {
				price = 83350;
				class textures {
					class SMG_03_black {};
					class SMG_03_TR_black {};
				};
			};
			class arifle_SPAR_01_blk_F {
				price = 127075;
				class textures {
					class arifle_SPAR_01_blk_F {};
				};
			};
		};
		class Pistols {
			class hgun_Rook40_F { price = 16550; };
			class hgun_ACPC2_F { price = 22500; };
		};
		class Attachments {
			class bipod_01_F_blk { 
				class textures {
					class bipod_01_F_blk {};
					class bipod_02_F_blk {};
					class bipod_03_F_blk {};
				};
			};
			class acc_flashlight {};

			// SIGHTS
			class optic_Aco {};
			class optic_Holosight {
				class textures {
					class optic_Holosight_blk_F {};
					class optic_Holosight_smg_blk_F {};
				};
			};
			class optic_Hamr {
				class textures { class optic_Hamr {}; };
			};
			class optic_MRCO {};
			class optic_Arco {
				class textures { class optic_Arco_blk_F {}; };
			};
			class optic_ERCO_blk_F {};
		};
		class Magazines {
			class 16Rnd_9x21_Mag {};
			class 30Rnd_9x21_Mag {};
			class 30Rnd_9x21_Mag_SMG_02 {};
			class 30Rnd_9x21_Mag_SMG_02_Tracer_Red {};
			class 9Rnd_45ACP_Mag {};
			class 30Rnd_45ACP_Mag_SMG_01 {};
			class 30Rnd_45ACP_Mag_SMG_01_Tracer_Green {};
			class 50Rnd_570x28_SMG_03 {};
			class 30Rnd_556x45_Stanag {};
			class 30Rnd_556x45_Stanag_Tracer_Red {};
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

	class Safehouse {
		storeName = "Safehouse Store";
		condition = "[] call ULP_fnc_isProtection && { [""GovernmentSafehouses""] call ULP_fnc_hasGroupPerk }";
		class Rifles {
			class hgun_PDW2000_F { price = 0; };
		};
		class Pistols {
			class hgun_Rook40_F { price = 0; };
		};
		class Attachments {};
		class Magazines {
			class 30Rnd_9x21_Mag {};
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
			class arifle_TRG21_F {};
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
			class 30Rnd_45ACP_Mag_SMG_01_Tracer_Green {};
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
			class arifle_TRG21_F {};
			class arifle_Mk20_plain_F {};
			class arifle_SPAR_01_blk_F {};
			class arifle_CTAR_blk_F {};
			class srifle_DMR_07_blk_F {};
			class arifle_Katiba_C_F {}; 
			class arifle_Katiba_F {};
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
			class optic_ico_01_black_f {};
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
			class 30Rnd_9x21_Mag_SMG_02_Tracer_Red {};
			class 9Rnd_45ACP_Mag {};
			class 11Rnd_45ACP_Mag {};
			class 6Rnd_45ACP_Cylinder {};
			class 30Rnd_45ACP_Mag_SMG_01 {};
			class 30Rnd_45ACP_Mag_SMG_01_Tracer_Green {};
			class 2Rnd_12Gauge_Pellets {};
			class 2Rnd_12Gauge_Slug {};
			class 30Rnd_545x39_Mag_F {};
			class 50Rnd_570x28_SMG_03 {};
			class 20Rnd_556x45_UW_mag  {};
			class 30Rnd_556x45_Stanag {};
			class 30Rnd_556x45_Stanag_Tracer_Red {};
			class 30Rnd_580x42_Mag_F {};
			class 30Rnd_580x42_Mag_Tracer_F {};
			class 20Rnd_650x39_Cased_Mag_F {};
			class 30Rnd_65x39_caseless_green {};
			class 30Rnd_65x39_caseless_green_mag_Tracer {};
			class 30Rnd_65x39_caseless_msbs_mag {};
			class 30Rnd_65x39_caseless_msbs_mag_Tracer {};
			class 30Rnd_65x39_caseless_black_mag {};
			class 30Rnd_65x39_caseless_black_mag_Tracer {};
			class 30Rnd_762x39_Mag_F {};
		};

		class Items {
			class ItemMap {};
			class ItemCompass {};
			class ItemWatch {};
			class ItemGPS {};
			class ItemRadio {};
			class NVGoggles {};
			class O_NVGoggles_grn_F { condition = "[] call ULP_fnc_donatorLevel > 0"; };
			class Binocular {};
			class ToolKit {};
			class Chemlight_green {};
			class SmokeShell {};
		};
	};

	class Blackmarket {
		storeName = "Blackmarket";
		condition = "[""Blackmarket""] call ULP_fnc_hasLicense && { [""Blackmarketer""] call ULP_fnc_hasPerk || [""Blackmarket""] call ULP_fnc_hasGroupPerk }";
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
			class arifle_TRG21_F {};
			class arifle_Mk20_plain_F {};
			class arifle_SPAR_01_blk_F {};
			class arifle_SPAR_02_blk_F {};
			class LMG_03_F {};
			class arifle_CTAR_blk_F {};
			class arifle_CTARS_blk_F {};
			class srifle_DMR_07_blk_F {};
			class arifle_Katiba_C_F {}; 
			class arifle_Katiba_F {};
			class arifle_MSBS65_black_F {};
			class arifle_MSBS65_Mark_black_F {};
			class arifle_MXC_Black_F {};
			class arifle_MX_Black_F {};
			class arifle_MXM_Black_F {};
			class arifle_MX_SW_Black_F {};
			class arifle_ARX_blk_F {};
			class LMG_Mk200_F {};
			class arifle_AKM_F {};
			class arifle_AK12U_F {};
			class arifle_AK12_F {};
			class srifle_DMR_01_F {};
			class arifle_SPAR_03_blk_F {};
			class srifle_DMR_06_olive_F {};
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
			// Rail
			class bipod_01_F_blk {};
			class acc_flashlight {};
			class acc_flashlight_pistol {};
			class acc_pointer_IR {};

			// Sights
			class optic_MRD {};
			class optic_Aco {};
			class optic_Holosight {};
			class optic_ico_01_black_f {};
			class optic_Hamr {};
			class optic_MRCO {};
			class optic_Arco {};
			class optic_ERCO_blk_F {};
			class optic_DMS_weathered_F {};

			// Barrel
			class muzzle_snds_L { condition = "[""SilentKiller""] call ULP_fnc_hasPerk"; };
			class muzzle_snds_acp { condition = "[""SilentKiller""] call ULP_fnc_hasPerk"; };
			class muzzle_snds_M { condition = "[""SilentKiller""] call ULP_fnc_hasPerk"; };
			class muzzle_snds_570 { condition = "[""SilentKiller""] call ULP_fnc_hasPerk"; };
			class muzzle_snds_58_blk_F { condition = "[""SilentKiller""] call ULP_fnc_hasPerk"; };
		};

		class Magazines {
			class 10Rnd_9x21_Mag {};
			class 16Rnd_9x21_Mag {};
			class 30Rnd_9x21_Mag {};
			class 30Rnd_9x21_Mag_SMG_02 {};
			class 30Rnd_9x21_Mag_SMG_02_Tracer_Red {};
			class 9Rnd_45ACP_Mag {};
			class 11Rnd_45ACP_Mag {};
			class 6Rnd_45ACP_Cylinder {};
			class 30Rnd_45ACP_Mag_SMG_01 {};
			class 30Rnd_45ACP_Mag_SMG_01_Tracer_Green {};
			class 2Rnd_12Gauge_Pellets {};
			class 2Rnd_12Gauge_Slug {};
			class 30Rnd_545x39_Mag_F {};
			class 50Rnd_570x28_SMG_03 {};
			class 20Rnd_556x45_UW_mag  {};
			class 30Rnd_556x45_Stanag {};
			class 30Rnd_556x45_Stanag_Tracer_Red {};
			class 150Rnd_556x45_Drum_Mag_F {};
			class 150Rnd_556x45_Drum_Mag_Tracer_F {};
			class 200Rnd_556x45_Box_F {};
			class 30Rnd_580x42_Mag_F {};
			class 30Rnd_580x42_Mag_Tracer_F {};
			class 100Rnd_580x42_Mag_F {};
			class 100Rnd_580x42_Mag_Tracer_F {};
			class 20Rnd_650x39_Cased_Mag_F {};
			class 30Rnd_65x39_caseless_green {};
			class 30Rnd_65x39_caseless_green_mag_Tracer {};
			class 30Rnd_65x39_caseless_msbs_mag {};
			class 30Rnd_65x39_caseless_msbs_mag_Tracer {};
			class 30Rnd_65x39_caseless_black_mag {};
			class 30Rnd_65x39_caseless_black_mag_Tracer {};
			class 100Rnd_65x39_caseless_black_mag {};
			class 100Rnd_65x39_caseless_black_mag_tracer {};
			class 200Rnd_65x39_cased_Box {};
			class 200Rnd_65x39_cased_Box_Tracer {};
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
			class O_NVGoggles_grn_F { condition = "[] call ULP_fnc_donatorLevel > 0"; };
			class Binocular {};
			class Rangefinder {};
			class ToolKit {};
			class Chemlight_green {};
			class SmokeShell {};
		};
	};

	class Base {
		storeName = "Gang Base";
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
			class arifle_TRG21_F {};
			class arifle_Mk20_plain_F {};
			class arifle_SPAR_01_blk_F {};
			class arifle_SPAR_02_blk_F {};
			class LMG_03_F {};
			class arifle_CTAR_blk_F {};
			class arifle_CTARS_blk_F {};
			class srifle_DMR_07_blk_F {};
			class arifle_Katiba_C_F {}; 
			class arifle_Katiba_F {};
			class arifle_MSBS65_black_F {};
			class arifle_MSBS65_Mark_black_F {};
			class arifle_MXC_Black_F {};
			class arifle_MX_Black_F {};
			class arifle_MXM_Black_F {};
			class arifle_MX_SW_Black_F {};
			class arifle_ARX_blk_F {};
			class LMG_Mk200_F {};
			class arifle_AKM_F {};
			class arifle_AK12U_F {};
			class arifle_AK12_F {};
			class srifle_DMR_01_F {};
			class arifle_SPAR_03_blk_F {};
			class srifle_DMR_06_olive_F {};
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
			class optic_ico_01_black_f {};
			class optic_Hamr {};
			class optic_MRCO {};
			class optic_Arco {};
			class optic_ERCO_blk_F {};
			class optic_DMS_weathered_F {};
			class muzzle_snds_L { condition = "[""SilentKiller""] call ULP_fnc_hasPerk"; };
			class muzzle_snds_acp { condition = "[""SilentKiller""] call ULP_fnc_hasPerk"; };
			class muzzle_snds_M { condition = "[""SilentKiller""] call ULP_fnc_hasPerk"; };
			class muzzle_snds_570 { condition = "[""SilentKiller""] call ULP_fnc_hasPerk"; };
		};

		class Magazines {
			class 10Rnd_9x21_Mag {};
			class 16Rnd_9x21_Mag {};
			class 30Rnd_9x21_Mag {};
			class 30Rnd_9x21_Mag_SMG_02 {};
			class 30Rnd_9x21_Mag_SMG_02_Tracer_Red {};
			class 9Rnd_45ACP_Mag {};
			class 11Rnd_45ACP_Mag {};
			class 6Rnd_45ACP_Cylinder {};
			class 30Rnd_45ACP_Mag_SMG_01 {};
			class 30Rnd_45ACP_Mag_SMG_01_Tracer_Green {};
			class 2Rnd_12Gauge_Pellets {};
			class 2Rnd_12Gauge_Slug {};
			class 30Rnd_545x39_Mag_F {};
			class 50Rnd_570x28_SMG_03 {};
			class 20Rnd_556x45_UW_mag  {};
			class 30Rnd_556x45_Stanag {};
			class 30Rnd_556x45_Stanag_Tracer_Red {};
			class 150Rnd_556x45_Drum_Mag_F {};
			class 150Rnd_556x45_Drum_Mag_Tracer_F {};
			class 200Rnd_556x45_Box_F {};
			class 30Rnd_580x42_Mag_F {};
			class 30Rnd_580x42_Mag_Tracer_F {};
			class 100Rnd_580x42_Mag_F {};
			class 100Rnd_580x42_Mag_Tracer_F {};
			class 20Rnd_650x39_Cased_Mag_F {};
			class 30Rnd_65x39_caseless_green {};
			class 30Rnd_65x39_caseless_green_mag_Tracer {};
			class 30Rnd_65x39_caseless_msbs_mag {};
			class 30Rnd_65x39_caseless_msbs_mag_Tracer {};
			class 30Rnd_65x39_caseless_black_mag {};
			class 30Rnd_65x39_caseless_black_mag_Tracer {};
			class 100Rnd_65x39_caseless_black_mag {};
			class 100Rnd_65x39_caseless_black_mag_tracer {};
			class 200Rnd_65x39_cased_Box {};
			class 200Rnd_65x39_cased_Box_Tracer {};
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
			class O_NVGoggles_grn_F { condition = "[] call ULP_fnc_donatorLevel > 0"; };
			class Binocular {};
			class Rangefinder {};
			class ToolKit {};
			class Chemlight_green {};
			class SmokeShell {};
		};
	};

	class GangWars {
		storeName = "Gang Wars Store";
		condition = "[""Rebel""] call ULP_fnc_hasLicense && { missionNamespace getVariable [""ULP_SRV_Setting_BaseBidsActive"", false] }";
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
			class arifle_TRG21_F {};
			class arifle_Mk20_plain_F {};
			class arifle_SPAR_01_blk_F {};
			class arifle_SPAR_02_blk_F {};
			class LMG_03_F {};
			class arifle_CTAR_blk_F {};
			class arifle_CTARS_blk_F {};
			class srifle_DMR_07_blk_F {};
			class arifle_Katiba_C_F {}; 
			class arifle_Katiba_F {};
			class arifle_MSBS65_black_F {};
			class arifle_MSBS65_Mark_black_F {};
			class arifle_MXC_Black_F {};
			class arifle_MX_Black_F {};
			class arifle_MXM_Black_F {};
			class arifle_MX_SW_Black_F {};
			class arifle_ARX_blk_F {};
			class LMG_Mk200_F {};
			class arifle_AKM_F {};
			class arifle_AK12U_F {};
			class arifle_AK12_F {};
			class srifle_DMR_01_F {};
			class arifle_SPAR_03_blk_F {};
			class srifle_DMR_06_olive_F {};
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
			class optic_ico_01_black_f {};
			class optic_Hamr {};
			class optic_MRCO {};
			class optic_Arco {};
			class optic_ERCO_blk_F {};
			class optic_DMS_weathered_F {};
			class muzzle_snds_L { condition = "[""SilentKiller""] call ULP_fnc_hasPerk"; };
			class muzzle_snds_acp { condition = "[""SilentKiller""] call ULP_fnc_hasPerk"; };
			class muzzle_snds_M { condition = "[""SilentKiller""] call ULP_fnc_hasPerk"; };
			class muzzle_snds_570 { condition = "[""SilentKiller""] call ULP_fnc_hasPerk"; };
		};

		class Magazines {
			class 10Rnd_9x21_Mag {};
			class 16Rnd_9x21_Mag {};
			class 30Rnd_9x21_Mag {};
			class 30Rnd_9x21_Mag_SMG_02 {};
			class 30Rnd_9x21_Mag_SMG_02_Tracer_Red {};
			class 9Rnd_45ACP_Mag {};
			class 11Rnd_45ACP_Mag {};
			class 6Rnd_45ACP_Cylinder {};
			class 30Rnd_45ACP_Mag_SMG_01 {};
			class 30Rnd_45ACP_Mag_SMG_01_Tracer_Green {};
			class 2Rnd_12Gauge_Pellets {};
			class 2Rnd_12Gauge_Slug {};
			class 30Rnd_545x39_Mag_F {};
			class 50Rnd_570x28_SMG_03 {};
			class 20Rnd_556x45_UW_mag  {};
			class 30Rnd_556x45_Stanag {};
			class 30Rnd_556x45_Stanag_Tracer_Red {};
			class 150Rnd_556x45_Drum_Mag_F {};
			class 150Rnd_556x45_Drum_Mag_Tracer_F {};
			class 200Rnd_556x45_Box_F {};
			class 30Rnd_580x42_Mag_F {};
			class 30Rnd_580x42_Mag_Tracer_F {};
			class 100Rnd_580x42_Mag_F {};
			class 100Rnd_580x42_Mag_Tracer_F {};
			class 20Rnd_650x39_Cased_Mag_F {};
			class 30Rnd_65x39_caseless_green {};
			class 30Rnd_65x39_caseless_green_mag_Tracer {};
			class 30Rnd_65x39_caseless_msbs_mag {};
			class 30Rnd_65x39_caseless_msbs_mag_Tracer {};
			class 30Rnd_65x39_caseless_black_mag {};
			class 30Rnd_65x39_caseless_black_mag_Tracer {};
			class 100Rnd_65x39_caseless_black_mag {};
			class 100Rnd_65x39_caseless_black_mag_tracer {};
			class 200Rnd_65x39_cased_Box {};
			class 200Rnd_65x39_cased_Box_Tracer {};
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
			class O_NVGoggles_grn_F { condition = "[] call ULP_fnc_donatorLevel > 0"; };
			class Binocular {};
			class Rangefinder {};
			class ToolKit {};
			class Chemlight_green {};
			class SmokeShell {};
		};
	};
};