/*
	@File: fn_onLoad.sqf
  
	@Author: Jack "Scarso" Farhall
  
	@Description: Runs on switch application...
*/
#include "..\..\..\..\script_macros.hpp"
#include "..\macros.hpp"
params [
	["_title", "AsYetUntitled", [""]]
];

disableSerialization;
if (_title isEqualTo "AsYetUntitled") exitWith { systemChat "No Title..." };

switch (_title) do {
	case "Inventory": {
		private _list = CONTROL(IDD_TABLET_MAIN, IDC_INV_LIST);
		lbClear _list;
		
		ctrlSetText[IDC_INV_TITLE,format["Inventory Menu [Weight: %1 / %2]", life_carryWeight, life_maxWeight]];
		
		{
			if(ITEM_VALUE(configName _x) > 0) then {
				_list lbAdd format["%2 [x%1]",ITEM_VALUE(configName _x),localize (getText(_x >> "displayName"))];
				_list lbSetData [(lbSize _list)-1,configName _x];
				_icon = M_CONFIG(getText,"VirtualItems",configName _x,"icon");
				if !(_icon isEqualTo "") then {
					_list lbSetPicture [(lbSize _list)-1,_icon];
				};
			};
		} foreach ("true" configClasses (missionConfigFile >> "VirtualItems"));

		if(((lbSize _list)-1) isEqualTo -1) then {
			_list lbAdd "You don't have any items...";
			_list lbSetData [(lbSize _list)-1,""];
		};
	};

	case "Licenses": {
		private _list = CONTROL(IDD_TABLET_MAIN, IDC_LIC_LIST);
		lbClear _list;

		{
			if (LICENSE_VALUE(configName _x,_side)) then { _list lbAdd getText(_x >> "displayName") };
		} forEach (format ["getText(_x >> 'side') isEqualTo '%1'",_side] configClasses (missionConfigFile >> "CfgLicenses"));

		if(((lbSize _list)-1) isEqualTo -1) then {
			_list lbAdd "You don't have any licenses...";
			_list lbSetData [(lbSize _list)-1,""];
		};
	};
};