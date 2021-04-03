/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
scopeName "fn_inStrings";

_this params [
	["_needle", "", [""]], 
	["_haystack", "", [""]]
];

((toLower _haystack) find (toLower _needle) > -1)