# Project & Portfolio 1

### Skyler Roberson

Hello my name is Skyler. I am a student from Kentucky. The purpose of this repository is to practice development using version control. This work will help me begin to build a portfolio of skills and accomplishment that can be shared in the future.

## Project: Camp Woodwreath
Camp Woodwreath is a console-based supernatural horror investigation game developed using C++20 and Visual Studio.

The player controls a teenage supernatural hunter investigating mysterious disappearances near Grand Portage. Their investigation leads to Camp Woodwreath, where the director and his family are hiding a dangerous secret.

<br>

## 📢 &nbsp; Weekly Stand Up

Each week I will summarize my milestone activity and progress by writing a stand-up. A stand-up is meant to be a succinct update on how things are going. Use these prompts as a guide on what to write about:

⚙️ Overview - What I worked on this past week
<br>
🌵 Challenges - What problems did I have & how I'm addressing them
<br>
🏆 Accomplishments - What is something I "leveled up" on this week
<br>
🔮 Next Steps - What I plan to prioritize and do next

<br>

### Week 1

Camp Woodwreath is supposed to be a branch-based story driven horror game that takes place in the small town of Grand Portage, Minnesota. The story follows a nineteen year old protagonist who is investigating the recent disappearances around the town; all of which seem to be leading back to one place. Camp Woodwreath

**Core Features:**

A branching story system where player decisions lead to different scenes and eventually different endings.

A 0–10 stat system in which abilities improve through milestones reached during different story paths.

A lore and investigation system where discovering information can unlock additional choices and story paths.

A reputation system where interactions with characters and groups can affect dialogue and available decisions.

Multiple story paths that can diverge and later converge depending on previous player actions.

**Planned Classes:**

Player — Stores the player's stats and will eventually track discovered lore, evidence, reputation, and other player-specific information.

Game — Controls the main game flow, title screen, starting a new game, and movement through the story.

Scene — Represents sections of the story, including scene descriptions and the choices available to the player.

Choice — Represents individual player decisions and determines which scene a choice leads to. (Currently implemented as a struct, so if your instructor specifically wants classes here, I'd list another planned actual class instead.)

**Current Focus:**
My current focus is building the foundational systems for the game. I have created the Player, Game, and Scene systems, a title menu, basic player stats, and a working branching scene system. My next focus is expanding the choice system so that player stats, discovered lore, and other conditions can affect which choices become available.

### Week 2

Camp Woodwreath has progressed from its basic foundations into a working prototype with several of its planned gameplay systems implemented. The main focus this week was expanding the branching story system so that player decisions, collected lore, and character stats can affect which choices become available throughout the investigation.

**Core Features Implemented:**

- Expanded the branching story system with additional locations, dialogue interactions, and story events.
- Implemented milestone-based stat progression, allowing player abilities to increase through specific actions and discoveries.
- Added a lore collection system involving three notebook pages that unlock a hidden location once all three have been discovered.
- Implemented conditional choices that become available depending on the player's stats, collected lore, and previous decisions.
- Added a Suspicion system for Director Woodwreath, allowing certain dialogue choices to affect his behavior and future interactions.
- Added a player status screen that displays current stats, collected notebook pages, and the director's Suspicion.
- Implemented a playable prototype ending where the player can escape Camp Woodwreath with evidence from the investigation.

**Classes and Systems Updated:**

- Player — Expanded to manage collected notebook pages, stat increases, and skill requirement checks.
- Game — Expanded to handle additional story scenes, conditional choices, investigation milestones, NPC Suspicion, and player progression.
- Scene — Used to organize new locations, conversations, and story events.
- Choice — Continues to function as a struct that connects player decisions to different scenes, with the Game system determining when certain choices should become available.

**Challenges:**

One of the main challenges this week was getting conditional choices to appear correctly without interfering with the existing story system. I also had to make sure that revisiting locations would not repeatedly increase stats or trigger the same rewards. These issues were addressed by adjusting the choice logic, tracking previous player actions, and testing different story paths.

**Current Focus:**

My current focus is testing and refining the existing prototype before expanding the story further. The next steps will involve introducing more skill-based encounters, expanding the consequences of player decisions, and eventually implementing additional endings. I also plan to continue improving the program's structure as more story content is added.

### Week 3

This week, I focused on improving the structure of Camp Woodwreath and expanding its branching storyline. I refactored the scene system, improved navigation safety, and added two new underground encounters.

### Improvements
I separated scene events from conditional player choices by creating dedicated functions. I also added scene index validation to prevent invalid navigation.

I expanded the underground storyline with Hunting and Stealth skill checks, allowing players to unlock different choices based on earlier decisions.

### Challenges
One challenge was managing the growing number of story choices. Refactoring helped make the code easier to organize.

Another challenge was that players couldn't unlock the Stealth encounter without a way to increase their Stealth stat. I solved this by adding a milestone for pretending to be a camper.

### Accomplishments
I improved my understanding of organizing C++ functions, implementing conditional gameplay, and connecting player progression to branching story choices.

I'm particularly happy that both new underground encounters work and have valid exits.

### Next Steps
Before Week 4, I plan to continue improving the storyline, expand the consequences of player decisions, and prepare additional endings.

### Week 4

**Overview**
This week, I focused on finishing Camp Woodwreath, fixing bugs, testing gameplay, and preparing the project for submission.

**Project Wrap-Up**
Camp Woodwreath is now a playable C++ console horror game featuring branching storylines, three endings, six player stats, collectible lore, skill checks, and a character suspicion system.

**Challenges**
My biggest challenges were managing complicated dialogue branches and making sure certain choices appeared only when their requirements were met. I addressed these problems through refactoring, debugging, and testing.

**Biggest Takeaway**
This project helped me improve my understanding of C++ classes, vectors, references, input validation, and organizing larger programs. I'm especially proud of the branching story system and player status screen.

**Future Development**
If I continue developing Camp Woodwreath, I would like to add more story paths, additional supernatural encounters, and a save/load system. On top of that, I'd like to add individual encounters. More purpose to Grand Portage as a town, giving it a purpose; it currently lacks one beyond a skill point.

tldr; There are like, a dozen different independent features I want to add to this stinking project and am being halted on time and me work schedule.

The werewolves were the least of my problems; my greatest challenge was overcoming and dodging Window Security and Smart App Control.

![[Pasted image 20261023193420.png]]