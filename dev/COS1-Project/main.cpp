#include <iostream>
#include "Player.h"

int main()
{
    Player player;

    std::cout << "Hunting: " << player.hunting << "/10\n";
    std::cout << "Lore: " << player.lore << "/10\n";
    std::cout << "Perception: " << player.perception << "/10\n";
    std::cout << "Courage: " << player.courage << "/10\n";
    std::cout << "Charisma: " << player.charisma << "/10\n";
    std::cout << "Stealth: " << player.stealth << "/10\n";

    return 0;
}