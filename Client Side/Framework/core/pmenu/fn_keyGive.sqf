#include "..\..\script_macros.hpp"
/*
    File: fn_keyGive.sqf
    Author: Bryan "Tonic" Boardwine

    Description:
    Gives a copy of the key for the selected vehicle to the selected player.
    Player must be within range.
*/
private ["_dialog","_list","_plist","_sel","_vehicle","_owners","_index","_unit","_uid"];
disableSerialization;

_dialog = findDisplay 23000;
_list = _dialog displayCtrl 23402;
_plist = _dialog displayCtrl 23403;

_sel = lbCurSel _list;
if ((_list lbData _sel) isEqualTo "") exitWith {hint "You did not select a vehicle.";};
_vehicle = _list lbData _sel;
_vehicle = life_vehicles select parseNumber(_vehicle);

if ((lbCurSel 23403) isEqualTo -1) exitWith {hint "You did not select a player.";};
_sel = lbCurSel _plist;
_unit = _plist lbData _sel;
_unit = call compile format ["%1", _unit];
if (isNull _unit || isNil "_unit") exitWith {};
if (_unit == player) exitWith {};

_uid = getPlayerUID _unit;
_owners = _vehicle getVariable "vehicle_info_owners";
_index = [_uid,_owners] call TON_fnc_index;
if (_index isEqualTo -1) then  {
    _owners pushBack [_uid,_unit getVariable ["realname",name _unit]];
    _vehicle setVariable ["vehicle_info_owners",_owners,true];
};

hint format ["You have given %1 keys to your %2.",_unit getVariable ["realname",name _unit],typeOf _vehicle];
[_vehicle,_unit,profileName] remoteExecCAll ["TON_fnc_clientGetKey",_unit];