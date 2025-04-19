class CfgBases {
	// Bidding info...
	Day = "Saturday";
	Restart[] = {18, 20};

	BidIncrement = 1000000;
	StartingBid = 9000000; // StartingBid = BidIncrement + StartingBid
	GangWarsOnlyMarkers[] = { "spawn_1", "greenzone_09", "spawn_2", "greenzone_10", "chop_shop_red" };

	class North {
		icon = "Data\UI\Spawns\base.paa";
		displayName = "North Base";
		position[] = {{12044.9, 10492.4, -0.303827}, 0};
		includeBidding = true;
		defaultGroupOwnerId = -1;
	};

	// class South : North {
	// 	displayName = "South Base";
	// 	position[] = {{12295.3,8872.94,0.00119019}, 289.015};
	// };
};