/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "\life_server\script_macros.hpp"
scopeName "fn_popupCartel";

_this params [
	["_cfg", configNull, [configNull]],
	["_shouldLoop", true, [false]]
];

if (isNull _cfg) exitWith { false };

private _location = selectRandom ("isClass _x" configClasses (_cfg >> "Locations"));
if (isNil "_location" || { _location isEqualTo [] }) exitWith { false };

private _pos = getArray (_location >> "position");
private _radius = getNumber (_location >> "radius");

private _area = createMarker [format["capture_popup_cartel_area_%1", time], _pos];
_area setMarkerShape "Ellipse";
_area setMarkerColor "ColorYellow";
_area setMarkerSize [_radius, _radius];
_area setMarkerBrush "FDIAGONAL";

private _marker = createMarker [format["redzone_popup_cartel_marker_%1", time], _pos];
_marker setMarkerType "mil_warning";
_marker setMarkerColor "ColorRed";
_marker setMarkerSize [0.5, 0.5];
_marker setMarkerText "Popup Cartel";

private _obj = createSimpleObject ["A3\Weapons_f\empty.p3d", _pos, false];
_obj setVariable ["area", _area, true];

["OnSpawnPopupCartel", [
	_obj, _radius, "<t color='#ff0000' size='1.5px'>Cartel<br/></t><t color='#ffffff' size='1px'>The cartel capture zone has spawned! The location has been marked on your map."
]] remoteExecCall ["ULP_fnc_invokeEvent", -2, "PopupCartelSpawn"];

private _endTime = time + getNumber(missionConfigFile >> "CfgCartels" >> "Popup" >> "duration");

[ { isNull (_this select 0) || { !(isNil { (_this select 0) getVariable "popup_winner" }) } || { time >= (_this select 3) } }, [_obj, _marker, _area, _endTime, _shouldLoop], {
	_this params [ "_obj", "_marker", "_area", "", "_shouldLoop" ];

	remoteExecCall ["", "PopupCartelSpawn"];

	private _winner = _obj getVariable ["popup_winner", objNull];
	private _hasWinner = !(isNull _winner);

	private _message = "<t color='#ff0000' size='1.5px'>Cartel<br/></t><t color='#ffffff' size='1px'>The cartel was not captured and despawned, a new one will appear soon!";

	private _units = [];

	if (_hasWinner) then {
		(getArray (missionConfigFile >> "CfgCartels" >> "Popup"  >> "reward")) params ["_base", "_random" ];

		private _totalReward = _base + (random _random);
		private _units = (units (group _winner)) inAreaArray _area;
		private _reward = floor(_totalReward / (count _units));

		private _name = [_winner] call ULP_fnc_getName;

		[group _winner, "Popup"] call ULP_SRV_fnc_addGroupXP;

		["OnClaimedPopupCartel", [
			format["<t color='#ff0000' size='1.5px'>Cartel<br/></t><t color='#ffffff' size='1px'>The cartel has been captured by %1 and you've recieved <t color='#B92DE0'>%2%3</t>, a new one will appear soon!", _name, "£", [_reward] call ULP_fnc_numberText],
			_reward
		]] remoteExecCall ["ULP_fnc_invokeEvent", _units];

		_message = format["<t color='#ff0000' size='1.5px'>Cartel<br/></t><t color='#ffffff' size='1px'>The cartel has been captured by %1, a new one will appear soon!", _name];
	};

	["OnClaimedPopupCartel", [ _message ]] remoteExecCall ["ULP_fnc_invokeEvent", allUnits select { isPlayer _x && { !(_x in _units) } }];
	
	deleteMarker _marker;
	deleteMarker _area;

	deleteVehicle _obj;

	if !(_shouldLoop) exitWith {};

	private _cfg = missionConfigFile >> "CfgRandomEvents" >> "PopupCartel";
	missionNamespace setVariable [format ["ULP_SRV_%1_Active", configName _cfg], nil, true];

	private _delay = getNumber ([_cfg, "Cooldown"] call ULP_SRV_fnc_getEventParam);
	_delay = _delay + (random getNumber ([_cfg, "RandomAddition"] call ULP_SRV_fnc_getEventParam));

	[_delay, _cfg, {
		_this call compile getText (_this >> "ServerFunctions" >> "onCompleted");
	}] call ULP_fnc_waitExecute
}] call ULP_fnc_waitUntilExecute;

true