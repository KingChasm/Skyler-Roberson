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
    scenes.clear();

    CreateScenes();

    PlayScene(0);
}

void Game::CreateScenes()
{
    Scene introduction(
        "The Case",
        "Three people have disappeared near the small town of "
        "Grand Portage over the last two months.\n\n"
        "The police believe they simply got lost in the wilderness.\n"
        "You don't.\n\n"
        "All three disappearances have one thing in common:\n\n"
        "Camp Woodwreath."
    );

    introduction.AddChoice(
        "Visit the town first.",
        1
    );

    introduction.AddChoice(
        "Go directly to Camp Woodwreath.",
        2
    );

    scenes.push_back(introduction);


    Scene town(
        "Grand Portage",
        "You decide that walking blindly into the camp would be stupid.\n\n"
        "Grand Portage is small enough that strangers get noticed.\n"
        "A town with only six hundred or so people.\n"
        "If people have disappeared here, someone knows something."
    );

    town.AddChoice(
        "Return to the investigation.",
        -1
    );

    scenes.push_back(town);


    Scene camp(
        "Camp Woodwreath",
        "The wooden sign appears between the trees.\n\n"
        "CAMP WOODWREATH\n\n"
        "Beyond it, a narrow road disappears deep into the forest.\n\n"
        "You expected an old summer camp.\n"
        "You weren't expecting the property to be this large."
    );

    camp.AddChoice(
        "Return to the investigation.",
        -1
    );

    scenes.push_back(camp);
}

void Game::PlayScene(int sceneIndex)
{
    int currentScene = sceneIndex;

    while (currentScene != -1)
    {
        Scene& scene = scenes[currentScene];

        std::cout << "\n";
        std::cout << "============================================\n";
        std::cout << scene.GetTitle() << "\n";
        std::cout << "============================================\n\n";

        std::cout << scene.GetDescription() << "\n\n";

        // ============================================
        // Collectible Lore System
        // ============================================

        // Notebook Page 1 is discovered in Grand Portage.
        if (currentScene == 1)
        {
            if (player.CollectNotebookPage(1))
            {
                std::cout << "============================================\n";
                std::cout << "              LORE DISCOVERED!\n";
                std::cout << "============================================\n";
                std::cout << "You discovered Notebook Page 1!\n";
                std::cout << "Notebook Pages: "
                    << player.GetNotebookPageCount()
                    << "/3\n";
                std::cout << "============================================\n\n";
            }
        }

        // ============================================
        // Display Available Choices
        // ============================================

        const std::vector<Choice>& choices = scene.GetChoices();

        for (int i = 0; i < choices.size(); i++)
        {
            std::cout << "[" << i + 1 << "] "
                << choices[i].text << "\n";
        }

        std::cout << "\n> ";

        int choice;
        std::cin >> choice;

        if (choice >= 1 && choice <= choices.size())
        {
            currentScene = choices[choice - 1].nextScene;
        }
        else
        {
            std::cout << "\nInvalid choice.\n";
        }
    }
}