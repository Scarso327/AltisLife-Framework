class CfgCapture {
	class Altis {
		class WestHideout {
			displayName = "Western Criminal Hideout";
			time = 90;
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
			time = 120;
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

		class ParosCheckpoint {
			displayName = "Abandoned Checkpoint";
			time = 10;
			cooldown = 180;
			class Marker {
				markerType = "MinefieldAP";
				markerColour = "ColorEast";
				defaultName = "Abandoned Checkpoint";
			};
			condition = "[] call ULP_fnc_isGroup";
		};
		class SouthParos : ParosCheckpoint {
			displayName = "South Paros";
			class Marker : Marker {
				defaultName = "South Paros";
			};
		};
	};
};