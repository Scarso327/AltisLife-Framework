/*
    @File: fn_playerSkins.sqf

    @Author: Jack "Scarso" Farhall

    @Date Created: 12th January 2019

    @Description: Sets players uniform skins.
*/
#include "..\..\script_macros.hpp"
#define CONFIG missionConfigFile >> "CfgTextures"
params [
    ["_object", player, [objNull]]
];

if !(isPlayer _object) exitWith {};

private _isInvisible = false; // Backpack...

// Uniform.
if (isClass (CONFIG >> (uniform _object))) then {
    private _level = switch (side _object) do {
        case west: { (FETCH_CONST(life_coplevel)) };
    }; 

    private _texture = "";
    private _textDir = getArray(CONFIG >> (uniform _object) >> "texture");

    if ((_textDir # 0) isEqualTo 1) then {
        private _array = _textDir # 1;
        private _texCount = count(_array);
        
        if (_level > _texCount) then {
            _texture = _array select (count(_array) - 1);
        } else {
            _texture = _array select (_level - 1);
        };
    } else {
        _texture = _textDir # 1;
    };

    if !(_texture isEqualTo "") then { _object setObjectTextureGlobal [0, TEXTURE(_texture)] };
    
    if(((getArray(CONFIG >> (uniform _object) >> "invisBackpack")) select 0) isEqualTo 3) then {
        _isInvisible = true;
    };
};

// Backpack
if (backpack _object != "") then {
    // Remove backpacks....
    if (_isInvisible) then {
        (unitBackpack _object) setObjectTextureGlobal [0, ""];
    } else {
        // Retexture Backpack...
        if (isClass (CONFIG >> (backpack _object))) then {
            private _texture = getText(CONFIG >> (backpack _object) >> "texture");
            (unitBackpack _object) setObjectTextureGlobal [0, TEXTURE(_texture)];
        };
    };
};