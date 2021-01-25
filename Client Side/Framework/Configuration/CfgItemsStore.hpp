class CfgItemsStore {
	onItemBuy = "_this call ULP_fnc_onBuyItems";
	toolBoxIDC = 3113;
	itemCfg = "CfgItems";

	class Police {
		storeName = "Police Equipment Store";
		class Rifles {
			class SMG_05_F {};
			class SMG_01_F { condition = "[""Police_SFO"", 1] call ULP_fnc_hasAccess"; };
			class SMG_03C_black { condition = "[""Police_Main"", 2] call ULP_fnc_hasAccess"; };
			class SMG_03_black { condition = "[""Police_Main"", 2] call ULP_fnc_hasAccess"; };
			class arifle_SDAR_F { condition = "[""Police_SFO"", 1] call ULP_fnc_hasAccess"; };
			class arifle_SPAR_01_blk_F {
				condition = "[""Police_Main"", 2] call ULP_fnc_hasAccess";
				class textures {
					class arifle_SPAR_01_blk_F {};
				};
			};
			class arifle_CTAR_blk_F {
				condition = "[""Police_Main"", 2] call ULP_fnc_hasAccess";
				class textures {
					class arifle_CTAR_blk_F {};
				};
			};
			class arifle_MX_Black_F {
				condition = "[""Police_Main"", 3] call ULP_fnc_hasAccess || { [""Police_SFO"", 1] call ULP_fnc_hasAccess }";
				class textures {
					class arifle_MX_Black_F {};
				};
			};
			class arifle_MSBS65_black_F {
				condition = "[""Police_Main"", 4] call ULP_fnc_hasAccess || { [""Police_SFO"", 1] call ULP_fnc_hasAccess }";
				class textures {
					class arifle_MSBS65_black_F {};
				};
			};
			class arifle_ARX_blk_F {
				condition = "[""Police_Main"", 5] call ULP_fnc_hasAccess || { [""Police_SFO"", 1] call ULP_fnc_hasAccess }";
				class textures {
					class arifle_ARX_blk_F {};
				};
			};
			class srifle_DMR_07_blk_F {
				condition = "[""Police_Main"", 3] call ULP_fnc_hasAccess || { [""Police_SFO"", 1] call ULP_fnc_hasAccess }";
				class textures {
					class srifle_DMR_07_blk_F {};
				};
			};
			class arifle_MXM_Black_F {
				condition = "[""Police_Main"", 4] call ULP_fnc_hasAccess || { [""Police_SFO"", 1] call ULP_fnc_hasAccess }";
				class textures {
					class arifle_MXM_Black_F {};
				};
			};
			class arifle_MSBS65_Mark_black_F {
				condition = "[""Police_Main"", 4] call ULP_fnc_hasAccess || { [""Police_SFO"", 1] call ULP_fnc_hasAccess }";
				class textures {
					class arifle_MSBS65_Mark_black_F {};
				};
			};
			class arifle_SPAR_03_blk_F {
				condition = "[""Police_Main"", 5] call ULP_fnc_hasAccess || { [""Police_SFO"", 1] call ULP_fnc_hasAccess }";
				class textures {
					class arifle_SPAR_03_blk_F {};
				};
			};
			class srifle_EBR_F {
				condition = "[""Police_Main"", 6] call ULP_fnc_hasAccess || { [""Police_SFO"", 1] call ULP_fnc_hasAccess }";
				class textures {
					class srifle_EBR_F {};
				};
			};
			class srifle_DMR_03_F {
				condition = "[""Police_Main"", 7] call ULP_fnc_hasAccess || { [""Police_SFO"", 1] call ULP_fnc_hasAccess }";
				class textures {
					class srifle_DMR_03_F {};
				};
			};
		};

		class Pistols {
			class hgun_P07_F {};
			class hgun_Rook40_F { condition = "[""Police_Main"", 2] call ULP_fnc_hasAccess"; };
			class hgun_ACPC2_F { condition = "[""Police_Main"", 6] call ULP_fnc_hasAccess || { [""Police_SFO"", 1] call ULP_fnc_hasAccess }"; };
		};

		class Attachments {
			class acc_flashlight {};
			class acc_flashlight_pistol {};
			class acc_pointer_IR {};
			class optic_Aco {};
			class optic_Holosight {
				class textures {
					class optic_Holosight_blk_F : optic_Holosight {};
					class optic_Holosight_smg_blk_F : optic_Holosight {};
				};
			};
			class optic_Hamr {
				condition = "[""Police_Main"", 2] call ULP_fnc_hasAccess";
				class textures {
					class optic_Hamr {};
				};
			};
			class optic_MRCO { condition = "[""Police_Main"", 2] call ULP_fnc_hasAccess"; };
			class optic_Arco {
				condition = "[""Police_Main"", 2] call ULP_fnc_hasAccess";
				class textures {
					class optic_Arco_blk_F : optic_Arco {};
				};
			};
			class optic_ERCO_blk_F { condition = "[""Police_Main"", 2] call ULP_fnc_hasAccess"; };
			class optic_DMS {
				condition = "[""Police_Main"", 5] call ULP_fnc_hasAccess || { [""Police_SFO"", 1] call ULP_fnc_hasAccess }";
				class textures {
					class optic_DMS {};
				};
			};
			class optic_NVS { condition = "[""Police_SFO"", 1] call ULP_fnc_hasAccess"; };
			class muzzle_snds_L {};
			class muzzle_snds_acp { condition = "[""Police_Main"", 6] call ULP_fnc_hasAccess || { [""Police_SFO"", 1] call ULP_fnc_hasAccess }"; };
			class muzzle_snds_M { 
				condition = "[""Police_Main"", 2] call ULP_fnc_hasAccess"; 
				class textures {
					class muzzle_snds_M {};
				};
			};
			class muzzle_snds_570 { condition = "[""Police_Main"", 2] call ULP_fnc_hasAccess"; };
			class muzzle_snds_58_blk_F { 
				condition = "[""Police_Main"", 2] call ULP_fnc_hasAccess"; 
				class textures {
					class muzzle_snds_58_blk_F {};
				};
			};
			class muzzle_snds_H { 
				condition = "[""Police_Main"", 3] call ULP_fnc_hasAccess || { [""Police_SFO"", 1] call ULP_fnc_hasAccess }"; 
				class textures {
					class muzzle_snds_H {};
				};
			};
			class muzzle_snds_65_TI_blk_F { 
				condition = "[""Police_Main"", 5] call ULP_fnc_hasAccess || { [""Police_SFO"", 1] call ULP_fnc_hasAccess }"; 
				class textures {
					class muzzle_snds_65_TI_blk_F {};
				};
			};
			class muzzle_snds_B { 
				condition = "[""Police_Main"", 5] call ULP_fnc_hasAccess || { [""Police_SFO"", 1] call ULP_fnc_hasAccess }"; 
				class textures {
					class muzzle_snds_B {};
				};
			};
			class bipod_01_F_blk { 
				condition = "[""Police_Main"", 2] call ULP_fnc_hasAccess"; 
				class textures {
					class bipod_01_F_blk {};
					class bipod_02_F_blk {};
					class bipod_03_F_blk {};
				};
			};
		};

		class Magazines {};

		class Items {
			class ItemMap {};
			class ItemCompass {};
			class ItemWatch {};
			class ItemGPS {};
			class B_UavTerminal { condition = "[""Police_Main"", 5] call ULP_fnc_hasAccess || { [""Police_SFO"", 1] call ULP_fnc_hasAccess }"; };
			class ItemRadio {};
			class Rangefinder {};
			class FirstAidKit {};
			class Medikit {};
			class ToolKit {};
			class HandGrenade_Stone { condition = "[""Police_SFO"", 1] call ULP_fnc_hasAccess"; };
			class SmokeShell { condition = "[""Police_Main"", 2] call ULP_fnc_hasAccess"; };
			class SmokeShellYellow { condition = "[""Police_SFO"", 1] call ULP_fnc_hasAccess"; };
		};
	};

	class Medic {
		storeName = "Medic Equipment Store";
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
			class FirstAidKit {};
			class Medikit {};
			class ToolKit {};
		};
	};

	class Civilian {
		storeName = "General Store";
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
			class FirstAidKit {};
			class ToolKit {};
		};
	};

	class Guns {
		storeName = "Handgun Store";
		class Rifles {};
		class Pistols {
			class hgun_Pistol_01_F {};
			class hgun_Rook40_F {};
			class hgun_ACPC2_F {};
			class hgun_Pistol_heavy_01_F {};
			class hgun_Pistol_heavy_02_F {};
		};
		class Attachments {};
		class Magazines {};
		class Items {
			class ItemMap {};
			class ItemCompass {};
			class ItemWatch {};
			class ItemGPS {};
			class ItemRadio {};
			class Binocular {};
			class FirstAidKit {};
			class ToolKit {};
		};
	};

	class Syndikat {
		storeName = "Syndikat Weapon Store";
		class Rifles {};
		class Pistols {
			class hgun_Pistol_01_F {};
			class hgun_Rook40_F {};
			class hgun_ACPC2_F {};
			class hgun_Pistol_heavy_01_F {};
			class hgun_Pistol_heavy_02_F {};
		};
		class Attachments {};
		class Magazines {};
		class Items {
			class ItemMap {};
			class ItemCompass {};
			class ItemWatch {};
			class ItemGPS {};
			class ItemRadio {};
			class Binocular {};
			class FirstAidKit {};
			class ToolKit {};
		};
	};
};