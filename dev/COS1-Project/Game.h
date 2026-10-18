#pragma once

#include "Player.h"
#include "Scene.h"

#include <vector>

class Game
{
private:
	Player player;

	int GetValidatedChoice(int minimum, int maximum);

	std::vector<Scene> scenes;

	void ShowTitleScreen();
	void StartNewGame();

	void CreateScenes();
	void PlayScene(int sceneIndex);

	// Week 3 Scene System Refactoring
	void HandleSceneEvents(int sceneIndex);
	std::vector<Choice> GetAvailableChoices(int sceneIndex);

	// Story Milestone Tracking
	bool mInvestigatedGrandPortage = false;
	bool mInvestigatedRangerStation = false;
	bool mInvestigatedTracks = false;
	bool mIntroducedToDirector = false;

	// Status
	void ShowPlayerStatus() const;

	// Character Suspicion System
	int mDirectorSuspicion = 0;
	bool mAskedAboutMissingPeople = false;
	bool mReassuredDirector = false;
	bool mConfrontedDirector = false;

public:
	void Start();
};

