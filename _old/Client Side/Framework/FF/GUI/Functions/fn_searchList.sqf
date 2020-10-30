/*
	@File: fn_searchList.sqf

	@Author: Jack "Scarso" Farhall

	@Description: Allows for the user to search through a list and update accordingly.

	@Written For: SerenityRP, PhoeinxRP

	@Note:
	Currently only supports one search box per UI. I could make it support multiple but it's not required currently.
*/

#include "..\..\..\script_macros.hpp"

params [
	["_display",-1,[0]],
	["_listBox",-1,[0]],
	["_searchBox",-1,[0]],
	["_type","",[""]]
];

disableSerialization;
if(_display isEqualTo -1 || {_listBox isEqualTo -1} || {_searchBox isEqualTo -1}) exitWith {hint "Bad Input!";};

private _list = CONTROL(_display,_listBox);
private _ctrlSearchEdit = CONTROL(_display,_searchBox);

switch(_type) do {
	case "setup": {
		private _listInArray = [];

		for "_i" from 0 to (lbSize _list) do {
			private _value = lbText [_listBox, _i];
			private _data = lbData [_listBox, _i];
			_value = ((_value splitString '"') joinString '');
			_data = ((_data splitString '"') joinString '');
			_listInArray pushBack [_value, _data];
		};
		FF_originalList = _listInArray;
	};

	case "search": {
		lbClear _list;

		{
			_value = _x select 0;
			_dataRaw = str(_x select 1);
			_data = ((_dataRaw splitString '"') joinString '');
			if (toUpper _value find (toUpper ctrlText _ctrlSearchEdit) >= 0) then {
				_list lbAdd format["%1",_value];
				_list lbSetData [(lbSize _list)-1,_data];
			};
		} foreach FF_originalList;
	};
};