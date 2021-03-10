/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\..\script_macros.hpp"
#include "..\..\..\UI\gridCommon.inc"
scopeName "fn_options";

_display = _this;
if (isNull _display) exitWith {};

private _ctrlGroup = _display displayCtrl 23023;

private _category = configNull;
private _categoryCtrl = controlNull;
private _option = configNull;
private _optionCtrl = controlNull;
private _yPos = 0;
private _lastCtrlPos = ctrlPosition controlNull;

{
	_category = _x;
	_categoryCtrl = _display ctrlCreate ["ULP_ctrlOptionsHeader", -1, _ctrlGroup];

	_yPos = (_lastCtrlPos # 1) + (_lastCtrlPos # 3);
	if (_forEachIndex > 0) then { _yPos = _yPos + (PIXEL_GRID / 2); };

	_categoryCtrl ctrlSetPositionY _yPos;
	_categoryCtrl ctrlCommit 0;

	_categoryCtrl ctrlSetText getText(_category >> "title");
	_lastCtrlPos = ctrlPosition _categoryCtrl;

	{
		_option = _x;
		private _isDefault = true;

		_optionCtrl = switch (getText(_option >> "type")) do {
			case "DROPDOWN": {
				private _optionCtrlRaw = _display ctrlCreate ["ULP_ctrlOption", -1, _ctrlGroup];
				private _dropdown = (_optionCtrlRaw controlsGroupCtrl 102);

				getArray (_option >> "values") params [ "_values", "_defaultValue" ];

				private _optionValue = [configName _option, configName _category, _defaultValue] call ULP_fnc_getOption;
				private _selected = 0;

				{
					_x params ["_name", "_data"];

					private _val = _dropdown lbAdd _name;
					_dropdown lbSetValue [_val, _data];

					if (_data isEqualTo _optionValue) then {
						_selected = _val;

						if !(_optionValue isEqualTo _defaultValue) then {
							_isDefault = false;
						};
					};
				} forEach _values;

				_dropdown lbSetCurSel _selected;

				_dropdown ctrlAddEventHandler ["LBSelChanged", {
					_this params [
						["_combo", controlNull, [controlNull]],
						["_index", 0, [0]]
					];
					
					[_combo, _combo lbValue _index, _combo getVariable "default"] call ULP_fnc_setOption;
				}];

				_dropdown setVariable ["default", _defaultValue];
				
				_optionCtrlRaw
			};
			default { controlNull };
		};
		
		if !(isNull _optionCtrl) then {
			_optionCtrl ctrlSetPositionY (((_lastCtrlPos # 1) + (_lastCtrlPos # 3)) + (PIXEL_GRID / 2));
			_optionCtrl ctrlCommit 0;

			private _nameCtrl = _optionCtrl controlsGroupCtrl 101;
			_nameCtrl ctrlSetText getText (_option >> "name");
			_nameCtrl ctrlSetTooltip getText (_option >> "tooltip");

			private _resetCtrl = _optionCtrl controlsGroupCtrl 103;
			_resetCtrl ctrlEnable !_isDefault; // Enable / Disable reset button...

			private _valueCtrl = _optionCtrl controlsGroupCtrl 102;
			_valueCtrl setVariable ["category", configName _category];
			_valueCtrl setVariable ["option", configName _option];
			_valueCtrl setVariable ["resetCtrl", _resetCtrl];

			_resetCtrl ctrlSetEventHandler ["ButtonClick", "[(_this select 0)] call ULP_fnc_resetOption;"];

			_lastCtrlPos set [1, (ctrlPosition _optionCtrl) # 1]; // Update Y...
		};
	} forEach ("isClass _x" configClasses _category);
} forEach ("isClass _x" configClasses (missionConfigFile >> "CfgOptions"));