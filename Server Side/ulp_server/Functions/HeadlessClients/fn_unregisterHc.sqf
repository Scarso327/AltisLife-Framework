/*
    Description:
    Unregisters given headless client from the server, preventing it from being used for processing and other tasks.
*/
scopeName "fn_unregisterHc";

_this params [
	["_hcId", -1, [0]]
];

if (_hcId == -1) exitWith {
	["No headless client ID provided to unregister."] call ULP_fnc_logIt;

	false
};

ULP_HC_ID = -1;
publicVariable "HC_READY";

[format["Unregistered headless client with ID %1", _hcId]] call ULP_fnc_logIt;

true