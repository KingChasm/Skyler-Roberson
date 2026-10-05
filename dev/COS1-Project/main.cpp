#include <iostream>
#include "Player.h"

int main()
{
    Player player;
    
    std::cout << "Initial Stats\n";
    std::cout << "==================\n";
    std::cout << "Hunting: " << player.GetHunting() << "/10\n";
    std::cout << "Lore: " << player.GetLore() << "/10\n";
    std::cout << "Perception: " << player.GetPerception() << "/10\n";
    std::cout << "Courage: " << player.GetCourage() << "/10\n";
    std::cout << "Charisma: " << player.GetCharisma() << "/10\n";
    std::cout << "Stealth: " << player.GetStealth() << "/10\n";

    std::cout << "\n";

    player.IncreaseLore();
	player.IncreasePerception();

    std::cout << "After Learning Something\n";
    std::cout << "------------------------\n";
    std::cout << "Lore: " << player.GetLore() << "/10\n";
    std::cout << "Perception: " << player.GetPerception() << "/10\n";
    return 0;
}