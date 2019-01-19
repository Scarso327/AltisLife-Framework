#include "..\..\script_macros.hpp"
/*
    @File: fn_playerSkins.sqf

    @Author: Jack "Scarso" Farhall

    @Date Created: 12th January 2019

    @Description: Sets players uniform skins.
*/

private _isInvisible = false; // Backpack...
private _cfgTexture = missionConfigFile >> "CfgTextures";

// Uniform.
if (isClass (_cfgTexture >> (uniform player))) then {
    _texture = getText(_cfgTexture >> (uniform player) >> "texture");
    player setObjectTextureGlobal [0, TEXTURE(_texture)];
    
    if(((getArray(_cfgTexture >> (uniform player) >> "invisBackpack")) select 0) isEqualTo 3) then {
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
        if (isClass (_cfgTexture >> (backpack player))) then {
            _texture = getText(_cfgTexture >> (backpack player) >> "texture");
            (unitBackpack player) setObjectTextureGlobal [0, TEXTURE(_texture)];
        };
    };
};