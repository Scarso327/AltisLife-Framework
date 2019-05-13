/*
    File: fn_teleport.sqf
    Author: ColinM9991
*/

private ["_pos"];
_pos = [_this select 0, _this select 1, _this select 2];
(vehicle player) setPos [_pos select 0, _pos select 1, 0];
onMapSingleClick "";
openMap [false, false];
hint "You have teleported to your selected position.";
