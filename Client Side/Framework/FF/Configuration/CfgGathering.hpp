class CfgGathering {
	class mango {
		text = "Gathering mangos...";
		amount = 5; 
		zones[] = { "mango_area_1", "mango_area_2", "mango_area_3", "mango_area_4" };
		profession[] = { "Prof_Gathering", 0, 1, 50 }; // PROFESSION, REQUIRED LEVEL, INCREASE AMOUNT, CHANCE OF INCREASE
		gathered = "mango";
		gems[] = {};
		item = "";
		zoneSize = 30;
	};

	class coconut {
		text = "Gathering coconuts...";
		amount = 5; 
		zones[] = { "coconut_area_1", "coconut_area_2", "coconut_area_3" };
		profession[] = { "Prof_Gathering", 0, 1, 50 }; // PROFESSION, REQUIRED LEVEL, INCREASE AMOUNT, CHANCE OF INCREASE
		gathered = "coconut";
		gems[] = {};
		item = "";
		zoneSize = 30;
	};

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

	class bannana {
		text = "Gathering bannanas...";
		amount = 5; 
		zones[] = { "banana_area" };
		profession[] = { "Prof_Gathering", 50, 1, 50 }; // PROFESSION, REQUIRED LEVEL, INCREASE AMOUNT, CHANCE OF INCREASE
		gathered = "bannana";
		gems[] = {};
		item = "";
		zoneSize = 30;
	};

	class sugar {
		text = "Gathering sugar...";
		amount = 5; 
		zones[] = { "sugar_area" };
		profession[] = { "Prof_Gathering", 50, 1, 50 }; // PROFESSION, REQUIRED LEVEL, INCREASE AMOUNT, CHANCE OF INCREASE
		gathered = "sugarCane";
		gems[] = {};
		item = "";
		zoneSize = 30;
	};

	class rice {
		text = "Gathering rice...";
		amount = 5; 
		zones[] = { "rice_area" };
		profession[] = { "Prof_Gathering", 50, 1, 50 }; // PROFESSION, REQUIRED LEVEL, INCREASE AMOUNT, CHANCE OF INCREASE
		gathered = "rice";
		gems[] = {};
		item = "";
		zoneSize = 30;
	};

	class wood {
		text = "Gathering wood...";
		amount = 5; 
		zones[] = { "logging_area_area_1", "logging_area_area_2", "logging_area_area_3" };
		profession[] = { "Prof_Gathering", 100, 1, 50 }; // PROFESSION, REQUIRED LEVEL, INCREASE AMOUNT, CHANCE OF INCREASE
		gathered = "wood";
		gems[] = {};
		item = "axe";
		zoneSize = 30;
	};

	class cannabis {
		text = "Gathering cannabis...";
		amount = 3; 
		zones[] = { "cannabis_area" };
		profession[] = { "Prof_Gathering", 50, 1, 50 }; // PROFESSION, REQUIRED LEVEL, INCREASE AMOUNT, CHANCE OF INCREASE
		gathered = "cannabis";
		gems[] = {};
		item = "";
		zoneSize = 30;
	};

	class opium {
		text = "Gathering opium...";
		amount = 3; 
		zones[] = { "opium_area" };
		profession[] = { "Prof_Gathering", 100, 1, 50 }; // PROFESSION, REQUIRED LEVEL, INCREASE AMOUNT, CHANCE OF INCREASE
		gathered = "opium";
		gems[] = {};
		item = "";
		zoneSize = 30;
	};

	class coca {
		text = "Gathering coca...";
		amount = 3; 
		zones[] = { "coca_area" };
		profession[] = { "Prof_Gathering", 250, 1, 50 }; // PROFESSION, REQUIRED LEVEL, INCREASE AMOUNT, CHANCE OF INCREASE
		gathered = "coca";
		gems[] = {};
		item = "";
		zoneSize = 30;
	};

	class coal {
		text = "Mining for coal...";
		amount = 5;
		zones[] = { "coal_area" };
		profession[] = { "Prof_Mining", 250, 1, 50 }; // PROFESSION, REQUIRED LEVEL, INCREASE AMOUNT, CHANCE OF INCREASE
		gathered = "coal";
		gems[] = { {"nothing",0,85},{"uncut_diamond",85,100} };
		item = "pickaxe";
		zoneSize = 30;
	};

	class coral {
		text = "Mining for coral...";
		amount = 5;
		zones[] = { "coral_area" };
		profession[] = { "Prof_Mining", 500, 1, 50 }; // PROFESSION, REQUIRED LEVEL, INCREASE AMOUNT, CHANCE OF INCREASE
		gathered = "coral";
		gems[] = {};
		item = "pickaxe";
		zoneSize = 30;
	};

	class tin_ore {
		text = "Mining for tin...";
		amount = 5;
		zones[] = { "tin_area" };
		profession[] = { "Prof_Mining", 0, 1, 50 }; // PROFESSION, REQUIRED LEVEL, INCREASE AMOUNT, CHANCE OF INCREASE
		gathered = "tin_ore";
		gems[] = { {"nothing",0,45},{"uncut_opal",45,63},{"uncut_sapphire",63,78},{"uncut_ruby",78,90},{"uncut_emerald",90,97},{"uncut_diamond",97,100} };
		item = "pickaxe";
		zoneSize = 30;
	};

	class copper_ore {
		text = "Mining for copper...";
		amount = 5;
		zones[] = { "copper_area" };
		profession[] = { "Prof_Mining", 0, 1, 50 }; // PROFESSION, REQUIRED LEVEL, INCREASE AMOUNT, CHANCE OF INCREASE
		gathered = "copper_ore";
		gems[] = { {"nothing",0,45},{"uncut_opal",45,63},{"uncut_sapphire",63,78},{"uncut_ruby",78,90},{"uncut_emerald",90,97},{"uncut_diamond",97,100} };
		item = "pickaxe";
		zoneSize = 30;
	};

	class silver_ore {
		text = "Mining for silver...";
		amount = 5;
		zones[] = { "silver_area" };
		profession[] = { "Prof_Mining", 50, 1, 50 }; // PROFESSION, REQUIRED LEVEL, INCREASE AMOUNT, CHANCE OF INCREASE
		gathered = "silver_ore";
		gems[] = { {"nothing",0,45},{"uncut_opal",45,63},{"uncut_sapphire",63,78},{"uncut_ruby",78,90},{"uncut_emerald",90,97},{"uncut_diamond",97,100} };
		item = "pickaxe";
		zoneSize = 30;
	};

	class iron_ore {
		text = "Mining for iron...";
		amount = 5;
		zones[] = { "iron_area" };
		profession[] = { "Prof_Mining", 50, 1, 50 }; // PROFESSION, REQUIRED LEVEL, INCREASE AMOUNT, CHANCE OF INCREASE
		gathered = "iron_ore";
		gems[] = { {"nothing",0,45},{"uncut_opal",45,63},{"uncut_sapphire",63,78},{"uncut_ruby",78,90},{"uncut_emerald",90,97},{"uncut_diamond",97,100} };
		item = "pickaxe";
		zoneSize = 30;
	};

	class platinum_ore {
		text = "Mining for platinum...";
		amount = 5;
		zones[] = { "platinum_area" };
		profession[] = { "Prof_Mining", 100, 1, 50 }; // PROFESSION, REQUIRED LEVEL, INCREASE AMOUNT, CHANCE OF INCREASE
		gathered = "platinum_ore";
		gems[] = { {"nothing",0,45},{"uncut_opal",45,63},{"uncut_sapphire",63,78},{"uncut_ruby",78,90},{"uncut_emerald",90,97},{"uncut_diamond",97,100} };
		item = "pickaxe";
		zoneSize = 30;
	};

	class rock {
		text = "Mining for rock...";
		amount = 5;
		zones[] = { "rock_area" };
		profession[] = { "Prof_Mining", 100, 1, 50 }; // PROFESSION, REQUIRED LEVEL, INCREASE AMOUNT, CHANCE OF INCREASE
		gathered = "rock";
		gems[] = {};
		item = "pickaxe";
		zoneSize = 30;
	};

	class crude_oil {
		text = "Mining for oil...";
		amount = 5;
		zones[] = { "oil_rig" };
		profession[] = { "Prof_Mining", 250, 1, 50 }; // PROFESSION, REQUIRED LEVEL, INCREASE AMOUNT, CHANCE OF INCREASE
		gathered = "crude_oil";
		gems[] = { {"nothing",0,45},{"uncut_opal",45,63},{"uncut_sapphire",63,78},{"uncut_ruby",78,90},{"uncut_emerald",90,97},{"uncut_diamond",97,100} };
		item = "pickaxe";
		zoneSize = 30;
	};

	class iridium_ore {
		text = "Mining for iridium...";
		amount = 5;
		zones[] = { "iridium_ara" };
		profession[] = { "Prof_Mining", 500, 1, 50 }; // PROFESSION, REQUIRED LEVEL, INCREASE AMOUNT, CHANCE OF INCREASE
		gathered = "iridium_ore";
		gems[] = { {"nothing",0,45},{"uncut_opal",45,63},{"uncut_sapphire",63,78},{"uncut_ruby",78,90},{"uncut_emerald",90,97},{"uncut_diamond",97,100} };
		item = "pickaxe";
		zoneSize = 30;
	};
};