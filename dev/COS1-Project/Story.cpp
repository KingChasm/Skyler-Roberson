#include "Game.h"
#include "Scene.h"

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
        24
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
        25
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
        27
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
        28
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

    // ============================================
    // Scene 20 - Stand Your Ground (Courage)
    // ============================================

    Scene standYourGround(
        "Stand Your Ground",
        "The footsteps grow louder.\n\n"
        "Every instinct tells you to run.\n"
        "But you remember your father's training.\n\n"
        "Fear is natural. Giving in to it is a choice.\n\n"
        "You steady your breathing and raise your flashlight.\n\n"
        "A massive figure emerges from the darkness.\n"
        "Its yellow eyes lock onto yours.\n\n"
        "You recognize the creature immediately.\n\n"
        "A werewolf.\n\n"
        "It growls, preparing to attack.\n"
        "You refuse to turn your back.\n\n"
        "For a brief moment, the creature hesitates.\n\n"
        "You have a chance to escape."
    );

    standYourGround.AddChoice(
        "Retreat while the creature hesitates.",
        5
    );

    standYourGround.AddChoice(
        "Escape the camp with your evidence.",
        15
    );

    scenes.push_back(standYourGround);

    // ============================================
    // Scene 21 - The Hunter's Knowledge (Lore)
    // ============================================

    Scene huntersKnowledge(
        "The Hunter's Knowledge",
        "You remember a passage from your father's notebook.\n\n"
        "Werewolves are terrifying predators, but they are not invincible.\n\n"
        "Silver can wound them, and their heightened senses\n"
        "can sometimes be used against them.\n\n"
        "You study the claw marks again.\n"
        "There is more than one set.\n\n"
        "A terrible realization settles over you.\n\n"
        "The creature approaching you is not alone.\n"
        "You are standing in the territory of an entire pack.\n\n"
        "Your father's notes may have just saved your life."
    );

    huntersKnowledge.AddChoice(
        "Retreat through the hatch before the pack arrives.",
        5
    );

    huntersKnowledge.AddChoice(
        "Escape with your evidence and knowledge.",
        15
    );

    scenes.push_back(huntersKnowledge);

    // ============================================
    // Scene 22 - The Predator's Mask (Perception)
    // ============================================

    Scene predatorsMask(
        "The Predator's Mask",
        "You watch Director Woodwreath carefully.\n\n"
        "His smile is practiced, almost rehearsed.\n"
        "But his eyes tell a different story.\n\n"

        "They follow every movement you make.\n"
        "Even when you shift your weight slightly,\n"
        "his gaze immediately adjusts.\n\n"

        "Then you notice his hands.\n\n"
        "His fingernails are unusually thick,\n"
        "almost resembling claws.\n\n"

        "For a brief moment, the sunlight catches\n"
        "his eyes at an unusual angle.\n\n"

        "They're yellow.\n\n"

        "Whatever Director Woodwreath is hiding,\n"
        "you suspect it isn't entirely human.\n\n"

        "And judging by his expression...\n"
        "he may have noticed your suspicion."
    );

    predatorsMask.AddChoice(
        "Pretend you noticed nothing and ask about the camp's activities.",
        25
    );

    predatorsMask.AddChoice(
        "Leave the director and return to the campgrounds.",
        2
    );

    scenes.push_back(predatorsMask);

    // ============================================
    // Scene 23 - A Carefully Chosen Question
    // ============================================

    Scene carefullyChosenQuestion(
        "A Carefully Chosen Question",
        "You decide that accusing Director Woodwreath\n"
        "would only make him defensive.\n\n"

        "Instead, you smile and compliment the camp.\n\n"

        "\"This place must have quite a history.\n"
        "Has your family owned it for long?\"\n\n"

        "The director's expression softens.\n\n"

        "\"Oh, generations,\" he replies.\n"
        "\"My grandfather helped establish this place.\n"
        "We've always believed in keeping things\n"
        "within the family.\"\n\n"

        "He glances toward the forest.\n\n"

        "\"The woods have always belonged to us,\n"
        "in one way or another.\"\n\n"

        "You notice something strange about his wording.\n\n"

        "Not the camp.\n"
        "The woods.\n\n"

        "Before you can ask another question,\n"
        "his welcoming smile returns.\n\n"

        "\"Anyway, enough about the past!\n"
        "What brings you here?\"\n\n"

        "You have learned something important:\n"
        "the Woodwreath family's connection to\n"
        "this land goes back generations."
    );

    carefullyChosenQuestion.AddChoice(
        "Ask about the camp's activities.",
        25
    );

    carefullyChosenQuestion.AddChoice(
        "Thank the director and return to the campgrounds.",
        2
    );

    scenes.push_back(carefullyChosenQuestion);

    // ============================================
    // Scene 24 - The Animals in the Woods
    // ============================================

    Scene animalsInTheWoods(
        "The Animals in the Woods",

        "\"Animal problems?\" you ask. "
        "\"What kind of animals?\"\n\n"

        "Director Woodwreath chuckles.\n\n"

        "\"Oh, the usual things. Bears, coyotes. "
        "Occasionally something a little larger "
        "wanders down from the Canadian wilderness.\"\n\n"

        "You raise an eyebrow.\n\n"

        "\"Something larger?\"\n\n"

        "For the briefest moment, his smile falters.\n\n"

        "\"Just an expression,\" he says quickly.\n\n"

        "He glances toward the forest.\n\n"

        "\"The important thing is that you stay on "
        "the marked trails. Especially after dark.\"\n\n"

        "You notice that his eyes remain fixed "
        "on the treeline for several seconds.\n\n"

        "\"Trust me,\" he adds, turning back toward you.\n"
        "\"You wouldn't want to meet what's out there.\"\n\n"

        "Something about the way he says that "
        "makes your stomach tighten."
    );

    animalsInTheWoods.AddChoice(
        "Thank him for the warning and return to the campgrounds.",
        2
    );

    animalsInTheWoods.AddChoice(
        "Ask about the missing people.",
        10
    );

    scenes.push_back(animalsInTheWoods);

    // ============================================
    // Scene 25 - Camp Activities
    // ============================================

    Scene campActivities(
        "A Summer to Remember",

        "\"So, what kind of activities does the camp offer?\"\n\n"

        "Director Woodwreath's face brightens.\n\n"

        "\"Oh, all sorts of things! Hiking, swimming, "
        "archery, wilderness survival. The usual "
        "outdoor adventures.\"\n\n"

        "He gestures toward the distant cabins.\n\n"

        "\"We also have a rather special nighttime "
        "program. The children absolutely love it.\"\n\n"

        "\"Nighttime program?\" you ask.\n\n"

        "His smile widens.\n\n"

        "\"A little tradition we call the Moonlight Hunt.\"\n\n"

        "Something about that name makes you uneasy.\n\n"

        "\"It's perfectly harmless, of course,\" "
        "he continues. \"A game of hide-and-seek "
        "through the forest.\"\n\n"

        "He pauses.\n\n"

        "\"The children hide... and our staff "
        "members find them.\"\n\n"

        "For a moment, his expression becomes "
        "strangely distant.\n\n"

        "\"We're very good at finding people.\"\n\n"

        "Then his cheerful smile returns.\n\n"

        "\"But enough about that! Are you thinking "
        "of joining us this summer?\""
    );

    campActivities.AddChoice(
        "Ask more about the Moonlight Hunt.",
        26
    );

    campActivities.AddChoice(
        "Thank him and return to the campgrounds.",
        2
    );

    scenes.push_back(campActivities);

    // ============================================
    // Scene 26 - The Moonlight Hunt
    // ============================================

    Scene moonlightHunt(
        "The Moonlight Hunt",

        "\"You mentioned something called "
        "the Moonlight Hunt?\"\n\n"

        "Director Woodwreath nods enthusiastically.\n\n"

        "\"An old family tradition! My father "
        "organized the very first one.\"\n\n"

        "\"And the children enjoy it?\"\n\n"

        "\"Oh, they certainly make plenty of noise!\"\n\n"

        "He laughs.\n\n"

        "You don't.\n\n"

        "\"We have one very important rule,\" "
        "he continues.\n\n"

        "\"Once the hunt begins, nobody leaves "
        "the designated grounds until it's over.\"\n\n"

        "\"What happens if someone breaks that rule?\"\n\n"

        "His smile slowly disappears.\n\n"

        "\"We find them.\"\n\n"

        "An uncomfortable silence follows.\n\n"

        "Then he claps his hands together.\n\n"

        "\"Now! Was there anything else "
        "you wanted to know?\""
    );

    moonlightHunt.AddChoice(
        "Ask about the missing people.",
        10
    );

    moonlightHunt.AddChoice(
        "Leave the director and investigate the campgrounds.",
        2
    );

    scenes.push_back(moonlightHunt);

    // ============================================
    // Scene 27 - An Uneasy Apology
    // ============================================

    Scene uneasyApology(
        "An Uneasy Apology",

        "\"Sorry,\" you say. \"I didn't mean to pry.\"\n\n"

        "Director Woodwreath studies you in silence.\n\n"

        "For several uncomfortable seconds, neither "
        "of you speaks.\n\n"

        "Finally, his smile returns.\n\n"

        "\"No harm done. Curiosity is natural, "
        "especially for someone your age.\"\n\n"

        "He rests one hand against the porch railing.\n\n"

        "\"But curiosity can get people into trouble "
        "out here. These woods aren't nearly as "
        "forgiving as they look.\"\n\n"

        "You nod, pretending to accept his explanation.\n\n"

        "\"Anyway,\" he continues, his voice brightening, "
        "\"we have plenty of things to keep visitors "
        "occupied without worrying about old rumors.\"\n\n"

        "His eyes drift toward the forest.\n\n"

        "\"Best to leave certain things alone.\"\n\n"

        "The conversation has become noticeably colder.\n\n"

        "Whatever the director knows, "
        "he isn't interested in sharing it."
    );

    uneasyApology.AddChoice(
        "Ask about the camp's activities instead.",
        25
    );

    uneasyApology.AddChoice(
        "Thank him and return to the campgrounds.",
        2
    );

    scenes.push_back(uneasyApology);

    // ============================================
    // Scene 28 - A More Relaxed Conversation
    // ============================================

    Scene relaxedConversation(
        "A More Relaxed Conversation",

        "Director Woodwreath seems satisfied with "
        "your explanation.\n\n"

        "He releases his grip on the porch railing "
        "and adjusts his camp jacket.\n\n"

        "\"Well, I suppose I can't blame you for "
        "being curious,\" he says.\n\n"

        "\"Small towns have a habit of turning "
        "every little incident into a mystery.\"\n\n"

        "He gestures toward the campgrounds.\n\n"

        "\"We've been running this camp for "
        "generations. My family takes great pride "
        "in keeping our guests safe.\"\n\n"

        "His smile returns.\n\n"

        "\"Now, was there something else "
        "you wanted to know?\"\n\n"

        "Although his manner has softened, "
        "you notice that he still watches "
        "your reactions carefully."
    );

    relaxedConversation.AddChoice(
        "Ask about the camp's activities.",
        25
    );

    relaxedConversation.AddChoice(
        "Ask about the Woodwreath family history.",
        23
    );

    relaxedConversation.AddChoice(
        "Thank him and return to the campgrounds.",
        2
    );

    scenes.push_back(relaxedConversation);

    // ============================================
    // Scene 29 - A Familiar Question
    // ============================================

    Scene familiarQuestion(
        "A Familiar Question",

        "You bring up the disappearances once again.\n\n"

        "Director Woodwreath's smile fades.\n\n"

        "\"We've already discussed this, haven't we?\"\n\n"

        "He folds his arms across his chest.\n\n"

        "\"I understand that you're curious, but "
        "there's nothing more I can tell you.\"\n\n"

        "His voice remains polite, although "
        "his patience is clearly wearing thin.\n\n"

        "\"Now, I'd appreciate it if we could "
        "leave the subject alone.\"\n\n"

        "You get the impression that another "
        "question might push him too far."
    );

    familiarQuestion.AddChoice(
        "Change the subject and ask about camp activities.",
        25
    );

    familiarQuestion.AddChoice(
        "Leave the lodge.",
        2
    );

    scenes.push_back(familiarQuestion);

    // ============================================
    // Scene 30 - A Diplomatic Response
    // ============================================

    Scene diplomaticResponse(
        "A Diplomatic Response",

        "You raise your hands slightly, offering "
        "Director Woodwreath a reassuring smile.\n\n"

        "\"I understand. I didn't mean to suggest "
        "you were involved in anything.\"\n\n"

        "The director watches you carefully.\n\n"

        "\"It's just that people in town seem worried,\" "
        "you continue. \"I figured as someone who knows "
        "these woods you might have some advice.\"\n\n"

        "For a moment, he says nothing.\n\n"

        "Then his shoulders relax.\n\n"

        "\"Well, when you put it that way...\"\n\n"

        "He glances toward the forest.\n\n"

        "\"Stay away from the northern trails after "
        "sunset. That's the best advice I can give.\"\n\n"

        "You nod appreciatively.\n\n"

        "\"Thank you, Director.\"\n\n"

        "His smile returns, although it doesn't "
        "quite reach his eyes.\n\n"

        "You may have eased his suspicions.\n\n"

        "And you've learned something useful."
    );

    diplomaticResponse.AddChoice(
        "Thank the director and leave the lodge.",
        2
    );

    scenes.push_back(diplomaticResponse);

    // ============================================
    // Scene 31 - The Director's Tell
    // ============================================

    Scene directorsTell(
        "The Director's Tell",

        "You decide not to argue with Director Woodwreath.\n\n"

        "Instead, you watch him carefully.\n\n"

        "His expression is controlled, but his body "
        "language tells a different story.\n\n"

        "Every time you mention the missing people, "
        "his eyes drift toward the northern forest.\n\n"

        "You casually glance in the same direction.\n\n"

        "For a fraction of a second, his jaw tightens.\n\n"

        "\"Something interesting out there?\" you ask.\n\n"

        "\"Nothing worth your attention,\" he replies.\n\n"

        "But you notice something else.\n\n"

        "A small patch of dark soil clings to the "
        "bottom of his boots.\n\n"

        "The same reddish soil you noticed near "
        "the abandoned ranger station.\n\n"

        "Director Woodwreath notices your gaze.\n\n"

        "\"You seem distracted,\" he says quietly.\n\n"

        "You look back up.\n\n"

        "His smile has disappeared.\n\n"

        "You've learned something important.\n\n"

        "Whatever the director is hiding, "
        "the northern forest may hold the answers."
    );

    directorsTell.AddChoice(
        "Excuse yourself and investigate the campgrounds.",
        2
    );

    scenes.push_back(directorsTell);

    // ============================================
    // Scene 32 - Refusing to Back Down
    // ============================================

    Scene refusingToBackDown(
        "Refusing to Back Down",

        "Director Woodwreath stares at you.\n\n"

        "\"I believe I've answered your questions.\"\n\n"

        "You don't move.\n\n"

        "\"Not really,\" you reply.\n\n"

        "The director's expression darkens.\n\n"

        "\"Excuse me?\"\n\n"

        "\"People are missing. Someone knows something, "
        "and I'm not going to pretend otherwise.\"\n\n"

        "For several seconds, neither of you speaks.\n\n"

        "Then the director slowly stands.\n\n"

        "He's taller than you expected.\n\n"

        "\"You remind me of someone,\" he mutters.\n\n"

        "Your stomach tightens.\n\n"

        "\"Who?\"\n\n"

        "He smiles, revealing unusually sharp teeth.\n\n"

        "\"Someone who didn't know when to stop asking "
        "questions.\"\n\n"

        "A low growl escapes his throat.\n\n"

        "\"Leave my lodge. Now.\"\n\n"

        "You hold his gaze for another moment before "
        "stepping toward the door.\n\n"

        "Whatever happens next, you've made yourself "
        "an enemy."
    );

    refusingToBackDown.AddChoice(
        "Leave the lodge before things turn violent.",
        2
    );

    scenes.push_back(refusingToBackDown);

    // ============================================
    // Scene 33 - Following the Red Soil
    // ============================================

    Scene followingRedSoil(
        "Following the Red Soil",

        "You kneel beside the abandoned ranger station.\n\n"

        "The reddish soil beneath your boots looks familiar.\n\n"

        "It's the same soil you noticed on Director "
        "Woodwreath's boots.\n\n"

        "You examine the ground more carefully.\n\n"

        "Several deep footprints lead away from the "
        "station and toward the northern forest.\n\n"

        "They're unusually large.\n\n"

        "Some resemble human footprints.\n\n"

        "Others look disturbingly similar to the "
        "tracks of an enormous animal.\n\n"

        "You follow them a short distance before "
        "discovering something caught on a thorn bush.\n\n"

        "A torn piece of dark fabric.\n\n"

        "The material looks remarkably similar to "
        "the director's coat.\n\n"

        "Whatever happened here, Director Woodwreath "
        "may have been involved."
    );

    followingRedSoil.AddChoice(
        "Return to the ranger station.",
        4
    );

    followingRedSoil.AddChoice(
        "Return to the campgrounds.",
        2
    );

    scenes.push_back(followingRedSoil);


}