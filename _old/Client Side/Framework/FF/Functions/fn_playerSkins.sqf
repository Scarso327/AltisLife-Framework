/*
    @File: fn_playerSkins.sqf

    @Author: Jack "Scarso" Farhall

    @Date Created: 12th January 2019

    @Description: Sets players uniform skins.
*/
#include "..\..\script_macros.hpp"
#define CONFIG missionConfigFile >> "CfgTextures"
_this params [
    ["_object", player, [objNull]],
    ["_isLocal", false, [true]],
    ["_side", sideUnknown, [sideUnknown]]
];

if (_side isEqualTo sideUnknown) then { _side = (side _object) };

fnc_texture = {
    params [
        ["_object", player, [objNull]], 
        ["_isLocal", false, [true]], 
        ["_texture", "", [""]], 
        ["_expected", "", [""]], 
        ["_fallback", false, [true]],
        ["_type", "(uniform _object) isEqualTo _expected", [""]]
    ];

    if (_expected isEqualTo "") exitWith {};
    
    if !(_texture isEqualTo "") then {
        _texture = TEXTURE(_texture);
    } else {
        if (_fallback) then {
            _texture = (getArray(configFile >> "CfgWeapons" >> (uniform _object) >> "hiddenSelectionsTextures")) select 0;
        };
    };

    private _timed = diag_tickTime;
    waitUntil {(call compile _type) || { ((diag_tickTime - _timed) > 15) }};

    if (_isLocal) then {
        _object setObjectTexture [0, _texture];
    } else {
        _object setObjectTextureGlobal [0, _texture];
    };
};

private _hasBPTexture = false; // Backpack...
private _bpTexture = "";

// Uniform.
if (isClass (CONFIG >> (uniform _object))) then {
    private _level = _object getVariable ["rank", 1];

    private _texture = "";
    private _textures = getArray(CONFIG >> (uniform _object) >> "textures");

    if !(_textures isEqualTo []) then {
        {
            if ((call compile (_x select 1))) exitWith {
                _texture = (_x select 0);
                _hasBPTexture = (((_x select 2) select 0) isEqualTo 1);
                _bpTexture = ((_x select 2) select 1);
            };
        } forEach _textures;
    };

    if !(_texture isEqualTo "") then { [_object, _isLocal, _texture, (uniform _object), true, "(uniform _object) isEqualTo _expected"] spawn fnc_texture };
};

diag_log format["%1 | %2 | %3", (backpack _object), _hasBPTexture, _bpTexture];

// Backpack
if (backpack _object != "") then {
    if (_hasBPTexture) then {
        [(unitBackpack _object), _isLocal, _bpTexture, (backpack _object), false, "(typeOf _object) isEqualTo _expected"] spawn fnc_texture;
    } else {
        if (isClass (CONFIG >> (backpack _object))) then {
            private _texture = getText(CONFIG >> (backpack _object) >> "texture");
            [(unitBackpack _object), _isLocal, _texture, (backpack _object), false, "(typeOf _object) isEqualTo _expected"] spawn fnc_texture;
        };
    };
};