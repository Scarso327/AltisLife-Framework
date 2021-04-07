/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "\life_server\script_macros.hpp"
scopeName "fn_initBases";

private _hour = _this;

["Initialising Group Bases..."] call ULP_fnc_logIt;

private _hours = getArray (missionConfigFile >> "CfgBases" >> "Restart");
if (([] call ULP_SRV_fnc_getDayName) isEqualTo getText (missionConfigFile >> "CfgBases" >> "Day") && { _hour >= (_hours select 0) } && { _hour < (_hours select 1) }) then {
	missionNamespace setVariable ["ULP_SRV_BaseBidding", true, true];	
};

{
	(getArray (_x >> "position")) params [ "_pos", "_dir" ];

	private _owner = -1;

	if ([getNumber (_x >> "includeBidding")] call ULP_fnc_bool) then {
		private _query = [format ["SELECT value FROM settings WHERE setting = 'base_owner_%1'", configName _x], 2] call DB_fnc_asyncCall;
		_query params [
			["_queryOwner", -2, [0, ""]]
		];

		if (_queryOwner isEqualTo -2) then {
			// Insert...
			[format ["INSERT INTO settings (setting, value) VALUES ('base_owner_%1', '-1');",  configName _x], 1] call DB_fnc_asyncCall;
		} else {
			if (missionNamespace getVariable ["ULP_SRV_BaseBidding", false]) then {
				[format ["UPDATE settings SET value = '-1' WHERE setting = 'base_owner_%1'",  configName _x], 1] call DB_fnc_asyncCall;
			} else {
				if (_queryOwner isEqualType "") then { _queryOwner = parseNumber _queryOwner; };
				_owner = _queryOwner;
			};
		};
	};

	private _flag = createVehicle ["Flag_Syndikat_F", _pos, [], 0, "CAN_COLLIDE"];
	_flag setDir _dir;
	_flag allowDamage false;
	_flag enableDynamicSimulation true;
	
	_flag setVariable ["cfg", _x, true];
	_flag setVariable ["owner", _owner, true];

	missionNamespace setVariable [format ["ULP_SRV_Base_%1", configName _x], _flag, true];
} forEach ("isClass _x" configClasses (missionConfigFile >> "CfgBases"));