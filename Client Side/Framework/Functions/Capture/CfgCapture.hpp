class CfgCapture {
	class Altis {
		class WestHideout {
			displayName = "Western Criminal Hideout";
			time = 180;
			condition = "[""Hideout""] call ULP_fnc_hasGroupPerk";
		};
		class EastHideout : WestHideout { displayName = "Eastern Criminal Hideout"; };
	};
};