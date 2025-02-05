/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\..\script_macros.hpp"
scopeName "fn_DialogSalvageFactory_OnEachFrame";

_this params [ "_display" ];

if (isNull _display) exitWith { [_thisEventHandler] call ULP_fnc_removeEachFrame; };

private _ctrlProgress = _display displayCtrl 5606;
private _ctrlText = _display displayCtrl 5607;

private _factory = _display getVariable ["factory", objNull];

private _factoryOrder = _factory getVariable ["product_order", []];

if (_factoryOrder isEqualTo []) exitWith {
	_display closeDisplay 2;
	[_thisEventHandler] call ULP_fnc_removeEachFrame;

	["Order finished"] call ULP_fnc_hint;
};

_factoryOrder params [ "_productCfg", "", "_quantity", "_startTime" ];

private _cfg = [configName _productCfg] call ULP_fnc_vehicleCfg;
if (isNull _vehicle || { _cfg isEqualTo [] }) exitWith {};

private _name = _cfg param [3, "Unknown", [""]];

_ctrlText ctrlSetText format ["Salvaging %1", _name];
_ctrlProgress progressSetPosition ((serverTime - _startTime) / getNumber (_productCfg >> "tickTime"));