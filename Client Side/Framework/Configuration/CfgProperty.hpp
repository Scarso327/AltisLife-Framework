#define true 1
#define false 0

class Housing {
    class Altis {};

    class Tanoa {
        // Houses with Garages
        class Land_Hotel_01_F {
            price = 960000;
            numberCrates = 5;
            restrictedPos[] = {};
            canGarage = true;
            garageSpawnPos[] = {-1.27246,-11.4361,-5.63821};
            garageSpawnDir = 0;
            garageBlacklists[] = {{5909.93,10491.9,-0.153875}};
            lightPos[] = {0.5,0.5,7.5};
        };
        
        class Land_Hotel_02_F {
            price = 2000000;
            numberCrates = 8;
            restrictedPos[] = {};
            canGarage = true;
            garageSpawnPos[] = {14.1128,1.51736,-4.18449};
            garageSpawnDir = 0;
            garageBlacklists[] = {};
            lightPos[] = {0,1,3};
        };
        
        class Land_GarageShelter_01_F {
            price = 80000;
            numberCrates = 1;
            restrictedPos[] = {};
            canGarage = true;
            garageSpawnPos[] = {0.241684,-5.72266,-1.46744};
            garageSpawnDir = 90;
            garageBlacklists[] = {{10998,9698.24,-0.219376}};
            lightPos[] = {0,0,2};
        };
        
        class Land_House_Big_02_F {
            price = 450000;
            numberCrates = 2;
            restrictedPos[] = {};
            canGarage = true;
            garageSpawnPos[] = {12.8365,0.414551,-1.81252};
            garageSpawnDir = 0;
            garageBlacklists[] = {};
            lightPos[] = {0,0,2};
        };
        
        class Land_School_01_F {
            price = 3000000;
            numberCrates = 8;
            restrictedPos[] = {};
            canGarage = true;
            garageSpawnPos[] = {-6.91215,-11.5288,-1.70768};
            garageSpawnDir = 0;
            garageBlacklists[] = {{10957,9532.16,-0.528702}};
            lightPos[] = {0,0,2.65};
        };
        
        class Land_House_Big_04_F {
            price = 140000;
            numberCrates = 2;
            restrictedPos[] = {};
            canGarage = false;
            garageSpawnPos[] = {12.308,-0.228027,-3.34715};
            garageSpawnDir = 0;
            garageBlacklists[] = {{5879.2,10002.7,-0.278984},{9508.48,13082.7,0.021286}};
            lightPos[] = {0,0,3.5};
        };
        
        class Land_House_Big_03_F {
            price = 900000;
            numberCrates = 3;
            restrictedPos[] = {};
            canGarage = true;
            garageSpawnPos[] = {14.9072,0.394043,-3.60528};
            garageSpawnDir = 0;
            garageBlacklists[] = {{11507.2,2447.47,-0.145175}};
            lightPos[] = {0,0,3.5};
        };
        
        // Houses without Garages
        class Land_House_Big_01_F {
            price = 350000;
            numberCrates = 2;
            restrictedPos[] = {};
            canGarage = false;
            garageSpawnPos[] = {};
            garageSpawnDir = 0;
            garageBlacklists[] = {};
            lightPos[] = {-1,2,2};
        };
        
        class Land_House_Small_03_F {
            price = 600000;
            numberCrates = 3;
            restrictedPos[] = {};
            canGarage = false;
            garageSpawnPos[] = {};
            garageSpawnDir = 0;
            garageBlacklists[] = {};
            lightPos[] = {-2.35,1,2.8};
        };
        
        class Land_House_Small_06_F {
            price = 700000;
            numberCrates = 3;
            restrictedPos[] = {};
            canGarage = false;
            garageSpawnPos[] = {};
            garageSpawnDir = 0;
            garageBlacklists[] = {};
            lightPos[] = {3,-2,2};
        };
        
        class Land_Slum_03_F {
            price = 450000;
            numberCrates = 4;
            restrictedPos[] = {};
            canGarage = false;
            garageSpawnPos[] = {};
            garageSpawnDir = 0;
            garageBlacklists[] = {};
            lightPos[] = {1,2,3};
        };
        
        class Land_Addon_04_F {
            price = 120000;
            numberCrates = 2;
            restrictedPos[] = {};
            canGarage = false;
            garageSpawnPos[] = {};
            garageSpawnDir = 0;
            garageBlacklists[] = {};
            lightPos[] = {0,-2,4};
        };
        
        class Land_Slum_01_F {
            price = 200000;
            numberCrates = 1;
            restrictedPos[] = {};
            canGarage = false;
            garageSpawnPos[] = {};
            garageSpawnDir = 0;
            garageBlacklists[] = {};
            lightPos[] = {1.5,0,3.2};
        };
        
        class Land_House_Small_05_F {
            price = 100000;
            numberCrates = 2;
            restrictedPos[] = {};
            canGarage = false;
            garageSpawnPos[] = {};
            garageSpawnDir = 0;
            garageBlacklists[] = {};
            lightPos[] = {2,1,2};
        };
        
        class Land_House_Small_02_F {
            price = 160000;
            numberCrates = 2;
            restrictedPos[] = {};
            canGarage = false;
            garageSpawnPos[] = {};
            garageSpawnDir = 0;
            garageBlacklists[] = {};
            lightPos[] = {-2,0,2.4};
        };
        
        class Land_House_Small_04_F {
            price = 130000;
            numberCrates = 2;
            restrictedPos[] = {};
            canGarage = false;
            garageSpawnPos[] = {};
            garageSpawnDir = 0;
            garageBlacklists[] = {};
            lightPos[] = {1.2,0.2,2.5};
        };
    };
};

class Garages {
    class Altis {};

    class Tanoa {
        class Land_SM_01_shed_F {
            price = 140000;
            garageSpawnPos[] = {-11.404,3.81494,-1.64553};
            garageSpawnDir = 0;
            garageBlacklists[] = {};
        };

        class Land_i_Shed_Ind_F : Land_SM_01_shed_F {
            garageBlacklists[] = {{3078.71,11012.1,0.119904}};
        };

        class Land_Addon_05_F {
            price = 130000;
            garageSpawnPos[] = {0.0668793,-13.8677,-1.85385};
            garageSpawnDir = 0;
            garageBlacklists[] = {{5684.74,10216.8,1.16831},{5730.31,10326.1,-0.30881}};
        };

        class Land_DPP_01_smallFactory_F {
            price = 160000;
            garageSpawnPos[] = {-1.13538,6.99512,-2.21416};
            garageSpawnDir = 0;
            garageBlacklists[] = {};
        };

        class Land_Warehouse_03_F {
            price = 180000;
            garageSpawnPos[] = {-3.90981,-8.46338,-2.53567};
            garageSpawnDir = 90;
            garageBlacklists[] = {};
        };
    };
};
