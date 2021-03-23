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
			
			class OrangeSUV {
				chance = 0.95; // Chance 1 - VAL so this is 5% chance
				type = "TEXTURE";
				fallback[] = { 100000, 200000 }; // Money to be given if they already have this texture
				value[] = { "C_SUV_01_F", "Orange" };
			};

			class Money {
				chance = 0.80;
				type = "CASH";
				value[] = { 50000, 150000 }; // VAL_1 + (random VAL_2);
			};

			class XP {
				type = "XP";
				value[] = { 200, 250 }; // VAL_1 + (random VAL_2);
			};
		};
	};
};