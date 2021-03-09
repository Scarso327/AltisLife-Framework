class CfgApps {
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
		onload = "(_this displayCtrl 23001) ctrlSetStructuredText parseText format["" <t align='left'>%1</t><t align='right'>£%2</t>"", name player, [life_atmbank] call ULP_fnc_numberText]";
	};

	class Profile : BaseScreen {
		idc = 23002;
		pageTitle = "Profile";
		pageIdcs[] = {};
		rebindEsc = "";
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
		pageIdcs[] = {};
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
		pageIdcs[] = {};
	};

	class Goals : BaseScreen {
		idc= 23009;
		pageTitle = "Goals";
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
		pageIdcs[] = {};
	};
};