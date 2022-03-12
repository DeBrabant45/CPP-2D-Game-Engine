#include "Game/Game.h"
#include "Game/GameWindow.h"

int main(void)
{
    const int screenWidth = 1200;
    const int screenHeight = 800;
    Game game{ "NightFall" };
    while (!game.IsGameClosed())
    {
        game.Tick();
    }
    return 0;
}