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

			if (toUpper _name find (toUpper ctrlText _searchEdit) >= 0 && { (getNumber(_x >> "marketDisplay")) isEqualTo 1 }) then {
				_itemList lnbAddRow [
					_name, // Display Name...
					["Illegal", "Legal"] select (getNumber(_x >> "illegal") isEqualto 0),
					(getNumber(_x >> "weight")), // Item Weight...
					[(getNumber(_x >> "sellPrice"))] call life_fnc_numberText // Item Sell Price...
				];
			};
		} foreach ("true" configClasses (missionConfigFile >> "CfgItems"));

		_itemList lnbSetCurSelRow -1; // Set current selection...
	};

	case "Perks": {
		private _display = findDisplay IDD_TABLET_MAIN;
		private _scrollView = CONTROL(IDD_TABLET_MAIN, IDC_PERK_SCROLL);

		private _side = switch (playerSide) do {case west:{"Police"}; case civilian:{"Civilian"}; case independent:{"Medic"};};
		
		private _baseIDC = IDC_TABLET_BASE;
		private _yValues = [0.236,0.258,0.302,0.236,0.258];
		#define INC 0.099

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
				_button ctrlEnable false; // We can't unlock this perk...

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

				_cover ctrlCommit 0;
				_requiredText ctrlCommit 0;
			};

			// Work out different Y Values...
			_yValues set[0, ((_yValues select 0) + INC)]; // Title...
			_yValues set[1, ((_yValues select 1) + INC)]; // Description...
			_yValues set[2, ((_yValues select 2) + INC)]; // Button...
			_yValues set[3, ((_yValues select 3) + INC)]; // Cover...
			_yValues set[4, ((_yValues select 4) + INC)]; // Required Text...

			// Commit Changes...
			_title ctrlCommit 0;
			_description ctrlCommit 0;
			_button ctrlCommit 0;

			_baseIDC = _baseIDC + (count (_thisElement)); // Increment by count for next row...
			FF_createdElements pushBack _thisElement; // Save it to be deleted later...
		} foreach (format ["'%1' in (getArray(_x >> 'sides')) || { count ((getArray(_x >> 'sides'))) <= 0 }", _side] configClasses (missionConfigFile >> "CfgPerks"));
	};
};