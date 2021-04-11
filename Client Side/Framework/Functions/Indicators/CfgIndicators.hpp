class CfgIndicators {
	groupColour[] = { 0.502, 0.502, 0.502, 1 };
	alignedColour[] = { 0, 0.502, 0.502, 1 };

	class Police {
		// NPAS
		class U_O_PilotCoveralls { colour[] = { 1, 0.647, 0, 1 }; };

		// SCO19
		class U_B_CTRG_Soldier_F { colour[] = { 0.8, 0, 0, 1 }; };
		class U_B_GhillieSuit : U_B_CTRG_Soldier_F {};

		// NCA
		class U_O_R_Gorka_01_black_F { colour[] = { 0, 0.502, 0, 1 }; };

		// MPU
		class U_B_Wetsuit { colour[] = { 0, 0, 1, 1 }; };

		// RPU
		class U_B_CombatUniform_mcam_worn { colour[] = { 1, 1, 0, 1 }; };
	};

	class Medic {
		// AAA
		class U_O_PilotCoveralls { colour[] = { 0.8, 0, 0, 1 }; };
	};
};