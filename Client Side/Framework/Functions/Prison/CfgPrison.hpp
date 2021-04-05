class CfgPrison {
	class Altis {
		marker = "hm_prison_altis";
		release[] = { { 12335.884, 14370.2, 0 }, 49 };
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