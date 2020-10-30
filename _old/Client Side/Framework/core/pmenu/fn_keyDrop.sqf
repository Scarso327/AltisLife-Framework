/*
    File: fn_keyDrop.sqf
    Author: Bryan "Tonic" Boardwine

    Description:
    Drops a key to a vehicle (Excluding houses).
*/
#include "..\..\script_macros.hpp"
disableSerialization;

private _dialog = findDisplay 23000;
private _list = _dialog displayCtrl 23402;
private _sel = lbCurSel _list;

if (_sel isEqualTo -1) exitWith {
    hint "No data selected."
};

if (_list lbData _sel isEqualTo "") exitWith {
    hint "You did not select a vehicle."
};

private _index = parseNumber (_list lbData _sel);
private _vehicle = life_vehicles param [_index, objNull, [objNull]];
if isNull _vehicle exitWith {};

// Do not let them drop the key to a house
if (_vehicle isKindOf "House_F") exitWith {
    hint "You cannot remove the keys to your house!"
};

// Solve stupidness
if (objectParent player isEqualTo _vehicle && {locked _vehicle isEqualTo 2}) exitWith {
    hint "You cannot drop keys to a vehicle which is locked and you are inside of."
};

life_vehicles = life_vehicles - [_vehicle];

// Update vehicle owners
private _owners = _vehicle getVariable ["vehicle_info_owners", []];
_owners deleteAt _index;
_vehicle setVariable ["vehicle_info_owners", _owners, true];

// Reload
["KeyChain"] call FF(onLoad);