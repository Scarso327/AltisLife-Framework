/*
** Author: Jack "Scarso" Farhall
** Description: 
** Note: Probably should've create seperate pages for these two, didn't realise how much was going to be toggled, maybe do this later? TODO
*/
#include "..\..\..\script_macros.hpp"
scopeName "fn_messages";

_display = _this;
if (isNull _display) exitWith {};

_display setVariable ["preScreen", "Home"];

private _toolbox = _display displayCtrl 23036;
private _edit = _display displayCtrl 23037;
private _contactList = _display displayCtrl 23038;
lbClear _contactList;

private _sendButton = _display displayCtrl 23039;
private _inboxMessage = _display displayCtrl 23040;
private _replyEdit = _display displayCtrl 23041;
private _replyPlaceholder = _display displayCtrl 23042;
private _msgPlaceholder = _display displayCtrl 23043;
private _msgBackground = _display displayCtrl 23044;
private _replyBackground = _display displayCtrl 23045;

// Edit placeholders...
if (isNull (_edit getVariable ["Placeholder", controlNull])) then { [_edit, _msgPlaceholder] call ULP_UI_fnc_placeholder; };
if (isNull (_replyEdit getVariable ["Placeholder", controlNull])) then { [_replyEdit, _replyPlaceholder] call ULP_UI_fnc_placeholder; };

private _inboxHeader = _display displayCtrl 23046;
private _inboxHeaderBackground = _display displayCtrl 23047;
private _inboxList = _display displayCtrl 23048;
lnbClear _inboxList;

private _inboxListBackground = _display displayCtrl 23049;

if !(_inboxHeader getVariable ["setup", false]) then {
	[_inboxHeader, _inboxList, [0, 1, 2]] call BIS_fnc_initListNBoxSorting;
	_inboxHeader getVariable ["setup", true];
};

private _deleteButton = _display displayCtrl 23050;

switch (lbCurSel _toolbox) do {
	case 1: {
		_sendButton ctrlSetStructuredText parseText "<t align = 'center'>Reply</t>";
		_sendButton ctrlSetEventHandler ["ButtonClick", "_this call ULP_fnc_replyMessage;"];

		_contactList ctrlShow false;
		_edit ctrlShow false;
		_msgBackground ctrlShow false;
		_msgPlaceholder ctrlShow false;
		_inboxMessage ctrlShow true;
		_replyEdit ctrlShow true;
		_replyBackground ctrlShow true;
		_replyPlaceholder ctrlShow ((count (ctrlText _replyEdit)) <= 0);
		_inboxHeader ctrlShow true;
		_inboxHeaderBackground ctrlShow true;
		_inboxList ctrlShow true;
		_inboxListBackground ctrlShow true;
		_deleteButton ctrlShow true;

		{
			_x params ["_type", "_sender", "_message", ["_read", false, [true]]];

			private _cfg = missionConfigFile >> "CfgMessages" >> _type;
			if (isClass _cfg) then {
				_sender params [
					["_sender", "", [""]]
				];

				private _row = _inboxList lnbAddRow [ getText (_cfg >> "displayName"), _sender, "" ];

				_inboxList lnbSetValue [[_row, 0], _forEachIndex];
				_inboxList lnbSetData [[_row, 1], _sender];
				_inboxList lnbSetValue[[_row, 2], parseNumber _read];
				_inboxList lnbSetPicture [[_row, 2], format["\a3\3DEN\Data\Controls\ctrlCheckbox\%1_ca.paa", (["textureUnchecked", "textureChecked"] select (_read))]];
			};
		} forEach + (profileNamespace getVariable ["ULP_Messages", []]);

		if ((lbSize _inboxList) > 0) then {
			_inboxList lbSetCurSel 0;
			[_inboxList, 0] call ULP_fnc_inbox;
		} else {
			_inboxMessage ctrlSetText "";
			_inboxList lnbAddRow ["No Messages...", "", ""];
		};

		if ((_display getVariable ["MessageRecievedEvent", -1]) isEqualTo -1) then {
			["MessageReceived", {
				private _display = findDisplay 23000;
				if (isNull _display && { !((lbCUrSel (_display displayCtrl 23036)) isEqualTo 1) }) exitWith {
					[_event, _eventId] call ULP_fnc_removeEventHandler;
				};

				_display call ULP_fnc_messages;
			}] call ULP_fnc_addEventHandler;
		};
	};
	default {
		_sendButton ctrlSetStructuredText parseText "<t align = 'center'>Send Message</t>";
		_sendButton ctrlSetEventHandler ["ButtonClick", "_this call ULP_fnc_sendByType;"];

		_contactList ctrlShow true;
		_edit ctrlShow true;
		_msgBackground ctrlShow true;
		_msgPlaceholder ctrlShow ((count (ctrlText _edit)) <= 0);
		_inboxMessage ctrlShow false;
		_replyEdit ctrlShow false;
		_replyBackground ctrlShow false;
		_replyPlaceholder ctrlShow false;
		_inboxHeader ctrlShow false;
		_inboxHeaderBackground ctrlShow false;
		_inboxList ctrlShow false;
		_inboxListBackground ctrlShow false;
		_deleteButton ctrlShow false;
		
		{
			private _item = _contactList lbAdd getText (_x >> "displayName");
			_contactList lbSetData [_item, configName _x];

			private _picture = getText (_x >> "picture");
			if !(_picture isEqualTo "") then { _contactList lbSetPicture [_item, _picture]; };
			if (isText (_x >> "tooltip")) then { _contactList lbSetTooltip [_item, getText (_x >> "tooltip")]; };
		} forEach ("call compile getText (_x >> ""condition"")" configClasses (missionConfigFile >> "CfgMessages"));

		if ((lbSize _contactList) > 0) then {
			_contactList lbSetCurSel 0;
		} else {
			_contactList lbAdd "No Contacts...";
		};

		if !((_display getVariable ["MessageRecievedEvent", -1]) isEqualTo -1) then {
			["MessageReceived", (_display getVariable ["MessageRecievedEvent", -1])] call ULP_fnc_removeEventHandler;
		};
	};
};

// Toggle created toggle buttons...
for "_i" from 200 to 202 do { (_display displayCtrl _i) ctrlShow (ctrlShown _inboxHeader); };