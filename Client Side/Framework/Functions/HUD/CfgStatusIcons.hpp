class CfgStatusIcons {
	class Base {
		factions[] = { "Civilian", "Police", "Medic", "Hato" };
		condition = "true";
	};

	class Seatbelt : Base {
		icon = "Data\UI\seatbelt.paa";
		condition = "!isNull (objectParent player) && { !(player getVariable[""seatBelt"", false]) } && { (vehicle player) isKindOf ""LandVehicle"" }";
	};

	class Overweight : Base {
		icon = "Data\UI\overweight.paa";
		condition = "isForcedWalk player";
	};

	class RevivedRecently : Base {
		icon = "Data\UI\reviveCooldown.paa";
		condition = "missionNamespace getVariable [""ULP_LastRevived"", -300] > (time - 300)";
	};

	class NoCommunications : Base {
		icon = "Data\UI\noCommunications.paa";
		condition = "!([player] call ULP_fnc_hasComms)";
	};
};