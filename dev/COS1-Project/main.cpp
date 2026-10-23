#include <iostream>
#include "Player.h"
#include "Game.h"

int main()
{
    try
    {
        Game game;

		game.Start();
    }
    catch (const std::exception& error)
    {
        std::cerr << "\nAn error occurred: "
            << error.what() << "\n";

        std::cerr << "Camp Woodwreath is closing safely.\n";

        return 1;
    }

    return 0;
}