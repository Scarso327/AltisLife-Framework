/*
** Author: Jack "Scarso" Farhall
** Description: Basically just an eachFrame handler like arma's onEachFrame event but this allows everything to be put into one handler.
*/
scopeName "fn_addEachFrame";

_this params [
	["_params", []],
	["_function", {}, [{}]]
];

if (_function isEqualTo {}) exitWith { -1 };

(ULP_eachFrameEvents pushBack _this)