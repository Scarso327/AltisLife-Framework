class CfgInteractions {
	/* GENERAL INTERACTIONS */
	// Show ID	
	// Show Licenses	
	// Give Cash
	// Give Keys

	/* RESTRAINED INTERACTIONS */
	// Put In Vehicle
	// Feed/Hydrate
	// Blindfold/Remove Blindfold
	// Gag/Remove Gag
	// Check Inventory
	// Check vItems
	// Check ID
	// Check Licenses

	/* POLICE INTERACTIONS */
	// Issue Ticket
	// Send to Prison

	/* MEDIC INTERACTIONS */
	// Revive

	class Person {
		class GiveKeys {
			title = "Give Keys";
			factions[] = { "Police", "Medic", "Hato", "Civilian" };
			onClick = "_this call ULP_fnc_giveVehicleKeys";
			condition = "true";
		};

		class Unrestrain {
			title = "Unrestrain";
			factions[] = { "Police" };
			onClick = "[_this select 0, player, false] call ULP_fnc_restrain; closeDialog 0;";
			condition = "[_this] call ULP_fnc_isRestrained";
		};
		class Escort : Unrestrain {
			title = "Escort";
			onClick = "[_this select 0, player, true] call ULP_fnc_escort; closeDialog 0;";
			condition = "[_this] call ULP_fnc_isRestrained && { !([_this] call ULP_fnc_isEscorted) }";
		};
		class StopEscort : Unrestrain {
			title = "Stop Escorting";
			onClick = "[_this select 0, player, false] call ULP_fnc_escort; closeDialog 0;";
			condition = "[_this] call ULP_fnc_isRestrained && { [_this] call ULP_fnc_isEscorted }";
		};
	};

	class PersonMedical {
		class AdministerBlood {
			title = "Administer Blood";
			factions[] = { "Police", "Medic", "Hato", "Civilian" };
			onClick = "_this call ULP_fnc_administerBlood";
			condition = "(0 max ([""BloodBag""] call ULP_fnc_hasItem)) > 0";
		};
	};

	class PersonEscortOnly {
		class StopEscort {
			title = "Stop Escorting";
			factions[] = { "Police" };
			onClick = "[_this select 0, player, false] call ULP_fnc_escort; closeDialog 0;";
			condition = "[_this] call ULP_fnc_isRestrained && { [_this] call ULP_fnc_isEscorted }";
		};
	};

	class House {
		class BuyHouse {
			title = "Buy House";
			factions[] = { "Civilian" };
			onClick = "_this call ULP_fnc_buyHouse;";
			condition = "isClass (missionConfigFile >> ""CfgFactions"" >> [player] call ULP_fnc_getFaction >> ""Housing"") && { !([_this] call ULP_fnc_isHouseOwned) }";
		};
	};

	class HouseOwner {
		class SellHouse {
			title = "Sell House";
			factions[] = { "Civilian" };
			onClick = "_this call ULP_fnc_sellHouse;";
			condition = "[_this, player, false] call ULP_fnc_isHouseOwner";
		};
	};

	class EquipmentBox {
		class ClearBox {
			title = "Clear Box";
			factions[] = { "Police" };
			onClick = "_this call ULP_fnc_clearCargo;";
			condition = "true";
		};
		
		class ResetLoadout {
			title = "Reset Loadout";
			factions[] = { "Police", "Medic", "Hato" };
			onClick = "[] call ULP_fnc_setLoadout;";
			condition = "[[player] call ULP_fnc_getFaction] call ULP_fnc_canResetLoadout;";
		};
	};

	class Vehicle {

		class Repair {
			title = "Repair";
			factions[] = { "Police", "Medic", "Hato", "Civilian" };
			onClick = "_this call ULP_fnc_repairVehicle";
			condition = "true";
		};

		// TODO
		class Lockpick : Repair {
			title = "Lockpick";
			condition = "!([player, _this] call ULP_fnc_isVehicleOwner) && { [""Lockpick""] call ULP_fnc_hasItem > 0 }";
		};

		class Registration : Repair {
			title = "Registration";
			onClick = "closeDialog 0; [(_this select 0)] call ULP_fnc_vehicleRegistration";
			factions[] = { "Police", "Hato" };
		};

		// TODO
		class Clamp : Repair {
			title = "Clamp";
			onClick = "_this call ULP_fnc_repairVehicle";
			factions[] = { "Police", "Hato" };
		};

		// TODO
		class Search : Repair {
			title = "Search";
			onClick = "hint ""Hello"";";
			factions[] = { "Police" };
		};

		class Garage : Repair {
			title = "Garage";
			onClick = "_this call ULP_fnc_garageVehicle";
			factions[] = { "Police", "Hato" };
			condition = "[""Police_Main"", 2] call ULP_fnc_hasAccess || { [""Medic_Main"", 2] call ULP_fnc_hasAccess }";
		};

		class Impound : Repair {
			title = "Impound";
			onClick = "_this call ULP_fnc_impoundVehicle";
			factions[] = { "Police", "Hato" };
			condition = "[""Police_Main"", 3] call ULP_fnc_hasAccess";
		};

		class Scrap : Repair {
			title = "Scrap";
			onClick = "_this call ULP_fnc_crushVehicle";
			factions[] = { "Police" };
			condition = "[""Police_Main"", 3] call ULP_fnc_hasAccess";
		};

		class PulloutOccupants : Repair {
			title = "Pullout Occupants";
			onClick = "if (_this call ULP_fnc_ejectVehicleCrew) then { closeDialog 0; };";
			// TODO : Condition Keys or (Police or License) & canMove ! on veh
		};

		// TODO
		class Push : Repair {
			title = "Push";
			onClick = "hint ""Hello"";";
		};
	};
};