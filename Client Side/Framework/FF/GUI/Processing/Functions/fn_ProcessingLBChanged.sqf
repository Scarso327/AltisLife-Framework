/*
	@File: fn_ProcessingLBChanged.sqf
  
	@Author: Jack "Scarso" Farhall
  
	@Description: Update Processing Menu on Type Switch...
*/
#include "..\..\..\..\script_macros.hpp"
disableSerialization;

private _price = CONTROL_VALUE(5001);

private _text = switch (true) do {
	case (_price <= 0): { "<t size='1'>Cost: <t color='#b2ec00'>Free (License)</t></t>" };
	case (_price >= CASH): { format["<t size='1'>Cost: <t color='#b2ec00'>£%1</t></t>", [_price] call life_fnc_numberText] };
	default { format["<t size='1'>Cost: <t color='#b70000'>£%1</t></t>", [_price] call life_fnc_numberText] };
};

if (_price >= CASH) then { ctrlEnable[5003, true] } else { ctrlEnable[5003, false] }; // Toggle "Process Button"...
(CONTROL(5000, 5002)) ctrlSetStructuredText parseText _text;