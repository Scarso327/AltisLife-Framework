/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "\life_server\script_macros.hpp"
scopeName "fn_toggleVaults";

_this params [
	["_crime", "", [""]],
	["_state", 0, [0]],
	["_overrideVault", objNull, [objNull]]
];

private _cfg = missionConfigFile >> "CfgCrimes" >> worldName >> _crime;
if !(isClass _cfg) exitWith { false };

private _info = ULP_SRV_Crimes getOrDefault [_crime, createHashMap];
if ((count _info) < 1) exitWith { false };

private _loot = [];
if (_state isEqualTo 1) then {
	{
		_loot pushBack [configName _x, round (getNumber (_x >> "amount") + (call compile getText (_x >> "extra")))];
	} forEach ("isClass _x" configClasses (_cfg >> "Items"));

	missionNamespace setVariable [format ["ULP_SRV_Crime_%1", _crime], true, true];
} else {
	missionNamespace setVariable [format ["ULP_SRV_Crime_%1", _crime], nil, true];
};

diag_log _this;
diag_log _loot;

if (isNull _overrideVault) then {
	{
		private _building = _x;

		{
			_building animate [format["door_%1_rot", _forEachIndex + 1], _state];
		} forEach ([_building] call ULP_fnc_getBuildingDoors);

		private _vaults = _building getVariable ["vaults", []];

		// Populate or remove loot...
		if !(_vaults isEqualTo []) then {
			{
				_x params [ "_vault", "_perc" ];

				if (_loot isEqualTo []) then {
					_vault setVariable ["ULP_VirtualCargo", nil, true];
					_vault setVariable ["locked", true, true];
				} else {
					private _items = [];

					{
						_x params [ "_item", "_amount" ];
						_items pushBack [_item, round (_amount * _perc)];
					} forEach _loot;

					_vault setVariable ["locked", nil, true];

					_vault setVariable ["ULP_VirtualCargo", (createHashMapFromArray _items), true];
				};
			} forEach _vaults;
		};
	} forEach (_info get "VaultBuildings");
} else {
	if (_loot isEqualTo []) then {
		_overrideVault setVariable ["ULP_VirtualCargo", nil, true];
		_overrideVault setVariable ["locked", true, true];
	} else {
		_overrideVault setVariable ["ULP_VirtualCargo", (createHashMapFromArray _loot), true];
		_overrideVault setVariable ["locked", nil, true];
	};
};

true