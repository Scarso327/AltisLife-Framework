/*
    @File: fn_playerSkins.sqf

    @Author: Jack "Scarso" Farhall

    @Date Created: 12th January 2019

    @Description: Sets players uniform skins.
*/
#include "..\..\script_macros.hpp"
#define CONFIG missionConfigFile >> "CfgTextures"

private _isInvisible = false; // Backpack...

// Uniform.
if (isClass (CONFIG >> (uniform player))) then {
    _texture = getText(CONFIG >> (uniform player) >> "texture");
    player setObjectTextureGlobal [0, TEXTURE(_texture)];
    
    if(((getArray(CONFIG >> (uniform player) >> "invisBackpack")) select 0) isEqualTo 3) then {
        _isInvisible = true;
    };
};

// Backpack
if (backpack player != "") then {
    // Remove backpacks....
    if (_isInvisible) then {
        (unitBackpack player) setObjectTextureGlobal [0, ""];
    } else {
        // Retexture Backpack...
        if (isClass (CONFIG >> (backpack player))) then {
            _texture = getText(CONFIG >> (backpack player) >> "texture");
            (unitBackpack player) setObjectTextureGlobal [0, TEXTURE(_texture)];
        };
    };
};