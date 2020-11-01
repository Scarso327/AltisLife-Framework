class CfgFactions {
	defaultFaction = "Civilian";
	fallbackPay = 1000;

	class Police {
		displayName = "Tanoa Police Constabulary";
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
				queryIndex = 13;
			};
		};
		class DatabaseInfo {
			queryPrefix = "cop_";
			customQuery = ", cop_blacklisted, coplevel, asolevel, sfolevel";
			timeIndex = 0;
		};
	};
	class Medic {
		displayName = "Tanoa Ambulance Service";
		pay = 2500;
		class Whitelisting {
			class Main {
				queryIndex = 12;
			};
		};
		class DatabaseInfo {
			queryPrefix = "med_";
			customQuery = ", med_blacklisted, mediclevel";
			timeIndex = 1;
		};
	};
	class Civilian {
		displayName = "Civilian Population";
		pay = 2500;
		class Groups {};
		class Housing {};
		class DatabaseInfo {
			queryPrefix = "civ_";
			customQuery = ", arrested";
			timeIndex = 2;
		};
	};
};