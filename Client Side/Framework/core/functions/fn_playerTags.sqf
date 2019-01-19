#include "..\..\script_macros.hpp"
/*
    File: fn_playerTags.sqf
    Author: Bryan "Tonic" Boardwine

    Description:
    Adds the tags above other players heads when close and have visible range.
*/
if (!life_settings_tagson) exitWith {};
private ["_ui","_units","_masks"];
#define iconID 78000
#define scale 0.8

if (visibleMap || {!alive player} || {dialog}) exitWith {
    500 cutText["","PLAIN"];
};

_ui = uiNamespace getVariable ["Life_HUD_nameTags",displayNull];
if (isNull _ui) then {
    500 cutRsc["Life_HUD_nameTags","PLAIN"];
    _ui = uiNamespace getVariable ["Life_HUD_nameTags",displayNull];
};

_units = nearestObjects[(visiblePosition player),["CAManBase","Land_Pallet_MilBoxes_F","Land_Sink_F"],50];

_masks = LIFE_SETTINGS(getArray,"clothing_masks");

{
	_idc = _ui displayCtrl _x;
	_idc ctrlShow false;
} forEach life_nametags;
life_nametags = [];

private _index = -1;
{
    private "_text";
    _idc = _ui displayCtrl (iconID + _forEachIndex);
    life_nametags pushBack (iconID + _forEachIndex);
    if (!(lineIntersects [eyePos player, eyePos _x, player, _x]) && alive _x && {!isNil {_x getVariable "realname"}}) then {
        _pos = switch (typeOf _x) do {
            case "Land_Pallet_MilBoxes_F": {[visiblePosition _x select 0, visiblePosition _x select 1, (getPosATL _x select 2) + 1.5]};
            case "Land_Sink_F": {[visiblePosition _x select 0, visiblePosition _x select 1, (getPosATL _x select 2) + 2]};
            default {[visiblePosition _x select 0, visiblePosition _x select 1, ((_x modelToWorld (_x selectionPosition "head")) select 2)+.6]};
        };
        _sPos = worldToScreen _pos;
        _distance = _pos distance player;

        if (count _sPos > 1 && {_distance < 4}) then {
            _name = "";
            _icon = "";
            _subtitle = "";
            
            // Get settings...
            switch (true) do {
                // Masked Player...
                case ((headgear _x) in _masks || {(goggles _x) in _masks} || {(uniform _x) in _masks}): {
                    _name = "Unknown";
                    _subtitle = "Masked Player";
                };

                case ((side _x) isEqualTo west): {
                    _rankDetails = [] call FF(getRank);
                    _icon = _rankDetails select 1;
                    _subtitle = _rankDetails select 0;
                };
                
                // Gang Member...
                case (_x in (units grpPlayer) && playerSide isEqualTo civilian): {
                    _name = format["<t color='#00FF00'>%1</t>",(_x getVariable ["realname",name _x])];
                    _subtitle = (group _x) getVariable ["gang_name",""];
                };

                // Civilian...
                case (!isNil {(group _x) getVariable "gang_name"}): {
                    _subtitle = (group _x) getVariable ["gang_name",""];
                };

                // Could be an object?
                case (!isNil {_x getVariable "icon"} || !isNil {_x getVariable "subtitle"}): {
                    _icon = _x getVariable["icon",""];
                    _subtitle = _x getVariable["subtitle",""];
                };
            };

            if(_name isEqualTo "") then {_name = _x getVariable ["realname",name _x]};

            _text = "";
            _textRaw = [];

            _textRaw pushBack "<t align='center'>"; // Styling....
            if(_icon != "") then {_textRaw pushBack format["<img image='%1' size='2.5'></img><br/>",_icon];};
            _textRaw pushBack format["<t size='1.3'>%1</t><br/>", _name]; // Naming...
            if(_subtitle != "") then {_textRaw pushBack format["<t size='1'>%1</t><br/>",_subtitle];};	
            _textRaw pushBack "</t>"; // Styling....
            
            { _text = _text + _x} forEach _textRaw; // Output...

            _idc ctrlSetStructuredText parseText _text;
            _idc ctrlSetPosition [(_sPos select 0) - 0.13, _sPos select 1, 0.4, 0.65];
            _idc ctrlSetScale scale;
            _idc ctrlSetFade 0;
            _idc ctrlCommit 0;
            _idc ctrlShow true;
        } else {
            _idc ctrlShow false;
        };
    } else {
        _idc ctrlShow false;
    };
    _index = _forEachIndex;
} forEach _units;
(_ui displayCtrl (iconID + _index + 1)) ctrlSetStructuredText parseText "";