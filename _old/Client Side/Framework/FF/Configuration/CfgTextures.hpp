
/*
    textures : ARRAY OF TEXTURES {SKIN DIRECTORY, CONDITION, {USE CUSTOM BACKPACK SKIN, BACKPACK SKIN DIRECTORY}}
*/

class CfgTextures {

    // Main Medic Uniform...
    class U_Rangemaster {
        textures[] = {
            {"Medic\Uniforms\MedicLevel1.paa", "_side isEqualTo west && { _level <= 1 }", {1, ""}},
            {"Medic\Uniforms\MedicLevel2.paa", "_side isEqualTo west && { _level <= 5 }", {1, ""}},
            {"Medic\Uniforms\MedicLevel3.paa", "_side isEqualTo west && { _level > 5 }", {1, ""}}
        };
    };

    // Main Police Uniform...
    class U_Competitor {
        textures[] = {
            {"Police\Uniforms\Junior.paa", "_side isEqualTo west && { _level <= 1 }", {1, ""}},
            {"Police\Uniforms\PC.paa", "_side isEqualTo west && { _level <= 3 }", {1, ""}},
            {"Police\Uniforms\SGT.paa", "_side isEqualTo west && { _level isEqualTo 4 }", {1, ""}},
            {"Police\Uniforms\INSP.paa", "_side isEqualTo west && { _level isEqualTo 5 }", {1, ""}},
            {"Police\Uniforms\CINSP.paa", "_side isEqualTo west && { _level isEqualTo 6 }", {1, ""}},
            {"Police\Uniforms\SUPT.paa", "_side isEqualTo west && { _level isEqualTo 7 }", {1, ""}},
            {"Police\Uniforms\CSUPT.paa", "_side isEqualTo west && { _level isEqualTo 8 }", {1, ""}},
            {"Police\Uniforms\DCOM.paa", "_side isEqualTo west && { _level isEqualTo 9 }", {1, ""}},
            {"Police\Uniforms\COM.paa", "_side isEqualTo west && { _level isEqualTo 10 }", {1, ""}},
            {"Police\Uniforms\CMDR.paa", "_side isEqualTo west && { _level isEqualTo 11 }", {1, ""}}
        };
    };

    // Police High Vis Uniform
    class U_B_CTRG_1 {
        textures[] = {
            {"Police\Uniforms\Yellow.paa", "true", {1, ""}}
        };
    };

    class U_B_Wetsuit {
        textures[] = {
            {"", "_side isEqualTo west", {1, ""}}
        };
    };

    class U_Marshal : U_B_Wetsuit {};
};