/*
    File: fn_copLoadout.sqf
    Author: Bryan "Tonic" Boardwine
    Edited: Itsyuka

    Description:
    Loads the cops out with the default gear.
*/
#include "..\..\script_macros.hpp"

private _handle = [] spawn life_fnc_stripDownPlayer;
waitUntil {scriptDone _handle};

switch (FETCH_CONST(life_coplevel)) do {
    case 1: {
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

        player addItem "ToolKit";
    }; 

	case 2: {
        player addUniform "U_Competitor";
        player addHeadgear "H_Beret_blk_POLICE";
        player addVest "V_PlateCarrier1_blk";
        player addBackpack "B_TacticalPack_blk";

        player linkItem "ItemMap";
        player linkItem "ItemGPS";
        player linkItem "ItemRadio";
        player linkItem "ItemCompass";
        player linkItem "ItemWatch";
        player linkItem "Binocular";

        player addItem "ToolKit";
    }; 

    case 3: {
        player addUniform "U_Competitor";
        player addHeadgear "H_Beret_blk_POLICE";
        player addVest "V_PlateCarrier1_blk";
        player addBackpack "B_TacticalPack_blk";

        player linkItem "ItemMap";
        player linkItem "ItemGPS";
        player linkItem "ItemRadio";
        player linkItem "ItemCompass";
        player linkItem "ItemWatch";
        player linkItem "Binocular";

        player addItem "ToolKit";
    }; 

    case 4: {
        player addUniform "U_Competitor";
        player addHeadgear "H_Beret_blk_POLICE";
        player addVest "V_PlateCarrier1_blk";
        player addBackpack "B_TacticalPack_blk";

        player linkItem "ItemMap";
        player linkItem "ItemGPS";
        player linkItem "ItemRadio";
        player linkItem "ItemCompass";
        player linkItem "ItemWatch";
        player linkItem "Binocular";

        player addItem "ToolKit";
    }; 

    case 5: {
        player addUniform "U_Competitor";
        player addHeadgear "H_Beret_blk_POLICE";
        player addVest "V_PlateCarrier1_blk";
        player addBackpack "B_TacticalPack_blk";

        player linkItem "ItemMap";
        player linkItem "ItemGPS";
        player linkItem "ItemRadio";
        player linkItem "ItemCompass";
        player linkItem "ItemWatch";
        player linkItem "Binocular";

        player addItem "ToolKit";
    }; 

    case 6: {
        player addUniform "U_Competitor";
        player addHeadgear "H_Beret_blk_POLICE";
        player addVest "V_PlateCarrier1_blk";
        player addBackpack "B_TacticalPack_blk";

        player linkItem "ItemMap";
        player linkItem "ItemGPS";
        player linkItem "ItemRadio";
        player linkItem "ItemCompass";
        player linkItem "ItemWatch";
        player linkItem "Binocular";

        player addItem "ToolKit";
    }; 

    case 7: {
        player addUniform "U_Competitor";
        player addHeadgear "H_Beret_blk_POLICE";
        player addVest "V_PlateCarrier1_blk";
        player addBackpack "B_TacticalPack_blk";

        player linkItem "ItemMap";
        player linkItem "ItemGPS";
        player linkItem "ItemRadio";
        player linkItem "ItemCompass";
        player linkItem "ItemWatch";
        player linkItem "Binocular";

        player addItem "ToolKit";
    }; 

    case 8: {
        player addUniform "U_Competitor";
        player addHeadgear "H_Beret_blk_POLICE";
        player addVest "V_PlateCarrier1_blk";
        player addBackpack "B_TacticalPack_blk";

        player linkItem "ItemMap";
        player linkItem "ItemGPS";
        player linkItem "ItemRadio";
        player linkItem "ItemCompass";
        player linkItem "ItemWatch";
        player linkItem "Binocular";

        player addItem "ToolKit";
    }; 

    case 9: {
        player addUniform "U_Competitor";
        player addHeadgear "H_Beret_gen_F";
        player addVest "V_PlateCarrier1_blk";
        player addBackpack "B_TacticalPack_blk";

        player linkItem "ItemMap";
        player linkItem "ItemGPS";
        player linkItem "ItemRadio";
        player linkItem "ItemCompass";
        player linkItem "ItemWatch";
        player linkItem "Binocular";

        player addItem "ToolKit";
    }; 

    case 10: {
        player addUniform "U_Competitor";
        player addHeadgear "H_Beret_gen_F";
        player addVest "V_PlateCarrier1_blk";
        player addBackpack "B_TacticalPack_blk";

        player linkItem "ItemMap";
        player linkItem "ItemGPS";
        player linkItem "ItemRadio";
        player linkItem "ItemCompass";
        player linkItem "ItemWatch";
        player linkItem "Binocular";

        player addItem "ToolKit";
    }; 

    case 11: {
        player addUniform "U_Competitor";
        player addHeadgear "H_Beret_gen_F";
        player addVest "V_PlateCarrier1_blk";
        player addBackpack "B_TacticalPack_blk";

        player linkItem "ItemMap";
        player linkItem "ItemGPS";
        player linkItem "ItemRadio";
        player linkItem "ItemCompass";
        player linkItem "ItemWatch";
        player linkItem "Binocular";

        player addItem "ToolKit";
    }; 
};

[] call FF(playerSkins);
[] call life_fnc_saveGear;
