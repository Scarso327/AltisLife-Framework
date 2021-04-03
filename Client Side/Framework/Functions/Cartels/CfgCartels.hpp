class CfgCartels {
	class Fixed {
		cartelTick = 1 * 60;
		rewardTicks = 15; // Give reward every 15 ticks... (cartelTick * 15) seconds

		class Northern {
			name = "Northern Drug Cartel";
			factions[] = { "Police", "Civilian" };
			position[] = {14289, 13030.1, 0};
			zoneRadius = 50;
			kosRadius = 300;
			class Drug {
				extraPay = 0.15;
				saleTax = 0.1;
			};
		};

		class Church {
			name = "Church Arms Cartel";
			factions[] = { "Police", "Civilian" };
			position[] = {8916.57, 7482.06, 0};
			zoneRadius = 100;
			kosRadius = 1000;
			class Arms {
				primaryDiscount = 0.1;
				secondaryDiscount = 0.15;
			};
		};

		class Zaros {
			name = "Zaros Bay Cartel";
			factions[] = { "Police", "Civilian" };
			position[] = {10027.1, 10125.1, 0};
			zoneRadius = 80;
			kosRadius = 100;
			class Drug {
				extraPay = 0.15;
				saleTax = 0.1;
			};
			class Arms {
				primaryDiscount = 0.1;
				secondaryDiscount = 0.15;
			};
		};
	};
};