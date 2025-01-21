class CfgCartels {
	class Popup {
		duration = 30 * 60;
		captureTime = 10 * 60;
		reward[] = { 600000, 1200000 };
	};

	class Fixed {
		cartelTick = 1 * 60;
		rewardTicks = 20;
		rewardXp = 100;
		rewardAmounts[] = { 75, 150 }; // At or below 25 players, above 25
		maxRewardScoreMultiplier = 30;
		maxScoreLead = 5;
		allowPoliceNeutralise = true;
		policeNeutralisePerTick = 5;
		decreasePerRewardTick = 2;

		class Northern {
			name = "Northern Drug Cartel";
			factions[] = { "Police", "Civilian" };
			position[] = {14295, 13029, 0};
			zoneRadius = 50;
			kosRadius = 300;
			class Drug {
				extraPay = 1.05;
				saleTax = 0.05;
			};
		};

		class Southern {
			name = "Southern Drug Cartel";
			factions[] = { "Police", "Civilian" };
			position[] = {11194, 8717, 0};
			zoneRadius = 75;
			kosRadius = 0;
			class Drug {
				extraPay = 1.025;
				saleTax = 0.1;
			};
		};

		class Church {
			name = "Church Arms Cartel";
			factions[] = { "Police", "Civilian" };
			position[] = {8926, 7493, 0};
			zoneRadius = 50;
			kosRadius = 0;
			class Arms {
				primaryDiscount = 0.25;
				secondaryDiscount = 0.25;
			};
		};

		class Zaros {
			name = "Zaros Bay Cartel";
			factions[] = { "Police", "Civilian" };
			position[] = {10037, 10130, 0};
			zoneRadius = 40;
			kosRadius = 0;
			class Arms {
				primaryDiscount = 0.01;
				secondaryDiscount = 0.1;
			};
			class Chop {
				extraPay = 0.05;
				keepChance = 0.025;
			};
		};

		class Pefkas {
			name = "Pefkas Bay Cartel";
			factions[] = { "Police", "Civilian" };
			position[] = {20600, 20116, 0};
			zoneRadius = 50;
			kosRadius = 300;
			class Drug {
				extraPay = 1.015;
				saleTax = 0.025;
			};
			class Arms {
				primaryDiscount = 0.025;
				secondaryDiscount = 0.05;
			};
		};
	};
};