class CfgInteractions {
	class Vehicle {
		class Repair {
			title = "Repair";
			onClick = "hint ""Hello"";";
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