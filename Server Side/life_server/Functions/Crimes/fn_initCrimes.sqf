/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "\life_server\script_macros.hpp"
scopeName "fn_initCrimes";

["Setting Up Crimes..."] call ULP_fnc_logIt;

ULP_SRV_Crimes = createHashMap;

{
	private _crimeInfo = createHashMap;
	private _buildings = [];
	private _vaults = [];

	{
        private _building = nearestObject [getArray (_x >> "position"), getText (_x >> "classname")];

		if !(isNull _building) then {
			if (isClass (missionConfigFile >> "CfgHousing" >> "Houses" >> (typeOf _building))) then {
				_building setVariable ["blacklisted", true, true];
			};

			if (isClass (_x >> "BreakIn")) then {
				_building setVariable ["breakInConfig", (_x >> "BreakIn"), true];
			};

			{
				private _door = _forEachIndex + 1;
				_building animate [format["door_%1_rot", _door], 0];
				_building setVariable [format ["bis_disabled_Door_%1", _door], 1, true];
			} forEach ([_building] call ULP_fnc_getBuildingDoors);

			if (isArray (_x >> "vaults")) then {
				{
					_x params [ "_class", "_vector", "_perc" ];
					private _vault = [_class, [(getPos _building), 0]] call ULP_fnc_createSimpleObject;
					_vault setPosATL (_building modelToWorld _vector);
					_vault setDir (getDir _building);

					_vault setVariable ["locked", true, true];

					_vaults pushBack [_vault, _perc];
				} forEach getArray (_x >> "vaults");
					
				_building setVariable ["vaults", _vaults];
				_building setVariable ["block_boltcutter", true, true];
				_buildings pushBack _building;		
			};
			
			_building allowDamage false;
		};
    } forEach ("isClass _x" configClasses (_x >> "Buildings"));
		
	_crimeInfo set ["VaultBuildings", _buildings];
	_crimeInfo set ["Vaults", _vaults];
	ULP_SRV_Crimes set [configName _x, _crimeInfo];
} forEach ("isClass _x" configClasses (missionConfigFile >> "CfgCrimes" >> worldName));