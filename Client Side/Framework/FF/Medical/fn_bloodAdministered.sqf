/*
	@File: fn_bloodAdministered.sqf
  
	@Author: Jack "Scarso" Farhall
  
	@Description: Tells us that someone has administered blood and that now we'll take longer to bleedout...
*/
#include "..\..\script_macros.hpp"
if !(params [["_helper", objNull, [objNull]]]) exitWith {};

if !(isDowned(player)) exitWith {}; // How'd this even happen?

hint format ["%1 has administered blood extending the time you'll take to bleed out by 30 seconds...", (_helper getVariable ["realname", name _helper])];

FF_endTime = FF_endTime + 30; //  Add the 30 seconds to our bleedout timer...