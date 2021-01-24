class CfgItemsStore {
	onItemBuy = "_this call ULP_fnc_onBuyItems";
	toolBoxIDC = 3113;
	itemCfg = "CfgItems";

	class Police {
		storeName = "Police Equipment Store";
		class Rifles {
			// MX with all texture options...
			class arifle_MX_F {};
		};
		class Pistols {
			// Black P07 with Suppressor (Not texture options)...
			class hgun_P07_blk_Snds_F { class Textures {}; };
		};
		class Attachments {
			
		};
		class Magazines {
			// Black 6.5 Mag for MX (Not texture options)...
			class 30Rnd_65x39_caseless_black_mag { class Textures {}; };
		};
		class Items {
			
		};
	};

	class Guns {
		storeName = "Gun Store";
		class Rifles {

		};
		class Pistols {
			// P07 with all texture options...
			class hgun_P07_F {};
		};
		class Attachments {
			
		};
		class Magazines {
			// 6.5 Mag for MX (Sand/Default and Khaki texture options)...
			class 30Rnd_65x39_caseless_mag {
				class Textures {
					class 30Rnd_65x39_caseless_mag {};
					class 30Rnd_65x39_caseless_khaki_mag : 30Rnd_65x39_caseless_mag {};
				};
			};
		};
		class Items {
			
		};
	};
};