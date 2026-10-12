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

	// Story Milestone Tracking
	bool mInvestigatedGrandPortage = false;
	bool mInvestigatedRangerStation = false;
	bool mInvestigatedTracks = false;

	//Status
	void ShowPlayerStatus() const;

public:
	void Start();
};

