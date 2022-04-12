#pragma once
#include "Game.h"

class GameClient
{
	Game& game;


public:
	GameClient(Game& game)
		: game(game)
	{
	}

	void run()
	{
		game.play();
	}
};

