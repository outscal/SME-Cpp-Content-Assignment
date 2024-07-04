#include "Main/GameService.h"

int main()
{
    using namespace Main;

    GameService* game_service = new GameService();
    game_service->ignite();

    while (game_service->isRunning())
    {
        game_service->update();
        game_service->render();
    }

    return 0;
}