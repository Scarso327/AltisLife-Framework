class CfgGovernment {
	class Options {
		class Tax {
			type = "NUMBER";
			values[] = { { 1, 10 }, 5 };
		};
		class Paychecks {
			type = "NUMBER";
			values[] = { { 2500, 7500 }, 5000 };
		};
		class Mission {
			type = "NUMBER";
			values[] = { { 0, 30 }, 15 };
		};
		class Service {
			type = "NUMBER";
			values[] = { { 500, 1500 }, 1000 };
		};
	};
};