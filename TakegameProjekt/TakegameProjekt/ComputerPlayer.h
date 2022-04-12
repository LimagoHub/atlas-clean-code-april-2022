#pragma once
#include <iostream>
#include <vector>
#include <type_traits>
#include "AbstractNimgamePlayer.h"
class ComputerPlayer :
    public AbstractNimgamePlayer
{
public:
	ComputerPlayer()
		: AbstractNimgamePlayer(typeid(ComputerPlayer).name())
	{
	}

	int do_move(const int& stones) const override
	{
		const std::vector<int> moves{ 3,1,1,2 };

		int move = moves[stones % 4];
		std::cout << "Computer nimmt " << move << " Steine." << std::endl;
		return move;
	}
};

