class CfgPrison {
	class Altis {
		marker = "hm_prison_altis";
		imprison[] = { { 12572.1, 16522.1, 0 }, 328 }; 
		release[] = { { 12606.3, 16445.5, 0 }, 28 };
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