#include "Game.h"
#include <iostream>
#include <limits>

void Game::Start()
{
    bool running = true;

    while (running)
    {
        ShowTitleScreen();

        // Get a valid menu choice (1 or 2).
        int choice = GetValidatedChoice(1, 2);

        switch (choice)
        {
        case 1:
            StartNewGame();
            break;

        case 2:
            running = false;
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

    introduction.AddChoice("Visit the town first.", 1);
    introduction.AddChoice("Go directly to Camp Woodwreath.", 2);

    scenes.push_back(introduction);

	// ============================================
	// Scene 1: Grand Portage
	// ============================================
    Scene town(
        "Grand Portage",
        "You decide that walking blindly into the camp would be stupid.\n\n"
        "Grand Portage is small enough that strangers get noticed.\n"
        "A town with only six hundred or so people.\n"
        "If people have disappeared here, someone knows something."
    );

	town.AddChoice("Travel to Camp Woodwreath.", 2);
    town.AddChoice("End the investigation.", -1);

    scenes.push_back(town);

	// ============================================
	// Scene 2: Camp Woodwreath
	// ============================================
    Scene camp(
        "Camp Woodwreath",
        "The wooden sign appears between the trees.\n\n"
        "CAMP WOODWREATH\n\n"
        "Beyond it, a narrow road disappears deep into the forest.\n\n"
        "You expected an old summer camp.\n"
        "You weren't expecting the property to be this large.\n\n"
        "An old supply shed stands near the treeline."
        " Its wood is darkened from years of dry rotting and shadows pool beneath the door's wooden frame.\n"
        "Its door hangs slightly open."
    );
    camp.AddChoice("Investigate the abandoned supply shed.", 3);
    camp.AddChoice("Follow the forest trail.", 4);
    camp.AddChoice("Return to Grand Portage.", 1);
    camp.AddChoice("End the investigation.", -1);

    scenes.push_back(camp);

	// ============================================
	// Scene 3: Supply Shed
	// ============================================
	Scene supplyShed("The Supply Shed",
        "You approach the abandoned supply shed.\n\n"
        "The wooden door groans as you push it open.\n"
        "Dust covers the shelves, and rusted tools hang from the walls.\n\n"
        "Something catches your attention.\n\n"
        "A torn notebook page lies beneath an old toolbox.\n"
        "The handwriting looks strangely familiar."
    );

    supplyShed.AddChoice("Return to the campgrounds.", 2);

    scenes.push_back(supplyShed);

	// ============================================
	// Scene 4: Ranger Station
	// ============================================
    Scene rangerStation(
		"The Abandoned Ranger Station",
        "A narrow trail lead you deeper into the forest.\n\n"
        "Eventually, you discover an old ranger station.\n"
        "The windows are boarded shut, and the front door\n"
        "has been torn partially from its hinges.\n\n"
        "Deep claw marks scar the wooden walls.\n\n"
        "Inside, a desk lies overturned.\n"
        "Among the scattered papers, you notice a familiar\n"
        "piece of handwriting.\n\n"
        "Another page from the notebook."
    );

    rangerStation.AddChoice(
        "Return to the campgrounds.",
        2
    );

    scenes.push_back(rangerStation);

    // ============================================
    // Scene 5 - Hidden Lodge Entrance
    // ============================================

    Scene hiddenEntrance(
        "Beneath the Main Lodge",
        "The reconstructed notebook leads you to the\n"
        "northern side of the main lodge.\n\n"
        "Behind a stack of firewood, you discover a\n"
        "rusted metal hatch concealed beneath the dirt.\n\n"
        "The smell coming from below is unmistakable.\n\n"
        "Blood.\n\n"
        "Whatever is happening at Camp Woodwreath,\n"
        "you are getting dangerously close to the truth."
    );

    hiddenEntrance.AddChoice(
        "Return to the campgrounds.",
        2
    );

    scenes.push_back(hiddenEntrance);
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

		if (currentScene == 3)
		{
			if (player.CollectNotebookPage(2))
			{
				std::cout << "============================================\n";
				std::cout << "              LORE DISCOVERED!\n";
				std::cout << "============================================\n";
				std::cout << "You discovered Notebook Page 2!\n";
				std::cout << "Notebook Pages: "
					<< player.GetNotebookPageCount()
					<< "/3\n";
				std::cout << "============================================\n\n";
			}
		}

        if (currentScene == 4)
        {
            if (player.CollectNotebookPage(3))
            {
                std::cout << "============================================\n";
                std::cout << "              LORE DISCOVERED!\n";
                std::cout << "============================================\n";
                std::cout << "You discovered Notebook Page 3!\n";
                std::cout << "Notebook Pages: "
                    << player.GetNotebookPageCount()
                    << "/3\n";

                if (player.HasCompleteNotebook())
                {
                    std::cout << "\n";
                    std::cout << "You have reconstructed the notebook!\n";
                    std::cout << "Not much yet but enough to to gather some information.\n";
                    std::cout << "The pages contain disturbing information\n";
                    std::cout << "about Camp Woodwreath and its inhabitants.\n";
                }

                std::cout << "============================================\n\n";
            }
        }

        // ============================================
        // Display Available Choices
        // ============================================

        // Create a temporary list of choices for this visit.
        std::vector<Choice> availableChoices = scene.GetChoices();

        // If the player has completed the notebook,
        // unlock the secret entrance at the campgrounds.
        if (currentScene == 2 && player.HasCompleteNotebook())
        {
            availableChoices.push_back({
                "Search for the hidden entrance beneath the lodge.",
                5
                });
        }

        // Display all currently available choices.
        for (int i = 0; i < static_cast<int>(availableChoices.size()); i++)
        {
            std::cout << "[" << i + 1 << "] "
                << availableChoices[i].text << "\n";
        }

        std::cout << "\n";

        int choice = GetValidatedChoice(
            1,
            static_cast<int>(availableChoices.size())
        );

        currentScene = availableChoices[choice - 1].nextScene;
    }
}

int Game::GetValidatedChoice(int minimum, int maximum)
{
    int choice;

    while (true)
    {
        std::cout << "> ";

        if (std::cin >> choice)
        {
            if (choice >= minimum && choice <= maximum)
            {
                return choice;
            }

            std::cout << "\nInvalid choice. Please select a number between "
                << minimum << " and " << maximum << ".\n\n";
        }
        else
        {
            std::cout << "\nInvalid input. Please enter a number.\n\n";

            // Reset the failed input state.
            std::cin.clear();
        }

        // Remove leftover characters from the input buffer.
        std::cin.ignore(
            std::numeric_limits<std::streamsize>::max(),
            '\n'
        );
    }
}