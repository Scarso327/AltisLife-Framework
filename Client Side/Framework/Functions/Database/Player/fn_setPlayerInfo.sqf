/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\..\script_macros.hpp"
scopeName "fn_setPlayerInfo";

if (ULP_Loaded) exitWith {};

_this params [
	["_playerData", false, [[], false]]
];

["Setting Player Information"] call ULP_fnc_logIt;

if (_playerData isEqualType false) exitWith {}; // Fail

_playerData params ["_uid", "_steamid", "_cash", "_bank", "", "", "_adminlevel", "_donorlevel", "_licenses", "_gear", "_stats"];

if !(_steamid isEqualTo (getPlayerUID player)) exitWith {}; // Fail

private _factionCfg = missionConfigFile >> "CfgFactions" >> [player] call ULP_fnc_getFaction;

CASH = _cash;
BANK = _bank;

CONST(life_adminlevel, _adminlevel);
CONST(life_donorlevel, _donorlevel);

{
	ULP_Liceneses pushBackUnique (_x select 0);
} forEach (_licenses select {
	(_x select 1) isEqualTo 1
});

ULP_Survival_Hunger = (_stats select 0);
ULP_Survival_Thirst = (_stats select 1);
player setDamage (_stats select 2);

// TODO : Handle Blacklisting...

if (isClass (_factionCfg >> "Whitelisting")) then {
	{
		missionNamespace setVariable [format["%1_%2", configName _factionCfg, configName _x], compileFinal str(_playerData select (getNumber(_x >> "queryIndex")))];
	} forEach ("isNumber(_x >> 'queryIndex')" configClasses (_factionCfg >> "Whitelisting"));
};

private _gang = _playerData select (_count - 4);
if (_gang isEqualType []) then {
	// TODO
};

private _houses = _playerData select (_count - 3);
if (_houses isEqualType []) then {
	ULP_Houses = _houses;

	{
		_house = nearestObject [(parseSimpleArray (_x select 0)), "House"];
		life_vehicles pushBack (_house);
	} forEach ULP_Houses;
};

[] call life_fnc_initHouses;

{
	life_vehicles pushBack _x
} forEach (_playerData select (_count - 2));

ULP_Gear = _gear;
[] call ULP_fnc_loadGear;

ULP_Loaded = true;