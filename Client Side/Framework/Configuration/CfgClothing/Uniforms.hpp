class U_Rangemaster {
	price = 1200;
	class Textures {
		// Police Skins
		class CSI {
			displayName = "Chief Superindendent";
			textures[] = { "Data\Textures\Uniforms\Police\CSUPT.paa" };
			condition = "[player, [""Police""]] call ULP_fnc_isFaction && { [""Police_Main"", 7] call ULP_fnc_hasAccess }";
		};
		class SI {
			displayName = "Superindendent";
			textures[] = { "Data\Textures\Uniforms\Police\SUPT.paa" };
			condition = "[player, [""Police""]] call ULP_fnc_isFaction && { [""Police_Main"", 6] call ULP_fnc_hasAccess }";
		};
		class CI {
			displayName = "Chief Inspector";
			textures[] = { "Data\Textures\Uniforms\Police\CINSP.paa" };
			condition = "[player, [""Police""]] call ULP_fnc_isFaction && { [""Police_Main"", 5] call ULP_fnc_hasAccess }";
		};
		class INS {
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