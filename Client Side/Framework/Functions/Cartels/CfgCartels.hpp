class CfgCartels {
	class Fixed {
		cartelTick = 1 * 60;
		rewardTicks = 15;

		class Northern {
			name = "Northern Drug Cartel";
			factions[] = { "Police", "Civilian" };
			position[] = {14295, 13029, 0};
			zoneRadius = 50;
			kosRadius = 300;
			class Drug {
				extraPay = 0.2;
				saleTax = 0.1;
			};
		};

		class Southern {
			name = "Southern Drug Cartel";
			factions[] = { "Police", "Civilian" };
			position[] = {11194, 8717, 0};
			zoneRadius = 75;
			kosRadius = 0;
			class Drug {
				extraPay = 0.1;
				saleTax = 0.2;
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
			class Drug {
				extraPay = 0.1;
				saleTax = 0.1;
			};
			class Arms {
				primaryDiscount = 0.1;
				secondaryDiscount = 0.1;
			};
		};
	};
};