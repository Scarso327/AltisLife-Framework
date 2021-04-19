class CfgMessages {
	length = 256;

	class Message {
		picture = "\a3\3den\data\Cfg3DEN\Comment\texture_ca.paa";
		displayName = "Private Message";
		sendTo[] = { "Police", "Medic", "Civilian" };
		ignoreStreamer = false;
		ignoreComms = false;
		alertSound = true;
		canReply = true;
		confirmSend = true;
		sender = "%1";
		targets = "";
		condition = "true";
	};

	class Reply : Message {
		displayName = "Reply";
		condition = "false";
	};

	class PoliceDispatch : Message {
		picture = "Data\UI\Messaging\999.paa";
		displayName = "APC Emergency Dispatch";
		targets = "[""Police""] call ULP_fnc_allMembers";
	};

	class NHSDispatch : PoliceDispatch {
		displayName = "NHS Emergency Dispatch";
		targets = "[""Medic""] call ULP_fnc_allMembers";
	};

	class NonEmergnecyDispatch : PoliceDispatch {
		picture = "Data\UI\Messaging\101.paa"; // ICON
		displayName = "Non-Emergency Dispatch";
		alertSound = false;
		targets = "[""Police""] call ULP_fnc_allMembers && { [""Medic""] call ULP_fnc_allMembers } && { [""Hato""] call ULP_fnc_allMembers }";
	};

	class PublicAnnoucement : Message {
		picture = "Data\UI\Messaging\publicAnnouncement.paa";
		displayName = "Public Annoucement";
		ignoreStreamer = true;
		ignoreComms = true;
		canReply = false;
		sender = "Server";
		targets = "0";
		condition = "[""ULP_Staff"", 3] call ULP_fnc_hasAccess || { [""Police_Main"", 10] call ULP_fnc_hasAccess }";
	};

	class EventsAnnoucement : PublicAnnoucement {
		picture = "Data\UI\Messaging\eventAnnouncement.paa";
		displayName = "Event Annoucement";
		sender = "Events Team";
		targets = "0";
		condition = "[""ULP_Staff"", 2] call ULP_fnc_hasAccess || { [""ULP_Event"", 1] call ULP_fnc_hasAccess }";
	};

	class OpenAirBroadcast : PublicAnnoucement {
		displayName = "Open Air Broadcast";
		sender = "Altis Police Constabulary";
		targets = "(allPlayers select { !(isNull (objectParent _x)) && { (vehicle _x) isKindOf 'Air'} })";
		condition = "[""Police_Main"", 2] call ULP_fnc_hasAccess";
	};

	class Dispute : Message {
		picture = "Data\UI\dispute.paa";
		displayName = "Dispute";
		ignoreStreamer = true;
		ignoreComms = true;
		condition = "false";
	};

	class Panic : Dispute {
		displayName = "Panic Button";
		ignoreComms = false;
		alertSound = false;
		confirmSend = false;
		onRecieved = "private _sender = _this select 0; if (isNull _sender || { _sender isEqualTo player }) exitWith {}; private _marker = createMarkerLocal [format[""panic_marker_%1_%2"", time, name _sender], getPos _sender]; _marker setMarkerTypeLocal ""mil_warning""; _marker setMarkerColorLocal ""colorRed""; _marker setMarkerTextLocal (name _sender); [15, _marker, { deleteMarkerLocal _this }] call ULP_fnc_waitExecute;";
		targets = "[""Police""] call ULP_fnc_allMembers";
	};

	class Robbery : Panic {
		displayName = "Robbery";
		onRecieved = "private _sender = _this select 0; if (isNull _sender || { _sender isEqualTo player }) exitWith {};";
	};

	class BreakIn : Panic {
		displayName = "Break In";
		onRecieved = "private _sender = _this select 0; if (isNull _sender || { _sender isEqualTo player }) exitWith {}; private _marker = createMarkerLocal [format[""panic_marker_%1_%2"", time, name _sender], getPos _sender]; _marker setMarkerTypeLocal ""mil_warning""; _marker setMarkerColorLocal ""colorRed""; _marker setMarkerTextLocal ""Reported Break In""; [15, _marker, { deleteMarkerLocal _this }] call ULP_fnc_waitExecute;";
	};
};