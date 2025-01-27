/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
scopeName "fn_preInitVars";

ULP_eachFrameEventsHandles = [];
ULP_eachFrameEventsHandlers = [];
ULP_eachFrameEventsHandlersToRemove = [];

ULP_executeNextFrameBufferA = [];
ULP_executeNextFrameBufferB = [];
ULP_nextFrameNumber = diag_frameNo + 1;

ULP_waitExecute = [];
ULP_waitUntilExecute = [];

ULPEvent_TaserFired = false;