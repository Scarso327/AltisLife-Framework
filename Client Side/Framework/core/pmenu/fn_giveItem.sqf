/*
    @File: fn_giveItem.sqf

    @Author: Jack "Scarso" Farhall

    @Description: Gives items...
*/
#include "..\..\script_macros.hpp"
if !(params[
    ["_mode", "", [""]]
]) exitWith {};

switch (_mode) do {
    case "Load": {
        if !(createDialog "RscItemMenu") exitWith {};
        "Update" call LIFE(giveItem);
    };

    case "Update": {
        if (isNull (findDisplay 8000)) exitWith {};

        private _list = CONTROL(8000, 8004);
		lbClear _list;
		
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

    case "Give": {
        ctrlEnable [8003,false];

        private _value = ctrlText 8002;

        if ((lbCurSel 8004) isEqualTo -1) exitWith { hint "You didn't select an item you wanted to give."; ctrlEnable [8003,true]; };

        private _unit = life_pInact_curTarget;

        if (isNil "_unit") exitWith { hint "The selected player is not within range."; ctrlEnable [8003,true]; };
        if (isNull _unit || {_unit isEqualTo player}) exitWith {};

        private _item = lbData [8004, lbCurSel 8004];

        if !([_value] call TON_fnc_isnumber) exitWith { hint "You didn't enter an actual number format."; ctrlEnable [8003,true]; };
        if (parseNumber _value <= 0) exitWith { hint "You need to enter an actual amount you want to give."; ctrlEnable [8003,true]; };
        if !([false,_item, parseNumber _value] call life_fnc_handleInv) exitWith { hint "Couldn't give that much of that item, maybe you don't have that amount?"; ctrlEnable [8003,true]; };

        [_unit, _value, _item, player] remoteExecCall ["life_fnc_receiveItem", _unit];
        hint format ["You gave %1 %2 %3.", _unit getVariable ["realname", name _unit], _value, M_CONFIG(getText,"CfgItems",_item,"displayName")];

        "Update" call LIFE(giveItem);
        [3] call SOCK_fnc_updatePartial;

        ctrlEnable [8003,true];
    };
};