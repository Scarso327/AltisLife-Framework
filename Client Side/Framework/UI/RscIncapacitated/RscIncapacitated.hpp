class RscIncapacitated {
	idd = 9000;
	name = "RscIncapacitated";
	duration = 10e10;
	movingEnable = 0;
	fadein = 0;
	fadeout = 0;
  	onLoad="uiNamespace setVariable ['RscIncapacitated', _this select 0]";
  	objects[]={};

     class Controls {
		 class Background : Life_RscBackground {
            idc = -1;
            colorBackground[] = {0.16,0.16,0.16,0.8};
            x = 0 * safezoneW + safezoneX;
            y = 0.665 * safezoneH + safezoneY;
            w = 1 * safezoneW;
            h = 0.154 * safezoneH;
        };

        class TitleText : Life_RscStructuredText {
            idc = 9001;
            text = "<t align='center' size='2'>#######</t>";
            x = 0.29375 * safezoneW + safezoneX;
            y = 0.676 * safezoneH + safezoneY;
            w = 0.4125 * safezoneW;
            h = 0.044 * safezoneH;
        };

        class SubText : Life_RscStructuredText {
            idc = 9002;
            text = "<t align='left' size='1'>Waiting to respawn...</t><t align='right' size='1'>Nearest Medic: ##m</t>";
            x = 0.376251 * safezoneW + safezoneX;
            y = 0.764 * safezoneH + safezoneY;
            w = 0.2475 * safezoneW;
            h = 0.022 * safezoneH;
        };

		class ProgressBackground : Life_RscText {
            idc = -1;
            colorBackground[] = {0.16,0.16,0.16,0.7};
            x = 0.376251 * safezoneW + safezoneX;
            y = 0.731 * safezoneH + safezoneY;
            w = 0.2475 * safezoneW;
            h = 0.022 * safezoneH;
        };

        class ProgressBar : Life_RscProgress {
            idc = 9004;
            colorBar[] = {0.75, 0, 0, 0.9};
            x = 0.376251 * safezoneW + safezoneX;
            y = 0.731 * safezoneH + safezoneY;
            w = 0.2475 * safezoneW;
            h = 0.022 * safezoneH;
        };

        class ProgressText : Life_RscStructuredText {
            idc = 9003;
            text = "<t align='center' size='1'>Bleeding out...</t>";
            x = 0.376251 * safezoneW + safezoneX;
            y = 0.729 * safezoneH + safezoneY;
            w = 0.2475 * safezoneW;
            h = 0.022 * safezoneH;
        };

        class RequestMedic : Life_RscStructuredText {
            idc = 9005;
            text = "<t align='center' size='1'>Press <t color='#8A2BE2'>Space</t> to request a medic</t>";
            x = 0.29375 * safezoneW + safezoneX;
            y = 0.792 * safezoneH + safezoneY;
            w = 0.4125 * safezoneW;
            h = 0.044 * safezoneH;
        };
    };
};