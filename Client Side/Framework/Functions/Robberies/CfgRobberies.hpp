class CfgRobberies {
	personalTimeout = 3 * 60;
	
	class FuelStation {
		name = "Fuel Station";
		time = 5 * 60;
		timeout = 3 * 60;
		factions[] = { "Civilian" };
		reward[] = { 50000, 85000 };
		leveling[] = { { 5, 15 }, "Robbed Fuel Station", 100 };
		condition = "[[""Police""]] call ULP_fnc_onlineFaction >= 3";
		onFail = "[""There must be at least <t color='#B92DE0'>3 officers</t> online to rob this site!""] call ULP_fnc_hint;";
	};

	class Supermarket {
		name = "Supermarket";
		time = 7 * 60;
		timeout = 5 * 60;
		factions[] = { "Civilian" };
		reward[] = { 80000, 100000 };
		leveling[] = { { 5, 15 }, "Robbed Supermarket", 100 };
		condition = "[[""Police""]] call ULP_fnc_onlineFaction >= 4";
		onFail = "[""There must be at least <t color='#B92DE0'>4 officers</t> online to rob this site!""] call ULP_fnc_hint;";
	};

	class Jewellery {
		name = "Jewellery Store";
		time = 8 * 60;
		timeout = 15 * 60;
		factions[] = { "Civilian" };
		reward[] = { 150000, 250000 };
		leveling[] = { { 5, 15 }, "Robbed Jewellery Store", 100 };
		condition = "[[""Police""]] call ULP_fnc_onlineFaction >= 4";
		onFail = "[""There must be at least <t color='#B92DE0'>4 officers</t> online to rob this site!""] call ULP_fnc_hint;";
	};

	class RegionalBank {
		name = "Regional Bank";
		time = 10 * 60;
		timeout = 30 * 60;
		factions[] = { "Civilian" };
		reward[] = { 200000, 500000 };
		leveling[] = { { 5, 15 }, "Robbed Regional Bank", 100 };
		condition = "[[""Police""]] call ULP_fnc_onlineFaction >= 5";
		onFail = "[""There must be at least <t color='#B92DE0'>5 officers</t> online to rob this site!""] call ULP_fnc_hint;";
	};
};