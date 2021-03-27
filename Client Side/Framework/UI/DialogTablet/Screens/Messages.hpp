class MessageToolbox : Life_RscToolbox {
	idc = 23036;
	style = 2;
	onToolboxSelChanged = "(ctrlParent (_this select 0)) call ULP_fnc_messages;";
	colorBackground[] = NO_COLOUR;
	colorSelectedBg[] = INNER_BODY_COLOUR;
	SAFEZONE_X(UI_X);
	SAFEZONE_Y(UI_Y);
	SAFEZONE_W(((UI_WIDTH - (MARGIN_X / 2)) * 0.5) - (MARGIN_X / 2));
	SAFEZONE_H(MARGIN_Y * 3);
	columns = 2;
	fade = 0;
	strings[] = {
		"Contacts",
		"Inbox"
	};
	tooltips[] = {
		"Contacts",
		"Inbox"
	};
};

class MessageBackground: Life_RscText {
    idc = 23044;
	text = "";
	colorBackground[] = INNER_BODY_COLOUR;
    SAFEZONE_X(UI_X);
	SAFEZONE_Y(UI_Y + (MARGIN_Y * 3));
	SAFEZONE_W(((UI_WIDTH - (MARGIN_X / 2)) * 0.7) - (MARGIN_X / 2));
	SAFEZONE_H(UI_HEIGHT - (MARGIN_Y * 3));
};

class ReplyBackground: Life_RscText {
    idc = 23045;
	text = "";
	colorBackground[] = INNER_BODY_COLOUR;
    SAFEZONE_X(UI_X);
	SAFEZONE_Y((UI_Y + (MARGIN_Y * 3)) + (((UI_HEIGHT - (MARGIN_Y * 3)) * 0.7) + (MARGIN_Y / 2)));
	SAFEZONE_W(((UI_WIDTH - (MARGIN_X / 2)) * 0.5) - (MARGIN_X / 2));
	SAFEZONE_H(((UI_HEIGHT - (MARGIN_Y * 3)) * 0.3) - (MARGIN_Y / 2));
};

class ReplyPlaceholder : Life_RscText {
	style = "0x10";
    idc = 23042;
	text = "Type your reply here...";
	colorText[] = {1, 1, 1, 0.4};
    SAFEZONE_X(UI_X);
	SAFEZONE_Y((UI_Y + (MARGIN_Y * 3)) + (((UI_HEIGHT - (MARGIN_Y * 3)) * 0.7) + (MARGIN_Y / 2)));
	SAFEZONE_W(((UI_WIDTH - (MARGIN_X / 2)) * 0.5) - (MARGIN_X / 2));
	SAFEZONE_H(((UI_HEIGHT - (MARGIN_Y * 3)) * 0.3) - (MARGIN_Y / 2));
};

class MessagePlaceholder : ReplyPlaceholder {
    idc = 23043;
	text = "Type your message here...";
    SAFEZONE_X(UI_X);
	SAFEZONE_Y(UI_Y + (MARGIN_Y * 3));
	SAFEZONE_W(((UI_WIDTH - (MARGIN_X / 2)) * 0.7) - (MARGIN_X / 2));
	SAFEZONE_H(UI_HEIGHT - (MARGIN_Y * 3));
};

class MessageEdit: Life_RscEdit {
	style = "0x10 + 0x200";
    idc = 23037;
	text = "";
	colorFrame[] = {0,0,0,0};
	colorBackground[] = {0, 0, 0, 0};
    SAFEZONE_X(UI_X);
	SAFEZONE_Y(UI_Y + (MARGIN_Y * 3));
	SAFEZONE_W(((UI_WIDTH - (MARGIN_X / 2)) * 0.7) - (MARGIN_X / 2));
	SAFEZONE_H(UI_HEIGHT - (MARGIN_Y * 3));
};

class ContactsList: Life_RscListBox {
    idc = 23038;
	colorBackground[] = INNER_BODY_COLOUR;
	rowHeight = 0.075;
    sizeEx = 0.03;
    SAFEZONE_X(UI_X + (((UI_WIDTH - (MARGIN_X / 2)) * 0.7) + MARGIN_X));
	SAFEZONE_Y(UI_Y + (MARGIN_Y * 3));
	SAFEZONE_W(((UI_WIDTH - (MARGIN_X / 2)) * 0.3) - (MARGIN_X / 2));
	SAFEZONE_H((UI_HEIGHT - (MARGIN_Y * 3)) - (MARGIN_Y * 2));
};

class SendMessage : ULP_RscButtonClean {
	idc = 23039;
	text = "<t align = 'center'>Send Message</t>";
	SAFEZONE_X(UI_X + (((UI_WIDTH - (MARGIN_X / 2)) * 0.7) + MARGIN_X));
	SAFEZONE_Y((UI_Y + (MARGIN_Y * 3)) + (UI_HEIGHT - (MARGIN_Y * 3)) - (MARGIN_Y * 2));
	SAFEZONE_W(((UI_WIDTH - (MARGIN_X / 2)) * 0.3) - (MARGIN_X / 2));
	SAFEZONE_H(MARGIN_Y * 2);
};

class InboxMessage : Life_RscStructuredText {
	style = "0x10";
    idc = 23040;
	text = "";
	colorBackground[] = INNER_BODY_COLOUR;
    SAFEZONE_X(UI_X);
	SAFEZONE_Y(UI_Y + (MARGIN_Y * 3));
	SAFEZONE_W(((UI_WIDTH - (MARGIN_X / 2)) * 0.5) - (MARGIN_X / 2));
	SAFEZONE_H(((UI_HEIGHT - (MARGIN_Y * 3)) * 0.7) - (MARGIN_Y / 2));
};

class MessageReply : MessageEdit {
    idc = 23041;
	text = "";
    SAFEZONE_X(UI_X);
	SAFEZONE_Y((UI_Y + (MARGIN_Y * 3)) + (((UI_HEIGHT - (MARGIN_Y * 3)) * 0.7) + (MARGIN_Y / 2)));
	SAFEZONE_W(((UI_WIDTH - (MARGIN_X / 2)) * 0.5) - (MARGIN_X / 2));
	SAFEZONE_H(((UI_HEIGHT - (MARGIN_Y * 3)) * 0.3) - (MARGIN_Y / 2));
};

class InboxListHeaderBackground : Life_RscText {
	idc = 23047;
	colorBackground[] = { 0, 0, 0, 1 };
	text = "";
    SAFEZONE_X(UI_X + (((UI_WIDTH - (MARGIN_X / 2)) * 0.5) + MARGIN_X));
	SAFEZONE_Y(UI_Y + (MARGIN_Y * 3));
	SAFEZONE_W(((UI_WIDTH - (MARGIN_X / 2)) * 0.5) - (MARGIN_X / 2));
	SAFEZONE_H(0.022);
};

class InboxListHeader: Life_RscListNBox {
	idc = 23046;
    SAFEZONE_X(UI_X + (((UI_WIDTH - (MARGIN_X / 2)) * 0.5) + MARGIN_X));
	SAFEZONE_Y(UI_Y + (MARGIN_Y * 3));
	SAFEZONE_W(((UI_WIDTH - (MARGIN_X / 2)) * 0.5) - (MARGIN_X / 2));
	SAFEZONE_H(0.022);
	text = "";	
	rowHeight = 0.04;
	sizeEx = 0.038;
	columns[] = { 0, 0.4, 0.8 };
	drawSideArrows = false;
	idcLeft = -1;
	idcRight = -1;
	disableOverflow = 1;

	class Items {
		class Type {
			text = "Message Type";
			value = -1;
			data = "data";
		};
		class Sender {
			text = "Sender";
			value = -1;
			data = "data";
		};
		class Read {
			text = "Read";
			value = -1;
			data = "data";
		};
	};
};

class InboxListBackground : Life_RscText {
	idc = 23049;
	colorBackground[] = INNER_BODY_COLOUR;
	text = "";
    SAFEZONE_X(UI_X + (((UI_WIDTH - (MARGIN_X / 2)) * 0.5) + MARGIN_X));
	SAFEZONE_Y((UI_Y + (MARGIN_Y * 3)) + 0.022);
	SAFEZONE_W(((UI_WIDTH - (MARGIN_X / 2)) * 0.5) - (MARGIN_X / 2));
	SAFEZONE_H(((UI_HEIGHT - (MARGIN_Y * 3)) - 0.022) - (MARGIN_Y * 2));
};

class InboxList : Life_RscListNBox {
	idc = 23048;
    SAFEZONE_X(UI_X + (((UI_WIDTH - (MARGIN_X / 2)) * 0.5) + MARGIN_X));
	SAFEZONE_Y((UI_Y + (MARGIN_Y * 3)) + 0.022);
	SAFEZONE_W(((UI_WIDTH - (MARGIN_X / 2)) * 0.5) - (MARGIN_X / 2));
	SAFEZONE_H(((UI_HEIGHT - (MARGIN_Y * 3)) - 0.022) - (MARGIN_Y * 2));
	text = "";	
	onLBSelChanged = "_this call ULP_fnc_inbox;";
	rowHeight = 0.04;
	sizeEx = 0.038;
	columns[] = { 0, 0.4, 0.8 };
	drawSideArrows = false;
	idcLeft = -1;
	idcRight = -1;
};

class DeleteMessage : ULP_RscButtonClean {
	idc = 23050;
	text = "<t align = 'center'>Delete</t>";
	onButtonClick = "_this call ULP_fnc_deleteMessage;";
	SAFEZONE_X(UI_X + (((UI_WIDTH - (MARGIN_X / 2)) * 0.5) + MARGIN_X));
	SAFEZONE_Y((UI_Y + (MARGIN_Y * 3)) + (UI_HEIGHT - (MARGIN_Y * 3)) - (MARGIN_Y * 2));
	SAFEZONE_W(((UI_WIDTH - (MARGIN_X / 2)) * 0.2) - (MARGIN_X / 2));
	SAFEZONE_H(MARGIN_Y * 2);
};