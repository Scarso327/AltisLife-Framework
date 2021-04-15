class CfgRewards {
	class Types {
		class CASH {
			message = "You've been awarded %1 for %2";
			onRewarded = "[(_this select 1), true, ""Reward""] call ULP_fnc_addMoney; format[""%1%2"", ""£"", [(_this select 1)] call ULP_fnc_numberText]";
		};
		class XP : CASH {
			onRewarded = "[(_this select 1), ""Reward"", 100] call ULP_fnc_addXP; format[""%1 XP"", [(_this select 1)] call ULP_fnc_numberText]";
		};
		class TEXTURE : CASH {
			onRewarded = "_this call ULP_fnc_grantTexture";
		};
	};

	class Tiers {
		class Basic {
			default = "XP";
			
			class MB4_Ridge {
				chance = 0.95;
				type = "TEXTURE";
				fallback[] = { 100000, 200000 };
				value[] = { "C_Offroad_02_unarmed_F", "Ridge" };
			};

			class Money {
				chance = 0.80;
				type = "CASH";
				value[] = { 50000, 150000 };
			};

			class XP {
				type = "XP";
				value[] = { 300, 500 };
			};
		};

		class Advanced {
			default = "XP";

			class MB4_Ridge {
				chance = 0.95;
				type = "TEXTURE";
				fallback[] = { 100000, 200000 };
				value[] = { "C_Offroad_02_unarmed_F", "Ridge" };
			};
			
			class Offroad_Ridge {
				chance = 0.80;
				type = "TEXTURE";
				fallback[] = { 150000, 300000 };
				value[] = { "C_Offroad_01_F", "Ridge" };
			};

			class Money {
				chance = 0.70;
				type = "CASH";
				value[] = { 80000, 150000 };
			};

			class XP {
				type = "XP";
				value[] = { 500, 1000 };
			};
		};

		class Expert {
			default = "XP";
			
			class HEMTT_Ridge {
				chance = 0.95;
				type = "TEXTURE";
				fallback[] = { 200000, 450000 };
				value[] = { "B_Truck_01_box_F", "Ridge" };
			};

			class Ifrit_Oil {
				chance = 0.90;
				type = "TEXTURE";
				fallback[] = { 200000, 450000 };
				value[] = { "O_MRAP_02_F", "Oil" };
			};

			class Strider_Asiimov {
				chance = 0.85;
				type = "TEXTURE";
				fallback[] = { 200000, 450000 };
				value[] = { "I_MRAP_03_F", "Asiimov" };
			};

			class Money {
				chance = 0.45;
				type = "CASH";
				value[] = { 100000, 250000 };
			};

			class XP {
				type = "XP";
				value[] = { 750, 1500 };
			};
		};
	};
};