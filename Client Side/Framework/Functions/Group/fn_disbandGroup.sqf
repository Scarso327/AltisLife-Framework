/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_disbandGroup";

if !([] call ULP_fnc_isGroup) exitWith { false };

private _group = group player;

if !((getPlayerUID player) isEqualTo (_group getVariable ["group_owner", ""])) exitWith {
	["You must be the group owner to disband the group!"] call ULP_fnc_hint;
	false
};

if !(isNil "ULP_DisbandEvent") then { ["GroupDisbanded", ULP_DisbandEvent] call ULP_fnc_removeEventHandler; ULP_DisbandEvent = nil; };

ULP_DisbandEvent = ["GroupDisbanded", {
	private _display = findDisplay 23000;
	if (isNull _display) exitWith {};

	if ((configName (_display getVariable ["screen", ""])) in ["Group", "GroupOverview", "GroupProgression", "GroupSettings"]) then {
		["Home"] call ULP_fnc_setScreen;
		ULP_DisbandEvent = nil;
	};

	ULP_HouseSellEvent = ["HouseSold", {
		_this params [
			["_house", objNull, [objNull]],
			["_success", false, [true]],
			["_message", "", [""]],
			["_money", 0, [0]]
		];

		if (_success) then { [_money, true, "House Sold"] call ULP_fnc_addMoney; };

		ULP_HousesToSell = ULP_HousesToSell - 1;
		if (ULP_HousesToSell < 1) then {
			["All group dependant housing has been sold!"] call ULP_fnc_hint;
			["HouseSold", ULP_HouseSellEvent] call ULP_fnc_removeEventHandler;
			ULP_HouseSellEvent = nil;
		};

		_house setVariable ["selling", nil];
	}] call ULP_fnc_addEventHandler;
	ULP_HousesToSell = 0;

	{
		if ([_x, player, false] call ULP_fnc_isHouseOwner && { !(call compile getText (missionConfigFile >> "CfgHousing" >> "Houses" >> (typeOf _x) >> "condition")) }) then {
			_house setVariable ["selling", true];
			[getPlayerUID player, _x] remoteExecCall ["ULP_SRV_fnc_sellHouse", RSERV];
			ULP_HousesToSell = ULP_HousesToSell + 1;
		};
	} forEach ULP_Houses;
}] call ULP_fnc_addEventHandler;

[
	(findDisplay getNumber(configFile >> "RscDisplayMission" >> "idd")), "Confirmation", ["Disband", "Cancel"],
	format ["Are you sure you want to <t color='#B92DE0'>disband %1</t>...", [_group] call ULP_fnc_getGroupName], [_group],
	{	
		_this params [ "_group" ];

		[player, _group] remoteExecCall ["ULP_SRV_fnc_disbandGroup", RSERV];
		["GroupDisbanded", [player]] remoteExecCall ["ULP_fnc_invokeEvent", (units _group)];

		{
			[_x] joinSilent (createGroup [side _x, true]);
		} forEach (units _group);
		deleteGroup _group;
	}, { if !(isNil "ULP_DisbandEvent") then { ["GroupDisbanded", ULP_DisbandEvent] call ULP_fnc_removeEventHandler; ULP_DisbandEvent = nil; }; }, true
] call ULP_fnc_confirm;

true