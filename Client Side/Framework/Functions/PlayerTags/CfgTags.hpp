class CfgTags {
	baseColour[] = { 1, 1, 1 };
	friendColour[] = { 0, 0.901, 0.074 };

	class Tags {
		class Whitelisting {
			class Police {
				Main[] = {
					"PolicePCSO",
					"PolicePCSO",
					"PolicePPC",
					"PoliceSC",
					"PolicePC",
					"PolicePS",
					"PolicePI",
					"PoliceCI",
					"PoliceSU",
					"PoliceCSU",
					"PoliceDCC",
					"PoliceCC"
				};
			};

			class Medic {
				Main[] = {
					"MedicSTU",
					"MedicSTU",
					"MedicPAR",
					"MedicSPAR",
					"MedicDR",
					"MedicGP",
					"MedicCST",
					"MedicDOO",
					"MedicCMO"
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

		class Admin {
			icon = "Data\Tags\logo.paa";
			subtitle = "Staff On-Duty";
			condition = "false";
		};

		// Altis Police Constabulary
		class PoliceCC {
			icon = "Data\Tags\Ranks\Police\CC.paa";
			subtitle = "Chief Constable";
			condition = "[player, [""Police""]] call ULP_fnc_isFaction && { [""Police_Main"", 11] call ULP_fnc_hasAccess }";
		};
		class PoliceDCC {
			icon = "Data\Tags\Ranks\Police\DCC.paa";
			subtitle = "Deputy Chief Constable";
			condition = "[player, [""Police""]] call ULP_fnc_isFaction && { [""Police_Main"", 10] call ULP_fnc_hasAccess }";
		};
		class PoliceCSU {
			icon = "Data\Tags\Ranks\Police\CSU.paa";
			subtitle = "Chief Superintendent";
			condition = "[player, [""Police""]] call ULP_fnc_isFaction && { [""Police_Main"", 9] call ULP_fnc_hasAccess }";
		};
		class PoliceSU {
			icon = "Data\Tags\Ranks\Police\SU.paa";
			subtitle = "Superintendent";
			condition = "[player, [""Police""]] call ULP_fnc_isFaction && { [""Police_Main"", 8] call ULP_fnc_hasAccess }";
		};
		class PoliceCI {
			icon = "Data\Tags\Ranks\Police\CI.paa";
			subtitle = "Chief Inspector";
			condition = "[player, [""Police""]] call ULP_fnc_isFaction && { [""Police_Main"", 7] call ULP_fnc_hasAccess }";
		};
		class PolicePI {
			icon = "Data\Tags\Ranks\Police\PI.paa";
			subtitle = "Police Inspector";
			condition = "[player, [""Police""]] call ULP_fnc_isFaction && { [""Police_Main"", 6] call ULP_fnc_hasAccess }";
		};
		class PolicePS {
			icon = "Data\Tags\Ranks\Police\PS.paa";
			subtitle = "Police Sergeant";
			condition = "[player, [""Police""]] call ULP_fnc_isFaction && { [""Police_Main"", 5] call ULP_fnc_hasAccess }";
		};
		class PolicePC  {
			icon = "Data\Tags\Ranks\Police\PC.paa";
			subtitle = "Police Constable";
			condition = "[player, [""Police""]] call ULP_fnc_isFaction && { [""Police_Main"", 4] call ULP_fnc_hasAccess }";
		};
		class PoliceSC  {
			icon = "Data\Tags\Ranks\Police\SC.paa";
			subtitle = "Special Constable";
			condition = "[player, [""Police""]] call ULP_fnc_isFaction && { [""Police_Main"", 3] call ULP_fnc_hasAccess }";
		};
		class PolicePPC  {
			icon = "Data\Tags\Ranks\Police\PC.paa";
			subtitle = "Probationary Police Constable";
			condition = "[player, [""Police""]] call ULP_fnc_isFaction && { [""Police_Main"", 2] call ULP_fnc_hasAccess }";
		};
		class PolicePCSO  {
			icon = "Data\Tags\Ranks\Police\PCSO.paa";
			subtitle = "Police Community Support Officer";
			condition = "[player, [""Police""]] call ULP_fnc_isFaction && { [""Police_Main"", 1] call ULP_fnc_hasAccess }";
		};

		// National Health Service
		class MedicCMO {
			icon = "Data\Tags\Ranks\Medic\CMO.paa";
			subtitle = "Chief Medical Officer";
			condition = "[player, [""Medic""]] call ULP_fnc_isFaction && { [""Medic_Main"", 8] call ULP_fnc_hasAccess }";
		};
		class MedicDOO {
			icon = "Data\Tags\Ranks\Medic\DOO.paa";
			subtitle = "Director of Operations";
			condition = "[player, [""Medic""]] call ULP_fnc_isFaction && { [""Medic_Main"", 7] call ULP_fnc_hasAccess }";
		};
		class MedicCST {
			icon = "Data\Tags\Ranks\Medic\CST.paa";
			subtitle = "Consultant";
			condition = "[player, [""Medic""]] call ULP_fnc_isFaction && { [""Medic_Main"", 6] call ULP_fnc_hasAccess }";
		};
		class MedicGP {
			icon = "Data\Tags\Ranks\Medic\GP.paa";
			subtitle = "General Practitioner";
			condition = "[player, [""Medic""]] call ULP_fnc_isFaction && { [""Medic_Main"", 5] call ULP_fnc_hasAccess }";
		};
		class MedicDR  {
			icon = "Data\Tags\Ranks\Medic\DR.paa";
			subtitle = "Doctor";
			condition = "[player, [""Medic""]] call ULP_fnc_isFaction && { [""Medic_Main"", 4] call ULP_fnc_hasAccess }";
		};
		class MedicSPAR  {
			icon = "Data\Tags\Ranks\Medic\SPAR.paa";
			subtitle = "Senior Paramedic";
			condition = "[player, [""Medic""]] call ULP_fnc_isFaction && { [""Medic_Main"", 3] call ULP_fnc_hasAccess }";
		};
		class MedicPAR  {
			icon = "Data\Tags\Ranks\Medic\PAR.paa";
			subtitle = "Paramedic";
			condition = "[player, [""Medic""]] call ULP_fnc_isFaction && { [""Medic_Main"", 2] call ULP_fnc_hasAccess }";
		};
		class MedicSTU  {
			icon = "Data\Tags\Ranks\Medic\STU.paa";
			subtitle = "Student";
			condition = "[player, [""Medic""]] call ULP_fnc_isFaction && { [""Medic_Main"", 1] call ULP_fnc_hasAccess }";
		};
	};
};