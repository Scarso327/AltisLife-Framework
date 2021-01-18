/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
scopeName "fn_initEventHandlers";

player addEventHandler ["Take", {_this call life_fnc_onTakeItem}];
player addEventHandler ["Fired", {_this call life_fnc_onFired}];
player addEventHandler ["InventoryClosed", {_this call life_fnc_inventoryClosed}];
player addEventHandler ["InventoryOpened", {_this call life_fnc_inventoryOpened}];

addMissionEventHandler ["Map", {_this call life_fnc_checkMap}];