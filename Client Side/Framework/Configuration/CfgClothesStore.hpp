class CfgClothesStore {
	onItemBuy = "_this call ULP_fnc_onBuyClothes";
	toolBoxIDC = 3102;
	itemCfg = "CfgClothing";

	class Police {
		storeName = "Police Clothing Store";
		class Uniforms {
			
		};

		class Headgear {
			class H_WirelessEarpiece_F {};
			class H_Cap_blk {
				displayName = "Cap";
				class Textures {
					class H_Cap_blk {
						displayName = "Black";
						condition = "true";
					};
					class H_Cap_red : H_Cap_blk { displayName = "Red"; };
					class H_Cap_blu : H_Cap_blk { displayName = "Blue"; };
					class H_Cap_tan : H_Cap_blk { displayName = "Tan"; };
					class H_Cap_oli : H_Cap_blk { displayName = "Olive"; };
					class H_Cap_police : H_Cap_blk { displayName = "Police"; };
				};
			};
			class H_Beret_blk {
				displayName = "Beret";
				class Textures {
					class H_Beret_blk {
						displayName = "Police";
						condition = "true";
					};
					class H_Beret_EAF_01_F : H_Beret_blk {
						displayName = "SFO";
						condition = "[""Police_SFO"", 1] call ULP_fnc_hasAccess;";
					};
					class H_Beret_gen_F : H_Beret_blk {
						displayName = "Command";
						condition = "[""Police_Main"", 7] call ULP_fnc_hasAccess";
					};
				};
			};
			class H_Watchcap_blk { condition = "[""Police_Main"", 3] call ULP_fnc_hasAccess"; };
			class H_PilotHelmetHeli_B { 
				displayName = "Flight Helmet";
				condition = "[""Police_Main"", 2] call ULP_fnc_hasAccess;";
				class Textures {
					class H_PilotHelmetHeli_B {
						displayName = "Pilot";
						condition = "true";
					};
					class H_CrewHelmetHeli_B : H_PilotHelmetHeli_B { displayName = "Crew"; };
				};
			};
			class H_HelmetSpecB_blk { 
				displayName = "Operation Helmet";
				condition = "[""Police_SFO"", 1] call ULP_fnc_hasAccess;"; 
			};
		};

		class Facewear {
			class G_WirelessEarpiece_F {};
			class G_Aviator {};
			class G_Squares {
				class Textures {
					class G_Squares {
						displayName = "Clear";
						condition = "true";
					};
					class G_Squares_Tinted : G_Squares { displayName = "Tinted"; };
				};
			};
			class G_Spectacles {
				class Textures {
					class G_Spectacles {
						displayName = "Clear";
						condition = "true";
					};
					class G_Spectacles_Tinted : G_Spectacles { displayName = "Tinted"; };
				};
			};
			class G_Shades_Black {
				displayName = "Shades";
				class Textures {
					class G_Shades_Black {
						displayName = "Black";
						condition = "true";
					};
					class G_Shades_Red : G_Shades_Black { displayName = "Red"; };
					class G_Squares_Green : G_Shades_Black { displayName = "Green"; };
					class G_Squares_Blue : G_Shades_Black { displayName = "Blue";
					};
				};
			};
			class G_Sport_Red {
				displayName = "Sport Shades";
				class Textures {
					class G_Sport_Red {
						displayName = "Red";
						condition = "true";
					};
					class G_Shades_BlackWhite : G_Sport_Red { displayName = "Black-White"; };
					class G_Shades_Blackred : G_Sport_Red { displayName = "Black-Red"; };
					class G_Shades_Blackyellow : G_Sport_Red { displayName = "Black-Yellow"; };
					class G_Shades_Greenblack : G_Sport_Red { displayName = "Green-Black"; };
					class G_Shades_checkered : G_Sport_Red { displayName = "Checkered"; };
				};
			};
			class G_Lady_Blue {};
			class G_Tactical_Clear {};
			class G_B_Diving { condition = "[""Police_SFO"", 1] call ULP_fnc_hasAccess;"; };
			class G_Respirator_white_F {
				displayName = "Respirator";
				class Textures {
					class G_Respirator_white_F {
						displayName = "White";
						condition = "true";
					};
					class G_Respirator_blue_F : G_Respirator_white_F { displayName = "Blue"; };
					class G_Respirator_yellow_F : G_Respirator_white_F { displayName = "Yellow"; };
				};
			};
			class G_RegulatorMask_F {};
			class G_Bandanna_aviator {
				displayName = "Bandanna";
				condition = "[""Police_SFO"", 1] call ULP_fnc_hasAccess;";
				class Textures {
					class G_Bandanna_aviator {
						displayName = "Black + Aviators";
						condition = "true";
					};
					class G_Bandanna_shades : G_Bandanna_aviator { displayName = "Black + Shades"; };
					class G_Bandanna_sport : G_Bandanna_aviator { displayName = "Black + Sport"; };
					class G_Bandanna_beast : G_Bandanna_aviator { displayName = "Beast"; };
					class G_Bandanna_blk : G_Bandanna_aviator { displayName = "Black"; };
				};
			};
			class G_Balaclava_TI_blk_F {
				displayName = "Balaclava";
				condition = "[""Police_SFO"", 1] call ULP_fnc_hasAccess;";
				class Textures {
					class G_Balaclava_TI_blk_F {
						displayName = "Black";
						condition = "true";
					};
					class G_Balaclava_TI_G_blk_F : G_Balaclava_TI_blk_F { displayName = "Black + Goggles"; };
				};
			};
		};

		class Vests {
			class V_LegStrapBag_black_F {};
			class V_Rangemaster_belt {};
			class V_BandollierB_blk {};
			class V_TacVest_blk_POLICE {};
			class V_PlateCarrier1_blk {};
			class V_PlateCarrier2_blk {};
			class V_RebreatherB { condition = "[""Police_SFO"", 1] call ULP_fnc_hasAccess;"; };
		};

		class Backpacks {
			class B_Carryall_cbr { displayName = "Invisible Backpack"; };
		};
	};

	class Medic {
		storeName = "Medic Clothing Store";
		class Uniforms {
			
		};
		
		class Headgear {
			class H_HeadBandage_clean_F {};
			class H_WirelessEarpiece_F {};
			class H_Cap_blk {
				displayName = "Cap";
				class Textures {
					class H_Cap_blk {
						displayName = "Black";
						condition = "true";
					};
					class H_Cap_red : H_Cap_blk { displayName = "Red"; };
					class H_Cap_blu : H_Cap_blk { displayName = "Blue"; };
					class H_Cap_tan : H_Cap_blk { displayName = "Tan"; };
					class H_Cap_oli : H_Cap_blk { displayName = "Olive"; };
					class H_Cap_surfer : H_Cap_blk { displayName = "Surfer"; };
				};
			};
			class H_Watchcap_blk {
				displayName = "Beanie";
				class Textures {
					class H_Watchcap_blk {
						displayName = "Black";
						condition = "true";
					};
					class H_Watchcap_cbr : H_Watchcap_blk { displayName = "Brown"; };
					class H_Watchcap_khk : H_Watchcap_blk { displayName = "Khaki"; };
					class H_Watchcap_camo : H_Watchcap_blk { displayName = "Green"; };
				};
			};
			class H_Beret_CSAT_01_F { condition = "[""Medic_Main"", 5] call ULP_fnc_hasAccess"; };
			class H_PilotHelmetHeli_B { 
				displayName = "Flight Helment";
				condition = "[""Medic_Main"", 2] call ULP_fnc_hasAccess;";
				class Textures {
					class H_PilotHelmetHeli_B {
						displayName = "Pilot";
						condition = "true";
					};
					class H_CrewHelmetHeli_B : H_PilotHelmetHeli_B { displayName = "Crew"; };
				};
			};
		};

		class Facewear {
			class G_WirelessEarpiece_F {};
			class G_Aviator {};
			class G_Squares {
				class Textures {
					class G_Squares {
						displayName = "Clear";
						condition = "true";
					};
					class G_Squares_Tinted : G_Squares { displayName = "Tinted"; };
				};
			};
			class G_Spectacles {
				class Textures {
					class G_Spectacles {
						displayName = "Clear";
						condition = "true";
					};
					class G_Spectacles_Tinted : G_Spectacles { displayName = "Tinted"; };
				};
			};
			class G_Shades_Black {
				displayName = "Shades";
				class Textures {
					class G_Shades_Black {
						displayName = "Black";
						condition = "true";
					};
					class G_Shades_Red : G_Shades_Black { displayName = "Red"; };
					class G_Squares_Green : G_Shades_Black { displayName = "Green"; };
					class G_Squares_Blue : G_Shades_Black { displayName = "Blue";
					};
				};
			};
			class G_Sport_Red {
				displayName = "Sport Shades";
				class Textures {
					class G_Sport_Red {
						displayName = "Red";
						condition = "true";
					};
					class G_Shades_BlackWhite : G_Sport_Red { displayName = "Black-White"; };
					class G_Shades_Blackred : G_Sport_Red { displayName = "Black-Red"; };
					class G_Shades_Blackyellow : G_Sport_Red { displayName = "Black-Yellow"; };
					class G_Shades_Greenblack : G_Sport_Red { displayName = "Green-Black"; };
					class G_Shades_checkered : G_Sport_Red { displayName = "Checkered"; };
				};
			};
			class G_Lady_Blue {};
			class G_Tactical_Clear {};
			class G_B_Diving { condition = "[""Medic_Main"", 1] call ULP_fnc_hasAccess;"; };
			class G_Respirator_white_F {
				displayName = "Respirator";
				class Textures {
					class G_Respirator_white_F {
						displayName = "White";
						condition = "true";
					};
					class G_Respirator_blue_F : G_Respirator_white_F { displayName = "Blue"; };
					class G_Respirator_yellow_F : G_Respirator_white_F { displayName = "Yellow"; };
				};
			};
			class G_RegulatorMask_F {};
		};

		class Vests {
			class V_LegStrapBag_black_F {};
			class V_Safety_yellow_F {};
			class V_BandollierB_blk {};
			class V_RebreatherB { condition = "[""Medic_Main"", 2] call ULP_fnc_hasAccess"; };
		};

		class Backpacks {
			class B_Carryall_cbr { displayName = "Invisible Backpack"; };
		};
	};

	class Civilian {
		storeName = "Civilian Clothing Store";
		class Uniforms {
			
		};
		class Headgear {
			class H_WirelessEarpiece_F {};
			class H_Bandanna_gry {
				displayName = "Bandanna";
				class Textures {
					class H_Bandanna_gry {
						displayName = "Gray";
						condition = "true";
					};
					class H_Bandanna_blu : H_Bandanna_gry { displayName = "Blue"; };
					class H_Bandanna_khk : H_Bandanna_gry { displayName = "Khaki"; };
					class H_Bandanna_cbr : H_Bandanna_gry { displayName = "Coyote"; };
					class H_Bandanna_sand : H_Bandanna_gry { displayName = "Sand"; };
					class H_Bandanna_sgg : H_Bandanna_gry { displayName = "Sage"; };
					class H_Bandanna_camo : H_Bandanna_gry { displayName = "Camo"; };
					class H_Bandanna_mcamo : H_Bandanna_gry { displayName = "MTP"; };
				};
			};
			class H_Cap_blk {
				displayName = "Cap";
				class Textures {
					class H_Cap_blk {
						displayName = "Black";
						condition = "true";
					};
					class H_Cap_usblack : H_Cap_blk { displayName = "US (Black)"; };
					class H_Cap_tan_specops_US : H_Cap_blk { displayName = "US (MTP)"; };
					class H_Cap_khaki_specops_UK : H_Cap_blk { displayName = "UK"; };
					class H_Cap_brn_SPECOPS : H_Cap_blk { displayName = "OPFOR"; };
					class H_Cap_blk_Raven : H_Cap_blk { displayName = "AAF"; };
					class H_Cap_grn_BI : H_Cap_blk { displayName = "BI"; };
					class H_Cap_blk_ION : H_Cap_blk { displayName = "ION"; };
					class H_Cap_blk_CMMG : H_Cap_blk { displayName = "CMMG"; };
					class H_Cap_red : H_Cap_blk { displayName = "Red"; };
					class H_Cap_blu : H_Cap_blk { displayName = "Blue"; };
					class H_Cap_tan : H_Cap_blk { displayName = "Tan"; };
					class H_Cap_oli : H_Cap_blk { displayName = "Olive"; };
				};
			};
			class H_Hat_grey {
				displayName = "Hat";
				class Textures {
					class H_Hat_grey {
						displayName = "Grey";
						condition = "true";
					};
					class H_Hat_blue : H_Hat_grey { displayName = "Blue"; };
					class H_Hat_brown : H_Hat_grey { displayName = "Brown"; };
					class H_Hat_tan : H_Hat_grey { displayName = "Tan"; };
					class H_Hat_checker : H_Hat_grey { displayName = "Checker"; };
					class H_Hat_camo : H_Hat_grey { displayName = "Camo"; };
					class H_StrawHat : H_Hat_grey { displayName = "Straw (Light)"; };
					class H_StrawHat_dark : H_Hat_grey { displayName = "Straw (Dark)"; };
				};
			};
			class H_Hat_Safari_sand_F {
				displayName = "Safari";
				class Textures {
					class H_Hat_Safari_sand_F {
						displayName = "Sand";
						condition = "true";
					};
					class H_Hat_Safari_olive_F : H_Hat_Safari_sand_F { displayName = "Olive"; };
				};
			};
			class H_Watchcap_blk {
				displayName = "Beanie";
				class Textures {
					class H_Watchcap_blk {
						displayName = "Black";
						condition = "true";
					};
					class H_Watchcap_cbr : H_Watchcap_blk { displayName = "Coyote"; };
					class H_Watchcap_khk : H_Watchcap_blk { displayName = "Khaki"; };
					class H_Watchcap_camo : H_Watchcap_blk { displayName = "Green"; };
				};
			};
			class H_Booniehat_khk {
				displayName = "Booniehat";
				class Textures {
					class H_Booniehat_khk {
						displayName = "Khaki";
						condition = "true";
					};
					class H_Booniehat_grn : H_Booniehat_khk { displayName = "Green"; };
					class H_Booniehat_oli : H_Booniehat_khk { displayName = "Olive"; };
					class H_Booniehat_tan : H_Booniehat_khk { displayName = "Tan"; };
					class H_Booniehat_mcamo : H_Booniehat_khk { displayName = "MTP"; };
					class H_Booniehat_dgtl : H_Booniehat_khk { displayName = "Digital"; };
					class H_Booniehat_wdl : H_Booniehat_khk { displayName = "Woodland"; };
				};
			};
			class H_EarProtectors_black_F {
				displayName = "Ear Protectors";
				class Textures {
					class H_EarProtectors_black_F {
						displayName = "Black";
						condition = "true";
					};
					class H_HeadSet_black_F : H_EarProtectors_black_F { displayName = "Black (Headset)"; };
					class H_EarProtectors_white_F : H_EarProtectors_black_F { displayName = "White"; };
					class H_HeadSet_white_F : H_EarProtectors_black_F { displayName = "White (Headset)"; };
					class H_EarProtectors_red_F : H_EarProtectors_black_F { displayName = "Red"; };
					class H_HeadSet_red_F : H_EarProtectors_black_F { displayName = "Red (Headset)"; };
					class H_EarProtectors_orange_F : H_EarProtectors_black_F { displayName = "Orange"; };
					class H_HeadSet_orange_F : H_EarProtectors_black_F { displayName = "Orange (Headset)"; };
					class H_EarProtectors_yellow_F : H_EarProtectors_black_F { displayName = "Yellow"; };
					class H_HeadSet_yellow_F : H_EarProtectors_black_F { displayName = "Yellow (Headset)"; };
				};
			};
			class H_Construction_basic_black_F {
				displayName = "Hard Hat";
				class Textures {
					class H_Construction_basic_black_F {
						displayName = "Black";
						condition = "true";
					};
					class H_Construction_headset_black_F : H_Construction_basic_black_F { displayName = "Black (Headset)"; };
					class H_Construction_basic_white_F : H_Construction_basic_black_F { displayName = "White"; };
					class H_Construction_headset_white_F : H_Construction_basic_black_F { displayName = "White (Headset)"; };
					class H_Construction_basic_red_F : H_Construction_basic_black_F { displayName = "Red"; };
					class H_Construction_headset_red_F : H_Construction_basic_black_F { displayName = "Red (Headset)"; };
					class H_Construction_basic_orange_F : H_Construction_basic_black_F { displayName = "Orange"; };
					class H_Construction_headset_orange_F : H_Construction_basic_black_F { displayName = "Orange (Headset)"; };
					class H_Construction_basic_yellow_F : H_Construction_basic_black_F { displayName = "Yellow"; };
					class H_Construction_headset_yellow_F : H_Construction_basic_black_F { displayName = "Yellow (Headset)"; };
					class H_Construction_basic_vrana_F : H_Construction_basic_black_F { displayName = "Virana"; };
					class H_Construction_headset_vrana_F : H_Construction_basic_black_F { displayName = "Virana (Headset)"; };
				};
			};
			class H_Helmet_Skate {};
		};

		class Facewear {
			class G_WirelessEarpiece_F {};
			class G_Aviator {};
			class G_Squares {
				class Textures {
					class G_Squares {
						displayName = "Clear";
						condition = "true";
					};
					class G_Squares_Tinted : G_Squares { displayName = "Tinted"; };
				};
			};
			class G_Spectacles {
				class Textures {
					class G_Spectacles {
						displayName = "Clear";
						condition = "true";
					};
					class G_Spectacles_Tinted : G_Spectacles { displayName = "Tinted"; };
				};
			};
			class G_Shades_Black {
				displayName = "Shades";
				class Textures {
					class G_Shades_Black {
						displayName = "Black";
						condition = "true";
					};
					class G_Shades_Red : G_Shades_Black { displayName = "Red"; };
					class G_Squares_Green : G_Shades_Black { displayName = "Green"; };
					class G_Squares_Blue : G_Shades_Black { displayName = "Blue";
					};
				};
			};
			class G_Sport_Red {
				displayName = "Sport Shades";
				class Textures {
					class G_Sport_Red {
						displayName = "Red";
						condition = "true";
					};
					class G_Shades_BlackWhite : G_Sport_Red { displayName = "Black-White"; };
					class G_Shades_Blackred : G_Sport_Red { displayName = "Black-Red"; };
					class G_Shades_Blackyellow : G_Sport_Red { displayName = "Black-Yellow"; };
					class G_Shades_Greenblack : G_Sport_Red { displayName = "Green-Black"; };
					class G_Shades_checkered : G_Sport_Red { displayName = "Checkered"; };
				};
			};
			class G_Lady_Blue {};
			class G_Tactical_Clear {};
			class G_B_Diving { condition = "[""Police_SFO"", 1] call ULP_fnc_hasAccess;"; };
			class G_Respirator_white_F {
				displayName = "Respirator";
				class Textures {
					class G_Respirator_white_F {
						displayName = "White";
						condition = "true";
					};
					class G_Respirator_blue_F : G_Respirator_white_F { displayName = "Blue"; };
					class G_Respirator_yellow_F : G_Respirator_white_F { displayName = "Yellow"; };
				};
			};
			class G_EyeProtectors_F {
				class Textures {
					class G_EyeProtectors_F {
						displayName = "Eye Protectors";
						condition = "true";
					};
					class G_EyeProtectors_Earpiece_F : G_EyeProtectors_F { displayName = "Eye Protectors + Earpiece"; };
				};
			};
		};

		class Vests {
			class V_LegStrapBag_black_F {
				displayName = "Leg Strap";
				class Textures {
					class V_LegStrapBag_black_F {
						displayName = "Black";
						condition = "true";
					};
					class V_LegStrapBag_coyote_F : V_LegStrapBag_black_F { displayName = "Coyote"; };
					class V_LegStrapBag_olive_F : V_LegStrapBag_black_F { displayName = "Olive"; };
				};
			};
			class V_Pocketed_black_F {
				displayName = "Pocketed Vest";
				class Textures {
					class V_Pocketed_black_F {
						displayName = "Black";
						condition = "true";
					};
					class V_Pocketed_coyote_F : V_Pocketed_black_F { displayName = "Coyote"; };
					class V_Safety_yellow_F : V_Pocketed_black_F { displayName = "Olive"; };
				};
			};
			class V_Safety_yellow_F {
				displayName = "Safety Vest";
				class Textures {
					class V_Safety_yellow_F {
						displayName = "Yellow";
						condition = "true";
					};
					class V_Safety_orange_F : V_Safety_yellow_F { displayName = "Orange"; };
					class V_Safety_blue_F : V_Safety_yellow_F { displayName = "Blue"; };
				};
			};
		};

		class Backpacks {
			class B_LegStrapBag_black_F {
				displayName = "Leg Strap";
				class Textures {
					class B_LegStrapBag_black_F {
						displayName = "Black";
						condition = "true";
					};
					class B_LegStrapBag_coyote_F : B_LegStrapBag_black_F { displayName = "Coyote"; };
					class B_LegStrapBag_olive_F : B_LegStrapBag_black_F { displayName = "Olive"; };
				};
			};
			class B_Messenger_Black_F {
				displayName = "Messenger Bag";
				class Textures {
					class B_Messenger_Black_F {
						displayName = "Black";
						condition = "true";
					};
					class B_Messenger_Gray_F : B_Messenger_Black_F { displayName = "Gray"; };
					class B_Messenger_Coyote_F : B_Messenger_Black_F { displayName = "Coyote"; };
					class B_Messenger_Olive_F : B_Messenger_Black_F { displayName = "Olive"; };
				};
			};
			class B_AssaultPack_blk {
				displayName = "Assault Pack";
				class Textures {
					class B_AssaultPack_blk {
						displayName = "Black";
						condition = "true";
					};
					class B_AssaultPack_cbr : B_AssaultPack_blk { displayName = "Coyote"; };
					class B_AssaultPack_khk : B_AssaultPack_blk { displayName = "Coyote"; };
					class B_AssaultPack_rgr : B_AssaultPack_blk { displayName = "Green"; };
					class B_AssaultPack_sgg : B_AssaultPack_blk { displayName = "Sage"; };
					class B_AssaultPack_wdl_F : B_AssaultPack_blk { displayName = "Woodland"; };
				};
			};
			class B_FieldPack_blk {
				displayName = "Field Pack";
				class Textures {
					class B_FieldPack_blk {
						displayName = "Black";
						condition = "true";
					};
					class B_FieldPack_cbr : B_FieldPack_blk { displayName = "Coyote"; };
					class B_FieldPack_khk : B_FieldPack_blk { displayName = "Khaki"; };
					class B_FieldPack_oli : B_FieldPack_blk { displayName = "Olive"; };
					class B_FieldPack_green_F : B_FieldPack_blk { displayName = "Green"; };
				};
			};
			class B_Kitbag_cbr {
				displayName = "Kitbag";
				class Textures {
					class B_Kitbag_cbr {
						displayName = "Coyote";
						condition = "true";
					};
					class B_Kitbag_tan : B_Kitbag_cbr { displayName = "Tan"; };
					class B_Kitbag_rgr : B_Kitbag_cbr { displayName = "Green"; };
					class B_Kitbag_sgg : B_Kitbag_cbr { displayName = "Sage"; };
					class B_Kitbag_mcamo : B_Kitbag_cbr { displayName = "MTP"; };
				};
			};
			class B_TacticalPack_blk {
				displayName = "Tactical Pack";
				class Textures {
					class B_TacticalPack_blk {
						displayName = "Black";
						condition = "true";
					};
					class B_TacticalPack_oli : B_TacticalPack_blk { displayName = "Olive"; };
					class B_TacticalPack_rgr : B_TacticalPack_blk { displayName = "Green"; };
				};
			};
			class B_Carryall_cbr {
				displayName = "Carryall";
				class Textures {
					class B_Carryall_cbr {
						displayName = "Coyote";
						condition = "true";
					};
					class B_Carryall_khk : B_Carryall_cbr { displayName = "khaki"; };
					class B_Carryall_oli : B_Carryall_cbr { displayName = "Olive"; };
					class B_Carryall_green_F : B_Carryall_cbr { displayName = "Green"; };
					class B_Carryall_wdl_F : B_Carryall_cbr { displayName = "Woodland"; };
				};
			};
			class B_ViperLightHarness_khk_F {
				displayName = "Light Viper Harness";
				class Textures {
					class B_ViperLightHarness_khk_F {
						displayName = "khaki";
						condition = "true";
					};
					class B_ViperLightHarness_oli_F : B_ViperLightHarness_khk_F { displayName = "Olive"; };
				};
			};
			class B_ViperHarness_khk_F {
				displayName = "Viper Harness";
				class Textures {
					class B_ViperHarness_khk_F {
						displayName = "khaki";
						condition = "true";
					};
					class B_ViperHarness_oli_F : B_ViperHarness_khk_F { displayName = "Olive"; };
				};
			};
			class B_Bergen_mcamo_F {
				displayName = "Bergen";
				class Textures {
					class B_Bergen_mcamo_F {
						displayName = "MTP";
						condition = "true";
					};
					class B_Bergen_dgtl_F : B_Bergen_mcamo_F { displayName = "Digital"; };
					class B_Bergen_hex_F : B_Bergen_mcamo_F { displayName = "Hex"; };
				};
			};
		};
	};

	class GoKart {
		storeName = "Go-Kart Clothing Store";
		class Uniforms {
			
		};

		class Headgear {
			class H_RacingHelmet_1_black_F {
				displayName = "Racing Helmet";
				class Textures {
					class H_RacingHelmet_1_black_F {
						displayName = "Black";
						condition = "true";
					};
					class H_RacingHelmet_1_white_F : H_RacingHelmet_1_black_F { displayName = "Black"; };
					class H_RacingHelmet_1_red_F : H_RacingHelmet_1_black_F { displayName = "Red"; };
					class H_RacingHelmet_1_blue_F : H_RacingHelmet_1_black_F { displayName = "Blue"; };
					class H_RacingHelmet_1_green_F : H_RacingHelmet_1_black_F { displayName = "Green"; };
					class H_RacingHelmet_1_orange_F : H_RacingHelmet_1_black_F { displayName = "Orange"; };
					class H_RacingHelmet_1_yellow_F : H_RacingHelmet_1_black_F { displayName = "Yellow"; };
					class H_RacingHelmet_4_F : H_RacingHelmet_1_black_F { displayName = "Vrana"; };
					class H_RacingHelmet_3_F : H_RacingHelmet_1_black_F { displayName = "Redstone"; };
					class H_RacingHelmet_2_F : H_RacingHelmet_1_black_F { displayName = "Bluking"; };
					class H_RacingHelmet_1_F : H_RacingHelmet_1_black_F { displayName = "Fuel"; };
				};
			};
		};

		class Facewear {};
		class Vests {};
		class Backpacks {};
	};

	class Diving {
		storeName = "Diving Store";
		class Uniforms {
			
		};

		class Headgear {
			class H_Bandanna_surfer {
				displayName = "Bandanna";
				class Textures {
					class H_Bandanna_surfer {
						displayName = "Surfer";
						condition = "true";
					};
					class H_Bandanna_surfer_blk : H_Bandanna_surfer { displayName = "Surfer, Black"; };
					class H_Bandanna_surfer_grn : H_Bandanna_surfer { displayName = "Surfer, Green"; };
				};
			};
			class H_Cap_surfer {};
		};

		class Facewear {
			class G_B_Diving {
				displayName = "Diving Goggles";
				class Textures {
					class G_B_Diving {
						displayName = "Black";
						condition = "true";
					};
					class G_O_Diving : G_B_Diving { displayName = "Brown"; };
					class G_I_Diving : G_B_Diving { displayName = "Green"; };
				};
			};
		};

		class Vests {
			class V_RebreatherB {
				displayName = "Rebreather";
				class Textures {
					class V_RebreatherB {
						displayName = "Black";
						condition = "true";
					};
					class V_RebreatherIR : V_RebreatherB { displayName = "Brown"; };
					class V_RebreatherIA : V_RebreatherB { displayName = "Green"; };
				};
			};
		};

		class Backpacks {
			class B_ViperLightHarness_blk_F {};
			class B_ViperHarness_blk_F {};
		};
	};

	class Press {
		storeName = "Press Clothing Store";
		class Uniforms {
			
		};

		class Headgear {
			class H_Cap_press {};
			class H_PASGT_basic_blue_press_F {
				class Textures {
					class H_PASGT_basic_blue_press_F {
						displayName = "Basic";
						condition = "true";
					};
					class H_PASGT_neckprot_blue_press_F : H_PASGT_basic_blue_press_F { displayName = "Neck Protection"; };
				};
			};
		};

		class Facewear {
			class G_WirelessEarpiece_F {};
			class G_Aviator {};
			class G_Squares {
				class Textures {
					class G_Squares {
						displayName = "Clear";
						condition = "true";
					};
					class G_Squares_Tinted : G_Squares { displayName = "Tinted"; };
				};
			};
			class G_Spectacles {
				class Textures {
					class G_Spectacles {
						displayName = "Clear";
						condition = "true";
					};
					class G_Spectacles_Tinted : G_Spectacles { displayName = "Tinted"; };
				};
			};
			class G_Shades_Black {
				displayName = "Shades";
				class Textures {
					class G_Shades_Black {
						displayName = "Black";
						condition = "true";
					};
					class G_Shades_Red : G_Shades_Black { displayName = "Red"; };
					class G_Squares_Green : G_Shades_Black { displayName = "Green"; };
					class G_Squares_Blue : G_Shades_Black { displayName = "Blue";
					};
				};
			};
			class G_Sport_Red {
				displayName = "Sport Shades";
				class Textures {
					class G_Sport_Red {
						displayName = "Red";
						condition = "true";
					};
					class G_Shades_BlackWhite : G_Sport_Red { displayName = "Black-White"; };
					class G_Shades_Blackred : G_Sport_Red { displayName = "Black-Red"; };
					class G_Shades_Blackyellow : G_Sport_Red { displayName = "Black-Yellow"; };
					class G_Shades_Greenblack : G_Sport_Red { displayName = "Green-Black"; };
					class G_Shades_checkered : G_Sport_Red { displayName = "Checkered"; };
				};
			};
			class G_Lady_Blue {};
			class G_Tactical_Clear {};
			class G_B_Diving { condition = "[""Police_SFO"", 1] call ULP_fnc_hasAccess;"; };
			class G_Respirator_white_F {
				displayName = "Respirator";
				class Textures {
					class G_Respirator_white_F {
						displayName = "White";
						condition = "true";
					};
					class G_Respirator_blue_F : G_Respirator_white_F { displayName = "Blue"; };
					class G_Respirator_yellow_F : G_Respirator_white_F { displayName = "Yellow"; };
				};
			};
			class G_EyeProtectors_F {
				class Textures {
					class G_EyeProtectors_F {
						displayName = "Eye Protectors";
						condition = "true";
					};
					class G_EyeProtectors_Earpiece_F : G_EyeProtectors_F { displayName = "Eye Protectors + Earpiece"; };
				};
			};
		};

		class Vests {
			class V_Press_F {};
		};

		class Backpacks {
			class B_Messenger_Black_F {
				displayName = "Messenger Bag";
				class Textures {
					class B_Messenger_Black_F {
						displayName = "Black";
						condition = "true";
					};
					class B_Messenger_Gray_F : B_Messenger_Black_F { displayName = "Gray"; };
					class B_Messenger_Coyote_F : B_Messenger_Black_F { displayName = "Coyote"; };
					class B_Messenger_Olive_F : B_Messenger_Black_F { displayName = "Olive"; };
				};
			};
		};
	};

	class Syndikat {
		storeName = "Syndikat Clothing Store";
		class Uniforms {
			
		};
		class Headgear {
			class H_WirelessEarpiece_F {};
			class H_Bandanna_gry {};
			class H_Bandanna_blu {};
			class H_Bandanna_khk {};
			class H_Bandanna_cbr {};
			class H_Bandanna_sand {};
			class H_Bandanna_sgg {};
			class H_Bandanna_camo {};
			class H_Bandanna_mcamo {};
			class H_Cap_blk {};
			class H_Cap_usblack {};
			class H_Cap_tan_specops_US {};
			class H_Cap_khaki_specops_UK {};
			class H_Cap_brn_SPECOPS {};
			class H_Cap_blk_Raven {};
			class H_Cap_grn_BI {};
			class H_Cap_blk_ION {};
			class H_Cap_blk_CMMG {};
			class H_Cap_red {};
			class H_Cap_blu {};
			class H_Cap_tan {};
			class H_Cap_oli {};
			class H_Watchcap_blk {};
			class H_Watchcap_cbr {};
			class H_Watchcap_khk {};
			class H_Watchcap_camo {};
			class H_Booniehat_khk {};
			class H_Booniehat_khk_hs {};
			class H_Booniehat_grn {};
			class H_Booniehat_oli {};
			class H_Booniehat_tan {};
			class H_Booniehat_mcamo {};
			class H_Booniehat_dgtl {};
			class H_Booniehat_wdl {};
			class H_ShemagOpen_khk {};
			class H_Shemag_tan {};
			class H_Shemag_olive {};
			class H_HelmetB_light {};
			class H_HelmetB_light_black {};
			class H_HelmetB_light_desert {};
			class H_HelmetB_light_sand {};
			class H_HelmetB_light_snakeskin {};
			class H_HelmetB_light_grass {};
			class H_HelmetB_light_wdl {};
			class H_HelmetB {};
			class H_HelmetB_plain_blk {};
			class H_HelmetB_desert {};
			class H_HelmetB_sand {};
			class H_HelmetB_snakeskin {};
			class H_HelmetB_grass {};
			class H_HelmetB_camo {};
			class H_HelmetB_paint {};
			class H_HelmetB_plain_wdl {};
			class H_HelmetSpecB {};
			class H_HelmetSpecB_blk {};
			class H_HelmetSpecB_paint2 {};
			class H_HelmetSpecB_sand {};
			class H_HelmetSpecB_snakeskin {};
			class H_HelmetSpecB_paint1 {};
		};
		class Facewear {
			class G_WirelessEarpiece_F {};
			class G_Aviator {};
			class G_Squares {};
			class G_Squares_Tinted {};
			class G_Spectacles {};
			class G_Spectacles_Tinted {};
			class G_Shades_Black {};
			class G_Shades_Red {};
			class G_Squares_Green {};
			class G_Squares_Blue {};
			class G_Sport_Red {};
			class G_Shades_BlackWhite {};
			class G_Shades_Blackred {};
			class G_Shades_Blackyellow {};
			class G_Shades_Greenblack {};
			class G_Shades_checkered {};
			class G_Lowprofile {};
			class G_Combat {};
			class G_Tactical_Clear {};
			class G_RegulatorMask_F {};
			class G_Blindfold_01_black__F {};
			class G_Blindfold_01_white__F {};
			class G_Bandanna_aviator {};
			class G_Bandanna_shades {};
			class G_Bandanna_sport {};
			class G_Bandanna_beast {};
			class G_Bandanna_blk {};
			class G_Bandanna_khk {};
			class G_Bandanna_oli {};
			class G_Balaclava_blk {};
			class G_Balaclava_lowprofile {};
			class G_Balaclava_combat {};
			class G_Balaclava_oli {};
		};
		class Vests {
			class V_LegStrapBag_black_F {};
			class V_LegStrapBag_coyote_F {};
			class V_LegStrapBag_olive_F {};
			class V_Pocketed_black_F {};
			class V_Pocketed_coyote_F {};
			class V_Pocketed_olive_F {};
			class V_Rangemaster_belt {};
			class V_BandollierB_cbr {};
			class V_BandollierB_khk {};
			class V_BandollierB_oli {};
			class V_BandollierB_rgr {};
			class V_HarnessO_brn {};
			class V_HarnessO_gry {};
			class V_HarnessOGL_brn {};
			class V_HarnessOGL_gry {};
			class V_Chestrig_khk {};
			class V_Chestrig_oli {};
			class V_Chestrig_rgr {};
			class V_TacChestrig_cbr_F {};
			class V_TacChestrig_oli_F {};
			class V_TacChestrig_grn_F {};
			class V_TacVest_camo {};
			class V_TacVest_brn {};
			class V_TacVest_khk {};
			class V_TacVest_oli {};
			class V_PlateCarrier1_rgr {};
			class V_PlateCarrier1_rgr_noflag_F {};
			class V_PlateCarrier1_wdl {};
			class V_PlateCarrierL_CTRG {};
			class V_PlateCarrier2_rgr {};
			class V_PlateCarrier2_rgr_noflag_F {};
			class V_PlateCarrier2_wdl {};
			class V_PlateCarrierH_CTRG {};
		};
		class Backpacks {
			class B_LegStrapBag_black_F {};
			class B_LegStrapBag_coyote_F {};
			class B_LegStrapBag_olive_F {};
			class B_Messenger_Black_F {};
			class B_Messenger_Gray_F {};
			class B_Messenger_Coyote_F {};
			class B_Messenger_Olive_F {};
			class B_AssaultPack_blk {};
			class B_AssaultPack_cbr {};
			class B_AssaultPack_khk {};
			class B_AssaultPack_rgr {};
			class B_AssaultPack_sgg {};
			class B_AssaultPack_wdl_F {};
			class B_FieldPack_blk {};
			class B_FieldPack_cbr {};
			class B_FieldPack_khk {};
			class B_FieldPack_oli {};
			class B_FieldPack_green_F {};
			class B_Kitbag_cbr {};
			class B_Kitbag_tan {};
			class B_Kitbag_rgr {};
			class B_Kitbag_sgg {};
			class B_Kitbag_mcamo {};
			class B_TacticalPack_blk {};
			class B_TacticalPack_oli {};
			class B_TacticalPack_rgr {};
			class B_Carryall_cbr {};
			class B_Carryall_khk {};
			class B_Carryall_oli {};
			class B_Carryall_green_F {};
			class B_Carryall_wdl_F {};
			class B_ViperLightHarness_khk_F {};
			class B_ViperLightHarness_oli_F {};
			class B_ViperHarness_khk_F {};
			class B_ViperHarness_oli_F {};
			class B_Bergen_mcamo_F {};
			class B_Bergen_dgtl_F {};
			class B_Bergen_hex_F {};
			class B_Parachute {};
		};
	};
};