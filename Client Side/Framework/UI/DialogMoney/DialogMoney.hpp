#define UI_WIDTH 0.275
#define UI_X 0.5 - (UI_WIDTH / 2)
#define BODY_HEIGHT 0.400
#define BODY_Y 0.5 - (BODY_HEIGHT / 2)

class DialogMoney {
    idd = 4100;
    movingEnable = 0;
    enableSimulation = 0;
	onUnload = "[""TransactionsUpdated"", ((_this select 0) getVariable [""trans_event"", -1])] call ULP_fnc_removeEventHandler; [""MoneyChanged"", ((_this select 0) getVariable [""money_event"", -1])] call ULP_fnc_removeEventHandler; [""GroupMoneyChanged"", ((_this select 0) getVariable [""gang_event"", -1])] call ULP_fnc_removeEventHandler;";

    class ControlsBackground {
		class Header : Life_RscText {
			idc = -1;
			colorBackground[] = HEADER_COLOUR;
			text = "Bank";
			SAFEZONE_X(UI_X);
			SAFEZONE_Y(BODY_Y - 0.022);
			SAFEZONE_W(UI_WIDTH);
			SAFEZONE_H(0.022);
		};

		class Body : Life_RscText {
			idc = -1;
			colorBackground[] = BODY_COLOUR;
			SAFEZONE_X(UI_X);
			SAFEZONE_Y(BODY_Y);
			SAFEZONE_W(UI_WIDTH);
			SAFEZONE_H(BODY_HEIGHT);
		};

		class ListBackground : Life_RscText {
			idc = -1;
			colorBackground[] = INNER_BODY_COLOUR;
			text = "";
			SAFEZONE_X(UI_X + MARGIN_X);
			SAFEZONE_Y((BODY_Y + 0.022) + MARGIN_Y);
			SAFEZONE_W(UI_WIDTH - (MARGIN_X * 2));
			SAFEZONE_H((BODY_HEIGHT - (0.022 * 3))- (MARGIN_Y * 5));
		};

		class Footer : Life_RscText {
			idc = -1;
			colorBackground[] = FOOTER_COLOUR;
			SAFEZONE_X(UI_X);
			SAFEZONE_Y((BODY_Y + BODY_HEIGHT));
			SAFEZONE_W(UI_WIDTH);
			SAFEZONE_H(0.033);
		};
	};

	class Controls {

		class TypeSwitch : Life_RscToolbox {
			idc = 4101;
			style = 2;
			onToolboxSelChanged = "_this call ULP_fnc_switchBank;";
			colorBackground[] = NO_COLOUR;
			colorSelectedBg[] = INNER_BODY_COLOUR;
			SAFEZONE_X(UI_X + MARGIN_X);
			SAFEZONE_Y((BODY_Y + BODY_HEIGHT) - (0.022 * 3) - MARGIN_Y);
			SAFEZONE_W(UI_WIDTH - (MARGIN_X * 2));
			SAFEZONE_H(0.022);
			columns = 2;
			fade = 0;
			strings[] = {
				"Personal",
				"Group"
			};
			tooltips[] = {
				"Personal",
				"Group"
			};
		};

		class Personal : Life_RscStructuredText {
			idc = 4102;
			text = "<t align='left'>£1,000,000</t><t align='right'>1.5%</t><br/><t size='0.9'>Balance<t align='right'>Tax</t></t>";
			colorBackground[] = INNER_BODY_COLOUR;
			SAFEZONE_X(UI_X + MARGIN_X);
			SAFEZONE_Y((BODY_Y + BODY_HEIGHT) - (0.022 * 2) - MARGIN_Y);
			SAFEZONE_W(UI_WIDTH - (MARGIN_X * 2));
			SAFEZONE_H((0.022 * 2));
		};

		class TransactionHeaderBackground : Life_RscText {
			idc = 4103;
			colorBackground[] = { 0, 0, 0, 1 };
			text = "";
			SAFEZONE_X(UI_X + MARGIN_X);
			SAFEZONE_Y(BODY_Y + MARGIN_Y);
			SAFEZONE_W(UI_WIDTH - (MARGIN_X * 2));
			SAFEZONE_H(0.022);
		};

		class TransactionListHeader: Life_RscListNBox {
			idc = 4104;
			SAFEZONE_X(UI_X + MARGIN_X);
			SAFEZONE_Y(BODY_Y + MARGIN_Y);
			SAFEZONE_W(UI_WIDTH - (MARGIN_X * 2));
			SAFEZONE_H(0.022);
			text = "";	
			rowHeight = 0.04;
			sizeEx = 0.038;
			columns[] = { 0, 0.5, 0.75 };
			drawSideArrows = false;
			idcLeft = -1;
			idcRight = -1;
			disableOverflow = 1;

			class Items {
				class DisplayName {
					text = "Transaction";
					value = 1;
                    data = "data";
				};
				class Weight {
					text = "In";
					value = -1;
					data = "data";
				};
				class Legal {
					text = "Out";
					value = -1;
					data = "data";
				};
			};
		};

		class TransactionList : Life_RscListNBox {
			idc = 4105;
			SAFEZONE_X(UI_X + MARGIN_X);
			SAFEZONE_Y((BODY_Y + 0.022) + MARGIN_Y);
			SAFEZONE_W(UI_WIDTH - (MARGIN_X * 2));
			SAFEZONE_H((BODY_HEIGHT - (0.022 * 3))- (MARGIN_Y * 5));
			text = "";	
			rowHeight = 0.04;
			sizeEx = 0.038;
			columns[] = { 0, 0.5, 0.75 };
			drawSideArrows = false;
			idcLeft = -1;
			idcRight = -1;
		};

		class Withdraw : Life_RscButtonCenter {
			idc = 4106;
			text = "<t align = 'center'>Withdraw</t>";
			onButtonClick = "_this call ULP_fnc_withdrawMoney";
			SAFEZONE_X((UI_X + UI_WIDTH - (UI_WIDTH / 4)) - MARGIN_X);
			SAFEZONE_Y((BODY_Y + BODY_HEIGHT) + BUTTON_MARGIN_Y);
			SAFEZONE_W((UI_WIDTH / 4));
			SAFEZONE_H(0.022);
		};

		class Deposit : Life_RscButtonCenter {
			idc = 4107;
			text = "<t align = 'center'>Deposit</t>";
			onButtonClick = "_this call ULP_fnc_depositMoney";
			SAFEZONE_X((UI_X + UI_WIDTH - ((UI_WIDTH / 4) * 2)) - (MARGIN_X * 2));
			SAFEZONE_Y((BODY_Y + BODY_HEIGHT) + BUTTON_MARGIN_Y);
			SAFEZONE_W((UI_WIDTH / 4));
			SAFEZONE_H(0.022);
		};

		class Transfer : Life_RscButtonCenter {
			idc = 4108;
			text = "<t align = 'center'>Transfer</t>";
			onButtonClick = "[(findDisplay getNumber(configFile >> ""RscDisplayMission"" >> ""idd"")), [""Police"", ""Medic"", ""Hato"", ""Civilian"", ""Dunamis""], [], { _this params [[""_display"", displayNull, [displayNull]]]; if (isNull _display) exitWith {}; private _list = _display displayCtrl 3809; private _unit = (_list tvData (tvCurSel _list)) call BIS_fnc_objectFromNetId; if (isNull _unit) exitWith { [""You didn't select anyone to transfer to!""] call ULP_fnc_hint; }; [0.01, [_unit], { [_this select 0, true] call ULP_fnc_giveMoney }] call ULP_fnc_waitExecute; }, false, false] call ULP_fnc_selectPlayer;";
			SAFEZONE_X((UI_X + UI_WIDTH - ((UI_WIDTH / 4) * 3)) - (MARGIN_X * 3));
			SAFEZONE_Y((BODY_Y + BODY_HEIGHT) + BUTTON_MARGIN_Y);
			SAFEZONE_W((UI_WIDTH / 4));
			SAFEZONE_H(0.022);
		};
	};
};