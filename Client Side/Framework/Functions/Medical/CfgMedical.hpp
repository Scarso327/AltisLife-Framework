class CfgMedical {
	class Damage {
		amount = 3;
		maxWounds = 5;

		class Abrasion {
			time = 4;
			items[] = { 
				{ "FieldDressing", { 5, 1 } }, 
				{ "Packing", { 6, 1 } }, 
				{ "Elastic", { 3, 1 } },
				{ "QuickClot", { 0, 0.7 } } 
			};
		};
		class Avulsion {
			time = 9;
			items[] = { 
				{ "FieldDressing", { 5, 0.3 } }, 
				{ "Packing", { 6, 1 } }, 
				{ "Elastic", { 3, 0.3 } },
				{ "QuickClot", { 0, 0.2 } } 
			};
		};
		class Laceration {
			time = 6;
			items[] = { 
				{ "FieldDressing", { 5, 0.7 } }, 
				{ "Packing", { 6, 0.3 } }, 
				{ "Elastic", { 3, 1 } },
				{ "QuickClot", { 0, 0.7 } } 
			};
		};
		class Puncture {
			time = 7;
			items[] = { 
				{ "FieldDressing", { 5, 0.5 } }, 
				{ "Packing", { 6, 0.75 } }, 
				{ "Elastic", { 3, 0.6 } },
				{ "QuickClot", { 0, 0.5 } } 
			};
		};
	};
};