/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_initGroups";

["Initialising Groups"] call ULP_fnc_logIt;

["GroupCreationSucceeded", {
	_this params [
		["_groupId", -1, [0]]
	];
	
	["Your group has been created."] call ULP_fnc_hint;
	ULP_Group_Creating = false;

	[format["Created Group (%1)", _groupId]] call ULP_fnc_logIt;

	[ { [] call ULP_fnc_isGroup }, [], { [] call ULP_fnc_setTags; }] call ULP_fnc_waitUntilExecute;
}] call ULP_fnc_addEventHandler;

["GroupCreationFailed", {
	_this params [
		["_reason", "Unknown", [""]]
	];

	[_reason] call ULP_fnc_hint;
	ULP_Group_Creating = false;

	[format["Group Creation Failed (%1)", _reason]] call ULP_fnc_logIt;
}] call ULP_fnc_addEventHandler;

["GroupWithdraw", {
	_this params [
		["_message", "", [""]],
		["_amount", 0, [0]],
		["_total", 0, [0]]
	];

	if (_amount > 0) then {
		[_amount, false, format ["Group Funds"]] call ULP_fnc_addMoney;
	};

	[_message] call ULP_fnc_hint;
}] call ULP_fnc_addEventHandler;

["GroupRankChanged", {
	_this params [
		["_rank", 0, [0]],
		["_actioner", objNull, [objNull]]
	];

	_rank = [_rank] call ULP_fnc_rankName;
	[format ["Your rank has been set to <t color='#B92DE0'>%1</t>", ([format["%1 by %2!", _rank, name _actioner], _rank] select (isNull _actioner))]] call ULP_fnc_hint;
}] call ULP_fnc_addEventHandler;

["GroupOwner", {
	[format ["<t color='#B92DE0'>%1</t> has transferred <t color='#B92DE0'>group ownership</t> to you!", name (_this param [0, objNull])]] call ULP_fnc_hint;
}] call ULP_fnc_addEventHandler;

["GroupInvite", {
	_this params [
		["_group", grpNull, [grpNull]],
		["_unit", objNull, [objNull]]
	];

	if (isNull _group || { isNull _unit }) exitWith {};

	if ([["EnableAutoDecline"] call ULP_fnc_getOption] call ULP_fnc_bool) then {
		["GroupInviteRejected", [player]] remoteExecCall ["ULP_fnc_invokeEvent", _unit];
	};

	[
		(findDisplay getNumber(configFile >> "RscDisplayMission" >> "idd")), "Confirmation", ["Accept", "Decline"],
		format ["<t color='#B92DE0'>%1</t> has invited you to join <t color='#B92DE0'>%2</t>, do you accept?", name _unit, [_group] call ULP_fnc_getGroupName], [_group, _unit],
		{
			_this params [ "_group", "_unit" ];

			[_group, player] remoteExecCall ["ULP_SRV_fnc_addGroupMember", RSERV];
		}, {
			private _unit = _this param [1, objNull];
			if (isNull _unit) exitWith {};
			["GroupInviteRejected", [player]] remoteExecCall ["ULP_fnc_invokeEvent", _unit];
		}, false
	] call ULP_fnc_confirm;
}] call ULP_fnc_addEventHandler;

["GroupInviteRejected", {
	_this params [
		["_unit", objNull, [objNull]]
	];

	if (isNull _unit) exitWith {};

	_unit setVariable ["group_invited", nil];
	[format ["<t color='#B92DE0'>%1</t> has declined the group invite you sent them!", name _unit]] call ULP_fnc_hint;
}] call ULP_fnc_addEventHandler;

["GroupJoined", {
	_this params [
		["_unit", objNull, [objNull]]
	];

	if (isNull _unit) exitWith {};
	
	if (_unit isEqualTo player) then {
		[ { [] call ULP_fnc_isGroup }, [], {
			["JoinGroup"] call ULP_fnc_achieve;

			[format ["You have <t color='#B92DE0'>joined %1</t>", [] call ULP_fnc_getGroupName]] call ULP_fnc_hint;
			[] call ULP_fnc_setTags;
		}] call ULP_fnc_waitUntilExecute;
	} else {
		_unit setVariable ["group_invited", nil];
		[format ["<t color='#B92DE0'>%1</t> has joined your group", name _unit]] call ULP_fnc_hint;
	};
}] call ULP_fnc_addEventHandler;

["GroupKicked", {
	[format ["<t color='#B92DE0'>%1</t> has kicked you from the group!", name (_this param [0, objNull])]] call ULP_fnc_hint;
	[ { !([] call ULP_fnc_isGroup) }, [], { [] call ULP_fnc_setTags; }] call ULP_fnc_waitUntilExecute;
}] call ULP_fnc_addEventHandler;

["GroupDisbanded", {
	[format ["<t color='#B92DE0'>%1</t> has disbanded the group!", name (_this param [0, objNull])]] call ULP_fnc_hint;
	[ { !([] call ULP_fnc_isGroup) }, [], { [] call ULP_fnc_setTags; }] call ULP_fnc_waitUntilExecute;
}] call ULP_fnc_addEventHandler;

["SoldVirtualItem", {
	_this params [ "_soldItem", "_amount", "", "_illegal" ];

	private _group = group player;
	private _itemCfg = missionConfigFile >> "CfgVirtualItems" >> _soldItem;

	if !(isClass _itemCfg 
		&& { [getNumber (_itemCfg >> "Settings" >> "isEventItem")] call ULP_fnc_bool } 
		&& { [] call ULP_fnc_isGroup } 
		&& { _illegal isEqualTo ((_group getVariable ["group_type", ""]) isEqualTo "Criminal") }) exitWith {};

	private _xpAmountPerItem = getNumber (missionConfigFile >> "CfgGroups" >> "Leveling" >> "XP" >> "SoldLegalItems" >> "amountPerItem");
	private _groupXp = floor (_xpAmountPerItem * _amount);

	[_group, "SoldLegalItems", _groupXp] remoteExecCall ["ULP_SRV_fnc_addGroupXP", RSERV];
	[format ["You got <t color='#B92DE0'>%1</t> Group XP for this sale", [_groupXp] call ULP_fnc_numberText]] call ULP_fnc_hint;
}] call ULP_fnc_addEventHandler;