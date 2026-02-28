#include "includes.h"
#include "entity.h"

typedef struct Field {
    int row, col;
    Entity cell[10][10];
    Entity* player[10];
} Field;
