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
		class preInitVars { preInit=1; }
		class preInitEvents { preInit=1; };
	};

	class Events {
		file = "Functions\Events";
		class addEachFrame {};
		class onEachFrame {};
		class removeEachFrame {};
	};

	class Utility {
		file = "Functions\Utility";
		class waitExecute {};
		class waitUntilExecute {};
	};

	class Faction {
		file = "Functions\Faction";
		class setFaction {};
		class getFaction {};
		class isFaction {};
		class hasAccess {};
		class setLoadout {};
	};

	class Clothing {
		file = "Functions\Clothing";
		class setTextures {};
	};

	class Items {
		file = "Functions\Items";
		class itemCfg {};
		class addItems {};
	};

	class Player {
		file = "Functions\Player";
		class loadGear {};
		class saveGear {};
		class isRestrained {};
		class isSurrendered {};
		class keyDown {};
		class keyUp {};
		class initSurvival {};
		class initPlayerEvents {};
		class getInventory {};
		class resetSurvival {};
	};

	class PlayerActions {
		file = "Functions\Player\Actions";
		class surrender {};
		class toggleRestraint {};
	};

	class PlayerEvents {
		file = "Functions\Player\Events";
		class onRestrained {};
		class onUnrestrained {};
		class onIncapacitated {};
		class onKilled {};
		class onRespawn {};
		class onDamaged {};
		class onSurvival {};
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
		class openStore {};
		class switchInventory {};
		class switchCategory {};
		class addCart {};
		class removeCart {};
		class itemInfo {};
		class cartInfo {};
		class buyItems {};
		class sellItem {};
		class onItemClick {};
		class onTextureSwitch {};
	};

	class StoresItem {
		file = "Functions\Stores\Item";
		class onBuyItems {};
	};

	class StoresClothing {
		file = "Functions\Stores\Clothing";
		class onBuyClothes {};
	};
};

class ULP_Functions_UI {
	tag = "ULP_UI";

	class Functions {
		file = "UI\Functions";
		class screenCredits {};
		class closeDialogs {};
	};

	class RscLayers {
		file = "UI\RscLayers";
		class createLayer {};
		class destroyLayer {};
		class getLayer {};
	};
};