#include "game.h"
int main(void)
{
    Game *game;
    game = new Game();
    game->load();
    game->run();
    delete game;
    return 0;
}
