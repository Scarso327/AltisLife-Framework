/*
	@File: CfgPaychecks.hpp
	@Author: Jack "Scarso" Farhall & Lewis Mackinnon
	@Description: Configures the paycheck settings.
*/
class CfgPaychecks {
	class west {
		class levels {
			class life_coplevel {
				paychecks[] = {
					0, // Unwhitelisted
					5000, // Police Cadet
					6000, // Police Constable
					7000, // Senior Police Constable
					8000, // Sergeant
					9000, // Inspector
					10000, // Chief Inspector
					11000, // Superintendent
					12000, // Chief Superintendent
					13000, // Deputy Commissioner
					14000, // Commissioner
					15000 // Commander
				};
			};
		};

		class licenses {
			class sfo1 {
				paycheck = paycheck + 1000;
			};

			class sfo2 {
				paycheck = paycheck + 2000;
			};

			class sfo3 {
				paycheck = paycheck + 3000;
			};

			class aso1 {
				paycheck = paycheck + 1000;
			};

			class aso2 {
				paycheck = paycheck + 2000;
			};

			class aso3 {
				paycheck = paycheck + 3000;
			};
		};
	};

	class independent {
		class levels {
			class life_mediclevel {
				paychecks[] = {
					0, // Level 0
					5000, // Medical Student
					7500, // Nurse
					10000, // Junior Doctor
					12500, // Emergency Doctor
					15000, // Consultant
					17500 // Regional Director
				};
			};
		};

		class licenses {
			class taa1 {
				paycheck = paycheck + 2000;
			};
			class taa2 {
				paycheck = paycheck + 4000;
			};
			class taa3 {
				paycheck = paycheck + 6000;
			};
		};
	};
}; 