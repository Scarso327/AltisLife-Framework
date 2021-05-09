/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_selectPlayer";

_this params [
	["_parent", displayNull, [displayNull]],
	["_factions", [], [[]]],
	["_params", [], [[]]],
	["_onSelect", {}, [{}]],
	["_self", false, [true]],
	["_tablet", true, [false]],
	["_condition", { true }, [{}]]
];

if (isNull _parent) exitWith {};

private _display = _parent createDisplay "DisplaySelectPlayer";

(_display displayCtrl 3807) ctrlShow _tablet;
(_display displayCtrl 3808) ctrlShow !_tablet;

private _tree = _display displayCtrl 3809;

{
	private _cfg = missionConfigFile >> "CfgFactions" >> _x;
	if (isClass _cfg) then {
		private _parent = _tree tvAdd [[], getText(_cfg >> "displayName")];
		_tree tvSetPicture [[_parent], "\a3\ui_f_curator\data\Displays\RscDisplayCurator\side_west_ca.paa"];
		_tree tvSetPictureColor [[_parent], getArray(_cfg >> "colour")];

		{
			if (_self || { !(_x isEqualTo player) }) then {
				private _member = _tree tvAdd [[_parent], [_x] call ULP_fnc_getName];
				_tree tvSetData [[_parent, _member], _x call BIS_fnc_netId];
				_tree tvSetPicture [[_parent, _member], [getText(configFile >> "CfgVehicles" >> typeOf _x >> "icon")] call BIS_fnc_textureVehicleIcon];
				_tree tvSetPictureColor [[_parent, _member], getArray(_cfg >> "colour")];

				if !(_someoneAdded) then { _someoneAdded = true; };
			};
		} forEach ([_x, _condition] call ULP_fnc_allMembers);
	};
} forEach _factions;

if (_factions isEqualTo [] || { !_someoneAdded }) exitWith {
	["There is no one available to select..."] call ULP_fnc_hint;
	_display closeDisplay 0;
};

_display setVariable ["params", _params];
_display setVariable ["onSelect", _onSelect];