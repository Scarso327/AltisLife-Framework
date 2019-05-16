/*
	@File: fn_onLoad.sqf
  
	@Author: Jack "Scarso" Farhall
  
	@Description: Runs on switch application...
*/
#include "..\..\..\..\script_macros.hpp"
#include "..\macros.hpp"
params [
	["_title", "AsYetUntitled", [""]]
];

disableSerialization;
if (_title isEqualTo "AsYetUntitled") exitWith { systemChat "No Title..." };

// Delete all previous to ensure we don't end up with doubles...
{
	if (_x isEqualType []) then {
		for "_i" from 0 to (count (_x) - 1) do { ctrlDelete (_x select _i) };
	} else {
		ctrlDelete _x;
	};
} forEach FF_createdElements;
FF_createdElements = []; // Wipe it...

switch (_title) do {
	case "Inventory": {
		private _list = CONTROL(IDD_TABLET_MAIN, IDC_INV_LIST);
		lbClear _list;
		
		ctrlSetText[IDC_INV_TITLE,format["Inventory Menu [Weight: %1 / %2]", life_carryWeight, life_maxWeight]];
		
		{
			if(ITEM_VALUE(configName _x) > 0) then {
				_list lbAdd format["%2 [x%1]",ITEM_VALUE(configName _x),(getText(_x >> "displayName"))];
				_list lbSetData [(lbSize _list)-1,configName _x];
				_icon = M_CONFIG(getText,"CfgItems",configName _x,"icon");
				if !(_icon isEqualTo "") then {
					_list lbSetPicture [(lbSize _list)-1,_icon];
				};
			};
		} foreach ("true" configClasses (missionConfigFile >> "CfgItems"));

		if(((lbSize _list)-1) isEqualTo -1) then {
			_list lbAdd "You don't have any items...";
			_list lbSetData [(lbSize _list)-1,""];
		};
	};

	case "Licenses": {
		private _list = CONTROL(IDD_TABLET_MAIN, IDC_LIC_LIST);
		lbClear _list;

		private _side = switch (playerSide) do {case west:{"cop"}; case civilian:{"civ"}; case independent:{"med"};};
		
		private _keyword = ["License", "Authorisation"] select (playerSide isEqualTo west);
		ctrlSetText[IDC_LIC_TITLE, format["%1 Menu", _keyword]];

		{
			if (LICENSE_VALUE(configName _x,_side)) then { _list lbAdd getText(_x >> "displayName") };
		} forEach (format ["getText(_x >> 'side') isEqualTo '%1'",_side] configClasses (missionConfigFile >> "CfgLicenses"));

		if(((lbSize _list)-1) isEqualTo -1) then {
			_list lbAdd format["You don't have any %1s...", _keyword];
			_list lbSetData [(lbSize _list)-1,""];
		};
	};
	
	case "KeyChain": {
		private _list = CONTROL(IDD_TABLET_MAIN, IDC_KEY_LIST);
		lbClear _list;
		
		for "_i" from 0 to (count life_vehicles)-1 do {
			_veh = life_vehicles select _i;
			if (!isNull _veh && alive _veh) then {
				_color = ((M_CONFIG(getArray,"LifeCfgVehicles",(typeOf _veh),"textures") select (_veh getVariable "Life_VEH_color")) select 0);
				if (isNil "_color") then {_color = ""};
				_text = format ["(%1)",_color];
				if (_text == "()") then {
					_text = "";
				};

				_name = getText(configFile >> "CfgVehicles" >> (typeOf _veh) >> "displayName");
				_pic = getText(configFile >> "CfgVehicles" >> (typeOf _veh) >> "picture");
				_list lbAdd format ["%1 %3 - [Distance: %2m]",_name,round(player distance _veh),_text];
				if (_pic != "pictureStaticObject") then {
					_list lbSetPicture [(lbSize _list)-1,_pic];
				};
				_list lbSetData [(lbSize _list)-1,str(_i)];
			};
		};

		if(((lbSize _list)-1) isEqualTo -1) then {
			_list lbAdd "You don't have any keys...";
			_list lbSetData [(lbSize _list)-1,""];
		};

		_list = CONTROL(IDD_TABLET_MAIN, IDC_KEY_PLAYERS);
		lbClear _list;

		{
			_list lbAdd format ["%1 - %2",_x getVariable ["realname",name _x], side _x];
			_list lbSetData [(lbSize _list)-1,str(_x)];
		} forEach (playableUnits select {!isNull _x && alive _x && player distance _x < 20 && !(_x isEqualTo player)});
	};

	case "Market": {
		private _listHeader = CONTROL(IDD_TABLET_MAIN, IDC_MARKET_HEADER);
		private _itemList = CONTROL(IDD_TABLET_MAIN, IDC_MARKET_LIST);
		private _searchEdit = CONTROL(IDD_TABLET_MAIN, IDC_MARKET_SEARCH);

		[_listHeader, _itemList, IDC_MARKET_HEADER_BUTTONS_BASE] call FF(setupFilter);
		["MarketUpdate"] call FF(onLoad);

		_searchEdit ctrlAddEventHandler ["KeyUp", {["MarketUpdate"] call FF(onLoad);}]; // Reload when searching...
	};

	case "MarketUpdate": {
		private _itemList = CONTROL(IDD_TABLET_MAIN, IDC_MARKET_LIST);
		private _searchEdit = CONTROL(IDD_TABLET_MAIN, IDC_MARKET_SEARCH);

		lnbClear _itemList; // Ensure the list is cleared...

		{
			private _name = (getText(_x >> "displayName"));

			if (toUpper _name find (toUpper ctrlText _searchEdit) >= 0 && { (getNumber(_x >> "marketDisplay")) isEqualTo 1 } && { (getNumber(_x >> "sellPrice")) > 0 }) then {
				_itemList lnbAddRow [
					_name, // Display Name...
					["Illegal", "Legal"] select (getNumber(_x >> "illegal") isEqualto 0),
					[(getNumber(_x >> "weight"))] call life_fnc_numberText, // Item Weight...
					[(getNumber(_x >> "sellPrice"))] call life_fnc_numberText // Item Sell Price...
				];
			};
		} foreach ("true" configClasses (missionConfigFile >> "CfgItems"));

		_itemList lnbSetCurSelRow -1; // Set current selection...
	};

	case "Perks": {
		private _display = findDisplay IDD_TABLET_MAIN;
		private _scrollView = CONTROL(IDD_TABLET_MAIN, IDC_PERK_SCROLL);
		private _removalInfo = CONTROL(IDD_TABLET_MAIN, IDC_PERK_REMOVE_INFO);

		private _side = switch (playerSide) do {case west:{"Police"}; case civilian:{"Civilian"}; case independent:{"Medic"};};
		
		private _baseIDC = IDC_TABLET_BASE;
		private _yValues = [0.236,0.258,0.302,0.236,0.258];
		#define INC 0.099

		_removalInfo ctrlSetStructuredText parseText format["<t align='center'>Removal Cost: <t color = '#7300e6'>£%1</t></t>", [LIFE_SETTINGS(getNumber, "perk_removal")] call LIFE(numberText)];

		// This area works out and updates the inactive perks...
		{
			private _thisElement = [];

			// Create Perk Title...
			private _title = _display ctrlCreate ["Life_RscText", _baseIDC, _scrollView];
			_title ctrlSetText (getText(_x >> "displayName"));
			_title ctrlSetPosition [0.345312 * safezoneW + safezoneX, (_yValues select 0) * safezoneH + safezoneY, 0.201094 * safezoneW, 0.022 * safezoneH];
			_thisElement pushBack _title;
			
			// Create Perk Description...
			private _description = _display ctrlCreate ["Life_RscStructuredText", (_baseIDC + 1), _scrollView];
			_description ctrlSetStructuredText parseText (getText(_x >> "description"));
			_description ctrlSetPosition [0.345312 * safezoneW + safezoneX, (_yValues select 1) * safezoneH + safezoneY, 0.37125 * safezoneW, 0.044 * safezoneH];
			_thisElement pushBack _description;

			// Create Select Button...
			private _button = _display ctrlCreate ["Life_RscButtonMenu", (_baseIDC + 2), _scrollView];
			_button ctrlSetStructuredText parseText "SELECT PERK";
			_button ctrlSetPosition [0.345312 * safezoneW + safezoneX, (_yValues select 2) * safezoneH + safezoneY, 0.0721875 * safezoneW, 0.022 * safezoneH];
			_thisElement pushBack _button;

			if !(FF_Level >= (getNumber(_x >> "unlockLevel"))) then {
				_button ctrlRemoveAllEventHandlers "ButtonClick"; // Stop them being able to use it...

				// Create Cover...
				private _cover = _display ctrlCreate ["Life_RscBackground", (_baseIDC + 4), _scrollView];
				_cover ctrlSetPosition [0.283437 * safezoneW + safezoneX, (_yValues select 3) * safezoneH + safezoneY, 0.443438 * safezoneW, 0.088 * safezoneH];
				_cover ctrlSetBackgroundColor [0,0,0,0.8];
				_thisElement pushBack _cover;

				// Create Text...
				private _requiredText = _display ctrlCreate ["Life_RscStructuredText", (_baseIDC + 5), _scrollView];
				_requiredText ctrlSetPosition [0.283437 * safezoneW + safezoneX, (_yValues select 4) * safezoneH + safezoneY, 0.443438 * safezoneW, 0.044 * safezoneH];
				_requiredText ctrlSetStructuredText parseText format["<t align='center' size='2'>LEVEL <t color = '#7300e6'>%1</t> REQUIRED</t>", (getNumber(_x >> "unlockLevel"))];
				_thisElement pushBack _requiredText;

				// Commit Changes...
				_cover ctrlCommit 0;
				_requiredText ctrlCommit 0;
			} else {
				if !(HAS_PERK(_perk)) then {
					// Add button functionality...
					private _function = format["['%1', false] call FF_fnc_changePerks", configName _x];
					_button ctrlSetEventHandler ["ButtonClick", _function];
				} else {
					_button ctrlRemoveAllEventHandlers "ButtonClick"; // Stop them being able to use it...
				};
			};

			{ _yValues set[_forEachIndex, ((_yValues select _forEachIndex) + INC)] } forEach _yValues; // Work out different Y Values...

			// Commit Changes...
			_title ctrlCommit 0;
			_description ctrlCommit 0;
			_button ctrlCommit 0;

			_baseIDC = _baseIDC + (count (_thisElement)); // Increment by count for next row...
			FF_createdElements pushBack _thisElement; // Save it to be deleted later...
		} foreach (format ["'%1' in (getArray(_x >> 'sides')) || { count ((getArray(_x >> 'sides'))) <= 0 }", _side] configClasses (missionConfigFile >> "CfgPerks"));

		[] call FF(updatePerks); // This will update our active perks...
	};

	case "Professions": {
		private _display = findDisplay IDD_TABLET_MAIN;
		private _scrollView = CONTROL(IDD_TABLET_MAIN, IDC_PROF_VIEW);

		private _side = switch (playerSide) do {case west:{"Police"}; case civilian:{"Civilian"}; case independent:{"Medic"};};

		private _baseIDC = IDC_TABLET_BASE;
		private _yValues = [0.225,0.236,0.269,0.275];
		#define INC 0.094

		{
			private _thisElement = [];
			
			private _curLevel = PROF_LVL(configName _x);
			private _maxLevel = getNumber(_x >> "maxLevel");

			// Create Background...
			private _background = _display ctrlCreate ["Life_RscBackground", (_baseIDC + 1), _scrollView];
			_background ctrlSetPosition [0.298906 * safezoneW + safezoneX, (_yValues select 0) * safezoneH + safezoneY, 0.433125 * safezoneW, 0.088 * safezoneH];
			_background ctrlSetBackgroundColor [0,0,0,0.2];
			_thisElement pushBack _background;

			// Create Icon...
			private _icon = _display ctrlCreate ["Life_RscBackground", (_baseIDC + 2), _scrollView];
			_icon ctrlSetPosition [0.304062 * safezoneW + safezoneX, (_yValues select 1) * safezoneH + safezoneY, 0.04125 * safezoneW, 0.066 * safezoneH];
			_icon ctrlSetBackgroundColor [0,0,0,1];
			_thisElement pushBack _icon;

			// Create Progress Background...
			private _progressBack = _display ctrlCreate ["Life_RscBackground", (_baseIDC + 3), _scrollView];
			_progressBack ctrlSetPosition [0.347312 * safezoneW + safezoneX, (_yValues select 2) * safezoneH + safezoneY, 0.293906 * safezoneW, 0.033 * safezoneH];
			_progressBack ctrlSetBackgroundColor [0.7,0.7,0.7,0.3];
			_thisElement pushBack _progressBack;

			// Create Progress Bar...
			private _progressBar = _display ctrlCreate ["Life_RscProgress", (_baseIDC + 4), _scrollView];
			_progressBar ctrlSetPosition [0.347312 * safezoneW + safezoneX, (_yValues select 2) * safezoneH + safezoneY, 0.293906 * safezoneW, 0.033 * safezoneH];
			_progressBar ctrlSetBackgroundColor [0.09,0.09,0.09,1];
			_progressBar progressSetPosition (_curLevel / _maxLevel);
			_thisElement pushBack _progressBar;

			// Create XP Text...
			private _XPText = _display ctrlCreate ["Life_RscStructuredText", (_baseIDC + 5), _scrollView];
			_XPText ctrlSetPosition [0.347312 * safezoneW + safezoneX, (_yValues select 3) * safezoneH + safezoneY, 0.293906 * safezoneW, 0.033 * safezoneH];
			_XPText ctrlSetStructuredText parseText format["<t align='center' valign='middle' size='1.15'>%1 / %2</t>", _curLevel, _maxLevel];
			_thisElement pushBack _XPText;

			// Create View Button...
			private _button = _display ctrlCreate ["Life_RscButtonMenu", (_baseIDC + 6), _scrollView];
			_button ctrlSetStructuredText parseText "<t align='center' valign='middle'>VIEW MORE</t>";
			_button ctrlSetPosition [0.644374 * safezoneW + safezoneX, (_yValues select 2) * safezoneH + safezoneY, 0.0825 * safezoneW, 0.033 * safezoneH];
			_thisElement pushBack _button;

			// Create Title Text...
			private _titleText = _display ctrlCreate ["Life_RscStructuredText", (_baseIDC + 7), _scrollView];
			_titleText ctrlSetPosition [0.347312 * safezoneW + safezoneX, (_yValues select 1) * safezoneH + safezoneY, 0.195937 * safezoneW, 0.033 * safezoneH];
			_titleText ctrlSetStructuredText parseText format["<t size='1.5'>%1</t>", toUpper(getText(_x >> "displayName"))];
			_thisElement pushBack _titleText;

			{ _yValues set[_forEachIndex, ((_yValues select _forEachIndex) + INC)] } forEach _yValues; // Work out different Y Values...

			// Commit Changes...
			_background ctrlCommit 0;
			_titleText ctrlCommit 0;
			_icon ctrlCommit 0;
			_progressBack ctrlCommit 0;
			_button ctrlCommit 0;
			_progressBar ctrlCommit 0;
			_XPText ctrlCommit 0;

			_baseIDC = _baseIDC + (count (_thisElement)); // Increment by count for next row...
			FF_createdElements pushBack _thisElement; // Save it to be deleted later...
		} foreach (format ["'%1' isEqualTo (getText(_x >> 'side'))", _side] configClasses (missionConfigFile >> "CfgProfessions"));
	};
};