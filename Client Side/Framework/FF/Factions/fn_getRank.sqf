/*
    @File: fn_getRank.sqf

    @Author: Jack "Scarso" Farhall

    @Description: Returns an array with the rank title and icon...
*/
#include "..\..\script_macros.hpp"

private _return = ["", ""];

_return = call {
	if(playerSide isEqualTo west) exitWith {
		switch (FETCH_CONST(life_coplevel)) do {
			case 2: {["Police Constable", "\a3\ui_f\data\gui\cfg\Ranks\corporal_gs.paa"]};
			case 3: {["Senior Police Constable", "\a3\ui_f\data\gui\cfg\Ranks\sergeant_gs.paa"]};
			case 4: {["Sergeant", "\a3\ui_f\data\gui\cfg\Ranks\lieutenant_gs.paa"]};
			case 5: {["Inspector", "\a3\ui_f\data\gui\cfg\Ranks\captain_gs.paa"]};
			case 6: {["Chief Inspector", "\a3\ui_f\data\gui\cfg\Ranks\major_gs.paa"]};
			case 7: {["Superintendent", "\a3\ui_f\data\gui\cfg\Ranks\colonel_gs.paa"]};
			case 8: {["Chief Superintendent", "\a3\ui_f\data\gui\cfg\Ranks\general_gs.paa"]};
			case 9: {["Deputy Chief Constable", "\a3\ui_f\data\gui\cfg\Ranks\general_gs.paa"]};
			case 10: {["Chief Constable", "\a3\ui_f\data\gui\cfg\Ranks\general_gs.paa"]};
			default {["Police Community Support Officer", "\a3\ui_f\data\gui\cfg\Ranks\private_gs.paa"]};
		};
	};
};

_return;