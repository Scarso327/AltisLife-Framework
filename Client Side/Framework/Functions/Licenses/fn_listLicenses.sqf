/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_listLicenses";

private _display = findDisplay 3900;
private _cfg = _display getVariable ["store", configNull];
if (isNull _cfg) exitWith {};

private _list = _display displayCtrl 3903;
lbClear _list;

{
	private _license = missionConfigFile >> "CfgLicenses" >> _x;

	if (isClass _license && { !([_x] call ULP_fnc_hasLicense) }) then {
		private _item = _list lbAdd format["%1", getText (_license >> "displayName")];
		_list lbSetValue [_item, getNumber (_license >> "buyPrice")];
		_list lbSetData [_item, _x];
	};
} forEach getArray(_cfg >> "licenses");

_list lbSetCurSel 0;
[_list, 0] call ULP_fnc_onLicenseSwitch;