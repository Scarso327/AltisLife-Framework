#include "..\..\script_macros.hpp"
/*
    File: fn_weaponShopMenu.sqf
    Author: Bryan "Tonic" Boardwine

    Description:
    Something
*/

private _shopTitle = M_CONFIG(getText,"CfgWeapons",(_this select 3),"name");
private _shopSides = M_CONFIG(getArray,"CfgWeapons",(_this select 3),"requiredSide");
private _shopLicenses = M_CONFIG(getArray,"CfgWeapons",(_this select 3),"requiredLicenses");
private _shopWhitelist = M_CONFIG(getArray,"CfgWeapons",(_this select 3),"requiredWhitelist");

// Check Sides
private _sideMatch = false;
{
    private _side = switch (_x) do {case "Police": {west}; case "NHS" : {independent}; case "Civilian" : {civilian};};

    if (side player == _side) exitWith {
        _sideMatch = true;
    };
} forEach _shopSides;

if (!_sideMatch) exitWith { hint format["You must be one of the following sides to use this store: %1", _shopSides]; };

// Check Licenses
private _hasLicense = true;
if(count(_shopLicenses) > 0) then {
    {
        private _flag = M_CONFIG(getText,"Licenses",_x,"side");
        if(!(LICENSE_VALUE(_x,_flag))) exitWith {_hasLicense = false;};
    } forEach _shopLicenses;
};

if (!_hasLicense) exitWith { hint format["You must have the following licenses to use this store: %1", _shopLicenses]; };

// New Whitelist Check
private _isWhitelisted = true; // Assume Whitelisted
if(count(_shopWhitelist) > 0) then {
    {
        _type = _x select 0; // Required Type Example: life_coplevel
        _levelReq = _x select 1; // Required Minimum Level

        _myLevel = GVAR_MNS _type;
	    if(typeName _myLevel == typeName {}) then {_myLevel = FETCH_CONST(_myLevel);};

        if(!(_myLevel >= _levelReq)) exitWith {
            _isWhitelisted = false;
        };
    } forEach _shopWhitelist;
};

if (!_isWhitelisted) exitWith { hint format["You must have the following access levels to use this store: %1", _shopWhitelist]; };

uiNamespace setVariable ["Weapon_Shop",(_this select 3)];
uiNamespace setVariable ["Weapon_Magazine",0];
uiNamespace setVariable ["Weapon_Accessories",0];
uiNamespace setVariable ["Magazine_Array",[]];
uiNamespace setVariable ["Accessories_Array",[]];

if !(createDialog "life_weapon_shop") exitWith {};
if (!isClass(missionConfigFile >> "CfgWeapons" >> (_this select 3))) exitWith {}; //Bad config entry.

disableSerialization;

ctrlSetText[38401,_shopTitle];

private _filters = ((findDisplay 38400) displayCtrl 38402);
lbClear _filters;

ctrlShow [38406,true];
ctrlEnable [38406,false];
ctrlShow [38407,true];
ctrlEnable [38407,false];

_filters lbAdd localize "STR_Shop_Weapon_ShopInv";
_filters lbAdd localize "STR_Shop_Weapon_YourInv";

_filters lbSetCurSel 0;
