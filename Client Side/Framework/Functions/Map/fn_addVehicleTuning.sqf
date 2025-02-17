/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_addVehicleTuning";

_this params [
	["_trader", objNull, [objNull]]
];

if (isNull _trader) exitWith {};

_trader addAction ["<t color='#B92DE0'>[Civilian]</t> Vehicle Tuning", {

	private _near = ((player nearEntities [["Car", "Air", "Ship"], 15]) select {
		[player, _x] call ULP_fnc_isVehicleOwner
	});

	if (_near isEqualTo []) exitWith {
		["There are no vehicles you own nearby"] call ULP_fnc_hint;
	};

	[(findDisplay getNumber(configFile >> "RscDisplayMission" >> "idd")), (_near apply { 
		([typeOf _x] call ULP_fnc_vehicleCfg) params [  "", "", "_picture", "_name" ]; 
		[_picture, _name, _x call BIS_fnc_netId, 0];
		}), ["Upgrade", "Cancel"], [], {
			_this params [
				["_display", displayNull, [displayNull]]
			];

			if (isNull _display) exitWith {};
			private _list = _display displayCtrl 4509;

			private _vehicle = (_list lbData (lbCurSel _list)) call BIS_fnc_objectFromNetId;
			if (isNull _vehicle) exitWith { ["You didn't select a vehicle to upgrade!"] call ULP_fnc_hint; };

			private _cfg = [typeOf _vehicle] call ULP_fnc_vehicleCfg;
			if (isNull _vehicle || { _cfg isEqualTo [] }) exitWith {};

			_cfg params [
				"", "_missionCfg"
			];

			if !(isClass _missionCfg) exitWith {};

			["DialogUpgrades", [_vehicle]] call ULP_UI_fnc_createDialog;
		}, false] call ULP_fnc_selectObject;
}, [], 1, true, true, "", "isNull (objectParent _this) && { [_this, [""Civilian""]] call ULP_fnc_isFaction }", 3];