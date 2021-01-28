/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
scopeName "fn_onEachFrame";

{
	_x params ["_params", "_function"];
	private _thisEventHandler = _forEachIndex;
	_params call _function;
} forEach ULP_eachFrameEvents;

// Credit: Ace Mod Team (https://ace3mod.com/wiki/development/arma-3-scheduler-and-our-practices.html)

for "_i" from 0 to 1 step 0 do {
	if (ULP_waitExecute isEqualTo [] || {
		(ULP_waitExecute select 0 select 0) >= diag_tickTime
	}) exitWith {};

	private _exec = (ULP_waitExecute deleteAt 0);
	(_exec select 1) call (_exec select 2);
};

{
	ULP_waitUntilExecute deleteAt (ULP_waitUntilExecute find _x);
	(_x select 1) call (_x select 2);

    nil
} count + (ULP_waitUntilExecute select {
	(_x select 1) call (_x select 0)
});