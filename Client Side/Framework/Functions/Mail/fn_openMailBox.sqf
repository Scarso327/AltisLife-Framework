/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_openMailBox";

_this params [
	["_trader", objNull, [objNull]]
];

if (createDialog "DialogMailBox") then {
	private _display = findDisplay 5300;
	if (isNull _display) exitWith {};

	private _list = _display displayCtrl 5303;
	lbClear _list;

	private _button = _display displayCtrl 5304;
	_button ctrlEnable false;

	_list lnbAddRow ["Retriving Mail...", "-", "-"];

	_display setVariable ["mail_received", (["MailReceived", {
		_this params [
			["_mail", [], [[]]]
		];

		private _display = findDisplay 5300;
		if (isNull _display) exitWith { [_event, _eventId] call ULP_fnc_removeEventHandler; };

		private _filter = _display displayCtrl 5302;
		private _list = _display displayCtrl 5303;
		lnbClear _list;

		[_filter, _list] call BIS_fnc_initListNBoxSorting;

		if (_mail isEqualTo []) exitWith {
			_list lnbAddRow ["No Mail...", "-", "-"];
		};

		private _button = _display displayCtrl 5304;
		_button ctrlEnable true;

		{
			_x params [ "_id", "", "_type", "_className", "_data", "_daysUntilExpiry" ];

			private _friendlyName = [_type, _className] call {
				scopeName "fn_getDisplayNameForMailBox";

				_this params ["_type", "_class"];

				switch (_type) do {
					case "VirtualItem": {
						getText(missionConfigFile >> "CfgVirtualItems" >> _class >> "displayName") breakOut "fn_getDisplayNameForMailBox";
					};
					case "Money": {
						_class breakOut "fn_getDisplayNameForMailBox";
					};
				};

				// All others should be handled via this
				[_className] call ULP_fnc_itemCfg param [5, _class];
			};

			private _quantity = switch (true) do {
				case (_data isEqualType []) : { [_data select 0] call ULP_fnc_numberText };
				case (_data isEqualType 0 && { _type isEqualTo "Money" }) : { format["%1%2", "£", [_data] call ULP_fnc_numberText] };
				case (_data isEqualType 0) : { [_data] call ULP_fnc_numberText };
				default { _data };
			};

			private _expiryText = if (_daysUntilExpiry isEqualTo "") then {
				"-"
			} else {
				[_daysUntilExpiry] call ULP_fnc_numberText
			};

			private _row = _list lnbAddRow [
				_friendlyName, 
				[_quantity, "-"] select (_quantity isEqualTo 0 || { _quantity isEqualTo "0" }),
				_expiryText
			];

			_list lnbSetData [[_row, 0], str [ _id, _type, _className, _data ]];
		} forEach _mail;
	}] call ULP_fnc_addEventHandler)];

	[getPlayerUID player] remoteExecCall ["ULP_SRV_fnc_getMail", RSERV];
};