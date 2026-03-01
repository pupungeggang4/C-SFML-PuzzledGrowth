#pragma once
#include "includes.h"

enum TypeTag {
    EMPTY, PLAYER, WATER, FLOWER, VINE, WALL, GOAL
};

typedef struct Entity {
    int type;
    int playerValid;
    int row, col;
    int solid, pushable;
    sfVector2f pos;
    sfSprite* sprite;
} Entity;
