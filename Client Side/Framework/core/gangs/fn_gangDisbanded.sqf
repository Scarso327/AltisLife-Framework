/*
    File: fn_gangDisbanded.sqf
    Author: Bryan "Tonic" Boardwine

    Description:
    Notifies members that the gang has been disbanded.
*/
private "_group";
_group = param [0,grpNull,[grpNull]];
if (isNull _group) exitWith {}; //Fail horn please.
if (!isNull (findDisplay 2620)) then {closeDialog 2620};

hint "The leader has disbanded the group.";
[player] joinSilent (createGroup civilian);

if (units _group isEqualTo []) then {
    deleteGroup _group;
};
