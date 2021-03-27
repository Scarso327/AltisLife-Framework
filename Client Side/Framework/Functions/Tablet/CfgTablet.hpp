class CfgTablet {
	globalIdcs[] = {
		23001, 23012, 23013
	};

	class BaseScreen {
		idc = -1;
		pageTitle = "";
		pageIdcs[] = {};
		onLoad = "";
		onUnload = "";
		rebindEsc = "";
	};

	class Home : BaseScreen {
		idc = -1;
		pageTitle = "";
		pageIdcs[] = {
			23002, 23003, 23004, 23005, 23006, 23007, 23008, 23009, 23010, 23011
		};
		onload = "(_this displayCtrl 23001) ctrlSetStructuredText parseText format[""<t align='left'>%1</t><t align='right'>£%2</t>"", name player, [ULP_547_Bank] call ULP_fnc_numberText]";
	};

	class Profile : BaseScreen {
		idc = 23002;
		pageTitle = "Profile";
		pageIdcs[] = {
			23024, 23025, 23026, 23027, 23028
		};
		onload = "_this call ULP_fnc_profile";
	};

	class Professions : Profile {
		pageTitle = "Profile - Professions";
		pageIdcs[] = {
			23024, 23025, 23026, 23027, 23028, 23029, 23030
		};
		onload = "_this call ULP_fnc_professions";
	};

	class Achievements : Profile {
		pageTitle = "Profile - Achievements";
		pageIdcs[] = {
			23024, 23025, 23026, 23027, 23028, 23029, 23030
		};
		onload = "_this call ULP_fnc_achievements";
	};

	class Loyalty : Profile {
		pageTitle = "Profile - Personal Goals";
		pageIdcs[] = {
			23024, 23025, 23026, 23027, 23028, 23029, 23030
		};
		onload = "_this call ULP_fnc_personalGoals";
	};

	class PlayerTag : Profile {
		pageTitle = "Profile - Player Tag";
		pageIdcs[] = {
			23024, 23025, 23026, 23027, 23028
		};
		onload = "";
	};

	class Inventory : BaseScreen {
		idc= 23003;
		pageTitle = "Inventory";
		pageIdcs[] = {
			23014, 23015, 23016, 23017, 23018, 23019
		};
		onload = "_this call ULP_fnc_inventory";
	};

	class Messaging : BaseScreen {
		idc= 23004;
		pageTitle = "Messaging";
		pageIdcs[] = {
			23036, 23037, 23038, 23039, 23040, 23041, 23042, 23043, 23044, 23045, 23046, 23047, 23048, 23049, 23050
		};
		onload = "_this call ULP_fnc_messages";
	};

	class Group : BaseScreen {
		idc= 23005;
		pageTitle = "Group";
		pageIdcs[] = {};
	};

	class Keys : BaseScreen {
		idc= 23006;
		pageTitle = "Keys";
		pageIdcs[] = {
			23021, 23022
		};
		onload = "_this call ULP_fnc_keys";
	};

	class Dispute : BaseScreen {
		idc= 23007;
		pageTitle = "Dispute";
		pageIdcs[] = {};
	};

	class Market : BaseScreen {
		idc= 23008;
		pageTitle = "Market";
		pageIdcs[] = {
			23032, 23033, 23034, 23035
		};
		onload = "_this call ULP_fnc_market";
	};

	class Goals : BaseScreen {
		idc= 23009;
		pageTitle = "Community Goals";
		pageIdcs[] = {};
	};

	class Perks : BaseScreen {
		idc= 23010;
		pageTitle = "Perks";
		pageIdcs[] = {};
	};

	class Settings {
		idc= 23011;
		pageTitle = "Settings";
		pageIdcs[] = {
			23023
		};
		onload = "_this call ULP_fnc_options";
		onUnload = "saveProfileNamespace;";
	};
};