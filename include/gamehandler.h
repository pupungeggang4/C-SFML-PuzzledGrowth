#pragma once
#include "includes.h"
#include "game.h"

int initGame(Game*);
void runGame(Game*);
void updateGame(Game*);
void renderGame(Game*);
void handleInputGame(Game*);
void quitGame(Game*);
