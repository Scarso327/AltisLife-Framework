class CfgTutorial {
	class Stages {
		class GetCash {
			displayName = "Acquire £100k Cash";
			description = "Use a ATM to acquire £100k cash";
			location[] = { 0, 0, 0 };
			nextStage = "BuyBackpack";
			condition = "ULP_234_Cash >= 100000";
		};
		class BuyBackpack {
			displayName = "Buy Backpack";
			description = "Buy a backpack at the clothing store";
			location[] = { 0, 0, 0 };
			nextStage = "BuyLicense";
			condition = "!((backpack player) isEqualTo """")";
		};
		class BuyLicense {
			displayName = "Buy Driving License";
			description = "Buy a driving license at the DVLA";
			location[] = { 0, 0, 0 };
			nextStage = "BuyCar";
			condition = "[""Driving""] call ULP_fnc_hasLicense";
		};
		class BuyCar {
			displayName = "Buy Car";
			description = "Buy a offroad at the car shop";
			location[] = { 0, 0, 0 };
			nextStage = "StoreCash";
			condition = "!(ULP_Keys isEqualTo [])";
		};
		class StoreCash {
			displayName = "Store Cash";
			description = "Use a ATM to store remaining cash";
			location[] = { 0, 0, 0 };
			nextStage = "GoAppleField";
			condition = "ULP_234_Cash isEqualTo 0";
		};
		class GoAppleField {
			displayName = "Go to Apple Field";
			description = "Go to the Apple Field";
			location[] = { 0, 0, 0 };
			nextStage = "GatherApples";
			condition = "(player distance [0, 0, 0]) <= 20";
		};
		class GatherApples {
			displayName = "Gather Apples";
			description = "Use Left Windows key to gather apples";
			location[] = { 0, 0, 0 };
			nextStage = "GoMarket";
			condition = """FreshApple"" in ULP_Inventory";
		};
		class GoMarket {
			displayName = "Go to General Market";
			description = "Go to the General Market";
			location[] = { 0, 0, 0 };
			nextStage = "GatherApples";
			condition = "(player distance [0, 0, 0]) <= 10";
		};
		class SellApples {
			displayName = "Sell Apples";
			description = "Sell the apples you gathered to the market";
			location[] = { 0, 0, 0 };
			condition = "!(""FreshApple"" in ULP_Inventory)";
		};
	};
};