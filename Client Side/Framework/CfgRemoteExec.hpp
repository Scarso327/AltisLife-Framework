#define ANYONE 0
#define CLIENT 1
#define SERVER 2

class CfgRemoteExec {
    class Commands {
        mode = 1;
        jip = 0;
        
        class switchMove {};
    };

    class Functions {
        mode = 1;
        jip = 0;

        // REMOVE IN PRODUCTION
        class bis_fnc_debugconsoleexec {};
        
        class ULP_fnc_setFuel {};
        class ULP_fnc_lock {};
        class ULP_fnc_say3D {};

        class ULP_fnc_chatMessage {};
        class ULP_fnc_restrain {};
        class ULP_fnc_onKnocked {};
        class ULP_fnc_setPlayerInfo {};
        class ULP_fnc_initVehicle {};
        class ULP_fnc_vehicleLights {};
        class ULP_fnc_invokeEvent {};
        class ULP_fnc_receiveMessage {};
        class ULP_fnc_lockForFactions {};
        class ULP_fnc_receivedBlood {};

        class ULP_fnc_createVehicle {
            allowedTargets = CLIENT;
        };
        class ULP_fnc_cartelHud {
            allowedTargets = CLIENT;
        };

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
        class ULP_SRV_fnc_destroyVehicle {
            allowedTargets = SERVER;
        };
        class ULP_SRV_fnc_transferVehicle {
            allowedTargets = SERVER;
        };
        class ULP_SRV_fnc_createGroup {
            allowedTargets = SERVER;
        };
        class ULP_SRV_fnc_registerCargoUser {
            allowedTargets = SERVER;
        };
        class ULP_SRV_fnc_unregisterCargoUser {
            allowedTargets = SERVER;
        };
        class ULP_SRV_fnc_logPlayerEvent {
            allowedTargets = SERVER;
        };
        class ULP_SRV_fnc_buyHouse {
            allowedTargets = SERVER;
        };
        class ULP_SRV_fnc_sellHouse {
            allowedTargets = SERVER;
        };
        class ULP_SRV_fnc_setHouseShared {
            allowedTargets = SERVER;
        };
        class ULP_SRV_fnc_setHouseName {
            allowedTargets = SERVER;
        };
        class ULP_SRV_fnc_handleGroupFunds {
            allowedTargets = SERVER;
        };
        class ULP_SRV_fnc_reputation {
            allowedTargets = SERVER;
        };
    };
};