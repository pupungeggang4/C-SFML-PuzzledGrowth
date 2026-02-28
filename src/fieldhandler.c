#include "includes.h"
#include "entity.h"
#include "field.h"

void loadField(Field* field, int* data, int row, int col) {
    for (int k = 0; k < 10; k++) {
        field->player[k] = NULL;
    }
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            memset(&field->cell[i][j], 0, sizeof(Entity));
            field->cell[i][j].type = data[col * i + j];
            if (data[col * i + j] == PLAYER) {
                field->cell[i][j].playerValid = 1;
                for (int k = 0; k < 10; k++) {
                    if (field->player[k] == NULL) {
                        field->player[k] = &field->cell[i][j];
                        break;
                    }
                }
            }
        }
    }
}
