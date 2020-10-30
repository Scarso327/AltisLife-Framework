/*
    File: fn_calNtPos.sqf
    Author: Sig

    Original Authors
      cptnnick
      Whalenator

    Credit to them guys
    See this post
    https://forums.bohemia.net/forums/topic/206072-multi-line-text-in-drawicon3d/?tab=comments#comment-3204731

    Description: Calculates three draw3d text positions

    Arguments
      0 (REQUIRED) (ARRAY) Orignal position of the middle draw3d text
      1 (REQUIRED) (ARRAY) Players position
      2 (OPTIONAL) (NUMBER) Base spacing between the text

    Return
      (ARRAY):
        0 (NUMBER) Top text position
        1 (NUMBER) Middle text position
        2 (NUMBER) Bottom text position
*/

params [
  [ "_targetPos", [], [ [] ] ],
  [ "_myPos", [], [ [] ] ],
  [ "_spacing", 0.01, [ 0 ] ]
];

private _distance = _targetPos distance _myPos;

private _zoom = (
  [ 0.5, 0.5 ]
  distance2D
  worldToScreen
  positionCameraToWorld
  [ 0, 3, 4 ]
) * (
  getResolution
  select 5
) / 2;

private _dir = _targetPos vectorDiff _myPos;
private _myDir = _myPos vectorFromTo ( positionCameraToWorld [ 0, 0, 1 ] );

private _cross = _myDir vectorCrossProduct ( vectorUp player );

private _posNormalized = vectorNormalized ( _cross vectorCrossProduct _dir );
private _upNorm = _posNormalized vectorMultiply ( _spacing * _distance / _zoom );
private _downNorm = _upNorm vectorMultiply -1;

private _finalUpPos = _targetPos vectorAdd _upNorm;
private _finalDownPos = _targetPos vectorAdd _downNorm;

[ _finalUpPos, _targetPos, _finalDownPos ]