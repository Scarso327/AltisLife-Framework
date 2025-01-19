class CfgPrison {
	class Altis {
		marker = "hm_prison_altis";
		imprison[] = { { 9733.38, 12554.4, 0 }, 46 };
		release[] = { { 9694.23, 12551.3, 0 }, 285 };
		maxDuraction = 30 * 60;

		class PrisonLoadout {
			class Uniforms {
				class U_C_IDAP_Man_Tee_F {
					class Textures { class HMP {}; };
				};
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