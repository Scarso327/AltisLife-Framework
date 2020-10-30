#include "..\..\..\..\script_macros.hpp"
private _handled = false;

if ((_this select 1) isEqualTo 1 && (FF_curApp != "Home")) then {[23100, "Home"] call FF(switchApp);_handled = true;};
_handled;