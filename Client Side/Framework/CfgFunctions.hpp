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
		class preInitVars { preInit=1; };
		class preInitEvents { preInit=1; };
	};

	class Events {
		file = "Functions\Events";
		class addEventHandler {};
		class invokeEvent {};
		class addEachFrame {};
		class onEachFrame {};
		class removeEachFrame {};
		class removeEventHandler {};
		class onPause {};
		class onRestrain {};
		class onIncapacitated {};
		class onKilled {};
		class onRespawn {};
		class onDamaged {};
		class onSurvival {};
		class onKnocked {};
		class onGetIn {};
		class onGetOut {};
		class onFired {};
		class onReloaded {};
	};

	class Utility {
		file = "Functions\Utility";
		class directCall {};
		class waitExecute {};
		class waitUntilExecute {};
		class stripString {};
	};

	class Faction {
		file = "Functions\Faction";
		class setFaction {};
		class getFaction {};
		class isFaction {};
		class hasAccess {};
		class setLoadout {};
		class factionPresistant {};
	};

	class Functions {
		file = "Functions\Functions";
		class getAnim {};
		class numberText {};
		class bool {};
		class switchMove {};
	};

	class Clothing {
		file = "Functions\Clothing";
		class setTextures {};
	};

	class Items {
		file = "Functions\Items";
		class itemCfg {};
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
		class handleGear {};
		class canFitGear {};
		class addContainer {};
		class setGear {};
		class addItems {};
		class stripGear {};
		class getInventory {};
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

	class TabletGroup {
		file = "Functions\Tablet\Group";
		class openGroup {};
	};

	class Selects {
		file = "Functions\Selects";
		class selectNumber {};
		class inputGroupInfo {};
	};

	class VirutalStores {
		file = "Functions\VirtualStore";
		class openVStore {};
		class updateVStore {};
		class vStoreChange {};
		class handleVItems {};
	};

	class Spawn {
		file = "Functions\Spawn";
		class spawnMenu {};
		class spawn {};
		class changeSpawn {};
	};

	class Vehicle {
		file = "Functions\Vehicle";
		class createVehicle {};
		class initVehicle {};
		class skinVehicle {};
		class vehicleCfg {};
		class vehicleSiren {};
		class vehicleLights {};
		class repairVehicle {};
	};

	class VehicleStore {
		file = "Functions\VehicleStore";
		class buyVehicle {};
		class vehicleStore {};
		class vehicleChange {};
		class switchTexture {};
	};

	class Map {
		file = "Functions\Map";
		class addMarket {};
		class addStore {};
	};
	
	class Garage {
		file = "Functions\Garage";
		class openGarage {};
		class storeVehicle {};
		class populateGarage {};
		class onGarageSwitch {};
		class retrieveGarage {};
	};

	class Interactions {
		file = "Functions\Interactions";
		class openInteractions {};
		class getInteractions {};
	};

	class Group {
		file = "Functions\Group";
		class joinGroup {};
		class inGroup {};
		class isGroup {};
		class getGroupById {};
		class getGroupName {};
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
		class blockEsc {};
		class setMapPosition {};
		class inputLimit {};
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

	class RscHUD {
		file = "Functions\HUD";
		class openHUD {};
		class closeHUD {};
		class eachFrameHUD {};
		class isHudShown {};
	};
};