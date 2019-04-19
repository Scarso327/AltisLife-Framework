#include "..\..\script_macros.hpp"

private _handle = [] spawn life_fnc_stripDownPlayer;
waitUntil {scriptDone _handle};

switch (true) do {
    case (FETCH_CONST(life_coplevel) isEqualTo 1): {
        player addUniform "U_Rangemaster";
        player addHeadgear "H_Cap_police";
        player addVest "V_PlateCarrier1_blk";
        player addBackpack "B_TacticalPack_blk";

        player linkItem "ItemMap";
        player linkItem "ItemGPS";
        player linkItem "ItemRadio";
        player linkItem "ItemCompass";
        player linkItem "ItemWatch";
        player linkItem "Binocular";

        player addItem "FirstAidKit";
        player addItem "FirstAidKit";
        player addItem "FirstAidKit";
        player addItem "ToolKit";
    }; 

    case (FETCH_CONST(life_coplevel) >= 9): {
        player addUniform "U_Competitor";
        player addHeadgear "H_Beret_02";
        player addVest "V_PlateCarrier1_blk";
        player addBackpack "B_TacticalPack_blk";

        player linkItem "ItemMap";
        player linkItem "ItemGPS";
        player linkItem "ItemRadio";
        player linkItem "ItemCompass";
        player linkItem "ItemWatch";
        player linkItem "Binocular";

        player addItem "FirstAidKit";
        player addItem "FirstAidKit";
        player addItem "FirstAidKit";
        player addItem "ToolKit";
    }; 

    default {
        player addUniform "U_Competitor";
        player addHeadgear "H_Beret_blk";
        player addVest "V_PlateCarrier1_blk";
        player addBackpack "B_TacticalPack_blk";

        player linkItem "ItemMap";
        player linkItem "ItemGPS";
        player linkItem "ItemRadio";
        player linkItem "ItemCompass";
        player linkItem "ItemWatch";
        player linkItem "Binocular";

        player addItem "FirstAidKit";
        player addItem "FirstAidKit";
        player addItem "FirstAidKit";
        player addItem "ToolKit";
    }; 
};

[] call FF(playerSkins);
[] call life_fnc_saveGear;
