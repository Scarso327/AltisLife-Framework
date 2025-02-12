class CfgVehicleUpgrades {
	class ImprovedStorageUpgrade {
		icon = "Data\Icons\improvedStorageUpgrade.paa";
		displayName = "Improved Storage Upgrade";
		description = "Increases max virtual storage space by <t color='#B92DE0'>10%</t>";
		time = 1 * 60;
		materials[] = { { "ImprovedStorageUpgrade", 1 } };
		onApplied = "";
		condition = "true";
	};

	class ImprovedLocksUpgrade : ImprovedStorageUpgrade {
		icon = "Data\Icons\improvedLocksUpgrade.paa";
		displayName = "Improved Locks Upgrade";
		description = "Increases the time it takes to lockpick by <t color='#B92DE0'>50%</t>";
		materials[] = { { "ImprovedLocksUpgrade", 1 } };
	};

	class ImprovedHullUpgrade : ImprovedStorageUpgrade {
		icon = "Data\Icons\improvedHullUpgrade.paa";
		displayName = "Improved Hull Upgrade";
		description = "Increases hull armour value by <t color='#B92DE0'>25%</t>";
		materials[] = { { "ImprovedHullUpgrade", 1 } };
	};

	class ImprovedTyresUpgrade : ImprovedStorageUpgrade {
		icon = "Data\Icons\tyre.paa";
		displayName = "Improved Tyres Upgrade";
		description = "Increases tyre armour value by <t color='#B92DE0'>25%</t>";
		materials[] = { { "ImprovedTyresUpgrade", 1 } };
	};

	class EfficientEngineUpgrade : ImprovedStorageUpgrade {
		icon = "Data\Icons\improvedEngineUpgrade.paa";
		displayName = "Efficient Engine Upgrade";
		description = "Decreases fuel consumption by <t color='#B92DE0'>30%</t> [Mutually exclusive with Performance Engine]";
		materials[] = { { "EfficientEngineUpgrade", 1 } };
		onApplied = "private _fuelConsumptionRateCoef = getFuelConsumptionCoef _this; _fuelConsumptionRateCoef = _fuelConsumptionRateCoef - (_fuelConsumptionRateCoef * 0.3); _this setFuelConsumptionCoef _fuelConsumptionRateCoef;";
		condition = "!([_this, ""PerformanceEngineUpgrade""] call ULP_fnc_hasVehicleUpgrade)";
	};

	class StongCasingUpgrade : ImprovedStorageUpgrade {
		icon = "Data\Icons\stongCasingUpgrade.paa";
		displayName = "Stong Casing Upgrade";
		description = "Increases chop process by <t color='#B92DE0'>50%</t>";
		materials[] = { { "StongCasingUpgrade", 1 } };
	};

	class TrackingDeviceUpgrade : ImprovedStorageUpgrade {
		icon = "Data\Icons\trackingDeviceUpgrade.paa";
		displayName = "Tracking Device Upgrade";
		description = "Live location of the vehicle on your map when you have keys";
		materials[] = { { "TrackingDeviceUpgrade", 1 } };
	};

	class ClonedPlatesUpgrade : ImprovedStorageUpgrade {
		icon = "Data\Icons\clonedPlatesUpgrade.paa";
		displayName = "Cloned Plates Upgrade";
		description = "Randomises the vehicle's plate for ANPR systems";
		materials[] = { { "ClonedPlatesUpgrade", 1 } };
	};
};