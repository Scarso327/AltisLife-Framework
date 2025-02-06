/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_preInitFactories";

["PowerRedirected", {
	_this params [
		["_location", objNull, [objNull]],
		["_unit", objNull, [objNull]],
		["_toName", "", [""]]
	];

	private _station = _location getVariable ["powerStation", ""];

	if (_siteName isEqualTo "" || { isNull _unit } || { _station isEqualTo "" }) exitWith {};

	[format [
		"<t color='#ff0000' size='1.5px'>Power Redirected<br/></t><t color='#ffffff' size='1px'><t color='#B92DE0'>%1</t> has redirected power to <t color='#B92DE0'>%2</t>.",
		name _unit, _toName
	]] call ULP_fnc_hint;
}] call ULP_fnc_addEventHandler;

["SiteNeutralised", {
	_this params [
		["_location", objNull, [objNull]],
		["_unit", objNull, [objNull]]
	];

	private _station = _location getVariable ["powerStation", ""];

	if (isNull _location || { _station isEqualTo "" } || { isNull _unit } || { !(player isEqualTo _unit) }) exitWith {};

	private _currentTarget = _location getVariable ["powering", objNull];
	private _stationCfg = missionConfigFile >> "CfgPowerStations" >> worldName >> _station;

	if (isNull _currentTarget || { !isClass _stationCfg }) exitWith {};

	[_currentTarget, - getNumber (_stationCfg >> "tier")] call ULP_fnc_setFactoryPower;
}] call ULP_fnc_addEventHandler;