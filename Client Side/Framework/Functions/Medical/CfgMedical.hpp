class CfgMedical {
	class Damage {
		amount = 2;

		class Abrasion {
			amount = 2;
			time = 4;
			items[] = { { "QuickClot", { 0, 0.25 } }, { "FieldDressing", { 5, 0.4 } }, { "Packing", { 5, 0.6 } }, { "Elastic", { 10, 0.85 } } };
		};
		class Laceration : Abrasion  {
			time = 6;
			items[] = { { "QuickClot", { 0, 0.25 } }, { "FieldDressing", { 5, 0.3 } }, { "Packing", { 7, 0.5 } }, { "Elastic", { 11, 0.75 } } };
		};
		class Puncture : Laceration {
			items[] = { { "QuickClot", { 2, 0.3 } }, { "FieldDressing", { 5, 0.25 } }, { "Packing", { 5, 0.3 } }, { "Elastic", { 8, 0.6 } } };
		};
		class Avulsion : Abrasion {
			time = 9;
			items[] = { { "QuickClot", { 0, 0.15 } }, { "FieldDressing", { 5, 0.35 } }, { "Packing", { 5, 0.5 } }, { "Elastic", { 8, 0.65 } } };
		};
	};
};