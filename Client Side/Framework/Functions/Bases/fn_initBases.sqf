/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_initBases";

if (missionNamespace getVariable ["ULP_SRV_Setting_BaseBidsActive", false]) then {
	["Initialising Base Bidding..."] call ULP_fnc_logIt;

	["BaseAwarded", {
		_this params [
			["_baseCfgName", "", [""]],
			["_groupTag", "", [""]]
		];

		if (_baseCfgName isEqualTo "" || { _groupTag isEqualTo "" }) exitWith {};

		private _flag = missionNamespace getVariable [format ["ULP_SRV_Base_%1", _baseCfgName], objNull];

		if (isNull _flag) exitWith {};
		
		private _actionId = _flag getVariable ["bidAction", -1];
		if !(_actionId isEqualTo -1) then { _flag removeAction _actionId; };

		[format [
			"<t color='#ff0000' size='1.5px'>Gang Wars<br/></t><t color='#ffffff' size='1px'><t color='#B92DE0'>%1</t> has won the <t color='#B92DE0'>%2</t> Gang Base.",
			_groupTag, _baseCfgName
		]] call ULP_fnc_hint;
	}] call ULP_fnc_addEventHandler;

	if ([player, ["Civilian"]] call ULP_fnc_isFaction) then {
		{
			private _flag = missionNamespace getVariable [format ["ULP_SRV_Base_%1", configName _x], objNull];

			if !(isNull _flag) then {
				private _bidAction = _flag addAction [format["Bid on %1", getText (_x >> "displayName")], { [(_this select 3)] call ULP_fnc_placeBid }, configName _x, 1.25, true, true, "", "true", 3];
				_flag setVariable ["bidAction", _bidAction];
			};
		} forEach ("[getNumber (_x >> ""includeBidding"")] call ULP_fnc_bool" configClasses (missionConfigFile >> "CfgBases"));

		["KilledSomeone", {
			_this params [
				["_unit", objNull, [objNull]]
			];

			if (isNull _unit 
				|| { !(["redzone_"] call ULP_fnc_isUnitsInZone) } 
				|| { [group player, _unit] call ULP_fnc_inGroup }
				|| { !(missionNamespace getVariable ["ULP_SRV_Setting_BaseBidsActive", false]) }) exitWith {};

			private _reward = getNumber (missionConfigFile >> "CfgBases" >> "RedzoneKillReward");

			[5, "Redzone Kill"] call ULP_fnc_addXP;

			if ([_reward, true, "Gang Wars Kill"] call ULP_fnc_addMoney) then {
				[format ["You have recieved <t color='#B92DE0'>%1%2</t> for killing someone in a redzone during gang wars...", "£", [_reward] call ULP_fnc_numberText]] call ULP_fnc_hint;
			};
		}] call ULP_fnc_addEventHandler;
	};
};