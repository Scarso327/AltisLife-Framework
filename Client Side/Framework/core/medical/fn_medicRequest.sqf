/*
    File: fn_medicRequest.sqf
    Author: Bryan "Tonic" Boardwine

    Description:
    Notifies the medics that someone has requested emergency and prompts them
    if they want to take the request or not.
*/
params [
    ["_callerName","Unknown Player",[""]]
];

["MedicalRequestEmerg",[format ["%1 is requesting medical assistance.",_callerName]]] call BIS_fnc_showNotification;
