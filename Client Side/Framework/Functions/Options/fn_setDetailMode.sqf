/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
scopeName "fn_setDetailMode";

private _optionValue = ["DetailMode", "General"] call ULP_fnc_getOption;

private _gridValue = switch (true) do {
	case (["redzone_"] call ULP_fnc_isUnitsInZone && { _optionValue isEqualTo 2 }): { 50 };
	case (_optionValue isEqualTo 0): { 3.125 };
	default { 25 };
};

setTerrainGrid _gridValue;