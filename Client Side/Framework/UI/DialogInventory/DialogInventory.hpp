#define UI_WIDTH 0.325
#define UI_X 0.5 - (UI_WIDTH / 2)
#define BODY_HEIGHT 0.400
#define BODY_Y 0.5 - (BODY_HEIGHT / 2)

#define BODY_CONTENT_Y (BODY_Y + MARGIN_Y)
#define BODY_CONTENT_LIST_Y (BODY_CONTENT_Y + MARGIN_Y + BUTTON_H)

class DialogInventory {
    idd = 4200;
    movingEnable = 0;
    enableSimulation = 0;
	onUnload = "[""RegisteredAsUser"", ((_this select 0) getVariable [""userRegisterEvent"", -1])] call ULP_fnc_removeEventHandler; [((_this select 0) getVariable [""eachframe"", -1])] call ULP_fnc_removeEachFrame; [((_this select 0) getVariable [""container"", objNull]), player] remoteExecCall [""ULP_SRV_fnc_unregisterCargoUser"", 2]; [true] call ULP_fnc_saveGear;";

    class ControlsBackground {
		class Header : Life_RscStructuredText {
			idc = 4201;
			colorBackground[] = HEADER_COLOUR;
			text = "Container Inventory";
			SAFEZONE_X(UI_X);
			SAFEZONE_Y(BODY_Y - BUTTON_H);
			SAFEZONE_W(UI_WIDTH);
			SAFEZONE_H(BUTTON_H);
		};

		class Body : Life_RscText {
			idc = -1;
			colorBackground[] = BODY_COLOUR;
			SAFEZONE_X(UI_X);
			SAFEZONE_Y(BODY_Y);
			SAFEZONE_W(UI_WIDTH);
			SAFEZONE_H(BODY_HEIGHT);
		};

		class PersonalListBackground : Life_RscText {
			idc = -1;
			colorBackground[] = INNER_BODY_COLOUR;
			text = "";
			SAFEZONE_X(UI_X + MARGIN_X);
			SAFEZONE_Y(BODY_CONTENT_LIST_Y);
			SAFEZONE_W((((UI_WIDTH - (MARGIN_X * 2)) / 2) - (MARGIN_X / 2)));
			SAFEZONE_H(BODY_HEIGHT - (MARGIN_Y * 3) - BUTTON_H);
		};

		class PersonalHeaderBackground : Life_RscText {
			idc = -1;
			colorBackground[] = { 0, 0, 0, 1 };
			text = "";
			SAFEZONE_X(UI_X + MARGIN_X);
			SAFEZONE_Y(BODY_CONTENT_LIST_Y);
			SAFEZONE_W((((UI_WIDTH - (MARGIN_X * 2)) / 2) - (MARGIN_X / 2)));
			SAFEZONE_H(0.044);
		};

		class ContainerListBackground : Life_RscText {
			idc = -1;
			colorBackground[] = INNER_BODY_COLOUR;
			text = "";
			SAFEZONE_X((UI_X + (((UI_WIDTH / 2) - (MARGIN_X / 2)) - MARGIN_X)) + (MARGIN_X * 2));
			SAFEZONE_Y(BODY_CONTENT_LIST_Y);
			SAFEZONE_W((((UI_WIDTH - (MARGIN_X * 2)) / 2) - (MARGIN_X / 2)));
			SAFEZONE_H(BODY_HEIGHT - (MARGIN_Y * 3) - BUTTON_H);
		};

		class ContainerHeaderBackground : Life_RscText {
			idc = -1;
			colorBackground[] = { 0, 0, 0, 1 };
			text = "";
			SAFEZONE_X((UI_X + (((UI_WIDTH / 2) - (MARGIN_X / 2)) - MARGIN_X)) + (MARGIN_X * 2));
			SAFEZONE_Y(BODY_CONTENT_LIST_Y);
			SAFEZONE_W((((UI_WIDTH - (MARGIN_X * 2)) / 2) - (MARGIN_X / 2)));
			SAFEZONE_H(0.044);
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

		class PersonalSearch : life_RscEdit {
			style = "0x10";
			idc = 4210;
			text = "";
			onKeyUp = "[ctrlParent (_this select 0), 0] call ULP_fnc_updateInventory;";
			colorDisabled[] = {0.95, 0.95, 0.95, 1};
			SAFEZONE_X(UI_X + MARGIN_X);
			SAFEZONE_Y(BODY_CONTENT_Y);
			SAFEZONE_W((((UI_WIDTH - (MARGIN_X * 2)) / 2) - (MARGIN_X / 2)));
			SAFEZONE_H(BUTTON_H);
		};

		class Personal : Life_RscStructuredText {
			idc = 4202;
			text = "Personal Inventory<t align='right'>0/0</t>";
			SAFEZONE_X(UI_X + MARGIN_X);
			SAFEZONE_Y(BODY_CONTENT_LIST_Y);
			SAFEZONE_W((((UI_WIDTH - (MARGIN_X * 2)) / 2) - (MARGIN_X / 2)));
			SAFEZONE_H(BUTTON_H);
		};

		class PersonalListHeader: Life_RscListNBox {
			idc = 4203;
			SAFEZONE_X(UI_X + MARGIN_X);
			SAFEZONE_Y(BODY_CONTENT_LIST_Y + BUTTON_H);
			SAFEZONE_W((((UI_WIDTH - (MARGIN_X * 2)) / 2) - (MARGIN_X / 2)));
			SAFEZONE_H(BUTTON_H);
			text = "";	
			rowHeight = 0.04;
			sizeEx = 0.038;
			columns[] = { 0, 0.6 };
			drawSideArrows = false;
			idcLeft = -1;
			idcRight = -1;
			disableOverflow = 1;

			class Items {
				class DisplayName {
					text = "Item";
					value = 0;
				};
				class Count {
					text = "Total";
					value = -1;
					data = "data";
				};
			};
		};

		class PersonalList : Life_RscListNBox {
			idc = 4204;
			SAFEZONE_X(UI_X + MARGIN_X);
			SAFEZONE_Y(BODY_CONTENT_LIST_Y + (BUTTON_H * 2));
			SAFEZONE_W((((UI_WIDTH - (MARGIN_X * 2)) / 2) - (MARGIN_X / 2)));
			SAFEZONE_H((BODY_HEIGHT - (MARGIN_Y * 3)) - (BUTTON_H * 4));
			text = "";	
			rowHeight = 0.04;
			sizeEx = 0.038;
			columns[] = { 0, 0.6 };
			drawSideArrows = false;
			idcLeft = -1;
			idcRight = -1;
		};

		class ToInventory : ULP_RscButtonIconNoAnim {
			idc = 4205;
			text = "\A3\Ui_f\data\GUI\RscCommon\RscHTML\arrow_right_ca.paa";
			tooltip = "Transfer to container";
			colorBackground[] = {0,0,0,1};
            colorFocused[] = {0.09,0.09,0.09,1};
            colorBackgroundActive[] = {0.03,0.03,0.03,1};
			colorBackgroundDisabled[] = {0,0,0,0};
			onButtonClick = "_this call ULP_fnc_putInCargo;";
			SAFEZONE_X(UI_X + MARGIN_X);
			SAFEZONE_Y((BODY_Y + (BODY_HEIGHT - BUTTON_H)) - MARGIN_Y);
			SAFEZONE_W((((UI_WIDTH - (MARGIN_X * 2)) / 2) - (MARGIN_X / 2)));
			SAFEZONE_H(BUTTON_H);
		};

		#define CONTAINER_X ((UI_X + (((UI_WIDTH / 2) - (MARGIN_X / 2)) - MARGIN_X)) + (MARGIN_X * 2))

		class ContainerSearch : PersonalSearch {
			idc = 4211;
			onKeyUp = "[ctrlParent (_this select 0), 1] call ULP_fnc_updateInventory;";
			SAFEZONE_X(CONTAINER_X);
		};

		class Container : Personal {
			idc = 4206;
			text = "Container Inventory<t align='right'>0/0</t>";
			SAFEZONE_X(CONTAINER_X);
		};

		class ContainerListHeader: PersonalListHeader {
			idc = 4207;
			SAFEZONE_X(CONTAINER_X);
		};

		class ContainerList : PersonalList {
			idc = 4208;
			SAFEZONE_X(CONTAINER_X);
		};

		class ToPersonal : ToInventory {
			idc = 4209;
			text = "\A3\Ui_f\data\GUI\RscCommon\RscHTML\arrow_left_ca.paa";
			tooltip = "Transfer to self";
			onButtonClick = "_this call ULP_fnc_takeFromCargo;";
			SAFEZONE_X(CONTAINER_X);
		};
	};
};