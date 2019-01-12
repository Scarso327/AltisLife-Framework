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
    
    if((getNumber(_cfgTexture >> (uniform player) >> "invisBackpack")) isEqualTo 1) then {
        _isInvisible = true;
    };
};

// Remove backpacks....
if (_isInvisible && backpack player != "") then {
    (unitBackpack player) setObjectTextureGlobal [0, ""];
};