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
private _captureRadius = getNumber (_location >> "captureRadius");
private _radius = getNumber (_location >> "radius");

private _isSyndicate = [getNumber (_cfg >> "SyndicateChance")] call ULP_fnc_chance && { call compile getText (_cfg >> "SyndicateCondition") };
private _popupName = (["Popup Cartel", "Popup Syndicate"] select (_isSyndicate));

private _area = createMarker [format["redzone_%1_capture_popup_cartel_area_%2", (["popup", "syndicate"] select (_isSyndicate)), time], _pos];
_area setMarkerShape "Ellipse";
_area setMarkerColor "ColorYellow";
_area setMarkerSize [_radius, _radius];
_area setMarkerBrush "FDIAGONAL";

private _captureArea = createMarker [format["capture_popup_cartel_area_%1", time], _pos];
_captureArea setMarkerShape "Ellipse";
_captureArea setMarkerColor "ColorYellow";
_captureArea setMarkerSize [_captureRadius, _captureRadius];
_captureArea setMarkerBrush "BDiagonal";

private _marker = createMarker [format["popup_cartel_marker_%1", time], _pos];
_marker setMarkerType "mil_warning";
_marker setMarkerColor "ColorRed";
_marker setMarkerSize [0.5, 0.5];
_marker setMarkerText _popupName;

private _obj = createSimpleObject ["A3\Weapons_f\empty.p3d", _pos, false];
_obj setVariable ["area", _captureArea, true];

["OnSpawnPopupCartel", [
	_obj, _captureRadius, format["<t color='#ff0000' size='1.5px'>%1<br/></t><t color='#ffffff' size='1px'>The %1 capture zone has spawned! The location has been marked on your map.", _popupName]
]] remoteExecCall ["ULP_fnc_invokeEvent", -2, "PopupCartelSpawn"];

private _endTime = time + getNumber(missionConfigFile >> "CfgCartels" >> "Popup" >> "duration");

[ { isNull (_this select 0) 
	|| { !(isNil { (_this select 0) getVariable "popup_winner" }) } 
	|| { time >= (_this select 6) && { ([(_this select 2), allPlayers, ["Police", "Civilian"]] call ULP_fnc_unitsInZone) isEqualTo [] } } },
	 [_obj, _marker, _area, _captureArea, _popupName, _isSyndicate, _endTime, _shouldLoop], {
	_this params [ "_obj", "_marker", "_area", "_captureArea", "_popupName", "_isSyndicate", "", "_shouldLoop" ];

	remoteExecCall ["", "PopupCartelSpawn"];

	private _winner = _obj getVariable ["popup_winner", objNull];
	private _hasWinner = !(isNull _winner);

	private _message = format ["<t color='#ff0000' size='1.5px'>%1<br/></t><t color='#ffffff' size='1px'>The %1 was not captured and despawned, a new one will appear soon!", _popupName];

	private _units = [];

	if (_hasWinner) then {
		(getArray (missionConfigFile >> "CfgCartels" >> "Popup"  >> "reward")) params ["_base", "_random" ];

		private _totalReward = _base + (random _random);

		if (_isSyndicate) then {
			_totalReward = _totalReward * 3;
		};

		private _units = (units (group _winner)) inAreaArray _area;
		private _reward = floor(_totalReward / (count _units));

		private _name = [_winner] call ULP_fnc_getName;

		[group _winner, "Popup"] call ULP_SRV_fnc_addGroupXP;

		["OnClaimedPopupCartel", [
			format["<t color='#ff0000' size='1.5px'>%1<br/></t><t color='#ffffff' size='1px'>The %1 has been captured by %2 and you've recieved <t color='#B92DE0'>%3%4</t>, a new one will appear soon!", _popupName, _name, "£", [_reward] call ULP_fnc_numberText],
			_reward
		]] remoteExecCall ["ULP_fnc_invokeEvent", _units];

		_message = format["<t color='#ff0000' size='1.5px'>%1<br/></t><t color='#ffffff' size='1px'>The %1 has been captured by %2, a new one will appear soon!", _popupName, _name];
	};

	["OnClaimedPopupCartel", [ _message ]] remoteExecCall ["ULP_fnc_invokeEvent", allUnits select { isPlayer _x && { !(_x in _units) } }];
	
	deleteMarker _marker;
	deleteMarker _captureArea;
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