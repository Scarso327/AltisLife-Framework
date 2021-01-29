class CfgFactions {
	defaultFaction = "Civilian";
	fallbackPay = 1000;

	class Police {
		displayName = "Malden Police Constabulary";
		pay = 2500;
		class Whitelisting {
			class Main {
				queryIndex = 12;
				payMulti = 0.1; // Pay increase per level...
				required = 1;
			};

			class ASO {
				queryIndex = 13;
			};

			class SFO {
				queryIndex = 14;
			};
		};

		class DatabaseInfo {
			queryPrefix = "cop_";
			customQuery = ", cop_blacklisted, coplevel, asolevel, sfolevel";
			timeIndex = 0;
		};

		class Loadout {
			class Uniforms {
				class U_Rangemaster {};
			};
			class LinkedItems {
				hasMap = true;
				hasGPS = true;
				hasCompass = true;
				hasWatch = true;
				hasRadio = true;
			};
		};
	};

	class Medic {
		displayName = "Malden Ambulance Service";
		pay = 2500;
		class Whitelisting {
			class Main {
				queryIndex = 12;
			};
			
			class TAA {
				queryIndex = 13;
			};
		};

		class DatabaseInfo {
			queryPrefix = "med_";
			customQuery = ", med_blacklisted, mediclevel, taalevel";
			timeIndex = 1;
		};

		class Loadout {
			class Uniforms {
				class U_Rangemaster {};
			};
			class LinkedItems {
				hasMap = true;
				hasGPS = true;
				hasCompass = true;
				hasWatch = true;
				hasRadio = true;
			};
		};
	};

	class Civilian {
		displayName = "Civilian";
		pay = 2500;
		class Groups {};
		class Housing {};
		class DatabaseInfo {
			queryPrefix = "civ_";
			customQuery = ", arrested";
			timeIndex = 2;
		};
		
		class Loadout {
			class Uniforms {
				class U_Rangemaster {};
			};
			class LinkedItems {
				hasMap = true;
				hasGPS = false;
				hasCompass = true;
				hasWatch = true;
				hasRadio = false;
			};
		};
	};
};