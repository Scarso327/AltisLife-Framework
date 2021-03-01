class DefaultEventhandlers;
class CfgPatches {
    class life_server {
        units[] = {"C_man_1"};
        weapons[] = {};
        requiredAddons[] = {"A3_Data_F","A3_Soft_F","A3_Soft_F_Offroad_01","A3_Characters_F"};
        fileName = "life_server.pbo";
        author = "Tonic";
    };
};

class CfgFunctions {

    class Functions {
        tag = "ULP_SRV";

        class DatabaseMain {
            file = "\life_server\Functions\Database";
            class getLocalTime {};
        };

        class DatabasePlayer {
            file = "\life_server\Functions\Database\Player";
            class queryPlayerInfo {};
            class savePlayerInfo {};
            class savePlayerState {};
        };
    };

    class MySQL_Database {
        tag = "DB";
        class MySQL
        {
            file = "\life_server\Functions\MySQL";
            class numberSafe {};
            class mresArray {};
            class asyncCall{};
            class mresToArray {};
            class bool {};
            class mresString {};
            class updatePartial {};
        };
    };

    class Life_System {
        tag = "life";
        class Wanted_Sys {
            file = "\life_server\Functions\WantedSystem";
            class wantedFetch {};
            class wantedPerson {};
            class wantedBounty {};
            class wantedRemove {};
            class wantedAdd {};
            class wantedCrimes {};
            class wantedProfUpdate {};
        };
    };

    class TON_System {
        tag = "TON";
        class Systems {
            file = "\life_server\Functions\Systems";
            class managesc {};
            class cleanup {};
            class clientDisconnect {};
            class entityRespawned {};
            class cleanupRequest {};
        };

        class PlayTime {
            file = "\life_server\Functions\PlayTime";
            class setPlayTime {};
            class getPlayTime {};
        };
    };
};

class CfgVehicles {
    class Car_F;
    class CAManBase;
    class Civilian;
    class Civilian_F : Civilian {
        class EventHandlers;
    };

    class C_man_1 : Civilian_F {
        class EventHandlers: EventHandlers {
            init = "(_this select 0) execVM ""\life_server\fix_headgear.sqf""";
        };
    };
};
