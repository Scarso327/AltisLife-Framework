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

        class ULP_SRV_fnc_queryPlayerInfo {
            allowedTargets = SERVER;
        };
        class ULP_SRV_fnc_savePlayerInfo {
            allowedTargets = SERVER;
        };
        class ULP_SRV_fnc_savePlayerState {
            allowedTargets = SERVER;
        };
    };
};
