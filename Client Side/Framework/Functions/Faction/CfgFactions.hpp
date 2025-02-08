class CfgFactions {
	defaultFaction = "Civilian";
	fallbackPay = 4600;

	class Police {
		shortName = "Police";
		displayName = "Altis Police Constabulary";
		selectionImage = "Data\UI\Factions\police.paa";
		selectionVideo = "\a3\Ui_f\Video\spotlight_2.ogv";
		colour[] = { 0, 0.3, 0.6, 1 };
		pay = 10200;
		sideChannel = false;
		jointChannel = true;
		imprison = true;
		hasRedzoneNlr = true;

		class Whitelisting {
			class Main {
				queryIndex = 26;
				payMulti = 0.1;
				required = 1;
			};
			class COL {
				queryIndex = 27;
				payMulti = 0.2;
			};
			class NPAS { queryIndex = 28; };
			class SCO { queryIndex = 29; };
			class NCA { queryIndex = 30; };
			class MPU { queryIndex = 31; };
			class RPU { queryIndex = 32; };
			class SFO { queryIndex = 33; };
			class UC { queryIndex = 34; };
		};

		class DatabaseInfo {
			queryPrefix = "cop_";
			customQuery = ", cop_blacklisted, coplevel, collevel, npaslevel, scolevel, ncalevel, mpulevel, rpulevel, sfolevel, uclevel";
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
			virtualItems[] = { { "Identification", "[name player] call ULP_fnc_stripString" }, { "PanicButton", 1 } };
		};
	};

	class Medic {
		shortName = "Medic";
		displayName = "Altis Ambulance Service";
		selectionImage = "Data\UI\Factions\medic.paa";
		selectionVideo = "\a3\Ui_f\Video\spotlight_2.ogv";
		colour[] = { 0, 0.5, 0, 1 };
		pay = 11600;
		sideChannel = false;
		jointChannel = true;
		hasRedzoneNlr = false;

		class Whitelisting {
			class Main {
				queryIndex = 26;
				payMulti = 0.15;
				required = 1;
			};
			class AA { queryIndex = 27; };
			class HART { queryIndex = 28; };
			class HR {
				queryIndex = 29;
				payMulti = 0.2;
			};
		};

		class DatabaseInfo {
			queryPrefix = "med_";
			customQuery = ", med_blacklisted, mediclevel, aalevel, hartlevel, hrlevel";
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
			virtualItems[] = { { "Identification", "[name player] call ULP_fnc_stripString" }, { "MediKit", 1 }, { "Defibrillator", 1 }, { "PanicButton", 1 } };
		};
	};

	class Hato {
		shortName = "HATO";
		displayName = "Highways Agency";
		selectionImage = "Data\UI\Factions\hato.paa";
		selectionVideo = "\a3\Ui_f\Video\spotlight_2.ogv";
		colour[] = { 0.7, 0.6, 0, 1 };
		pay = 10060;
		sideChannel = false;
		jointChannel = true;
		hasRedzoneNlr = false;
		
		class Whitelisting {
			class Main {
				queryIndex = 26;
				payMulti = 0.4;
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
			virtualItems[] = { { "Identification", "[name player] call ULP_fnc_stripString" }, { "PanicButton", 1 } };
		};
	};

	class Civilian {
		shortName = "Civilian";
		displayName = "Civilian";
		selectionImage = "Data\UI\Factions\civ.paa";
		selectionVideo = "\a3\Ui_f\Video\spotlight_2.ogv";
		colour[] = { 0.4, 0, 0.5, 1 };
		pay = 3750;
		sideChannel = true;
		imprisoned = true;
		hasRedzoneNlr = false;
		
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
				hasRadio = true;
			};
			virtualItems[] = { { "Identification", "[name player] call ULP_fnc_stripString" } };
		};
	};
};