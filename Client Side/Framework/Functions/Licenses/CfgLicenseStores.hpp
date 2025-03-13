class CfgLicenseStores {
	class DVLA {
		title = "DVLA";
		factions[] = { "Civilian", "Dunamis" };
		condition = "!([""Driving""] call ULP_fnc_hasLicense) || { !([""Trucking""] call ULP_fnc_hasLicense) } || { !([""Boating""] call ULP_fnc_hasLicense) } || { !([""Piloting""] call ULP_fnc_hasLicense) }";
		licenses[] = { "Driving", "Trucking", "Boating", "Piloting" };
	};

	class Taxi : DVLA {
		title = "Taxi Altis";
		condition = "!([""Taxi""] call ULP_fnc_hasLicense)";
		licenses[] = { "Taxi" };
	};
	class Solicitor : DVLA {
		title = "Altis Solicitors";
		condition = "!([""Solicitor""] call ULP_fnc_hasLicense)";
		licenses[] = { "Solicitor" };
	};
	class News : DVLA {
		title = "AAN World News";
		condition = "!([""News""] call ULP_fnc_hasLicense)";
		licenses[] = { "News" };
	};
	class IDAP : DVLA {
		title = "IDAP Volunteer";
		condition = "!([""IDAP""] call ULP_fnc_hasLicense) && { ULP_Reputation >= 0 }";
		licenses[] = { "IDAP" };
	};

	class Schnapps : DVLA { 
		title = "Schnapps Processing";
		condition = "!([""Schnapps""] call ULP_fnc_hasLicense)";
		licenses[] = { "Schnapps" }; 
	};
	class Tobacco : DVLA { 
		title = "Tobacco Processing";
		condition = "!([""Tobacco""] call ULP_fnc_hasLicense)";
		licenses[] = { "Tobacco" }; 
	};
	class Copper : DVLA { 
		title = "Copper Processing";
		condition = "!([""Copper""] call ULP_fnc_hasLicense)";
		licenses[] = { "Copper" }; 
	};
	class Silver : DVLA { 
		title = "Silver Processing";
		condition = "!([""Silver""] call ULP_fnc_hasLicense)";
		licenses[] = { "Silver" }; 
	};
	class Iron : DVLA { 
		title = "Iron Processing";
		condition = "!([""Iron""] call ULP_fnc_hasLicense)";
		licenses[] = { "Iron" }; 
	};
	class Uranium : DVLA { 
		title = "Uranium Processing";
		condition = "!([""Uranium""] call ULP_fnc_hasLicense)";
		licenses[] = { "Uranium" }; 
	};
	class Diamond : DVLA { 
		title = "Diamond Processing";
		condition = "!([""Diamond""] call ULP_fnc_hasLicense)";
		licenses[] = { "Diamond" }; 
	};
	class Salt : DVLA { 
		title = "Salt Processing";
		condition = "!([""Salt""] call ULP_fnc_hasLicense)";
		licenses[] = { "Salt" }; 
	};
	class Sand : DVLA { 
		title = "Sand Processing";
		condition = "!([""Sand""] call ULP_fnc_hasLicense)";
		licenses[] = { "Sand" }; 
	};
	class Oil : DVLA { 
		title = "Oil Processing";
		condition = "!([""Oil""] call ULP_fnc_hasLicense)";
		licenses[] = { "Oil" }; 
	};
	class Weed : DVLA { 
		title = "Weed Processing";
		condition = "!([""Weed""] call ULP_fnc_hasLicense)";
		licenses[] = { "Weed" }; 
	};
	class Heroin : DVLA { 
		title = "Heroin Processing";
		condition = "!([""Heroin""] call ULP_fnc_hasLicense)";
		licenses[] = { "Heroin" }; 
	};
	class Cocaine : DVLA {
		title = "Cocaine Processing";
		condition = "!([""Cocaine""] call ULP_fnc_hasLicense)"; 
		licenses[] = { "Cocaine" }; 
	};
	class Meth : DVLA { 
		title = "Meth Processing";
		condition = "!([""Meth""] call ULP_fnc_hasLicense)";
		licenses[] = { "Meth" }; 
	};
	class Moonshine : DVLA { 
		title = "Moonshine Processing";
		condition = "!([""Moonshine""] call ULP_fnc_hasLicense)";
		licenses[] = { "Moonshine" }; 
	};
	class Weapons : DVLA { 
		title = "Weapons Processing";
		condition = "!([""Weapons""] call ULP_fnc_hasLicense)";
		licenses[] = { "Weapons" }; 
	};
	class MultiDrug : DVLA {
		title = "Multi-Drug Processing";
		condition = "!([""Weed""] call ULP_fnc_hasLicense) || { !([""Heroin""] call ULP_fnc_hasLicense) } || { !([""Cocaine""] call ULP_fnc_hasLicense) } || { !([""ULP_fnc_hasLicense""] call ULP_fnc_hasLicense) } || { !([""Moonshine""] call ULP_fnc_hasLicense) }";
		licenses[] = { "Weed", "Heroin", "Cocaine", "Meth", "Moonshine" };
	};

	class Home : DVLA {
		title = "Homeowner's Association";
		condition = "!([""Home""] call ULP_fnc_hasLicense)";
		licenses[] = { "Home" };
	};

	class Gun : DVLA {
		title = "Gun Store";
		condition = "!([""Handgun""] call ULP_fnc_hasLicense) || { !([""SMG""] call ULP_fnc_hasLicense) }";
		licenses[] = { "Handgun", "SMG" };
	};
	class Security : DVLA {
		title = "Security Contractors";
		condition = "!([""Security""] call ULP_fnc_hasLicense)";
		licenses[] = { "Security" };
	};
	class Protection : DVLA {
		title = "Government Protection";
		condition = "!([""Protection""] call ULP_fnc_hasLicense)";
		licenses[] = { "Protection" };
	};

	class Hunting : DVLA {
		title = "Hutning Camp";
		condition = "!([""Hunting""] call ULP_fnc_hasLicense)";
		licenses[] = { "Hunting" };
	};

	class Rebel : DVLA {
		title = "Rebel";
		condition = "!([""Rebel""] call ULP_fnc_hasLicense)";
		licenses[] = { "Rebel" };
	};

	class Blackmarket : DVLA {
		title = "Blackmarket";
		condition = "[""Rebel""] call ULP_fnc_hasLicense && { !([""Blackmarket""] call ULP_fnc_hasLicense) } && { [""Blackmarketer""] call ULP_fnc_hasPerk || [""Blackmarket""] call ULP_fnc_hasGroupPerk }";
		licenses[] = { "Blackmarket" };
	};
}; 
