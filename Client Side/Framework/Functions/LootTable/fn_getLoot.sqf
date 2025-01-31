/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_getLoot";

_this params [
	["_table", "", [""]],
	["_lootToAdd", 5, [0]]
];

private _ret = createHashMap;

private _cfg = missionConfigFile >> "CfgLoot" >> _table;
if !(isClass _cfg) exitWith { _ret };

private _lootTable = ("isClass _x" configClasses _cfg);

for "_i" from 1 to _lootToAdd do {
	private _chance = random 1;
	private _loot = _lootTable param [_lootTable findIf { getNumber (_x >> "chance") <= _chance }, configNull];

	if !(isNull _loot) then {

		{
			private _cfgName = configName _x;
			private _data = getNumber (_x >> "amount");

			private _type = switch (true) do {
				case (isClass (missionConfigFile >> "CfgVirtualItems" >> _cfgName)): { "VirtualItem" };
				case (isClass (configFile >> "CfgWeapons" >> _cfgName)): { "Weapon" };
				case (isClass (configFile >> "CfgMagazines" >> _cfgName)): { "Magazine" };
				case (isClass (configFile >> "CfgVehicles" >> _cfgName)): {
					([
						(["Texture", "Vehicle"] select (_data > 0)), 
						"Backpack"
					] select ([getNumber (configFile >> "CfgVehicles" >> _cfgName >> "isBackpack")] call ULP_fnc_bool))
				};
				default { "" };
			};

			if !(_type isEqualTo "") then {
				if (_type in ["Texture", "Vehicle"]) then {
					_data = [[_data, getText (_x >> "texture")]];
				};

				if (_type in _ret) then {
					private _lootType = _ret get _type;
					private _curLoot = _lootType getOrDefault [_cfgName, 0];

					if (_data isEqualType 0) then {
						_curLoot = _curLoot + _data;
					} else {
						_curLoot append _data;
					};

					_lootType set [_cfgName, _curLoot];
				} else {
					_ret set [_type, (createHashMapFromArray [[_cfgName, _data]])];
				};
			};
		} forEach ("isClass _x" configClasses _loot);
	};
};

_ret