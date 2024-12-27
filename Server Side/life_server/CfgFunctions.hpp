class CfgFunctions {

    class Functions {
        tag = "ULP_SRV";

		class Root {
			file = "\life_server";
			class init {};
		};

        class Airdrop {
            file = "\life_server\Functions\Airdrop";
            class claimAirdrop {};
        };

        class DatabaseMain {
            file = "\life_server\Functions\Database";
            class getLocalTime {};
            class getWeek {};
            class getNextId {};
            class getDayName {};
        };

        class DatabasePlayer {
            file = "\life_server\Functions\Database\Player";
            class logPlayerEvent {};
            class queryPlayerInfo {};
            class savePlayerInfo {};
            class savePlayerState {};
        };

        class DatabaseVehicle {
            file = "\life_server\Functions\Database\Vehicle";
            class createVehicle {};
            class storeVehicle {};
            class getGarage {};
            class retrieveVehicle {};
            class destroyVehicle {};
            class transferVehicle {};
            class isAtGarageLimit {};
        };

        class DatabaseGroup {
            file = "\life_server\Functions\Database\Group";
            class createGroup {};
            class queryGroupInfo {};
            class handleGroupFunds {};
            class disbandGroup {};
            class setGroupId {};
            class setGroupOwner {};
            class addGroupXP {};
            class addGroupBuff {};
            class setGroupTax {};
            class addGroupMember {};
        };

        class DatabaseHousing {
            file = "\life_server\Functions\Database\Housing";
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
        };

        class DatabaseWarrants {
            file = "\life_server\Functions\Database\Warrants";
            class addWarrant {};
            class fetchWarrants {};
            class clearWarrants {};
            class deleteCrime {};
        };

        class DatabaseGovernment {
            file = "\life_server\Functions\Database\Government";
            class saveLegislation {};
            class enlistCandidate {};
            class handleVotes {};
            class getCandidates {};
            class submitVote {};
        };

        class DatabaseMail {
            file = "\life_server\Functions\Database\Mail";
            class addMail {};
            class getMail {};
            class updateMail {};
        };

        class DatabaseCommunityGoals {
            file = "\life_server\Functions\Database\CommunityGoals";
            class getCommunityGoals {};
            class initCommunityGoals {};
            class getGoalProgress {};
            class addCommunityGoalContribution {};
            class addCommunityGoal {};
            class finishCommunityGoal {};
        };

        class Channels {
            file = "\life_server\Functions\Channels";
            class initRadios {};
            class addRadio {};
            class removeRadio {};
        };

        class Events {
            file = "\life_server\Functions\Events";
            class initEvents {};
            class onPlayerRespawn {};
            class onPlayerDisconnect {};
            class onPlayerKilled {};
        };

        class Player {
            file = "\life_server\Functions\Player";
            class registerSession {};
            class unregisterSession {};
            class getSessionField {};
            class setSessionField {};
            class validateField {};
            class reputation {};
            class hidePlayer {};
        };

        class Containers {
            file = "\life_server\Functions\Containers";
            class registerCargoUser {};
            class unregisterCargoUser {};
        };

        class ServerEvents {
            file = "\life_server\Functions\ServerEvents";
            class getEventParam {};
            class spawnEvent {};
            class initServerEvents {};
        };

        class EventTypes {
            file = "\life_server\Functions\ServerEvents\Types";
            class airdrop {};
            class shipwreck {};
            class popupCartel {};
        };

        class Cartels {
            file = "\life_server\Functions\Cartels";
            class initCartels {};
            class cartelTick {};
            class cartelReward {};
            class onCartelKill {};
        };

        class Bases {
            file = "\life_server\Functions\Bases";
            class initBases {};
            class addBaseBid {};
        };

        class Gathering {
            file = "\life_server\Functions\Gathering";
            class initGathering {};
        };

        class Loot {
            file = "\life_server\Functions\Loot";
            class giveLoot {};
        };

        class Crimes {
            file = "\life_server\Functions\Crimes";
            class initCrimes {};
            class toggleVaults {};
        };

        class Vehicle {
            file = "\life_server\Functions\Vehicle";
            class registerStinger {};
        };

        class Government {
            file = "\life_server\Functions\Government";
            class rigPollingStation {};
        };

        class Shipwreck {
            file = "\life_server\Functions\Shipwreck";
            class claimShipwreck {};
        };

        class Weather {
            file = "\life_server\Functions\Weather";
            class handleFog {};
        };
    };

    class MySQL_Database {
        tag = "DB";
        class MySQL
        {
            file = "\life_server\Functions\MySQL";
            class mresArray {};
            class asyncCall {};
            class mresToArray {};
            class mresString {};
        };
    };

    class TON_System {
        tag = "TON";
        class Systems {
            file = "\life_server\Functions\Systems";
            class cleanup {};
        };

        class PlayTime {
            file = "\life_server\Functions\PlayTime";
            class setPlayTime {};
            class getPlayTime {};
        };
    };
};