/*
	@File: fn_openProcessing.sqf
  
	@Author: Jack "Scarso" Farhall
  
	@Description: Opens the "Processing" Menu...
*/
#include "..\..\..\..\script_macros.hpp"
disableSerialization;
private _processList = _this select 3;
FF_ProcessingVendor = _this select 0;

private _side = switch (playerSide) do {case west:{"cop"}; case civilian:{"civ"}; case independent:{"med"};};

if (life_is_processing || life_action_inUse) exitWith {}; // Already Processing or doing something...
if !(createDialog "RscProcessing") exitWith { systemChat "Failed to create dialog..." };

private _list = CONTROL(5000, 5001);
lbClear _list;

{
    private _materialsRequired = M_CONFIG(getArray,"CfgProcess",_x,"MaterialsReq");
	private _reqItem = (_materialsRequired select 0) select 0;
	private _itemCount = ITEM_VALUE(_reqItem);

	if (_itemCount > 0) then {
		private _displayName = M_CONFIG(getText,"CfgItems",_reqItem,"displayName");
		private _icon = M_CONFIG(getText,"CfgItems",_reqItem,"icon");

		private _price = (M_CONFIG(getNumber,"CfgProcess",_x,"NoLicenseCost")) * _itemCount;
		private _licenseReq = M_CONFIG(getText,"CfgProcess",_x,"RequiredLicense");

		private _license = LICENSE_VALUE(_licenseReq,_side); 
		if (_license) then {_price = 0};

		_list lbAdd format["%1 [x%2]", _displayName, _itemCount];
		_list lbSetData[(lbSize _list)-1, _x];
		_list lbSetValue[(lbSize _list)-1,_price];

		if !(_icon isEqualTo "") then {
			_list lbSetPicture [(lbSize _list)-1,_icon];
		};
	};
} forEach _processList;

ctrlEnable[5003, false]; // Disable "Process Button"