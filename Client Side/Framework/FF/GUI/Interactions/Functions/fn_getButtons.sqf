/*
	@File: fn_getButtons.sqf
  
	@Author: Jack "Scarso" Farhall
  
	@Description: Gets the buttons for this interaction...

	@Parameters:
		0 - TYPE: STRING - DES: The interaciton menu we're opening...
*/
scopeName "getButtons";
#include "..\..\..\..\script_macros.hpp"
if !(params [
	["_menu", "", [""]]
]) exitWith { systemChat "No Menu Provided" };

// Default variables...
private _title = "Unknown Interaction";
private _buttons = [];

switch (_menu) do {
	case "General": {
		// Checks for this menu...
		if (player getVariable ["Escorting", false]) exitWith { breakOut "getButtons" }; // Can't do these actions while escorting someone...
		
		_title = "Player Interaction"; // Set Title...

		// Setup buttons...
		_buttons pushBack ["Give Money", "createDialog ""RscMoneyMenu"""]; // Give Money Button...
			_buttons pushBack ["Give Items", """Load"" call life_fnc_giveItem"]; // Give Items Button...
	};

	case "Police": {
		_title = "Detained Interaction"; // Set Title...

		// Setup buttons...
		if (player getVariable ["isEscorting",false]) then {
			_buttons pushBack ["Stop Escorting", "[] call life_fnc_stopEscorting; closeDialog 0;"]; // Stop Escorting Button...
		} else {
			_buttons pushBack ["Give Money", "createDialog ""RscMoneyMenu"""]; // Give Money Button...
			_buttons pushBack ["Give Items", """Load"" call life_fnc_giveItem"]; // Give Items Button...
			_buttons pushBack ["Unrestrain", "[life_pInact_curTarget] call life_fnc_unrestrain; closeDialog 0;"]; // Unrestrain Action...
			_buttons pushBack ["Check Licenses", "[player] remoteExecCall [""life_fnc_licenseCheck"",life_pInact_curTarget]; closeDialog 0;"]; // Unrestrain Action...
			_buttons pushBack ["Search Player", "[life_pInact_curTarget] spawn life_fnc_searchAction; closeDialog 0;"]; // Unrestrain Action...
			_buttons pushBack ["Ticket Player", "[life_pInact_curTarget] call life_fnc_ticketAction;"]; // Ticket Action...
			_buttons pushBack ["Escort Player", "[life_pInact_curTarget] call life_fnc_escortAction; closeDialog 0;"]; // Escort Button...

			// Jail Button...
			{
				if ((player distance (getMarkerPos _x) <50)) exitWith { _buttons pushBack ["Send to prison", "[life_pInact_curTarget] call life_fnc_arrestAction; closeDialog 0;"] };
			} forEach LIFE_SETTINGS(getArray,"sendtoJail_locations");

			_buttons pushBack ["Put in vehicle", "[life_pInact_curTarget] call life_fnc_putInCar; closeDialog 0;"]; // Put in Vehicle Button...

			if (FETCH_CONST(life_coplevel) < (LIFE_SETTINGS(getNumber,"seize_minimum_rank"))) then { _buttons pushBack ["Seize Contraband", "[life_pInact_curTarget] spawn life_fnc_seizePlayerAction; closeDialog 0;"] }; // Seize Contraband Button...
		};
	};

	case "Vehicle": {

		// Repair Button...
		if (alive life_vInact_curTarget && {([life_vInact_curTarget] call life_fnc_isDamaged)}) then {
			_buttons pushBack ["Repair Vehicle", "[life_vInact_curTarget] spawn life_fnc_repairTruck; closeDialog 0;"];
		};

		// Get Side...
		switch (playerSide) do {
			// Police Actions...
			case west: {
				_buttons pushBack ["Registration", "[life_vInact_curTarget] spawn life_fnc_searchVehAction; closeDialog 0;"];
				_buttons pushBack ["Search Vehicle", "[life_vInact_curTarget] spawn life_fnc_vehInvSearch; closeDialog 0;"];
				_buttons pushBack ["Pullout Players", "[life_vInact_curTarget] spawn life_fnc_pulloutAction; closeDialog 0;"];
				_buttons pushBack ["Impound Vehicle", "[life_vInact_curTarget] spawn life_fnc_impoundAction; closeDialog 0;"];
			};
			// Civilian Actions...
			case civilian: {
				if (typeOf life_vInact_curTarget == "O_Truck_03_device_F") then {
					if (isNil {(life_vInact_curTarget getVariable "mining")} || local life_vInact_curTarget && { life_vInact_curTarget in life_vehicles }) then {
						_buttons pushBack ["Mine from device", "[life_vInact_curTarget] spawn life_fnc_deviceMine"];
					};
				};
			};
		};

		private _id = getObjectDLC life_vInact_curTarget; // Get DLC Id...

		if (life_vInact_curTarget isKindOf "Ship" && { local life_vInact_curTarget } && { crew life_vInact_curTarget isEqualTo [] }) then {
			_buttons pushBack ["Push Boat", "[] spawn life_fnc_pushObject; closeDialog 0;"];
		} else {
			if !(isNil "_id") then {
				if (!(_id in getDLCs 1) && { crew life_vInact_curTarget isEqualTo [] } && { canMove life_vInact_curTarget } && { locked life_vInact_curTarget isEqualTo 0 }) then {
					_buttons pushBack ["Get In Vehicle", "player moveInDriver life_vInact_curTarget; closeDialog 0;"];
				};
			};

			if (alive life_vInact_curTarget && { ( !(crew life_vInact_curTarget isEqualTo []) || {!(canMove life_vInact_curTarget)} ) }) then {
				_buttons pushBack ["Unflip Vehicle", "life_vInact_curTarget spawn FF_fnc_unflipVehicle; closeDialog 0;"];
			};
		};
	};
};

[_title, _buttons] call FF(createMenu);