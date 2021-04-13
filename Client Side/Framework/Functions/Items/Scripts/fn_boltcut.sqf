/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\..\script_macros.hpp"
scopeName "fn_boltcut";

private _object = cursorObject;
if (isNull _object || { (player distance _object) > 5 } || { !(_object getVariable ["locked", false]) }) exitWith {
	hint "You're either not close enough to something you can bolt cut or it's already been cut...";
};

["Boltcutting", 150, [_object], { (player distance (_this select 0)) <= 5 }, {
	private _object = _this select 0;
	
	hint "You have successfully cut the bolt...";
	_object setVariable ["locked", nil, true];
}, {}, ["GRAB", "CROUCH"]] call ULP_UI_fnc_startProgress;