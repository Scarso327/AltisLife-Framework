#include "..\..\script_macros.hpp"

private _handle = [] spawn life_fnc_stripDownPlayer;
waitUntil {scriptDone _handle};

switch (true) do {
    case (FETCH_CONST(life_mediclevel) = 6): {
        player addUniform "U_Rangemaster";
        player addHeadgear "H_Beret_gen_F";
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
        player addItem "MediKit";
    }; 

    default {
        player addUniform "U_Rangemaster";
        player addHeadgear "H_Cap_blk";
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
        player addItem "MediKit";
    }; 
};

[] call FF(playerSkins);
[] call life_fnc_saveGear;
