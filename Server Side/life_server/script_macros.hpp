#define CASH ULP_234_Cash
#define BANK ULP_547_Bank

//RemoteExec Macros
#define RSERV 2 //Only server
#define RCLIENT -2 //Except server
#define RANY 0 //Global

#define EXTDB "extDB3" callExtension
#define EXTDB_SETTING(TYPE,SETTING) TYPE(missionConfigFile >> "CfgServer" >> SETTING)
#define EXTDB_FAILED(MESSAGE) \
    life_server_extDB_notLoaded = [true,##MESSAGE]; \
    publicVariable "life_server_extDB_notLoaded"; \
    diag_log MESSAGE;

//Scripting Macros
#define CONST(var1,var2) var1 = compileFinal (if (var2 isEqualType "") then {var2} else {str(var2)})
#define CONSTVAR(var) var = compileFinal (if (var isEqualType "") then {var} else {str(var)})
#define FETCH_CONST(var) (call var)

#define LIFE_SETTINGS(TYPE,SETTING) TYPE(missionConfigFile >> "CfgSettings" >> SETTING)