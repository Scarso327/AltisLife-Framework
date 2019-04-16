#include "..\..\script_macros.hpp"
/*
    File: fn_handleDamage.sqf
    Author: Bryan "Tonic" Boardwine

    Description:
    Handles damage, specifically for handling the 'tazer' pistol and nothing else.
*/
params [
    ["_unit",objNull,[objNull]],
    ["_part","",[""]],
    ["_damage",0,[0]],
    ["_source",objNull,[objNull]],
    ["_projectile","",[""]],
    ["_index",0,[0]]
];

if (!isNull _source && {_source != _unit}) then {
    if (currentWeapon _source in ["hgun_Pistol_heavy_01_F","hgun_Pistol_heavy_01_MRD_F"] && _projectile in ["B_45ACP_Ball"]) then {
        if (alive _unit) then {
            if !(life_istazed) then {
                private _distance = 35;
                if (_unit distance _source < _distance) then {
                    if !(isNull objectParent _unit) then {
                        if (typeOf (vehicle _unit) isEqualTo "B_Quadbike_01_F") then {
                            _unit action ["Eject",vehicle _unit];
                            [_unit,_source] spawn life_fnc_tazed;
                        };
                    } else {
                        [_unit,_source] spawn life_fnc_tazed;
                    };
                };
            };
            _damage = if (_part isEqualTo "") then {
                damage _unit;
            } else { 
                _unit getHit _part;
            };
        };
    };
};

[] spawn FF_fnc_hudUpdate;
_damage;
