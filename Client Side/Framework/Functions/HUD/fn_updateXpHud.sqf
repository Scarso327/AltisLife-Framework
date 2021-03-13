/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_updateXpHud";

private _ui = ["RscHUD"] call ULP_UI_fnc_getLayer;
if (isNull _ui) exitWith {}; 

_this params [
	["_show", [["EnableXPBar", "HUD"] call ULP_fnc_getOption] call ULP_fnc_bool, [false]]
];

private _xpBar = _ui displayCtrl 507;
private _xpTxt = _ui displayCtrl 508;
private _curLvlTxt = _ui displayCtrl 509;
private _nextLvlTxt = _ui displayCtrl 510;
private _bg = _ui displayCtrl 511;

if !((CtrlShown _bg) isEqualTo _show) then {
	{
		_x ctrlShow _show;
	} forEach [
		_xpBar, _xpTxt, _curLvlTxt, _nextLvlTxt, _bg
	];
};

_curLvlTxt ctrlSetStructuredText parseText format["<t align='center'>%1</t>", [ULP_Level] call ULP_fnc_numberText];

private _requiredXp = [ULP_Level] call ULP_fnc_getRequiredXP;

_xpTxt ctrlSetStructuredText parseText format["<t align='center'>%1 / %2</t>", 
	[ULP_XP] call ULP_fnc_numberText, 
	[_requiredXp] call ULP_fnc_numberText
];

_nextLvlTxt ctrlSetStructuredText parseText format["<t align='center'>%1</t>", [(ULP_Level + 1) min ([] call ULP_fnc_getMaxLevel)] call ULP_fnc_numberText];

_xpBar progressSetPosition (ULP_XP / _requiredXp);

private _txtWidth = ctrlTextWidth _curLvlTxt;

_curLvlTxt ctrlSetPositionX (((ctrlPosition _xpTxt) # 0) - _txtWidth);
_curLvlTxt ctrlSetPositionW _txtWidth;
_curLvlTxt ctrlCommit 0;

_txtWidth = ctrlTextWidth _nextLvlTxt;

_nextLvlTxt ctrlSetPositionX ((((ctrlPosition _xpTxt) # 0) + (((ctrlPosition _xpTxt) # 2) - 0.002)));
_nextLvlTxt ctrlSetPositionW _txtWidth;
_nextLvlTxt ctrlCommit 0;