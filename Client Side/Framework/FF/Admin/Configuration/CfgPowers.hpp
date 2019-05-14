class CfgPowers {
	class dutyMode {
		title = "Duty Mode";
		onDuty = false;
		notify = true;
		dialogs = true;
		reqLevel = 2;
		message = "<t color = '#7300e6'>%1</t> has turned duty status <t color = '#7300e6'>%2</t>.";
		conditions = "";
		disableIF = "";
		tooltip = "Go on/off duty as a staff member..";
	};

	class godMode {
		title = "Godmode";
		onDuty = true;
		notify = true;
		dialogs = true;
		reqLevel = 2;
		message = "<t color = '#7300e6'>%1</t> has turned godmode <t color = '#7300e6'>%2</t>.";
		conditions = "";
		disableIF = "";
		tooltip = "Become immume to all damage types.";
	};

	class markers {
		title = "Markers";
		onDuty = true;
		notify = true;
		dialogs = true;
		reqLevel = 2;
		message = "<t color = '#7300e6'>%1</t> has turned markers <t color = '#7300e6'>%2</t>.";
		conditions = "";
		disableIF = "";
		tooltip = "Display all players on the map.";
	};
	
	class compensate {
		title = "Compensate";
		onDuty = true;
		notify = true;
		dialogs = true;
		reqLevel = 2;
		message = "<t color = '#7300e6'>%1</t> has compensated <t color = '#7300e6'>%2</t> for <t color = '#7300e6'>%3</t>.";
		conditions = "";
		disableIF = "";
		tooltip = "Compensate a selected player for a specific amount."; 
	};

	class camera {
		title = "Camera";
		onDuty = true;
		notify = true;
		dialogs = false;
		reqLevel = 2;
		message = "<t color = '#7300e6'>%1</t> entered the camera.";
		conditions = "";
		disableIF = "";
		tooltip = "Make use of the camera."; 
	};

	class teleportSelect {
		title = "tpSelect";
		onDuty = true;
		notify = true;
		dialogs = false;
		reqLevel = 2;
		message = "<t color = '#7300e6'>%1</t> has open the teleport menu.";
		conditions = "";
		disableIF = "";
		tooltip = "Teleport to a selected point on the map.";
	};

	class teleportTo {
		title = "TpTo";
		onDuty = true;
		notify = true;
		dialogs = false;
		reqLevel = 2;
		message = "<t color = '#7300e6'>%1</t> has teleported to <t color = '#7300e6'>%2</t>.";
		conditions = "";
		disableIF = "";
		tooltip = "Teleport to a selected player.";
	};

	class teleportHere {
		title = "TpHere";
		onDuty = true;
		notify = true;
		dialogs = false;
		reqLevel = 2;
		message = "<t color = '#7300e6'>%1</t> has teleported <t color = '#7300e6'>%2</t> to their location.";
		conditions = "";
		disableIF = "";
		tooltip = "Teleport a selected player to your location.";
	};

	class teleportToInVehicle {
		title = "TpToInVehicle";
		onDuty = true;
		notify = true;
		dialogs = false;
		reqLevel = 2;
		message = "<t color = '#7300e6'>%1</t> has teleported into the vehicle of <t color = '#7300e6'>%2</t>.";
		conditions = "";
		disableIF = "";
		tooltip = "Teleport inside a selected player's vehicle.";
	};

	class teleportHereInVehicle {
		title = "TpHereInVehicle";
		onDuty = true;
		notify = true;
		dialogs = false;
		reqLevel = 2;
		message = "<t color = '#7300e6'>%1</t> has teleported <t color = '#7300e6'>%2</t> into their vehicle.";
		conditions = "";
		disableIF = "";
		tooltip = "Teleport the selected player inside of your vehicle.";
	};

	class vehicleEject {
		title = "Vehicle Eject";
		onDuty = true;
		notify = true;
		dialogs = true;
		reqLevel = 2;
		message = "<t color = '#7300e6'>%1</t> has ejected <t color = '#7300e6'>%2</t> from their vehicle.";
		conditions = "";
		disableIF = "";
		tooltip = "Eject the selected player from their vehicle.";
	};

	class vehicleRepair {
		title = "Repair Vehicle";
		onDuty = true;
		notify = true;
		dialogs = true;
		reqLevel = 2;
		message = "<t color = '#7300e6'>%1</t> has repaired the vehicle of <t color = '#7300e6'>%2</t>.";
		conditions = "";
		disableIF = "";
		tooltip = "Repair the selected player's vehicle.";
	};

	class vehicleRefuel {
		title = "Refuel Vehicle";
		onDuty = true;
		notify = true;
		dialogs = true;
		reqLevel = 2;
		message = "<t color = '#7300e6'>%1</t> has refueled the vehicle of <t color = '#7300e6'>%2</t>.";
		conditions = "";
		disableIF = "";
		tooltip = "Refuel the selected player's vehicle.";
	};
};