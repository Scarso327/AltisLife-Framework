/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\..\script_macros.hpp"
scopeName "fn_changeTax";

if (canSuspend) exitWith {
    [ULP_fnc_changeTax, _this] call ULP_fnc_directCall;
};

_this params [
	"_ctrl"
];

private _display = ctrlParent _ctrl;
if (isNull _display) exitWith {};

private _group = group player;

if !([] call ULP_fnc_isGroupOwner) exitWith {
	["Only the owner can change group taxation rules!"] call ULP_fnc_hint;
	false
};

// Stop spam...
if (time < (_group getVariable ["tax_last_changed", 0])) exitWith {
	["You've changed the tax for this group, please wait..."] call ULP_fnc_hint;
	false
};

[
	(findDisplay getNumber(configFile >> "RscDisplayMission" >> "idd")), getArray (missionConfigFile >> "CfgGroups" >> "tax"), [_group, _display],
	{
		_this params [
			["_group", grpNull, [grpNull]],
			["_display", displayNull, [displayNull]],
			"", ["_tax", 1, [0]]
		];

		if (isNull _group) exitWith {};

		[_group, _tax] remoteExecCall ["ULP_SRV_fnc_setGroupTax", RSERV];

		[format["You've changed your group's tax rate to <t color='#B92DE0'>%1</t>", format ["%1%2", [_tax] call ULP_fnc_numberText, "%"]]] call ULP_fnc_hint;
		_group setVariable ["tax_last_changed", time + 5];

		if !(isNull _display) then {
			(_display displayCtrl 23088) ctrlSetStructuredText parseText format ["Group Tax<t align='right'>(%1%2)</t>", _tax, "%"];
		};
	}, true, "format [""%1%2"", [_this] call ULP_fnc_numberText, ""%""]", false
] call ULP_fnc_selectNumber;