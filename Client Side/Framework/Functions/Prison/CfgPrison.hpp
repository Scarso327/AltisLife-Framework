class CfgPrison {
	class Altis {
		marker = "hm_prison_altis";
		release[] = { { 9735.43, 12548.6, 0 }, 306 };
		maxDuraction = 30 * 60;

		class PrisonLoadout {
			class Uniforms {
				class U_C_Poor_1 {}; // TODO : Prisoner Uniform
			};
			class LinkedItems {
				hasMap = true;
				hasGPS = false;
				hasCompass = true;
				hasWatch = true;
				hasRadio = false;
			};
		};

		class ReleaseLoadout : PrisonLoadout {
			class Uniforms {
				class U_C_Poor_1 {};
			};
		};
	};
};