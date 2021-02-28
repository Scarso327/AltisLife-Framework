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
		class onPause {};
		class onRestrain {};
		class onIncapacitated {};
		class onKilled {};
		class onRespawn {};
		class onDamaged {};
		class onSurvival {};
		class onKnocked {};
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

	class Functions {
		file = "Functions\Functions";
		class getAnim {};
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

	class Input {
		file = "Functions\Input";
		class keyDown {};
		class keyUp {};
		class actionKeyDown {};
	};

	class Player {
		file = "Functions\Player";
		class loadGear {};
		class saveGear {};
		class isRestrained {};
		class isSurrendered {};
		class isKnocked {};
		class initSurvival {};
		class initPlayerEvents {};
		class getInventory {};
		class resetSurvival {};
		class canRestrain {};
		class getName {};
	};

	class PlayerActions {
		file = "Functions\Player\Actions";
		class knockOut {};
		class surrender {};
		class restrain {};
	};

	class Paycheck {
		file = "Functions\Paycheck";
		class calcPaycheck {};
	};

	class Processing {
		file = "Functions\Processing";
		class process {};		
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

	class Tags {
		file = "Functions\PlayerTags";
		class playerTags {};
		class setTags {};
		class getTagColour {};
	};

	class Licenses {
		file = "Functions\Licenses";
		class addLicense {};
		class hasLicense {};
	};

	class Inventory {
		file = "Functions\Inventory";
		class handleItem {};
		class hasItem {};	
		class getMaxQuantity {};
	};
	
	class Gathering {
		file = "Functions\Gathering";
		class gather {};
		class getGatherZone {};
	};

	class Tablet {
		file = "Functions\Tablet";
		class openTablet {};
		class setScreen {};
		class rebindEsc {};
	};

	class TabletInventory {
		file = "Functions\Tablet\Inventory";
		class inventory {};
		class invLbChange {};
		class removeItem {};
	};

	class Selects {
		file = "Functions\Selects";
		class selectNumber {};
	};

	class VirutalStores {
		file = "Functions\VirtualStore";
		class openVStore {};
		class updateVStore {};
		class vStoreChange {};
		class handleVItems {};
	};
};

class ULP_Functions_UI {
	tag = "ULP_UI";

	class Functions {
		file = "UI\Functions";
		class screenCredits {};
		class closeDialogs {};
		class setVAlignText {};
		class setSyncButton {};
	};

	class RscLayers {
		file = "UI\RscLayers";
		class createLayer {};
		class destroyLayer {};
		class getLayer {};
	};
	
	class RscProgress {
		file = "Functions\Progress";
		class isProgress {};
		class startProgress {};
		class eachFrameProgress {};
		class endProgress {};
	};
};