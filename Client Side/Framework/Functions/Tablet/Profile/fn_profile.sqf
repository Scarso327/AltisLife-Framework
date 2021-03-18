/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\..\script_macros.hpp"
scopeName "fn_profile";

_display = _this;
if (isNull _display) exitWith {};

_display setVariable ["preScreen", "Home"];

private _toolbox = _display displayCtrl 23028;

private _mainText = _display displayCtrl 23024;
_mainText ctrlSetStructuredText parseText format["<t size='1.25'>%1<br/><t size ='1'>Developer</t></t>", name player];

private _prestigeText = _display displayCtrl 23025;
_prestigeText ctrlSetStructuredText parseText format["<t size ='1' align='center'><t size ='1.25'>%1</t><br/>Prestige</t>", [ULP_Prestige] call ULP_fnc_numberText];

private _levelText = _display displayCtrl 23026;
_levelText ctrlSetStructuredText parseText format["<t size ='1' align='center'><t size ='1.25'>%1</t><br/>Level</t>", [ULP_Level] call ULP_fnc_numberText];

switch (lbCurSel _toolbox) do {
	case 3: { ["PlayerTag"] call ULP_fnc_setScreen; };
	case 2: { ["Loyalty"] call ULP_fnc_setScreen; };
	case 1: { ["Achievements"] call ULP_fnc_setScreen; };
	default { ["Professions"] call ULP_fnc_setScreen; };
};

(_display displayCtrl 23031) ctrlShow ([] call ULP_fnc_canPrestige);