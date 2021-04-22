class CfgReputation {
	Lowest = -1000;
	Highest = 1000;

	class Types {
		// High Repuation
		class ReviveHighRep {
			reason = "Revived someone with a high reputation";
			change = 25;
		};

		class IncapHighRep {
			reason = "incapacitated someone with a high reputation";
			change = -25;
		};

		class KilledHighRep {
			reason = "killed someone with a high reputation";
			change = -50;
		};

		// Normal Repuation
		class ReviveNormal {
			reason = "Revived someone with a neutral reputation";
			change = 15;
		};

		class IncapNormal {
			reason = "incapacitated someone with a neutral reputation";
			change = -15;
		};

		class KilledNormal : IncapNormal {
			reason = "killed someone with a neutral reputation";
		};

		// Low Repuation
		class IncapLowRep {
			reason = "incapacitated someone with a Low reputation";
			change = 25;
		};

		class KilledLowRep {
			reason = "killed someone with a Low reputation";
			change = 50;
		};
	};
};