class CfgProcessing {
	class BaseProcess {
		processTime = 60;
		factions[] = { "Civilian", "Police" };
		reqItems[] = {};
		reqLicenses[] = {};
	};

	// Skinning
	class Skinning : BaseProcess {
		processTitle = "Skinning";
		processTime = 40;
		reqItems[] = { { "cuttingKnife", 1 } };
	};

	class Rabbit : Skinning {
		materials[] = { { "rawRabbit", 1 } };
		items[] = { { "skinnedRabbit", 1 } };
	};

	class Goat : Skinning {
		materials[] = { { "rawLamb", 1 } };
		items[] = { { "skinnedLamb", 1 } };
	};

	// Cooking
	class Cooking : BaseProcess {
		processTitle = "Cooking";
		processTime = 30;
	};

	class Salema : Cooking {
		materials[] = { { "rawSalema", 1 } };
		items[] = { { "cookedSalema", 1 } };
	};

	class Ornate : Cooking {
		materials[] = { { "rawOrnate", 1 } };
		items[] = { { "cookedOrnate", 1 } };
	};

	class Tuna : Cooking {
		materials[] = { { "rawTuna", 1 } };
		items[] = { { "cookedTuna", 1 } };
	};

	class Mullet : Cooking {
		materials[] = { { "rawMullet", 1 } };
		items[] = { { "cookedMullet", 1 } };
	};

	class Catshark : Cooking {
		materials[] = { { "rawCatshark", 1 } };
		items[] = { { "cookedCatshark", 1 } };
	};

	class Turtle : Cooking {
		materials[] = { { "rawTurtle", 1 } };
		items[] = { { "cookedTurtle", 1 } };
	};

	// Smelting
	class Smelting : BaseProcess { processTitle = "Smelting"; };

	class Copper : Smelting {
		materials[] = { { "copperOre", 1 } };
		items[] = { { "copperBar", 1 } };
		reqLicenses[] = {};
	};

	class Iron : Smelting {
		materials[] = { { "ironOre", 1 } };
		items[] = { { "ironBar", 1 } };
		reqLicenses[] = {};
	};

	class Sand : Smelting {
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
	class Processing : BaseProcess { processTitle = "Processing"; };

	class Schnaps : BaseProcess {
		processTime = 40;
		materials[] = { { "peach", 2 } };
		items[] = { { "schnaps", 1 } };
		reqLicenses[] = {};
	};

	class Cigarette : BaseProcess {
		materials[] = { { "tobacco", 2 } };
		items[] = { { "cigarette", 1 } };
		reqLicenses[] = {};
	};

	class Cigar : BaseProcess {
		processTime = 70;
		materials[] = { { "tobacco", 2 } };
		items[] = { { "cigar", 1 } };
		reqLicenses[] = {};
	};

	class Weed : BaseProcess {
		materials[] = { { "unprocessedWeed", 1 } };
		items[] = { { "processedWeed", 1 } };
		reqLicenses[] = {};
	};

	class Heroin : BaseProcess {
		processTime = 70;
		materials[] = { { "unprocessedHeroin", 1 } };
		items[] = { { "processedHeroin", 1 } };
		reqLicenses[] = {};
	};

	class Cocaine : BaseProcess {
		processTime = 80;
		materials[] = { { "unprocessedCocaine", 1 } };
		items[] = { { "processedCocaine", 1 } };
		reqLicenses[] = {};
	};

	class Methamphetamine : BaseProcess {
		processTime = 90;
		materials[] = { { "unprocessedMeth", 1 } };
		items[] = { { "processedMeth", 1 } };
		reqLicenses[] = {};
	};

	class Uranium : BaseProcess {
		processTime = 90;
		materials[] = { { "uraniumOre", 1 } };
		items[] = { { "uraniumBar", 1 } };
		reqLicenses[] = {};
	};

	class Gold : BaseProcess {
		processTime = 120;
		materials[] = { { "unmarkedGold", 1 } };
		items[] = { { "markedGold", 1 } };
	};
};