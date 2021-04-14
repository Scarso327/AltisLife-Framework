class CfgFunctions {
	class ULP_Functions {
		tag = "ULP";

		class Admin {
			file = "Functions\Admin";
			class isStaff {};
			class adminCamera {};
			class onDuty {};
			class toggleAdminGear {};
			class inCamera {};
			class checkPower {};
		};

		class Airdrop {
			file = "Functions\Airdrop";
			class onAirdropSpawn {};
		};

		class Achievements {
			file = "Functions\Achievements";
			class achieve {};
			class hasAchieved {};
			class initAchievements {};
		};
		
		class General {
			file = "Functions\General";
			class logIt {};
		};

		class Initalisation {
			file = "Functions\Initialisation";
			class initPlayer {};
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
			class onTake {};
		};

		class Utility {
			file = "Functions\Utility";
			class directCall {};
			class waitExecute {};
			class waitUntilExecute {};
			class stripString {};
			class inString {};
		};

		class Faction {
			file = "Functions\Faction";
			class setFaction {};
			class getFaction {};
			class isFaction {};
			class hasAccess {};
			class setLoadout {};
			class factionPresistant {};
			class allMembers {};
			class onlineFaction {};
			class canResetLoadout {};
		};

		class Functions {
			file = "Functions\Functions";
			class getAnim {};
			class numberText {};
			class bool {};
			class switchMove {};
			class threatLevel {};
			class lock {};
			class say3D {};
			class setFuel {};
			class getBuildingDoors {};
			class getNearestDoor {};
			class isUnitsInZone {};
			class unitsInZone {};
			class forgeIdentity {};
			class metalDetector {};
			class hint {};
		};

		class Clothing {
			file = "Functions\Clothing";
			class setTextures {};
			class isGas {};
			class isMask {};
		};

		class Items {
			file = "Functions\Items";
			class itemCfg {};
			class getSellPrices {};
		};

		class ItemScripts {
			file = "Functions\Items\Scripts";
			class addSustenance {};
			class disguiseIdentity {};
			class panic {};
			class healAction {};
			class boltcut {};
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
			class isEscorted {};
			class isEscorting {};
			class isKnocked {};
			class initSurvival {};
			class initPlayerEvents {};
			class resetSurvival {};
			class canRestrain {};
			class getName {};
			class playerByUID {};
			class isUndercover {};
			class canHeal {};
		};

		class PlayerActions {
			file = "Functions\Player\Actions";
			class knockOut {};
			class surrender {};
			class restrain {};
			class escort {};
		};

		class Paycheck {
			file = "Functions\Paycheck";
			class calcPaycheck {};
		};

		class Processing {
			file = "Functions\Processing";
			class process {};	
			class listProcesses {};
			class openProcessing {};
			class selectProcess {};	
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
			class getTagPos {};
			class initTags {};
		};

		class Licenses {
			file = "Functions\Licenses";
			class addLicense {};
			class hasLicense {};
			class listLicenses {};
			class openLicenses {};
			class onLicenseSwitch {};
			class buyLicense {};
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
			class setCfgLoadout {};
			class compatibleItems {};
		};
		
		class Gathering {
			file = "Functions\Gathering";
			class gather {};
			class getGatherZone {};
			class catchFish {};
			class initGathering {};
		};

		class Tablet {
			file = "Functions\Tablet";
			class openTablet {};
			class setScreen {};
			class rebindEsc {};
		};

		class TabletMarket {
			file = "Functions\Tablet\Market";
			class market {};
		};

		class TabletInventory {
			file = "Functions\Tablet\Inventory";
			class inventory {};
			class invLbChange {};
			class removeItem {};
			class useItem {};
		};

		class TabletGroup {
			file = "Functions\Tablet\Group";
			class openGroup {};
			class group {};
			class overview {};
			class changeRank {};
		};

		class TabletKeys {
			file = "Functions\Tablet\Key";
			class keys {};
			class switchHouse {};
		};
		
		class TabletOptions {
			file = "Functions\Tablet\Options";
			class options {};
		};

		class TabletDispute {
			file = "Functions\Tablet\Dispute";
			class dispute {};
		};

		class TabletMessaging {
			file = "Functions\Tablet\Messaging";
			class messages {};
			class sendByType {};
			class sendMessage {};
			class inbox {};
			class replyMessage {};
			class deleteMessage {};
		};

		class TabletProfile {
			file = "Functions\Tablet\Profile";
			class profile {};
			class professions {};
			class achievements {};
			class personalGoals {};
			class nameTags {};
			class updateTagPreview {};
			class getTagRGB {};
			class resetTagRGB {};
		};

		class TabletPerks {
			file = "Functions\Tablet\Perks";
			class perks {};
		};

		class Options {
			file = "Functions\Options";
			class setOption {};
			class getOption {};
			class resetOption {};
			class getDefaultOption {};
		};

		class Selects {
			file = "Functions\Selects";
			class selectNumber {};
			class inputGroupInfo {};
			class selectPlayer {};
			class confirm {};
			class enterString {};
			class selectObject {};
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
			class chopVehicle {};
			class createVehicle {};
			class initVehicle {};
			class skinVehicle {};
			class vehicleCfg {};
			class vehicleSiren {};
			class vehicleLights {};
			class giveVehicleKeys {};
			class ejectVehicleCrew {};
			class ejectVehicleUnit {};
			class repairVehicle {};
			class garageVehicle {};
			class serviceVehicle {};
			class crushVehicle {};
			class impoundVehicle {};
			class setVehicleAmmo {};
			class isVehicleOwner {};
			class getVehicleOwner {};
			class vehicleRegistration {};
			class clearCargo {};
			class unlockTexture {};
			class isTextureUnlocked {};
			class vehRemoteGate {};
			class canANPR {};
		};

		class VehicleEvents {
			file = "Functions\Vehicle\Events";
			class onVehicleDeleted {};
			class onVehicleKilled {};
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
			class createSimpleObject {};
			class addMarket {};
			class addStore {};
			class addGarage {};
			class addVehicleStore {};
			class addLicenseStore {};
			class addProcessing {};
			class addRobAction {};
			class addBank {};
			class addMission {};
			class isATM {};
			class lockForFactions {};
		};
		
		class Garage {
			file = "Functions\Garage";
			class openGarage {};
			class storeVehicle {};
			class populateGarage {};
			class onGarageSwitch {};
			class retrieveGarage {};
			class destroyGarage {};
			class transferGarage {};
		};

		class Interactions {
			file = "Functions\Interactions";
			class openInteractions {};
			class getInteractions {};
		};

		class Group {
			file = "Functions\Group";
			class initGroups {};
			class joinGroup {};
			class inGroup {};
			class isGroup {};
			class getGroupById {};
			class getGroupName {};
			class getGroupRank {};
			class setGroupRank {};
			class groupId {};
			class groupFunds {};
			class groupPermissions {};
			class groupRanks {};
			class isGroupPremium {};
			class rankName {};
			class canGroupRank {};
			class groupMembers {};
			class isGroupMember {};
			class disbandGroup {};
			class groupTax {};
		};

		class NLR {
			file = "Functions\NLR";
			class addNLR {};
			class addNLREachFrame {};
		};

		class Professions {
			file = "Functions\Professions";
			class increaseProfession {};
			class getProfessionCalculation {};
			class getProfessionLevel {};
		};

		class Leveling {
			file = "Functions\Leveling";
			class addXP {};
			class getMaxLevel {};
			class getRequiredXP {};
			class canPrestige {};
			class prestige {};
		};
		
		class Money {
			file = "Functions\Money";
			class addMoney {};
			class removeMoney {};
			class openBank {};
			class switchBank {};
			class logTransaction {};
			class withdrawMoney {};
			class depositMoney {};
		};

		class Robberies {
			file = "Functions\Robberies";
			class robObject {};
		};
		
		class Variables {
			file = "Functions\Variables";
			class constant {};
		};

		class Prison {
			file = "Functions\Prison";
			class canImprison {};
			class canImprisoned {};
			class imprison {};
			class release {};
			class setPrisonTIme {};
		};

		class VirtualInventory {
			file = "Functions\VirtualInventory";
			class addToCargo {};
			class removeFromCargo {};
			class currentLoad {};
			class maxLoad {};
			class hasInventory {};
			class openInventory {};
			class updateInventory {};
			class takeFromCargo {};
			class putInCargo {};
			class isCargoUser {};
		};

		class Goals {
			file = "Functions\Goals";
			class initPersonalGoals {};
			class handleGoal {};
			class increaseGoal {};
			class saveGoals {};
			class rewardTier {};
		};

		class Rewards {
			file = "Functions\Rewards";
			class grantReward {};
			class grantTexture {};
		};

		class Chat {
			file = "Functions\Chat";
			class chatMessage {};
		};

		class Messaging {
			file = "Functions\Messaging";
			class receiveMessage {};
		};

		class Medical {
			file = "Functions\Medical";
			class createBodyBag {};
			class administerBlood {};
			class receivedBlood {};
		};

		class Housing {
			file = "Functions\Housing";
			class setupHouses {};
			class isHouse {};
			class isHouseOwner {};
			class isHouseShared {};
			class isHouseOwned {};
			class ownedHouses {};
			class buyHouse {};
			class sellHouse {};
			class shareHouse {};
			class renameHouse {};
		};

		class Missions {
			file = "Functions\Missions";
			class claimMission {};
			class finishMission {};
			class initMissions {};
		};

		class Titles {
			file = "Functions\Titles";
			class hasTitle {};
			class unlockTitle {};
		};

		class RandomEvents {
			file = "Functions\RandomEvents";
			class initRandomEvents {};
		};

		class Cartels {
			file = "Functions\Cartels";
			class initCartels {};
			class cartelHud {};
			class ownsCartel {};
		};

		class Perks {
			file = "Functions\Perks";
			class hasPerk {};
			class getPerkLevel {};
			class activatePerk {};
			class getPerkBonus {};
			class getPerkRequirement {};
			class getPerkLimit {};
			class togglePerk {};
			class addPerkXP {};
			class initPerks {};
		};

		class Reputation {
			file = "Functions\Reputation";
			class initReputation {};
			class reputationPrice {};
		};

		class Bases {
			file = "Functions\Bases";
			class ownsBase {};
			class initBases {};
		};

		class Donator {
			file = "Functions\Donator";
			class donatorLevel {};	
		};

		class Indicators {
			file = "Functions\Indicators";
			class groupIndicators {};
			class getIndicatorColour {};
		};
		
		class Archaeology {
			file = "Functions\Archaeology";
			class getSite {};
			class surveySite {};
			class digSite {};
		};

		class Moves {
			file = "Functions\Moves";
			class movesMenu {};
		};

		class Camera {
			file = "Functions\Camera";
			class handleCamera {};
			class addCameras {};
		};

		class LootTable {
			file = "Functions\LootTable";
			class getLoot {};
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
			class placeholder {};
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
			class updateXpHud {};
		};
	};
};