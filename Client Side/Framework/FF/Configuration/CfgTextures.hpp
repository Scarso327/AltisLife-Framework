
/*
    texture : STRING DIRECTORY
    invisBackpack : ARRAY (SETTING, DIRECTORY) [1 = No change, 2 = Retexture backpack, 3 = Insivible]
*/

class CfgTextures {

    // Main Medic Uniform...
    class U_Rangemaster {
        texture[] = {
            1,
            {
                "Medic\Uniforms\MedicLevel1.paa", // Level 1
                "Medic\Uniforms\MedicLevel2.paa", // Level 2
                "Medic\Uniforms\MedicLevel1.paa", // Level 3
                "Medic\Uniforms\MedicLevel2.paa", // Level 4
                "Medic\Uniforms\MedicLevel2.paa", // Level 5
                "Medic\Uniforms\MedicLevel3.paa", // Level 6
                "Medic\Uniforms\MedicLevel3.paa" // Level 7
            }
        };
        invisBackpack[] = {3, ""};
    };

    // Main Police Uniform...
    class U_Competitor {
        texture[] = {
            1,
            {
                "Police\Uniforms\Junior.paa", // Level 1
                "Police\Uniforms\PC.paa", // Level 2
                "Police\Uniforms\PC.paa", // Level 3
                "Police\Uniforms\SGT.paa", // Level 4
                "Police\Uniforms\INSP.paa", // Level 5
                "Police\Uniforms\CINSP.paa", // Level 6
                "Police\Uniforms\SUPT.paa", // Level 7
                "Police\Uniforms\CSUPT.paa", // Level 8
                "Police\Uniforms\DCOM.paa", // Level 9
                "Police\Uniforms\COM.paa", // Level 10
                "Police\Uniforms\CMDR.paa" // Level 11
            }
        };
        invisBackpack[] = {3, ""};
    };

    // Police High Vis Uniform
    class U_B_CTRG_1 {
        texture[] = {
            0,
            "Police\Uniforms\Yellow.paa"
        };
        invisBackpack[] = {3, ""};
    };

    class U_B_Wetsuit {
        texture[] = {0, "" };
        invisBackpack[] = {3, ""};
    };

    class U_Marshal {
        texture[] = {0, "" };
        invisBackpack[] = {3, ""};
    };
};