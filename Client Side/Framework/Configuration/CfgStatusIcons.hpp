class CfgStatusIcons {
	class Base {
		factions[] = { "Police", "Medic", "Civilian" };
		condition = "true";
	};

	class Seatbelt : Base {
		icon = "Data\UI\seatbelt.paa";
		condition = "isNull (objectParent player) && { !(player getVariable[""seatBelt"", false]) }";
	};
};