class CfgProcess {
    class apple {
        MaterialsReq[] = {{"apple",1}};
        MaterialsGive[] = {{"apple_schnapps",1}};
        Text = "Processing Schnapps...";
        NoLicenseCost = 0;
    };

    class mango {
        MaterialsReq[] = {{"mango",1}};
        MaterialsGive[] = {{"mango_schnapps",1}};
        Text = "Processing Schnapps...";
        NoLicenseCost = 0;
    };

    class cococut {
        MaterialsReq[] = {{"cococut",1}};
        MaterialsGive[] = {{"cococut_schnapps",1}};
        Text = "Processing Schnapps...";
        NoLicenseCost = 0;
    };

    class apple {
        MaterialsReq[] = {{"apple",1}};
        MaterialsGive[] = {{"cider",1}};
        Text = "Processing Cider...";
        NoLicenseCost = 0;
    };

    class copper {
        MaterialsReq[] = {{"copper_ore",1}};
        MaterialsGive[] = {{"copper_bar",1}};
        Text = "Processing Copper...";
        NoLicenseCost = 0;
    };

    class silver {
        MaterialsReq[] = {{"silver_ore",1}};
        MaterialsGive[] = {{"silver_bar",1}};
        Text = "Processing Silver...";
        NoLicenseCost = 0;
    };

    class iron {
        MaterialsReq[] = {{"iron_ore",1}};
        MaterialsGive[] = {{"iron_bar",1}};
        Text = "Processing Iron...";
        NoLicenseCost = 0;
    };

    class platinum {
        MaterialsReq[] = {{"platinum_ore",1}};
        MaterialsGive[] = {{"platinum_bar",1}};
        Text = "Processing Platinum...";
        NoLicenseCost = 0;
    };

    class cement {
        MaterialsReq[] = {{"rock",1}};
        MaterialsGive[] = {{"cement",1}};
        Text = "Processing Cement...";
        NoLicenseCost = 0;
    };

    class oil {
        MaterialsReq[] = {{"crude_oil",1}};
        MaterialsGive[] = {{"refined_oil",1}};
        Text = "Processing Oil...";
        NoLicenseCost = 0;
    };

    class iridium {
        MaterialsReq[] = {{"iridium_ore",1}};
        MaterialsGive[] = {{"iridium_bar",1}};
        Text = "Processing Iridium...";
        NoLicenseCost = 0;
    };

    class gem { // Add array for all gem types
        MaterialsReq[] = {{"tin_ore",1}};
        MaterialsGive[] = {{"tin_bar",1}};
        Text = "Processing Gems...";
        NoLicenseCost = 0;
    };

    class marijuana {
        MaterialsReq[] = {{"cannabis",1}};
        MaterialsGive[] = {{"marijuana",1}};
        Text = "Processing Marijuana...";
        NoLicenseCost = 0;
    };

    class heroin {
        MaterialsReq[] = {{"opium",1}};
        MaterialsGive[] = {{"heroin",1}};
        Text = "Processing Heroin...";
        NoLicenseCost = 0;
    };

    class cocaine {
        MaterialsReq[] = {{"coca",1}};
        MaterialsGive[] = {{"cocaine",1}};
        Text = "Processing Cocaine...";
        NoLicenseCost = 0;
    };

    class ephedrine {
        MaterialsReq[] = {{"empty_fuel_can",1}};
        MaterialsGive[] = {{"ephedrine",1}};
        Text = "Processing Ephedrine...";
        NoLicenseCost = 0;
    };

    class methamphetamine {
        MaterialsReq[] = {{"ephedrine",1}};
        MaterialsGive[] = {{"methamphetamine",1}};
        Text = "Processing Methamphetamine...";
        NoLicenseCost = 0;
    };

    class drug_refining { // Add array for all drug types
        MaterialsReq[] = {{"marijuana",1}};
        MaterialsGive[] = {{"refined_marijuana",1}};
        Text = "Refining Drugs...";
        NoLicenseCost = 0;
    };

    class gold_debranding {
        MaterialsReq[] = {{"branded_gold_bar",1}};
        MaterialsGive[] = {{"unbranded_gold_bar",1}};
        Text = "Unbranding Gold...";
        NoLicenseCost = 0;
    };
};
