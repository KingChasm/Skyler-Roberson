# Milestone 4 – Final Development and Delivery

## Project Overview

Camp Woodwreath is a console-based interactive horror game developed in C++20 using Visual Studio.

The player takes the role of a young supernatural hunter investigating mysterious disappearances near Camp Woodwreath. Throughout the story, players make decisions, collect clues, develop character skills, and uncover the secrets of the camp's director.

## Final Features

The completed game includes:

- A main menu with New Game and Quit options.
    
- A branching story with three possible endings.
    
- Six player statistics: Hunting, Lore, Perception, Courage, Charisma, and Stealth.
    
- Skill checks that unlock additional dialogue and investigation choices.
    
- Three collectible notebook pages.
    
- A hidden lodge entrance unlocked by completing the notebook.
    
- A suspicion system that tracks Director Woodwreath's attitude toward the player.
    
- Dialogue choices that can increase or decrease suspicion.
    
- Investigation clues that unlock additional story options.
    
- A player status screen displaying statistics, collected lore, and relationships.
    
- Colored console text for menus, important messages, and endings.
    

## Object-Oriented Programming and Data Structures

The game uses multiple classes to organize its systems.

The `Game` class manages gameplay, scene transitions, player choices, and story events.

The `Player` class manages character statistics and collected notebook pages.

The `Scene` class stores individual story scenes and their available choices.

The game uses a `std::vector<Scene>` to store and access story scenes. References are used to access existing scene objects without making unnecessary copies.

Temporary vectors of choices allow the game to add or change available actions based on player statistics and story progress without permanently changing the original scene data.

## Refactoring and Code Improvements

During development, I improved the organization and maintainability of the code by:

- Separating scene creation into `Story.cpp`.
    
- Separating story events into `StoryEvents.cpp`.
    
- Organizing player statistics and scene data into dedicated classes.
    
- Creating a reusable input-validation function.
    
- Centralizing conditional dialogue and skill checks in `GetAvailableChoices()`.
    
- Using references when accessing scene objects.
    
- Keeping story progression separate from player status display logic.
    

## Bug Fixes

I fixed several issues discovered during development and testing:

- Invalid menu and story inputs are now handled correctly.
    
- Nonnumeric inputs no longer cause normal gameplay to crash.
    
- Out-of-range choices are rejected.
    
- Repeated conversations with the director no longer apply certain suspicion changes multiple times.
    
- Director confrontation correctly changes available dialogue.
    
- An early return statement was corrected so additional Perception, Courage, and investigation clue options can become available.
    

## Usability Improvements

I improved the player's experience by adding:

- Clearly numbered menu and story choices.
    
- Helpful error messages for invalid input.
    
- Color-coded story text and endings.
    
- A player status screen accessible during gameplay.
    
- Visible notebook collection progress.
    
- Director suspicion and attitude information.
    
- Notifications for discoveries and character progression.
    

## Final Testing

I tested the game in Visual Studio using a successful build and gameplay runs.

Testing included:

- Starting a new game and returning to the main menu.
    
- Quitting through the main menu.
    
- Entering invalid inputs such as letters, negative numbers, and out-of-range numbers.
    
- Navigating between story scenes.
    
- Collecting notebook pages and unlocking the hidden entrance.
    
- Testing character skill checks and conditional choices.
    
- Testing director suspicion and confrontation.
    
- Reaching the good, neutral, and bad endings.
    

## Final Result

Camp Woodwreath is a playable branching horror game that demonstrates C++ object-oriented programming, vectors, references, input validation, conditional logic, and code refactoring.

Player decisions influence available story choices, investigation progress, and interactions with the camp director.

## Future Development

Possible future improvements include a save/load system, additional story branches, more supernatural encounters, and an expanded investigation journal.