/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\..\script_macros.hpp"
scopeName "fn_onVehicleEngine";

_this params [
	["_vehicle", objNull, [objNull]],
	["_engineOn", false, [true]]
];

if (local _vehicle && { _engineOn }) then {
	private _clamp = _vehicle getVariable ["clamp_fine", []];

	if !(_clamp isEqualTo []) then {
		_vehicle engineOn false;

		_clamp params [ "_finer", "_steamid", "_fine" ];

		if (CASH < _fine) exitWith {
			if (time >= _vehicle getVariable ["clamp_notify", 0]) then {
				[format ["Your vehicle has been clamped by %1 and you can't afford the %2%3 fine...", _finer, "£", [_fine] call ULP_fnc_numberText]] call ULP_fnc_hint;
			};
			_vehicle setVariable ["clamp_notify", time + 3];
		};

		[
			(findDisplay getNumber(configFile >> "RscDisplayMission" >> "idd")), "Vehicle Fine", ["Pay", "Cancel"],
			format ["%1 has clamped your vehicle and given you a fine of %2%3", _finer, "£", [_fine] call ULP_fnc_numberText], [_vehicle, _fine, _steamid],
			{	
				_this params [ "_vehicle", "_fine", "_steamid" ];

				if ([_fine, false, "Vehicle Fine"] call ULP_fnc_removeMoney) then {
					_vehicle engineOn true;
					_vehicle setVariable ["clamp_fine", nil, true];

					[format ["You have paid the fine of %1%2 and your vehicle has had the clamp removed...", "£", [_fine] call ULP_fnc_numberText]] call ULP_fnc_hint;

					private _unit = [_steamid] call ULP_fnc_playerByUID;
					if (!(isNull _unit) && { [player, ["Police", "Hato"]] call ULP_fnc_isFaction }) then {
						["ClampFinePaid", [profileName, _vehicle, _fine]] remoteExecCall ["ULP_fnc_invokeEvent", _unit];
					};
				} else {
					["You don't have enough money on you to pay the fine..."] call ULP_fnc_hint;
				};
			}, false, {}
		] call ULP_fnc_confirm;
	};
};