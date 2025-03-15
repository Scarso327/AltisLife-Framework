class CfgFactions {
	defaultFaction = "Civilian";
	fallbackPay = 5000;

	class Police {
		shortName = "Police";
		displayName = "Altis Police Constabulary";
		selectionImage = "Data\UI\Factions\police.paa";
		selectionVideo = "\a3\Ui_f\Video\spotlight_2.ogv";
		colour[] = { 0, 0.3, 0.6, 1 };
		pay = 12000;
		sideChannel = false;
		jointChannel = true;
		imprison = true;
		hasRedzoneNlr = true;

		class Whitelisting {
			class Main {
				queryIndex = 27;
				payMulti = 0.15;
				required = 1;
			};
			class COL {
				queryIndex = 28;
				payMulti = 0.25;
			};
			class NPAS { queryIndex = 29; };
			class SCO { queryIndex = 30; };
			class NCA { queryIndex = 31; };
			class MPU { queryIndex = 32; };
			class RPU { queryIndex = 33; };
			class SFO { queryIndex = 34; };
			class UC { queryIndex = 35; };
			class SEG { queryIndex = 36; };
		};

		class DatabaseInfo {
			queryPrefix = "cop_";
			customQuery = ", cop_blacklisted, coplevel, collevel, npaslevel, scolevel, ncalevel, mpulevel, rpulevel, sfolevel, uclevel, seglevel";
			arrayIndexes[] = {};
			mapIndexes[] = {};
			boolIndexes[] = {};
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
		pay = 13500;
		sideChannel = false;
		jointChannel = true;
		hasRedzoneNlr = false;

		class Whitelisting {
			class Main {
				queryIndex = 27;
				payMulti = 0.25;
				required = 1;
			};
			class AA { queryIndex = 28; };
			class HART { queryIndex = 29; };
			class HR {
				queryIndex = 30;
				payMulti = 0.25;
			};
		};

		class DatabaseInfo {
			queryPrefix = "med_";
			customQuery = ", med_blacklisted, mediclevel, aalevel, hartlevel, hrlevel";
			arrayIndexes[] = {};
			mapIndexes[] = {};
			boolIndexes[] = {};
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
		pay = 15000;
		sideChannel = false;
		jointChannel = true;
		hasRedzoneNlr = false;
		
		class Whitelisting {
			class Main {
				queryIndex = 27;
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
	
	class Dunamis {
		shortName = "Dunamis";
		displayName = "Dunamis";
		selectionImage = "Data\UI\Factions\dms.paa";
		selectionVideo = "\a3\Ui_f\Video\spotlight_2.ogv";
		colour[] = { 0.5, 0, 0, 1 };
		pay = 5000;
		sideChannel = true;
		imprisoned = true;
		hasRedzoneNlr = false;

		class Whitelisting {
			class Main {
				queryIndex = 28;
				payMulti = 0.15;
				required = 1;
			};
		};

		class DatabaseInfo {
			queryPrefix = "dms_";
			customQuery = ", dms_arrested, dms_prison_timer, dmslevel";
			arrayIndexes[] = {};
			mapIndexes[] = {};
			boolIndexes[] = {};
		};

		class Persistance {
			vehicles = true;
		};

		class Free {
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

	class Civilian {
		shortName = "Civilian";
		displayName = "Civilian";
		selectionImage = "Data\UI\Factions\civ.paa";
		selectionVideo = "\a3\Ui_f\Video\spotlight_2.ogv";
		colour[] = { 0.4, 0, 0.5, 1 };
		pay = 5000;
		sideChannel = true;
		imprisoned = true;
		hasRedzoneNlr = false;
		
		class Groups {};
		class Housing {};
		class DatabaseInfo {
			queryPrefix = "civ_";
			customQuery = ", civ_arrested, civ_prison_timer, coplevel, uclevel";
			arrayIndexes[] = {};
			mapIndexes[] = {};
			boolIndexes[] = {};
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