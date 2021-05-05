class CfgInteractions {
	class Money {
		class Pickup {
			title = "Pickup Money";
			factions[] = { "Police", "Medic", "Hato", "Civilian" };
			onClick = "_this call ULP_fnc_pickupMoney";
			condition = "(_this getVariable [""ULP_MoneyStack"", 0]) > 0";
		};
		class Burn : Pickup {
			title = "Burn Money";
			onClick = "deleteVehicle (_this select 0)";
			condition = "(_this getVariable [""ULP_MoneyStack"", 0]) > 0 && { (([""Lighter""] call ULP_fnc_hasItem) > 0) }";
		};
	};

	class Person {
		class GiveKeys {
			title = "Give Keys";
			factions[] = { "Police", "Medic", "Hato", "Civilian" };
			onClick = "_this call ULP_fnc_giveVehicleKeys";
			condition = "true";
		};
		class GiveCash : GiveKeys {
			title = "Give Cash";
			onClick = "if ([_this select 0] call ULP_fnc_giveMoney) then { closeDialog 0; };";
		};
		class GiveItems : GiveKeys { // TODONOW
			title = "Give Items";
			onClick = "hint ""Hello"";";
		};
		class ShowLicenses : GiveKeys { // TODONOW
			title = "Show Licenses";
			onClick = "hint ""Hello"";";
		};

		class Unrestrain : GiveKeys {
			title = "Unrestrain";
			onClick = "[_this select 0, player, false] call ULP_fnc_restrain; closeDialog 0;";
			condition = "[_this] call ULP_fnc_isRestrained && { [player, [""Police""]] call ULP_fnc_isFaction || (([_this getVariable [""restrained"", objNull]] call ULP_fnc_getFaction) isEqualTo player || [group (_this getVariable [""restrained"", objNull]), player] call ULP_fnc_inGroup) || [player] call ULP_fnc_onDuty }";
		};
		class Escort : Unrestrain {
			title = "Escort";
			onClick = "[_this select 0, player, true] call ULP_fnc_escort; closeDialog 0;";
			condition = "[_this] call ULP_fnc_isRestrained && { [player, [""Police""]] call ULP_fnc_isFaction || (([_this getVariable [""restrained"", objNull]] call ULP_fnc_getFaction) isEqualTo player || [group (_this getVariable [""restrained"", objNull]), player] call ULP_fnc_inGroup) || [player] call ULP_fnc_onDuty } && { !([_this] call ULP_fnc_isEscorted) }";
		};
		class StopEscort : Unrestrain {
			title = "Stop Escorting";
			onClick = "[_this select 0, player, false] call ULP_fnc_escort; closeDialog 0;";
			condition = "[_this] call ULP_fnc_isRestrained && { [player, [""Police""]] call ULP_fnc_isFaction || (([_this getVariable [""restrained"", objNull]] call ULP_fnc_getFaction) isEqualTo player || [group (_this getVariable [""restrained"", objNull]), player] call ULP_fnc_inGroup) || [player] call ULP_fnc_onDuty } && { [_this] call ULP_fnc_isEscorted }";
		};
		class PutInVehicle : Unrestrain { // TODONOW
			title = "Put In Vehicle";
			onClick = "hint ""Hello"";";
		};
		class FeedHydrate : Unrestrain { // TODO
			title = "Feed/Hydrate";
			onClick = "hint ""Hello"";";
		};
		class Blindfold : Unrestrain {
			title = "Blindfold";
			onClick = "_this call ULP_fnc_blindfold";
			condition = "[_this] call ULP_fnc_isRestrained && { [player, [""Police""]] call ULP_fnc_isFaction || (([_this getVariable [""restrained"", objNull]] call ULP_fnc_getFaction) isEqualTo player || [group (_this getVariable [""restrained"", objNull]), player] call ULP_fnc_inGroup) || [player] call ULP_fnc_onDuty } && { ([""Blindfold""] call ULP_fnc_hasItem) > 0 } && { !(_this getVariable [""blindfold"", false]) }";
		};
		class Unblindfold : Blindfold {
			title = "Remove Blindfold";
			condition = "[_this] call ULP_fnc_isRestrained && { [player, [""Police""]] call ULP_fnc_isFaction || (([_this getVariable [""restrained"", objNull]] call ULP_fnc_getFaction) isEqualTo player || [group (_this getVariable [""restrained"", objNull]), player] call ULP_fnc_inGroup) || [player] call ULP_fnc_onDuty } && { _this getVariable [""blindfold"", false] }";
		};
		class CashCheck : Unrestrain { // TODONOW
			title = "Check Cash"; // Provide ability to seize
			onClick = "hint ""Hello"";";
		};
		class InventoryCheck : Unrestrain {
			title = "Check Inventory";
			onClick = "player action [""Gear"", cursorObject]; closeDialog 0;";
		};
		class vItemCheck : Unrestrain { // TODONOW
			title = "Check vItems"; // Provide ability to seize
			onClick = "hint ""Hello"";";
		};
		class LicenseCheck : Unrestrain { // TODONOW
			title = "Check Licenses"; // Provide ability to seize
			onClick = "hint ""Hello"";";
		};
		class SeizeCommunications : Unrestrain {
			title = "Destroy Communications";
			onClick = "_this call ULP_fnc_seizeComms;";
			condition = "[_this] call ULP_fnc_isRestrained && { [player, [""Police""]] call ULP_fnc_isFaction || (([_this getVariable [""restrained"", objNull]] call ULP_fnc_getFaction) isEqualTo player || [group (_this getVariable [""restrained"", objNull]), player] call ULP_fnc_inGroup) || [player] call ULP_fnc_onDuty } && { [_this] call ULP_fnc_hasComms }";
		};
		class Ticket : Unrestrain { // TODONOW
			title = "Issue Penalty Notice";
			onClick = "hint ""Hello"";";
		};
		class Imprision : Unrestrain {
			title = "Send to Prison";
			onClick = "_this call ULP_fnc_setPrisonTime; closeDialog 0;";
			condition = "[player] call ULP_fnc_canImprison && { [_this] call ULP_fnc_canImprisoned }";
		};

		// Admin Commands...
		class AdminHeal {
			title = "Admin Heal";
			factions[] = { "Police", "Medic", "Hato", "Civilian" };
			onClick = "(_this select 0) setDamage 0; [format[""You've healed this player using admin powers...""]] call ULP_fnc_hint; [getPlayerUID player, ""Admin"", [""AdminHeal"", serverTime, [name (_this select 0)]]] remoteExecCall [""ULP_SRV_fnc_logPlayerEvent"", 2]; closeDialog 0;";
			condition = "[] call ULP_fnc_isStaff && { [player] call ULP_fnc_onDuty } && { (damage _this) > 0 } && { [""Heal"", false] call ULP_fnc_checkPower }";
		};
	};

	class PersonMedical {
		class Revive {
			title = "Open Vitals";
			factions[] = { "Police", "Medic", "Hato", "Civilian" };
			onClick = "_this call ULP_fnc_openMedical";
			condition = "true";
		};

		class AdministerBlood : Revive {
			title = "Administer Blood";
			onClick = "_this call ULP_fnc_administerBlood";
			condition = "(0 max ([""BloodBag""] call ULP_fnc_hasItem)) > 0";
		};

		class SeizeCommunications : Revive {
			title = "Seize Communications";
			onClick = "_this call ULP_fnc_seizeComms;";
			condition = "[_this] call ULP_fnc_isRestrained && { [player, [""Police""]] call ULP_fnc_isFaction || (([_this getVariable [""restrained"", objNull]] call ULP_fnc_getFaction) isEqualTo player || [group (_this getVariable [""restrained"", objNull]), player] call ULP_fnc_inGroup) || [player] call ULP_fnc_onDuty } && { [_this] call ULP_fnc_hasComms }";
		};

		// Admin Commands...
		class AdminRevive : Revive {
			title = "Admin Revive";
			onClick = "[player] remoteExecCall [""ULP_fnc_revived"", _this select 0]; (_this select 0) setDamage 0; [format[""You've revived this player using admin powers...""]] call ULP_fnc_hint; [getPlayerUID player, ""Admin"", [""AdminRevive"", serverTime, [name (_this select 0)]]] remoteExecCall [""ULP_SRV_fnc_logPlayerEvent"", 2]; closeDialog 0;";
			condition = "[] call ULP_fnc_isStaff && { [player] call ULP_fnc_onDuty } && { [""Revive"", false] call ULP_fnc_checkPower }";
		};
	};

	class PersonEscortOnly {
		class StopEscort {
			title = "Stop Escorting";
			factions[] = { "Police", "Medic", "Hato", "Civilian" };
			onClick = "[_this select 0, player, false] call ULP_fnc_escort; closeDialog 0;";
			condition = "[_this] call ULP_fnc_isRestrained && { [_this] call ULP_fnc_isEscorted }";
		};
	};

	class House {
		class BuyHouse {
			title = "Buy House";
			factions[] = { "Civilian" };
			onClick = "_this call ULP_fnc_buyHouse;";
			condition = "isClass (missionConfigFile >> ""CfgFactions"" >> [player] call ULP_fnc_getFaction >> ""Housing"") && { !([_this] call ULP_fnc_isHouseOwned) }";
		};
	};

	class HouseOwner {
		class SellHouse {
			title = "Sell House";
			factions[] = { "Civilian" };
			onClick = "_this call ULP_fnc_sellHouse;";
			condition = "[_this, player, false] call ULP_fnc_isHouseOwner";
		};
	};

	class EquipmentBox {
		class ClearBox {
			title = "Clear Box";
			factions[] = { "Police" };
			onClick = "_this call ULP_fnc_clearCargo;";
			condition = "true";
		};
		
		class ResetLoadout {
			title = "Reset Loadout";
			factions[] = { "Police", "Medic", "Hato" };
			onClick = "[] call ULP_fnc_setLoadout;";
			condition = "[[player] call ULP_fnc_getFaction] call ULP_fnc_canResetLoadout;";
		};
	};

	class Vault {
		class Repair {
			title = "Repair Vault";
			factions[] = { "Police" };
			onClick = "[""Repairing Vault"", 60, _this, { (player distance (_this select 0)) <= 5 }, { private _object = _this select 0; [""You have successfully reapired the lock!""] call ULP_fnc_hint; _object setVariable [""drilled"", false, true]; }, {}, [""GRAB"", ""CROUCH""]] call ULP_UI_fnc_startProgress;";
			condition = "_this getVariable [""drilled"", true]";
		};
	};

	class Vehicle {

		class Repair {
			title = "Repair";
			factions[] = { "Police", "Medic", "Hato", "Civilian" };
			onClick = "_this call ULP_fnc_repairVehicle";
			condition = "true";
		};

		class Refuel : Repair {
			title = "Refuel with Fuel Can";
			onClick = "_this call ULP_fnc_fuelCan";
			condition = "[""FuelCan""] call ULP_fnc_hasItem > 0";
		};

		class Lockpick : Repair {
			title = "Lockpick";
			onClick = "_this call ULP_fnc_lockpickVehicle";
			condition = "!([player, _this] call ULP_fnc_isVehicleOwner) && { [""Lockpick""] call ULP_fnc_hasItem > 0 }";
		};

		class Registration : Repair {
			title = "Registration";
			onClick = "closeDialog 0; [(_this select 0)] call ULP_fnc_vehicleRegistration";
			factions[] = { "Police", "Hato" };
		};

		class Clamp : Repair {
			title = "Clamp";
			onClick = "_this call ULP_fnc_clampVehicle";
			factions[] = { "Police", "Hato" };
		};

		class Garage : Repair {
			title = "Garage";
			onClick = "_this call ULP_fnc_garageVehicle";
			factions[] = { "Police", "Hato" };
			condition = "[""Police_Main"", 2] call ULP_fnc_hasAccess || { [""Hato_Main"", 1] call ULP_fnc_hasAccess }";
		};

		class Impound : Repair {
			title = "Impound";
			onClick = "_this call ULP_fnc_impoundVehicle";
			factions[] = { "Police" };
			condition = "[""Police_Main"", 2] call ULP_fnc_hasAccess";
		};

		class Scrap : Repair {
			title = "Scrap";
			onClick = "_this call ULP_fnc_crushVehicle";
			factions[] = { "Police" };
			condition = "[""Police_Main"", 3] call ULP_fnc_hasAccess && { [""bluezone_""] call ULP_fnc_isUnitsInZone }";
		};

		class PulloutOccupants : Repair {
			title = "Pullout Occupants";
			onClick = "if (_this call ULP_fnc_ejectVehicleCrew) then { closeDialog 0; };";
			condition = "(speed _this) <= 4 && { _this in ULP_Keys || [""Police_Main"", 1] call ULP_fnc_hasAccess }";
		};

		class Unflip : Repair { // TODONOW
			title = "Unflip";
			onClick = "hint ""Hello"";";
		};

		class Push : Repair { // TODONOW (for boats)
			title = "Push";
			onClick = "hint ""Hello"";";
		};

		// Admin Commands...
		class AdminRepair {
			title = "Admin Repair";
			factions[] = { "Police", "Medic", "Hato", "Civilian" };
			onClick = "(_this select 0) setDamage 0; [format[""You've repaired this vehicle using admin powers.""]] call ULP_fnc_hint; [getPlayerUID player, ""Admin"", [""AdminRepair"", serverTime, [(_this select 0) getVariable [""vehicle_id"", -1]]]] remoteExecCall [""ULP_SRV_fnc_logPlayerEvent"", 2];";
			condition = "[] call ULP_fnc_isStaff && { [player] call ULP_fnc_onDuty } && { [""Vehicle"", false] call ULP_fnc_checkPower }";
		};
		class AdminRefuel {
			title = "Admin Refuel";
			factions[] = { "Police", "Medic", "Hato", "Civilian" };
			onClick = "if ((count (units (_this select 0))) > 0) exitWith { [""No one can be in the vehicle while its refueled!""] call ULP_fnc_hint; }; [(_this select 0), 1] remoteExecCall [""ULP_fnc_setFuel"", (_this select 0)]; hint format[""You've refueled this vehicle using admin powers...""]; [getPlayerUID player, ""Admin"", [""AdminFuel"", serverTime, [(_this select 0) getVariable [""vehicle_id"", -1]]]] remoteExecCall [""ULP_SRV_fnc_logPlayerEvent"", 2];";
			condition = "[] call ULP_fnc_isStaff && { [player] call ULP_fnc_onDuty } && { [""Vehicle"", false] call ULP_fnc_checkPower }";
		};
		class AdminGarage {
			title = "Admin Garage";
			factions[] = { "Police", "Medic", "Hato", "Civilian" };
			onClick = "_this call ULP_fnc_garageVehicle; [getPlayerUID player, ""Admin"", [""AdminGarage"", serverTime, [(_this select 0) getVariable [""vehicle_id"", -1]]]] remoteExecCall [""ULP_SRV_fnc_logPlayerEvent"", 2];";
			condition = "[] call ULP_fnc_isStaff && { [player] call ULP_fnc_onDuty } && { [""Vehicle"", false] call ULP_fnc_checkPower }";
		};
	};
};