class CfgIndicators {
	groupColour[] = { 0.502, 0.502, 0.502, 1 };
	alignedColour[] = { 0, 0.502, 0.502, 1 };

	class Police {
		// NPAS
		class U_O_PilotCoveralls { colour[] = { 1, 0.647, 0, 1 }; };

		// SCO19
		class U_B_CTRG_Soldier_F { colour[] = { 0.8, 0, 0, 1 }; };
		class U_B_GhillieSuit : U_B_CTRG_Soldier_F {};

		// NCA & RPU
		class U_BG_Guerrilla_6_1 { colour[] = { 0, 0, 1, 1 }; };
		class U_O_R_Gorka_01_black_F : U_BG_Guerrilla_6_1 {};
		class U_B_CombatUniform_mcam_worn : U_BG_Guerrilla_6_1 {};

		// MPU
		class U_B_Wetsuit { colour[] = { 0, 0.502, 0, 1 }; };
	};

	class Medic {
		// AAA
		class U_O_PilotCoveralls { colour[] = { 0.8, 0, 0, 1 }; };
	};
};