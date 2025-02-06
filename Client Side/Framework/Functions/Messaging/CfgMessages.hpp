class CfgMessages {
	length = 256;

	class Message {
		picture = "\a3\3den\data\Cfg3DEN\Comment\texture_ca.paa";
		displayName = "Private Message";
		sendTo[] = { "Police", "Medic", "Hato", "Civilian" };
		ignoreStreamer = false;
		ignoreComms = false;
		alertSound = true;
		canReply = true;
		confirmSend = true;
		saveInbox = true;
		log = false;
		sender = "%1";
		targets = "";
		condition = "true";
	};

	class StaffMessage : Message {
		displayName = "Message as Staff";
		ignoreStreamer = true;
		ignoreComms = true;
		sender = "Staff Member";
		condition = "[""ULP_Staff"", 2] call ULP_fnc_hasAccess";
	};

	class Reply : Message {
		displayName = "Reply";
		condition = "false";
	};

	class StaffDispatch : Message {
		picture = "Data\UI\Messaging\staffDispatch.paa";
		displayName = "Message Staff Team";
		ignoreStreamer = true;
		ignoreComms = true;
		targets = "(allPlayers select { [_x] call ULP_fnc_onDuty })";
	};

	class PoliceEmergencyDispatch : Message {
		picture = "Data\UI\Messaging\999.paa";
		displayName = "Police Emergency Dispatch";
		targets = "[""Police""] call ULP_fnc_allMembers";
	};

	class HealthEmergencyDispatch : PoliceEmergencyDispatch {
		displayName = "Medical Emergency Dispatch";
		targets = "[""Medic""] call ULP_fnc_allMembers";
	};

	class NonEmergnecyDispatch : PoliceEmergencyDispatch {
		picture = "Data\UI\Messaging\101.paa";
		displayName = "HATO Non-Emergency Dispatch";
		targets = "[""Hato""] call ULP_fnc_allMembers";
	};

	class GovernmentAnnoucement : Message {
		picture = "Data\UI\Spawns\government.paa";
		displayName = "HM Government";
		ignoreStreamer = true;
		canReply = false;
		sender = "HM Government";
		targets = "0";
		condition = "[] call ULP_fnc_isGovernor || { [""Police_Main"", 8] call ULP_fnc_hasAccess } || { [""ULP_Staff"", 4] call ULP_fnc_hasAccess }";
	};

	class PublicAnnoucement : GovernmentAnnoucement {
		picture = "Data\UI\Messaging\publicAnnouncement.paa";
		displayName = "Staff Annoucement";
		sender = "Staff Team";
		condition = "[""ULP_Staff"", 2] call ULP_fnc_hasAccess";
	};

	class EventsAnnoucement : PublicAnnoucement {
		picture = "Data\UI\Messaging\eventAnnouncement.paa";
		displayName = "Event Annoucement";
		sender = "Events Team";
		condition = "[""ULP_Staff"", 2] call ULP_fnc_hasAccess || { [""ULP_Event"", 1] call ULP_fnc_hasAccess }";
	};

	class OpenAirBroadcast : PublicAnnoucement {
		displayName = "Open Air Broadcast";
		sender = "Altis Police Service";
		targets = "(allPlayers select { !(isNull (objectParent _x)) && { (vehicle _x) isKindOf 'Air'} })";
		condition = "[""Police_Main"", 2] call ULP_fnc_hasAccess";
		log = true;
	};

	class OpenSeaBroadcast : OpenAirBroadcast {
		displayName = "Open Sea Broadcast";
		targets = "(allPlayers select { !(isNull (objectParent _x)) && { (vehicle _x) isKindOf 'Ship'} })";
	};

	class Dispute : Message {
		picture = "Data\UI\dispute.paa";
		displayName = "Dispute";
		ignoreStreamer = true;
		ignoreComms = true;
		condition = "false";
	};

	class MedicRequest : Dispute {
		displayName = "Medic Request";
		confirmSend = false;
		saveInbox = false;
		targets = "[""Medic""] call ULP_fnc_allMembers";
	};

	class Panic : Dispute {
		displayName = "Panic Button";
		ignoreComms = false;
		alertSound = false;
		confirmSend = false;
		saveInbox = false;
		canReply = false;
		onRecieved = "private _sender = _this select 0; if (isNull _sender || { _sender isEqualTo player }) exitWith {}; private _marker = createMarkerLocal [format[""panic_marker_%1_%2"", time, name _sender], getPos _sender]; _marker setMarkerTypeLocal ""mil_warning""; _marker setMarkerColorLocal ""colorRed""; _marker setMarkerTextLocal (name _sender); [60, _marker, { deleteMarkerLocal _this }] call ULP_fnc_waitExecute;";
		targets = "[""Police""] call ULP_fnc_allMembers";
	};

	class Robbery : Panic {
		displayName = "Robbery";
		sender = "Police Dispatch";
		onRecieved = "private _sender = _this select 0; if (isNull _sender || { _sender isEqualTo player }) exitWith {};";
	};

	class BreakIn : Panic {
		displayName = "Break In";
		sender = "Police Dispatch";
		onRecieved = "private _sender = _this select 0; if (isNull _sender || { _sender isEqualTo player }) exitWith {}; private _marker = createMarkerLocal [format[""breakin_marker_%1_%2"", time, name _sender], getPos _sender]; _marker setMarkerTypeLocal ""mil_warning""; _marker setMarkerColorLocal ""colorRed""; _marker setMarkerTextLocal ""Reported Break In""; [60, _marker, { deleteMarkerLocal _this }] call ULP_fnc_waitExecute;";
	};
};