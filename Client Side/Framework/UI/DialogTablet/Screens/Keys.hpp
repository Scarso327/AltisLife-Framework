class KeyPages : Life_RscToolbox {
	idc = 23021;
	style = 2;
	onToolboxSelChanged = "(ctrlParent (_this select 0)) call ULP_fnc_keys;";
	colorBackground[] = NO_COLOUR;
	colorSelectedBg[] = INNER_BODY_COLOUR;
	SAFEZONE_X(UI_X);
	SAFEZONE_Y(UI_Y);
	SAFEZONE_W(((UI_WIDTH - 0.01) / 2) - (MARGIN_X / 2));
	SAFEZONE_H(MARGIN_Y * 3);
	columns = 2;
	fade = 0;
	strings[] = {
		"Vehicles",
		"Properties"
	};
	tooltips[] = {
		"Vehicles",
		"Properties"
	};
};

class KeyList: Life_RscListBox {
    idc = 23022;
	colorBackground[] = INNER_BODY_COLOUR;
    rowHeight = 0.09;
    sizeEx = 0.033;
    SAFEZONE_X(UI_X);
	SAFEZONE_Y(UI_Y + (MARGIN_Y * 3));
	SAFEZONE_W(((UI_WIDTH - 0.01) / 2) - (MARGIN_X / 2));
	SAFEZONE_H(UI_HEIGHT - (MARGIN_Y * 3));
};

class HouseList: Life_RscListBox {
    idc = 23051;
	colorBackground[] = INNER_BODY_COLOUR;
	onLBSelChanged = "_this call ULP_fnc_switchHouse;";
    rowHeight = 0.09;
    sizeEx = 0.033;
    SAFEZONE_X(UI_X);
	SAFEZONE_Y(UI_Y + (MARGIN_Y * 3));
	SAFEZONE_W(((UI_WIDTH - 0.01) / 2) - (MARGIN_X / 2));
	SAFEZONE_H(UI_HEIGHT - (MARGIN_Y * 3));
};

class HouseView : Life_RscControlsGroup {
    idc = 23052;
	colorBackground[] = INNER_BODY_COLOUR;
	SAFEZONE_X((UI_X + ((UI_WIDTH - 0.01) / 2) - (MARGIN_X / 2)) + MARGIN_X);
	SAFEZONE_Y(UI_Y + (MARGIN_Y * 3));
	SAFEZONE_W(((UI_WIDTH - 0.01) / 2) - (MARGIN_X / 2));
	SAFEZONE_H(UI_HEIGHT - (MARGIN_Y * 3));

    class Controls {
		class Options : ULP_ctrlOptionsHeader {
			idc = 101;
			text = "House Options";
			w = 15.55 * GUI_GRID_CENTER_W;
		};

		class NameOption : Life_RscControlsGroupNoScrollbars {
            idc = 102;
            w = 15.55 * GUI_GRID_CENTER_W;
            h = SIZE_M * GUI_GRID_CENTER_H;
            y = SIZE_M * GUI_GRID_CENTER_H;

            class Controls {
                class OptionName: Life_RscText {
                    idc = 101;
                    text = "Name House";
                    tooltip = "You can rename your house to make it easier to identify...";
                    w = (15.55 / 2) * GUI_GRID_CENTER_W;
                    h = SIZE_M * GUI_GRID_CENTER_H;
                };
                class OptionButton : ULP_RscButtonClean {
                    idc = 102;
                    text = "<t align = 'center'>Rename</t>";
                    onButtonClick = "private _house = (ctrlParent (_this select 0)) getVariable [""house"", objNull]; [_house, { _this params [ ""_display"", ""_house"" ]; if (isNull _display || { isNull _house }) exitWith {}; private _list = _display displayCtrl 23051; _list lbSetText [(lbCurSel _list), (_house getVariable [""building_name"", ([typeOf _house] call ULP_fnc_vehicleCfg) param [3, ""House""]])]; }, [ctrlParent (_this select 0), _house]] call ULP_fnc_renameHouse;";
                    x = (15.55 - (15.55 / 2)) * GUI_GRID_CENTER_W;
                    w = (15.55 / 2) * GUI_GRID_CENTER_W;
                    h = SIZE_M * GUI_GRID_H;
                };
            };
        };

		class ShareOption : Life_RscControlsGroupNoScrollbars {
			idc = 103;
			w = 15.55 * GUI_GRID_CENTER_W;
			h = SIZE_M * GUI_GRID_CENTER_H;
			y = (SIZE_M * 2) * GUI_GRID_CENTER_H;

			class Controls {
				class OptionName: Life_RscText {
					idc = 101;
					text = "Share House";
					tooltip = "When shared a house can be accessed by your group members...";
					w = (15.55 / 2) * GUI_GRID_CENTER_W;
					h = SIZE_M * GUI_GRID_CENTER_H;
				};
				class OptionButton : ULP_RscButtonClean {
					idc = 102;
					text = "<t align = 'center'>Share</t>";
					onButtonClick = "private _house = (ctrlParent (_this select 0)) getVariable [""house"", objNull]; if ([_house] call ULP_fnc_shareHouse) then { (_this select 0) ctrlSetStructuredText parseText format[""<t align = 'center'>%1</t>"", [""Share"",""Unshare""] select ([_house] call ULP_fnc_isHouseShared)] };";
					x = (15.55 - (15.55 / 2)) * GUI_GRID_CENTER_W;
					w = (15.55 / 2) * GUI_GRID_CENTER_W;
					h = SIZE_M * GUI_GRID_H;
				};
			};
		};
	};
};

class VehicleView : Life_RscControlsGroup {
    idc = 23092;
	colorBackground[] = INNER_BODY_COLOUR;
	SAFEZONE_X((UI_X + ((UI_WIDTH - 0.01) / 2) - (MARGIN_X / 2)) + MARGIN_X);
	SAFEZONE_Y(UI_Y + (MARGIN_Y * 3));
	SAFEZONE_W(((UI_WIDTH - 0.01) / 2) - (MARGIN_X / 2));
	SAFEZONE_H(UI_HEIGHT - (MARGIN_Y * 3));

    class Controls {
		class Options : ULP_ctrlOptionsHeader {
			idc = 101;
			text = "Vehicle Options";
			w = 15.55 * GUI_GRID_CENTER_W;
		};

		class ShareOption : Life_RscControlsGroupNoScrollbars {
			idc = 102;
            w = 15.55 * GUI_GRID_CENTER_W;
            h = SIZE_M * GUI_GRID_CENTER_H;
            y = SIZE_M * GUI_GRID_CENTER_H;

			class Controls {
				class OptionName: Life_RscText {
					idc = 101;
					text = "Share Keys";
					tooltip = "Shares vehicle keys with every member inside vehicle...";
					w = (15.55 / 2) * GUI_GRID_CENTER_W;
					h = SIZE_M * GUI_GRID_CENTER_H;
				};
				class OptionButton : ULP_RscButtonClean {
					idc = 102;
					text = "<t align = 'center'>Share</t>";
					onButtonClick = "_this call ULP_fnc_shareKeys";
					x = (15.55 - (15.55 / 2)) * GUI_GRID_CENTER_W;
					w = (15.55 / 2) * GUI_GRID_CENTER_W;
					h = SIZE_M * GUI_GRID_H;
				};
			};
		};
	};
};