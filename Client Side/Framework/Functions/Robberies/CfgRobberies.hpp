class CfgRobberies {
	personalTimeout = 3 * 60;
	
	class FuelStation {
		name = "Fuel Station";
		time = 5 * 60;
		timeout = 3 * 60;
		factions[] = { "Civilian" };
		reward[] = { 100, 500 };
		leveling[] = { { 5, 15 }, "Robbed Fuel Station", 100 };
		condition = "[[""Police""]] call ULP_fnc_onlineFaction < 5";
		onFail = "hint ""There must be at least 5 officers online to rob this store."";";
	};
};