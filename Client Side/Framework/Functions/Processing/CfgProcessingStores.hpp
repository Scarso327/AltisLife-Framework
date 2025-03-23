class CfgProcessingStores {
	class Base {
		factions[] = { "Civilian", "Dunamis" };
		condition = "true";
	};

	// Fishing
	class PublicCookhouse : Base {
		title = "Public Cookhouse";
		processes[] = { "Salema", "Ornate", "Mackerel", "Tuna", "Mullet", "Catshark" };
	};

	// Gathering
	class Schnapps : Base {
		title = "Schnapps Processing";
		processes[] = { "SchnapsApple", "SchnapsPeach" };
	};
	class Tobacco : Base {
		title = "Tobacco Processing";
		processes[] = { "Cigarette", "Cigar" };
	};
	class Weed : Base {
		title = "Weed Processing";
		processes[] = { "Weed" };
	};
	class Heroin : Base {
		title = "Heroin Processing";
		processes[] = { "Heroin" };
	};
	class Cocaine : Base {
		title = "Cocaine Processing";
		processes[] = { "Cocaine" };
	};
	class Meth : Base {
		title = "Meth Processing";
		processes[] = { "Meth" };
	};
	class MultiDrug : Base {
		title = "Multi-Drug Processing";
		processes[] = { "Weed", "Heroin", "Cocaine", "Meth" };
	};
	class Purifier : Base {
		title = "Drugs Purifier";
		processes[] = { "PurifiedWeed", "PurifiedHeroin", "PurifiedCocaine", "PurifiedMeth" };
		condition = "[""Northern""] call ULP_fnc_ownsCartel";
	};

	// Mining
	class Copper : Base {
		title = "Copper Processing";
		processes[] = { "Copper" };
	};
	class Silver : Base {
		title = "Silver Processing";
		processes[] = { "Silver" };
	};
	class Iron : Base {
		title = "Iron Processing";
		processes[] = { "Iron" };
	};
	class Oil : Base {
		title = "Oil Processing";
		processes[] = { "Oil" };
	};
	class Sand : Base {
		title = "Sand Processing";
		processes[] = { "Sand" };
	};
	class Salt : Base {
		title = "Salt Processing";
		processes[] = { "Salt" };
	};
	class Diamond : Base {
		title = "Diamond Processing";
		processes[] = { "Diamond" };
	};
	class Uranium : Base {
		title = "Uranium Processing";
		processes[] = { "Uranium" };
	};
	
	// Majors
	class Gold : Base {
		title = "Goldsmith";
		processes[] = { "Gold" };
	};
	class Secrets : Base {
		title = "Decrypter";
		processes[] = { "Secrets" };
	};

	// Weapons
	class Weapons : Base {
		title = "Weapons Processing";
		processes[] = { "Weapons" };
	};
};