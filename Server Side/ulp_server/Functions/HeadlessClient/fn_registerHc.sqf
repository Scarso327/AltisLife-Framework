/*
    Description:
    Registers given headless client to the server, allowing it to be used for processing and other tasks.
*/
scopeName "fn_registerHc";

_this params [
	["_hcId", -1, [0]]
];

if (_hcId == -1) exitWith {
	["No headless client ID provided to register."] call ULP_fnc_logIt;

	false
};

ULP_HC_ID = _hcId;
publicVariable "ULP_HC_ID";

[format["Registered headless client with ID %1", _hcId]] call ULP_fnc_logIt;

true