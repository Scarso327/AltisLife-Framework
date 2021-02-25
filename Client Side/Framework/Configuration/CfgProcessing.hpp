class CfgProcessing {
	class BaseProcess {
		processTitle = "Processing";
		processTime = 60; // Time in seconds per item made
		factions[] = { "Civilian" };
		reqItems[] = {};
		reqLicenses[] = {};
	};

	class Copper : BaseProcess {
		processTitle = "Smelting";
		materials[] = { { "CopperOre", 1 } };
		items[] = { { "Copper", 1 } };
	};
};