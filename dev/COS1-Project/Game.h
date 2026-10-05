#pragma once

#include "Player.h"

class Game
{
private:
	Player player;

	void ShowTitleScreen();
	void StartNewGame();

public:
	void Start();
};

