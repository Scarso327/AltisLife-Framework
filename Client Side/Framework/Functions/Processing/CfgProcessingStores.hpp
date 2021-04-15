class CfgProcessingStores {
	class Base {
		factions[] = { "Civilian" };
		condition = "true";
	};

	class Gold : Base {
		title = "Goldsmith";
		factions[] = { "Civilian", "Police" };
		processes[] = { "Gold" };
	};

	class Decrypter : Base {
		title = "Decrypter";
		factions[] = { "Civilian", "Police" };
		processes[] = { "Secrets" };
	};

	class PublicCookhouse : Base {
		title = "Public Cookhouse";
		processes[] = { "Salema", "Ornate", "Mackerel", "Tuna", "Mullet", "Catshark" };
	};

	class Schnapps : Base {
		title = "Schnapps Processing";
		processes[] = { "SchnapsApple", "SchnapsPeach" };
	};

	class Tobacco : Base {
		title = "Tobacco Processing";
		processes[] = { "Cigarette", "Cigar" };
	};

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

	class Uranium : Base {
		title = "Uranium Processing";
		processes[] = { "Uranium" };
	};

	class Diamond : Base {
		title = "Diamond Processing";
		processes[] = { "Diamond" };
	};

	class Salt : Base {
		title = "Salt Processing";
		processes[] = { "Salt" };
	};

	class Sand : Base {
		title = "Sand Processing";
		processes[] = { "Sand" };
	};

	class Oil : Base {
		title = "Oil Processing";
		processes[] = { "Oil" };
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

	class Moonshine : Base {
		title = "Moonshine Processing";
		processes[] = { "Moonshine" };
	};

	class Purifier : Base {
		title = "Drugs Purifier";
		processes[] = { "PurifiedWeed", "PurifiedHeroin", "PurifiedCocaine", "PurifiedMeth", "PurifiedMoonshine" };
		condition = "[""Northern""] call ULP_fnc_ownsCartel";
	};

	class MultiDrug : Base {
		title = "Multi-Drug Processing";
		processes[] = { "Weed", "Heroin", "Cocaine", "Meth", "Moonshine" };
	};
};