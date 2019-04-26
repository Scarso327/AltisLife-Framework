#include "..\..\script_macros.hpp"
/*
    File: fn_buyLicense.sqf
    Author: Bryan "Tonic" Boardwine

    Editor: Jack "Scarso" Farhall (Allows Purchasing Through UI)

    Description:
    Called when purchasing a license. May need to be revised.
*/
private _type = CONTROL_DATA(4001);

if (_type isEqualTo "") exitWith {hint "You have not selected a license to buy!"};
if (!isClass (missionConfigFile >> "CfgLicenses" >> _type)) exitWith { systemChat "Bad Entry..." };

private _displayName = M_CONFIG(getText, "CfgLicenses", _type, "displayName");
private _price = M_CONFIG(getNumber, "CfgLicenses", _type, "price");
private _sideFlag = M_CONFIG(getText, "CfgLicenses", _type, "side");
private _varName = LICENSE_VARNAME(_type, _sideFlag);

private _side = switch (_sideFlag) do {case "cop": {west}; case "med" : {independent}; case "civ" : {civilian};};
if !(playerSide isEqualTo _side) exitWith { hint format["You must be a %1 to purchase this license!", _sideFlag] };

if (CASH < _price) exitWith {hint format ["You do not have enough money..."]};
CASH = CASH - _price;

[0] call SOCK_fnc_updatePartial;

titleText[format ["You bought a %1 for £%2.", _displayName,[_price] call life_fnc_numberText],"PLAIN"];
missionNamespace setVariable [_varName,true];

[2] call SOCK_fnc_updatePartial;
closeDialog 0;