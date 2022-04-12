#pragma once
#include "Game.h"
#include <iostream>
#include <vector>
#include <string>
class NimgameImpl: public Game
{
	int stones;
	int move;
	
	

	void execute_moves() // Integration
	{
		human_move();
		computer_move();
	}

	

	void human_move()
	{
		if (is_game_over())
			return;
		
		while(true)
		{
			std::cout << "Es gibt " << stones << " Steine. Bitte nehmen Sie 1, 2 oder 3!" << std::endl;
			std::cin >> move;
			if (move >= 1 && move <= 3) break;
			std::cout << "Ungueltiger Zug" << std::endl;
		}
		terminate_turn("Du Loser");
	}
	void computer_move()
	{
		if (is_game_over())
			return;
		
		const std::vector<int> moves{ 3,1,1,2 };
		

		move = moves[stones % 4];
		std::cout << "Computer nimmt " << move << " Steine." << std::endl;

		terminate_turn("Du hast nur Glück gehabt");
	}


	

	void terminate_turn(std::string message)
	{
		update_board();
		write_game_over_message_if_game_is_over(message);
	}
	
	void write_game_over_message_if_game_is_over(std::string message)
	{
		if (is_game_over())
		{
			std::cout << message << std::endl;

		}
	}
	
	bool is_game_over() const
	{
		return stones < 1;
	}
	void update_board()
	{
		stones -= move;
	}

public:

	NimgameImpl():stones(23)
	{
	}



	void play() override
	{
		while( ! is_game_over())
		{
			execute_moves();
		}
	}
};
