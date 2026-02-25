#pragma once
#include "includes.h"

typedef struct Game {
	sfRenderWindow* window;
	sfView* view;
    sfView* viewUI;
    int width, height;
	float frameCurrent, framePrevious, delta;
} Game;
