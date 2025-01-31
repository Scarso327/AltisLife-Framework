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
	if ([player, ["Police"]] call ULP_fnc_isFaction || { ["cuffCourier"] call ULP_fnc_hasPerk } || { [_detainer] call ULP_fnc_onDuty } || { ["Ziptie", 1, _restrain] call ULP_fnc_handleItem }) then {
		_this remoteExecCall ["ULP_fnc_restrain", _target];
		["Retain"] call ULP_fnc_achieve;
	} else {
		["You need a ziptie to restrain someone"] call ULP_fnc_hint;
	};
};

if (_restrain) then {
	if (isNull _detainer || { [_target] call ULP_fnc_onDuty }) exitWith {};
	if ([_target] call ULP_fnc_isRestrained) exitWith {}; // Already restrained...
	_target setVariable ["restrained_in_vehicle", objectParent _target];
	_target setVariable ["restrained", _detainer, true];
	
	[] spawn ULP_UI_fnc_closeDialogs;

	if ([_target] call ULP_fnc_isSurrendered) then { _target setVariable ["surrender", nil, true]; };
	if !((currentWeapon _target) isEqualTo "") then { _target action ["SwitchWeapon", _target, _target, 100]; };
	if ([] call ULP_fnc_isEscorting) then { detach ULP_Escort; ULP_Escort = nil; };

	_target setVariable ["ULP_ScriptedInventory", true, true];
	
	{
		[_target, _x, _y, true, true] call ULP_fnc_addToCargo;
	} forEach ULP_Inventory;

	ULP_Inventory = createHashMap;
	ULP_CarryWeight = 0;

	_target setVariable ["ULP_VirtualSpace", ([] call ULP_fnc_maxCarry), true];

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
	["Restrained", [[_target, true] call ULP_fnc_getName, [_detainer, true] call ULP_fnc_getName]] remoteExecCall ["ULP_fnc_chatMessage", RCLIENT];

	[_target, "handCuff", 50, 1] remoteExecCall ["ULP_fnc_say3D"];
} else {
	if !([_target] call ULP_fnc_isRestrained) exitWith {}; // Already restrained...
	_target setVariable ["restrained_in_vehicle", nil, true];
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
	} forEach (_target getVariable ["ULP_VirtualCargo", createHashMap]);

	_target setVariable ["ULP_VirtualSpace", nil, true];
	_target setVariable ["ULP_ScriptedInventory", nil, true];
	_target setVariable ["ULP_VirtualCargo", nil, true];
	
	[format ["You've been unrestrained %1.", ([format ["by <t color='#B92DE0'>%1</t>", name _detainer], ""] select (isNull _detainer))]] call ULP_fnc_hint;

	if !(isNull _detainer) then {
		["UnRestrained", [[_target, true] call ULP_fnc_getName, [_detainer, true] call ULP_fnc_getName]] remoteExecCall ["ULP_fnc_chatMessage", RCLIENT];
	};
};