#include "game.h"
#include <memory>
int main(void)
{
    std::unique_ptr<Game> game(std::make_unique<Game>());
    game->load();
    game->run();
    return 0;
}
