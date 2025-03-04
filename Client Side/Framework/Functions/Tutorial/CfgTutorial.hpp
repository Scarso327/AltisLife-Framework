class CfgTutorial {
	class Stages {
		class GetCash {
			displayName = "Acquire £100k Cash";
			description = "Use an ATM to acquire £100k cash";
			location[] = { 3640.48, 13082.8, 0 };
			nextStage = "BuyBackpack";
			condition = "ULP_234_Cash >= 100000 || { [""Driving""] call ULP_fnc_hasLicense }";
		};
		class BuyBackpack {
			displayName = "Buy Backpack";
			description = "Buy a backpack at the clothing store";
			location[] = { 3630.21, 13077.2, 0 };
			nextStage = "BuyLicense";
			condition = "!((backpack player) isEqualTo """") || { [""Driving""] call ULP_fnc_hasLicense }";
		};
		class BuyLicense {
			displayName = "Buy Driving License";
			description = "Buy a driving license at the DVLA";
			location[] = { 3649.38, 13093.8, 0 };
			nextStage = "BuyCar";
			condition = "[""Driving""] call ULP_fnc_hasLicense";
		};
		class BuyCar {
			displayName = "Buy Car";
			description = "Buy a offroad at the car shop";
			location[] = { 3693.8, 13155, 0 };
			nextStage = "StoreCash";
			condition = "!(ULP_Keys isEqualTo [])";
		};
		class StoreCash {
			displayName = "Store Cash";
			description = "Drive your car to the ATM and store the remaining cash. You can unlock your vehicle using <t color='#B92DE0'>U</t>";
			location[] = { 3640.48, 13082.8, 0 };
			nextStage = "GoAppleField";
			condition = "ULP_234_Cash isEqualTo 0";
		};
		class GoAppleField {
			displayName = "Go to Apple Field";
			description = "Go to the Apple Field";
			location[] = { 4193.83, 12993.5, 0 };
			nextStage = "GatherApples";
			condition = "(player distance [4193.83,12993.5, 0]) <= 20";
		};
		class GatherApples {
			displayName = "Gather Apples";
			description = "Use <t color='#B92DE0'>Left Windows</t> key to gather apples. You can rebind this interaction key under <t color='#B92DE0'>Custom Control 10</t>";
			location[] = { 4193.83, 12993.5, 0 };
			nextStage = "GoMarket";
			condition = """FreshApple"" in ULP_Inventory";
		};
		class GoMarket {
			displayName = "Go to General Market";
			description = "Go to the General Market";
			location[] = { 3629, 13095, 0 };
			nextStage = "SellApples";
			condition = "(player distance [3629, 13095, 0]) <= 10";
		};
		class SellApples {
			displayName = "Sell Apples";
			description = "Sell the apples you gathered to the market";
			location[] = { 3629, 13095, 0 };
			condition = "!(""FreshApple"" in ULP_Inventory)";
		};
	};
};