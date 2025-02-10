/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_buyVehicle";

if (canSuspend) exitWith {
    [ULP_fnc_buyVehicle, _this] call ULP_fnc_directCall;
};

_this params [
	"_button"
];

private _display = ctrlParent _button;
if (isNull _display) exitWith {};

private _texList = _display displayCtrl 3408;

private _vehInfo = _display getVariable ["selected", []];
if (_vehInfo isEqualTo []) exitWith {};

_vehInfo params [
	"", "_missionCfg", "", "_name", "", "", "", "", "", "_dlcInfo"
];

private _hasDlc = _dlcInfo param [0, true, [false]];

private _buyPrice = getNumber(_missionCfg >> "buyPrice");
private _texture = _texList lbData (lbCurSel _texList);

private _textureCfg = _missionCfg >> "Textures" >> _texture;
if (isClass _textureCfg) then {
	if !([configName _missionCfg, _texture] call ULP_fnc_isTextureUnlocked) then {
		[format ["The texture <t color='#B92DE0'>%1</t> is currently locked, you'll have to unlock it before you can use it!", getText (_textureCfg >> "displayName")]] call ULP_fnc_hint;
		breakOut "fn_buyVehicle";
	};
};

[
	(findDisplay getNumber(configFile >> "RscDisplayMission" >> "idd")), "Confirmation", ["Yes", "No"],
	format ["<t color='#B92DE0'>%1</t> requires DLC that you don't have, are you sure you want to purchase?", _name], 
	[_display, _missionCfg, _buyPrice, _texture],
	{	
		_this params [ "_display", "_missionCfg", "_buyPrice", "_texture" ];

		private _spawns = _display getVariable ["spawns", []];

		_spawns = _spawns apply {
			if (_x isEqualType []) exitWith { [_x] };
			[markerPos _x, markerDir _x]
		};

		private _spawn = {
			if (((_x select 0) nearEntities [["Car", "Ship", "Air"], 8]) isEqualTo []) exitWith { _x };
		} forEach _spawns;

		if (isNil "_spawn") exitWith {
			["There are no available spawn points!"] call ULP_fnc_hint;
		};

		private _faction = [player] call ULP_fnc_getFaction;

		if ([_faction, "vehicles"] call ULP_fnc_factionFree || { [_buyPrice, false, format ["Purchased %1", _name]] call ULP_fnc_removeMoney }) exitWith {

			if ([_faction, "vehicles"] call ULP_fnc_factionPresistant) then {
				["VehicleBought", {
					_this params [
						["_params", [], [[]]],
						["_limitReached", false, [true]],
						["_price", 0, [0]]
					];

					if (_limitReached) exitWith {
						([_params select 0] call ULP_fnc_vehicleCfg) params [
							"", "", "", ["_name", "Unknown", [""]], "", "", "", "", ""
						];

						private _limit = (getNumber (missionConfigFile >> "CfgVehicles" >> (_params select 0) >> "garageLimit")) + ULP_Prestige;
						if (["VehicleCollector"] call ULP_fnc_hasPerk) then { _limit = _limit * 2 };
						
						[_price, false, "Limit Refund"] call ULP_fnc_addMoney;
						[([format ["Your purchase was unable to be made as you've reached the max garagable limit for %1 of <t color='#B92DE0'>%2</t>", _name, [_limit] call ULP_fnc_numberText], 
							format ["You've been refunded <t color='#B92DE0'>%1%2</t> for %3 as you've reached the max garagable limit of <t color='#B92DE0'>%4</t>...", "£", [_price] call ULP_fnc_numberText, _name, [_limit] call ULP_fnc_numberText]] select (_price > 0))] call ULP_fnc_hint;
					};

					_params call ULP_fnc_createVehicle;
				}, true] call ULP_fnc_addEventHandler;

				[
					_buyPrice, 
					getPlayerUID player, 
					profileName, _faction, 
					configName _missionCfg, 
					_spawn, 
					_texture, 
					["VehicleCollector"] call ULP_fnc_hasPerk
				] remoteExecCall ["ULP_SRV_fnc_createVehicle", RSERV];
			} else {
				[configName _missionCfg, _spawn, _texture] call ULP_fnc_createVehicle;
			};

			["BuyVehicle"] call ULP_fnc_achieve;
			closeDialog 0;
		};

		[format["You can't afford to pay for this vehicle. You need £%1.", [_buyPrice] call ULP_fnc_numberText]] call ULP_fnc_hint;
	}, {}, false, _hasDlc
] call ULP_fnc_confirm;