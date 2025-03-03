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
		class EastHideout : WestHideout { displayName = "Eastern Criminal Hideout"; };

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
			class Marker : Marker { defaultName = "Eastern Power Station"; };
		};

		class ParosCheckpoint {
			displayName = "Paros Checkpoint";
			time = 300;
			cooldown = 300;
			class Marker {
				markerType = "MinefieldAP";
				markerColour = "ColorEast";
				defaultName = "Paros Checkpoint";
			};
			condition = "[] call ULP_fnc_isGroup";
		};
		class WesternHills : ParosCheckpoint {
			displayName = "Western Hills";
			class Marker : Marker { defaultName = "Western Hills"; };
		};
		class SouthernCoast : ParosCheckpoint {
			displayName = "Southern Coast";
			class Marker : Marker { defaultName = "Southern Coast"; };
		};
		class SaltFlats : ParosCheckpoint {
			displayName = "Salt Flats";
			class Marker : Marker { defaultName = "Salt Flats"; };
		};
		class GhostHotel : ParosCheckpoint {
			displayName = "Ghost Hotel";
			class Marker : Marker { defaultName = "Ghost Hotel"; };
		};
		class SofiaTown : ParosCheckpoint {
			displayName = "Sofia Town";
			class Marker : Marker { defaultName = "Sofia Town"; };
		};
		class NorthernForest : ParosCheckpoint {
			displayName = "Northern Forest";
			class Marker : Marker { defaultName = "Northern Forest"; };
		};
		class MolosRegion : ParosCheckpoint {
			displayName = "Molos Region";
			class Marker : Marker { defaultName = "Molos Region"; };
		};
		class NorthernAirfield : ParosCheckpoint {
			displayName = "Northern Airfield";
			class Marker : Marker { defaultName = "Northern Airfield"; };
		};
	};
};