#include "includes.h"
#include "asset.h"
#include "entity.h"
#include "field.h"
#include "game.h"

void loadField(Field* field, int* data, int row, int col) {
    field->row = row;
    field->col = col;
    field->goal = NULL;
    for (int k = 0; k < 10; k++) {
        field->player[k] = NULL;
    }
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            Entity* entity = &field->cell[i][j];
            int d = data[col * i + j];
            memset(entity, 0, sizeof(Entity));

            entity->row = i;
            entity->col = j;
            entity->pos.x = j * 40.f;
            entity->pos.y = i * 40.f;
            entity->sprite = NULL;
            entity->sprite = sfSprite_create(texture);
            sfSprite_setPosition(entity->sprite, entity->pos);
            sfIntRect rect = {{0, 0}, {40, 40}};
            if (d == WALL) {
                rect.position.x = 0;
                rect.position.y = 0;
            } else if (d == GOAL) {
                rect.position.x = 40;
                rect.position.y = 80;
            }
            sfSprite_setTextureRect(entity->sprite, rect);

            entity->type = d;
            if (d == PLAYER) {
                entity->playerValid = 1;
                for (int k = 0; k < 10; k++) {
                    if (field->player[k] == NULL) {
                        field->player[k] = entity;
                        break;
                    }
                }
            } else if (d == GOAL) {
                if (field->goal != NULL) {
                    field->goal = &field->cell[i][j];
                }
            }
        }
    }
}

void renderField(Game* game, Field* field) {
    int row = field->row;
    int col = field->col;

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (field->cell[i][j].type != EMPTY) {
                sfRenderWindow_drawSprite(game->window, field->cell[i][j].sprite, NULL);
            }
        }
    }
}
