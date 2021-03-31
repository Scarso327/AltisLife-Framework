/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_renameHouse";

if (canSuspend) exitWith {
    [ULP_fnc_renameHouse, _this] call ULP_fnc_directCall;
};

_this params [
	["_house", objNull, [objNull]],
	["_onRename", {}, [{}]],
	["_params", [], [[]]]
];

if (isNull _house) exitWith { false };

if !([_house, player, false] call ULP_fnc_isHouseOwner) exitWith {
	hint "Only the house owner can change the house name...";
	false
};

// Stop spam...
if (time < (_house getVariable ["building_last_renamed", 0])) exitWith {
	hint "You've changed the renamed this house recently, please wait...";
	false
};
_house setVariable ["building_last_renamed", time + 5];

if (_house getVariable ["selling", false]) exitWith {
	hint "This house is being sold...";
	false
};

[
	(findDisplay getNumber(configFile >> "RscDisplayMission" >> "idd")), "Enter House Name", ["Enter", "Cancel"],
	format ["Type name here...", _name], [_house, [_params, _onRename]],
	{	
		_this params [
			["_house", objNull, [objNull]],
			["_fnc", [[], {}], [[]]],
			["_name", "", [""]]
		];
		
		_name = [_name] call ULP_fnc_stripString;

		if (isNull _house) exitWith {};

		if (_house getVariable ["selling", false]) exitWith {
			hint "This house is already being sold...";
		};

		if ((count _name) > getNumber (missionConfigFile >> "CfgHousing" >> "nameLength")) exitWith {
			hint "This name is too long...";
		};

		if ((_house getVariable ["building_name", ""]) isEqualTo _name) exitWith {
			hint "You can't set the house name to the same as it's current value...";
		};

		_house setVariable ["building_name", ([_name, nil] select (_name isEqualTo "")), true];

		["HouseRenamed", [_house]] call ULP_fnc_invokeEvent;

		if ([_house] call ULP_fnc_isHouseShared) then {
			{
				["HouseRenamed", [_house]] remoteExecCall ["ULP_fnc_invokeEvent", _x];
			} forEach ((units (group player)) select {
				!(_x isEqualTo player)
			});
		};

		[_house getVariable ["building_id", -1], _name] remoteExecCall ["ULP_SRV_fnc_setHouseName", RSERV];
		hint format ["You've renamed this house to %1", _name];

		(_fnc select 0) call (_fnc select 1);
	}, false
] call ULP_fnc_enterString;
true