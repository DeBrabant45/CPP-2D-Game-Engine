#include "Game/Game.h"
#include "Game/GameWindow.h"

int main(void)
{
    Game game{ "NightFall" };
    while (!game.IsGameClosed())
    {
        game.Tick();
    }
    return 0;
}