class CfgClothing {
	class U_Rangemaster {
		price = 1200;
		class Textures {
			class CMDR {
				displayName = "Commander's Uniform";
				textures[] = { "Data\Textures\Uniforms\Police\CMDR.paa" };
				condition = "[player, [""Police""]] call ULP_fnc_isFaction && { [""Police_Main"", 10] call ULP_fnc_hasAccess }";
			};
			class CC {
				displayName = "Chief Constable's Uniform";
				textures[] = { "Data\Textures\Uniforms\Police\CC.paa" };
				condition = "[player, [""Police""]] call ULP_fnc_isFaction && { [""Police_Main"", 9] call ULP_fnc_hasAccess }";
			};
			class DCC {
				displayName = "Deputy Chief Constable's Uniform";
				textures[] = { "Data\Textures\Uniforms\Police\DCC.paa" };
				condition = "[player, [""Police""]] call ULP_fnc_isFaction && { [""Police_Main"", 8] call ULP_fnc_hasAccess }";
			};
			class CSUPT {
				displayName = "Chief Superindendent's Uniform";
				textures[] = { "Data\Textures\Uniforms\Police\CSUPT.paa" };
				condition = "[player, [""Police""]] call ULP_fnc_isFaction && { [""Police_Main"", 7] call ULP_fnc_hasAccess }";
			};
			class SUPT {
				displayName = "Superindendent's Uniform";
				textures[] = { "Data\Textures\Uniforms\Police\SUPT.paa" };
				condition = "[player, [""Police""]] call ULP_fnc_isFaction && { [""Police_Main"", 6] call ULP_fnc_hasAccess }";
			};
			class CINSP {
				displayName = "Chief Inspector's Uniform";
				textures[] = { "Data\Textures\Uniforms\Police\CINSP.paa" };
				condition = "[player, [""Police""]] call ULP_fnc_isFaction && { [""Police_Main"", 5] call ULP_fnc_hasAccess }";
			};
			class INSP {
				displayName = "Inspector's Uniform";
				textures[] = { "Data\Textures\Uniforms\Police\INSP.paa" };
				condition = "[player, [""Police""]] call ULP_fnc_isFaction && { [""Police_Main"", 4] call ULP_fnc_hasAccess }";
			};
			class SGT {
				displayName = "Sergeant's Uniform";
				textures[] = { "Data\Textures\Uniforms\Police\SGT.paa" };
				condition = "[player, [""Police""]] call ULP_fnc_isFaction && { [""Police_Main"", 3] call ULP_fnc_hasAccess }";
			};
			class PC {
				displayName = "Contable's Uniform";
				textures[] = { "Data\Textures\Uniforms\Police\PC.paa" };
				condition = "[player, [""Police""]] call ULP_fnc_isFaction && { [""Police_Main"", 2] call ULP_fnc_hasAccess }";
			};
			class PCSO {
				displayName = "PCSO's Uniform";
				textures[] = { "Data\Textures\Uniforms\Police\PCSO.paa" };
				condition = "[player, [""Police""]] call ULP_fnc_isFaction && { [""Police_Main"", 1] call ULP_fnc_hasAccess }";
			};
		};
	};
};