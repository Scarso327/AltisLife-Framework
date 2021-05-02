#define UI_WIDTH 0.3
#define UI_X 0.5 - (UI_WIDTH / 2)
#define BODY_HEIGHT 0.400
#define BODY_Y 0.5 - (BODY_HEIGHT / 2)
#define BUTTON_W HORIZONTAL_GRID_W(0.149531, 4)

class DialogMedical {
    idd = 4900;
    movingEnable = 0;
    enableSimulation = 0;

    class ControlsBackground {
		class Header : Life_RscStructuredText {
			idc = -1;
			colorBackground[] = HEADER_COLOUR;
			text = "Patient Vitals";
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

		class BackgroundBody: Life_RscPicture {
			idc = -1;
			style = ST_PICTURE + ST_CENTER;
			text = "data\ui\medical\body.paa";
			x = safeZoneX + safeZoneW * 0.355625;
			y = safeZoneY + safeZoneH * 0.313;
			w = safeZoneW * 0.134062;
			h = safeZoneH * 0.374;
		};

		class PartListHeaderBackground : Life_RscText {
			idc = -1;
			colorBackground[] = { 0, 0, 0, 1 };
			SAFEZONE_X(0.494844);
			SAFEZONE_Y(0.335);
			SAFEZONE_W(0.149531);
			SAFEZONE_H(0.022);
		};

		class PartListBackground : Life_RscText {
			idc = -1;
			colorBackground[] = INNER_BODY_COLOUR;
			SAFEZONE_X(0.494844);
			SAFEZONE_Y(0.357);
			SAFEZONE_W(0.149531);
			SAFEZONE_H((0.33 - BUTTON_W) - MARGIN_Y);
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

		class Head: Life_RscActiveText {
			idc = 4901;
			style = ST_PICTURE + ST_CENTER;
			text = "data\ui\medical\head.paa";
			onButtonClick = "[_this select 0, ""Head""] call ULP_fnc_setLimb";
			x = safeZoneX + safeZoneW * 0.402031;
			y = safeZoneY + safeZoneH * 0.335;
			w = safeZoneW * 0.04125;
			h = safeZoneH * 0.055;
		};

		class RArm: Life_RscActiveText {
			idc = 4902;
			style = ST_PICTURE;
			text = "data\ui\medical\rarm.paa";
			onButtonClick = "[_this select 0, ""RArm""] call ULP_fnc_setLimb";
			x = 0.365938 * safeZoneW + safeZoneX;
			y = safeZoneY + safeZoneH * 0.39;
			w = safeZoneW * 0.0515625;
			h = safeZoneH * 0.132;
		};
		
		class LArm: Life_RscActiveText {
			idc = 4903;
			style = ST_PICTURE;
			text = "data\ui\medical\larm.paa";
			onButtonClick = "[_this select 0, ""LArm""] call ULP_fnc_setLimb";
			x = safeZoneX + safeZoneW * 0.427812;
			y = safeZoneY + safeZoneH * 0.39;
			w = safeZoneW * 0.0515625;
			h = safeZoneH * 0.132;
		};

		class Body: Life_RscActiveText {
			idc = 4904;
			style = ST_PICTURE + ST_CENTER;
			text = "data\ui\medical\torso.paa";
			onButtonClick = "[_this select 0, ""Body""] call ULP_fnc_setLimb";
			x = safeZoneX + safeZoneW * 0.402031;
			y = safeZoneY + safeZoneH * 0.39;
			w = safeZoneW * 0.04125;
			h = safeZoneH * 0.11;
		};

		class RLegs: Life_RscActiveText {
			idc = 4905;
			style = ST_PICTURE;
			text = "data\ui\medical\rleg.paa";
			onButtonClick = "[_this select 0, ""RLeg""] call ULP_fnc_setLimb";
			x = safeZoneX + safeZoneW * 0.391719;
			y = safeZoneY + safeZoneH * 0.478;
			w = safeZoneW * 0.0309375;
			h = safeZoneH * 0.187;
		};
		
		class LLegs: Life_RscActiveText {
			idc = 4906;
			style = ST_PICTURE;
			text = "data\ui\medical\lleg.paa";
			onButtonClick = "[_this select 0, ""LLeg""] call ULP_fnc_setLimb";
			x = safeZoneX + safeZoneW * 0.422656;
			y = safeZoneY + safeZoneH * 0.478;
			w = safeZoneW * 0.0309375;
			h = safeZoneH * 0.187;
		};

		class PartHeader : Life_RscStructuredText {
			idc = 4907;
			text = "Limb's Status";
			colorBackground[] = { 0, 0, 0, 1 };
			SAFEZONE_X(0.494844);
			SAFEZONE_Y(0.313);
			SAFEZONE_W(0.149531);
			SAFEZONE_H(0.022);
		};


		class PartListHeader: Life_RscListNBox {
			idc = 4908;
			SAFEZONE_X(0.494844);
			SAFEZONE_Y(0.335);
			SAFEZONE_W(0.149531);
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
				class DisplayName {
					text = "Injury";
					value = 0;
				};
				class Count {
					text = "Count";
					value = 0;
				};
			};
		};

		class PartList : Life_RscListNBox {
			idc = 4909;
			SAFEZONE_X(0.494844);
			SAFEZONE_Y(0.357);
			SAFEZONE_W(0.149531);
			SAFEZONE_H((0.33 - BUTTON_W) - MARGIN_Y);
			text = "";	
			rowHeight = 0.04;
			sizeEx = 0.038;
			columns[] = { 0, 0.6 };
			drawSideArrows = false;
			idcLeft = -1;
			idcRight = -1;
		};

		class FieldDressing : Life_RscActiveText {
			idc = 4910;
			style = ST_KEEP_ASPECT_RATIO  + ST_CENTER + ST_PICTURE;
			text = "Data\Icons\FieldDressing.paa";
			tooltip = "Apply Field Dressing";
			onButtonClick = "[_this select 0, ""FieldDressing""] call ULP_fnc_applyBandage";
			SAFEZONE_X(HORIZONTAL_GRID_X(0.494844, BUTTON_W, 0));
			SAFEZONE_Y(0.687 - BUTTON_W);
			SAFEZONE_W(BUTTON_W);
			SAFEZONE_H(BUTTON_W);
		};

		class Packing : FieldDressing {
			idc = 4911;
			text = "Data\Icons\packingBandage.paa";
			tooltip = "Apply Packing Bandage";
			onButtonClick = "[_this select 0, ""Packing""] call ULP_fnc_applyBandage";
			SAFEZONE_X(HORIZONTAL_GRID_X(0.494844, BUTTON_W, 1));
		};

		class QuickClot : FieldDressing {
			idc = 4912;
			text = "Data\Icons\quikClot.paa";
			tooltip = "Apply QuikClot";
			onButtonClick = "[_this select 0, ""QuickClot""] call ULP_fnc_applyBandage";
			SAFEZONE_X(HORIZONTAL_GRID_X(0.494844, BUTTON_W, 2));
		};

		class Elastic : FieldDressing {
			idc = 4913;
			text = "Data\Icons\elasticBandage.paa";
			tooltip = "Apply Elastic Bandage";
			onButtonClick = "[_this select 0, ""Elastic""] call ULP_fnc_applyBandage";
			SAFEZONE_X(HORIZONTAL_GRID_X(0.494844, BUTTON_W, 3));
		};

		class Revive : Life_RscButtonCenter {
			idc = 4914;
			text = "<t align = 'center'>Revive</t>";
			onButtonClick = "_this call ULP_fnc_revivePatient";
			SAFEZONE_X((UI_X + UI_WIDTH - (UI_WIDTH / 4)) - MARGIN_X);
			SAFEZONE_Y((BODY_Y + BODY_HEIGHT) + BUTTON_MARGIN_Y);
			SAFEZONE_W((UI_WIDTH / 4));
			SAFEZONE_H(0.022);
		};
	};
};