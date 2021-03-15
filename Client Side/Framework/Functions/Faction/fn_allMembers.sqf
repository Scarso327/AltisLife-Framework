/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
scopeName "fn_allMembers";

_this params [
	["_faction", "", [""]]
];

(allPlayers select {
	_x getVariable ["faction", ""] isEqualTo _faction
})