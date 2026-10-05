#pragma once

#include "Player.h"
#include "Scene.h"

#include <vector>

class Game
{
private:
	Player player;

	std::vector<Scene> scenes;

	void ShowTitleScreen();
	void StartNewGame();

	void CreateScenes();
	void PlayScene(int sceneIndex);

public:
	void Start();
};

