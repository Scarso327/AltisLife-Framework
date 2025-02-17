class GroupPages : Life_RscToolbox {
	idc = 23061;
	style = 2;
	onToolboxSelChanged = "(ctrlParent (_this select 0)) call ULP_fnc_group;";
	colorBackground[] = NO_COLOUR;
	colorSelectedBg[] = INNER_BODY_COLOUR;
	SAFEZONE_X(UI_X);
	SAFEZONE_Y(UI_Y);
	SAFEZONE_W(((UI_WIDTH - 0.01) / 1.5) - (MARGIN_X / 2));
	SAFEZONE_H(MARGIN_Y * 3);
	columns = 4;
	fade = 0;
	strings[] = {
		"Overview",
		"Progression",
		"Alliances",
		"Settings"
	};
	tooltips[] = {
		"Overview",
		"Progression",
		"Alliances",
		"Settings"
	};
};

class GroupMemberBackground : Life_RscText {
	idc = 23065;
	colorBackground[] = INNER_BODY_COLOUR;
	text = "";
    SAFEZONE_X(UI_X);
	SAFEZONE_Y((UI_Y + 0.022) + (MARGIN_Y * 3));
	SAFEZONE_W(((UI_WIDTH - 0.01) / 2) - (MARGIN_X / 2));
	SAFEZONE_H((UI_HEIGHT - (0.022 * 3)) - (MARGIN_Y * 4));
};

class GroupMemberHeaderBackground : Life_RscText {
	idc = 23064;
	colorBackground[] = { 0, 0, 0, 1 };
	text = "";
	SAFEZONE_X(UI_X);
	SAFEZONE_Y(UI_Y + (MARGIN_Y * 3));
	SAFEZONE_W(((UI_WIDTH - 0.01) / 2) - (MARGIN_X / 2));
	SAFEZONE_H(0.022);
};

class GroupMemberListHeader: Life_RscListNBox {
	idc = 23063;
    SAFEZONE_X(UI_X);
	SAFEZONE_Y(UI_Y + (MARGIN_Y * 3));
	SAFEZONE_W(((UI_WIDTH - 0.01) / 2) - (MARGIN_X / 2));
	SAFEZONE_H(0.022);
	text = "";	
	rowHeight = 0.04;
	sizeEx = 0.038;
	columns[] = { 0, 0.6 };
	drawSideArrows = false;
	idcLeft = -1;
	idcRight = -1;
	disableOverflow = 1;

	class Items {
		class Member {
			text = "Member";
			value = 0;
		};
		class Rank {
			text = "Rank";
			value = -1;
			data = "data";
		};
	};
};

class GroupMemberList: Life_RscListNBox {
    idc = 23062;
	colorBackground[] = INNER_BODY_COLOUR;
	onLBSelChanged = "((ctrlParent (_this select 0)) displayCtrl 23068) lbSetCurSel ((_this select 0) lnbValue [(_this select 1), 1])";
    rowHeight = 0.09;
    sizeEx = 0.033;
    SAFEZONE_X(UI_X);
	SAFEZONE_Y((UI_Y + 0.022) + (MARGIN_Y * 3));
	SAFEZONE_W(((UI_WIDTH - 0.01) / 2) - (MARGIN_X / 2));
	SAFEZONE_H((UI_HEIGHT - (0.022 * 3)) - (MARGIN_Y * 4));
	columns[] = { 0, 0.6 };
	drawSideArrows = false;
	idcLeft = -1;
	idcRight = -1;
};

class GroupFunds : Life_RscStructuredText {
	idc = 23066;
	text = "<t align='left'>£1,000,000</t><t align='right'>1.5%</t><br/><t size='0.9'>Balance<t align='right'>Tax</t></t>";
	colorBackground[] = INNER_BODY_COLOUR;
	SAFEZONE_X(UI_X);
	SAFEZONE_Y((UI_Y + UI_HEIGHT) - (0.022 * 2));
	SAFEZONE_W(((UI_WIDTH - 0.01) / 2) - (MARGIN_X / 2));
	SAFEZONE_H((0.022 * 2));
};

class ChangeRank : ULP_RscButtonClean {
	idc = 23067;
	text = "<t align = 'center'>Change Rank</t>";
	onButtonClick = "_this call ULP_fnc_changeRank;";
	SAFEZONE_X((UI_X + ((UI_WIDTH - 0.01) / 2) - (MARGIN_X / 2)) + MARGIN_X);
	SAFEZONE_Y((UI_Y + 0.022) + (MARGIN_Y * 3));
	SAFEZONE_W((((UI_WIDTH - 0.01) / 2) - (MARGIN_X / 2)) / 2);
	SAFEZONE_H(0.022);
};

class GroupRankSelectList : Life_RscCombo {
	idc = 23068;
	onLBSelChanged = "";
	SAFEZONE_X((UI_X + ((UI_WIDTH - 0.01) / 2) - (MARGIN_X / 2)) + MARGIN_X);
	SAFEZONE_Y(UI_Y + (MARGIN_Y * 3));
	SAFEZONE_W((((UI_WIDTH - 0.01) / 2) - (MARGIN_X / 2)) / 2);
	SAFEZONE_H(0.022);
};

class TransferOwnership : ChangeRank {
	idc = 23079;
	text = "<t align = 'center'>Transfer Ownership</t>";
	onButtonClick = "_this call ULP_fnc_transferOwner;";
	SAFEZONE_Y((UI_Y + (0.022 * 2)) + (MARGIN_Y * 3) + ((MARGIN_Y / 2)));
};

class Kick : ChangeRank {
	idc = 23080;
	text = "<t align = 'center'>Kick</t>";
	onButtonClick = "_this call ULP_fnc_kickMember;";
	SAFEZONE_Y((UI_Y + (0.022 * 3)) + (MARGIN_Y * 3) + ((MARGIN_Y / 2) * 2));
};

class Invite : ChangeRank {
	idc = 23089;
	text = "<t align = 'center'>Invite</t>";
	onButtonClick = "_this call ULP_fnc_inviteMember;";
	SAFEZONE_Y((UI_Y + (0.022 * 4)) + (MARGIN_Y * 4) + ((MARGIN_Y / 2) * 3));
};

class LeaveGroup : ULP_RscButtonClean {
	idc = 23081;
	text = "<t align = 'center'>Leave Group</t>";
	onButtonClick = "[] call ULP_fnc_leaveGroup;";
	SAFEZONE_X((UI_X + UI_WIDTH) - ((((UI_WIDTH - 0.01) / 2) - (MARGIN_X / 2)) / 2));
	SAFEZONE_Y(UI_Y + (MARGIN_Y * 3));
	SAFEZONE_W((((UI_WIDTH - 0.01) / 2) - (MARGIN_X / 2)) / 2);
	SAFEZONE_H(0.022);
};

class DisbandGroup : LeaveGroup {
	idc = 23076;
	text = "<t align = 'center'>Disband Group</t>";
	onButtonClick = "[] call ULP_fnc_disbandGroup;";
	SAFEZONE_Y((UI_Y + 0.022) + (MARGIN_Y * 3) + (MARGIN_Y / 2));
};

class XPBarBackground : Life_RscText {
	idc = 23082;
	colorBackground[] = INNER_BODY_COLOUR;
	text = "";
	SAFEZONE_X(UI_X);
	SAFEZONE_Y(UI_Y + (MARGIN_Y * 3));
	SAFEZONE_W(UI_WIDTH);
	SAFEZONE_H(MARGIN_Y * 5);
};

class XPBar : Life_RscProgress {
	idc = 23083;
	colorBar[] = { 0.451, 0, 0.902, 1 };
	SAFEZONE_X(UI_X);
	SAFEZONE_Y(UI_Y + (MARGIN_Y * 3));
	SAFEZONE_W(UI_WIDTH);
	SAFEZONE_H(MARGIN_Y * 5);
};

class XPText: Life_RscStructuredText {
	idc = 23084;
	text = "";
	SAFEZONE_X(UI_X);
	SAFEZONE_Y(UI_Y + (MARGIN_Y * 3));
	SAFEZONE_W(UI_WIDTH);
	SAFEZONE_H(MARGIN_Y * 5);
};

class LeftView : Life_RscControlsGroup {
    idc = 23085;
	colorBackground[] = INNER_BODY_COLOUR;
    SAFEZONE_X(UI_X);
	SAFEZONE_Y(UI_Y + (MARGIN_Y * 8));
	SAFEZONE_W(((UI_WIDTH - 0.01) / 2) - (MARGIN_X / 2));
	SAFEZONE_H(UI_HEIGHT - (MARGIN_Y * 8));

    class Controls {};
};

class RightView : Life_RscControlsGroup {
    idc = 23086;
	colorBackground[] = INNER_BODY_COLOUR;
   	SAFEZONE_X((UI_X + ((UI_WIDTH - 0.01) / 2)) + (MARGIN_X * 2));
	SAFEZONE_Y(UI_Y + (MARGIN_Y * 8));
	SAFEZONE_W(((UI_WIDTH - 0.01) / 2) - (MARGIN_X / 2));
	SAFEZONE_H(UI_HEIGHT - (MARGIN_Y * 8));

    class Controls {};
};

class GroupTaxText : Life_RscStructuredText {
	idc = 23088;
	text = "Group Tax (5%)";
	SAFEZONE_X(UI_X);
	SAFEZONE_Y(UI_Y + (MARGIN_Y * 3));
	SAFEZONE_W((((UI_WIDTH - 0.01) / 2) - (MARGIN_X / 2)) / 2);
	SAFEZONE_H(0.022);
};

class ChangeTax : ULP_RscButtonClean {
	idc = 23087;
	text = "<t align = 'center'>Set Tax</t>";
	onButtonClick = "_this call ULP_fnc_changeTax;";
	SAFEZONE_X(UI_X);
	SAFEZONE_Y((UI_Y + 0.022) + (MARGIN_Y * 3));
	SAFEZONE_W((((UI_WIDTH - 0.01) / 2) - (MARGIN_X / 2)) / 2);
	SAFEZONE_H(0.022);
};

class PermissionChangeText : GroupTaxText {
	idc = 23094;
	text = "Permissions";
	SAFEZONE_Y((UI_Y + (0.022 * 2)) + (MARGIN_Y * 4));
};

class ChangeDepositRank : ChangeTax {
	idc = 23093;
	text = "<t align = 'center'>Set Deposit Rank</t>";
	onButtonClick = "[_this select 0, ""deposit""] call ULP_fnc_setRankPermission;";
	SAFEZONE_Y((UI_Y + (0.022 * 3)) + (MARGIN_Y * 4));
};

class ChangeWithdrawRank : ChangeTax {
	idc = 23095;
	text = "<t align = 'center'>Set Withdraw Rank</t>";
	onButtonClick = "[_this select 0, ""withdraw""] call ULP_fnc_setRankPermission;";
	SAFEZONE_Y((UI_Y + (0.022 * 4)) + (MARGIN_Y * 4) + ((MARGIN_Y / 2) * 1));
};

class ChangeInviteRank : ChangeTax {
	idc = 23096;
	text = "<t align = 'center'>Set Invite Rank</t>";
	onButtonClick = "[_this select 0, ""invite""] call ULP_fnc_setRankPermission;";
	SAFEZONE_Y((UI_Y + (0.022 * 5)) + (MARGIN_Y * 4) + ((MARGIN_Y / 2) * 2));
};

class ChangeKickRank : ChangeTax {
	idc = 23097;
	text = "<t align = 'center'>Set Kick Rank</t>";
	onButtonClick = "[_this select 0, ""kick""] call ULP_fnc_setRankPermission;";
	SAFEZONE_Y((UI_Y + (0.022 * 6)) + (MARGIN_Y * 4) + ((MARGIN_Y / 2) * 3));
};

class ChangeRankChangeRank : ChangeTax {
	idc = 23098;
	text = "<t align = 'center'>Set Promote Rank</t>";
	onButtonClick = "[_this select 0, ""rank""] call ULP_fnc_setRankPermission;";
	SAFEZONE_Y((UI_Y + (0.022 * 7)) + (MARGIN_Y * 4) + ((MARGIN_Y / 2) * 4));
};

class GroupAlliancesBackground : Life_RscText {
	idc = 23099;
	colorBackground[] = INNER_BODY_COLOUR;
	text = "";
    SAFEZONE_X(UI_X);
	SAFEZONE_Y((UI_Y + 0.022) + (MARGIN_Y * 3));
	SAFEZONE_W(UI_WIDTH);
	SAFEZONE_H((UI_HEIGHT - (0.022 * 2)) - (MARGIN_Y * 4));
};

class GroupAlliancesHeaderBackground : Life_RscText {
	idc = 23100;
	colorBackground[] = { 0, 0, 0, 1 };
	text = "";
    SAFEZONE_X(UI_X);
	SAFEZONE_Y(UI_Y + (MARGIN_Y * 3));
	SAFEZONE_W(UI_WIDTH);
	SAFEZONE_H(0.022);
};

class GroupAlliancesListHeader: Life_RscListNBox {
	idc = 23101;
    SAFEZONE_X(UI_X);
	SAFEZONE_Y(UI_Y + (MARGIN_Y * 3));
	SAFEZONE_W(UI_WIDTH);
	SAFEZONE_H(0.022);
	text = "";	
	rowHeight = 0.04;
	sizeEx = 0.038;
	columns[] = { 0 };
	drawSideArrows = false;
	idcLeft = -1;
	idcRight = -1;
	disableOverflow = 1;

	class Items {
		class Member {
			text = "Group Name";
			value = 0;
		};
	};
};

class GroupAlliancesList: Life_RscListNBox {
    idc = 23102;
	colorBackground[] = INNER_BODY_COLOUR;
	onLBSelChanged = "";
    rowHeight = 0.09;
    sizeEx = 0.033;
    SAFEZONE_X(UI_X);
	SAFEZONE_Y((UI_Y + 0.022) + (MARGIN_Y * 3));
	SAFEZONE_W(UI_WIDTH);
	SAFEZONE_H((UI_HEIGHT - (0.022 * 2)) - (MARGIN_Y * 4));
	columns[] = { 0 };
	drawSideArrows = false;
	idcLeft = -1;
	idcRight = -1;
};

class NewAllianceButton : ULP_RscButtonClean {
	idc = 23103;
	text = "<t align = 'center'>New Alliance</t>";
	onButtonClick = "_this call ULP_fnc_startGroupAlliance";
	SAFEZONE_X(UI_X);
	SAFEZONE_Y((UI_Y + (UI_HEIGHT - (0.022 * 3))) + (MARGIN_Y * 4));
	SAFEZONE_W((((UI_WIDTH - 0.01) / 2) - (MARGIN_X / 2)) / 2);
	SAFEZONE_H(0.022);
};

class EndAllianceButton : NewAllianceButton {
	idc = 23104;
	text = "<t align = 'center'>End Alliance</t>";
	onButtonClick = "_this call ULP_fnc_endGroupAlliance";
	SAFEZONE_X(UI_X + ((((UI_WIDTH - 0.01) / 2)) / 2));
};