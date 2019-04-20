/*
	@File: fn_nameTags.sqf
  
	@Author: Jack "Scarso" Farhall
  
	@Description: Creates and displays nametags above player names...
*/
#include "..\..\..\..\script_macros.hpp"

if (!isNil "FF_fnc_nameTags_draw3d") then {removeMissionEventHandler ["Draw3D", FF_fnc_nameTags_loop]};

FF_fnc_nameTags_draw3d = addMissionEventHandler ["Draw3D", {
	if (life_settings_tagson && { !(isDowned(player)) }) then {
		private _masks = LIFE_SETTINGS(getArray,"clothing_masks");
		private _colorSub = [1,1,1,1];

		{
			private _tagPos = ( _x modelToWorldVisual ( _x selectionPosition "pilot" ) ) vectorAdd [ 0, 0, 0.48 ];
			private _myPos = positionCameraToWorld [ 0, 0, 0 ];

			if (!lineIntersects [eyePos player, eyePos _x, player, _x] && {!isNil {_x getVariable "realname"}}) then {
				( [ _tagPos, _myPos, 0.00571 ] call FF(D3DTextCal) ) params [ "_up", "_mid", "_down" ];

				// Default some values...
				private _name = (_x getVariable["realname", name _x]);
				private _icon = "";
				private _subtitle = "";
				private _colorMain = [0,0.901,0.074,1];

				private _alpha = linearConversion [ 15 / 1.25, 15, _tagPos distance _myPos, 1, 0, true];
				_colorMain set [3, _alpha];
				_colorSub set [3, _alpha];

				switch true do {
					// Masked Player...
					case ((headgear _x) in _masks || {(goggles _x) in _masks} || {(uniform _x) in _masks}): {
						_name = "Unknown";
						_subtitle = "Masked Player";
					};

					// Faction Information...
					case ((side _x) in [west, independent]): {
						private _rankDetails = _x call FF(getRank);
						_subtitle = _rankDetails # 0;
						_icon = _rankDetails # 1;
					};

					// Civilian...
					case (!isNil {(group _x) getVariable "gang_name"}): {
						_subtitle = (group _x) getVariable ["gang_name",""];
					};
              	};

				if !(_icon isEqualTo "" ) then { drawIcon3D [_icon, _colorSub, _up, 1, 1, 0] };
				drawIcon3D ["", _colorMain, _mid, 0, 0, 0, _name, 0, 0.0323, "RobotoCondensed"];
              	drawIcon3D ["", _colorSub, _down, 0, 0, 0, _subtitle, 0, 0.0285, "RobotoCondensed"];
			};
		} forEach ( 
			((getPosATLVisual player) nearEntities [ "Man", 15 ]) select { 
				isPlayer _x && { alive _x } && { isNull objectParent _x }
			}
		);
	};
}];