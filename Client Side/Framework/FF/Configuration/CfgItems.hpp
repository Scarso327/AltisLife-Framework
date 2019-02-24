/*
*    CLASS:
*        variable = Variable Name
*        displayName = Item Name
*        weight = Item Weight
*        buyPrice = Item Buy Price
*        sellPrice = Item Sell Price
*        illegal = Illegal Item
*        edible = Item Edible (-1 = Disabled)
*        icon = Item Icon
*        processedItem = Processed Item
*/
class CfgItems {
    //Virtual Items

    //Misc
    class pickaxe {
        variable = "pickaxe";
        displayName = "STR_Item_Pickaxe";
        weight = 2;
        buyPrice = 750;
        sellPrice = 350;
        illegal = false;
        save = false;
        taxed = false;
        class dynmarket {
            dynmaic = false;
            prices[] = {600, 800}; // Lowest Price, Highest Price
        };
        class edibility {
            edible[] = {false, ""}; // Edible Bool, Thirst/Hunger/Both
            value = -1;
        };
        icon = "ico_pickaxe.paa";
    };

    class defibrillator {
        variable = "defibrillator";
        displayName = "STR_Item_Defibrillator";
        weight = 4;
        buyPrice = 900;
        sellPrice = 450;
        illegal = false;
        save = false;
        taxed = false;
        class dynmarket {
            dynmaic = false;
            prices[] = {600, 800}; // Lowest Price, Highest Price
        };
        class edibility {
            edible[] = {false, ""}; // Edible Bool, Thirst/Hunger/Both
            value = -1;
        };
        icon = "ico_defibrillator.paa";
    };

    class fuelEmpty {
        variable = "fuelEmpty";
        displayName = "STR_Item_FuelE";
        weight = 2;
        buyPrice = -1;
        sellPrice = 10;
        illegal = false;
        save = false;
        taxed = false;
        class dynmarket {
            dynmaic = false;
            prices[] = {600, 800}; // Lowest Price, Highest Price
        };
        class edibility {
            edible[] = {false, ""}; // Edible Bool, Thirst/Hunger/Both
            value = -1;
        };
        icon = "ico_fuelEmpty.paa";
    };

    class fuelFull {
        variable = "fuelFull";
        displayName = "STR_Item_FuelF";
        weight = 5;
        buyPrice = 850;
        sellPrice = 500;
        illegal = false;
        save = false;
        taxed = false;
        class dynmarket {
            dynmaic = false;
            prices[] = {600, 800}; // Lowest Price, Highest Price
        };
        class edibility {
            edible[] = {false, ""}; // Edible Bool, Thirst/Hunger/Both
            value = -1;
        };
        icon = "ico_fuel.paa";
    };

    class spikeStrip {
        variable = "spikeStrip";
        displayName = "STR_Item_SpikeStrip";
        weight = 15;
        buyPrice = 2500;
        sellPrice = 1200;
        illegal = true;
        save = false;
        taxed = false;
        class dynmarket {
            dynmaic = false;
            prices[] = {600, 800}; // Lowest Price, Highest Price
        };
        class edibility {
            edible[] = {false, ""}; // Edible Bool, Thirst/Hunger/Both
            value = -1;
        };
        icon = "ico_spikeStrip.paa";
    };

    class lockpick {
        variable = "lockpick";
        displayName = "STR_Item_Lockpick";
        weight = 1;
        buyPrice = 150;
        sellPrice = 75;
        illegal = true;
        save = false;
        taxed = false;
        class dynmarket {
            dynmaic = false;
            prices[] = {600, 800}; // Lowest Price, Highest Price
        };
        class edibility {
            edible[] = {false, ""}; // Edible Bool, Thirst/Hunger/Both
            value = -1;
        };
        icon = "ico_lockpick.paa";
    };

    class goldbar {
        variable = "goldBar";
        displayName = "STR_Item_GoldBar";
        weight = 12;
        buyPrice = -1;
        sellPrice = 95000;
        illegal = true;
        save = false;
        taxed = false;
        class dynmarket {
            dynmaic = false;
            prices[] = {600, 800}; // Lowest Price, Highest Price
        };
        class edibility {
            edible[] = {false, ""}; // Edible Bool, Thirst/Hunger/Both
            value = -1;
        };
        icon = "ico_goldBar.paa";
    };

    class blastingcharge {
        variable = "blastingCharge";
        displayName = "STR_Item_BCharge";
        weight = 15;
        buyPrice = 35000;
        sellPrice = 10000;
        illegal = true;
        save = false;
        taxed = false;
        class dynmarket {
            dynmaic = false;
            prices[] = {600, 800}; // Lowest Price, Highest Price
        };
        class edibility {
            edible[] = {false, ""}; // Edible Bool, Thirst/Hunger/Both
            value = -1;
        };
        icon = "ico_blastingCharge.paa";
    };

    class boltcutter {
        variable = "boltCutter";
        displayName = "STR_Item_BCutter";
        weight = 5;
        buyPrice = 7500;
        sellPrice = 1000;
        illegal = true;
        save = false;
        taxed = false;
        class dynmarket {
            dynmaic = false;
            prices[] = {600, 800}; // Lowest Price, Highest Price
        };
        class edibility {
            edible[] = {false, ""}; // Edible Bool, Thirst/Hunger/Both
            value = -1;
        };
        icon = "ico_boltCutter.paa";
    };

    class defusekit {
        variable = "defuseKit";
        displayName = "STR_Item_DefuseKit";
        weight = 2;
        buyPrice = 2500;
        sellPrice = 2000;
        illegal = true;
        save = false;
        taxed = false;
        class dynmarket {
            dynmaic = false;
            prices[] = {600, 800}; // Lowest Price, Highest Price
        };
        class edibility {
            edible[] = {false, ""}; // Edible Bool, Thirst/Hunger/Both
            value = -1;
        };
        icon = "ico_defuseKit.paa";
    };

    class storagesmall {
        variable = "storageSmall";
        displayName = "STR_Item_StorageBS";
        weight = 5;
        buyPrice = 75000;
        sellPrice = 50000;
        illegal = false;
        save = false;
        taxed = false;
        class dynmarket {
            dynmaic = false;
            prices[] = {600, 800}; // Lowest Price, Highest Price
        };
        class edibility {
            edible[] = {false, ""}; // Edible Bool, Thirst/Hunger/Both
            value = -1;
        };
        icon = "ico_storageSmall.paa";
    };

    class storagebig {
        variable = "storageBig";
        displayName = "STR_Item_StorageBL";
        weight = 10;
        buyPrice = 150000;
        sellPrice = 125000;
        illegal = false;
        save = false;
        taxed = false;
        class dynmarket {
            dynmaic = false;
            prices[] = {600, 800}; // Lowest Price, Highest Price
        };
        class edibility {
            edible[] = {false, ""}; // Edible Bool, Thirst/Hunger/Both
            value = -1;
        };
        icon = "ico_storageBig.paa";
    };

    //Mined Items
    class oil_unprocessed {
        variable = "oilUnprocessed";
        displayName = "STR_Item_OilU";
        weight = 7;
        buyPrice = -1;
        sellPrice = -1;
        illegal = false;
        save = false;
        taxed = false;
        class dynmarket {
            dynmaic = false;
            prices[] = {600, 800}; // Lowest Price, Highest Price
        };
        class edibility {
            edible[] = {false, ""}; // Edible Bool, Thirst/Hunger/Both
            value = -1;
        };
        icon = "ico_oilUnprocessed.paa";
    };

    class oil_processed {
        variable = "oilProcessed";
        displayName = "STR_Item_OilP";
        weight = 6;
        buyPrice = -1;
        sellPrice = 3200;
        illegal = false;
        save = false;
        taxed = false;
        class dynmarket {
            dynmaic = false;
            prices[] = {600, 800}; // Lowest Price, Highest Price
        };
        class edibility {
            edible[] = {false, ""}; // Edible Bool, Thirst/Hunger/Both
            value = -1;
        };
        icon = "ico_oilProcessed.paa";
    };

    class copper_unrefined {
        variable = "copperUnrefined";
        displayName = "STR_Item_CopperOre";
        weight = 4;
        buyPrice = -1;
        sellPrice = -1;
        illegal = false;
        save = false;
        taxed = false;
        class dynmarket {
            dynmaic = false;
            prices[] = {600, 800}; // Lowest Price, Highest Price
        };
        class edibility {
            edible[] = {false, ""}; // Edible Bool, Thirst/Hunger/Both
            value = -1;
        };
        icon = "ico_copperOre.paa";
    };

    class copper_refined {
        variable = "copperRefined";
        displayName = "STR_Item_CopperIngot";
        weight = 3;
        buyPrice = -1;
        sellPrice = 1500;
        illegal = false;
        save = false;
        taxed = false;
        class dynmarket {
            dynmaic = false;
            prices[] = {600, 800}; // Lowest Price, Highest Price
        };
        class edibility {
            edible[] = {false, ""}; // Edible Bool, Thirst/Hunger/Both
            value = -1;
        };
        icon = "ico_copper.paa";
    };

    class iron_unrefined {
        variable = "ironUnrefined";
        displayName = "STR_Item_IronOre";
        weight = 5;
        buyPrice = -1;
        sellPrice = -1;
        illegal = false;
        save = false;
        taxed = false;
        class dynmarket {
            dynmaic = false;
            prices[] = {600, 800}; // Lowest Price, Highest Price
        };
        class edibility {
            edible[] = {false, ""}; // Edible Bool, Thirst/Hunger/Both
            value = -1;
        };
        icon = "ico_ironOre.paa";
    };

    class iron_refined {
        variable = "ironRefined";
        displayName = "STR_Item_IronIngot";
        weight = 3;
        buyPrice = -1;
        sellPrice = 3200;
        illegal = false;
        save = false;
        taxed = false;
        class dynmarket {
            dynmaic = false;
            prices[] = {600, 800}; // Lowest Price, Highest Price
        };
        class edibility {
            edible[] = {false, ""}; // Edible Bool, Thirst/Hunger/Both
            value = -1;
        };
        icon = "ico_iron.paa";
    };

    class salt_unrefined {
        variable = "saltUnrefined";
        displayName = "STR_Item_Salt";
        weight = 3;
        buyPrice = -1;
        sellPrice = -1;
        illegal = false;
        save = false;
        taxed = false;
        class dynmarket {
            dynmaic = false;
            prices[] = {600, 800}; // Lowest Price, Highest Price
        };
        class edibility {
            edible[] = {false, ""}; // Edible Bool, Thirst/Hunger/Both
            value = -1;
        };
        icon = "ico_saltUnprocessed.paa";
    };

    class salt_refined {
        variable = "saltRefined";
        displayName = "STR_Item_SaltR";
        weight = 1;
        buyPrice = -1;
        sellPrice = 1450;
        illegal = false;
        save = false;
        taxed = false;
        class dynmarket {
            dynmaic = false;
            prices[] = {600, 800}; // Lowest Price, Highest Price
        };
        class edibility {
            edible[] = {false, ""}; // Edible Bool, Thirst/Hunger/Both
            value = -1;
        };
        icon = "ico_saltProcessed.paa";
    };

    class sand {
        variable = "sand";
        displayName = "STR_Item_Sand";
        weight = 3;
        buyPrice = -1;
        sellPrice = -1;
        illegal = false;
        save = false;
        taxed = false;
        class dynmarket {
            dynmaic = false;
            prices[] = {600, 800}; // Lowest Price, Highest Price
        };
        class edibility {
            edible[] = {false, ""}; // Edible Bool, Thirst/Hunger/Both
            value = -1;
        };
        icon = "ico_sand.paa";
    };

    class glass {
        variable = "glass";
        displayName = "STR_Item_Glass";
        weight = 1;
        buyPrice = -1;
        sellPrice = 1450;
        illegal = false;
        save = false;
        taxed = false;
        class dynmarket {
            dynmaic = false;
            prices[] = {600, 800}; // Lowest Price, Highest Price
        };
        class edibility {
            edible[] = {false, ""}; // Edible Bool, Thirst/Hunger/Both
            value = -1;
        };
        icon = "ico_glass.paa";
    };

    class diamond_uncut {
        variable = "diamondUncut";
        displayName = "STR_Item_DiamondU";
        weight = 4;
        buyPrice = -1;
        sellPrice = 750;
        illegal = false;
        save = false;
        taxed = false;
        class dynmarket {
            dynmaic = false;
            prices[] = {600, 800}; // Lowest Price, Highest Price
        };
        class edibility {
            edible[] = {false, ""}; // Edible Bool, Thirst/Hunger/Both
            value = -1;
        };
        icon = "ico_diamondUncut.paa";
    };

    class diamond_cut {
        variable = "diamondCut";
        displayName = "STR_Item_DiamondC";
        weight = 2;
        buyPrice = -1;
        sellPrice = 2000;
        illegal = false;
        save = false;
        taxed = false;
        class dynmarket {
            dynmaic = false;
            prices[] = {600, 800}; // Lowest Price, Highest Price
        };
        class edibility {
            edible[] = {false, ""}; // Edible Bool, Thirst/Hunger/Both
            value = -1;
        };
        icon = "ico_diamondCut.paa";
    };

    class rock {
        variable = "rock";
        displayName = "STR_Item_Rock";
        weight = 6;
        buyPrice = -1;
        sellPrice = -1;
        illegal = false;
        save = false;
        taxed = false;
        class dynmarket {
            dynmaic = false;
            prices[] = {600, 800}; // Lowest Price, Highest Price
        };
        class edibility {
            edible[] = {false, ""}; // Edible Bool, Thirst/Hunger/Both
            value = -1;
        };
        icon = "ico_rock.paa";
    };

    class cement {
        variable = "cement";
        displayName = "STR_Item_CementBag";
        weight = 5;
        buyPrice = -1;
        sellPrice = 1950;
        illegal = false;
        save = false;
        taxed = false;
        class dynmarket {
            dynmaic = false;
            prices[] = {600, 800}; // Lowest Price, Highest Price
        };
        class edibility {
            edible[] = {false, ""}; // Edible Bool, Thirst/Hunger/Both
            value = -1;
        };
        icon = "ico_cement.paa";
    };

    //Drugs
    class heroin_unprocessed {
        variable = "heroinUnprocessed";
        displayName = "STR_Item_HeroinU";
        weight = 6;
        buyPrice = -1;
        sellPrice = -1;
        illegal = true;
        save = false;
        taxed = false;
        class dynmarket {
            dynmaic = false;
            prices[] = {600, 800}; // Lowest Price, Highest Price
        };
        class edibility {
            edible[] = {false, ""}; // Edible Bool, Thirst/Hunger/Both
            value = -1;
        };
        icon = "ico_heroinUnprocessed.paa";
        processedItem = "heroin_processed";
    };

    class heroin_processed {
        variable = "heroinProcessed";
        displayName = "STR_Item_HeroinP";
        weight = 4;
        buyPrice = 3500;
        sellPrice = 2560;
        illegal = true;
        save = false;
        taxed = false;
        class dynmarket {
            dynmaic = false;
            prices[] = {600, 800}; // Lowest Price, Highest Price
        };
        class edibility {
            edible[] = {false, ""}; // Edible Bool, Thirst/Hunger/Both
            value = -1;
        };
        icon = "ico_heroinProcessed.paa";
    };

    class cannabis {
        variable = "cannabis";
        displayName = "STR_Item_Cannabis";
        weight = 4;
        buyPrice = -1;
        sellPrice = -1;
        illegal = true;
        save = false;
        taxed = false;
        class dynmarket {
            dynmaic = false;
            prices[] = {600, 800}; // Lowest Price, Highest Price
        };
        class edibility {
            edible[] = {false, ""}; // Edible Bool, Thirst/Hunger/Both
            value = -1;
        };
        icon = "ico_cannabis.paa";
        processedItem = "marijuana";
    };

    class marijuana {
        variable = "marijuana";
        displayName = "STR_Item_Marijuana";
        weight = 3;
        buyPrice = 2800;
        sellPrice = 2350;
        illegal = true;
        save = false;
        taxed = false;
        class dynmarket {
            dynmaic = false;
            prices[] = {600, 800}; // Lowest Price, Highest Price
        };
        class edibility {
            edible[] = {false, ""}; // Edible Bool, Thirst/Hunger/Both
            value = -1;
        };
        icon = "ico_marijuana.paa";
    };

    class cocaine_unprocessed {
        variable = "cocaineUnprocessed";
        displayName = "STR_Item_CocaineU";
        weight = 6;
        buyPrice = -1;
        sellPrice = -1;
        illegal = true;
        save = false;
        taxed = false;
        class dynmarket {
            dynmaic = false;
            prices[] = {600, 800}; // Lowest Price, Highest Price
        };
        class edibility {
            edible[] = {false, ""}; // Edible Bool, Thirst/Hunger/Both
            value = -1;
        };
        icon = "ico_cocaineUnprocessed.paa";
        processedItem = "cocaine_processed";
    };

    class cocaine_processed {
        variable = "cocaineProcessed";
        displayName = "STR_Item_CocaineP";
        weight = 4;
        buyPrice = -1;
        sellPrice = 5000;
        illegal = true;
        save = false;
        taxed = false;
        class dynmarket {
            dynmaic = false;
            prices[] = {600, 800}; // Lowest Price, Highest Price
        };
        class edibility {
            edible[] = {false, ""}; // Edible Bool, Thirst/Hunger/Both
            value = -1;
        };
        icon = "ico_cocaineProcessed.paa";
    };

    //Drink
    class redgull {
        variable = "redgull";
        displayName = "STR_Item_RedGull";
        weight = 1;
        buyPrice = 1500;
        sellPrice = 200;
        illegal = false;
        save = false;
        taxed = false;
        class dynmarket {
            dynmaic = false;
            prices[] = {600, 800}; // Lowest Price, Highest Price
        };
        class edibility {
            edible[] = {true, "Thirst"};
            value = 100;
        };
        icon = "ico_redgull.paa";
    };

    class coffee {
        variable = "coffee";
        displayName = "STR_Item_Coffee";
        weight = 1;
        buyPrice = 10;
        sellPrice = 5;
        illegal = false;
        save = false;
        taxed = false;
        class dynmarket {
            dynmaic = false;
            prices[] = {600, 800}; // Lowest Price, Highest Price
        };
        class edibility {
            edible[] = {true, "Thirst"};
            value = 100;
        };
        icon = "ico_coffee.paa";
    };

    class waterBottle {
        variable = "waterBottle";
        displayName = "STR_Item_WaterBottle";
        weight = 1;
        buyPrice = 10;
        sellPrice = 5;
        illegal = false;
        save = false;
        taxed = false;
        class dynmarket {
            dynmaic = false;
            prices[] = {600, 800}; // Lowest Price, Highest Price
        };
        class edibility {
            edible[] = {true, "Thirst"};
            value = 100;
        };
        icon = "ico_waterBottle.paa";
    };

    //Food
    class apple {
        variable = "apple";
        displayName = "STR_Item_Apple";
        weight = 1;
        buyPrice = 65;
        sellPrice = 50;
        illegal = false;
        save = false;
        taxed = false;
        class dynmarket {
            dynmaic = false;
            prices[] = {600, 800}; // Lowest Price, Highest Price
        };
        class edibility {
            edible[] = {true, "Hunger"};
            value = 10;
        };
        icon = "ico_apple.paa";
    };

    class peach {
        variable = "peach";
        displayName = "STR_Item_Peach";
        weight = 1;
        buyPrice = 68;
        sellPrice = 55;
        illegal = false;
        save = false;
        taxed = false;
        class dynmarket {
            dynmaic = false;
            prices[] = {600, 800}; // Lowest Price, Highest Price
        };
        class edibility {
            edible[] = {true, "Hunger"};
            value = 10;
        };
        icon = "ico_peach.paa";
    };

    class tbacon {
        variable = "tbacon";
        displayName = "STR_Item_TBacon";
        weight = 1;
        buyPrice = 75;
        sellPrice = 25;
        illegal = false;
        save = false;
        taxed = false;
        class dynmarket {
            dynmaic = false;
            prices[] = {600, 800}; // Lowest Price, Highest Price
        };
        class edibility {
            edible[] = {true, "Hunger"};
            value = 40;
        };
        icon = "ico_tBacon.paa";
    };

    class donuts {
        variable = "donuts";
        displayName = "STR_Item_Donuts";
        weight = 1;
        buyPrice = 120;
        sellPrice = 60;
        illegal = false;
        save = false;
        taxed = false;
        class dynmarket {
            dynmaic = false;
            prices[] = {600, 800}; // Lowest Price, Highest Price
        };
        class edibility {
            edible[] = {true, "Hunger"};
            value = 30;
        };
        icon = "ico_donuts.paa";
    };

    class rabbit_raw {
        variable = "rabbitRaw";
        displayName = "STR_Item_RabbitRaw";
        weight = 2;
        buyPrice = -1;
        sellPrice = 95;
        illegal = false;
        save = false;
        taxed = false;
        class dynmarket {
            dynmaic = false;
            prices[] = {600, 800}; // Lowest Price, Highest Price
        };
        class edibility {
            edible[] = {false, ""}; // Edible Bool, Thirst/Hunger/Both
            value = -1;
        };
        icon = "ico_rabbitRaw.paa";
    };

    class rabbit {
        variable = "rabbit";
        displayName = "STR_Item_Rabbit";
        weight = 1;
        buyPrice = 150;
        sellPrice = 115;
        illegal = false;
        save = false;
        taxed = false;
        class dynmarket {
            dynmaic = false;
            prices[] = {600, 800}; // Lowest Price, Highest Price
        };
        class edibility {
            edible[] = {true, "Hunger"};
            value = 20;
        };
        icon = "ico_rabbit.paa";
    };

    class salema_raw {
        variable = "salemaRaw";
        displayName = "STR_Item_SalemaRaw";
        weight = 2;
        buyPrice = -1;
        sellPrice = 45;
        illegal = false;
        save = false;
        taxed = false;
        class dynmarket {
            dynmaic = false;
            prices[] = {600, 800}; // Lowest Price, Highest Price
        };
        class edibility {
            edible[] = {false, ""}; // Edible Bool, Thirst/Hunger/Both
            value = -1;
        };
        icon = "ico_salemaRaw.paa";
    };

    class salema {
        variable = "salema";
        displayName = "STR_Item_Salema";
        weight = 1;
        buyPrice = 75;
        sellPrice = 55;
        illegal = false;
        save = false;
        taxed = false;
        class dynmarket {
            dynmaic = false;
            prices[] = {600, 800}; // Lowest Price, Highest Price
        };
        class edibility {
            edible[] = {true, "Hunger"};
            value = 30;
        };
        icon = "ico_cookedFish.paa";
    };

    class ornate_raw {
        variable = "ornateRaw";
        displayName = "STR_Item_OrnateRaw";
        weight = 2;
        buyPrice = -1;
        sellPrice = 40;
        illegal = false;
        save = false;
        taxed = false;
        class dynmarket {
            dynmaic = false;
            prices[] = {600, 800}; // Lowest Price, Highest Price
        };
        class edibility {
            edible[] = {false, ""}; // Edible Bool, Thirst/Hunger/Both
            value = -1;
        };
        icon = "ico_ornateRaw.paa";
    };

    class ornate {
        variable = "ornate";
        displayName = "STR_Item_Ornate";
        weight = 1;
        buyPrice = 175;
        sellPrice = 150;
        illegal = false;
        save = false;
        taxed = false;
        class dynmarket {
            dynmaic = false;
            prices[] = {600, 800}; // Lowest Price, Highest Price
        };
        class edibility {
            edible[] = {true, "Hunger"};
            value = 25;
        };
        icon = "ico_cookedFish.paa";
    };

    class mackerel_raw {
        variable = "mackerelRaw";
        displayName = "STR_Item_MackerelRaw";
        weight = 4;
        buyPrice = -1;
        sellPrice = 175;
        illegal = false;
        save = false;
        taxed = false;
        class dynmarket {
            dynmaic = false;
            prices[] = {600, 800}; // Lowest Price, Highest Price
        };
        class edibility {
            edible[] = {false, ""}; // Edible Bool, Thirst/Hunger/Both
            value = -1;
        };
        icon = "ico_mackerelRaw.paa";
    };

    class mackerel {
        variable = "mackerel";
        displayName = "STR_Item_Mackerel";
        weight = 2;
        buyPrice = 250;
        sellPrice = 200;
        illegal = false;
        save = false;
        taxed = false;
        class dynmarket {
            dynmaic = false;
            prices[] = {600, 800}; // Lowest Price, Highest Price
        };
        class edibility {
            edible[] = {true, "Hunger"};
            value = 30;
        };
        icon = "ico_cookedFish.paa";
    };

    class tuna_raw {
        variable = "tunaRaw";
        displayName = "STR_Item_TunaRaw";
        weight = 6;
        buyPrice = -1;
        sellPrice = 700;
        illegal = false;
        save = false;
        taxed = false;
        class dynmarket {
            dynmaic = false;
            prices[] = {600, 800}; // Lowest Price, Highest Price
        };
        class edibility {
            edible[] = {false, ""}; // Edible Bool, Thirst/Hunger/Both
            value = -1;
        };
        icon = "ico_tunaRaw.paa";
    };

    class tuna {
        variable = "tuna";
        displayName = "STR_Item_Tuna";
        weight = 3;
        buyPrice = 1250;
        sellPrice = 1000;
        illegal = false;
        save = false;
        taxed = false;
        class dynmarket {
            dynmaic = false;
            prices[] = {600, 800}; // Lowest Price, Highest Price
        };
        class edibility {
            edible[] = {true, "Hunger"};
            value = 100;
        };
        icon = "ico_cookedFish.paa";
    };

    class mullet_raw {
        variable = "mulletRaw";
        displayName = "STR_Item_MulletRaw";
        weight = 4;
        buyPrice = -1;
        sellPrice = 250;
        illegal = false;
        save = false;
        taxed = false;
        class dynmarket {
            dynmaic = false;
            prices[] = {600, 800}; // Lowest Price, Highest Price
        };
        class edibility {
            edible[] = {false, ""}; // Edible Bool, Thirst/Hunger/Both
            value = -1;
        };
        icon = "ico_mulletRaw.paa";
    };

    class mullet {
        variable = "mullet";
        displayName = "STR_Item_Mullet";
        weight = 2;
        buyPrice = 600;
        sellPrice = 400;
        illegal = false;
        save = false;
        taxed = false;
        class dynmarket {
            dynmaic = false;
            prices[] = {600, 800}; // Lowest Price, Highest Price
        };
        class edibility {
            edible[] = {true, "Hunger"};
            value = 80;
        };
        icon = "ico_cookedFish.paa";
    };

    class catshark_raw {
        variable = "catsharkRaw";
        displayName = "STR_Item_CatSharkRaw";
        weight = 6;
        buyPrice = -1;
        sellPrice = 300;
        illegal = false;
        save = false;
        taxed = false;
        class dynmarket {
            dynmaic = false;
            prices[] = {600, 800}; // Lowest Price, Highest Price
        };
        class edibility {
            edible[] = {false, ""}; // Edible Bool, Thirst/Hunger/Both
            value = -1;
        };
        icon = "ico_catsharkRaw.paa";
    };

    class catshark {
        variable = "catshark";
        displayName = "STR_Item_CatShark";
        weight = 3;
        buyPrice = 750;
        sellPrice = 500;
        illegal = false;
        save = false;
        taxed = false;
        class dynmarket {
            dynmaic = false;
            prices[] = {600, 800}; // Lowest Price, Highest Price
        };
        class edibility {
            edible[] = {true, "Hunger"};
            value = 100;
        };
        icon = "ico_cookedFish.paa";
    };

    class turtle_raw {
        variable = "turtleRaw";
        displayName = "STR_Item_TurtleRaw";
        weight = 6;
        buyPrice = -1;
        sellPrice = 3000;
        illegal = true;
        save = false;
        taxed = false;
        class dynmarket {
            dynmaic = false;
            prices[] = {600, 800}; // Lowest Price, Highest Price
        };
        class edibility {
            edible[] = {false, ""}; // Edible Bool, Thirst/Hunger/Both
            value = -1;
        };
        icon = "ico_turtleRaw.paa";
    };

    class turtle_soup {
        variable = "turtleSoup";
        displayName = "STR_Item_TurtleSoup";
        weight = 2;
        buyPrice = 1000;
        sellPrice = 750;
        illegal = false;
        save = false;
        taxed = false;
        class dynmarket {
            dynmaic = false;
            prices[] = {600, 800}; // Lowest Price, Highest Price
        };
        class edibility {
            edible[] = {true, "Hunger"};
            value = 100;
        };
        icon = "ico_turtleSoup.paa";
    };

    class hen_raw {
        variable = "henRaw";
        displayName = "STR_Item_HenRaw";
        weight = 1;
        buyPrice = -1;
        sellPrice = 65;
        illegal = false;
        save = false;
        taxed = false;
        class dynmarket {
            dynmaic = false;
            prices[] = {600, 800}; // Lowest Price, Highest Price
        };
        class edibility {
            edible[] = {false, ""}; // Edible Bool, Thirst/Hunger/Both
            value = -1;
        };
        icon = "ico_wholeChickenRaw.paa";
    };

    class hen {
        variable = "hen";
        displayName = "STR_Item_Hen";
        weight = 1;
        buyPrice = 115;
        sellPrice = 85;
        illegal = false;
        save = false;
        taxed = false;
        class dynmarket {
            dynmaic = false;
            prices[] = {600, 800}; // Lowest Price, Highest Price
        };
        class edibility {
            edible[] = {true, "Hunger"};
            value = 65;
        };
        icon = "ico_wholeChicken.paa";
    };

    class rooster_raw {
        variable = "roosterRaw";
        displayName = "STR_Item_RoosterRaw";
        weight = 1;
        buyPrice = -1;
        sellPrice = 65;
        illegal = false;
        save = false;
        taxed = false;
        class dynmarket {
            dynmaic = false;
            prices[] = {600, 800}; // Lowest Price, Highest Price
        };
        class edibility {
            edible[] = {false, ""}; // Edible Bool, Thirst/Hunger/Both
            value = -1;
        };
        icon = "ico_chickenDrumstickRaw.paa";
    };

    class rooster {
        variable = "rooster";
        displayName = "STR_Item_Rooster";
        weight = 115;
        buyPrice = 90;
        sellPrice = 85;
        illegal = false;
        save = false;
        taxed = false;
        class dynmarket {
            dynmaic = false;
            prices[] = {600, 800}; // Lowest Price, Highest Price
        };
        class edibility {
            edible[] = {true, "Hunger"};
            value = 45;
        };
        icon = "ico_chickenDrumstick.paa";
    };

    class sheep_raw {
        variable = "sheepRaw";
        displayName = "STR_Item_SheepRaw";
        weight = 2;
        buyPrice = -1;
        sellPrice = 95;
        illegal = false;
        save = false;
        taxed = false;
        class dynmarket {
            dynmaic = false;
            prices[] = {600, 800}; // Lowest Price, Highest Price
        };
        class edibility {
            edible[] = {false, ""}; // Edible Bool, Thirst/Hunger/Both
            value = -1;
        };
        icon = "ico_lambChopRaw.paa";
    };

    class sheep {
        variable = "sheep";
        displayName = "STR_Item_Sheep";
        weight = 2;
        buyPrice = 155;
        sellPrice = 115;
        illegal = false;
        save = false;
        taxed = false;
        class dynmarket {
            dynmaic = false;
            prices[] = {600, 800}; // Lowest Price, Highest Price
        };
        class edibility {
            edible[] = {true, "Hunger"};
            value = 100;
        };
        icon = "ico_lambChop.paa";
    };

    class goat_raw {
        variable = "goatRaw";
        displayName = "STR_Item_GoatRaw";
        weight = 2;
        buyPrice = -1;
        sellPrice = 115;
        illegal = false;
        save = false;
        taxed = false;
        class dynmarket {
            dynmaic = false;
            prices[] = {600, 800}; // Lowest Price, Highest Price
        };
        class edibility {
            edible[] = {false, ""}; // Edible Bool, Thirst/Hunger/Both/Both
            value = -1;
        };
        icon = "ico_muttonLegRaw.paa";
    };

    class goat {
        variable = "goat";
        displayName = "STR_Item_Goat";
        weight = 2;
        buyPrice = 175;
        sellPrice = 135;
        illegal = false;
        save = false;
        taxed = false;
        class dynmarket {
            dynmaic = false;
            prices[] = {600, 800}; // Lowest Price, Highest Price
        };
        class edibility {
            edible[] = {true, "Hunger"};
            value = 100;
        };
        icon = "ico_muttonLeg.paa";
    };
};
