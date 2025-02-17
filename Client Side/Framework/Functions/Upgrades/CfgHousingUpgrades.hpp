class CfgHousingUpgrades {
	class PersonalAlarmUpgrade {
		icon = "Data\Icons\personalAlarmUpgrade.paa";
		displayName = "Improved Storage Upgrade";
		description = "Notifies you when someone is breaking into your property";
		time = 1 * 60;
		materials[] = { { "PersonalAlarmUpgrade", 1 } };
		onApplied = "";
		condition = "true";
	};
};