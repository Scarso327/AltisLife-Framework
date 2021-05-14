class CfgClothesStore {
	onItemBuy = "_this call ULP_fnc_onBuyClothes";
	toolBoxIDC = 3102;
	itemCfg = "CfgClothing";

	class FactionBase { price = 0; };

	class Police {
		storeName = "Personal Equipment Store";
		condition = "[player, [""Police""]] call ULP_fnc_isFaction";
		class Uniforms {
			class U_Rangemaster : FactionBase {};
			class U_B_GEN_Commander_F : FactionBase { 
				condition = "[""Police_COL"", 1] call ULP_fnc_hasAccess"; 
			};
			class U_C_FormalSuit_01_black_F : FactionBase { 
				condition = "[""Police_Main"", 2] call ULP_fnc_hasAccess"; 
			};
			class U_I_ParadeUniform_01_AAF_F : FactionBase { 
				condition = "[""Police_Main"", 2] call ULP_fnc_hasAccess"; 
			};
			class U_I_ParadeUniform_01_AAF_decorated_F : FactionBase { 
				condition = "[""Police_Main"", 10] call ULP_fnc_hasAccess"; 
			};
			class U_BG_Guerrilla_6_1 : FactionBase { 
				condition = "[""Police_NCA"", 1] call ULP_fnc_hasAccess"; 
			};
			class U_O_R_Gorka_01_black_F : FactionBase { 
				condition = "[""Police_NCA"", 1] call ULP_fnc_hasAccess || { [""Police_RPU"", 1] call ULP_fnc_hasAccess }"; 
			};
			class U_B_CombatUniform_mcam_worn : FactionBase { 
				condition = "[""Police_RPU"", 1] call ULP_fnc_hasAccess || { [""Police_AFO"", 1] call ULP_fnc_hasAccess }"; 
			};
			class U_O_PilotCoveralls : FactionBase { 
				condition = "[""Police_NPAS"", 1] call ULP_fnc_hasAccess"; 
			};
			class U_B_CTRG_Soldier_F : FactionBase {
				displayName = "SCO19 Combat Uniform";
				condition = "[""Police_SCO"", 1] call ULP_fnc_hasAccess";
				class textures { class SCO19 {}; };
			};
			class U_B_GhillieSuit : FactionBase {
				displayName = "SCO19 Ghillie Suit";
				condition = "[""Police_SCO"", 2] call ULP_fnc_hasAccess";
				class textures { class SCO19 {}; };
			};
			class U_B_Wetsuit : FactionBase {
				displayName = "Marine Wetsuit";
				condition = "[""Police_MPU"", 1] call ULP_fnc_hasAccess";
				class Textures { class MPU {}; };
			};
			class U_C_CBRN_Suit_01_White_F : FactionBase {
				condition = "[""Police_Main"", 2] call ULP_fnc_hasAccess";
				class Textures { class U_C_CBRN_Suit_01_Blue_F {}; };
			};
		};

		class Headgear {
			class H_WirelessEarpiece_F : FactionBase {};
			class H_Cap_blk : FactionBase {
				class Textures {
					class H_Cap_blk {};
					class H_Cap_red : H_Cap_blk {};
					class H_Cap_blu : H_Cap_blk {};
					class H_Cap_tan : H_Cap_blk {};
					class H_Cap_oli : H_Cap_blk {};
					class H_Cap_khaki_specops_UK : H_Cap_blk {};
					class H_Cap_police : H_Cap_blk {};
				};
			};
			class H_Beret_blk : FactionBase { 
				condition = "[""Police_Main"", 2] call ULP_fnc_hasAccess"; 
			};
			class H_Watchcap_blk : FactionBase { 
				condition = "[""Police_SCO"", 1] call ULP_fnc_hasAccess } || { [""Police_NCA"", 1] call ULP_fnc_hasAccess } || { [""Police_AFO"", 1] call ULP_fnc_hasAccess }"; 
				class Textures { class H_Watchcap_blk {}; };
			};
			class H_Booniehat_khk : FactionBase { 
				condition = "[""Police_NCA"", 1] call ULP_fnc_hasAccess || { [""Police_MPU"", 1] call ULP_fnc_hasAccess }"; 
				class Textures { class H_Booniehat_khk {}; };
			};
			class H_PilotHelmetHeli_B : FactionBase { 
				condition = "[""Police_NPAS"", 1] call ULP_fnc_hasAccess"; 
			};
			class H_HelmetSpecB_blk : FactionBase { 
				displayName = "Operation Helmet";
				condition = "[""Police_SCO"", 1] call ULP_fnc_hasAccess"; 
				class Textures { class H_HelmetSpecB_blk {}; };
			};
		};

		class Facewear {
			class G_WirelessEarpiece_F : FactionBase {};
			class G_Aviator : FactionBase {};
			class G_Squares : FactionBase {
				class Textures : FactionBase {
					class G_Squares {};
					class G_Squares_Tinted : G_Squares {};
				};
			};
			class G_Spectacles : FactionBase {};
			class G_Shades_Black : FactionBase {};
			class G_Sport_Red : FactionBase {};
			class G_Lady_Blue : FactionBase {};
			class G_B_Diving : FactionBase { 
				condition = "[""Police_MPU"", 1] call ULP_fnc_hasAccess"; 
			};
			class G_Respirator_white_F : FactionBase {};
			class G_RegulatorMask_F : FactionBase { 
				condition = "[""Police_Main"", 2] call ULP_fnc_hasAccess"; 
			};
			class G_Bandanna_aviator : FactionBase { 
				condition = "[""Police_SCO"", 1] call ULP_fnc_hasAccess || { [""Police_NCA"", 1] call ULP_fnc_hasAccess }"; 
				class Textures {
					class G_Bandanna_aviator {};
					class G_Bandanna_sport : G_Bandanna_aviator {};
					class G_Bandanna_beast : G_Bandanna_aviator {};
					class G_Bandanna_blk : G_Bandanna_aviator {};
				};
			};
			class G_Balaclava_TI_blk_F : FactionBase { 
				condition = "[""Police_SCO"", 1] call ULP_fnc_hasAccess"; 
			};
		};

		class Vests {
			class V_LegStrapBag_black_F : FactionBase {
				class Textures { class V_LegStrapBag_black_F {}; };
			};
			class V_Rangemaster_belt : FactionBase {};
			class V_BandollierB_blk : FactionBase {
				class Textures { class V_BandollierB_blk {}; };
			};
			class V_TacVest_blk_POLICE : FactionBase {
				class Textures {};
			};
			class V_PlateCarrier1_blk : FactionBase {
				condition = "[""Police_Main"", 2] call ULP_fnc_hasAccess";
				class Textures { class V_PlateCarrier1_blk {}; };
			};
			class V_PlateCarrier2_blk : FactionBase {
				condition = "[""Police_Main"", 10] call ULP_fnc_hasAccess || { [""Police_SCO"", 1] call ULP_fnc_hasAccess } || { [""Police_NCA"", 1] call ULP_fnc_hasAccess } || { [""Police_AFO"", 1] call ULP_fnc_hasAccess }";
				class Textures { class V_PlateCarrier2_blk {}; };
			};
			class V_RebreatherB : FactionBase {
				condition = "[""Police_MPU"", 1] call ULP_fnc_hasAccess"; 
				class Textures { class V_RebreatherB {}; };
			};
		};

		class Backpacks {
			class B_Carryall_cbr : FactionBase { 
				displayName = "Invisible Backpack"; 
				class Textures { class INVIS {}; };
			};
		};
	};

	class PoliceUM {
		storeName = "Personal Equipment Store";
		condition = "[player, [""Police""]] call ULP_fnc_isFaction && { [""Police_NCA"", 1] call ULP_fnc_hasAccess }";
		class Uniforms {
			class U_C_Mechanic_01_F : FactionBase {};
			class U_C_ArtTShirt_01_v1_F : FactionBase {};
			class U_I_C_Soldier_Bandit_3_F : FactionBase {};
			class U_IG_Guerilla1_1 : FactionBase {
				class Textures : FactionBase {
					class U_IG_Guerilla2_2 {};
					class U_IG_Guerilla2_1 : U_IG_Guerilla2_2 {};
					class U_IG_Guerilla2_3 : U_IG_Guerilla2_2 {};
				};
			};
			class U_I_L_Uniform_01_tshirt_skull_F : FactionBase {};
		};

		class Headgear {
			class H_WirelessEarpiece_F {};
			class H_Bandanna_gry {};
			class H_Cap_blk {};
			class H_Hat_grey {};
			class H_Watchcap_blk {};
			class H_Booniehat_khk {};
		};

		class Facewear {
			class G_WirelessEarpiece_F : FactionBase {};
			class G_Aviator : FactionBase {};
			class G_Squares : FactionBase {
				class Textures : FactionBase {
					class G_Squares {};
					class G_Squares_Tinted : G_Squares {};
				};
			};
			class G_Spectacles : FactionBase {};
			class G_Shades_Black : FactionBase {};
			class G_Sport_Red : FactionBase {};
			class G_Lady_Blue : FactionBase {};
			class G_Respirator_white_F : FactionBase {};
			class G_Bandanna_aviator : FactionBase { 
				class Textures {
					class G_Bandanna_aviator {};
					class G_Bandanna_sport : G_Bandanna_aviator {};
					class G_Bandanna_beast : G_Bandanna_aviator {};
					class G_Bandanna_blk : G_Bandanna_aviator {};
				};
			};
		};

		class Vests {
			class V_LegStrapBag_black_F : FactionBase {
				class Textures { class V_LegStrapBag_black_F {}; };
			};
			class V_Rangemaster_belt : FactionBase {};
			class V_BandollierB_blk : FactionBase {
				class Textures { class V_BandollierB_blk {}; };
			};
			class V_TacVest_blk_POLICE : FactionBase {
				class Textures {};
			};
			class V_PlateCarrier1_blk : FactionBase {
				class Textures { class V_PlateCarrier1_blk {}; };
			};
			class V_PlateCarrier2_blk : FactionBase {
				class Textures { class V_PlateCarrier2_blk {}; };
			};
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

	class Medic {
		storeName = "Personal Equipment Store";
		condition = "[player, [""Medic""]] call ULP_fnc_isFaction";
		class Uniforms {
			class U_Competitor : FactionBase {};
			class U_O_R_Gorka_01_black_F : FactionBase {}; // TODO TEXTURE (3)
			class U_C_FormalSuit_01_black_F : FactionBase { 
				condition = "[""Medic_Main"", 2] call ULP_fnc_hasAccess"; 
			};
			class U_I_ParadeUniform_01_AAF_decorated_F : FactionBase { // TODO TEXTURE
				condition = "[""Medic_Main"", 2] call ULP_fnc_hasAccess"; 
			};
			class U_O_PilotCoveralls : FactionBase { 
				condition = "[""Medic_AA"", 1] call ULP_fnc_hasAccess"; 
			};
			class U_B_Wetsuit : FactionBase {
				displayName = "Marine Wetsuit";
				condition = "[""Medic_HART"", 1] call ULP_fnc_hasAccess";
				class Textures { class U_B_Wetsuit {}; };
			};
			class U_C_CBRN_Suit_01_White_F : FactionBase { // TODO TEXTURE
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
			class H_Beret_blk : FactionBase { 
				condition = "[""Medic_Main"", 6] call ULP_fnc_hasAccess || { [""Medic_HART"", 1] call ULP_fnc_hasAccess }"; 
			};
			class H_PilotHelmetHeli_B : FactionBase { 
				condition = "[""Medic_AA"", 1] call ULP_fnc_hasAccess"; 
			};
		};

		class Facewear {
			class G_WirelessEarpiece_F : FactionBase {};
			class G_Aviator : FactionBase {};
			class G_Squares : FactionBase {};
			class G_Spectacles : FactionBase {};
			class G_Shades_Black : FactionBase {};
			class G_Sport_Red : FactionBase {};
			class G_Lady_Blue : FactionBase {};
			class G_B_Diving : FactionBase { 
				condition = "[""Medic_HART"", 1] call ULP_fnc_hasAccess"; 
			};
			class G_Respirator_white_F : FactionBase {};
			class G_RegulatorMask_F : FactionBase { 
				condition = "[""Medic_HART"", 1] call ULP_fnc_hasAccess"; 
			};
		};

		class Vests {
			class V_LegStrapBag_black_F : FactionBase {
				class Textures { class V_LegStrapBag_black_F {}; };
			};
			class V_Safety_yellow_F : FactionBase {
				class Textures { class V_Safety_yellow_F {}; };
			};
			class V_BandollierB_blk : FactionBase {
				class Textures { class V_BandollierB_blk {}; };
			};
			class V_RebreatherB : FactionBase { 
				condition = "[""Medic_HART"", 1] call ULP_fnc_hasAccess"; 
				class Textures { class V_RebreatherB {}; };
			};
		};

		class Backpacks {
			class B_Carryall_cbr : FactionBase { 
				displayName = "Invisible Backpack"; 
				class Textures { class INVIS {}; };
			};
			class B_SCBA_01_F : FactionBase { 
				condition = "[""Medic_HART"", 1] call ULP_fnc_hasAccess"; 
			};
		};
	};

	class Hato {
		storeName = "Personal Equipment Store";
		condition = "[player, [""Hato""]] call ULP_fnc_isFaction";
		class Uniforms {
			class U_O_R_Gorka_01_black_F : FactionBase {};
			class U_C_FormalSuit_01_black_F : FactionBase { 
				condition = "[""Hato_Main"", 4] call ULP_fnc_hasAccess"; 
			};
		};
		
		class Headgear {
			class H_WirelessEarpiece_F : FactionBase {};
			class H_Cap_blk : FactionBase {
				class Textures {
					class H_Cap_blk {};
					class H_Cap_red : H_Cap_blk {};
					class H_Cap_blu : H_Cap_blk {};
					class H_Cap_tan : H_Cap_blk {};
					class H_Cap_oli : H_Cap_blk {};
					class H_Cap_surfer : H_Cap_blk {};
				};
			};
			class H_Watchcap_blk : FactionBase {};
		};

		class Facewear {
			class G_WirelessEarpiece_F : FactionBase {};
			class G_Aviator : FactionBase {};
			class G_Squares : FactionBase {};
			class G_Spectacles : FactionBase {};
			class G_Shades_Black : FactionBase {};
			class G_Sport_Red : FactionBase {};
			class G_Lady_Blue : FactionBase {};
			class G_Respirator_white_F : FactionBase {};
		};

		class Vests {};

		class Backpacks {
			class B_Carryall_cbr : FactionBase { 
				displayName = "Invisible Backpack"; 
				class Textures { class INVIS {}; };
			};
		};
	};

	class Civilian {
		storeName = "City Clothing Store";
		condition = "true";
		class Uniforms {
			class U_C_Poor_1 {};
			class U_C_Mechanic_01_F {};
			class U_C_WorkerOveralls {};
			class U_C_Poloshirt_blue {};
			class U_C_Man_casual_1_F {};
			class U_C_Man_casual_6_F {};
			class U_C_Scientist {};
			class U_I_C_Soldier_Bandit_1_F {};
			class U_I_C_Soldier_Bandit_3_F {};
			class U_IG_Guerilla2_1 {
				class Textures {
					class U_IG_Guerilla2_1 {};
					class U_IG_Guerilla2_2 {};
					class U_IG_Guerilla2_3 {};
					class U_IG_Guerilla3_1 {};
					class U_IG_Guerilla3_2 {};
				};
			};
			class U_C_E_LooterJacket_01_F {};
			class U_OrestesBody {};
			class U_NikosBody {};
			class U_NikosAgedBody {};
			class U_C_FormalSuit_01_tshirt_black_F {};
			class U_C_FormalSuit_01_black_F {};
		};

		class Headgear {
			class H_WirelessEarpiece_F {};
			class H_Bandanna_gry {};
			class H_Cap_blk {};
			class H_Hat_grey {};
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
			class B_Carryall_cbr {};
		};
	};

	class Outlet {
		storeName = "Outlet Clothing Store";
		condition = "true";
		class Uniforms {
			class U_C_Poor_1 {};
			class U_C_Farmer {};
			class U_C_Mechanic_01_F {};
			class U_C_Poloshirt_blue {};
			class U_C_Man_casual_6_F {};
			class U_I_C_Soldier_Bandit_1_F {};
			class U_I_C_Soldier_Bandit_3_F {};
			class U_IG_Guerilla2_1 {
				class Textures {
					class U_IG_Guerilla2_1 {};
					class U_IG_Guerilla2_2 {};
					class U_IG_Guerilla2_3 {};
					class U_IG_Guerilla3_1 {};
					class U_IG_Guerilla3_2 {};
				};
			};
			class U_C_E_LooterJacket_01_F {};
			class U_OrestesBody {};
		};

		class Headgear {
			class H_Bandanna_gry {};
			class H_Cap_blk {};
			class H_Hat_Safari_sand_F {};
			class H_Watchcap_blk {};
			class H_Booniehat_khk {};
		};

		class Facewear {
			class G_Aviator {};
			class G_Squares {};
			class G_Spectacles {};
			class G_Shades_Black {};
			class G_Sport_Red {};
			class G_Respirator_white_F {};
			class G_EyeProtectors_F {};
		};

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
		};
	};

	class Archaeology {
		storeName = "Archaeologist Clothing Store";
		condition = "true";
		class Uniforms {
			class U_IG_Guerilla2_1 {
				class Textures {
					class U_IG_Guerilla3_1 {};
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

		class Facewear {
			class G_Aviator {};
			class G_Shades_Black {};
			class G_Sport_Red {};
		};

		class Vests {
			class V_LegStrapBag_black_F {};
			class V_Pocketed_black_F {};
		};

		class Backpacks {
			class B_LegStrapBag_black_F {};
			class B_Messenger_Black_F {};
			class B_Bergen_mcamo_F {};
		};
	};

	class Hunting {
		storeName = "Hunting Clothing Store";
		condition = "[""Hunting""] call ULP_fnc_hasLicense";
		class Uniforms {
			class U_IG_Guerilla2_1 {
				class Textures {
					class U_IG_Guerilla3_1 {};
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

		class Facewear {
			class G_Aviator {};
			class G_Shades_Black {};
			class G_Sport_Red {};
		};

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
			class U_B_Wetsuit {
				class Textures {
					class U_B_Wetsuit {};
					class U_I_Wetsuit : U_B_Wetsuit {};
				};
			};
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
			class G_Aviator {};
			class G_Squares {};
			class G_Spectacles {};
			class G_Shades_Black {};
			class G_Sport_Red {};
			class G_Lady_Blue {};
			class G_Respirator_white_F {};
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

	class Taxi {
		storeName = "Taxi Clothing Store";
		condition = "[""Taxi""] call ULP_fnc_hasLicense && { [""CompletedCV""] call ULP_fnc_hasPerk }";
		class Uniforms {
			class U_Competitor {};
		};

		class Headgear {
			class H_WirelessEarpiece_F {};
			class H_Bandanna_gry {};
			class H_Cap_blk {};
			class H_Hat_grey {};
			class H_Hat_Safari_sand_F {};
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

		class Vests {};
		class Backpacks {};
	};

	class Solicitor {
		storeName = "Solicitor Clothing Store";
		condition = "[""Solicitor""] call ULP_fnc_hasLicense && { [""CompletedCV""] call ULP_fnc_hasPerk }";
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
			class G_EyeProtectors_F {};
		};

		class Vests {};
		class Backpacks {};
	};

	class Press {
		storeName = "Press Clothing Store";
		condition = "[""News""] call ULP_fnc_hasLicense && { [""CompletedCV""] call ULP_fnc_hasPerk }";
		class Uniforms {
			class U_C_Journalist {};
		};

		class Headgear {
			class H_Cap_press {};
			class H_PASGT_basic_blue_press_F {};
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
			class V_Press_F {};
		};

		class Backpacks {
			class B_Messenger_Black_F {};
		};
	};

	class IDAP {
		storeName = "IDAP Clothing Store";
		condition = "[""IDAP""] call ULP_fnc_hasLicense && { [""CompletedCV""] call ULP_fnc_hasPerk }";
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

	class Rebel {
		storeName = "Rebel/Blackmarket Clothing Store";
		condition = "[""Rebel""] call ULP_fnc_hasLicense || [""Blackmarket""] call ULP_fnc_hasLicense";
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
			class U_B_survival_uniform { 
				condition = "[""Blackmarket""] call ULP_fnc_hasLicense && { [""Blackmarketer""] call ULP_fnc_hasPerk } && { [""Blackmarket""] call ULP_fnc_hasGroupPerk }"; 
			};
			class U_B_CombatUniform_mcam {};
			class U_B_GhillieSuit {};
			class U_B_FullGhillie_ard { 
				condition = "[""Blackmarket""] call ULP_fnc_hasLicense && { [""Blackmarketer""] call ULP_fnc_hasPerk } && { [""Blackmarket""] call ULP_fnc_hasGroupPerk }"; 
			};
			class U_C_CBRN_Suit_01_White_F {
				condition = "[""Blackmarket""] call ULP_fnc_hasLicense"; 
				class Textures {
					class U_B_CBRN_Suit_01_MTP_F {};
					class U_B_CBRN_Suit_01_Wdl_F {};
					class U_I_CBRN_Suit_01_AAF_F {};
				};
			};
		};

		class Headgear {
			class H_WirelessEarpiece_F {};
			class H_Bandanna_gry {};
			class H_Cap_blk {};
			class H_Watchcap_blk {};
			class H_Booniehat_khk {};
			class H_ShemagOpen_khk {};
			class H_HelmetB_light {};
			class H_HelmetB {};
			class H_HelmetSpecB { 
				condition = "[""Blackmarket""] call ULP_fnc_hasLicense && { [""Blackmarketer""] call ULP_fnc_hasPerk } && { [""Blackmarket""] call ULP_fnc_hasGroupPerk }"; 
			};
		};

		class Facewear {
			class G_WirelessEarpiece_F {};
			class G_Aviator {};
			class G_Squares {};
			class G_Spectacles {};
			class G_Shades_Black {};
			class G_Sport_Red {};
			class G_Lowprofile {};
			class G_Combat {};
			class G_RegulatorMask_F {};
			class G_Blindfold_01_black_F {};
			class G_Bandanna_aviator {};
			class G_Balaclava_blk {};
		};

		class Vests {
			class V_LegStrapBag_black_F {};
			class V_Pocketed_black_F {};
			class V_Rangemaster_belt {};
			class V_BandollierB_cbr {};
			class V_BandollierB_blk {
				class Textures {
					class V_BandollierB_cbr {};
					class V_BandollierB_rgr {};
				};
			};
			class V_HarnessO_brn {};
			class V_Chestrig_blk {
				class Textures {
					class V_Chestrig_khk {};
					class V_Chestrig_oli {};
					class V_Chestrig_rgr {};
				};
			};
			class V_TacChestrig_cbr_F {};
			class V_TacVest_blk {
				class Textures {
					class V_TacVest_camo {};
					class V_TacVest_brn {};
					class V_TacVest_khk {};
					class V_TacVest_oli {};
				};
			};
			class V_PlateCarrier1_blk {
				class Textures {
					class V_PlateCarrier1_rgr {};
					class V_PlateCarrier1_rgr_noflag_F {};
					class V_PlateCarrier1_wdl {};
					class V_PlateCarrierL_CTRG {};
				};
			};
			class V_PlateCarrier2_blk {
				condition = "[""Blackmarket""] call ULP_fnc_hasLicense && { [""Blackmarketer""] call ULP_fnc_hasPerk } && { [""Blackmarket""] call ULP_fnc_hasGroupPerk }"; 
				class Textures {
					class V_PlateCarrier2_rgr {};
					class V_PlateCarrier2_rgr_noflag_F {};
					class V_PlateCarrier2_wdl {};
					class V_PlateCarrier2_CTRG {};
				};
			};
		};
		
		class Backpacks {
			class B_LegStrapBag_black_F {};
			class B_Messenger_Black_F {};
			class B_AssaultPack_blk {};
			class B_FieldPack_blk {};
			class B_Kitbag_cbr {};
			class B_TacticalPack_blk {};
			class B_Carryall_cbr {};
			class B_ViperLightHarness_blk_F {};
			class B_ViperHarness_blk_F {};
			class B_Parachute {};
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
			class U_C_E_LooterJacket_01_F {};
			class U_O_R_Gorka_01_black_F {};
			class U_I_C_Soldier_Para_1_F {};
			class U_B_survival_uniform {};
			class U_B_CombatUniform_mcam {};
			class U_B_GhillieSuit {};
			class U_B_FullGhillie_ard {};
			class U_C_CBRN_Suit_01_White_F {
				class Textures {
					class U_B_CBRN_Suit_01_MTP_F {};
					class U_B_CBRN_Suit_01_Wdl_F {};
					class U_I_CBRN_Suit_01_AAF_F {};
				};
			};
		};

		class Headgear {
			class H_WirelessEarpiece_F {};
			class H_Bandanna_gry {};
			class H_Cap_blk {};
			class H_Watchcap_blk {};
			class H_Booniehat_khk {};
			class H_ShemagOpen_khk {};
			class H_HelmetB_light {};
			class H_HelmetB {};
			class H_HelmetSpecB {};
		};

		class Facewear {
			class G_WirelessEarpiece_F {};
			class G_Aviator {};
			class G_Squares {};
			class G_Spectacles {};
			class G_Shades_Black {};
			class G_Sport_Red {};
			class G_Lowprofile {};
			class G_Combat {};
			class G_RegulatorMask_F {};
			class G_Blindfold_01_black_F {};
			class G_Bandanna_aviator {};
			class G_Balaclava_blk {};
		};

		class Vests {
			class V_LegStrapBag_black_F {};
			class V_Pocketed_black_F {};
			class V_Rangemaster_belt {};
			class V_BandollierB_cbr {};
			class V_BandollierB_blk {
				class Textures {
					class V_BandollierB_cbr {};
					class V_BandollierB_rgr {};
				};
			};
			class V_HarnessO_brn {};
			class V_Chestrig_blk {
				class Textures {
					class V_Chestrig_khk {};
					class V_Chestrig_oli {};
					class V_Chestrig_rgr {};
				};
			};
			class V_TacChestrig_cbr_F {};
			class V_TacVest_blk {
				class Textures {
					class V_TacVest_camo {};
					class V_TacVest_brn {};
					class V_TacVest_khk {};
					class V_TacVest_oli {};
				};
			};
			class V_PlateCarrier1_blk {
				class Textures {
					class V_PlateCarrier1_rgr {};
					class V_PlateCarrier1_rgr_noflag_F {};
					class V_PlateCarrier1_wdl {};
					class V_PlateCarrierL_CTRG {};
				};
			};
			class V_PlateCarrier2_blk {
				class Textures {
					class V_PlateCarrier2_rgr {};
					class V_PlateCarrier2_rgr_noflag_F {};
					class V_PlateCarrier2_wdl {};
					class V_PlateCarrier2_CTRG {};
				};
			};
		};
		
		class Backpacks {
			class B_LegStrapBag_black_F {};
			class B_Messenger_Black_F {};
			class B_AssaultPack_blk {};
			class B_FieldPack_blk {};
			class B_Kitbag_cbr {};
			class B_TacticalPack_blk {};
			class B_Carryall_cbr {};
			class B_ViperLightHarness_blk_F {};
			class B_ViperHarness_blk_F {};
			class B_Parachute {};
		};
	};
};