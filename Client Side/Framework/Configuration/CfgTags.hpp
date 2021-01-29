class CfgTags {
	baseColour[] = { 1, 1, 1 };
	friendColour[] = { 0, 0.901, 0.074 };

	class Tags {
		class Whitelisting {
			class Police {
				class Main {
					class PolicePPC {};
					class PolicePC {};
					class PoliceSGT {};
					class PoliceINS {};
					class PoliceCI {};
					class PoliceSI {};
					class PoliceCSI {};
				};
			};
		};
	};

	class Icons {
		class IconBase {
			icon = "";
			subtitle = "";
			condition = "true";
		};

		class PoliceCSI {
			icon = "Data\Tags\Ranks\Police\CSI.paa";
			subtitle = "Chief Superintendent";
			condition = "[player, [""Police""]] call ULP_fnc_isFaction && { [""Police_Main"", 7] call ULP_fnc_hasAccess }";
		};

		class PoliceSI {
			icon = "Data\Tags\Ranks\Police\SI.paa";
			subtitle = "Superintendent";
			condition = "[player, [""Police""]] call ULP_fnc_isFaction && { [""Police_Main"", 6] call ULP_fnc_hasAccess }";
		};

		class PoliceCI {
			icon = "Data\Tags\Ranks\Police\CI.paa";
			subtitle = "Chief Inspector";
			condition = "[player, [""Police""]] call ULP_fnc_isFaction && { [""Police_Main"", 5] call ULP_fnc_hasAccess }";
		};

		class PoliceINS {
			icon = "Data\Tags\Ranks\Police\INS.paa";
			subtitle = "Inspector";
			condition = "[player, [""Police""]] call ULP_fnc_isFaction && { [""Police_Main"", 4] call ULP_fnc_hasAccess }";
		};

		class PoliceSGT {
			icon = "Data\Tags\Ranks\Police\SGT.paa";
			subtitle = "Sergeant";
			condition = "[player, [""Police""]] call ULP_fnc_isFaction && { [""Police_Main"", 3] call ULP_fnc_hasAccess }";
		};

		class PolicePC  {
			icon = "Data\Tags\Ranks\Police\PC.paa";
			subtitle = "Constable";
			condition = "[player, [""Police""]] call ULP_fnc_isFaction && { [""Police_Main"", 1] call ULP_fnc_hasAccess }";
		};

		class PolicePPC : PolicePC {};
	};
};