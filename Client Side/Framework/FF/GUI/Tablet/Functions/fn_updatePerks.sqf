/*
	@File: fn_updatePerks.sqf
  
	@Author: Jack "Scarso" Farhall
  
	@Description: Updates the active perk ui....
*/
#include "..\macros.hpp"

private _display = findDisplay IDD_TABLET_MAIN;

// This area updates the active perks...
private _perkBoxes = [
	IDC_PERK_ACTIVE_ONE,
	IDC_PERK_ACTIVE_TWO,
	IDC_PERK_ACTIVE_THREE,
	IDC_PERK_ACTIVE_FOUR,
	IDC_PERK_ACTIVE_FIVE
];

for "_i" from 0 to 4 do {
	private _text = "Free";

	// If we are still within the perks length then this is a perk...
	if !((count(FF_Perks) - 1) < _i) then {
		_text = getText(missionConfigFile >> "CfgPerks" >> (FF_Perks select _i) >> "displayName");
	};

	private _curBox = _display displayCtrl (_perkBoxes select _i);
	private _curButton = _display displayCtrl ((_perkBoxes select _i) + 1); // Get the button... (IDC + 1)

	_curBox ctrlSetStructuredText parseText format["<t align='center'>%1</t>", _text];

	// If it's not marked as free then we need to setup the button...
	if !(_text isEqualTo "Free") then {
		// Add "remove" functionality...
		private _function = format["['%1', true] call FF_fnc_changePerks", (FF_Perks select _i)];
		_curButton ctrlSetEventHandler ["ButtonClick", _function];
	} else {
		_curButton ctrlRemoveAllEventHandlers "ButtonClick"; // It shouldn't have any functionality...
	};
};