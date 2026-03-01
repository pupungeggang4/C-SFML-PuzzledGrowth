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
            memset(entity, 0, sizeof(Entity));

            entity->row = i;
            entity->col = j;
            entity->pos.x = j * 40.f;
            entity->pos.y = i * 40.f;
            entity->sprite = NULL;
            entity->sprite = sfSprite_create(texture);
            const sfIntRect rect = {{0, 0}, {40, 40}};
            sfSprite_setTextureRect(entity->sprite, rect);
            sfSprite_setPosition(entity->sprite, entity->pos);

            entity->type = data[col * i + j];
            if (data[col * i + j] == PLAYER) {
                entity->playerValid = 1;
                for (int k = 0; k < 10; k++) {
                    if (field->player[k] == NULL) {
                        field->player[k] = entity;
                        break;
                    }
                }
            } else if (data[col * i + j] == GOAL) {
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
            sfRenderWindow_drawSprite(game->window, field->cell[i][j].sprite, NULL);
        }
    }
}
