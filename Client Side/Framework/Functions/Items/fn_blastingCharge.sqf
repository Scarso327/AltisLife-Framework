#include "..\..\script_macros.hpp"
/*
    File: fn_blastingCharge.sqf
    Author: Bryan "Tonic" Boardwine

    Description:
    Blasting charge is used for the federal reserve vault and nothing  more.. Yet.
*/
private ["_vault","_handle"];
_vault = param [0,ObjNull,[ObjNull]];

if (isNull _vault) exitWith {}; //Bad object
if (typeOf _vault != "Land_CargoBox_V1_F") exitWith {hint "This can only be used on a vault."};
if (_vault getVariable ["chargeplaced",false]) exitWith {hint "There is already a charge placed on this vault."};
if (_vault getVariable ["safe_open",false]) exitWith {hint "The vault is already opened."};
if (west countSide playableUnits < (LIFE_SETTINGS(getNumber,"hm_required_number"))) exitWith {
     hint format ["There needs to be %1 or more police officers online to continue.",(LIFE_SETTINGS(getNumber,"hm_required_number"))];
};

private _vaultHouse = [[["Altis", "Land_Research_house_V1_F"], ["Tanoa", "Land_Medevac_house_V1_F"]]] call TON_fnc_terrainSort;
private _altisArray = [16019.5,16952.9,0];
private _tanoaArray = [11074.2,11501.5,0.00137329];
private _pos = [[["Altis", _altisArray], ["Tanoa", _tanoaArray]]] call TON_fnc_terrainSort;

if ((nearestObject [_pos,_vaultHouse]) getVariable ["locked",true]) exitWith {hint "You must open the container before placing the charge!"};
if (!([false,"blastingcharge",1] call life_fnc_handleInv)) exitWith {}; //Error?

_vault setVariable ["chargeplaced",true,true];
[0,"A blasting charge has been placed on the federal reserves vault, You have till the clock runs out to disarm the charge!",true,[]] remoteExecCall ["life_fnc_broadcast",west];
hint "The timer is ticking! Keep the cops away from the vault!";

[] remoteExec ["life_fnc_demoChargeTimer",[west,player]];
[] remoteExec ["TON_fnc_handleBlastingCharge",2];
