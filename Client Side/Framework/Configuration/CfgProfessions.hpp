class CfgProfessions {
	class Repairing {
		displayName = "Repairing";
		effectDescription = "Currently decreases the time it takes to repair by %1%2";
		effectCalculation = "5 * (_this select 0)"; // (_this select 0) refers to the level of this profession and (_this select 1) is the current xp.
		xpLevel = 100;
		xpMultipler = 2; // XP REQUIRED FOR LEVEL = xpLevel * (xpMultipler * CURRENT LEVEL) (If CURRENT LEVEL = 0 THEN xpMultipler isn't added)
		maxLevel = 5;
	};
};