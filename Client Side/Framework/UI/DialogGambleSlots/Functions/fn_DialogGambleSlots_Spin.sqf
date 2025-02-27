/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\..\script_macros.hpp"
#define ICON_ARRAY ["Data\UI\Gambling\lemon.paa", "Data\UI\Gambling\plum.paa", "Data\UI\Gambling\cherries.paa", "Data\UI\Gambling\watermelon.paa", "Data\UI\Gambling\bar.paa", "Data\UI\Gambling\seven.paa", "Data\UI\Gambling\diamond.paa"]
#define SANDWICH_BASE 800
#define NEIGHBOUR_BASE 1000
#define PRECEDING_BASE 2300
#define EQUAL_BASE 5000

scopeName "fn_DialogGambleSlots_Spin";

_this params [ "_button" ];

if (isNull _button) exitWith {};

_button ctrlEnable false;

private _display = ctrlParent _button;
if !(isNil { _display getVariable "spinsLeft" }) exitWith {};

[
	(findDisplay getNumber(configFile >> "RscDisplayMission" >> "idd")), [1000, 100000], [_display, _button],
	{
		_this params [
			["_display", displayNull, [displayNull]],
			["_button", controlNull, [controlNull]],
			"",
			["_bet", 1, [0]]
		];

		if (_bet > (BANK * 0.5)) exitWith {
			["You can't bet more than half your bank balance"] call ULP_fnc_hint;
		};

		if ([_bet, false, "Gambling Bet"] call ULP_fnc_removeMoney) then {
			_display setVariable ["eachFrame", ([[_display, _button, 30 + round(random 30), _bet], {
				_this params [ "_display", "_button", "_totalSpins", "_bet" ];

				if (isNull _display) exitWith {
					[_thisEventHandler] call ULP_fnc_removeEachFrame;
				};

				private _changeImage = {
					_this params [ "_ctrl", "_stop" ];

					if (_stop) exitWith {};

					private _selected = selectRandom (ICON_ARRAY - [_ctrl getVariable ["current", ""]]);
					_ctrl setVariable ["current", _selected];
					
					playSound "FD_Timer_F";

					_ctrl ctrlSetText _selected;
				};

				private _spins = _display getVariable ["spinsLeft", _totalSpins];

				private _slotOne = _display displayCtrl 5902;
				private _slotTwo = _display displayCtrl 5903;
				private _slotThree = _display displayCtrl 5904;

				[_slotOne, _spins <= ceil (_totalSpins / 1.5)] call _changeImage;
				[_slotTwo, _spins <= ceil (_totalSpins / 3)] call _changeImage;
				[_slotThree, _spins <= 0] call _changeImage;

				_spins = _spins - 1;
				_display setVariable ["spinsLeft", _spins];

				if (_spins <= 0) exitWith {
					_display setVariable ["spinsLeft", nil];
					_display setVariable ["eachFrame", nil];

					[_thisEventHandler] call ULP_fnc_removeEachFrame;

					private _firstIcon = _slotOne getVariable "current";
					private _secondIcon = _slotTwo getVariable "current";
					private _thirdIcon = _slotThree getVariable "current";

					private _firstIconIndex = ICON_ARRAY find _firstIcon;

					private _winnings = if (_firstIcon isEqualTo _thirdIcon && { !(_secondIcon isEqualTo _thirdIcon) }) then {
						SANDWICH_BASE
					} else {
						if (
							_firstIcon isEqualTo _secondIcon && { !(_secondIcon isEqualTo _thirdIcon) }
							|| { _secondIcon isEqualTo _thirdIcon && { !(_firstIcon isEqualTo _secondIcon) } }
							) exitWith {
							NEIGHBOUR_BASE
						};

						private _secondIconIndex = ICON_ARRAY find _secondIcon;
						private _thirdIconIndex = ICON_ARRAY find _thirdIcon;

						if (_secondIconIndex isEqualTo (_firstIconIndex + 1) && { _thirdIconIndex isEqualTo (_secondIconIndex + 1) }) exitWith {
							PRECEDING_BASE
						};

						if (_firstIcon isEqualTo _secondIcon && { _secondIcon isEqualTo _thirdIcon }) exitWith {
							EQUAL_BASE
						};

						0
					};

					_winnings = (_winnings + ((_firstIconIndex max 1) * (_winnings / 4))) * ( _bet / 1000 );

					if ([_winnings, false, "Slots Reward"] call ULP_fnc_addMoney) then {
						[format ["You bet <t color='#B92DE0'>%1%2</t> and won <t color='#B92DE0'>%1%3</t>", "£", [_bet] call ULP_fnc_numberText, [_winnings] call ULP_fnc_numberText]] call ULP_fnc_hint;
					} else {
						["You didn't win anything, better luck next time"] call ULP_fnc_hint;
					};

					private _casinoProfit = _bet - _winnings;
					[_casinoProfit] remoteExecCall ["ULP_SRV_fnc_updateCasinoVault", RSERV];

					_button ctrlEnable true;
				};
			}, 0.1] call ULP_fnc_addEachFrame)];
		} else {
			[format ["You can't afford to bet <t color='#B92DE0'>%1%2</t>", "£", [_bet] call ULP_fnc_numberText]] call ULP_fnc_hint;
		};
	}, false
] call ULP_fnc_selectNumber;