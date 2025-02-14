/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\..\script_macros.hpp"
scopeName "fn_DialogMedicMap_OnMapDraw";

_this params [ "_map" ];

if (isNull _map) exitWith {};

private _display = ctrlParent _map;

_map drawIcon [
	"\A3\ui_f\data\map\vehicleicons\iconMan_ca.paa", 
	[player] call ULP_fnc_getTagColour, 
	getPosVisual player, 26, 26, getDirVisual player, 
	[player, false] call ULP_fnc_getName, 
	1, 0.06, 'RobotoCondensed', 'right'
];

private _incapacitatedPlayers = _display getVariable ["IncapacitatedPlayers", []];

{
	if (isNull _x) exitWith {};

	private _assignedMedic = _x getVariable ["AssignedMedic", objNull];
	private _colour = switch (true) do {
		case (_assignedMedic isEqualTo player): { [0, 0.901, 0.074, 0.7] };
		case (isNull _assignedMedic): { [0.9 , 0, 0, 0.7] };
		default { [0.85, 0.40, 0.7] };
	};
	private _pos = getPosVisual _x;
	private _dir = getDirVisual _x;

	_map drawIcon [
		"\a3\ui_f\data\IGUI\Cfg\simpleTasks\types\heal_ca.paa", _colour, _pos, 36, 36, _dir, [_x] call ULP_fnc_getName, 1, 0.06, 'RobotoCondensed', 'right'
	];

	_map drawIcon [
		"\a3\Data_f\clear_empty.paa", _colour, _pos, 36, 36, _dir, [(_x getVariable ["IncapacitatedBleedOutTime", serverTime + 10]) - serverTime, "MM:SS"] call BIS_fnc_secondsToString, 1, 0.06, 'RobotoCondensed', 'left'
	];

	if (player isEqualTo _assignedMedic) then {
		_map drawIcon [
			"\A3\ui_f\data\map\groupicons\selector_selectedMission_ca.paa", _colour, _pos, 48, 48, 0, "", 1
		];
	};
} forEach _incapacitatedPlayers;