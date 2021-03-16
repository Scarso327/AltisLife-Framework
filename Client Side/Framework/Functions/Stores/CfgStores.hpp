class CfgStores {
	sellPerc = 0.2; // % of original price returned when you sell an item...

	#include "Clothing\CfgClothesStore.hpp"
	#include "Item\CfgItemsStore.hpp"
	#include "..\VirtualStore\CfgVirtualStores.hpp"
};

/*
APC -----------------------------------------------------
# APC GENERAL
[this, "<t color='#3266A8'>[APC]</t> General Market", "Police"] call ULP_fnc_addMarket;
[this, "<t color='#3266A8'>[APC]</t> Equipment Store", "Police", "CfgItemsStore"] call ULP_fnc_addStore; 
[this, "<t color='#3266A8'>[APC]</t> Clothing Store", "Police", "CfgClothesStore"] call ULP_fnc_addStore;

NHS -----------------------------------------------------
# NHS GENERAL
[this, "<t color='#32A863'>[NHS]</t> General Market", "Medic"] call ULP_fnc_addMarket;
[this, "<t color='#32A863'>[NHS]</t> Equipment Store", "Medic", "CfgItemsStore"] call ULP_fnc_addStore; 
[this, "<t color='#32A863'>[NHS]</t> Clothing Store", "Medic", "CfgClothesStore"] call ULP_fnc_addStore;

HATO ----------------------------------------------------
# HATO GENERAL
[this, "<t color='#D7E02D'>[HATO]</t> General Market", "Hato"] call ULP_fnc_addMarket;
[this, "<t color='#D7E02D'>[HATO]</t> Equipment Store", "Hato", "CfgItemsStore"] call ULP_fnc_addStore; 
[this, "<t color='#D7E02D'>[HATO]</t> Clothing Store", "Hato", "CfgClothesStore"] call ULP_fnc_addStore;

CIVILIAN ------------------------------------------------
[this, "<t color='#B92DE0'>[CIV]</t> General Market", "Civilian"] call ULP_fnc_addMarket;
[this, "<t color='#B92DE0'>[CIV]</t> Fish Market", "Fish"] call ULP_fnc_addMarket;
[this, "<t color='#B92DE0'>[CIV]</t> Medical Supplies", "Fish"] call ULP_fnc_addMarket;
[this, "<t color='#B92DE0'>[CIV]</t> Redburger", "Burger"] call ULP_fnc_addMarket;
[this, "<t color='#B92DE0'>[CIV]</t> Tea Room", "Tea"] call ULP_fnc_addMarket;
[this, "<t color='#B92DE0'>[CIV]</t> Local Pub", "Pub"] call ULP_fnc_addMarket;

[this, "<t color='#B92DE0'>[CIV]</t> General Store", "Civilian", "CfgItemsStore"] call ULP_fnc_addStore; 
[this, "<t color='#B92DE0'>[CIV]</t> Handgun Store", "Handgun", "CfgItemsStore"] call ULP_fnc_addStore; 

[this, "<t color='#B92DE0'>[CIV]</t> Clothing Store", "Civilian", "CfgClothesStore"] call ULP_fnc_addStore;
[this, "<t color='#B92DE0'>[CIV]</t> Clothing Store", "GoKart", "CfgClothesStore"] call ULP_fnc_addStore;
[this, "<t color='#B92DE0'>[CIV]</t> Clothing Store", "Diving", "CfgClothesStore"] call ULP_fnc_addStore;
[this, "<t color='#B92DE0'>[CIV]</t> Clothing Store", "Solicitor", "CfgClothesStore"] call ULP_fnc_addStore;
[this, "<t color='#B92DE0'>[CIV]</t> Clothing Store", "Press", "CfgClothesStore"] call ULP_fnc_addStore;
[this, "<t color='#B92DE0'>[CIV]</t> Clothing Store", "IDAP", "CfgClothesStore"] call ULP_fnc_addStore;
[this, "<t color='#B92DE0'>[CIV]</t> Clothing Store", "Solicitor", "CfgClothesStore"] call ULP_fnc_addStore;

# TRADING SITES
[this, "<t color='#B92DE0'>[CIV]</t> Cigarette Trader", "Cigarette"] call ULP_fnc_addMarket;
[this, "<t color='#B92DE0'>[CIV]</t> Cigar Trader", "Cigar"] call ULP_fnc_addMarket;
[this, "<t color='#B92DE0'>[CIV]</t> Coal Trader", "Coal"] call ULP_fnc_addMarket;
[this, "<t color='#B92DE0'>[CIV]</t> Coral Trader", "Coral"] call ULP_fnc_addMarket;
[this, "<t color='#B92DE0'>[CIV]</t> Glass Trader", "Glass"] call ULP_fnc_addMarket;
[this, "<t color='#B92DE0'>[CIV]</t> Salt Trader", "Salt"] call ULP_fnc_addMarket;
[this, "<t color='#B92DE0'>[CIV]</t> Diamond Trader", "Diamond"] call ULP_fnc_addMarket;
[this, "<t color='#B92DE0'>[CIV]</t> Oil Trader", "Oil"] call ULP_fnc_addMarket;
[this, "<t color='#B92DE0'>[CIV]</t> Metal Exports", "Metal"] call ULP_fnc_addMarket;
[this, "<t color='#B92DE0'>[CIV]</t> Uranium Trader", "Uranium"] call ULP_fnc_addMarket;
[this, "<t color='#B92DE0'>[CIV]</t> Gold Buyer", "Gold"] call ULP_fnc_addMarket;
[this, "<t color='#B92DE0'>[CIV]</t> Drug Dealer", "Drug"] call ULP_fnc_addMarket;
[this, "<t color='#B92DE0'>[CIV]</t> Turtle Dealer", "Turtle"] call ULP_fnc_addMarket;

# HUNTING CAMP
[this, "<t color='#B92DE0'>[CIV]</t> Hunting Market", "Hunting"] call ULP_fnc_addMarket;
[this, "<t color='#B92DE0'>[CIV]</t> Hunting Store", "Hunting", "CfgItemsStore"] call ULP_fnc_addStore; 

# REBEL OUTPOST
[this, "<t color='#E02D2D'>[REB]</t> General Market", "Rebel"] call ULP_fnc_addMarket;
[this, "<t color='#E02D2D'>[REB]</t> Equipment Store", "Rebel", "CfgItemsStore"] call ULP_fnc_addStore; 
[this, "<t color='#E02D2D'>[REB]</t> Clothing Store", "Rebel", "CfgClothesStore"] call ULP_fnc_addStore;

# BLACKMARKET
[this, "<t color='#E02D2D'>[REB]</t> General Market", "Blackmarket"] call ULP_fnc_addMarket;
[this, "<t color='#E02D2D'>[REB]</t> Equipment Store", "Blackmarket", "CfgItemsStore"] call ULP_fnc_addStore; 
[this, "<t color='#E02D2D'>[REB]</t> Clothing Store", "Blackmarket", "CfgClothesStore"] call ULP_fnc_addStore;
*/