/*
** Author: Jack "Scarso" Farhall
** Credit: Ace Mod Team (https://ace3mod.com/wiki/development/arma-3-scheduler-and-our-practices.html)
** Description: I used the solution I found with Ace mod when learning about the scheduler to improve my code, it works well.
*/
scopeName "fn_waitExecute";

_this params [
	["_delay", 0, [0]],
	["_params", []],
	["_function", {}, [{}]]
];

ULP_waitExecute pushBack [diag_tickTime + _delay, _params, _function];
ULP_waitExecute sort true;