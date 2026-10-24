#include "Game.h"
#include "ConsoleColors.h"
#include <iostream>
#include <limits>
#include <vector>
#include <string>
#include <stdexcept>

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
            ConsoleColors::ResetColor();
            running = false;
            break;
        }
    }
}

void Game::ShowTitleScreen()
{
    std::cout << "\n";

    // Dark forest atmosphere
    ConsoleColors::SetColor(ConsoleColors::Green);

    std::cout << "============================================\n";
    std::cout << "                                            \n";
    std::cout << "          C A M P  W O O D W R E A T H     \n";
    std::cout << "                                            \n";

    // Supernatural theme
    ConsoleColors::SetColor(ConsoleColors::Purple);

    std::cout << "              A Horror Story                \n";
    std::cout << "                                            \n";

    ConsoleColors::SetColor(ConsoleColors::Green);

    std::cout << "============================================\n";
    std::cout << "\n";

    // Menu options
    ConsoleColors::SetColor(ConsoleColors::Cyan);

    std::cout << "[1] New Game\n";
    std::cout << "[2] Quit\n";
    std::cout << "\n";

    // Restore normal text
    ConsoleColors::ResetColor();
}

void Game::StartNewGame()
{
    mInvestigatedGrandPortage = false; // Reset story milestone
    mInvestigatedRangerStation = false;
    mNotebookLoreAwarded = false;
    mInvestigatedTracks = false;
    mIntroducedToDirector = false;
	mPretendToBeCamper = false;

    mDirectorSuspicion = 0;
    mAskedAboutMissingPeople = false;
    mReassuredDirector = false;
    mConfrontedDirector = false;
    mRepeatedMissingPeopleQuestion = false;
    mDiplomaticResponseUsed = false;
    mDiscoveredDirectorClue = false;

	player = Player(); // Reset player stats and collected notebook pages

    scenes.clear();

    CreateScenes();

    PlayScene(0);
}

void Game::PlayScene(int sceneIndex)
{
    int currentScene = sceneIndex;

    while (currentScene != -1)
    {
        // Prevent access to invalid scene indexes.
        if (currentScene < 0 ||
            currentScene >= static_cast<int>(scenes.size()))
        {
            std::cout << "\nERROR: Invalid scene index detected.\n";
            std::cout << "Returning to the main menu...\n\n";
            break;
        }

        const Scene& scene = scenes[currentScene];

        // ============================================
        // Display Scene with Atmospheric Colors
        // ============================================

        std::cout << "\n";

        // Determine the scene's color.
        WORD sceneColor = ConsoleColors::Green;

        // Special colors for the three endings.
        if (currentScene == 15)
        {
            // Successful escape
            sceneColor = ConsoleColors::Green;
        }
        else if (currentScene == 18)
        {
            // Abandoned investigation
            sceneColor = ConsoleColors::Yellow;
        }
        else if (currentScene == 19)
        {
            // Fatal ending
            sceneColor = ConsoleColors::Red;
        }

        // Display the scene title.
        ConsoleColors::SetColor(sceneColor);

        std::cout << "============================================\n";
        std::cout << scene.GetTitle() << "\n";
        std::cout << "============================================\n\n";

        // Color the ending narration to match its outcome.
        if (currentScene == 15 ||
            currentScene == 18 ||
            currentScene == 19)
        {
            ConsoleColors::SetColor(sceneColor);
        }
        else
        {
            ConsoleColors::ResetColor();
        }

        std::cout << scene.GetDescription() << "\n\n";

        // Restore normal color for subsequent messages.
        ConsoleColors::ResetColor();

        // Process lore discoveries, milestones, and story events.
		HandleSceneEvents(currentScene);
        

        // ============================================
        // Display Available Choices
        // ============================================

        std::vector<Choice> availableChoices = GetAvailableChoices(currentScene);
        
        ConsoleColors::SetColor(ConsoleColors::Cyan);

        for (int i = 0; i < static_cast<int>(availableChoices.size()); i++)
        {
            std::cout << "[" << i + 1 << "] "
                << availableChoices[i].text << "\n";
        }

        // Highlight the Player Status option.
        ConsoleColors::SetColor(ConsoleColors::Red);

        std::cout << "\n[0] View Player Status\n";

        // Restore normal color before accepting input.
        ConsoleColors::ResetColor();

        std::cout << "\n";

        int choice = GetValidatedChoice(
            0,
            static_cast<int>(availableChoices.size())
        );

        // Option 0 opens the Player Status screen.
        if (choice == 0)
        {
            ShowPlayerStatus();

            std::cout << "\nPress Enter to return to the story...";

            // Wait for the player to press Enter.
            std::string pauseInput;
            std::getline(std::cin, pauseInput);

            // Redisplay the current scene.
            continue;
        }

        // Process regular story choices.
        currentScene = availableChoices[choice - 1].nextScene;

    }
}

int Game::GetValidatedChoice(int minimum, int maximum)
{
    std::string input;

    while (true)
    {
        std::cout << "> ";

        if (!std::getline(std::cin, input))
        {
            throw std::runtime_error("Input stream closed");
        }

        try
        {
            size_t position = 0;
            int choice = std::stoi(input, &position);

            // Reject extra characters such as "2abc".
            if (position != input.length())
            {
                throw std::invalid_argument("Invalid characters");
            }

            if (choice >= minimum && choice <= maximum)
            {
                return choice;
            }

            std::cout << "\nInvalid choice. Enter a number between "
                << minimum << " and " << maximum << ".\n\n";
        }
        catch (const std::invalid_argument&)
        {
            std::cout << "\nInvalid input. Please enter a whole number.\n\n";
        }
        catch (const std::out_of_range&)
        {
            std::cout << "\nThat number is too large or too small.\n\n";
        }
    }
}

// ============================================
// Player Status Screen (Most useful thing I've made imo)
// ============================================

void Game::ShowPlayerStatus() const
{
    std::cout << "\n";

    // Player Status heading
    ConsoleColors::SetColor(ConsoleColors::Purple);

    std::cout << "============================================\n";
    std::cout << "               PLAYER STATUS\n";
    std::cout << "============================================\n\n";

    // Character Stats
    ConsoleColors::SetColor(ConsoleColors::Cyan);

    std::cout << "CHARACTER STATS\n";
    std::cout << "--------------------------------------------\n";
    std::cout << "--------------------------------------------\n";

    std::cout << "Hunting:    " << player.GetHunting() << "/10\n";
    std::cout << "Lore:       " << player.GetLore() << "/10\n";
    std::cout << "Perception: " << player.GetPerception() << "/10\n";
    std::cout << "Courage:    " << player.GetCourage() << "/10\n";
    std::cout << "Charisma:   " << player.GetCharisma() << "/10\n";
    std::cout << "Stealth:    " << player.GetStealth() << "/10\n";
    ConsoleColors::ResetColor();

    // ============================================
    // Collected Lore
    // ============================================

    std::cout << "\n";

    ConsoleColors::SetColor(ConsoleColors::Yellow);

    std::cout << "COLLECTED LORE\n";
    std::cout << "--------------------------------------------\n";
    std::cout << "Notebook Pages: "
        << player.GetNotebookPageCount()
        << "/3\n";

    ConsoleColors::ResetColor();

    // Display individual notebook pages.
    for (int page = 1; page <= 3; page++)
    {
        std::cout << "Page " << page << ": ";

        if (player.HasNotebookPage(page))
        {
            ConsoleColors::SetColor(ConsoleColors::Green);
            std::cout << "Collected\n";
        }
        else
        {
            ConsoleColors::SetColor(ConsoleColors::Red);
            std::cout << "Missing\n";
        }

        ConsoleColors::ResetColor();
    }

    // Completed notebook message.
    if (player.HasCompleteNotebook())
    {
        ConsoleColors::SetColor(ConsoleColors::Yellow);

        std::cout << "\n";
        std::cout << "NOTEBOOK COMPLETE!\n";
        std::cout << "Hidden Lodge Entrance Unlocked.\n";

        ConsoleColors::ResetColor();
    }

    // ============================================
    // Camp Relationships
    // ============================================

    std::cout << "\n";

    ConsoleColors::SetColor(ConsoleColors::Cyan);

    std::cout << "CAMP RELATIONSHIPS\n";
    std::cout << "--------------------------------------------\n";

    ConsoleColors::ResetColor();

    std::cout << "Director Woodwreath's Suspicion: "
        << mDirectorSuspicion << "/10\n";

    // Confrontation overrides the director's attitude.
    if (mConfrontedDirector)
    {
        ConsoleColors::SetColor(ConsoleColors::Red);
        std::cout << "Attitude: Hostile\n";
    }
    else if (mDirectorSuspicion <= 2)
    {
        ConsoleColors::SetColor(ConsoleColors::Green);
        std::cout << "Attitude: Friendly\n";
    }
    else if (mDirectorSuspicion <= 5)
    {
        ConsoleColors::SetColor(ConsoleColors::Yellow);
        std::cout << "Attitude: Cautious\n";
    }
    else if (mDirectorSuspicion <= 8)
    {
        ConsoleColors::SetColor(ConsoleColors::Orange);
        std::cout << "Attitude: Suspicious\n";
    }
    else
    {
        ConsoleColors::SetColor(ConsoleColors::Red);
        std::cout << "Attitude: Hostile\n";
    }
    ConsoleColors::ResetColor();

    ConsoleColors::SetColor(ConsoleColors::Purple);
    std::cout << "\n";
    std::cout << "============================================\n";
    ConsoleColors::ResetColor();
}

std::vector<Choice> Game::GetAvailableChoices(int sceneIndex)
{
	int currentScene = sceneIndex;
	Scene& scene = scenes[currentScene];

    // Create a temporary list of choices for this visit.
    std::vector<Choice> availableChoices = scene.GetChoices();
    
    // ============================================
    // Director Relationship - Repeated Questions
    // ============================================

    if (mAskedAboutMissingPeople)
    {
        // Replace the original missing-people question
        // with a follow-up conversation.

        for (Choice& choice : availableChoices)
        {
            if (choice.nextScene == 10)
            {
                choice.nextScene = 29;
                choice.text = "Bring up the disappearances again.";
            }
        }
    }

    // ============================================
    // Director Relationship - Hostile Conversation
    // ============================================

    if (currentScene == 7 && mConfrontedDirector)
    {
        availableChoices.clear();

        availableChoices.push_back({
            "Leave the lodge before the director loses his patience.",
            2
            });

        return availableChoices;
    }

    // ============================================
    // Director Relationship - Lodge Access
    // ============================================

    if (currentScene == 2 && mConfrontedDirector)
    {
        // Remove the normal conversation option.
        for (auto it = availableChoices.begin();
            it != availableChoices.end();)
        {
            if (it->nextScene == 7)
            {
                it = availableChoices.erase(it);
            }
            else
            {
                ++it;
            }
        }

        // Replace it with a hostile encounter.
        availableChoices.push_back({
            "Approach the lodge despite the director's warning.",
            13
            });
    }

    // If the player has completed the notebook,
    // unlock the secret entrance at the campgrounds.
    if (currentScene == 2 && player.HasCompleteNotebook())
    {
        availableChoices.push_back({
            "Search for the hidden entrance beneath the lodge.",
            5
            });
    }

    //Ranger Station, perception check
    if (currentScene == 4 &&
        player.CheckStat(PlayerStat::Perception, 1))
    {
        availableChoices.push_back({
            "[Perception] Investigate the unusual tracks.",
            6
            });
    }

	//Underground Passage, hunting skill check
    if (currentScene == 14 &&
        player.CheckStat(PlayerStat::Hunting, 1))
    {
        availableChoices.push_back({
            "[Hunting] Examine the claw marks for signs of a creature.",
            16
            });
    }
        
    // Underground Passage - Stealth Skill Check

    if (currentScene == 14 &&
        player.CheckStat(PlayerStat::Stealth, 1))
    {
        availableChoices.push_back({
            "[Stealth] Hide from the approaching creature.",
            17
            });
    }

    // Director Woodwreath, charisma check
    if (currentScene == 10 &&
        player.CheckStat(PlayerStat::Charisma, 1) &&
        !mReassuredDirector)
    {
        availableChoices.push_back({
            "[Charisma] Reassure the director.",
            11
            });
    }

    // Director Woodwreath, Confrontation
    if (currentScene == 10 &&
        mDirectorSuspicion >= 2 &&
        !mReassuredDirector)
    {
        availableChoices.push_back({
            "[Suspicion] Challenge the director's explanation.",
            12
            });
    }

    // Underground Passage - Courage Skill Check
    if (currentScene == 14 &&
        player.CheckStat(PlayerStat::Courage, 1))
    {
        availableChoices.push_back({
            "[Courage] Stand your ground against the approaching creature.",
            20
            });
    }

    // Signs of the Beast - Lore Skill Check
    if (currentScene == 14 &&
        player.CheckStat(PlayerStat::Lore, 1))
    {
        availableChoices.push_back({
            "[Lore] Recall your father's notes about werewolves.",
            21
            });
    }

    // Director Woodwreath - Perception Skill Check
    if (currentScene == 10 &&
        player.CheckStat(PlayerStat::Perception, 1))
    {
        availableChoices.push_back({
            "[Perception] Study the director's unusual behavior.",
            22
            });
    }

    // Camp Director - Charisma Skill Check
    if (currentScene == 7 &&
        player.CheckStat(PlayerStat::Charisma, 1))
    {
        availableChoices.push_back({
            "[Charisma] Persuade the director to discuss the camp's history.",
            23
            });
    }

    // ============================================
    // Repeated Questions - Charisma Skill Check
    // ============================================

    if (currentScene == 29 &&
        player.CheckStat(PlayerStat::Charisma, 1) &&
        !mDiplomaticResponseUsed)
    {
        availableChoices.push_back({
            "[Charisma] Calm the director down.",
            30
            });
    }

    

    // ============================================
    // Repeated Questions - Perception Skill Check
    // ============================================

    if (currentScene == 29 &&
        player.CheckStat(PlayerStat::Perception, 1))
    {
        availableChoices.push_back({
            "[Perception] Study the director's reaction.",
            31
            });
    }

    // ============================================
    // Repeated Questions - Courage Skill Check
    // ============================================

    if (currentScene == 29 &&
        player.CheckStat(PlayerStat::Courage, 1) &&
        !mConfrontedDirector)
    {
        availableChoices.push_back({
            "[Courage] Refuse to back down.",
            32
            });
    }

    // ============================================
    // Director Clue - Ranger Station Investigation
    // ============================================

    if (currentScene == 4 && mDiscoveredDirectorClue)
    {
        availableChoices.push_back({
            "[Clue] Investigate the reddish soil near the station.",
            33
            });
    }
    
    return availableChoices;
}