class CfgFactions {
	defaultFaction = "Civilian";
	fallbackPay = 1000;

	class Police {
		displayName = "National Health Service";
		pay = 2500;
		class Whitelisting {
			class Main {
				queryIndex = 12;
				payMulti = 0.1; // Pay increase per level...
				required = 1;
			};
			class NPAS {
				queryIndex = 13;
			};
		};
		class DatabaseInfo {
			queryPrefix = "cop_";
			customQuery = ", cop_blacklisted, coplevel, npaslevel";
			timeIndex = 0;
		};
	};
	class Medic {
		displayName = "National Health Service";
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
		displayName = "National Health Service";
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