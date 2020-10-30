#include "..\script_macros.hpp"
/*
    File: fn_notifyAdmins.sqf
    Author: Bryan "Tonic" Boardwine

    Description:
    Checks if player is admin and notifies them that of the
    flagged person.
*/



if (isNil "life_adminlevel") exitWith {};//Should fix undefined "Life_adminLevel"
if (isServer && {!hasInterface}) exitWith {};
if (FETCH_CONST(life_adminlevel) < 1) exitWith {};

hint parseText format ["&lt;t align='center'&gt;&lt;t color='#FF0000'&gt;&lt;t size='3'&gt;SPY-GLASS&lt;/t&gt;&lt;/t&gt;&lt;br/&gt;Cheater Flagged&lt;/t&gt;&lt;br/&lt;br/&gt;Name: %1&lt;br/&gt;Detection: %2", (_this select 0), (_this select 1)];
