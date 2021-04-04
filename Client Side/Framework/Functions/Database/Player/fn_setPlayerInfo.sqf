/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\..\script_macros.hpp"
scopeName "fn_setPlayerInfo";

if (ULP_Loaded) exitWith {};

if (canSuspend) exitWith {
    [ULP_fnc_setPlayerInfo, _this] call ULP_fnc_directCall;
};

_this params [
	["_playerData", false, [[], false]]
];

["Setting Player Information"] call ULP_fnc_logIt;

if (_playerData isEqualType false) exitWith {}; // Fail

_playerData params ["_uid", "_steamid", "_groupid", "_cash", "_bank", "", "", "_adminlevel", "_eventslevel", "_donorlevel", "_licenses", "_gear", "_stats", "_professions", "_prestige", "_level", "_xp", "_achievements", "_daily", "_weekly", "_textures", "_titles", "_perks", "_bool"];
private _count = count _playerData;

if !(_steamid isEqualTo (getPlayerUID player)) exitWith {}; // Fail

private _factionCfg = missionConfigFile >> "CfgFactions" >> [player] call ULP_fnc_getFaction; // Gets the config for our current faction...

// Money...
CASH = _cash;
BANK = _bank;

// System whitelisting...
CONST(ULP_Staff, _adminlevel);
CONST(ULP_Event, _eventslevel);
CONST(ULP_Donator, _donorlevel);

ULP_Licenses = (_licenses select {
	isClass (missionConfigFile >> "CfgLicenses" >> _x)
});

ULP_Professions = _professions;
ULP_Achievements = _achievements;

private _max = [] call ULP_fnc_getMaxLevel;
if (_level > _max) then { _level = _max; };

private _required = [_level] call ULP_fnc_getRequiredXP;
for "_i" from 0 to 1 step 0 do {
	scopeName "fn_setPlayerInfo_rankLoop";

	if (_xp < _required) exitWith {};

	if (_xp >= _required) then {
		if (_level isEqualTo _max) then {
			_xp = _required;
			breakOut "fn_setPlayerInfo_rankLoop";
		} else {
			_xp = _xp - _required;
			_level = _level + 1;
			_required = [_level] call ULP_fnc_getRequiredXP;
		};
	};
};

ULP_Prestige = _prestige;
ULP_Level = _level;
ULP_XP = _xp;

// Set saved survival statistics....
ULP_Survival_Hunger = (_stats select 0);
ULP_Survival_Thirst = (_stats select 1);
player setDamage (_stats select 2);

// TODO : Handle Blacklisting...

switch (configName _factionCfg) do {
	case "Civilian": {
		ULP_Imprisioned = _bool;
		ULP_Prison_Time = (_playerData select 18);
	};
};

// Set any whitelisting values our faction may have...
if (isClass (_factionCfg >> "Whitelisting")) then {
	{
		missionNamespace setVariable [format["%1_%2", configName _factionCfg, configName _x], compileFinal str(_playerData select (getNumber(_x >> "queryIndex")))];
	} forEach ("isNumber(_x >> 'queryIndex')" configClasses (_factionCfg >> "Whitelisting"));
};

// Add us into a gang if we're apart of one...
private _group = _playerData select (_count - 5);
if (_group isEqualType 0) then {
	if !(_groupid isEqualTo _group) exitWith {
		[format["Server didn't catch group id mismatch (%1, %2)", _groupid, _group]] call ULP_fnc_logIt;
	};

	InitGroupId = _groupid;
	[format["Joined Group (%1)", _group]] call ULP_fnc_logIt;
};

// Retrieve any houses returned to us from the sever and set them up...
private _houses = _playerData select (_count - 4);
if (_houses isEqualType []) then {
	[_houses] call ULP_fnc_setupHouses;
};

// Get vehicle keys we've had this restart...
{
	ULP_Keys pushBack _x
} forEach (_playerData select (_count - 3));

[_daily, _weekly] call ULP_fnc_initPersonalGoals;

ULP_New = (_playerData select (_count - 2)); // Tells us if this is a new database insert...
ULP_Date = (_playerData select (_count - 1)); // Contains Year, Month and Day in that order...

// Apply our saved gear...
ULP_Gear = _gear;
[ULP_Gear] call ULP_fnc_loadGear;

ULP_UnlockedTextures = _textures;
ULP_Titles = _titles;
ULP_Perks = _perks;

ULP_Loaded = true; // Tells the initialisation script we're able to continue...
InitGroupId = nil; // Only used during init as Arma doesn't seem to add us to group in time...