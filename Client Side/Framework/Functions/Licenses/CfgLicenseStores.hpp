class CfgLicenseStores {
	class DVLA {
		title = "Driver and Vehicle Licensing Agency";
		factions[] = { "Civilian" };
		condition = "true";
		licenses[] = { "Driving", "Trucking", "Boating", "Piloting" };
	};

	class Taxi {
		title = "Taxi Altis";
		factions[] = { "Civilian" };
		condition = "[""CompletedCV""] call ULP_fnc_hasPerk";
		licenses[] = { "Taxi" };
	};
	class Solicitor : Taxi {
		title = "Altis Solicitors";
		licenses[] = { "Solicitor" };
	};
	class News : Taxi {
		title = "AAN World News";
		licenses[] = { "News" };
	};
	class IDAP : Taxi {
		title = "IDAP Volunteer";
		licenses[] = { "IDAP" };
	};

	class Process {
		title = "Processing Site";
		factions[] = { "Civilian" };
		condition = "true";
	};
	class Schnapps : Process { licenses[] = { "Schnapps" }; };
	class Tobacco : Process { licenses[] = { "Tobacco" }; };
	class Copper : Process { licenses[] = { "Copper" }; };
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
		condition = "[""Rebel""] call ULP_fnc_hasLicense && { [""Blackmarketer""] call ULP_fnc_hasPerk } && { [""Blackmarket""] call ULP_fnc_hasGroupPerk }";
		licenses[] = { "Blackmarket" };
	};
}; 