/*
    @File: fn_getRank.sqf

    @Author: Jack "Scarso" Farhall

    @Description: Returns an array with the rank title and icon...
*/
#include "..\..\script_macros.hpp"

private _return = ["", ""];

if (!params [["_player", objNull, [objNull]]] || isNull _player) exitWith {_return;};

_return = call {
	if((side _player) isEqualTo west) exitWith {
		switch (_player getVariable ["rank", 0]) do {
			case 2: {["Police Constable", INSIGNIA("police\PC.paa")]};
			case 3: {["Senior Police Constable", INSIGNIA("police\SPC.paa")]};
			case 4: {["Sergeant", INSIGNIA("police\SGT.paa")]};
			case 5: {["Inspector", INSIGNIA("police\INSP.paa")]};
			case 6: {["Chief Inspector", INSIGNIA("police\CINSP.paa")]};
			case 7: {["Superintendent", INSIGNIA("police\SUPT.paa")]};
			case 8: {["Chief Superintendent", INSIGNIA("police\CSUPT.paa")]};
			case 9: {["Deputy Commissioner", INSIGNIA("police\DCOMM.paa")]};
			case 10: {["Commissioner", INSIGNIA("police\COMM.paa")]};
			case 11: {["Commander", INSIGNIA("police\CMDR.paa")]};
			default {["Police Cadet", INSIGNIA("police\Cdt.paa")]};
		};
	};

	if((side _player) isEqualTo independent) exitWith {
		switch (_player getVariable ["rank", 0]) do {
			case 2: {["Nurse", "\a3\ui_f\data\gui\cfg\Ranks\corporal_gs.paa"]};
			case 3: {["Junior Doctor", "\a3\ui_f\data\gui\cfg\Ranks\corporal_gs.paa"]};
			case 4: {["General Practitioner", "\a3\ui_f\data\gui\cfg\Ranks\corporal_gs.paa"]};
			case 5: {["Emergency Doctor", "\a3\ui_f\data\gui\cfg\Ranks\corporal_gs.paa"]};
			case 6: {["Consultant", "\a3\ui_f\data\gui\cfg\Ranks\corporal_gs.paa"]};
			case 7: {["Regional Director", "\a3\ui_f\data\gui\cfg\Ranks\corporal_gs.paa"]};
			default {["Medical Student", "\a3\ui_f\data\gui\cfg\Ranks\private_gs.paa"]};
		};
	};
};

_return;