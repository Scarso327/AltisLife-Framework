class CfgFactions {
	defaultFaction = "Civilian";
	fallbackPay = 1000;

	class Police {
		displayName = "Altis Police Constabulary";
		colour[] = { 0, 0.3, 0.6, 1 };
		pay = 15000;
		jointChannel = true;
		imprison = true;		

		class Whitelisting {
			class Main {
				queryIndex = 26;
				payMulti = 0.1;
				required = 1;
			};
			class RTA {
				queryIndex = 27;
				payMulti = 0.025;
			};
			class NPAS { queryIndex = 28; };
			class SCO { queryIndex = 29; };
			class NCA { queryIndex = 30; };
			class MPU { queryIndex = 31; };
			class RPU { queryIndex = 32; };
			class AFO { queryIndex = 33; };
			class UC { queryIndex = 34; };
		};

		class DatabaseInfo {
			queryPrefix = "cop_";
			customQuery = ", cop_blacklisted, coplevel, rtalevel, npaslevel, scolevel, ncalevel, mpulevel, rpulevel, afolevel, uclevel";
			arrayIndexes[] = {};
			mapIndexes[] = {};
			boolIndexes[] = {};
			timeIndex = 0;
		};

		class Persistance {
			vehicles = false;
		};

		class Free {
			physical = true;
			vehicles = true;
		};

		class Loadout {
			canRestLoadout = true;
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
		displayName = "National Health Service";
		colour[] = { 0, 0.5, 0, 1 };
		pay = 16000;
		jointChannel = true;

		class Whitelisting {
			class Main {
				queryIndex = 26;
				payMulti = 0.15;
				required = 1;
			};
			class AA { queryIndex = 27; };
			class HR {
				queryIndex = 28;
				payMulti = 0.025;
			};
		};

		class DatabaseInfo {
			queryPrefix = "med_";
			customQuery = ", med_blacklisted, mediclevel, aalevel, hrlevel";
			arrayIndexes[] = {};
			mapIndexes[] = {};
			boolIndexes[] = {};
			timeIndex = 1;
		};

		class Persistance {
			vehicles = false;
		};

		class Free {
			physical = true;
			vehicles = true;
		};

		class Loadout {
			canRestLoadout = true;
			class Uniforms {
				class U_Competitor {};
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

	class Hato {
		displayName = "Highways Traffic Agency";
		colour[] = { 0.7, 0.6, 0, 1 };
		pay = 14500;
		jointChannel = true;
		
		class Whitelisting {
			class Main {
				queryIndex = 26;
				payMulti = 0.5;
				required = 1;
			};
		};

		class DatabaseInfo {
			queryPrefix = "hato_";
			customQuery = ", hato_blacklisted, hatolevel";
			arrayIndexes[] = {};
			mapIndexes[] = {};
			boolIndexes[] = {};
			timeIndex = 2;
		};

		class Persistance {
			vehicles = false;
		};

		class Free {
			physical = true;
			vehicles = true;
		};

		class Loadout {
			canRestLoadout = true;
			class Uniforms {
				class U_O_R_Gorka_01_black_F {};
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
		colour[] = { 0.4, 0, 0.5, 1 };
		pay = 7500;
		imprisoned = true;
		
		class Groups {};
		class Housing {};
		class DatabaseInfo {
			queryPrefix = "civ_";
			customQuery = ", arrested, prison_timer, coplevel, uclevel";
			arrayIndexes[] = {};
			mapIndexes[] = {};
			boolIndexes[] = {};
			timeIndex = 3;
		};

		class Persistance {
			vehicles = true;
		};
		
		class Loadout {
			canRestLoadout = false;
			class Uniforms {
				class U_C_Poor_1 {};
				class U_C_Poloshirt_blue {};
				class U_C_Man_casual_1_F {};
				class U_C_Man_casual_6_F {};
			};
			class LinkedItems {
				hasMap = true;
				hasGPS = false;
				hasCompass = true;
				hasWatch = true;
				hasRadio = false;
			};
			virtualItems[] = { { "Identification", "name player" }};
		};
	};
};