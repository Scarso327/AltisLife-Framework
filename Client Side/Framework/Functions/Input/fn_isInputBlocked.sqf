/*
** Author: Jack "Scarso" Farhall
** Description:
*/
#include "..\..\script_macros.hpp"
scopeName "fn_isInputBlocked";

(!alive player
	|| { [] call ULP_fnc_isRestrained }
	|| { [] call ULP_fnc_isSurrendered }
	|| { [] call ULP_fnc_isKnocked }
	|| { isDowned(player) })