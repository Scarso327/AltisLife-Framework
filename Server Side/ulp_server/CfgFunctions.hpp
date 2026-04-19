class CfgFunctions {

    class Functions {
        tag = "ULP_SRV";

		class Root {
			file = "\ulp_server";
			class init {};
		};

        class Airdrop {
            file = "\ulp_server\Functions\Airdrop";
            class claimAirdrop {};
        };

        class DatabaseMain {
            file = "\ulp_server\Functions\Database";
            class getLocalTime {};
            class getWeek {};
            class getNextId {};
            class getDayName {};
        };

        class DatabasePlayer {
            file = "\ulp_server\Functions\Database\Player";
            class logPlayerEvent {};
            class queryPlayerInfo {};
            class savePlayerInfo {};
            class savePlayerState {};
            class insertPlayerInfo {};
        };

        class DatabaseVehicle {
            file = "\ulp_server\Functions\Database\Vehicle";
            class insertVehicle {};
            class storeVehicle {};
            class getGarage {};
            class retrieveVehicle {};
            class destroyVehicle {};
            class transferVehicle {};
            class isAtGarageLimit {};
            class saveVehicleUpgrades {};
        };

        class DatabaseGroup {
            file = "\ulp_server\Functions\Database\Group";
            class createGroup {};
            class queryGroupInfo {};
            class updateGroupFunds {};
            class disbandGroup {};
            class setGroupId {};
            class setGroupOwner {};
            class addGroupXP {};
            class addGroupBuff {};
            class setGroupTax {};
            class addGroupMember {};
            class getGroupFunds {};
            class setGroupPermissions {};
            class handleGroupAlliance {};
        };

        class DatabaseHousing {
            file = "\ulp_server\Functions\Database\Housing";
            class initHousing {};
            class getHouses {};
            class setupHouse {};
            class saveVirtualStorage {};
            class buyHouse {};
            class sellHouse {};
            class setHouseShared {};
            class setHouseName {};
            class getStorage {};
            class saveStorage {};
            class saveHouseUpgrades {};
            class saveHouseUpKeep {};
        };

        class DatabaseWarrants {
            file = "\ulp_server\Functions\Database\Warrants";
            class addWarrant {};
            class fetchWarrants {};
            class clearWarrants {};
            class deleteCrime {};
        };

        class DatabaseGovernment {
            file = "\ulp_server\Functions\Database\Government";
            class saveLegislation {};
            class enlistCandidate {};
            class handleVotes {};
            class getCandidates {};
            class submitVote {};
        };

        class DatabaseMail {
            file = "\ulp_server\Functions\Database\Mail";
            class addMail {};
            class getMail {};
            class updateMail {};
        };

        class DatabaseCommunityGoals {
            file = "\ulp_server\Functions\Database\CommunityGoals";
            class getCommunityGoals {};
            class initCommunityGoals {};
            class getGoalProgress {};
            class addCommunityGoalContribution {};
            class addCommunityGoal {};
            class finishCommunityGoal {};
        };

        class Channels {
            file = "\ulp_server\Functions\Channels";
            class initRadios {};
            class addRadio {};
            class removeRadio {};
            class setSideChannel {};
        };

        class Events {
            file = "\ulp_server\Functions\Events";
            class initEvents {};
            class onPlayerRespawn {};
            class onPlayerDisconnect {};
            class onPlayerKilled {};
        };

        class Player {
            file = "\ulp_server\Functions\Player";
            class registerSession {};
            class unregisterSession {};
            class getSessionField {};
            class setSessionField {};
            class validateField {};
            class reputation {};
            class hidePlayer {};
        };

        class Group {
            file = "\ulp_server\Functions\Group";
            class addToFactionGroup {};
            class handleGroupFunds {};
            class startGroupAlliance {};
            class endGroupAlliance {};
        };

        class Containers {
            file = "\ulp_server\Functions\Containers";
            class registerCargoUser {};
            class unregisterCargoUser {};
        };

        class ServerEvents {
            file = "\ulp_server\Functions\ServerEvents";
            class getEventParam {};
            class spawnEvent {};
            class initServerEvents {};
        };

        class EventTypes {
            file = "\ulp_server\Functions\ServerEvents\Types";
            class airdrop {};
            class shipwreck {};
            class popupCartel {};
        };

        class Cartels {
            file = "\ulp_server\Functions\Cartels";
            class initCartels {};
            class cartelTick {};
            class cartelReward {};
            class onCartelKill {};
        };

        class Bases {
            file = "\ulp_server\Functions\Bases";
            class initBases {};
            class awardGangBases {};
            class addBaseBid {};
            class setBaseMarkers {};
        };

        class Gathering {
            file = "\ulp_server\Functions\Gathering";
            class initGathering {};
        };

        class Loot {
            file = "\ulp_server\Functions\Loot";
            class giveLoot {};
        };

        class Crimes {
            file = "\ulp_server\Functions\Crimes";
            class initCrimes {};
            class toggleVaults {};
        };

        class Vehicle {
            file = "\ulp_server\Functions\Vehicle";
            class registerStinger {};
            class createVehicle {};
        };

        class Government {
            file = "\ulp_server\Functions\Government";
            class rigPollingStation {};
        };

        class Shipwreck {
            file = "\ulp_server\Functions\Shipwreck";
            class claimShipwreck {};
        };

        class Weather {
            file = "\ulp_server\Functions\Weather";
            class handleFog {};
            class handleRain {};
        };
        
        class Factories {
            file = "\ulp_server\Functions\Factories";
            class addFactoryTick {};
            class endFactory {};
            class startFactory {};
            class tickFactory {};
        };

        class FactoriesTypes {
            file = "\ulp_server\Functions\Factories\Types";
            class startComponentFactory {};
            class startSalvageFactory {};
            class startVehicleFactory {};
            class tickComponentFactory {};
            class tickSalvageFactory {};
            class tickVehicleFactory {};
        };

        class Cleanup {
            file = "\ulp_server\Functions\Cleanup";
            class cleanup {};
        };

        class Stats {
            file = "\ulp_server\Functions\Stats";
            class initStats {};
            class getStats {};
        };
      
        class Territories {
            file = "\ulp_server\Functions\Territories";
            class postInitTerritories { postInit=1; };
            class territoriesTick {};
        };
        
        class Gambling {
            file = "\ulp_server\Functions\Gambling";
            class resetCasinoVault {};
            class updateCasinoVault {};
        };
        
        class Notifications {
            file = "\ulp_server\Functions\Notifications";
            class sendNotification {};
            class postInitNotifications { postInit=1; };
            class buildEventNotification {};
        };
        
        class PVP {
            file = "\ulp_server\Functions\PVP";
            class initPvpModes {};
            class startPvpModeVoting {};
            class finishPvpModeVoting {};
            class castPvpModeVote {};
        };
        
        class PVPConflict {
            file = "\ulp_server\Functions\PVP\Conflict";
            class startConflict {};
            class stopConflict {};
            class spawnConflictNode {};
            class onEachFrameConflict {};
        };

        class HeadlessClient {
            file = "\ulp_server\Functions\HeadlessClient";
            class registerHc {};
            class unregisterHc {};
        };
    };
};