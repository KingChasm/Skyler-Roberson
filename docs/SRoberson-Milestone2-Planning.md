> Use this worksheet to plan the next phase of your project **before you begin coding**.
> Be clear, specific, and intentional—this will guide your development this week.

---
## 📌 Project Overview

**Project Name:**  
→ Camp Woodwreath

**What does your program currently do? (1–3 sentences)**  
→ Camp Woodwreath is a C++20 console-based, branching horror story set near Grand Portage, Minnesota. The player investigates disappearances by exploring scenes and selecting numbered choices. The foundation includes a title menu, Player, Game, and Scene systems, and basic player statistics.

---
## 🔍 Current Progress Check

**What is working right now?**  
→ The game starts in the console, shows a title menu, creates story scenes, and lets the player move between them using numbered choices. The Player class tracks six stats, and the Scene and Choice structures support branching paths.

**What is NOT working or incomplete?**  
→ At the start of this milestone, the story needed more investigation content, collectible lore, meaningful stat requirements, and decisions that affect later conversations. Multiple endings and more advanced supernatural encounters remain future goals.

**What feels confusing or messy in your code?**  
→ As the number of scenes grows, it becomes harder to keep scene indexes, branching destinations, and conditional choices organized. I need to make sure that scene-specific rewards and dialogue consequences do not trigger repeatedly when the player revisits a location.

---
## 🚀 Feature Planning

List the features you plan to add or improve this week.

### Feature 1
**Name:** Lore Collection and Hidden Investigation Paths  
→

**What does this feature do?**  
→ Allow the player to collect three notebook pages while exploring Grand Portage and Camp Woodwreath. Track which pages have already been collected and reveal a hidden entrance beneath the lodge after all three are found.

**Why is this feature important?**  
→ It rewards exploration, gives players a reason to investigate multiple locations, and shows how earlier discoveries can unlock new story choices.

---
### Feature 2
**Name:** Stat-Based Choices and Milestone Progression  
→

**What does this feature do?**  
→ Award stat increases for specific discoveries or interactions, then use stat checks to unlock selected investigation and dialogue options. Keep stats on a 0–10 scale and prevent repeated rewards for revisiting scenes.

**Why is this feature important?**  
→ It makes character progression meaningful and helps different player decisions produce different experiences instead of only changing the next paragraph of text.

---
### Feature 3 (optional)
**Name:** Director Suspicion and Story Consequences  
→

**What does this feature do?**  
→ Track Director Woodwreath's Suspicion as the player questions him. Allow some dialogue to increase or reduce Suspicion, and change future lodge interactions if the player confronts him. Connect the investigation to a short prototype ending.

**Why is this feature important?**  
→ It creates consequences for dialogue choices and provides a small but complete story arc that can be tested before expanding into additional endings.

---
## 🧩 System Design Updates

**Will you need to create any new classes? If so, which ones?**  
→ No new classes are required for this milestone. I can extend the existing Player, Game, and Scene classes. Choice can remain a struct containing choice text and the destination scene index.

**Will you modify any existing classes? How?**  
→ Player will gain notebook collection, stat increases, and stat requirement checks. Game will track investigation milestones, Director Woodwreath's Suspicion, dialogue decisions, and conditional choices. Scene will continue to hold story titles, descriptions, and choices; additional Scene objects will expand the narrative.

**What data structures will you use (vectors, 2D vectors, etc.)?**  
→ A `std::vector<Scene>` will hold the game's scenes, and each Scene will use a `std::vector<Choice>` for available actions. A `std::set<int>` will store unique notebook page IDs. Integers will track player stats and Suspicion, while Boolean variables will track completed milestones and dialogue decisions. A temporary vector of choices will allow the game to add or restrict options based on current progress.

---
## 🔄 Program Flow

**Describe how a user interacts with your program:**

1. **Program starts →** The console displays the Camp Woodwreath title menu.
2. **User chooses →** The player starts a new investigation and selects numbered exploration or dialogue choices; entering `0` during a scene opens Player Status.
3. **Program responds →** The game validates input, displays the selected scene, awards any first-time discoveries, updates relevant flags or Suspicion, and determines which choices are available.
4. **Loop/next step →** The player continues investigating and revisiting locations until they reach the prototype ending or choose to exit. Starting a new game resets the previous playthrough's progress.

---
## 🎯 Usability Improvements

How will you make your program easier to use this week?

- **Clearer prompts:**  
→ Display numbered options beneath each scene and provide a consistent `[0] View Player Status` option.

- **Better error handling:**  
→ Reject letters, words, and numbers that have nothing to do with the available options and prompt the player to enter a different option

- **Improved menu/navigation:**  
→ Keep return routes between major investigation locations, display progress through the status screen, and make the prototype ending clearly identifiable.

---
## ⚠️ Potential Challenges

**What do you think will be the hardest part this week?**  
→ Managing conditional choices without accidentally showing locked options, sending the player to the wrong scene, or awarding the same milestone repeatedly. Scene indexes also need to stay aligned with the order in which scenes are added to the vector.

**What is your plan if you get stuck?**  
→ Build and test one feature at a time, reproduce the issue with a specific route through the story, inspect the relevant conditions and scene destinations, and use Visual Studio debugging and compiler messages to locate mistakes. After each fix, retest the affected choices.

---
## 📈 Level Up Goal

**What skill are you focusing on improving this week?**  
→ Organizing C++ program state and writing reliable conditional logic for branching gameplay.

**What will you do to improve it?**  
→ Practice using vectors, sets, Boolean flags, and class methods; test several story routes; debug incorrect choice placement or navigation; and make small Git commits as features become stable.

---
## 🗓️ Task Breakdown (GitHub Issues Planning)

List the tasks you plan to create as GitHub Issues:

- [x] Implement collectible notebook pages and the hidden lodge entrance.
- [x] Add milestone stat increases and stat-dependent choices.
- [x] Implement Director Woodwreath's Suspicion and dialogue consequences.
- [x] Add and test a playable ending and status/navigation improvements.

*These items are checked because they have been implemented in the current prototype. Create or update corresponding GitHub Issues to reflect the completed work.*

---
## 🔥 Final Check

Before you start coding, ask yourself:

- [x] Do I know what I’m building this week?
- [x] Do I know where to start?
- [x] Did I break my work into small tasks?

If yes → start coding 🚀  
If no → refine your plan first

---
## 😈 Final Thought

> Plan it now… or debug it later.
