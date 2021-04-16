/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_hint";

if (canSuspend) exitWith {
    [ULP_fnc_hint, _this] call ULP_fnc_directCall;
};

_this params [
	["_text", "", [""]],
	["_header", "", [""]]
];

private _display = findDisplay 46;
if (_message isEqualTo "" || { isNull _display }) exitWith { false };

private _message = _display ctrlCreate [(["ULP_Notification", "ULP_NotificationNoHeader"] select (_header isEqualTo "")), -1];
private _ctrlText = _message controlsGroupCtrl 102;
_ctrlText ctrlSetStructuredText parseText _text;

private _height = ctrlTextHeight _ctrlText;

if !(_header isEqualTo "") then {
	_height = _height + ((ctrlPosition (_message controlsGroupCtrl 101)) select 1);
	(_message controlsGroupCtrl 101) ctrlSetStructuredText parseText _header;
};

_ctrlText ctrlSetPositionH (ctrlTextHeight _ctrlText);
_ctrlText ctrlCommit 0;
_message ctrlSetPositionH _height;
_message ctrlSetPositionY (0.5 * safeZoneH + safeZoneY);
_message ctrlSetFade 1;
_message ctrlCommit 0;

if (isNil "ULP_Messages") then { ULP_Messages = []; ULP_MessageAnimating = false; };

[{ !ULP_MessageAnimating }, [_message], {
	ULP_MessageAnimating = true;

	_this params [ "_message" ];
	private _previous = ctrlPosition (ULP_Messages param [(((count ULP_Messages) - 1) max 0), controlNull]);
	private _yPos = ([(0.09 * safeZoneH + safeZoneY), ((_previous select 1) + ((_previous select 3) + (0.0055 * safezoneH)))] select ((_previous select 0) > 0));

	_message ctrlSetPositionY _yPos;
	_message ctrlSetFade 0;
	_message ctrlCommit 0.3;

	[{ (((ctrlPosition (_this select 0)) select 1) isEqualTo (_this select 1)) }, [_message, _yPos], {
		ULP_MessageAnimating = false;

		_this params [ "_message" ];

		ULP_Messages pushBack _message;

		[{ (((ctrlPosition (_this select 0)) select 1) isEqualTo (0.09 * safeZoneH + safeZoneY)) }, [_message], {
			[5, [_this select 0], {
				_this params [ "_message" ];

				_message ctrlSetFade 1;
				_message ctrlCommit 0.2;

				[{ (ctrlFade (_this select 0)) isEqualTo 1 }, [_message], {
					ctrlDelete (_this select 0);

					{
						private _previous = ctrlPosition (ULP_Messages param [((_forEachIndex - 1) max 0), controlNull]);
						private _yPos = ([(0.09 * safeZoneH + safeZoneY), ((_previous select 1) + ((_previous select 3) + (0.0055 * safezoneH)))] select ((_previous select 0) > 0));

						_x ctrlSetPositionY _yPos;
						_x ctrlCommit 0;
					} forEach ULP_Messages;
				}] call ULP_fnc_waitUntilExecute;
			}] call ULP_fnc_waitExecute;
		}] call ULP_fnc_waitUntilExecute;
	}] call ULP_fnc_waitUntilExecute;
}] call ULP_fnc_waitUntilExecute;