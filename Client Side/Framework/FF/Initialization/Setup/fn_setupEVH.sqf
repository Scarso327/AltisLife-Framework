/*
    File: fn_setupEVH.sqf
    Author: Bryan "Tonic" Boardwine

    Description:
    Master eventhandler file
*/

/* Incapacitation System */
player addEventHandler ["Killed", {_this call FF_fnc_onKilled}];
player addEventHandler ["HandleDamage", {_this call FF_fnc_onDamaged}];
player addEventHandler ["Respawn", {_this call FF_fnc_onRespawn}];

/* Other */
player addEventHandler ["Take", {_this call life_fnc_onTakeItem}];
player addEventHandler ["Fired", {_this call life_fnc_onFired}];
player addEventHandler ["InventoryClosed", {_this call life_fnc_inventoryClosed}];
player addEventHandler ["InventoryOpened", {_this call life_fnc_inventoryOpened}];
player addEventHandler ["HandleRating", {0}];

addMissionEventHandler ["Map", {_this call life_fnc_checkMap}];