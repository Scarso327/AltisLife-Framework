/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_initMarkers";

addMissionEventHandler ["Map", {
	_this params [ "_visible" ];

	disableSerialization;

	private _display = findDisplay 12;
	if (_visible && { !(isNull _display) }) exitWith {
		if !(_display getVariable ["MAP_SETUP", false]) then {
			_display setVariable ["MAP_SETUP", true];

			(_display displayCtrl 112) ctrlSetText "ascensionroleplay.co.uk";
		};

        (_display displayCtrl 51) ctrlAddEventHandler ["Draw", ULP_fnc_mapMarkers];
	};
}];

["GPS", {
	_this params [ "_visible" ];

	if (_visible) then {
		disableSerialization;

		{
			private _map = _x displayCtrl 101;
			_map ctrlRemoveAllEventHandlers "Draw";
			_map ctrlAddEventHandler ["Draw", ULP_fnc_mapMarkers];
		} forEach ((uiNamespace getVariable ["IGUI_DISPLAYS", []]) select {
			(ctrlIDD _x) isEqualTo 311
		});
	};
}] call ULP_fnc_addEventHandler;