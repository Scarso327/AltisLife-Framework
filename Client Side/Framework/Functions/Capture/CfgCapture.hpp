class CfgCapture {
	class Altis {
		class WestHideout {
			displayName = "Western Criminal Hideout";
			time = 180;
			cooldown = 180;
			class Marker {
				markerType = "loc_Bunker";
				markerColour = "ColorEast";
				defaultName = "Criminal Hideout";
			};
			condition = "[""Hideout""] call ULP_fnc_hasGroupPerk";
		};
		class EastHideout : WestHideout {
			displayName = "Eastern Criminal Hideout";
		};

		class WesternPowerStation {
			displayName = "Western Power Station";
			time = 180;
			cooldown = 300;
			class Marker {
				markerType = "loc_Power";
				markerColour = "ColorIndependent";
				defaultName = "Western Power Station";
			};
			condition = "[] call ULP_fnc_isGroup";
		};
		class EasternPowerStation : WesternPowerStation {
			displayName = "Eastern Power Station";
			class Marker : Marker {
				defaultName = "Eastern Power Station";
			};
		};
	};
};