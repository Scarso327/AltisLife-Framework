/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\..\script_macros.hpp"
scopeName "fn_switchHouse";

_this params [
	["_list", controlNull, [controlNull]],
	["_index", -1, [0]]
];

private _display = ctrlParent _list;
if (isNull _display) exitWith {};

private _houseView = _display displayCtrl 23052;

private _house = (_list lbData _index) call BIS_fnc_objectFromNetId;
if (isNull _player) exitWith { _houseView ctrlShow false; };
if !(ctrlShown _houseView) then { _houseView ctrlShow true; };

private _shareButton = (_houseView controlsGroupCtrl 101) controlsGroupCtrl 102;
_shareButton ctrlSetStructuredText parseText format["<t align = 'center'>%1</t>", [
	"Share",
	"Unshare"
] select ([_house] call ULP_fnc_isHouseShared)];
_shareButton setVariable ["house", _house];