class CfgLicenseStores {
	class DVLA {
		title = "Driver and Vehicle Licensing Agency";
		factions[] = { "Civilian" };
		condition = "true";
		licenses[] = { "Driving", "Trucking", "Boating", "Piloting" };
	};

	class Job {
		title = "Altis Job Market";
		factions[] = { "Civilian" };
		condition = "true";
		licenses[] = { "Taxi", "Solicitor", "News" };
	};

	class Process {
		title = "Processing Site";
		factions[] = { "Civilian" };
		condition = "true";
	};
	class Schnapps : Process { licenses[] = { "Schnapps" }; };
	class Tobacco : Process { licenses[] = { "Tobacco" }; };
	class Copper : Process { licenses[] = { "Tobacco" }; };
	class Silver : Process { licenses[] = { "Silver" }; };
	class Iron : Process { licenses[] = { "Iron" }; };
	class Uranium : Process { licenses[] = { "Uranium" }; };
	class Diamond : Process { licenses[] = { "Diamond" }; };
	class Salt : Process { licenses[] = { "Salt" }; };
	class Sand : Process { licenses[] = { "Sand" }; };
	class Oil : Process { licenses[] = { "Oil" }; };
	class Weed : Process { licenses[] = { "Weed" }; };
	class Heroin : Process { licenses[] = { "Heroin" }; };
	class Cocaine : Process { licenses[] = { "Cocaine" }; };
	class Meth : Process { licenses[] = { "Meth" }; };
	class Moonshine : Process { licenses[] = { "Moonshine" }; };
	class MultiDrug : Process {
		licenses[] = { "Weed", "Heroin", "Cocaine", "Meth", "Moonshine" };
	};

	class Home {
		title = "Homeowner's Association";
		factions[] = { "Civilian" };
		condition = "true";
		licenses[] = { "Home" };
	};

	class Handgun {
		title = "Handgun Store";
		factions[] = { "Civilian", "Medic", "Hato" };
		condition = "true";
		licenses[] = { "Handgun" };
	};

	class Hunting {
		title = "Hutning Camp";
		factions[] = { "Civilian" };
		condition = "true";
		licenses[] = { "Hunting" };
	};

	class Rebel {
		title = "Rebel Access";
		factions[] = { "Civilian" };
		condition = "true";
		licenses[] = { "Rebel" };
	};

	class Blackmarket {
		title = "Blackmarket Access";
		factions[] = { "Civilian" };
		condition = "true";
		licenses[] = { "Blackmarket" };
	};
}; 