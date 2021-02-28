class CfgProcessing {
	class BaseProcess {
		processTime = 60;
		factions[] = { "Civilian", "Police" };
		reqItems[] = {};
		reqLicenses[] = {};
	};

	// Skinning
	class Rabbit : BaseProcess {
		processTitle = "Skinning";
		processTime = 40;
		materials[] = { { "rawRabbit", 1 } };
		items[] = { { "skinnedRabbit", 1 } };
	};

	class Goat : BaseProcess {
		processTitle = "Skinning";
		processTime = 40;
		materials[] = { { "rawLamb", 1 } };
		items[] = { { "skinnedLamb", 1 } };
	};

	// Cooking
	class Salema : BaseProcess {
		processTitle = "Cooking";
		processTime = 30;
		materials[] = { { "rawSalema", 1 } };
		items[] = { { "cookedSalema", 1 } };
	};

	class Ornate : BaseProcess {
		processTitle = "Cooking";
		processTime = 30;
		materials[] = { { "rawOrnate", 1 } };
		items[] = { { "cookedOrnate", 1 } };
	};

	class Tuna : BaseProcess {
		processTitle = "Cooking";
		processTime = 35;
		materials[] = { { "rawTuna", 1 } };
		items[] = { { "cookedTuna", 1 } };
	};

	class Mullet : BaseProcess {
		processTitle = "Cooking";
		processTime = 35;
		materials[] = { { "rawMullet", 1 } };
		items[] = { { "cookedMullet", 1 } };
	};

	class Catshark : BaseProcess {
		processTime = 40;
		processTitle = "Cooking";
		materials[] = { { "rawCatshark", 1 } };
		items[] = { { "cookedCatshark", 1 } };
	};

	class Turtle : BaseProcess {
		processTitle = "Cooking";
		materials[] = { { "rawTurtle", 1 } };
		items[] = { { "cookedTurtle", 1 } };
	};

	// Smelting
	class Copper : BaseProcess {
		processTitle = "Smelting";
		materials[] = { { "copperOre", 1 } };
		items[] = { { "copperBar", 1 } };
		reqLicenses[] = {};
	};

	class Iron : BaseProcess {
		processTitle = "Smelting";
		materials[] = { { "ironOre", 1 } };
		items[] = { { "ironBar", 1 } };
		reqLicenses[] = {};
	};

	class Sand : BaseProcess {
		processTitle = "Smelting";
		materials[] = { { "sand", 1 } };
		items[] = { { "glass", 1 } };
		reqLicenses[] = {};
	};

	// Refining
	class Salt : BaseProcess {
		processTitle = "Refining";
		materials[] = { { "unrefinedSalt", 1 } };
		items[] = { { "refindedSalt", 1 } };
		reqLicenses[] = {};
	};

	// Cutting
	class Diamond : BaseProcess {
		processTitle = "Cutting";
		materials[] = { { "uncutDiamond", 1 } };
		items[] = { { "cutDiamond", 1 } };
		reqLicenses[] = {};
	};

	class Emerald : BaseProcess {
		processTitle = "Cutting";
		materials[] = { { "uncutEmerald", 1 } };
		items[] = { { "cutDiamond", 1 } };
		reqLicenses[] = {};
	};

	// Processing
	class Schnaps : BaseProcess {
		processTitle = "Processing";
		processTime = 40;
		materials[] = { { "peach", 2 } };
		items[] = { { "schnaps", 1 } };
		reqLicenses[] = {};
	};

	class Cigarette : BaseProcess {
		processTitle = "Processing";
		materials[] = { { "tobacco", 2 } };
		items[] = { { "cigarette", 1 } };
		reqLicenses[] = {};
	};

	class Cigar : BaseProcess {
		processTitle = "Processing";
		processTime = 70;
		materials[] = { { "tobacco", 2 } };
		items[] = { { "cigar", 1 } };
		reqLicenses[] = {};
	};

	class Weed : BaseProcess {
		processTitle = "Processing";
		materials[] = { { "unprocessedWeed", 1 } };
		items[] = { { "processedWeed", 1 } };
		reqLicenses[] = {};
	};

	class Heroin : BaseProcess {
		processTitle = "Processing";
		processTime = 70;
		materials[] = { { "unprocessedHeroin", 1 } };
		items[] = { { "processedHeroin", 1 } };
		reqLicenses[] = {};
	};

	class Cocaine : BaseProcess {
		processTitle = "Processing";
		processTime = 80;
		materials[] = { { "unprocessedCocaine", 1 } };
		items[] = { { "processedCocaine", 1 } };
		reqLicenses[] = {};
	};

	class Methamphetamine : BaseProcess {
		processTitle = "Processing";
		processTime = 90;
		materials[] = { { "unprocessedMeth", 1 } };
		items[] = { { "processedMeth", 1 } };
		reqLicenses[] = {};
	};

	class Uranium : BaseProcess {
		processTitle = "Processing";
		processTime = 90;
		materials[] = { { "uraniumOre", 1 } };
		items[] = { { "uraniumBar", 1 } };
		reqLicenses[] = {};
	};

	class Gold : BaseProcess {
		processTitle = "Processing";
		processTime = 120;
		materials[] = { { "unmarkedGold", 1 } };
		items[] = { { "markedGold", 1 } };
	};
};