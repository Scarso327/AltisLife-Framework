/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_spawn";

_this params [
	"_button"
];

private _display = ctrlParent _button;
if (isNull _display) exitWith {};

private _spawnCfg = _display getVariable ["spawn", configNull];
if (isNull _spawnCfg) exitWith {};

private _name = "";
private _pos = [0,0,0];
private _dir = random 360;

if (_spawnCfg isEqualType configNull) then {
	_name = getText (_spawnCfg >> "displayName");
	_pos = getMarkerPos getText(_spawnCfg >> "marker");

	private _buildings = getArray (_spawnCfg >> "buildings");

	if !(_buildings isEqualTo []) then {
		_buildings = nearestObjects[_pos, _buildings, getNumber (_spawnCfg >> "radius")];
		if !(_buildings isEqualTo []) then {
			_pos = (selectRandom (_buildings select { isObjectHidden _x })) buildingPos 0;
		};
	};
} else {
	_name = [typeOf _spawnCfg] call ULP_fnc_vehicleCfg select 3;
	_pos = _spawnCfg modelToWorldVisual getArray(missionConfigFile >> "CfgHousing" >> "Houses" >> (typeOf _spawnCfg) >> "spawnPos");
};

player setPosASL AGLtoASL _pos;
player setDir _dir;

closeDialog 0;
cutText ["","BLACK IN"];
titleText[format ["%2 %1", _name, "You have spawned at"], "BLACK IN"];

if (ULP_FirstSpawn) then {
    ULP_FirstSpawn = false;

	if (["EnableWelcome"] call ULP_fnc_getOption isEqualTo 1) then {
		[
			3, [],
			{ [] call ULP_UI_fnc_screenCredits; }
		] call ULP_fnc_waitExecute;
	};

	["FirstSpawn"] call ULP_fnc_achieve;
} else {
	[false] call ULP_fnc_initPlayer;
};

player allowDammage true;

if (["EnableHUD", "HUD"] call ULP_fnc_getOption isEqualTo 1) then {
	[] call ULP_UI_fnc_openHUD;
};

[getPlayerUID player, "Spawn", [_name, getPos player]] remoteExecCall ["ULP_SRV_fnc_logPlayerEvent", RSERV];