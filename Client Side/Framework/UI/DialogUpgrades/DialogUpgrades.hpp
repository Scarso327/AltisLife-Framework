#define UI_WIDTH 0.35
#define UI_X 0.5 - (UI_WIDTH / 2)
#define BODY_HEIGHT 0.450
#define BODY_Y 0.5 - (BODY_HEIGHT / 2)

#define UPGRADE_LIST_W (UI_WIDTH * 0.4) - (MARGIN_X * 2)
#define MAIN_H BODY_HEIGHT - (MARGIN_Y * 2)

class DialogUpgrades {
    idd = 5700;
    movingEnable = 0;
    enableSimulation = 0;
    onInit = "_this call ULP_UI_fnc_DialogUpgrades_OnInit";
    onLoad = "_this call ULP_UI_fnc_DialogUpgrades_OnLoad";
	onUnload = "_this call ULP_UI_fnc_DialogUpgrades_OnUnload";

    class ControlsBackground {
		class Header : Life_RscStructuredText {
			idc = -1;
			colorBackground[] = HEADER_COLOUR;
			text = "Upgrades";
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
		class UpgradeList : Life_RscListBox {
			idc = 5701;
			colorBackground[] = INNER_BODY_COLOUR;
			onLBSelChanged = "_this call ULP_UI_fnc_DialogUpgrades_OnListChanged;";
			rowHeight = 0.04;
			sizeEx = 0.038;
			SAFEZONE_X(UI_X + MARGIN_X);
			SAFEZONE_Y(BODY_Y + MARGIN_Y);
			SAFEZONE_W(UPGRADE_LIST_W);
			SAFEZONE_H(MAIN_H);
		};

		class ItemsView : Life_RscControlsGroup {
			idc = -1;
			SAFEZONE_X(UI_X + (MARGIN_X * 2) + UPGRADE_LIST_W);
			SAFEZONE_Y(BODY_Y + MARGIN_Y);
			SAFEZONE_W(UI_WIDTH + MARGIN_X - UPGRADE_LIST_W);
			SAFEZONE_H(MAIN_H);

			class Controls {
				class ItemInformation : Life_RscStructuredText {
					idc = 5702;
					text = "";
					colorBackground[] = INNER_BODY_COLOUR;
					y = 0;
					x = 0;
					SAFEZONE_W(UI_WIDTH + MARGIN_X - UPGRADE_LIST_W);
					SAFEZONE_H(MAIN_H);
				};
			};
		};
		
		class ApplyButton : Life_RscButtonCenter {
			idc = 5703;
			text = "<t align = 'center'>Apply Upgrade</t>";
			onButtonClick = "_this call ULP_UI_fnc_DialogUpgrades_ApplyUpgrade;";
			SAFEZONE_X((UI_X + UI_WIDTH - (UI_WIDTH / 4)) - MARGIN_X);
			SAFEZONE_Y((BODY_Y + BODY_HEIGHT) + BUTTON_MARGIN_Y);
			SAFEZONE_W((UI_WIDTH / 4));
			SAFEZONE_H(0.022);
		};
	};
};