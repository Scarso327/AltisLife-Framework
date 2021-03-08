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
		class VehicleBase {
			factions[] = { "Police", "Medic", "Hato", "Civilian" };
			condition = "ture";
		};

		class Repair : VehicleBase {
			title = "Repair";
			onClick = "_this call ULP_fnc_repairVehicle";
		};

		class Lockpick : VehicleBase {
			title = "Lockpick";
			onClick = "_this call ULP_fnc_repairVehicle";
		};

		class Registration : VehicleBase {
			title = "Registration";
			onClick = "hint ""Hello"";";
			factions[] = { "Police", "Hato" };
		};

		class Clamp : VehicleBase {
			title = "Clamp";
			onClick = "_this call ULP_fnc_repairVehicle";
			factions[] = { "Police", "Hato" };
		};

		class Search : VehicleBase {
			title = "Search";
			onClick = "hint ""Hello"";";
			factions[] = { "Police" };
		};

		class Garage : VehicleBase {
			title = "Garage";
			onClick = "hint ""Hello"";";
			factions[] = { "Police", "Hato" };
			condition = "[""Police_Main"", 2] call ULP_fnc_hasAccess || { [""Medic_Main"", 2] call ULP_fnc_hasAccess }";
		};

		class Impound : VehicleBase {
			title = "Impound";
			onClick = "hint ""Hello"";";
			factions[] = { "Police", "Hato" };
			condition = "[""Police_Main"", 3] call ULP_fnc_hasAccess";
		};

		class Scrap : VehicleBase {
			title = "Scrap";
			onClick = "hint ""Hello"";";
			factions[] = { "Police" };
			condition = "[""Police_Main"", 3] call ULP_fnc_hasAccess";
		};

		class PulloutOccupants : VehicleBase {
			title = "Pullout Occupants";
			onClick = "hint ""Hello"";";
		};

		class Push : VehicleBase {
			title = "Push";
			onClick = "hint ""Hello"";";
		};
	};
};