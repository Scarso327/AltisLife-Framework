class CfgGovernment {
	electionInternal = 14;

	class Rigging {
		timeToRig = 30;
		alreadyRiggedMultiplier = 1.5;
	};
	
	class Legislation {
		class Tax {
			displayName = "Island Tax Rate";
			tooltip = "This changes the tax rate applied to certain prices across the island.";
			type = "NUMBER";
			format = "format [""%2%1"", ""%"", [_this select 1] call ULP_fnc_numberText]";
			values[] = { { 1, 10 }, 5 };
		};
		class Paychecks {
			displayName = "Paycheck Subsidies";
			tooltip = "This changes the amount of money added onto the paychecks of the citizens of altis.";
			type = "NUMBER";
			format = "format [""%1%2"", ""£"", [_this select 1] call ULP_fnc_numberText]";
			values[] = { { 2500, 7500 }, 5000 };
		};
		class Mission {
			displayName = "Job Pay Coverage";
			tooltip = "This changes the amount of money extra the government give for completing jobs.";
			type = "NUMBER";
			format = "format [""%1%2"", ""£"", [_this select 1] call ULP_fnc_numberText]";
			values[] = { { 0, 5 }, 0 };
		};
		class Service {
			displayName = "Air Service Pricing";
			tooltip = "This changes the the price for a unit of fuel at the air service station.";
			type = "NUMBER";
			format = "format [""%1%2"", ""£"", [_this select 1] call ULP_fnc_numberText]";
			values[] = { { 500, 1500 }, 1000 };
		};
		class Revival {
			displayName = "Revival Fee";
			tooltip = "This changes the amount of money paid to medics when reviving.";
			type = "NUMBER";
			format = "format [""%1%2"", ""£"", [_this select 1] call ULP_fnc_numberText]";
			values[] = { { 10000, 25000 }, 17500 };
		};
	};
};