class CfgCapture {
	class Altis {
		class WestHideout {
			displayName = "Western Criminal Hideout";
			time = 180;
			cooldown = 180;
			class Marker {
				markerType = "loc_Bunker";
				markerColour = "ColorEast";
				markerName = "criminal_hideout_1";
				defaultName = "Criminal Hideout";
			};
			condition = "[""Hideout""] call ULP_fnc_hasGroupPerk";
		};
		class EastHideout : WestHideout {
			displayName = "Eastern Criminal Hideout";
			class Marker : Marker {
				markerName = "criminal_hideout_2";
			};
		};

		class WesternPowerStation {
			displayName = "Western Power Station";
			time = 180;
			cooldown = 300;
			class Marker {
				markerType = "loc_Power";
				markerColour = "ColorEast";
				markerName = "western_power_plant";
				defaultName = "Western Power Station";
			};
			condition = "[] call ULP_fnc_isGroup";
		};
		class EasternPowerStation : WesternPowerStation {
			displayName = "Eastern Power Station";
			class Marker {
				markerName = "eastern_power_plant";
				defaultName = "Eastern Power Station";
			};
		};
	};
};