class CfgGoals {
	class Personal {
		class Daily {
			Amount = 3;

			class ArrestPeople {
				item = ""; // For goals like these we don't provide an item, the field is still required
				icon = "Data\UI\Goals\arrests.paa"; // Optional override
				title = "Arrest Criminals";
				description = "Arrest some criminals before today's end!";
				tiers[] = { 1, 5, 10 };
				factions[] = { "Police" };
				class Event {
					eventType = "ArrestedSomeone";
					getQuantity = "1";
				};
				condition = "true";
			};

			class IssueTickets : ArrestPeople {
				title = "Issue Paid Tickets";
				description = "Issue tickets before today's end!";
				tiers[] = { 25000, 100000, 250000 };
				class Event {
					eventType = "TicketPaid";
					getQuantity = "(_this select 1) params [ """", ""_amount"", ""_paid"" ]; if !(_paid) exitWith { 0 }; _amount";
				};
			};

			class RevivePeople  : ArrestPeople {
				icon = "\a3\ui_f\data\IGUI\Cfg\simpleTasks\types\heal_ca.paa";
				title = "Revive People";
				description = "Provide quality medical assistance before today's end!";
				tiers[] = { 1, 10, 25 };
				factions[] = { "Medic" };
				class Event {
					eventType = "RevivedSomeone";
				};
			};

			class GatherApple {
				item = "FreshApple";
				title = "Gather Apples";
				description = "Gather Fresh Apples before today's end!";
				tiers[] = { 250, 500, 1000 };
				factions[] = { "Civilian" };
				class Event {
					eventType = "GatheredVirtualItem";
					getQuantity = "_this params [ ""_cfgItem"", ""_eventParams"" ]; _eventParams params [ ""_eventItem"", ""_eventAmount"" ];  if !(_eventItem isEqualTo _cfgItem) exitWith { 0 }; _eventAmount";
				};
				condition = "true";
			};

			class GatherPeach : GatherApple {
				item = "FreshPeach";
				title = "Gather Peaches";
				description = "Gather Fresh Peachs before today's end!";
			};

			class GatherCoral : GatherApple {
				item = "Coral";
				title = "Gather Coral";
				description = "Gather Coral before today's end!";
				tiers[] = { 100, 300, 500 };
			};

			class GatherCorn : GatherApple {
				item = "Corn";
				title = "Gather Corn";
				description = "Gather Corn before today's end!";
			};

			class MineCoal : GatherApple {
				item = "Coal";
				title = "Mine Coal";
				description = "Mine Coal before today's end!";
				tiers[] = { 100, 300, 750 };
			};

			class MineCopper : MineCoal {
				item = "CopperOre";
				title = "Mine Copper";
				description = "Mine Copper before today's end!";
			};

			class MineSilver : MineCoal {
				item = "SilverOre";
				title = "Mine Silver";
				description = "Mine Silver before today's end!";
			};

			class MineIron : MineCoal {
				item = "IronOre";
				title = "Mine Iron";
				description = "Mine Iron before today's end!";
			};

			class ProcessTobacco {
				item = "Tobacco";
				title = "Process Tobacco";
				description = "Process Tobacco before today's end!";
				tiers[] = { 100, 250, 500 };
				factions[] = { "Civilian" };
				class Event {
					eventType = "ProcessedVirtualItem";
					getQuantity = "_this params [ ""_cfgItem"", ""_eventParams"" ]; _eventParams params [ ""_eventItem"", ""_eventAmount"" ];  if !(_eventItem isEqualTo _cfgItem) exitWith { 0 }; _eventAmount";
				};
				condition = "true";
			};

			class ProcessOil : ProcessTobacco {
				item = "UnprocessedOil";
				title = "Process Oil";
				description = "Process Oil before today's end!";
			};
			
			class ProcessSand : ProcessTobacco {
				item = "Sand";
				title = "Process Sand";
				description = "Process Sand before today's end!";
			};

			class ProcessSalt : ProcessTobacco {
				item = "UnrefinedSalt";
				title = "Process Salt";
				description = "Process Salt before today's end!";
			};

			class UncutDiamond : ProcessTobacco {
				item = "UncutDiamond";
				title = "Process Diamonds";
				description = "Process Diamond before today's end!";
			};

			class ProcessUranium : ProcessTobacco {
				item = "UraniumOre";
				title = "Process Uranium";
				description = "Process Uranium before today's end!";
				tiers[] = { 100, 200, 300 };
			};
		};

		class Weekly {
			Amount = 2;

			class SellSchnapps {
				item = "Schnapps";
				title = "Sell Schnapps";
				description = "Sell Schnapps before the week's end!";
				tiers[] = { 1000, 2000, 3000 };
				factions[] = { "Civilian" };
				class Event {
					eventType = "SoldVirtualItem";
					getQuantity = "_this params [ ""_cfgItem"", ""_eventParams"" ]; _eventParams params [ ""_eventItem"", ""_eventAmount"" ];  if !(_eventItem isEqualTo _cfgItem) exitWith { 0 }; _eventAmount";
				};
				condition = "true";
			};

			class SellCigarette : SellSchnapps {
				item = "Cigarette";
				title = "Sell Cigarettes";
				description = "Sell Cigarettes before the week's end!";
			};

			class SellCigar : SellSchnapps {
				item = "Cigar";
				title = "Sell Cigars";
				description = "Sell Cigars before the week's end!";
			};

			class SellCopper : SellSchnapps {
				item = "CopperBar";
				title = "Sell Copper";
				description = "Sell Copper before the week's end!";
			};

			class SellSilver : SellSchnapps {
				item = "SilverBar";
				title = "Sell Silver";
				description = "Sell Silver before the week's end!";
			};

			class SellIron : SellSchnapps {
				item = "IronBar";
				title = "Sell Iron";
				description = "Sell Iron before the week's end!";
			};

			class SellSand : SellSchnapps {
				item = "Glass";
				title = "Sell Glass";
				description = "Sell Sand before the week's end!";
			};

			class SellSalt : SellSchnapps {
				item = "RefinedSalt";
				title = "Sell Salt";
				description = "Sell Salt before the week's end!";
			};

			class SellDiamond : SellSchnapps {
				item = "CutDiamond";
				title = "Sell Diamond";
				description = "Sell Diamond before the week's end!";
			};

			class SellMoonshine : SellSchnapps {
				item = "Moonshine";
				title = "Sell Moonshine";
				description = "Sell Moonshine before the week's end!";
			};
		};
	};

	class Community {
		amountPerFaction[] =  { { "Police", 2 }, { "Medic", 1 }, { "Hato", 1 }, { "Civilian", 2 } };

		class ArrestPeople {
			item = ""; // For goals like these we don't provide an item, the field is still required
			icon = "Data\UI\Goals\arrests.paa"; // Optional override
			title = "Arrest Criminals";
			basePayout = 50000;
			maxPayout = 5000000;
			tiers[] = { 25, 100, 200 };
			duration = 7; 
			factions[] = { "Police" };
			class Event {
				eventType = "ArrestedSomeone";
				getQuantity = "1";
			};
		};

		class IssueTickets : ArrestPeople {
			title = "Issue Paid Tickets";
			tiers[] = { 1000000, 1750000, 2000000 };
			class Event {
				eventType = "TicketPaid";
				getQuantity = "(_this select 1) params [ """", ""_amount"", ""_paid"" ]; if !(_paid) exitWith { 0 }; _amount";
			};
		};

		class RevivePeople {
			item = ""; // For goals like these we don't provide an item, the field is still required
			icon = "\a3\ui_f\data\IGUI\Cfg\simpleTasks\types\heal_ca.paa"; // Optional override
			title = "Revive People";
			basePayout = 50000;
			maxPayout = 500000;
			tiers[] = { 25, 100, 200 };
			duration = 7; 
			factions[] = { "Medic" };
			class Event {
				eventType = "RevivedSomeone";
				getQuantity = "1";
			};
		};
		
		class GatherApple {
			item = "FreshApple";
			title = "Gather Apples";
			basePayout = 1000000;
			maxPayout = 16000000;
			tiers[] = { 2000, 3600, 4880, 5904, 6723, 7378, 7902, 8321, 8656, 9000 };
			duration = 14; // In days
			factions[] = { "Civilian" };
			class Event {
				eventType = "GatheredVirtualItem";
				getQuantity = "_this params [ ""_cfgItem"", ""_eventParams"" ]; _eventParams params [ ""_eventItem"", ""_eventAmount"" ];  if !(_eventItem isEqualTo _cfgItem) exitWith { 0 }; _eventAmount";
			};
		};

		class SellSchnapps {
			item = "Schnapps";
			title = "Sell Schnapps";
			basePayout = 1000000;
			maxPayout = 16000000;
			tiers[] = { 2000, 3600, 4880, 5904, 6723, 7378, 7902, 8321, 8656, 9000 };
			duration = 14; // In days
			factions[] = { "Civilian" };
			class Event {
				eventType = "SoldVirtualItem";
				getQuantity = "_this params [ ""_cfgItem"", ""_eventParams"" ]; _eventParams params [ ""_eventItem"", ""_eventAmount"" ];  if !(_eventItem isEqualTo _cfgItem) exitWith { 0 }; _eventAmount";
			};
		};

		class SellCigarette : SellSchnapps {
			item = "Cigarette";
			title = "Sell Cigarettes";
		};

		class SellCigar : SellSchnapps {
			item = "Cigar";
			title = "Sell Cigars";
		};

		class SellCopper : SellSchnapps {
			item = "CopperBar";
			title = "Sell Copper";
		};

		class SellSilver : SellSchnapps {
			item = "SilverBar";
			title = "Sell Silver";
		};

		class SellIron : SellSchnapps {
			item = "IronBar";
			title = "Sell Iron";
		};

		class SellSand : SellSchnapps {
			item = "Glass";
			title = "Sell Glass";
		};

		class SellSalt : SellSchnapps {
			item = "RefinedSalt";
			title = "Sell Salt";
		};

		class SellDiamond : SellSchnapps {
			item = "CutDiamond";
			title = "Sell Diamond";
		};

		class SellMoonshine : SellSchnapps {
			item = "Moonshine";
			title = "Sell Moonshine";
		};
	};
};