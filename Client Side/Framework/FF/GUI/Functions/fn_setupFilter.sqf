/// CREDIT TO WHOEVER THE SAD BASTERED WAS THAT WROTE THIS SCRIPT IS. Even I can't be asked.

#define PICTURE_NONE	"\a3\3DEN\Data\Displays\Display3DENSave\sort_none_ca.paa"
#define PICTURE_UP	"\a3\3DEN\Data\Displays\Display3DENSave\sort_up_ca.paa"
#define PICTURE_DOWN	"\a3\3DEN\Data\Displays\Display3DENSave\sort_down_ca.paa"
disableserialization;

private _ctrlFilter = param [0,controlnull,[controlnull]];
private _display = ctrlparent _ctrlFilter;
private _ctrlContent = param [1,controlnull,[controlnull]];
private _idc = param [2,200,[0]];
private _columnIndexes = param [3,[],[[]]];

if (isnull _ctrlFilter) exitwith {"Filter control is null." call bis_fnc_error; false};
if (isnull _ctrlContent) exitwith {"Content control is null." call bis_fnc_error; false};

private _pos = ctrlposition _ctrlFilter;
private _posX = _pos select 0;
private _posY = _pos select 1;
private _posW = _pos select 2;
private _posH = _pos select 3;

private _columns = lnbGetColumnsPosition _ctrlFilter;
private _code = "
	_display = ctrlparent (_this select 0);
	_ctrlFilter = _display displayctrl %2;
	_ctrlContent = _display displayctrl %3;
	_selected = %1;
	_columnIndexes = %7;
	for '_i' from 0 to (lnbsize _ctrlFilter select 1) - 1 do {
		_picture = '%4';
		_value = -1;
		_valueCurrent = _ctrlFilter lnbvalue [0,_i];
		if (_selected < 0 && _valueCurrent > -1) then {_selected = _i; _valueCurrent = _valueCurrent + 1;};
		if (_i == _selected) then {
			_value = (_valueCurrent + 1) mod 2;
			_picture = ['%6','%5'] select _value;
			_index = _columnIndexes param [_i,_selected];
			if ((_ctrlFilter lnbdata [0,_i]) != '') then {
				_ctrlContent lnbsortbyvalue [_index,_value > 0];
			} else {
				_ctrlContent lnbsort [_index,_value > 0];
			};
		};
		_ctrlFilter lnbsetvalue [[0,_i],_value];
		_ctrlFilter lnbsetpicture [[0,_i],_picture];
	};
	if (lbcursel _ctrlFilter != -1) then {_ctrlFilter lbsetcursel -1;};
";

//--- Create overlay buttons
private _isSelected = false;
private _ctrlGroup = ctrlparentcontrolsgroup _ctrlFilter;
{
	private _ctrlButton = if (isnull _ctrlGroup) then {
		_display ctrlCreate ["ctrlButtonFilter",_idc + _foreachindex];
	} else {
		_display ctrlCreate ["ctrlButtonFilter",_idc + _foreachindex,_ctrlGroup];
	};
	private _x2 = (_columns + [1]) select (_foreachindex + 1);
	private _ctrlButtonPos = [
		_posX + (_x * _posW),
		_posY,
		(_x2 - _x) * _posW,
		_posH
	];
	_ctrlButton ctrlsetposition _ctrlButtonPos;
	_ctrlButton ctrlcommit 0;
	_ctrlButton ctrladdeventhandler [
		"buttonclick",
		format [_code, _foreachindex ,ctrlidc _ctrlFilter,ctrlidc _ctrlContent,PICTURE_NONE,PICTURE_UP,PICTURE_DOWN,_columnIndexes]
	];
	_valueDef = _ctrlFilter lnbvalue [0,_foreachindex];
	if (_valueDef > -1) then {
		if (_isSelected) then {_valueDef = -1;};
		_isSelected = true;
	};
	_ctrlFilter lnbsetpicture [[0,_foreachindex],PICTURE_NONE];
	_ctrlFilter lnbsetvalue [[0,_foreachindex],_valueDef];
} foreach _columns;

//--- Add filter handler which will refresh sorting when filter selection changes
_ctrlFilter ctrladdeventhandler [
	"lbselchanged",
	format [_code,-1,ctrlidc _ctrlFilter,ctrlidc _ctrlContent,PICTURE_NONE,PICTURE_UP,PICTURE_DOWN,_columnIndexes]
];

//--- Init
[_display displayctrl _idc] call compile format [_code,-1,ctrlidc _ctrlFilter,ctrlidc _ctrlContent,PICTURE_NONE,PICTURE_UP,PICTURE_DOWN,_columnIndexes];
true