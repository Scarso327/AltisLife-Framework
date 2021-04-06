class CfgMessages {
	length = 256;

	class Message {
		picture = "\a3\3den\data\Cfg3DEN\Comment\texture_ca.paa";
		displayName = "Private Message";
		sendTo[] = { "Police", "Medic", "Civilian" };
		ignoreStreamer = false;
		ignoreComms = false; // TODO
		canReply = true;
		sender = "%1";
		targets = "";
		condition = "true"; // TODO
	};

	class Reply : Message {
		displayName = "Reply";
		condition = "false";
	};

	class PoliceDispatch : Message {
		picture = "Data\UI\Messaging\999.paa";
		displayName = "Police Dispatch";
		targets = "[""Police""] call ULP_fnc_allMembers";
	};

	class NHSDispatch : PoliceDispatch {
		displayName = "NHS Dispatch";
		targets = "[""Medic""] call ULP_fnc_allMembers";
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

	class Dispute : Message {
		picture = "Data\UI\dispute.paa";
		displayName = "Dispute";
		ignoreStreamer = true;
		ignoreComms = true;
		condition = "false";
	};
};