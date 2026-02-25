#include "includes.h"
#include "game.h"
#include "gamehandler.h"

int initGame(Game* game) {
    sfVideoMode desktopMode = sfVideoMode_getDesktopMode();
    if (desktopMode.size.x > 2500) {
        game->width = 1600;
        game->height = 1200;
    } else if (desktopMode.size.x > 2000) {
        game->width = 1200;
        game->height = 900;
    } else {
        game->width = 800;
        game->height = 600;
    }

	const sfVideoMode mode = {{game->width, game->height}, 32};
	game->window = sfRenderWindow_create(mode, "Puzzled Growth", sfResize | sfClose, sfWindowed, NULL);

    if (!game->window)
		return 0;

    sfFloatRect viewRect = {{0.f, 0.f}, {800.f, 600.f}};
    sfFloatRect viewRectUI = {{0.f, 0.f}, {800.f, 600.f}};
    game->view = sfView_createFromRect(viewRect);
    game->viewUI = sfView_createFromRect(viewRectUI);
    if (!game->view || !game->viewUI) {
        sfRenderWindow_destroy(game->window);
        return 0;
    }
    sfRenderWindow_setView(game->window, game->viewUI);

    return 1;
}

void runGame(Game* game) {
    while (sfRenderWindow_isOpen(game->window)) {
        handleInputGame(game);
        updateGame(game);
        renderGame(game);
    }
}

void updateGame(Game* game) {
}

void renderGame(Game* game) {
    sfRenderWindow_clear(game->window, sfWhite);
    sfRenderWindow_display(game->window);
}

void handleInputGame(Game* game) {
    sfEvent event;
    while (sfRenderWindow_pollEvent(game->window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(game->window);
    }
}

void quitGame(Game* game) {
    sfView_destroy(game->view);
    sfView_destroy(game->viewUI);
	sfRenderWindow_destroy(game->window);
}
