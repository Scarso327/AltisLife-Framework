class CfgReputation {
	Lowest = -1000;
	Highest = 1000;

	class Types {
		class IncapHighRep {
			reason = "incapacitated someone with a high reputation";
			change = -50;
		};

		class KilledHighRep {
			reason = "killed someone with a high reputation";
			change = -100;
		};

		class IncapNormal {
			reason = "incapacitated someone with a neutral reputation";
			change = -25;
		};

		class KilledNormal : IncapNormal {
			reason = "killed someone with a neutral reputation";
		};

		class IncapLowRep {
			reason = "incapacitated someone with a Low reputation";
			change = 50;
		};

		class KilledLowRep {
			reason = "killed someone with a Low reputation";
			change = 100;
		};
	};
};