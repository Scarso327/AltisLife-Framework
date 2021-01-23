class CfgClothesStore {
	onItemBuy = "_this call ULP_fnc_onBuyClothes";
	toolBoxIDC = 3102;
	itemCfg = "CfgClothing";

	class Police {
		storeName = "Police Clothing Store";
		class Uniforms {
			class U_Rangemaster {
				displayName = "Police Uniform";
			};
		};
		class Headgear {
			class H_Beret_blk_POLICE {};
		};
		class Facewear {
			class G_Tactical_Clear {};
		};
		class Vests {
			class V_TacVest_blk_POLICE {};
		};
		class Backpacks {
			class B_Carryall_cbr {};
		};
	};

	class Civilian {
		storeName = "Civilian Clothing Store";
		class Uniforms {
			class U_Rangemaster { class Textures {}; };
		};
	};
};