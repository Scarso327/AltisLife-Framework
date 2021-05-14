/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\..\script_macros.hpp"
scopeName "fn_restrain";

if (canSuspend) exitWith {
    [ULP_fnc_restrain, _this] call ULP_fnc_directCall;
};

_this params [
	["_target", cursorObject, [objNull]],
	["_detainer", objNull, [objNull]],
	["_restrain", false, [true]]
];

// Checks...
if (isNull _target || { !(isPlayer _target) } || { !(isNull _detainer) && { !([_detainer] call ULP_fnc_onDuty) } && { (_target distance _detainer) > 5 } }) exitWith { false };

if !(local _target) exitWith {
	if ([player, ["Police"]] call ULP_fnc_isFaction || { ["Ziptie", 1, true] call ULP_fnc_handleItem } || { ["cuffCourier"] call ULP_fnc_hasPerk } || { [_detainer] call ULP_fnc_onDuty }) then {
		_this remoteExecCall ["ULP_fnc_restrain", _target];
	} else {
		["You need a ziptie to restrain someone"] call ULP_fnc_hint;
	};
};

if (_restrain) then {
	if (isNull _detainer || { [_target] call ULP_fnc_onDuty }) exitWith {};
	if ([_target] call ULP_fnc_isRestrained) exitWith {}; // Already restrained...
	_target setVariable ["restrained", _detainer, true];
	
	[] spawn ULP_UI_fnc_closeDialogs;

	if ([_target] call ULP_fnc_isSurrendered) then { _target setVariable ["surrender", nil, true]; };
	if !((currentWeapon _target) isEqualTo "") then { _target action ["SwitchWeapon", _target, _target, 100]; };
	if ([] call ULP_fnc_isEscorting) then { detach ULP_Escort; ULP_Escort = nil; };

	player setVariable ["ULP_ScriptedInventory", true, true];
	
	{
		[player, _x, _y, true, true] call ULP_fnc_addToCargo;
	} forEach ULP_Inventory;

	ULP_Inventory = createHashMap;
	ULP_CarryInfo set [0, 0];

	player setVariable ["ULP_VirtualSpace", ULP_CarryInfo param [1, 0], true];

	[_target, {
		if (!(alive _this) || { !([_this] call ULP_fnc_isRestrained) } || { [_this] call ULP_fnc_onDuty }) exitWith {
			[_thisEventHandler] call ULP_fnc_removeEachFrame;
			[_this] call ULP_fnc_restrain;
		};

		if (isNull (objectParent _this) && { !([_this] call ULP_fnc_isKnocked) } && { !(isDowned(_this)) }) then {
			_this playMoveNow "AmovPercMstpSnonWnonDnon_Ease";
		};
    }] call ULP_fnc_addEachFrame;

	[format ["You've been restrained by <t color='#B92DE0'>%1</t>.", name _detainer]] call ULP_fnc_hint;
} else {
	if !([_target] call ULP_fnc_isRestrained) exitWith {}; // Already restrained...
	_target setVariable ["restrained", nil, true];

	if (alive _target && { !(isDowned(_target)) }) then {
		_target playMove (["IDLE", "STAND"] call ULP_fnc_getAnim);
	};

	if ([_target] call ULP_fnc_isEscorted) then {
		detach _target;
	};

	{
		if (_y isEqualType []) then {
			private _item = _x;

			{
				[_item, _x, false, true] call ULP_fnc_handleItem;
			} forEach _y;
		} else {
			[_x, _y, false, true] call ULP_fnc_handleItem;
		};
	} forEach (player getVariable ["ULP_VirtualCargo", createHashMap]);

	player setVariable ["ULP_VirtualSpace", nil, true];
	player setVariable ["ULP_ScriptedInventory", nil, true];
	player setVariable ["ULP_VirtualCargo", nil, true];
	
	[format ["You've been unrestrained %1.", ([format ["by <t color='#B92DE0'>%1</t>", name _detainer], ""] select (isNull _detainer))]] call ULP_fnc_hint;
};