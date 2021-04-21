/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
scopeName "fn_openLegislation";

if !([] call ULP_fnc_isGovernor) exitWith {
	["Only the governor can access this system..."] call ULP_fnc_hint;
};

if (createDialog "DialogLegislation") then {
	private _display = findDisplay 4800;
	if (isNull _display) exitWith {};

	_display setVariable ["legislation_changed", (["LegislationChanged", {
		private _display = findDisplay 4800;
		if (isNull _display) exitWith {};
		
		private _list = _display displayCtrl 4801;
		lbClear _list;

		{
			private _item = _list lbAdd format ["%1 [%2]", getText (_x >> "displayName"), ([configName _x] call ULP_fnc_getLegislation) call compile getText (_x >> "format")];
			_list lbSetData [_item, configName _x];
			_list lbSetTooltip [_item, getText (_x >> "tooltip")];
		} forEach ("isClass _x" configClasses (missionConfigFile >> "CfgGovernment" >> "Legislation"));
	}] call ULP_fnc_addEventHandler)];

	["LegislationChanged"] call ULP_fnc_invokeEvent;
};