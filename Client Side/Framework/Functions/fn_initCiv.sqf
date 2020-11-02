#include "..\script_macros.hpp"

waitUntil {!(isNull (findDisplay 46))};
if (life_is_alive && !life_is_arrested) then {
    player setVehiclePosition [life_civ_position, [], 0, "CAN_COLLIDE"];
} else {
    if (!life_is_alive && !life_is_arrested) then {
        [] call life_fnc_spawnMenu;
        waitUntil{!isNull (findDisplay 38500)};
        waitUntil{isNull (findDisplay 38500)};
    } else {
        if (life_is_arrested) then {
            life_is_arrested = false;
            [player,true] spawn life_fnc_jail;
        };
    };
};

life_is_alive = true;