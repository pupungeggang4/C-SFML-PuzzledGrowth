#pragma once
#include "includes.h"
#include "field.h"

typedef struct Game {
    sfTexture* texture;
	sfRenderWindow* window;
	sfView* view;
    sfView* viewUI;
    int width, height;
	float frameCurrent, framePrevious, delta;

    Field field;
} Game;
