/*
	@File: CfgProfessions.hpp
  
	@Author: Jack "Scarso" Farhall
  
	@Description: Holds all settings for all professions...
*/

class CfgProfessions {

    class Prof_Gathering {
        displayName = "Gathering";
        variable = "Prof_Gathering";
        description = "Gathering is a profession that is defined around the recovery of resources from various fields / plantations that are marked on the map.";
        side = "Civ";
        maxLevel = 300;
        levels[] = {
            {20, "Novice"},
            {100, "Intermediate"},
            {200, "Advanced"},
            {300, "Expert"}
        };
    };

};