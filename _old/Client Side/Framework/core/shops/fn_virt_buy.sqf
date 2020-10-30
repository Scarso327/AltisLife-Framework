#include "..\..\script_macros.hpp"
/*
    File: fn_virt_buy.sqf
    Author: Bryan "Tonic" Boardwine

    Description:
    Buy a virtual item from the store.
*/
private ["_type","_price","_amount","_diff","_name","_hideout"];
if ((lbCurSel 2401) isEqualTo -1) exitWith {hint "You need to select an item to buy."};
_type = lbData[2401,(lbCurSel 2401)];
_price = lbValue[2401,(lbCurSel 2401)];
_amount = ctrlText 2404;
if (!([_amount] call TON_fnc_isnumber)) exitWith {hint "You didn't enter an actual number";};
_diff = [_type,parseNumber(_amount),life_carryWeight,life_maxWeight] call life_fnc_calWeightDiff;
_amount = parseNumber(_amount);
if (_diff <= 0) exitWith {hint "You don't have enough space for that amount!"};
_amount = _diff;
private _altisArray = ["Land_u_Barracks_V2_F","Land_i_Barracks_V2_F"];
private _tanoaArray = ["Land_School_01_F","Land_Warehouse_03_F","Land_House_Small_02_F"];
private _hideoutObjs = [[["Altis", _altisArray], ["Tanoa", _tanoaArray]]] call TON_fnc_terrainSort;
_hideout = (nearestObjects[getPosATL player,_hideoutObjs,25]) select 0;
if ((_price * _amount) > CASH && {!isNil "_hideout" && {!isNil {group player getVariable "gang_bank"}} && {(group player getVariable "gang_bank") <= _price * _amount}}) exitWith {hint "You don't have that much money!"};
if ((time - life_action_delay) < 0.2) exitWith {hint "You're doing it too fast!";};
life_action_delay = time;

_name = M_CONFIG(getText,"CfgItems",_type,"displayName");

if ([true,_type,_amount] call life_fnc_handleInv) then {
    if (!isNil "_hideout" && {!isNil {group player getVariable "gang_bank"}} && {(group player getVariable "gang_bank") >= _price}) then {
        _action = [
            format [("Your group has enough funds to pay for this, would you like to pay with those funds or your own?")+ "<br/><br/>" +("Group Funds:")+ " <t color='#8cff9b'>£%1</t><br/>" +("Your Cash:")+ " <t color='#8cff9b'>£%2</t>",
                [(group player getVariable "gang_bank")] call life_fnc_numberText,
                [CASH] call life_fnc_numberText
            ],
            "Pay with cash or group funds",
            "Group Funds",
            "Your Cash"
        ] call BIS_fnc_guiMessage;
        if (_action) then {
            hint format ["You bought %1 %2 for £%3 with your group funds.",_amount,_name,[(_price * _amount)] call life_fnc_numberText];
            _funds = group player getVariable "gang_bank";
            _funds = _funds - (_price * _amount);
            group player setVariable ["gang_bank",_funds,true];

            if (life_HC_isActive) then {
                [1,group player] remoteExecCall ["HC_fnc_updateGang",HC_Life];
            } else {
                [1,group player] remoteExecCall ["TON_fnc_updateGang",RSERV];
            };

        } else {
            if ((_price * _amount) > CASH) exitWith {[false,_type,_amount] call life_fnc_handleInv; hint "You don't have that much money!";};
            hint format ["You bought %1 %2 for £%3.",_amount,_name,[(_price * _amount)] call life_fnc_numberText];
            CASH = CASH - _price * _amount;
        };
    } else {
        if (playerSide isEqualTo civilian) then {
            if ((_price * _amount) > CASH) exitWith {hint "You don't have that much money!"; [false,_type,_amount] call life_fnc_handleInv;};
            hint format ["You bought %1 %2 for £%3.",_amount,_name,[(_price * _amount)] call life_fnc_numberText];
            CASH = CASH - _price * _amount;
        } else {
            hint "As a public servant, the government has covered the costs of your equipment.";
        };
    };
    [] call life_fnc_virt_update;
};

[0] call SOCK_fnc_updatePartial;
[3] call SOCK_fnc_updatePartial;
