/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_screenCredits";

_this params [
	["_credits", [], [[]]]
];

if (_credits isEqualTo []) then {
	_credits = (("call compile getText (_x >> ""condition"")" configClasses (missionConfigFile >> "CfgSettings" >> "CfgCredits")) apply {
		[(configName _x), getArray(_x >> "items")]
	});
};

private _screenTime = getNumber(missionConfigFile >> "CfgSettings" >> "CfgCredits" >> "screenTime");

(_credits select 0) params ["_title", "_items"];

private _text = format ["<t size='0.40' color='#f2cb0b' align='right'>%1<br /></t><t size='0.70' color='#FFFFFF' align='right'>", _title];

{
	_text = format["%1%2<br/>", _text, (call compile _x)];
	nil
} count _items;

_text = format["%1</t>", _text];

_screenTime + (((count _items) - 1) * 0.5);

[ _text, [safezoneX + safezoneW - 0.8, 0.50], [safezoneY + safezoneH - 0.8, 0.7], _screenTime, 0.5] spawn BIS_fnc_dynamicText;

_credits deleteAt 0;

if (_credits isEqualTo []) exitWith {};

[
	(_screenTime + 2),
	[_credits],
	{ _this call ULP_UI_fnc_screenCredits; }
] call ULP_fnc_waitExecute;