class RscPvpScoreboard {
    idd = 6400;
    onLoad = "_this call ULP_UI_fnc_RscPvpScoreboard_OnLoad";
	onUnload = "_this call ULP_UI_fnc_RscPvpScoreboard_OnUnload";
    fadein=0;
    fadeout=0;
    duration = 10e10;

    class controlsBackground {
        SAFEZONE_X((1 - 0.12375012375) - MARGIN_X);
        SAFEZONE_Y(((1 - (BUTTON_H * 6)) - MARGIN_Y) - MARGIN_Y);
        SAFEZONE_W(0.12375012375);
        SAFEZONE_H(BUTTON_H * 2);

        class ScoreboardHeader : Life_RscStructuredText {
            idc = 6402;
            text = "<t align='left' size='1'>Scoreboard</t><t align='right' size='1'>Points in 00:00</t>";
            colorBackground[] = { 0.06, 0.06, 0.06, 0.85 };
			SAFEZONE_X(MARGIN_X);
            SAFEZONE_Y(0.2);
            SAFEZONE_W(0.12375012375);
            SAFEZONE_H(BUTTON_H);
        };

        class ScoreboardList : Life_RscListBox {
			idc = 6401;
			colorBackground[] = {0.1,0.1,0.1,0.85};
			SAFEZONE_X(MARGIN_X);
            SAFEZONE_Y(0.2 + BUTTON_H);
            SAFEZONE_W(0.12375012375);
            SAFEZONE_H(BUTTON_H * 9);
		};
    };
};