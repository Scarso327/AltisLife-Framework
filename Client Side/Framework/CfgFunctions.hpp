class ULP_Functions {
	tag = "ULP";

	class General {
		file = "Functions\General";
		class logIt {};
	};

	class Initalisation {
		file = "Functions\Initialisation";
		class initialisation {};
		class initEventHandlers {};
		class initVars {};
	};

	class Faction {
		file = "Functions\Faction";
		class setFaction {};
		class getFaction {};
		class isFaction {};
		class hasAccess {};
	};

	class Clothing {
		file = "Functions\Clothing";
		class setTextures {};
	};

	class Items {
		file = "Functions\Items";
		class itemCfg {};
	};

	class Player {
		file = "Functions\Player";
		class loadGear {};
		class saveGear {};
		class keyDown {};
		class keyUp {};
		class initPlayerEvents {};
		class getInventory {};
	};

	class PlayerEvents {
		file = "Functions\Player\Events";
		class onIncapacitated {};
		class onKilled {};
		class onRespawn {};
		class onDamaged {};
	};

	class Paycheck {
		file = "Functions\Paycheck";
		class calcPaycheck {};
	};

	class Database {
		file = "Functions\Database";
		class sync {};
	};

	class DatabasePlayer {
		file = "Functions\Database\Player";
		class getPlayerInfo {};
		class setPlayerInfo {};
		class syncPlayerInfo {};
	};

	class Effects {
		file = "Functions\Effects";
		class createEffect {};
		class destroyEffect {};
		class wipeEffects {};
	};

	class Stores {
		file = "Functions\Stores";
		class addCart {};
		class removeCart {};
		class itemInfo {};
		class cartInfo {};
		class switchInventory {};
		class sellItem {};
	};
};

class ULP_Functions_UI {
	tag = "ULP_UI";

	class Functions {
		file = "UI\Functions";
		class closeDialogs {};
	};

	class RscLayers {
		file = "UI\RscLayers";
		class createLayer {};
		class destroyLayer {};
		class getLayer {};
	};
};