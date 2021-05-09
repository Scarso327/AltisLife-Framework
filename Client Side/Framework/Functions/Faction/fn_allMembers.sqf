/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
scopeName "fn_allMembers";

_this params [
	["_faction", "", [""]],
	["_extra", { true }, [{}]]
];

(allPlayers select {
	_x getVariable ["faction", ""] isEqualTo _faction && { _extra }
})