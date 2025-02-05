class CfgPowerStations {
	class Altis {
		class WesternPowerStation {
			displayName = "Western Power Station";
			tier = 1;
			condition = "[""plant_flag_1""] call ULP_fnc_ownsSite";
		};

		class EasternPowerStation {
			displayName = "Eastern Power Station";
			tier = 2;
			condition = "[""plant_flag_2""] call ULP_fnc_ownsSite";
		};
	};
};