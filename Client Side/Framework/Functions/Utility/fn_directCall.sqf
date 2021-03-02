/*
** Author: Jack "Scarso" Farhall
** Credit: CBA (https://github.com/CBATeam/CBA_A3/blob/master/addons/common/fnc_directCall.sqf)
** Description: I used the solution I found with Ace mod when learning about the scheduler to improve my code, it works well.
*/
scopeName "fn_directCall";

_this params [
	["_code", {}, [{}]],
	["_this", [], [[]]]
];

private "_return";

isNil {
    _return = ([_x] apply { call _code }) select 0;
};

if !(isNil "_return") then {
	_return
};