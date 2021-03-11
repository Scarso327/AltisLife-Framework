/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_initialisation";

waitUntil { !isNull player && { !isNull (findDisplay 46) } };

cutText["","BLACK FADED"];
0 cutFadeOut 9999999;

private _startTime = diag_tickTime;
["Initialisation Started"] call ULP_fnc_logIt;

[] call ULP_fnc_initVars;

player allowDammage false;

["Setting Eventhandlers"] call ULP_fnc_logIt;
[] call ULP_fnc_initPlayerEvents;
[] call ULP_fnc_initEventHandlers;
[] call ULP_fnc_initSurvival;

["Waiting For Server"] call ULP_fnc_logIt;

waitUntil { !isNil "life_server_isReady" };

[] call ULP_fnc_getPlayerInfo;

waitUntil { ULP_Loaded };

["Checking Whitelisting"] call ULP_fnc_logIt;
private _factionCfg = missionConfigFile >> "CfgFactions" >> [player] call ULP_fnc_getFaction;

if (isClass (_factionCfg >> "Whitelisting")) then {
	{
		if (call (missionNamespace getVariable format["%1_%2", configName _factionCfg, configName _x]) <= 0) exitWith {
			["NotWhitelisted",false,true] call BIS_fnc_endMission;
			breakOut "fn_initialisation";
		};
	} forEach ("isNumber(_x >> 'required')" configClasses (_factionCfg >> "Whitelisting"));
};

["Setting Textures"] call ULP_fnc_logIt;
private _container = objNull;

{
	_container = uniformContainer _x;
	[_x, _container, _container getVariable ["texture", ""], false] call ULP_fnc_setTextures;
} forEach allUnits select {
	!(_x isEqualTo player)
};

[{
	{
		if (_x getVariable["jipReady", false]) then { [_x, true] call ULP_fnc_initVehicle; };
		if ((getPlayerUID player) in (_x getVariable ["vehicle_owners", createHashMap])) then { ULP_Keys pushBackUnique _x; };
	} forEach vehicles;
}] call ULP_fnc_directCall;

["Starting Paycheck Loop"] call ULP_fnc_logIt;
ULP_Paycheck = [] call ULP_fnc_calcPaycheck;
CONSTVAR(ULP_Paycheck);
[] execFSM "Functions\Paycheck\pay.fsm";

["Starting Input Handler"] call ULP_fnc_logIt;
(findDisplay 46) displayAddEventHandler ["KeyDown", "_this call ULP_fnc_keyDown"];
(findDisplay 46) displayAddEventHandler ["KeyUp", "_this call ULP_fnc_KeyUp"];

["Setting Player Tags"] call ULP_fnc_logIt;
[] call ULP_fnc_setTags;
[true] call ULP_fnc_playerTags;

["Creating World"] call ULP_fnc_logIt;

private _mapCfg = missionConfigFile >> "CfgMaps" >> worldName;

if (hasInterface && { isClass (_mapCfg >> "Lighting") }) then {
	ULP_NightLight = "#lightpoint" createVehicleLocal [0, 0, 0];

    ULP_NightLight setLightDayLight false;
	ULP_NightLight setLightBrightness (["NightLight"] call ULP_fnc_getOption);
	ULP_NightLight setLightAttenuation [10e10, getNumber(_mapCfg >> "Lighting" >> "brightness"), 4.31918e-005, 4.31918e-005];
	ULP_NightLight setLightAmbient getArray (_mapCfg >> "Lighting" >> "color");
};

["Finishing Initialisation"] call ULP_fnc_logIt;

[] call ULP_fnc_spawnMenu;

[format["Initialisation Lasted %1s", diag_tickTime - _startTime]] call ULP_fnc_logIt;