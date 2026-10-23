#include "Game.h"
#include <iostream>
#include "ConsoleColors.h"

void Game::HandleSceneEvents(int sceneIndex)
{
    int currentScene = sceneIndex;

    // ============================================
        // Collectible Lore System
        // ============================================

        // Notebook Page 1 is discovered in Grand Portage.
    if (currentScene == 1)
    {
        if (player.CollectNotebookPage(1))
        {
            ConsoleColors::SetColor(ConsoleColors::Yellow);
            std::cout << "============================================\n";
            std::cout << "              LORE DISCOVERED!\n";
            std::cout << "============================================\n";
            std::cout << "You discovered Notebook Page 1!\n";
            std::cout << "Notebook Pages: "
                << player.GetNotebookPageCount()
                << "/3\n";
            std::cout << "============================================\n\n";
            ConsoleColors::ResetColor();
        }
    }

    if (currentScene == 1 && !mInvestigatedGrandPortage)
    {
        player.IncreasePerception();

        mInvestigatedGrandPortage = true;

        ConsoleColors::SetColor(ConsoleColors::Green);
        std::cout << "============================================\n";
        std::cout << "           MILESTONE REACHED!\n";
        std::cout << "============================================\n";
        std::cout << "You carefully investigate Grand Portage.\n";
        std::cout << "Your awareness of the surroundings improves.\n\n";
        std::cout << "Perception increased by 1!\n";
        std::cout << "Current Perception: "
            << player.GetPerception() << "/10\n";
        std::cout << "============================================\n\n";
        ConsoleColors::ResetColor();
    }

    if (currentScene == 3)
    {
        if (player.CollectNotebookPage(2))
        {
            ConsoleColors::SetColor(ConsoleColors::Yellow);
            std::cout << "============================================\n";
            std::cout << "              LORE DISCOVERED!\n";
            std::cout << "============================================\n";
            std::cout << "You discovered Notebook Page 2!\n";
            std::cout << "Notebook Pages: "
                << player.GetNotebookPageCount()
                << "/3\n";
            std::cout << "============================================\n\n";
            ConsoleColors::ResetColor();
        }
    }

    if (currentScene == 4)
    {
        if (player.CollectNotebookPage(3))
        {
            ConsoleColors::SetColor(ConsoleColors::Yellow);
            std::cout << "============================================\n";
            std::cout << "              LORE DISCOVERED!\n";
            std::cout << "============================================\n";
            std::cout << "You discovered Notebook Page 3!\n";
            std::cout << "Notebook Pages: "
                << player.GetNotebookPageCount()
                << "/3\n";

            // ============================================
            // Milestone - Complete Father's Notebook
            // ============================================

            if (player.HasCompleteNotebook() && !mNotebookLoreAwarded)
            {
                // Prevent the reward from being earned again.
                mNotebookLoreAwarded = true;

                // Increase the player's supernatural knowledge.
                player.IncreaseLore();

                std::cout << "============================================\n";
                std::cout << "           NOTEBOOK COMPLETE!\n";
                std::cout << "============================================\n";

                std::cout << "You have reconstructed your father's notebook!\n";
                std::cout << "The pages contain disturbing information\n";
                std::cout << "about Camp Woodwreath and its inhabitants.\n\n";

                std::cout << "Your understanding of supernatural creatures grows.\n\n";

                std::cout << "Lore increased by 1!\n";
                std::cout << "Current Lore: "
                    << player.GetLore() << "/10\n";

                std::cout << "Hidden Lodge Entrance Unlocked!\n";

                std::cout << "============================================\n\n";
            }

            std::cout << "============================================\n\n";
            ConsoleColors::ResetColor();
        }
    }

    if (currentScene == 4 && !mInvestigatedRangerStation)
    {
        player.IncreaseCourage();

        mInvestigatedRangerStation = true;

        ConsoleColors::SetColor(ConsoleColors::Green);
        std::cout << "============================================\n";
        std::cout << "           MILESTONE REACHED!\n";
        std::cout << "============================================\n";
        std::cout << "You explore the abandoned ranger station.\n";
        std::cout << "Despite the evidence of something dangerous,\n";
        std::cout << "you refuse to abandon the investigation.\n\n";
        std::cout << "Courage increased by 1!\n";
        std::cout << "Current Courage: "
            << player.GetCourage() << "/10\n";
        std::cout << "============================================\n\n";
        ConsoleColors::ResetColor();
    }

    if (currentScene == 6 && !mInvestigatedTracks)
    {
        player.IncreaseHunting();

        mInvestigatedTracks = true;

        ConsoleColors::SetColor(ConsoleColors::Green);
        std::cout << "============================================\n";
        std::cout << "           MILESTONE REACHED!\n";
        std::cout << "============================================\n";
        std::cout << "You study the unusual tracks carefully.\n";
        std::cout << "Your knowledge of tracking dangerous creatures\n";
        std::cout << "has improved.\n\n";
        std::cout << "Hunting increased by 1!\n";
        std::cout << "Current Hunting: "
            << player.GetHunting() << "/10\n";
        std::cout << "============================================\n\n";
        ConsoleColors::ResetColor();
    }

    if (currentScene == 8 && !mIntroducedToDirector)
    {
        player.IncreaseCharisma();

        mIntroducedToDirector = true;

        ConsoleColors::SetColor(ConsoleColors::Green);
        std::cout << "============================================\n";
        std::cout << "           MILESTONE REACHED!\n";
        std::cout << "============================================\n";

        std::cout << "You remain composed while speaking with\n";
        std::cout << "Director Woodwreath.\n\n";

        std::cout << "Your confidence in social situations grows.\n\n";

        std::cout << "Charisma increased by 1!\n";
        std::cout << "Current Charisma: "
            << player.GetCharisma() << "/10\n";

        std::cout << "============================================\n\n";
        ConsoleColors::ResetColor();
    }

    if (currentScene == 9 && !mPretendToBeCamper)
    {
        player.IncreaseStealth();

        mPretendToBeCamper = true;

        ConsoleColors::SetColor(ConsoleColors::Green);
        std::cout << "============================================\n";
        std::cout << "           MILESTONE REACHED!\n";
        std::cout << "============================================\n";

        std::cout << "You successfully blend in by pretending\n";
        std::cout << "to be interested in attending the camp.\n\n";

        std::cout << "Your ability to conceal your intentions improves.\n\n";

        std::cout << "Stealth increased by 1!\n";
        std::cout << "Current Stealth: "
            << player.GetStealth() << "/10\n";

        std::cout << "============================================\n\n";
        ConsoleColors::ResetColor();
    }

    if (currentScene == 10 && !mAskedAboutMissingPeople)
    {
        mDirectorSuspicion += 2;

        if (mDirectorSuspicion > 10)
        {
            mDirectorSuspicion = 10;
        }

        mAskedAboutMissingPeople = true;
        ConsoleColors::SetColor(ConsoleColors::Red);
        std::cout << "============================================\n";
        std::cout << "       DIRECTOR'S SUSPICION INCREASED\n";
        std::cout << "============================================\n";
        std::cout << "Your questions about the missing people\n";
        std::cout << "have made Director Woodwreath uneasy.\n\n";

        std::cout << "Suspicion increased by 2!\n";
        std::cout << "Current Suspicion: "
            << mDirectorSuspicion << "/10\n";

        std::cout << "============================================\n\n";
        ConsoleColors::ResetColor();
    }

    // ============================================
    // Director Suspicion - Successful Reassurance
    // ============================================

    if (currentScene == 11 && !mReassuredDirector)
    {
        // Reduce Suspicion by 2.
        mDirectorSuspicion -= 2;

        // Prevent Suspicion from dropping below zero.
        if (mDirectorSuspicion < 0)
        {
            mDirectorSuspicion = 0;
        }

        mReassuredDirector = true;

        ConsoleColors::SetColor(ConsoleColors::Cyan);
        std::cout << "============================================\n";
        std::cout << "          DIRECTOR REASSURED\n";
        std::cout << "============================================\n";

        std::cout << "Your explanation seems to calm the director.\n";
        std::cout << "He appears less suspicious of your intentions.\n\n";

        std::cout << "Suspicion reduced by up to 2!\n";
        std::cout << "Current Suspicion: "
            << mDirectorSuspicion << "/10\n";

        std::cout << "============================================\n\n";
        ConsoleColors::ResetColor();
    }

    // ============================================
    // Story Event - Director Confronted
    // ============================================

    if (currentScene == 12 && !mConfrontedDirector)
    {
        mConfrontedDirector = true;

        ConsoleColors::SetColor(ConsoleColors::Red);
        std::cout << "============================================\n";
        std::cout << "           RELATIONSHIP CHANGED\n";
        std::cout << "============================================\n";

        std::cout << "Director Woodwreath now considers you\n";
        std::cout << "a threat to his camp.\n\n";

        std::cout << "He has ordered you to leave the property.\n";

        std::cout << "============================================\n\n";
        ConsoleColors::ResetColor();
    }

    // ============================================
    // Director - Repeated Missing People Question
    // ============================================

    if (currentScene == 29 && !mRepeatedMissingPeopleQuestion)
    {
        mRepeatedMissingPeopleQuestion = true;

        mDirectorSuspicion += 1;

        if (mDirectorSuspicion > 10)
        {
            mDirectorSuspicion = 10;
        }

        ConsoleColors::SetColor(ConsoleColors::Red);

        std::cout << "============================================\n";
        std::cout << "       DIRECTOR'S SUSPICION INCREASED!\n";
        std::cout << "============================================\n";
        std::cout << "Director Woodwreath is losing patience.\n\n";
        std::cout << "Suspicion increased by 1!\n";
        std::cout << "Current Suspicion: "
            << mDirectorSuspicion << "/10\n";
        std::cout << "============================================\n\n";

        ConsoleColors::ResetColor();
    }

    // ============================================
    // Director - Diplomatic Response
    // ============================================

    if (currentScene == 30 && !mDiplomaticResponseUsed)
    {
        mDiplomaticResponseUsed = true;

        mDirectorSuspicion -= 1;

        // Suspicion cannot fall below zero.
        if (mDirectorSuspicion < 0)
        {
            mDirectorSuspicion = 0;
        }

        ConsoleColors::SetColor(ConsoleColors::Cyan);

        std::cout << "============================================\n";
        std::cout << "          DIRECTOR REASSURED!\n";
        std::cout << "============================================\n";
        std::cout << "Your diplomatic approach eases the tension.\n\n";
        std::cout << "Suspicion decreased by 1!\n";
        std::cout << "Current Suspicion: "
            << mDirectorSuspicion << "/10\n";
        std::cout << "============================================\n\n";

        ConsoleColors::ResetColor();
    }

    // ============================================
    // Director - Courage Confrontation
    // ============================================

    if (currentScene == 32 && !mConfrontedDirector)
    {
        mConfrontedDirector = true;

        ConsoleColors::SetColor(ConsoleColors::Red);

        std::cout << "============================================\n";
        std::cout << "          DIRECTOR NOW HOSTILE!\n";
        std::cout << "============================================\n";
        std::cout << "Your refusal to back down has consequences.\n\n";
        std::cout << "Director Woodwreath now considers you a threat.\n";
        std::cout << "You are no longer welcome in his lodge.\n";
        std::cout << "============================================\n\n";

        ConsoleColors::ResetColor();
    }

    // ============================================
    // Director - Perception Discovery
    // ============================================

    if (currentScene == 31 && !mDiscoveredDirectorClue)
    {
        mDiscoveredDirectorClue = true;

        ConsoleColors::SetColor(ConsoleColors::Cyan);

        std::cout << "============================================\n";
        std::cout << "             CLUE DISCOVERED!\n";
        std::cout << "============================================\n";
        std::cout << "Director Woodwreath's boots carry reddish\n";
        std::cout << "soil resembling the soil near the ranger\n";
        std::cout << "station.\n\n";
        std::cout << "He also seems unusually interested in the\n";
        std::cout << "northern forest.\n";
        std::cout << "============================================\n\n";

        ConsoleColors::ResetColor();
    }
}