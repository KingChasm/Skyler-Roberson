#include "Game.h"
#include <iostream>
#include <limits>
#include <vector>

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
    mInvestigatedGrandPortage = false; // Reset story milestone
    mInvestigatedRangerStation = false;
    mInvestigatedTracks = false;
    mIntroducedToDirector = false;
	mPretendToBeCamper = false;

    mDirectorSuspicion = 0;
    mAskedAboutMissingPeople = false;
    mReassuredDirector = false;
    mConfrontedDirector = false;

	player = Player(); // Reset player stats and collected notebook pages

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
    town.AddChoice("End the investigation.", 18);

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
	camp.AddChoice("Approach the main lodge and speak with the director.", 7);
    camp.AddChoice("End the investigation.", 18);

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
        "Descend into the underground passage.",
        14
    );
    hiddenEntrance.AddChoice(
        "Return to the campgrounds.",
        2
    );
    hiddenEntrance.AddChoice(
        "Collect evidence and escape Camp Woodwreath.",
        15
    );

    scenes.push_back(hiddenEntrance);

    // ============================================
    // Scene 6 - Suspicious Tracks
    // ============================================

    Scene suspiciousTracks(
        "Tracks in the Mud",
        "You crouch beside the ranger station.\n\n"
        "Deep impressions mark the damp earth.\n"
        "At first, they resemble the tracks of a large wolf.\n\n"
        "But something is wrong.\n\n"
        "The tracks gradually change shape.\n"
        "What began as four-legged footprints becomes\n"
        "something disturbingly similar to human footsteps.\n\n"
        "Whatever left these tracks was no ordinary animal."
    );

    suspiciousTracks.AddChoice(
        "Return to the ranger station.",
        4
    );

    scenes.push_back(suspiciousTracks);

    // ============================================
    // Scene 7 - The Camp Director
    // ============================================

    Scene campDirector(
        "A Friendly Welcome",
        "As you approach the main lodge, a man steps "
        "onto the porch.\n\n"

        "He is tall, broad-shouldered, and wearing "
        "a faded camp jacket.\n\n"

        "\"Well, hello there! Don't get many visitors "
        "this time of year.\"\n\n"

        "His smile seems genuine, but his eyes linger "
        "on you a moment too long.\n\n"

        "\"Name's Woodwreath. I run this place. "
        "What brings you all the way out here?\""
    );

    campDirector.AddChoice(
        "Introduce yourself honestly.",
        8
    );

    campDirector.AddChoice(
        "Pretend you're interested in attending the camp.",
        9
    );

    campDirector.AddChoice(
        "Ask about the missing people.",
        10
    );

    campDirector.AddChoice(
        "Excuse yourself and return to the campgrounds.",
        2
    );

    scenes.push_back(campDirector);

    // ============================================
    // Scene 8 - Honest Introduction
    // ============================================

    Scene honestIntroduction(
        "An Honest Introduction",
        "You introduce yourself and explain that "
        "you're visiting the area.\n\n"

        "Director Woodwreath studies your face.\n\n"

        "\"Visiting, huh? Well, you're a long way "
        "from the usual tourist spots.\"\n\n"

        "He chuckles, but something about his "
        "expression feels rehearsed.\n\n"

        "\"Just be careful wandering these woods. "
        "We've had some... animal problems lately.\""
    );

    honestIntroduction.AddChoice(
        "Ask what kind of animals he's talking about.",
        7
    );

    honestIntroduction.AddChoice(
        "Thank him and return to the campgrounds.",
        2
    );

    scenes.push_back(honestIntroduction);

    // ============================================
    // Scene 9 - Pretending to Be a Camper
    // ============================================

    Scene pretendCamper(
        "A Potential Camper",
        "You explain that you're interested in "
        "attending Camp Woodwreath.\n\n"

        "The director's expression brightens.\n\n"

        "\"Well, now! That's wonderful to hear. "
        "We're always happy to welcome new faces.\"\n\n"

        "He gestures toward the cabins.\n\n"

        "\"We pride ourselves on making everyone "
        "feel like part of the family.\"\n\n"

        "For some reason, the word 'family' "
        "makes you uncomfortable."
    );

    pretendCamper.AddChoice(
        "Ask about the camp's activities.",
        7
    );

    pretendCamper.AddChoice(
        "Return to the campgrounds.",
        2
    );

    scenes.push_back(pretendCamper);

    // ============================================
    // Scene 10 - Missing People
    // ============================================

    Scene missingPeople(
        "An Uncomfortable Question",
        "You ask Director Woodwreath about the "
        "people who have disappeared nearby.\n\n"

        "His smile disappears.\n\n"

        "\"Missing people? Can't say I know "
        "anything about that.\"\n\n"

        "His voice remains calm, but his hands "
        "tighten around the porch railing.\n\n"

        "\"These woods are dangerous. People "
        "wander off sometimes. Happens everywhere.\"\n\n"

        "He takes a step closer.\n\n"

        "\"I'd recommend you stop asking "
        "questions like that.\""
    );

    missingPeople.AddChoice(
        "Apologize and change the subject.",
        7
    );

    missingPeople.AddChoice(
        "Leave and return to the campgrounds.",
        2
    );

    scenes.push_back(missingPeople);

    // ============================================
    // Scene 11 - Reassure the Director
    // ============================================

    Scene reassureDirector(
        "A Convincing Explanation",
        "You offer Director Woodwreath a reassuring smile.\n\n"

        "\"Sorry if that sounded strange. I heard some "
        "rumors in town and got curious.\"\n\n"

        "The director watches you carefully.\n\n"

        "\"Rumors have a way of getting out of hand "
        "around here,\" he says.\n\n"

        "After a moment, his expression softens.\n\n"

        "\"Just enjoy your visit, alright?\""
    );

    reassureDirector.AddChoice(
        "Return to the conversation.",
        7
    );

    reassureDirector.AddChoice(
        "Leave the main lodge.",
        2
    );

    scenes.push_back(reassureDirector);

    // ============================================
    // Scene 12 - Confront the Director
    // ============================================

    Scene confrontDirector(
        "A Dangerous Accusation",
        "You refuse to accept the director's explanation.\n\n"

        "\"Three people disappear near your camp, "
        "and you expect me to believe that's a coincidence?\"\n\n"

        "Director Woodwreath's expression hardens.\n\n"

        "\"You should be very careful about what "
        "you're accusing people of.\"\n\n"

        "For a moment, his eyes seem almost animalistic.\n\n"

        "Then he smiles again.\n\n"

        "\"I think it's time you left my camp.\""
    );

    confrontDirector.AddChoice(
        "Back away and return to the campgrounds.",
        2
    );

    scenes.push_back(confrontDirector);

    // ============================================
    // Scene 13 - Unwelcome Visitor
    // ============================================

    Scene unwelcomeVisitor(
        "An Unwelcome Visitor",
        "You approach the main lodge once again.\n\n"

        "Director Woodwreath is waiting on the porch.\n\n"

        "\"I thought I told you to leave.\"\n\n"

        "His friendly expression is gone.\n"
        "He steps down from the porch, blocking your path.\n\n"

        "\"You don't belong here.\"\n\n"

        "For a brief moment, you notice something\n"
        "unnatural about his teeth.\n\n"

        "They're much sharper than they should be.\n\n"

        "\"This is your last warning.\""
    );

    unwelcomeVisitor.AddChoice(
        "Retreat to the campgrounds.",
        2
    );

    scenes.push_back(unwelcomeVisitor);

    // ============================================
    // Scene 14 - The Underground Passage
    // ============================================

    Scene undergroundPassage(
        "Into the Darkness",
        "You carefully lift the rusted hatch.\n\n"

        "A narrow staircase descends beneath the lodge.\n"
        "The air is cold and carries the smell of decay.\n\n"

        "You switch on your flashlight and begin descending.\n\n"

        "At the bottom, you discover a long underground\n"
        "passage carved into the earth.\n\n"

        "Deep claw marks cover the wooden support beams.\n"
        "Something large has been moving through here.\n\n"

        "Then you hear it.\n\n"

        "Footsteps.\n\n"

        "Something is approaching from deeper in the tunnel."
    );

    undergroundPassage.AddChoice(
        "Retreat and escape with the evidence.",
        15
    );
    undergroundPassage.AddChoice(
        "Retreat through the hatch.",
        5
    );
    undergroundPassage.AddChoice(
        "Follow the mysterious footsteps deeper into the tunnels.",
        19
    );
    scenes.push_back(undergroundPassage);

    // ============================================
    // Scene 15 - Run  Rabbit
    // ============================================

    Scene escapeEnding(
        "ESCAPE - The Truth Survives",
        "You carefully document the hidden entrance,\n"
        "the claw marks, and the evidence beneath the lodge.\n\n"

        "As you retreat through the forest, a distant\n"
        "howl echoes between the trees.\n\n"

        "You finally understand what you've uncovered.\n\n"

        "Camp Woodwreath is not an ordinary summer camp.\n"
        "Something monstrous lives beneath its peaceful appearance.\n\n"

        "Your father's warnings suddenly make sense.\n"
        "These creatures are not simply wild animals.\n\n"

        "They are werewolves.\n\n"

        "And Director Woodwreath is protecting them.\n\n"

        "You escape the forest carrying enough evidence\n"
        "to expose what is happening at the camp.\n\n"

        "But as the first lights of Grand Portage appear,\n"
        "you hear several distant howls answering one another.\n\n"

        "There was never just one monster.\n\n"

        "============================================\n"
        "              INVESTIGATION COMPLETE\n"
        "============================================\n\n"

        "ENDING UNLOCKED: THE TRUTH SURVIVES\n\n"

        "You survived Camp Woodwreath.\n"
        "But the hunt is far from over.\n\n"

        "Thank you for playing Camp Woodwreath!"
    );

    escapeEnding.AddChoice(
        "Finish the investigation.",
        -1
    );

    scenes.push_back(escapeEnding);

    // ============================================
    // Scene 16 - Signs of the Beast
    // ============================================

    Scene signsOfTheBeast(
        "Signs of the Beast",
        "You kneel beside the claw marks carved into the tunnel wall.\n\n"
        "The spacing is wrong for an ordinary wolf.\n"
        "The marks are too high, too deep, and too deliberate.\n\n"
        "Your father's lessons return to you.\n\n"
        "A werewolf.\n\n"
        "The footsteps grow louder.\n"
        "Whatever made these marks is coming toward you."
    );

    signsOfTheBeast.AddChoice(
        "Retreat through the hatch.",
        5
    );

    signsOfTheBeast.AddChoice(
        "Escape with the evidence.",
        15
    );

    scenes.push_back(signsOfTheBeast);

    // ============================================
    // Scene 17 - Hidden in the Shadows
    // ============================================

    Scene hiddenInShadows(
        "Hidden in the Shadows",
        "You quickly switch off your flashlight.\n\n"
        "Pressing yourself against the cold tunnel wall,\n"
        "you slip behind a stack of abandoned wooden crates.\n\n"
        "The footsteps grow louder.\n\n"
        "A massive shadow stretches across the passage.\n"
        "Something stops only a few feet from your hiding place.\n\n"
        "You hold your breath.\n\n"
        "A low growl echoes through the darkness.\n\n"
        "After several terrifying seconds, the creature\n"
        "continues deeper into the tunnel.\n\n"
        "Whatever it was, it didn't notice you."
    );

    hiddenInShadows.AddChoice(
        "Escape with the evidence while the creature is gone.",
        15
    );

    hiddenInShadows.AddChoice(
        "Carefully retreat through the hatch.",
        5
    );

    scenes.push_back(hiddenInShadows);

    // ============================================
    // Scene 18 - Neutral Ending
    // ============================================

    Scene neutralEnding(
        "SOME SECRETS STAY BURIED",
        "You decide that continuing this investigation\n"
        "isn't worth risking your life.\n\n"

        "The disappearances are disturbing, but you\n"
        "have no idea what you're truly dealing with.\n\n"

        "You leave Grand Portage behind.\n\n"

        "Days pass. Then weeks.\n\n"

        "Eventually, another person disappears near\n"
        "Camp Woodwreath.\n\n"

        "And then another.\n\n"

        "You survived.\n"
        "But whatever lives in those woods remains free.\n\n"

        "============================================\n"
        "             INVESTIGATION ABANDONED\n"
        "============================================\n\n"

        "ENDING UNLOCKED: SOME SECRETS STAY BURIED\n\n"

        "Sometimes surviving means walking away.\n"
        "But some choices are harder to forget.\n\n"

        "Thank you for playing Camp Woodwreath!\n\n"

        "P.S.\n"
        "Some secrets are meant to stay buried, some are not...chicken. :<"
    );

    neutralEnding.AddChoice(
        "Return to the main menu.",
        -1
    );

    scenes.push_back(neutralEnding);

	// ============================================
	// Scene 19 - Bad Ending
	// ============================================

    Scene badEnding(
        "THE HUNTER BECOMES THE HUNTED",
        "Against your better judgment, you follow\n"
        "the footsteps deeper into the passage.\n\n"

        "The tunnel opens into a massive underground chamber.\n\n"

        "Bones litter the floor.\n"
        "Claw marks cover the walls.\n\n"

        "Then the footsteps stop.\n\n"

        "A familiar voice echoes through the darkness.\n\n"

        "\"I warned you to leave my camp.\"\n\n"

        "Director Woodwreath steps into the light.\n\n"

        "His body begins to twist and change. The transformation was slow and painful looking.\n"
        "Though you were frozen in terror at the sight. His hands become claws.\n"
        "His teeth sharpen into fangs.\n\n"

        "Before you can gain your bearings, more figures emerge\n"
        "from the darkness behind you.\n\n"

        "You finally understand your mistake.\n\n"

        "There was never just one werewolf.\n\n"

        "You came here expecting to hunt a monster.\n"
        "Instead, you walked into the heart of its pack.\n\n"

        "Your flashlight falls to the ground.\n\n"

        "The last thing you hear is a chorus of howls.\n\n"

        "Your world is overcome with whitehot pain, though that soon fades into cold\n"
		"and finally into darkness.\n\n"

        "============================================\n"
        "               INVESTIGATION FAILED\n"
        "============================================\n\n"

        "ENDING UNLOCKED: THE HUNTER BECOMES THE HUNTED\n\n"

        "The hunter has become the prey.\n\n"

        "Thank you for playing Camp Woodwreath!"
    );

    badEnding.AddChoice(
        "Return to the main menu.",
        -1
    );

    scenes.push_back(badEnding);
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

        Scene& scene = scenes[currentScene];

        std::cout << "\n";
        std::cout << "============================================\n";
        std::cout << scene.GetTitle() << "\n";
        std::cout << "============================================\n\n";

        std::cout << scene.GetDescription() << "\n\n";

        // Process lore discoveries, milestones, and story events.
		HandleSceneEvents(currentScene);
        

        // ============================================
        // Display Available Choices
        // ============================================
             
        std::vector<Choice> availableChoices = GetAvailableChoices(currentScene);

        // Display all currently available choices.
        for (int i = 0; i < static_cast<int>(availableChoices.size()); i++)
        {
            std::cout << "[" << i + 1 << "] "
                << availableChoices[i].text << "\n";
        }

        std::cout << "\n[0] View Player Status\n";

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
            std::cin.ignore(
                std::numeric_limits<std::streamsize>::max(),
                '\n'
            );

            std::cin.get();

            // Redisplay the current scene.
            continue;
        }

        // Process regular story choices.
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

// ============================================
// Player Status Screen (Most useful thing I've made imo)
// ============================================

void Game::ShowPlayerStatus() const
{
    std::cout << "\n";
    std::cout << "============================================\n";
    std::cout << "               PLAYER STATUS\n";
    std::cout << "============================================\n\n";

    // Player Stats
    std::cout << "CHARACTER STATS\n";
    std::cout << "--------------------------------------------\n";

    std::cout << "Hunting:    " << player.GetHunting() << "/10\n";
    std::cout << "Lore:       " << player.GetLore() << "/10\n";
    std::cout << "Perception: " << player.GetPerception() << "/10\n";
    std::cout << "Courage:    " << player.GetCourage() << "/10\n";
    std::cout << "Charisma:   " << player.GetCharisma() << "/10\n";
    std::cout << "Stealth:    " << player.GetStealth() << "/10\n";

    // Collected Lore
    std::cout << "\n";
    std::cout << "COLLECTED LORE\n";
    std::cout << "--------------------------------------------\n";

    std::cout << "Notebook Pages: "
        << player.GetNotebookPageCount()
        << "/3\n";

    // Display individual notebook pages.
    for (int page = 1; page <= 3; page++)
    {
        std::cout << "Page " << page << ": ";

        if (player.HasNotebookPage(page))
        {
            std::cout << "Collected\n";
        }
        else
        {
            std::cout << "Missing\n";
        }
    }

    // Completed notebook message.
    if (player.HasCompleteNotebook())
    {
        std::cout << "\n";
        std::cout << "NOTEBOOK COMPLETE!\n";
        std::cout << "Hidden Lodge Entrance Unlocked.\n";
    }

    std::cout << "\n";
    std::cout << "CAMP RELATIONSHIPS\n";
    std::cout << "--------------------------------------------\n";

    std::cout << "Director Woodwreath's Suspicion: "
        << mDirectorSuspicion << "/10\n";

    // Confrontation overrides the director's normal attitude.
    if (mConfrontedDirector)
    {
        std::cout << "Attitude: Hostile\n";
    }
    else if (mDirectorSuspicion <= 2)
    {
        std::cout << "Attitude: Friendly\n";
    }
    else if (mDirectorSuspicion <= 5)
    {
        std::cout << "Attitude: Cautious\n";
    }
    else if (mDirectorSuspicion <= 8)
    {
        std::cout << "Attitude: Suspicious\n";
    }
    else
    {
        std::cout << "Attitude: Hostile\n";
    }

    std::cout << "\n";
    std::cout << "============================================\n";
}

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

    if (currentScene == 1 && !mInvestigatedGrandPortage)
    {
        player.IncreasePerception();

        mInvestigatedGrandPortage = true;

        std::cout << "============================================\n";
        std::cout << "           MILESTONE REACHED!\n";
        std::cout << "============================================\n";
        std::cout << "You carefully investigate Grand Portage.\n";
        std::cout << "Your awareness of the surroundings improves.\n\n";
        std::cout << "Perception increased by 1!\n";
        std::cout << "Current Perception: "
            << player.GetPerception() << "/10\n";
        std::cout << "============================================\n\n";
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

    if (currentScene == 4 && !mInvestigatedRangerStation)
    {
        player.IncreaseCourage();

        mInvestigatedRangerStation = true;

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
    }

    if (currentScene == 6 && !mInvestigatedTracks)
    {
        player.IncreaseHunting();

        mInvestigatedTracks = true;

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
    }

    if (currentScene == 8 && !mIntroducedToDirector)
    {
        player.IncreaseCharisma();

        mIntroducedToDirector = true;

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
    }

if (currentScene == 9 && !mPretendToBeCamper)
{
    player.IncreaseStealth();

    mPretendToBeCamper = true;

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
}

    if (currentScene == 10 && !mAskedAboutMissingPeople)
    {
        mDirectorSuspicion += 2;

        if (mDirectorSuspicion > 10)
        {
            mDirectorSuspicion = 10;
        }

        mAskedAboutMissingPeople = true;

        std::cout << "============================================\n";
        std::cout << "       DIRECTOR'S SUSPICION INCREASED\n";
        std::cout << "============================================\n";
        std::cout << "Your questions about the missing people\n";
        std::cout << "have made Director Woodwreath uneasy.\n\n";

        std::cout << "Suspicion increased by 2!\n";
        std::cout << "Current Suspicion: "
            << mDirectorSuspicion << "/10\n";

        std::cout << "============================================\n\n";
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

        std::cout << "============================================\n";
        std::cout << "          DIRECTOR REASSURED\n";
        std::cout << "============================================\n";

        std::cout << "Your explanation seems to calm the director.\n";
        std::cout << "He appears less suspicious of your intentions.\n\n";

        std::cout << "Suspicion reduced by up to 2!\n";
        std::cout << "Current Suspicion: "
            << mDirectorSuspicion << "/10\n";

        std::cout << "============================================\n\n";
    }

    // ============================================
        // Story Event - Director Confronted
        // ============================================

    if (currentScene == 12 && !mConfrontedDirector)
    {
        mConfrontedDirector = true;

        std::cout << "============================================\n";
        std::cout << "           RELATIONSHIP CHANGED\n";
        std::cout << "============================================\n";

        std::cout << "Director Woodwreath now considers you\n";
        std::cout << "a threat to his camp.\n\n";

        std::cout << "He has ordered you to leave the property.\n";
        
        std::cout << "============================================\n\n";
    }
}

std::vector<Choice> Game::GetAvailableChoices(int sceneIndex)
{
	int currentScene = sceneIndex;
	Scene& scene = scenes[currentScene];

    // Create a temporary list of choices for this visit.
    std::vector<Choice> availableChoices = scene.GetChoices();

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
    if (currentScene == 10 && mDirectorSuspicion >= 2)
    {
        availableChoices.push_back({
            "[Suspicion] Challenge the director's explanation.",
            12
            });
    }

    return availableChoices;
}