/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "\life_server\script_macros.hpp"
scopeName "fn_territoriesTick";

if (ULP_Territories isEqualTo []) exitWith {};

private _tickDelay = getNumber (missionConfigFile >> "CfgTerritories" >> "tickTime");

missionNamespace setVariable ["ULP_SRV_TerritoriesNextTime", serverTime + _tickDelay, true];

[ _tickDelay, [] , {

	{
		private _sites = _x getVariable ["sites", []];

		{
			private _cfg = _x getVariable ["SiteCfg", configNull];

			private _items = getArray (_cfg >> "items");
			private _item = selectRandom _items;

			private _amount = round ([] call compile getText (_cfg >> "amount"));

			[_x, _item, _amount] call ULP_fnc_addToCargo;
		} forEach _sites;

		nil
	} count ULP_Territories;

	[] call ULP_SRV_fnc_territoriesTick; // Restart tick...
}] call ULP_fnc_waitExecute;