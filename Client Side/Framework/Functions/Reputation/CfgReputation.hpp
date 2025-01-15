class CfgReputation {
	Lowest = -1000;
	Highest = 1000;

	class Types {
		// Harming Others
		class ExecuteHigh { reason = "executed someone with a high reputation"; change = -50; };
		class ExecuteNorm { reason = "executed someone with a normal reputation"; change = -30; };
		class ExecuteLow { reason = "executed someone with a low reputation"; change = -20; };

		class IncapHigh { reason = "incapacitated someone with a high reputation"; change = -30; };
		class IncapNorm { reason = "incapacitated someone with a neutral reputation"; change = -15; };
		class IncapLow { reason = "incapacitated someone with a low reputation"; change = 25; };

		class AssaultHigh { reason = "have assaulted someone with a high rep"; change = -10; };
		class AssaultNorm { reason = "have assaulted someone with a normal rep"; change = -5; };
		
		class RobHigh { reason = "have robbed someone with a high rep"; change = -25; };
		class RobNorm { reason = "have robbed someone with a normal rep"; change = -20; };
		class RobLow { reason = "have robbed someone with a low rep"; change = -10; };

		class RobStore { reason = "have robbed a store"; change = -10; };

		class SeizeComms { reason = "destroyed someone's communications"; change = -5; };

		// Reviving
		class ReviveHigh { reason = "revived someone with a high rep"; change = 50; };
		class ReviveNorm { reason = "revived someone with a normal rep"; change = 30; };
		class ReviveLow { reason = "revived someone with a low rep"; change = 20; };

		class BloodHigh { reason = "have given someone with a high rep blood"; change = 5; };

		// Policing
		class ArrestHigh { reason = "arrested someone with a high rep"; change = 10; };
		class ArrestNorm { reason = "arrested someone with a normal rep"; change = 20; };
		class ArrestLow { reason = "arrested someone with a low rep"; change = 30; };

		class IssueTicket { reason = "issued a ticket to someone"; change = 10; };
		class SeizeLicense { reason = "seized someone's license"; change = 10; };

		// Removing Vehicles
		class ImpoundVehicle { reason = "impounded a vehicle"; change = 5; };
		class CrushVehicle { reason = "impounded a vehicle"; change = 5; };
		class ChopVehicle { reason = "have chopped someone's vehicle"; change = -50; };

		// Government
		class Vote { reason = "have supported democrazy by voting"; change = 50; };
		class Rig { reason = "have tried to sabotage democrazy"; change = -100; };
	};
};