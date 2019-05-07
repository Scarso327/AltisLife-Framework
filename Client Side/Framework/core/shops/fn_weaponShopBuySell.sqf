#include "..\..\script_macros.hpp"
/*
    File: fn_weaponShopBuySell.sqf
    Author: Bryan "Tonic" Boardwine

    Description:
    Master handling of the weapon shop for buying / selling an item.
*/
disableSerialization;
private ["_price","_item","_itemInfo","_bad"];
if ((lbCurSel 38403) isEqualTo -1) exitWith {hint "You need to select an item to buy/sell."};
_price = lbValue[38403,(lbCurSel 38403)]; if (isNil "_price") then {_price = 0;};
_item = lbData[38403,(lbCurSel 38403)];
_itemInfo = [_item] call life_fnc_fetchCfgDetails;

_bad = "";

if ((_itemInfo select 6) != "CfgVehicles") then {
    if ((_itemInfo select 4) in [4096,131072]) then {
        if (!(player canAdd _item) && (uiNamespace getVariable ["Weapon_Shop_Filter",0]) != 1) exitWith {_bad = ("You don't have enough room for that item.")};
    };
};

if (_bad != "") exitWith {hint _bad};

if ((uiNamespace getVariable ["Weapon_Shop_Filter",0]) isEqualTo 1) then {
    if (playerSide isEqualTo civilian) then {
        CASH = CASH + _price;
        hint parseText format ["You sold a %1 for <t color='#8cff9b'>£%2</t>",_itemInfo select 1,[_price] call life_fnc_numberText];
    } else {
        hint "As a public servant, the government has taken the profits from your sale.";
    };

    [_item,false] call life_fnc_handleItem;
    [nil,(uiNamespace getVariable ["Weapon_Shop_Filter",0])] call life_fnc_weaponShopFilter; //Update the menu.
} else {
    private _altisArray = ["Land_u_Barracks_V2_F","Land_i_Barracks_V2_F"];
    private _tanoaArray = ["Land_School_01_F","Land_Warehouse_03_F","Land_House_Small_02_F"];
    private _hideoutObjs = [[["Altis", _altisArray], ["Tanoa", _tanoaArray]]] call TON_fnc_terrainSort;
    private _hideout = (nearestObjects[getPosATL player,_hideoutObjs,25]) select 0;
    if (!isNil "_hideout" && {!isNil {group player getVariable "gang_bank"}} && {(group player getVariable "gang_bank") >= _price}) then {
        _action = [
            format [("Your has enough funds to pay for this, would you like to pay with those funds or your own?")+ "<br/><br/>" +("Group Funds:")+ " <t color='#8cff9b'>£%1</t><br/>" +("Your Cash:")+ " <t color='#8cff9b'>£%2</t>",
                [(group player getVariable "gang_bank")] call life_fnc_numberText,
                [CASH] call life_fnc_numberText
            ],
            "Pay with cash or group funds",
            "Group Funds",
            "Your Cash"
        ] call BIS_fnc_guiMessage;
        if (_action) then {
            hint parseText format ["You bought a %1 for <t color='#8cff9b'>£%2</t> with your group funds.",_itemInfo select 1,[_price] call life_fnc_numberText];
            _funds = group player getVariable "gang_bank";
            _funds = _funds - _price;
            group player setVariable ["gang_bank",_funds,true];
            [_item,true] call life_fnc_handleItem;

            if (life_HC_isActive) then {
                [1,group player] remoteExecCall ["HC_fnc_updateGang",HC_Life];
            } else {
                [1,group player] remoteExecCall ["TON_fnc_updateGang",RSERV];
            };


        } else {
            if (_price > CASH) exitWith {hint "You don't have that much money!"};
            hint parseText format ["You bought a %1 for <t color='#8cff9b'>£%2</t>",_itemInfo select 1,[_price] call life_fnc_numberText];
            CASH = CASH - _price;
            [_item,true] call life_fnc_handleItem;
        };
    } else {
        if (playerSide isEqualTo civilian) then {
            if (_price > CASH) exitWith {hint "You don't have that much money!"};
            hint parseText format ["You bought a %1 for <t color='#8cff9b'>£%2</t>",_itemInfo select 1,[_price] call life_fnc_numberText];
            CASH = CASH - _price;
        } else {
            hint "As a public servant, the government has covered the costs of your equipment."
        };
        [_item,true] call life_fnc_handleItem;
    };
};
[0] call SOCK_fnc_updatePartial;
[3] call SOCK_fnc_updatePartial;
