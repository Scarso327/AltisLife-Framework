class CfgFactions {
	defaultFaction = "Civilian";

	class Police {
		displayName = "National Health Service";
		class Whitelisting {
			class Main {
				queryIndex = 12;
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
		class Groups {};
		class Housing {};
		class DatabaseInfo {
			queryPrefix = "civ_";
			customQuery = ", arrested";
			timeIndex = 2;
		};
	};
};