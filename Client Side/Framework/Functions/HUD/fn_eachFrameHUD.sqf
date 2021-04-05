/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_eachFrameHud";

_this params [
	"_ui", "_food", "_water", "_health"
];

if (isNull _ui) exitWith { [_thisEventHandler] call ULP_fnc_removeEachFrame; };

private _lastVal = 0;

{
	_x params [
		"_ctrl", "_type", "_val"
	];

	_ctrl params [
		"_text", "_bar"
	];

	if (ctrlShown _text) then {
		_lastVal = _ui getVariable [_type, 1];

		if (_lastVal isEqualTo _val) exitWith {};

		_text ctrlSetStructuredText parseText format["<t><img image='Data\UI\%1.paa' size='0.8'/></t><t align='right'>%2%3</t>", _type, _val, "%"];
		_bar progressSetPosition (_val / 100);
		_ui setVariable [_type, _val];
	};
} forEach [
	[_food, "food", missionNamespace getVariable ["ULP_Survival_Hunger", 1]],
	[_water, "water", missionNamespace getVariable ["ULP_Survival_Thirst", 1]],
	[_health, "health", round ((1 - (damage player)) * 100)]
];

private _uiIcons = _ui getVariable ["icons", []];
private _icons = (("isText (_x >> ""condition"") && { isText (_x >> ""icon"") } && { call compile getText(_x >> ""condition"") }" 
configClasses (missionConfigFile >> "CfgStatusIcons")) select {
	[player] call ULP_fnc_getFaction in getArray (_x >> "factions")
});

if !(_icons isEqualTo _uiIcons) then {
	{
		ctrlDelete _x;
	} forEach (_ui getVariable ["iconCtrls", []]);
	
	private _iconCtrls = [];

	{
		private _icon = _ui ctrlCreate ["Life_RscPictureKeepAspect", 507 + _forEachIndex];
		_icon ctrlSetPosition [(0.0153125 + (0.021625 * _forEachIndex)) * safezoneW + safezoneX, 0.951 * safezoneH + safezoneY, 0.020625 * safezoneW, 0.033 * safezoneH];
		_icon ctrlSetText (getMissionPath getText (_x >> "icon"));

		_iconCtrls pushBack _icon;
		_icon ctrlCommit 0;
	} forEach _icons;

	_ui setVariable ["iconCtrls", _iconCtrls];
	_ui setVariable ["icons", _icons];
};