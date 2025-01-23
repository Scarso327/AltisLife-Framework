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
			class onAction {};
			class onNextAction {};
			class onPrevAction {};
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
			class onPut {};
			class onEnterRadiatedZone {};
			class onLeftRadiatedZone {};
			class InventoryOpened {};
			class InventoryClosed {};
		};

		class Utility {
			file = "Functions\Utility";
			class directCall {};
			class waitExecute {};
			class waitUntilExecute {};
			class stripString {};
			class inString {};
			class isKindOf {};
			class execNextFrame {};
		};

		class Faction {
			file = "Functions\Faction";
			class setFaction {};
			class getFaction {};
			class isFaction {};
			class hasAccess {};
			class setLoadout {};
			class factionPresistant {};
			class factionFree {};
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
		};

		class Clothing {
			file = "Functions\Clothing";
			class setTextures {};
			class applyTextures {};
			class isGas {};
			class isMask {};
			class isNightVision {};
			class preInitClothing { preInit=1; }
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
			class drill {};
			class blindfold {};
			class fuelCan {};
			class spikeStrip {};
			class triggerEvent {};
			class dropFishingNet {};
		};

		class Input {
			file = "Functions\Input";
			class keyDown {};
			class keyUp {};
			class actionKeyDown {};
			class isInputBlocked {};
		};

		class Player {
			file = "Functions\Player";
			class canFire {};
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
			class isGovernor {};
			class canHeal {};
			class setOverweight {};
			class hasComms {};
		};

		class PlayerActions {
			file = "Functions\Player\Actions";
			class knockOut {};
			class surrender {};
			class restrain {};
			class escort {};
			class seizeComms {};
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
			class switchCategory {};
			class addCart {};
			class removeCart {};
			class itemInfo {};
			class cartInfo {};
			class buyItems {};
			class onItemClick {};
			class onTextureSwitch {};
			class saveCart {};
			class newSavedCart {};
			class deleteSavedCart {};
			class loadSavedCart {};
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
			class seizeLicense {};
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
			class maxCarry {};
			class giveItem {};
			class recieveItem {};
			class giveVirtualItems {};
			class repackAmmo {};
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
			class virtualInventory {};
			class licenses {};
			class crafting {};
			class bpLbChange {};
			class invLbChange {};
			class removeItem {};
			class useItem {};
			class craft {};
		};

		class TabletGroup {
			file = "Functions\Tablet\Group";
			class openGroup {};
			class group {};
			class overview {};
			class changeRank {};
			class inviteMember {};
			class kickMember {};
			class leaveGroup {};
			class transferOwner {};
			class progression {};
			class settings {};
			class changeTax {};
		};

		class TabletKeys {
			file = "Functions\Tablet\Key";
			class keys {};
			class switchHouse {};
			class switchVehicle {};
			class shareKeys {};
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

		class TabletCommunityGoals {
			file = "Functions\Tablet\CommunityGoals";
			class communityGoals {};
		};

		class Options {
			file = "Functions\Options";
			class setOption {};
			class getOption {};
			class resetOption {};
			class getDefaultOption {};
			class setViewDistance {};
		};

		class Selects {
			file = "Functions\Selects";
			class selectNumber {};
			class inputGroupInfo {};
			class inputWarrantInfo {};
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
			class clampVehicle {};
			class lockpickVehicle {};
			class initVehicle {};
			class skinVehicle {};
			class vehicleCfg {};
			class vehicleSiren {};
			class vehicleLights {};
			class giveVehicleKeys {};
			class ejectVehicleCrew {};
			class ejectVehicleUnit {};
			class putVehicleUnit {};
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
			class spikeVehicle {};
			class flipVehicle {};
			class isVehicleStationary {};
			class removeVehicleClamp {};
			class hasTyreDamage {};
		};

		class VehicleEvents {
			file = "Functions\Vehicle\Events";
			class onVehicleDeleted {};
			class onVehicleKilled {};
			class onVehicleEngine {};
		};

		class VehicleStore {
			file = "Functions\VehicleStore";
			class buyVehicle {};
			class vehicleStore {};
			class vehicleChange {};
			class switchTexture {};
		};

		class Mail {
			file = "Functions\Mail";
			class openMailBox {};
			class claimMail {};
		}

		class Map {
			file = "Functions\Map";
			class createSimpleObject {};
			class addMarket {};
			class addStore {};
			class addGarage {};
			class addGarageStore {};
			class addVehicleStore {};
			class addLicenseStore {};
			class addProcessing {};
			class addRobAction {};
			class addBank {};
			class addMission {};
			class addPollingStation {};
			class addMailBox {};
			class addFreightMission {};
			class initBriefing {};
			class isATM {};
			class lockForFactions {};
			class sit {};
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
			class groupTag {};
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
			class setGroupOwner {};
			class removeMember {};
			class groupXP {};
			class groupLevel {};
			class hasGroupPerk {};
			class groupBuff {};
			class isSecurity {};
			class isGroupOwner {};
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
			class dropMoney {};
			class pickupMoney {};
			class giveMoney {};
			class sendMoney {};
			class recieveMoney {};
			class robMoney {};
			class checkMoney {};
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
			class wipeItemFromCargo {};
		};

		class Goals {
			file = "Functions\Goals";
			class initPersonalGoals {};
			class handlePersonalGoals {};
			class savePersonalGoals {};
			class rewardPersonalGoal {};
			class initCommunityGoals {};
			class getCommunityGoalPayout {};
		};

		class Rewards {
			file = "Functions\Rewards";
			class grantReward {};
			class grantTexture {};
		};

		class Chat {
			file = "Functions\Chat";
			class chatMessage {};
			class initChat {};
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
			class openMedical {};
			class setLimb {};
			class applyBandage {};
			class revivePatient {};
			class revived {};
			class nearestStretcher {};
			class toggleOnStretcher {};
		};

		class MedicMap {
			file = "Functions\MedicMap";
			class openMedicMap {};
		};

		class Housing {
			file = "Functions\Housing";
			class setupHouses {};
			class isHouse {};
			class isHouseOwner {};
			class isHouseShared {};
			class isHouseOwned {};
			class isHouseStorage {};
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
			class preInitRandomEvents { preInit=1; };
		};

		class Cartels {
			file = "Functions\Cartels";
			class initCartels {};
			class cartelHud {};
			class ownsCartel {};
			class onPopupCartelSpawn {}
		};

		class Perks {
			file = "Functions\Perks";
			class hasPerk {};
			class getPerkLevel {};
			class activatePerk {};
			class getPerkBonus {};
			class getPerkRequirement {};
			class getPerkXPRequirement {};
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
			class placeBid {};
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

		class PNC {
			file = "Functions\PNC";
			class openPNC {};
			class listWarrants {};
			class listCrimes {};
			class clearWarrants {};
			class deleteCrime {};
			class issueWarrant {};
		};

		class Crimes {
			file = "Functions\Crimes";
			class triggerStage {};
		};

		class Crafting {
			file = "Functions\Crafting";
			class hasBlueprint {};
			class unlockBlueprint {};
			class deconstruct {};
			class nearWorkbench {};
		};

		class Capture {
			file = "Functions\Capture";
			class capture {};
			class ownsSite {};
		};

		class Government {
			file = "Functions\Government";
			class setLegislation {};
			class getLegislation {};
			class openLegislation {};
			class taxPrice {};
			class enlist {};
			class isProtection {};
			class openPollingStation {};
			class vote {};
			class rigPollingStation {};
		};
		
		class Hints {
			file = "Functions\Hints";
			class clearHints {};
			class hint {};
			class hintEachFrame {};
		};

		class Markers {
			file = "Functions\Markers";
			class initMarkers {};
			class mapMarkers {};
		};

		class Police {
			file = "Functions\Police";
			class initPolice {};
			class issueTicket {};
		};

		class CorporateFreight {
			file = "Functions\Freight";
			class claimFreight {};
			class finishFreight {};
			class onEachFrameFreight {};
		};

		class Shipwreck {
			file = "Functions\Shipwreck";
			class onShipwreckSpawn {};
		};

		class Placeables {
			file = "Functions\Placeables";
			class dragPlaceable {};
			class placedObjects {};
			class placeObject {};
			class releasePlaceable {};
			class removeObject {};
			class stopPlacement {};
			class isPlaceable {};
			class isDragging {};
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
			class setToTextHeight {};
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
		};

		class RscHUD_UI {
			file = "UI\RscHUD\Functions";
			class onHudLoad {};
			class onHudUnload {};
			class eachFrameHUD {};
			class onXPUpdateHud {};
			class isHudShown {};
			class zoneText {};
		};

		class RscIncapacitated {
			file = "UI\RscIncapacitated\Functions";
			class RscIncapacitated_OnEachFrame {};
			class RscIncapacitated_OnLoad {};
			class RscIncapacitated_OnUnload {};
		};

		class DialogMedicMap {
			file = "UI\DialogMedicMap\Functions";
			class DialogMedicMap_OnLoad {};
			class DialogMedicMap_OnUnload {};
			class DialogMedicMap_OnMapDraw {};
			class DialogMedicMap_LoadList {};
			class DialogMedicMap_SetAssignedMedic {};
			class DialogMedicMap_OnListChanged {};
		};
	};
};