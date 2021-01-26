/*
** Author: Jack "Scarso" Farhall
** Credit: Ace Mod Team (https://ace3mod.com/wiki/development/arma-3-scheduler-and-our-practices.html)
** Description: I used the solution I found with Ace mod when learning about the scheduler to improve my code, it works well.
*/
scopeName "fn_waitUntilExecute";

_this params [
	["_condition", {true}, [{}]],
	["_params", []],
	["_function", {}, [{}]]
];

ULP_waitUntilExecute pushBack [_condition, _params, _function];