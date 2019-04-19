/*
    File: fn_deathScreen.sqf
    Author: Bryan "Tonic" Boardwine

    Description:
    Handles stuff being displayed on the death screen while
    it is currently active.
*/
private ["_medicsOnline","_medicsNear"];
disableSerialization;
[] call life_fnc_requestMedic;

_medicsOnline = ((findDisplay 7300) displayCtrl 7304);
_medicsNear = ((findDisplay 7300) displayCtrl 7305);

waitUntil {
    _nearby = if (([independent,getPosATL player,120] call life_fnc_nearUnits)) then {"Yes"} else {"No"};
    _medicsOnline ctrlSetText format ["Active Medics:",independent countSide playableUnits];
    _medicsNear ctrlSetText format ["Nearest Medic:",_nearby];
    sleep 1;
    (isNull (findDisplay 7300))
};
