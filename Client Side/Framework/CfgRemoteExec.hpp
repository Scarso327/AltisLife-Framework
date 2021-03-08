#define ANYONE 0
#define CLIENT 1
#define SERVER 2

class CfgRemoteExec {
    class Commands {
        mode = 1;
        jip = 0;

        class systemChat {};
        class lock {};
        class say3D {};
    };

    class Functions {
        mode = 1;
        jip = 0;

        // REMOVE IN PRODUCTION
        class bis_fnc_debugconsoleexec {};

        class ULP_fnc_setPlayerInfo {};
        class ULP_fnc_initVehicle {};
        class ULP_fnc_createVehicle {
            allowedTargets = CLIENT;
        };
        class ULP_fnc_vehicleLights {};
        class ULP_fnc_invokeEvent {};

        class ULP_SRV_fnc_queryPlayerInfo {
            allowedTargets = SERVER;
        };
        class ULP_SRV_fnc_savePlayerInfo {
            allowedTargets = SERVER;
        };
        class ULP_SRV_fnc_savePlayerState {
            allowedTargets = SERVER;
        };
        class ULP_SRV_fnc_createVehicle {
            allowedTargets = SERVER;
        };
        class ULP_SRV_fnc_storeVehicle {
            allowedTargets = SERVER;
        };
        class ULP_SRV_fnc_getGarage {
            allowedTargets = SERVER;
        };
        class ULP_SRV_fnc_retrieveVehicle {
            allowedTargets = SERVER;
        };
        class ULP_SRV_fnc_createGroup {
            allowedTargets = SERVER;
        };
    };
};
