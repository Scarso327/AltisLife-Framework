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
				_list lbAdd format["%2 [x%1]",ITEM_VALUE(configName _x),(getText(_x >> "displayName"))];
				_list lbSetData [(lbSize _list)-1,configName _x];
				_icon = M_CONFIG(getText,"CfgItems",configName _x,"icon");
				if !(_icon isEqualTo "") then {
					_list lbSetPicture [(lbSize _list)-1,_icon];
				};
			};
		} foreach ("true" configClasses (missionConfigFile >> "CfgItems"));

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
	
	case "KeyChain": {
		private _list = CONTROL(IDD_TABLET_MAIN, IDC_KEY_LIST);
		lbClear _list;
		
		for "_i" from 0 to (count life_vehicles)-1 do {
			_veh = life_vehicles select _i;
			if (!isNull _veh && alive _veh) then {
				_color = ((M_CONFIG(getArray,"LifeCfgVehicles",(typeOf _veh),"textures") select (_veh getVariable "Life_VEH_color")) select 0);
				if (isNil "_color") then {_color = ""};
				_text = format ["(%1)",_color];
				if (_text == "()") then {
					_text = "";
				};

				_name = getText(configFile >> "CfgVehicles" >> (typeOf _veh) >> "displayName");
				_pic = getText(configFile >> "CfgVehicles" >> (typeOf _veh) >> "picture");
				_list lbAdd format ["%1 %3 - [Distance: %2m]",_name,round(player distance _veh),_text];
				if (_pic != "pictureStaticObject") then {
					_list lbSetPicture [(lbSize _list)-1,_pic];
				};
				_list lbSetData [(lbSize _list)-1,str(_i)];
			};
		};

		if(((lbSize _list)-1) isEqualTo -1) then {
			_list lbAdd "You don't have any keys...";
			_list lbSetData [(lbSize _list)-1,""];
		};

		_list = CONTROL(IDD_TABLET_MAIN, IDC_KEY_PLAYERS);
		lbClear _list;

		{
			_list lbAdd format ["%1 - %2",_x getVariable ["realname",name _x], side _x];
			_list lbSetData [(lbSize _list)-1,str(_x)];
		} forEach (playableUnits select {!isNull _x && alive _x && player distance _x < 20 && !(_x isEqualTo player)});
	};

	case "Market": {
		private _listHeader = CONTROL(IDD_TABLET_MAIN, IDC_MARKET_HEADER);
		private _itemList = CONTROL(IDD_TABLET_MAIN, IDC_MARKET_LIST);

		[_listHeader, _itemList] call FF_fnc_setupFilter;
	};
};