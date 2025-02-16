class CfgClothesStore {
	onItemBuy = "_this call ULP_fnc_onBuyClothes";
	toolBoxIDC = 3102;
	itemCfg = "CfgClothing";

	class Police {
		storeName = "Equipment Store";
		condition = "[player, [""Police""]] call ULP_fnc_isFaction";
		class Uniforms {
			class U_Rangemaster {};
			class U_B_GEN_Commander_F { condition = "[""Police_COL"", 1] call ULP_fnc_hasAccess"; };
			class U_B_CombatUniform_mcam_worn { condition = "[""Police_RPU"", 1] call ULP_fnc_hasAccess"; };
			class U_C_FormalSuit_01_black_F { condition = "[""Police_Main"", 2] call ULP_fnc_hasAccess"; };
			class U_I_ParadeUniform_01_AAF_F { condition = "[""Police_Main"", 2] call ULP_fnc_hasAccess"; };
			class U_I_ParadeUniform_01_AAF_decorated_F { condition = "[""Police_Main"", 8] call ULP_fnc_hasAccess"; };
			class U_O_PilotCoveralls { condition = "[""Police_NPAS"", 1] call ULP_fnc_hasAccess"; };
			class U_B_CTRG_Soldier_F {
				displayName = "SCO19 Uniform";
				condition = "[""Police_SCO"", 1] call ULP_fnc_hasAccess || { [""Police_SFO"", 1] call ULP_fnc_hasAccess }";
				class textures { 
					class SCO19 {}; 
					class AFO {};
				};
			};
			class U_B_CTRG_Soldier_3_F {
				displayName = "SCO19 Uniform (Rolled)";
				condition = "[""Police_SCO"", 2] call ULP_fnc_hasAccess";
				class textures { 
					class SCO19 {}; 
					class AFO {};
				};
			};
			class U_B_CTRG_Soldier_2_Arid_F {
				displayName = "SCO19 Command Uniform";
				condition = "[""Police_SCO"", 3] call ULP_fnc_hasAccess";
				class textures { 
					class SCO19 {}; 
					class AFO {};
				};
			};
			class U_B_GhillieSuit {
				displayName = "SCO19 Ghillie Suit";
				condition = "[""Police_SCO"", 2] call ULP_fnc_hasAccess";
				class textures { 
					class SCO19 {}; 
					class AFO {};
				};
			};
			class U_BG_Guerrilla_6_1 { condition = "[""Police_NCA"", 1] call ULP_fnc_hasAccess"; };
			class U_O_R_Gorka_01_black_F { 
				condition = "[""Police_NCA"", 1] call ULP_fnc_hasAccess || { [""Police_RPU"", 1] call ULP_fnc_hasAccess }"; 
				class textures { 
					class RPU {}; 
					class NCA {}; 
				}; 
			};
			class U_B_Wetsuit {
				displayName = "MPU Wetsuit";
				condition = "[""Police_MPU"", 1] call ULP_fnc_hasAccess || { [""Police_Main"", 2] call ULP_fnc_hasAccess && { missionNamespace getVariable [""ULP_SRV_Crime_ResearchFacility"", false] || { missionNamespace getVariable [""ULP_SRV_Crime_HMSLiberty"", false] } } }";
				class Textures { class MPU {}; };
			};
			class U_C_CBRN_Suit_01_White_F {
				condition = "[""Police_SCO"", 1] call ULP_fnc_hasAccess || { [""Police_NCA"", 1] call ULP_fnc_hasAccess } || { [""Police_MPU"", 1] call ULP_fnc_hasAccess } || { [""Police_SFO"", 1] call ULP_fnc_hasAccess }";
				class Textures { class U_C_CBRN_Suit_01_Blue_F {}; };
			};
		};

		class Headgear {
			class H_WirelessEarpiece_F {};
			class H_Cap_blk {
				class Textures { 
					class H_Cap_police {}; 
					class H_Cap_blk {}; 
					class H_Cap_red {}; 
					class H_Cap_blu {}; 
					class H_Cap_tan {}; 
					class H_Cap_oli {}; 
					class H_Cap_oli_hs {}; 
					class H_Cap_marshal {}; 
				};
			};
			class H_Beret_blk { condition = "[""Police_Main"", 2] call ULP_fnc_hasAccess"; };
			class H_Watchcap_blk { 
				condition = "[""Police_Main"", 5] call ULP_fnc_hasAccess"; 
				class Textures { class H_Watchcap_blk {}; };
			};
			class H_Booniehat_khk { 
				condition = "[""Police_NCA"", 1] call ULP_fnc_hasAccess || { [""Police_MPU"", 1] call ULP_fnc_hasAccess }"; 
			};
			class H_PilotHelmetHeli_B { 
				condition = "[""Police_NPAS"", 1] call ULP_fnc_hasAccess";
				class Textures { 
					class H_PilotHelmetHeli_B {}; 
					class H_CrewHelmetHeli_B {};
				};
			};
			class H_PASGT_basic_black_F {
				condition = "[""Police_NCA"", 1] call ULP_fnc_hasAccess || { [""Police_MPU"", 1] call ULP_fnc_hasAccess } || { [""Police_COL"", 1] call ULP_fnc_hasAccess }"; 
				class Textures {
					class H_PASGT_basic_black_F {};
					class H_PASGT_basic_blue_F {};
					class H_PASGT_basic_white_F {};
				};
			};
			class H_HelmetB_plain_blk { 
				displayName = "Balistic Helmet";
				condition = "[""Police_NCA"", 1] call ULP_fnc_hasAccess"; 
				class Textures { class H_HelmetB_plain_blk {}; };
			};
			class H_HelmetSpecB_blk { 
				displayName = "Operation Helmet";
				condition = "[""Police_SCO"", 1] call ULP_fnc_hasAccess || { [""Police_Main"", 4] call ULP_fnc_hasAccess && { [""Police_SFO"", 1] call ULP_fnc_hasAccess } }"; 
				class Textures { class H_HelmetSpecB_blk {}; };
			};
		};

		class Facewear {
			class G_WirelessEarpiece_F {};
			class G_Aviator {};
			class G_Squares {};
			class G_Spectacles {};
			class G_Shades_Black {};
			class G_Sport_Red {};
			class G_Lady_Blue {};
			class G_B_Diving { condition = "[""Police_MPU"", 1] call ULP_fnc_hasAccess || { [""Police_Main"", 2] call ULP_fnc_hasAccess && { ( missionNamespace getVariable [""ULP_SRV_Crime_ResearchFacility"", false] ) || { ( missionNamespace getVariable [""ULP_SRV_Crime_HMSLiberty"", false] ) } } }"; };
			class G_Respirator_white_F {};
			class G_AirPurifyingRespirator_01_F { 
				condition = "[""Police_SCO"", 1] call ULP_fnc_hasAccess || { [""Police_NCA"", 1] call ULP_fnc_hasAccess } || { [""Police_MPU"", 1] call ULP_fnc_hasAccess } || { [""Police_SFO"", 1] call ULP_fnc_hasAccess }"; 
				class Textures { 
					class G_AirPurifyingRespirator_01_F {}; 
					class G_AirPurifyingRespirator_02_black_F {};
				};
			};
			class G_Bandanna_aviator { condition = "[""Police_SCO"", 1] call ULP_fnc_hasAccess || { [""Police_NCA"", 1] call ULP_fnc_hasAccess } || { [""Police_Main"", 4] call ULP_fnc_hasAccess && { [""Police_SFO"", 1] call ULP_fnc_hasAccess } }"; };
			class G_Balaclava_TI_blk_F { 
				condition = "[""Police_SCO"", 1] call ULP_fnc_hasAccess || { [""Police_NCA"", 1] call ULP_fnc_hasAccess }"; 
				class Textures { class G_Balaclava_TI_blk_F {}; };
			};
			class G_Balaclava_TI_G_blk_F { 
				condition = "[""Police_SCO"", 1] call ULP_fnc_hasAccess || { [""Police_NCA"", 1] call ULP_fnc_hasAccess }"; 
				class Textures { class G_Balaclava_TI_G_blk_F {}; };
			};
			class G_Tactical_Clear {};
		};

		class Vests {
			class V_LegStrapBag_black_F {
				class Textures { class V_LegStrapBag_black_F {}; };
			};
			class V_Rangemaster_belt {};
			class V_Safety_yellow_F {};
			class V_BandollierB_blk {
				class Textures { class V_BandollierB_blk {}; };
			};
			class V_TacVestIR_blk {};
			class V_Chestrig_blk {
				class Textures { class V_Chestrig_blk {}; };
			};
			class V_TacVest_blk {
				class Textures { class V_TacVest_blk_POLICE {}; };
			};
			class V_PlateCarrier1_blk {
				condition = "[""Police_Main"", 2] call ULP_fnc_hasAccess";
				class Textures { class V_PlateCarrier1_blk {}; };
			};
			class V_PlateCarrier2_blk {
				condition = "[""Police_SCO"", 1] call ULP_fnc_hasAccess || { [""Police_NCA"", 1] call ULP_fnc_hasAccess } || { [""Police_SFO"", 1] call ULP_fnc_hasAccess } || { [""Police_SEG"", 1] call ULP_fnc_hasAccess } || { [""Police_Main"", 3] call ULP_fnc_hasAccess && { missionNamespace getVariable [""ULP_SRV_Crime_ResearchFacility"", false] || { missionNamespace getVariable [""ULP_SRV_Crime_HMSLiberty"", false] } || { missionNamespace getVariable [""ULP_SRV_Crime_HMTreasury"", false] } || { missionNamespace getVariable [""ULP_SRV_Crime_PoliceEvidenceStorage"", false] } } }";
				class Textures { class V_PlateCarrier2_blk {}; };
			};
			class V_RebreatherB {
				condition = "[""Police_MPU"", 1] call ULP_fnc_hasAccess || { [""Police_Main"", 2] call ULP_fnc_hasAccess && { missionNamespace getVariable [""ULP_SRV_Crime_ResearchFacility"", false] || { missionNamespace getVariable [""ULP_SRV_Crime_HMSLiberty"", false] } } }";
				class Textures { class V_RebreatherB {}; };
			};
		};

		class Backpacks {
			class B_Carryall_cbr { 
				displayName = "Invisible Backpack"; 
				class Textures { 
					class INVIS {}; 
					class B_Carryall_blk {};
				};
			};
			class B_LegStrapBag_black_F {
				class Textures { class B_LegStrapBag_black_F {}; };
			};
			class B_Messenger_Black_F {
				class Textures { class B_Messenger_Black_F {}; };
			};
			class B_AssaultPack_blk {
				class Textures { class B_AssaultPack_blk {}; };
			};
			class B_FieldPack_blk {
				class Textures { class B_FieldPack_blk {}; };
			};
			class B_TacticalPack_blk {
				class Textures { class B_TacticalPack_blk {}; };
			};
			class B_CivilianBackpack_01_Everyday_Black_F {
				class Textures { class B_CivilianBackpack_01_Everyday_Black_F {}; };
			};
			class B_SCBA_01_F { condition = "[""Police_SCO"", 1] call ULP_fnc_hasAccess || { [""Police_NCA"", 1] call ULP_fnc_hasAccess } || { [""Police_MPU"", 1] call ULP_fnc_hasAccess } || { [""Police_SFO"", 1] call ULP_fnc_hasAccess }"; };
			class B_CombinationUnitRespiration_01_F { condition = "[""Police_SCO"", 1] call ULP_fnc_hasAccess || { [""Police_NCA"", 1] call ULP_fnc_hasAccess } || { [""Police_MPU"", 1] call ULP_fnc_hasAccess } || { [""Police_SFO"", 1] call ULP_fnc_hasAccess }"; };
		};
	};

	class Medic {
		storeName = "Equipment Store";
		condition = "[player, [""Medic""]] call ULP_fnc_isFaction";
		class Uniforms {
			class U_Competitor {};
			class U_O_R_Gorka_01_black_F {
				class Textures { 
					class Paramedic {}; 
					class Doctor {}; 
					class Commander {}; 
				};
			};
			class U_C_FormalSuit_01_black_F { condition = "[""Medic_Main"", 2] call ULP_fnc_hasAccess"; };
			class U_I_ParadeUniform_01_AAF_decorated_F { condition = "[""Medic_Main"", 2] call ULP_fnc_hasAccess"; };
			class U_O_PilotCoveralls { condition = "[""Medic_AA"", 1] call ULP_fnc_hasAccess"; };
			class U_B_Wetsuit {
				displayName = "Marine Wetsuit";
				condition = "[""Medic_HART"", 1] call ULP_fnc_hasAccess";
				class Textures { class U_B_Wetsuit {}; };
			};
			class U_C_CBRN_Suit_01_White_F {
				condition = "[""Medic_HART"", 1] call ULP_fnc_hasAccess";
				class Textures { class U_C_CBRN_Suit_01_White_F {}; };
			};
		};
		
		class Headgear {
			class H_WirelessEarpiece_F {};
			class H_Bandanna_gry {};
			class H_Cap_blk {};
			class H_Hat_grey {};
			class H_Watchcap_blk {};
			class H_Booniehat_khk {};
			class H_Beret_blk { condition = "[""Medic_Main"", 6] call ULP_fnc_hasAccess || { [""Medic_HART"", 1] call ULP_fnc_hasAccess }"; };
			class H_PilotHelmetHeli_B { 
				condition = "[""Medic_AA"", 1] call ULP_fnc_hasAccess"; 
				class Textures { 
					class H_PilotHelmetHeli_B {}; 
					class H_CrewHelmetHeli_B {}; 
				};
			};
			class H_PASGT_basic_black_F { 
				condition = "[""Medic_HART"", 1] call ULP_fnc_hasAccess"; 
				class Textures { class H_PASGT_basic_olive_F {}; };
			};
		};

		class Facewear {
			class G_WirelessEarpiece_F {};
			class G_Aviator {};
			class G_Squares {};
			class G_Spectacles {};
			class G_Shades_Black {};
			class G_Sport_Red {};
			class G_Lady_Blue {};
			class G_B_Diving { condition = "[""Medic_HART"", 1] call ULP_fnc_hasAccess"; };
			class G_Respirator_white_F {};
			class G_RegulatorMask_F { condition = "[""Medic_HART"", 1] call ULP_fnc_hasAccess"; };
			class G_Tactical_Clear {};
		};

		class Vests {
			class V_LegStrapBag_black_F {
				class Textures { class V_LegStrapBag_black_F {}; };
			};
			class V_Safety_yellow_F {};
			class V_BandollierB_blk {
				class Textures { class V_BandollierB_blk {}; };
			};
			class V_CarrierRigKBT_01_Olive_F { 
				condition = "[""Medic_HART"", 1] call ULP_fnc_hasAccess"; 
				class Textures { class V_CarrierRigKBT_01_Olive_F {}; };
			};
			class V_RebreatherB { 
				condition = "[""Medic_HART"", 1] call ULP_fnc_hasAccess"; 
				class Textures { class V_RebreatherB {}; };
			};
		};

		class Backpacks {
			class B_Bergen_mcamo_F { 
				displayName = "Invisible BIG Backpack"; 
				class Textures { class INVIS {}; };
			};
			class B_Carryall_cbr { 
				displayName = "Invisible Backpack"; 
				class Textures { class INVIS {}; };
			};
			class B_SCBA_01_F { condition = "[""Medic_HART"", 1] call ULP_fnc_hasAccess"; };
			class B_CombinationUnitRespiration_01_F { condition = "[""Medic_HART"", 1] call ULP_fnc_hasAccess"; };
		};
	};

	class Hato {
		storeName = "Equipment Store";
		condition = "[player, [""Hato""]] call ULP_fnc_isFaction";
		class Uniforms {
			class U_O_R_Gorka_01_black_F {
				class Textures {
					class HATO {};
				};
			};
			class U_C_FormalSuit_01_black_F { condition = "[""Hato_Main"", 4] call ULP_fnc_hasAccess"; };
		};
		
		class Headgear {
			class H_WirelessEarpiece_F {};
			class H_Bandanna_gry {};
			class H_Cap_blk {};
			class H_Hat_grey {};
			class H_Watchcap_blk {};
			class H_Booniehat_khk {};
			class G_Tactical_Clear {};
		};

		class Facewear {
			class G_WirelessEarpiece_F {};
			class G_Aviator {};
			class G_Squares {};
			class G_Spectacles {};
			class G_Shades_Black {};
			class G_Sport_Red {};
			class G_Lady_Blue {};
			class G_Respirator_white_F {};
			class G_Tactical_Clear {};
		};

		class Vests {};

		class Backpacks {
			class B_Bergen_mcamo_F { 
				displayName = "Invisible BIG Backpack"; 
				class Textures { class INVIS {}; };
			};
			class B_Carryall_cbr { 
				displayName = "Invisible Backpack"; 
				class Textures { class INVIS {}; };
			};
		};
	};

	class Civilian {
		storeName = "Clothing Store";
		condition = "true";
		class Uniforms {
			class U_C_Poor_1 {};
			class U_C_Farmer {};
			class U_C_Mechanic_01_F {};
			class U_C_Poloshirt_blue {};
			class U_C_WorkerOveralls {};
			class U_C_ConstructionCoverall_Black_F {};
			class U_C_Man_casual_1_F {};
			class U_C_ArtTShirt_01_v1_F {};
			class U_C_Man_casual_6_F {};
			class U_C_man_sport_1_F {};
			class U_C_Scientist {};
			class U_I_C_Soldier_Bandit_1_F {};
			class U_I_C_Soldier_Bandit_3_F {};
			class U_C_E_LooterJacket_01_F {};
			class U_OrestesBody {};
			class U_NikosBody {};
			class U_NikosAgedBody {};
			class U_C_FormalSuit_01_tshirt_black_F {};
			class U_C_FormalSuit_01_black_F {};
		};

		class Headgear {
			class H_Hat_Tinfoil_F {};
			class H_WirelessEarpiece_F {};
			class H_Bandanna_gry {};
			class H_Cap_blk {};
			class H_MilCap_gry {};
			class H_Hat_grey {};
			class H_StrawHat {};
			class H_Watchcap_blk {};
			class H_Booniehat_khk {};
			class H_EarProtectors_black_F {};
			class H_Construction_basic_black_F {};
			class H_Helmet_Skate {};
		};

		class Facewear {
			class G_WirelessEarpiece_F {};
			class G_Aviator {};
			class G_Squares {};
			class G_Spectacles {};
			class G_Shades_Black {};
			class G_Sport_Red {};
			class G_Lady_Blue {};
			class G_Respirator_white_F {};
			class G_EyeProtectors_F {};
		};

		class Vests {
			class V_LegStrapBag_black_F {};
			class V_Pocketed_black_F {};
			class V_Safety_yellow_F {};
		};

		class Backpacks {
			class B_LegStrapBag_black_F {};
			class B_Messenger_Black_F {};
			class B_AssaultPack_blk {};
			class B_FieldPack_blk {};
			class B_Kitbag_cbr {};
			class B_TacticalPack_blk {};
			class B_CivilianBackpack_01_Everyday_Black_F {};
			class B_CivilianBackpack_01_Sport_Blue_F {};
			class B_Carryall_cbr {};
		};
	};

	class Archaeology {
		storeName = "Archaeologist Clothing Store";
		condition = "true";
		class Uniforms {
			class U_IG_Guerilla2_1 {
				class Textures {
					class U_IG_Guerilla3_1 {};
					class U_IG_Guerilla3_2 {};
				};
			};
			class U_C_HunterBody_grn {};
		};

		class Headgear {
			class H_Bandanna_gry {};
			class H_Cap_blk {};
			class H_Hat_Safari_sand_F {};
			class H_Watchcap_blk {};
			class H_Booniehat_khk {};
		};

		class Facewear {};

		class Vests {
			class V_LegStrapBag_black_F {};
			class V_Pocketed_black_F {};
		};

		class Backpacks {
			class B_LegStrapBag_black_F {};
			class B_Messenger_Black_F {};
			class B_AssaultPack_blk {};
			class B_FieldPack_blk {};
			class B_Kitbag_cbr {};
			class B_TacticalPack_blk {};
			class B_Carryall_cbr {};
			class B_Bergen_mcamo_F {};
		};
	};

	class Hunting {
		storeName = "Hunting Clothing Store";
		condition = "[""Hunting""] call ULP_fnc_hasLicense";
		class Uniforms {
			class U_C_HunterBody_grn {};
		};

		class Headgear {
			class H_Bandanna_gry {};
			class H_Cap_blk {};
			class H_Hat_Safari_sand_F {};
			class H_Watchcap_blk {};
			class H_Booniehat_khk {};
		};

		class Facewear {};

		class Vests {
			class V_LegStrapBag_black_F {};
			class V_Pocketed_black_F {};
		};

		class Backpacks {
			class B_LegStrapBag_black_F {};
			class B_AssaultPack_blk {};
			class B_FieldPack_blk {};
			class B_Kitbag_cbr {};
			class B_TacticalPack_blk {};
			class B_Carryall_cbr {};
		};
	};

	class GoKart {
		storeName = "Go-Kart Clothing Store";
		condition = "true";
		class Uniforms {
			class U_C_Driver_1_black {};
		};

		class Headgear {
			class H_RacingHelmet_1_black_F {};
		};

		class Facewear {};
		class Vests {};
		class Backpacks {};
	};

	class Diving {
		storeName = "Diving Store";
		condition = "true";
		class Uniforms {
			class U_C_Man_casual_6_F {};
			class U_C_man_sport_1_F {};
			class U_B_Wetsuit {};
		};

		class Headgear {
			class H_Bandanna_gry {
				class Textures {
					class H_Bandanna_surfer {};
					class H_Bandanna_surfer_blk : H_Bandanna_surfer {};
					class H_Bandanna_surfer_grn : H_Bandanna_surfer {};
				};
			};
			class H_Cap_surfer {};
		};

		class Facewear {
			class G_B_Diving {};
		};

		class Vests {
			class V_RebreatherB {};
		};

		class Backpacks {
			class B_ViperLightHarness_blk_F {
				class Textures {
					class B_ViperLightHarness_blk_F {};
				};
			};
			class B_ViperHarness_blk_F {
				class Textures {
					class B_ViperLightHarness_blk_F {};
				};
			};
		};
	};

	class Governor {
		storeName = "Governor's Clothing Store";
		condition = "[] call ULP_fnc_isGovernor";
		class Uniforms {
			class U_C_Man_casual_1_F {};
			class U_OrestesBody {};
			class U_NikosAgedBody {};
			class U_C_FormalSuit_01_tshirt_black_F {};
			class U_C_FormalSuit_01_black_F {};
		};

		class Headgear {
			class H_WirelessEarpiece_F {};
			class H_Cap_blk {};
			class H_Hat_grey {};
		};

		class Facewear {
			class G_WirelessEarpiece_F {};
			class G_Aviator {};
			class G_Squares {};
			class G_Spectacles {};
			class G_Shades_Black {};
			class G_Sport_Red {};
			class G_Lady_Blue {};
			class G_Respirator_white_F {};
		};

		class Vests {};
		class Backpacks {};
	};

	class Protection {
		storeName = "Govenor Protection Clothing";
		condition = "[] call ULP_fnc_isProtection";
		class Uniforms {
			class U_Marshal {};
			class U_NikosAgedBody {};
			class U_C_FormalSuit_01_tshirt_black_F {};
			class U_C_FormalSuit_01_black_F {};
		};

		class Headgear {
			class H_WirelessEarpiece_F {};
			class H_Cap_blk {};
			class H_Watchcap_blk {};
		};

		class Facewear {
			class G_WirelessEarpiece_F {};
			class G_Aviator {};
			class G_Squares {};
			class G_Spectacles {};
			class G_Shades_Black {};
			class G_Sport_Red {};
			class G_Lady_Blue {};
			class G_Respirator_white_F {};
			class G_Tactical_Clear {};
		};

		class Vests {
			class V_PlateCarrier1_blk {
				class Textures {
					class V_PlateCarrier1_blk {};
				};
			};
		};
		class Backpacks {};
	};

	class Security {
		storeName = "Security Contractor Clothing";
		condition = "[] call ULP_fnc_isSecurity";
		class Uniforms {};

		class Headgear {
			class H_WirelessEarpiece_F {};
			class H_Cap_blk {};
			class H_Watchcap_blk {};
		};

		class Facewear {};

		class Vests {
			class V_TacVest_blk {
				class Textures {
					class V_TacVest_blk {};
				};
			};
			class V_PlateCarrier1_blk {
				class Textures {
					class V_PlateCarrier1_blk {};
				};
			};
		};
		class Backpacks {};
	};

	class Solicitor {
		storeName = "Solicitor Clothing Store";
		condition = "[""Solicitor""] call ULP_fnc_hasLicense";
		class Uniforms {
			class U_NikosAgedBody {};
			class U_C_FormalSuit_01_black_F {};
		};

		class Headgear {
			class H_Hat_grey {};
		};

		class Facewear {
			class G_WirelessEarpiece_F {};
			class G_Aviator {};
			class G_Squares {};
			class G_Spectacles {};
			class G_Shades_Black {};
			class G_Sport_Red {};
			class G_Lady_Blue {};
			class G_Respirator_white_F {};
		};

		class Vests {};
		class Backpacks {};
	};

	class Press {
		storeName = "Press Clothing Store";
		condition = "[""News""] call ULP_fnc_hasLicense";
		class Uniforms {
			class U_C_Journalist {};
		};

		class Headgear {
			class H_Cap_press {};
			class H_PASGT_basic_black_F {
				class Textures {
					class H_PASGT_basic_blue_press_F {};
					class H_PASGT_neckprot_blue_press_F {};
				};
			};
		};

		class Facewear {
			class G_WirelessEarpiece_F {};
			class G_Aviator {};
			class G_Squares {};
			class G_Spectacles {};
			class G_Shades_Black {};
			class G_Sport_Red {};
			class G_Lady_Blue {};
			class G_Respirator_white_F {};
		};

		class Vests {
			class V_Press_F {};
		};

		class Backpacks {
			class B_Messenger_Black_F {};
		};
	};

	class IDAP {
		storeName = "IDAP Clothing Store";
		condition = "[""IDAP""] call ULP_fnc_hasLicense";
		class Uniforms {
			class U_C_IDAP_Man_shorts_F {};
		};

		class Headgear {
			class H_Cap_Black_IDAP_F {};
			class H_Cap_White_IDAP_F {};
			class H_Cap_Orange_IDAP_F {};
		};

		class Facewear {
			class G_WirelessEarpiece_F {};
			class G_Aviator {};
			class G_Squares {};
			class G_Spectacles {};
			class G_Shades_Black {};
			class G_Sport_Red {};
			class G_Lady_Blue {};
			class G_Respirator_white_F {};
			class G_EyeProtectors_F {};
		};

		class Vests {
			class V_LegStrapBag_black_F {};
			class V_Plain_medical_F {};
		};

		class Backpacks {
			class B_Messenger_IDAP_F {};
		};
	};

	class Hideout {
		storeName = "Hideout Clothing Store";
		condition = "true";
		class Uniforms {
			class U_C_Poor_1 {};
			class U_C_Farmer {};
			class U_C_Mechanic_01_F {};
			class U_I_C_Soldier_Bandit_1_F {};
			class U_I_C_Soldier_Bandit_3_F {};
			class U_IG_Guerilla1_1 {};
			class U_C_E_LooterJacket_01_F {};
			class U_O_R_Gorka_01_black_F {};
			class U_I_C_Soldier_Para_1_F {};
			class U_I_E_Uniform_01_F {};
		};

		class Headgear {
			class H_HeadBandage_clean_F {};
			class H_Bandanna_gry {};
			class H_Cap_blk {};
			class H_MilCap_gry {};
			class H_Watchcap_blk {};
			class H_Booniehat_khk {};
			class H_ShemagOpen_khk {};
		};

		class Facewear {
			class G_WirelessEarpiece_F {};
			class G_Aviator {};
			class G_Squares {};
			class G_Spectacles {};
			class G_Shades_Black {};
			class G_Sport_Red {};
			class G_Blindfold_01_black_F {};
			class G_Bandanna_aviator {};
			class G_Balaclava_blk {};
		};

		class Vests {
			class V_LegStrapBag_black_F {};
			class V_Pocketed_black_F {};
			class V_Rangemaster_belt {};
			class V_BandollierB_blk {};
			class V_HarnessO_brn {};
			class V_TacVestIR_blk {};
			class V_Chestrig_blk {};
			class V_TacChestrig_cbr_F {};
			class V_SmershVest_01_F {};
			class V_TacVest_blk {};
		};
		
		class Backpacks {
			class B_LegStrapBag_black_F {};
			class B_Messenger_Black_F {};
			class B_AssaultPack_blk {};
			class B_FieldPack_blk {};
			class B_Kitbag_cbr {};
			class B_TacticalPack_blk {};
			class B_Carryall_cbr {};
		};
	};

	class Rebel {
		storeName = "Rebel Clothing Store";
		condition = "[""Rebel""] call ULP_fnc_hasLicense";
		class Uniforms {
			class U_C_Poor_1 {};
			class U_C_Farmer {};
			class U_C_Mechanic_01_F {};
			class U_I_C_Soldier_Bandit_1_F {};
			class U_I_C_Soldier_Bandit_3_F {};
			class U_IG_Guerilla1_1 {};
			class U_C_HunterBody_grn {};
			class U_C_E_LooterJacket_01_F {};
			class U_O_R_Gorka_01_black_F {};
			class U_I_C_Soldier_Para_1_F {};
			class U_I_E_Uniform_01_F {};
			class U_I_CombatUniform {};
			class U_B_CombatUniform_mcam {};
			class U_B_CombatUniform_mcam_vest {};
			class U_B_CombatUniform_mcam_tshirt {};
		};

		class Headgear {
			class H_HeadBandage_clean_F {};
			class H_Bandanna_gry {};
			class H_Cap_blk {};
			class H_MilCap_gry {};
			class H_Watchcap_blk {};
			class H_Booniehat_khk {};
			class H_ShemagOpen_khk {};
			class H_PASGT_basic_black_F {};
			class H_HelmetIA {};
			class H_HelmetB_light {};
		};

		class Facewear {
			class G_WirelessEarpiece_F {};
			class G_Aviator {};
			class G_Squares {};
			class G_Spectacles {};
			class G_Shades_Black {};
			class G_Sport_Red {};
			class G_Blindfold_01_black_F {};
			class G_Bandanna_aviator {};
			class G_Balaclava_blk {};
		};

		class Vests {
			class V_LegStrapBag_black_F {};
			class V_Pocketed_black_F {};
			class V_Rangemaster_belt {};
			class V_BandollierB_blk {};
			class V_HarnessO_brn {};
			class V_TacVestIR_blk {};
			class V_Chestrig_blk {};
			class V_TacChestrig_cbr_F {};
			class V_SmershVest_01_F {};
			class V_TacVest_blk {};
			class V_PlateCarrierIA1_dgtl {};
			class V_CarrierRigKBT_01_Olive_F {};
			class V_CarrierRigKBT_01_light_Olive_F {};
			class V_PlateCarrier1_blk {};
		};
		
		class Backpacks {
			class B_LegStrapBag_black_F {};
			class B_AssaultPack_blk {};
			class B_FieldPack_blk {};
			class B_Kitbag_cbr {};
			class B_TacticalPack_blk {};
			class B_Carryall_cbr {};
			class B_ViperLightHarness_blk_F {};
			class B_ViperHarness_blk_F {};
		};
	};

	class Blackmarket {
		storeName = "Blackmarket Clothing Store";
		condition = "[""Blackmarket""] call ULP_fnc_hasLicense";
		class Uniforms {
			class U_C_Poor_1 {};
			class U_C_Farmer {};
			class U_C_Mechanic_01_F {};
			class U_I_C_Soldier_Bandit_1_F {};
			class U_I_C_Soldier_Bandit_3_F {};
			class U_IG_Guerilla1_1 {};
			class U_C_HunterBody_grn {};
			class U_C_E_LooterJacket_01_F {};
			class U_O_R_Gorka_01_black_F {};
			class U_I_C_Soldier_Para_1_F {};
			class U_I_E_Uniform_01_F {};
			class U_I_CombatUniform {};
			class U_B_CombatUniform_mcam {};
			class U_B_CombatUniform_mcam_vest {};
			class U_B_CombatUniform_mcam_tshirt {};
			class U_B_survival_uniform {};
			class U_B_CTRG_Soldier_F {};
			class U_B_CTRG_Soldier_3_F {};
			class U_B_CTRG_Soldier_2_Arid_F {};
			class U_B_GhillieSuit {};
			class U_B_FullGhillie_ard {};
			class U_B_HeliPilotCoveralls {};
			class U_C_CBRN_Suit_01_White_F {};
		};

		class Headgear {
			class H_HeadBandage_clean_F {};
			class H_Bandanna_gry {};
			class H_Cap_blk {};
			class H_MilCap_gry {};
			class H_Watchcap_blk {};
			class H_Booniehat_khk {};
			class H_ShemagOpen_khk {};
			class H_PASGT_basic_black_F {};
			class H_PilotHelmetHeli_B {};
			class H_HelmetIA {};
			class H_HelmetB_light {};
			class H_HelmetB {};
			class H_HelmetSpecB {};
			class H_HelmetB_TI_arid_F {};
			class H_HelmetHBK_F {};
			class H_HelmetAggressor_F {};
		};

		class Facewear {
			class G_WirelessEarpiece_F {};
			class G_Aviator {};
			class G_Squares {};
			class G_Spectacles {};
			class G_Shades_Black {};
			class G_Sport_Red {};
			class G_Blindfold_01_black_F {};
			class G_Bandanna_aviator {};
			class G_Balaclava_blk {};
			class G_Balaclava_TI_blk_F {};
			class G_Balaclava_TI_G_blk_F {};
			class G_RegulatorMask_F {};
			class G_AirPurifyingRespirator_01_F {};
			class G_Tactical_Clear {};
		};

		class Vests {
			class V_LegStrapBag_black_F {};
			class V_Pocketed_black_F {};
			class V_Rangemaster_belt {};
			class V_BandollierB_blk {};
			class V_HarnessO_brn {};
			class V_TacVestIR_blk {};
			class V_Chestrig_blk {};
			class V_TacChestrig_cbr_F {};
			class V_SmershVest_01_F {};
			class V_TacVest_blk {};
			class V_PlateCarrierIA1_dgtl {};
			class V_CarrierRigKBT_01_Olive_F {};
			class V_CarrierRigKBT_01_light_Olive_F {};
			class V_PlateCarrier1_blk {};
			class V_PlateCarrier2_blk {};
		};
		
		class Backpacks {
			class B_LegStrapBag_black_F {};
			class B_AssaultPack_blk {};
			class B_FieldPack_blk {};
			class B_Kitbag_cbr {};
			class B_TacticalPack_blk {};
			class B_Carryall_cbr {};
			class B_ViperLightHarness_blk_F {};
			class B_ViperHarness_blk_F {};
			class B_RadioBag_01_black_F {};
			class B_SCBA_01_F {};
		};
	};

	class Base {
		storeName = "Gang Base Clothing Store";
		condition = "true";
		class Uniforms {
			class U_C_Poor_1 {};
			class U_C_Farmer {};
			class U_C_Mechanic_01_F {};
			class U_I_C_Soldier_Bandit_1_F {};
			class U_I_C_Soldier_Bandit_3_F {};
			class U_IG_Guerilla1_1 {};
			class U_C_HunterBody_grn {};
			class U_C_E_LooterJacket_01_F {};
			class U_O_R_Gorka_01_black_F {};
			class U_I_C_Soldier_Para_1_F {};
			class U_I_E_Uniform_01_F {};
			class U_I_CombatUniform {};
			class U_B_CombatUniform_mcam {};
			class U_B_CombatUniform_mcam_vest {};
			class U_B_CombatUniform_mcam_tshirt {};
			class U_B_survival_uniform {};
			class U_B_CTRG_Soldier_F {};
			class U_B_CTRG_Soldier_3_F {};
			class U_B_CTRG_Soldier_2_Arid_F {};
			class U_B_GhillieSuit {};
			class U_B_FullGhillie_ard {};
			class U_B_HeliPilotCoveralls {};
			class U_C_CBRN_Suit_01_White_F {};
		};

		class Headgear {
			class H_HeadBandage_clean_F {};
			class H_Bandanna_gry {};
			class H_Cap_blk {};
			class H_MilCap_gry {};
			class H_Watchcap_blk {};
			class H_Booniehat_khk {};
			class H_ShemagOpen_khk {};
			class H_PASGT_basic_black_F {};
			class H_PilotHelmetHeli_B {};
			class H_HelmetIA {};
			class H_HelmetB_light {};
			class H_HelmetB {};
			class H_HelmetSpecB {};
			class H_HelmetB_TI_arid_F {};
			class H_HelmetHBK_F {};
			class H_HelmetAggressor_F {};
		};

		class Facewear {
			class G_WirelessEarpiece_F {};
			class G_Aviator {};
			class G_Squares {};
			class G_Spectacles {};
			class G_Shades_Black {};
			class G_Sport_Red {};
			class G_Blindfold_01_black_F {};
			class G_Bandanna_aviator {};
			class G_Balaclava_blk {};
			class G_Balaclava_TI_blk_F {};
			class G_Balaclava_TI_G_blk_F {};
			class G_RegulatorMask_F {};
			class G_AirPurifyingRespirator_01_F {};
			class G_Tactical_Clear {};
		};

		class Vests {
			class V_LegStrapBag_black_F {};
			class V_Pocketed_black_F {};
			class V_Rangemaster_belt {};
			class V_BandollierB_blk {};
			class V_HarnessO_brn {};
			class V_TacVestIR_blk {};
			class V_Chestrig_blk {};
			class V_TacChestrig_cbr_F {};
			class V_SmershVest_01_F {};
			class V_TacVest_blk {};
			class V_PlateCarrierIA1_dgtl {};
			class V_CarrierRigKBT_01_Olive_F {};
			class V_CarrierRigKBT_01_light_Olive_F {};
			class V_PlateCarrier1_blk {};
			class V_PlateCarrier2_blk {};
		};
		
		class Backpacks {
			class B_LegStrapBag_black_F {};
			class B_AssaultPack_blk {};
			class B_FieldPack_blk {};
			class B_Kitbag_cbr {};
			class B_TacticalPack_blk {};
			class B_Carryall_cbr {};
			class B_ViperLightHarness_blk_F {};
			class B_ViperHarness_blk_F {};
			class B_RadioBag_01_black_F {};
			class B_SCBA_01_F {};
		};
	};
};
