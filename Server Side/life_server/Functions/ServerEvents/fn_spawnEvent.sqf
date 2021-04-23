/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "\life_server\script_macros.hpp"
scopeName "fn_spawnEvent";

private _cfg = _this;
if (isNull _cfg) exitWith { false };

private _delay = getNumber ([_cfg, "SpawnDelay"] call ULP_SRV_fnc_getEventParam);
_delay = _delay + (random getNumber ([_cfg, "RandomAddition"] call ULP_SRV_fnc_getEventParam));

[ _delay, _cfg, { _this call compile getText (_this >> "ServerFunctions" >> "onSpawn"); } ] call ULP_fnc_waitExecute;
true