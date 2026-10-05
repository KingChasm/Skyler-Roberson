#include "Game.h"
#include <iostream>

void Game::Start()
{
    bool running = true;

    while (running)
    {
        ShowTitleScreen();

        int choice;

        std::cout << "> ";
        std::cin >> choice;

        switch (choice)
        {
        case 1:
            StartNewGame();
            break;

        case 2:
            running = false;
            break;

        default:
            std::cout << "\nInvalid choice.\n";
            break;
        }
    }
}

void Game::ShowTitleScreen()
{
    std::cout << "\n";
    std::cout << "============================================\n";
    std::cout << "                                            \n";
    std::cout << "          C A M P  W O O D W R E A T H     \n";
    std::cout << "                                            \n";
    std::cout << "              A Horror Story                \n";
    std::cout << "                                            \n";
    std::cout << "============================================\n";
    std::cout << "\n";

    std::cout << "[1] New Game\n";
    std::cout << "[2] Quit\n";
    std::cout << "\n";
}

void Game::StartNewGame()
{
    std::cout << "\n";
    std::cout << "============================================\n";
    std::cout << "              NEW GAME                      \n";
    std::cout << "============================================\n";
    std::cout << "\n";

    std::cout << "The investigation begins...\n\n";
}