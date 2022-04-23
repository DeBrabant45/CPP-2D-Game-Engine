#include "Game/Game.h"
#include "Game/GameWindow.h"

int main(void)
{
    Game game{ "NightFall" };
    game.Start();
    while (!game.IsGameClosed())
    {
        game.Update();
    }
    return 0;
}