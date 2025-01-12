/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_openInventory";

if (canSuspend) exitWith {
    [ULP_fnc_openInventory, _this] call ULP_fnc_directCall;
};

_this params [
	["_container", objNull, [objNull]],
	["_force", false, [true]]
];

(_container call BIS_fnc_objectType) params ["", "_type"];

// Inventory Checks...
if (isNull _container 
	|| { !alive _container } 
	|| { !([_container, _force] call ULP_fnc_hasInventory) } 
	|| { dialog } 
	|| { isDowned(player) } 
	|| { [] call ULP_UI_fnc_isProgress } 
	|| { [] call ULP_fnc_isRestrained } 
	|| { [] call ULP_fnc_isKnocked } 
	|| { [] call ULP_fnc_isSurrendered }) exitWith { false };

_force = ([player] call ULP_fnc_onDuty || _force);

// Access Checks...
if (!(_force) && { (_type in ["Car", "Helicopter", "Plane", "Ship"] && !(_container in ULP_Keys) ) 
	|| { _container getVariable ["locked", false] } 
	|| { !(_container getVariable ["drilled", true]) }
	|| { _container isKindOf "CAManBase" && { isNull (_container getVariable ["restrained", objNull]) || { !([group (_container getVariable ["restrained", objNull]), player] call ULP_fnc_inGroup) } } }
	|| { [_container] call ULP_fnc_isHouseStorage && { _container getVariable ["locked", false] } && { !([_container getVariable ["building", objNull]] call ULP_fnc_isHouseOwner) } } }) exitWith {
	["You don't have access to this container..."] call ULP_fnc_hint;
	false
};

if (createDialog "DialogInventory") exitWith {
	private _display = findDisplay 4200;
	if (isNull _display) exitWith {};

	_display setVariable ["container", _container];

	private _containerInfo = [typeOf _container] call ULP_fnc_vehicleCfg;
	if (_containerInfo isEqualTo []) exitWith {};

	_containerInfo params [
		"", "_missionCfg", "_picture", "_name"
	];
	
	private _title = _display displayCtrl 4201;
	_title ctrlSetStructuredText parseText "Inventory";
	_display setVariable ["lastUser", objNull];

	private _filter = _display displayCtrl 23032;
	private _list = _display displayCtrl 23033;

	{
		_x params ["_filter", "_list"];
		[(_display displayCtrl _filter), (_display displayCtrl _list)] call BIS_fnc_initListNBoxSorting;
	} forEach [ [4203, 4204], [4207, 4208] ];

	[_display, 0] call ULP_fnc_updateInventory;
	[_display, 1] call ULP_fnc_updateInventory;

	_display setVariable ["userRegisterEvent", (["RegisteredAsUser", {
		_this params [
			["_container", objNull, [objNull]]
		];

		private _display = findDisplay 4200;
		if (isNull _container || { isNull _display } || { !([_container] call ULP_fnc_isCargoUser) }) exitWith {};
		if !(_container isEqualTo (_display getVariable ["container", objNull])) exitWith {};
	
		[_display, 0] call ULP_fnc_updateInventory;
		[_display, 1] call ULP_fnc_updateInventory;
	}] call ULP_fnc_addEventHandler)];

	[_container, player] remoteExecCall ["ULP_SRV_fnc_registerCargoUser", RSERV];

	_display setVariable ["lastInventory", (_container getVariable ["ULP_VirtualCargo", createHashMap])];
	_display setVariable ["eachframe", ( [[_container, _display], {
		_this params [
			["_container", objNull, [objNull]],
			["_display", displayNull, [displayNull]]
		];

		if (isNull _container || { !alive _container } || { isNull _display }) exitWith {
			if !(isNull _container) then {
				[_container, player] remoteExecCall ["ULP_SRV_fnc_unregisterCargoUser", RSERV];
			};
			
			closeDialog 0;
			[_thisEventHandler] call ULP_fnc_removeEachFrame;
		};

		if ((_container distance player) > 10) exitWith {
			["You're too far from the container to access it!"] call ULP_fnc_hint;
			closeDialog 0;

			[_container, player] remoteExecCall ["ULP_SRV_fnc_unregisterCargoUser", RSERV];
			[_thisEventHandler] call ULP_fnc_removeEachFrame;
		};

		private _curInv = _container getVariable ["ULP_VirtualCargo", createHashMap];
		private _lastInv = _display getVariable ["lastInventory", createHashMap];

		if !(_curInv isEqualTo _lastInv) then {
			[_display, 1] call ULP_fnc_updateInventory;
		};

		private _curUser = _container getVariable ["ULP_VirtualCargo_User", objNull];
		if !((_display getVariable ["lastUser", objNull]) isEqualTo _curUser) then {
			private _title = _display displayCtrl 4201;
			_title ctrlSetStructuredText parseText format["Inventory <t align='right'>User: %1</t>", name _curUser];
			_display setVariable ["lastUser", _curUser];
		};
	}] call ULP_fnc_addEachFrame)];

	true
};

false