class CfgGathering {
	class apple {
		text = "Gathering apples...";
		amount = 5;
		zones[] = { "apple_area_1" };
		profession[] = { "Prof_Gathering", 0, 1, 50 }; // PROFESSION, REQUIRED LEVEL, INCREASE AMOUNT, CHANCE OF INCREASE
		gathered = "apple";
		gems[] = {};
		item = "";
		zoneSize = 30;
	};

	class tin_ore {
		text = "Mining for Tin...";
		amount = 5;
		zones[] = { "tin_area" };
		profession[] = { "Prof_Mining", 0, 1, 50 }; // PROFESSION, REQUIRED LEVEL, INCREASE AMOUNT, CHANCE OF INCREASE
		gathered = "tin_ore";
		gems[] = { {"nothing",0,45},{"uncut_opal",45,63},{"uncut_sapphire",63,78},{"uncut_ruby",78,90},{"uncut_emerald",90,97},{"uncut_diamond",97,100} };
		item = "pickaxe";
		zoneSize = 30;
	};
};