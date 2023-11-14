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

	private _list = _display displayCtrl 5302;
	lbClear _list;

	private _button = _display displayCtrl 5303;
	_button ctrlEnable false;

	_list lbAdd "Retriving Mail...";

	_display setVariable ["mail_received", (["MailReceived", {
		_this params [
			["_mail", [], [[]]]
		];

		private _display = findDisplay 5300;
		if (isNull _display) exitWith { [_event, _eventId] call ULP_fnc_removeEventHandler; };
		
		private _list = _display displayCtrl 5302;
		lbClear _list;

		if ((count _mail) isEqualTo 0) exitWith {
			_list lbAdd "No Mail...";
		};

		private _button = _display displayCtrl 5303;
		_button ctrlEnable true;

		{
			_x params [ "_id", "", "_type", "_className", "_data" ];

			// We make the assumption all data is correct here
			// TODO: Maybe add handling just in case?
			private _friendlyName = [_type, _className] call {
				scopeName "fn_getDisplayNameForMailBox";

				_this params ["_type", "_class"];

				switch (_type) do {
					case "VirtualItem": {
						getText(missionConfigFile >> "CfgVirtualItems" >> _class >> "displayName") breakOut "fn_getDisplayNameForMailBox";
					};
				};

				// All others should be handled via this
				[_className] call ULP_fnc_itemCfg param [5, _class];
			};

			private _title = format ["%1 %2", _friendlyName, (switch (true) do {
				case (_data isEqualType []) : { 
					_data params [ "_amount", "_textureClass" ];

					// More assumption here is correct here, refer line 46
					private _textureName = getText(missionConfigFile >> "CfgVehicles" >> _className >> "textures" >> _textureClass >> "displayName");

					format[["[%2] x %1", "[%2] (Texture Unlock)"] select (_amount isEqualTo 0), _amount, _textureName]
				};
				case (_data isEqualType 0) : { format["x %1", _data] };
				default { _data };
			})];

			private _item = _list lbAdd _title;
			_list lbSetData [_item, str [ _id, _type, _className, _data ]];
			_list lbSetTooltip [_item, _title];
		} forEach _mail;
	}] call ULP_fnc_addEventHandler)];

	[getPlayerUID player] remoteExecCall ["ULP_SRV_fnc_getMail", RSERV];
};