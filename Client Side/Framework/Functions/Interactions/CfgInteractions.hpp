class CfgInteractions {
	/* GENERAL INTERACTIONS */
	// Show ID	
	// Show Licenses	
	// Give Cash
	// Give Keys

	/* RESTRAINED INTERACTIONS */
	// Unrestrain
	// Escort/Stop Escorting
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

		// TODO
		class Garage : Repair {
			title = "Garage";
			onClick = "hint ""Hello"";";
			factions[] = { "Police", "Hato" };
			condition = "[""Police_Main"", 2] call ULP_fnc_hasAccess || { [""Medic_Main"", 2] call ULP_fnc_hasAccess }";
		};

		// TODO
		class Impound : Repair {
			title = "Impound";
			onClick = "hint ""Hello"";";
			factions[] = { "Police", "Hato" };
			condition = "[""Police_Main"", 3] call ULP_fnc_hasAccess";
		};

		// TODO
		class Scrap : Repair {
			title = "Scrap";
			onClick = "hint ""Hello"";";
			factions[] = { "Police" };
			condition = "[""Police_Main"", 3] call ULP_fnc_hasAccess";
		};

		// TODO
		class PulloutOccupants : Repair {
			title = "Pullout Occupants";
			onClick = "hint ""Hello"";";
		};

		// TODO
		class Push : Repair {
			title = "Push";
			onClick = "hint ""Hello"";";
		};
	};
};