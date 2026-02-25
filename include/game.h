#pragma once
#include "includes.h"

typedef struct Game {
	sfRenderWindow* window;
	sfView* view;
	sfView* viewUI;
	float frameCurrent, framePrevious, delta;
} Game;
