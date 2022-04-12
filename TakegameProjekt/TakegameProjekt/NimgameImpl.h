#pragma once
#include "Game.h"
#include <iostream>
#include <vector>

class NimgameImpl: public Game
{
	int stones;
	bool gameover;

	void execute_moves()
	{
		human_move();
		computer_move();
	}
	void human_move()
	{
		int move;
		while(true)
		{
			std::cout << "Es gibt " << stones << " Steine. Bitte nehmen Sie 1, 2 oder 3!" << std::endl;
			std::cin >> move;
			if (move >= 1 && move <= 3) break;
			std::cout << "Ungueltiger Zug" << std::endl;
		}
		stones -= move;
	}
	void computer_move()
	{
		const std::vector<int> moves{ 3,1,1,2 };
		int move;

		if(stones == 1)
		{
			std::cout << "Du hast nur Glueck gehabt." << std::endl;
			gameover = true;
			return;
		}
		
		if (stones < 1)
		{
			std::cout << "Du Loser" << std::endl;
			gameover = true;
			return;
		}

		move = moves[stones % 4];
		std::cout << "Computer nimmt " << move << " Steine." << std::endl;
		stones -= move;
	}

public:

	NimgameImpl():stones(23), gameover(false)
	{
	}



	void play() override
	{
		while( ! gameover)
		{
			execute_moves();
		}
	}
};
