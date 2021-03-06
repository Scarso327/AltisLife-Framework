class CfgInteractions {
	class Vehicle {
		class Repair {
			title = "Repair";
			onClick = "_this call ULP_fnc_repairVehicle";
			factions[] = { "Police", "Medic", "Civilian" };
			condition = "true";
		};

		class Impound : Repair {
			title = "Impound";
			onClick = "hint ""Hello"";";
			factions[] = { "Police" };
		};
	};
};