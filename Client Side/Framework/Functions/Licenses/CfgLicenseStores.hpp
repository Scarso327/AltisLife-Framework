class CfgLicenseStores {
	class DVLA {
		title = "Driver and Vehicle Licensing Agency";
		factions[] = { "Civilian" };
		condition = "!([""Driving""] call ULP_fnc_hasLicense) || { !([""Trucking""] call ULP_fnc_hasLicense) } || { !([""Boating""] call ULP_fnc_hasLicense) } || { !([""Piloting""] call ULP_fnc_hasLicense) }";
		licenses[] = { "Driving", "Trucking", "Boating", "Piloting" };
	};

	class Taxi {
		title = "Taxi Altis";
		factions[] = { "Civilian" };
		condition = "[""CompletedCV""] call ULP_fnc_hasPerk && { !([""Taxi""] call ULP_fnc_hasLicense) }";
		licenses[] = { "Taxi" };
	};
	class Solicitor : Taxi {
		title = "Altis Solicitors";
		condition = "[""CompletedCV""] call ULP_fnc_hasPerk && { !([""Solicitor""] call ULP_fnc_hasLicense) }";
		licenses[] = { "Solicitor" };
	};
	class News : Taxi {
		title = "AAN World News";
		condition = "[""CompletedCV""] call ULP_fnc_hasPerk && { !([""News""] call ULP_fnc_hasLicense) }";
		licenses[] = { "News" };
	};
	class IDAP : Taxi {
		title = "IDAP Volunteer";
		condition = "!([""IDAP""] call ULP_fnc_hasLicense)";
		licenses[] = { "IDAP" };
	};

	class Process {
		title = "Processing Site";
		factions[] = { "Civilian" };
	};
	class Schnapps : Process { 
		condition = "!([""Schnapps""] call ULP_fnc_hasLicense)";
		licenses[] = { "Schnapps" }; 
	};
	class Tobacco : Process { 
		condition = "!([""Tobacco""] call ULP_fnc_hasLicense)";
		licenses[] = { "Tobacco" }; 
	};
	class Copper : Process { 
		condition = "!([""Copper""] call ULP_fnc_hasLicense)";
		licenses[] = { "Copper" }; 
	};
	class Silver : Process { 
		condition = "!([""Silver""] call ULP_fnc_hasLicense)";
		licenses[] = { "Silver" }; 
	};
	class Iron : Process { 
		condition = "!([""Iron""] call ULP_fnc_hasLicense)";
		licenses[] = { "Iron" }; 
	};
	class Uranium : Process { 
		condition = "!([""Uranium""] call ULP_fnc_hasLicense)";
		licenses[] = { "Uranium" }; 
	};
	class Diamond : Process { 
		condition = "!([""Diamond""] call ULP_fnc_hasLicense)";
		licenses[] = { "Diamond" }; 
	};
	class Salt : Process { 
		condition = "!([""Salt""] call ULP_fnc_hasLicense)";
		licenses[] = { "Salt" }; 
	};
	class Sand : Process { 
		condition = "!([""Sand""] call ULP_fnc_hasLicense)";
		licenses[] = { "Sand" }; 
	};
	class Oil : Process { 
		condition = "!([""Oil""] call ULP_fnc_hasLicense)";
		licenses[] = { "Oil" }; 
	};
	class Weed : Process { 
		condition = "!([""Weed""] call ULP_fnc_hasLicense)";
		licenses[] = { "Weed" }; 
	};
	class Heroin : Process { 
		condition = "!([""Heroin""] call ULP_fnc_hasLicense)";
		licenses[] = { "Heroin" }; 
	};
	class Cocaine : Process {
		condition = "!([""Cocaine""] call ULP_fnc_hasLicense)"; 
		licenses[] = { "Cocaine" }; 
	};
	class Meth : Process { 
		condition = "!([""Meth""] call ULP_fnc_hasLicense)";
		licenses[] = { "Meth" }; 
	};
	class Moonshine : Process { 
		condition = "!([""Moonshine""] call ULP_fnc_hasLicense)";
		licenses[] = { "Moonshine" }; 
	};
	class MultiDrug : Process {
		condition = "!([""Weed""] call ULP_fnc_hasLicense) || { !([""Heroin""] call ULP_fnc_hasLicense) } || { !([""Cocaine""] call ULP_fnc_hasLicense) } || { !([""ULP_fnc_hasLicense""] call ULP_fnc_hasLicense) } || { !([""Moonshine""] call ULP_fnc_hasLicense) }";
		licenses[] = { "Weed", "Heroin", "Cocaine", "Meth", "Moonshine" };
	};

	class Home {
		title = "Homeowner's Association";
		factions[] = { "Civilian" };
		condition = "!([""Home""] call ULP_fnc_hasLicense)";
		licenses[] = { "Home" };
	};

	class Handgun {
		title = "Handgun Store";
		factions[] = { "Civilian", "Medic", "Hato" };
		condition = "!([""Handgun""] call ULP_fnc_hasLicense)";
		licenses[] = { "Handgun" };
	};

	class Security {
		title = "Security Contractors";
		factions[] = { "Civilian" };
		condition = "!([""Security""] call ULP_fnc_hasLicense)";
		licenses[] = { "Security" };
	};

	class Protection {
		title = "Government Protection";
		factions[] = { "Civilian" };
		condition = "!([""Protection""] call ULP_fnc_hasLicense)";
		licenses[] = { "Protection" };
	};

	class Hunting {
		title = "Hutning Camp";
		factions[] = { "Civilian" };
		condition = "!([""Hunting""] call ULP_fnc_hasLicense)";
		licenses[] = { "Hunting" };
	};

	class Rebel {
		title = "Rebel Access";
		factions[] = { "Civilian" };
		condition = "!([""Rebel""] call ULP_fnc_hasLicense)";
		licenses[] = { "Rebel" };
	};

	class Blackmarket {
		title = "Blackmarket Access";
		factions[] = { "Civilian" };
		condition = "[""Rebel""] call ULP_fnc_hasLicense && { !([""Blackmarket""] call ULP_fnc_hasLicense) } && { [""Blackmarketer""] call ULP_fnc_hasPerk || [""Blackmarket""] call ULP_fnc_hasGroupPerk }";
		licenses[] = { "Blackmarket" };
	};
}; 
