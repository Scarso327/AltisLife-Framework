class CfgHousingUpgrades {
	class PersonalAlarmUpgrade {
		icon = "Data\Icons\personalAlarmUpgrade.paa";
		displayName = "Personal Alarm Upgrade";
		description = "Notifies you when someone is breaking into your property";
		time = 1 * 60;
		materials[] = { { "PersonalAlarmUpgrade", 1 } };
		onApplied = "";
		condition = "true";
	};
	class CentralAlarmUpgrade : PersonalAlarmUpgrade {
		displayName = "Central Alarm Upgrade";
		description = "Notifies your group when someone are breaking into your property";
		materials[] = { { "CentralAlarmUpgrade", 1 } };
	};
	class ImprovedDoorsUpgrade : PersonalAlarmUpgrade {
		icon = "Data\Icons\improvedDoorsUpgrade.paa";
		displayName = "Improved Doors Upgrade";
		description = "Increases the time to break door locks by <t color='#B92DE0'>50%</t>";
		materials[] = { { "ImprovedDoorsUpgrade", 1 } };
	};
	class ImprovedContainerUpgrade : PersonalAlarmUpgrade {
		icon = "Data\Icons\improvedStorageUpgrade.paa";
		displayName = "Improved Container Upgrade";
		description = "Increases vItem storage by <t color='#B92DE0'>10%</t>";
		materials[] = { { "ImprovedContainerUpgrade", 1 } };
	};
};