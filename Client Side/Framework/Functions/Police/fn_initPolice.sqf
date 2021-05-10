/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_initPolice";

["Initialising Police Related Events"] call ULP_fnc_logIt;

["TicketPaid", {
	_this params [
		["_name", "", [""]],
		["_amount", 0, [0]],
		["_paid", false, [true]]
	];

	if (_name isEqualTo "" || { _amount < 0 }) exitWith {};

	if (_paid) then {
		[format ["%1 has paid their penalty notice of %2%3", _name, "£", [_amount] call ULP_fnc_numberText]] call ULP_fnc_hint;
		[round (_amount / 2), true, format ["%1's Fine", _name]] call ULP_fnc_addMoney;
	} else {
		[format ["<t color='#B92DE0'>%1</t> has refused to or couldn't pay their penalty notice..."]] call ULP_fnc_hint;
	};
}] call ULP_fnc_addEventHandler;

["TicketRecieved", {
	_this params [
		["_unit", objNull, [objNull]],
		["_amount", 0, [0]]
	];

	if (isNull _unit || { _amount < 0 }) exitWith {};

	[
		(findDisplay getNumber(configFile >> "RscDisplayMission" >> "idd")), "Penalty Notice", ["Pay", "Refuse"],
		format ["%1 has issued you a penalty notice of %2%3", [_unit, true] call ULP_fnc_getName, "£", [_amount] call ULP_fnc_numberText], [_unit, _amount],
		{	
			_this params [ "_unit", "_amount" ];

			if (isNull _unit) exitWith {};

			private _name = [player, true] call ULP_fnc_getName;

			if ([_amount, true, "Penalty Notice"] call ULP_fnc_removeMoney) then {
				[format ["You have paid the fixed penalty notice of <t color='#B92DE0'>%1%2</t>", "£", [_amount] call ULP_fnc_numberText]] call ULP_fnc_hint;
				["TicketPaid", [_name, _amount, true]] remoteExecCall ["ULP_fnc_invokeEvent", _unit];
				["FinePaid", [_name, format ["%1%2", "£", [_amount] call ULP_fnc_numberText]]] remoteExecCall ["ULP_fnc_chatMessage", RCLIENT];
			} else {
				["You don't have enough money to pay this penalty notice..."] call ULP_fnc_hint;
				["TicketPaid", [_name, _amount, false]] remoteExecCall ["ULP_fnc_invokeEvent", _unit];
				["FinePoor", [_name, format ["%1%2", "£", [_amount] call ULP_fnc_numberText]]] remoteExecCall ["ULP_fnc_chatMessage", RCLIENT];
			};
		}, {
			_this params [ "_unit", "_amount" ];

			if (isNull _unit) exitWith {};
			
			private _name = [player, true] call ULP_fnc_getName;

			["TicketPaid", [_name, _amount, false]] remoteExecCall ["ULP_fnc_invokeEvent", _unit];
			["FineRefused", [_name, format ["%1%2", "£", [_amount] call ULP_fnc_numberText]]] remoteExecCall ["ULP_fnc_chatMessage", RCLIENT];
		}, false
	] call ULP_fnc_confirm;
}] call ULP_fnc_addEventHandler;