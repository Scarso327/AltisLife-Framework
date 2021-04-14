/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_onTextureSwitch";

_this params [
	"_ctrl", "_index"
];

private _display = ctrlParent _ctrl;
private _storeCfg = _display getVariable ["curStore", configNull];

if (!(isClass (_storeCfg)) || { isNull _display }) exitWith { ["Texture Failure!", "Cart Notification"] call ULP_fnc_hint; };

// Switching picture...
private _texture = _ctrl lbData _index;
if !(_texture isEqualTo "") then {
	_texture = parseSimpleArray _texture;

	if !((_texture select 2) isEqualTo "") then {
		(_display displayCtrl 3104) ctrlSetText (_texture select 2);
	};
};

(_display displayCtrl 3105) ctrlSetStructuredText parseText format[
	"<t size='0.8'>%1Texture: <t color='#8cff9b'>£%3</t><br/>%2<br/></t>",
	[] call ULP_fnc_itemInfo,
	[] call ULP_fnc_cartInfo,
	[(_ctrl lbValue _index)] call ULP_fnc_numberText
];