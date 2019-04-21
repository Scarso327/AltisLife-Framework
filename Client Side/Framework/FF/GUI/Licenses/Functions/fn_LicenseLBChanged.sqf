/*
	@File: fn_LicenseLBChanged.sqf
  
	@Author: Jack "Scarso" Farhall
  
	@Description: Update License Menu on License Switch...
*/
#include "..\..\..\..\script_macros.hpp"
disableSerialization;

private _price = CONTROL_VALUE(4001);

private _text = switch (true) do {
	case (_price <= 0): { "<t size='1'>Cost: <t color='#b2ec00'>Free</t></t>" };
	case (CASH >= _price): { format["<t size='1'>Cost: <t color='#b2ec00'>£%1</t></t>", [_price] call life_fnc_numberText] };
	default { format["<t size='1'>Cost: <t color='#b70000'>£%1</t></t>", [_price] call life_fnc_numberText] };
};

if (CASH >= _price) then { ctrlEnable[4003, true] } else { ctrlEnable[4003, false] }; // Toggle "Buy Button"...
(CONTROL(4000, 4002)) ctrlSetStructuredText parseText _text;