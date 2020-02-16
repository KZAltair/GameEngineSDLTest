#include "Game.h"

int main(int argc, char* args[])
{
    auto game = std::make_unique<Game>();

    game->Initialize(Game::WindowWidth, Game::WindowHeight);

    while (game->IsRunning())
    {
        game->ProcessInput();
        game->Update();
        game->Render();
    }

    game->Destroy();

    return 0;
}