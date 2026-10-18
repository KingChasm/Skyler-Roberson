# Milestone 3 — Camp Woodwreath

## Overview

During Milestone 3, I focused on improving the organization and reliability of Camp Woodwreath while expanding the branching supernatural horror storyline.

## Features Added

### Hunting Skill Encounter
- Added Scene 16: Signs of the Beast.
- Players with sufficient Hunting skill can examine claw marks in the underground passage.
- This allows players to recognize evidence of a werewolf.

### Stealth Skill Encounter
- Added Scene 17: Hidden in the Shadows.
- Players can earn Stealth by pretending to be interested in attending the camp.
- Players with sufficient Stealth can hide from an approaching creature.
- Both new encounters connect to existing escape routes.

## System Design Improvements

I continued using separate Player, Scene, and Game classes to organize the application.

I improved the Game class by separating story events from conditional choices. This makes it easier to expand the game without placing every gameplay condition inside the main scene loop.

## Refactoring Improvements

### Separated Scene Events

I moved scene-specific events into `HandleSceneEvents()`.

This function manages events such as collecting notebook pages, increasing player stats, and changing the director's attitude.

**Why:** Keeping these events in a dedicated function makes the scene navigation code easier to read and maintain.

### Separated Conditional Choices

I moved conditional choice logic into `GetAvailableChoices()`.

This function determines which choices are available based on player stats, collected evidence, and previous decisions.

**Why:** Separating this logic makes it easier to add skill checks and branching story options.

### Improved Navigation Safety

I added scene index validation before accessing scenes.

**Why:** This prevents the game from attempting to access an invalid scene index and provides a safer way to return to the main menu if an invalid index is encountered.

## Testing and Debugging

I tested the new Hunting and Stealth encounters to confirm that the appropriate choices become available when their requirements are met.

I also tested input validation and navigation between scenes.

Both new underground encounters have exits that return players to existing story locations or the escape ending.

## Challenges and Solutions

One challenge was managing the increasing number of conditional choices. Refactoring the scene system helped keep the code organized.

Another challenge was making the Stealth encounter accessible. Since Stealth originally had no progression opportunity, I added a milestone that rewards players for pretending to be campers.

## Next Steps

During the next milestone, I plan to expand the underground storyline, introduce more consequences for player decisions, and develop additional endings based on the player's actions.
