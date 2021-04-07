class CfgFunctions {

    class Functions {
        tag = "ULP_SRV";

		class Root {
			file = "\life_server";
			class init {};
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
        };

        class DatabaseGroup {
            file = "\life_server\Functions\Database\Group";
            class createGroup {};
            class queryGroupInfo {};
            class handleGroupFunds {};
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
        };

        class Containers {
            file = "\life_server\Functions\Containers";
            class registerCargoUser {};
            class unregisterCargoUser {};
        };

        class ServerEvents {
            file = "\life_server\Functions\ServerEvents";
            class spawnEvent {};
            class initServerEvents {};
        };

        class EventTypes {
            file = "\life_server\Functions\ServerEvents\Types";
            class airdrop {};
            class shipwreck {};
        };

        class Cartels {
            file = "\life_server\Functions\Cartels";
            class initCartels {};
            class cartelTick {};
            class cartelReward {};
            class onCartelKill {};
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