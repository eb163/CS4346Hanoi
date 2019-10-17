#pragma once
#include "Tower.h"
#include "GameState.h"
/*

Functions to be used by the AI for evaluating individual Towers and overall Game State

*/

int scoreTower(Tower t);

int scoreGameState(GameState state);