/*
	@File: CfgPaychecks.hpp
  
	@Author: Jack "Scarso" Farhall
  
	@Description: Paycheck settings...
*/

class CfgPaychecks {
    class west {
		class levels {
			class life_coplevel {
				paychecks[] = {
					1000, // Level 0
					1000, // Level 1
					1000, // Level 2
					1000, // Level 3
					1000, // Level 4
					1000, // Level 5
					1000 // Level 6
				};
			};
		};

		class licenses {
			class aso3 {
				paycheck = 1000;
			};
		};
	};
};