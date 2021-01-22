class U_Rangemaster {
	price = 1200;
	class Textures {
		// Police Skins
		class CMDR {
			displayName = "Commander";
			textures[] = { "Data\Textures\Uniforms\Police\CMDR.paa" };
			condition = "[player, [""Police""]] call ULP_fnc_isFaction && { [""Police_Main"", 10] call ULP_fnc_hasAccess }";
		};
		class CC {
			displayName = "Chief Constable";
			textures[] = { "Data\Textures\Uniforms\Police\CC.paa" };
			condition = "[player, [""Police""]] call ULP_fnc_isFaction && { [""Police_Main"", 9] call ULP_fnc_hasAccess }";
		};
		class DCC {
			displayName = "Deputy Chief Constable";
			textures[] = { "Data\Textures\Uniforms\Police\DCC.paa" };
			condition = "[player, [""Police""]] call ULP_fnc_isFaction && { [""Police_Main"", 8] call ULP_fnc_hasAccess }";
		};
		class CSUPT {
			displayName = "Chief Superindendent";
			price = 5000;
			textures[] = { "Data\Textures\Uniforms\Police\CSUPT.paa" };
			condition = "[player, [""Police""]] call ULP_fnc_isFaction && { [""Police_Main"", 7] call ULP_fnc_hasAccess }";
		};
		class SUPT {
			displayName = "Superindendent";
			textures[] = { "Data\Textures\Uniforms\Police\SUPT.paa" };
			condition = "[player, [""Police""]] call ULP_fnc_isFaction && { [""Police_Main"", 6] call ULP_fnc_hasAccess }";
		};
		class CINSP {
			displayName = "Chief Inspector";
			textures[] = { "Data\Textures\Uniforms\Police\CINSP.paa" };
			condition = "[player, [""Police""]] call ULP_fnc_isFaction && { [""Police_Main"", 5] call ULP_fnc_hasAccess }";
		};
		class INSP {
			displayName = "Inspector";
			textures[] = { "Data\Textures\Uniforms\Police\INSP.paa" };
			condition = "[player, [""Police""]] call ULP_fnc_isFaction && { [""Police_Main"", 4] call ULP_fnc_hasAccess }";
		};
		class SGT {
			displayName = "Sergeant";
			textures[] = { "Data\Textures\Uniforms\Police\SGT.paa" };
			condition = "[player, [""Police""]] call ULP_fnc_isFaction && { [""Police_Main"", 3] call ULP_fnc_hasAccess }";
		};
		class PC {
			displayName = "Contable";
			textures[] = { "Data\Textures\Uniforms\Police\PC.paa" };
			condition = "[player, [""Police""]] call ULP_fnc_isFaction && { [""Police_Main"", 2] call ULP_fnc_hasAccess }";
		};
		class PCSO {
			displayName = "PCSO";
			textures[] = { "Data\Textures\Uniforms\Police\PCSO.paa" };
			condition = "[player, [""Police""]] call ULP_fnc_isFaction && { [""Police_Main"", 1] call ULP_fnc_hasAccess }";
		};

		// Medic Skins
		class CMO {
			displayName = "CMO";
			textures[] = { "Data\Textures\Uniforms\Medic\MedicLevel3.paa" };
			condition = "[player, [""Medic""]] call ULP_fnc_isFaction && { [""Medic_Main"", 3] call ULP_fnc_hasAccess }";
		};

		class SMO {
			displayName = "SMO";
			textures[] = { "Data\Textures\Uniforms\Medic\MedicLevel2.paa" };
			condition = "[player, [""Medic""]] call ULP_fnc_isFaction && { [""Medic_Main"", 2] call ULP_fnc_hasAccess }";
		};

		class JMO {
			displayName = "JMO";
			textures[] = { "Data\Textures\Uniforms\Medic\MedicLevel1.paa" };
			condition = "[player, [""Medic""]] call ULP_fnc_isFaction && { [""Medic_Main"", 1] call ULP_fnc_hasAccess }";
		};
	};
};