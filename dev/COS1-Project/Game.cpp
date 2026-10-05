#include "Game.h"
#include <iostream>

void Game::Start()
{
    std::cout << "========================================\n";
    std::cout << "          CAMP WOODWREATH\n";
    std::cout << "========================================\n\n";

    std::cout << "A supernatural investigation.\n\n";

    std::cout << "Your current stats:\n\n";

    std::cout << "Hunting:    " << player.GetHunting() << "/10\n";
    std::cout << "Lore:       " << player.GetLore() << "/10\n";
    std::cout << "Perception: " << player.GetPerception() << "/10\n";
    std::cout << "Courage:    " << player.GetCourage() << "/10\n";
    std::cout << "Charisma:   " << player.GetCharisma() << "/10\n";
    std::cout << "Stealth:    " << player.GetStealth() << "/10\n";
}