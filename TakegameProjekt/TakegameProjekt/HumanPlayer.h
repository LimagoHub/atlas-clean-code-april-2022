#pragma once
#include <iostream>
#include <type_traits>
#include "AbstractNimgamePlayer.h"
class HumanPlayer :
    public AbstractNimgamePlayer
{
public:
	HumanPlayer()
		: AbstractNimgamePlayer(typeid(HumanPlayer).name())
	{
	}

	int do_move(const int& stones) const override
	{
		int move;
		std::cout << "Es gibt " << stones << " Steine. Bitte machen Sie Ihre Eingabe: " << std::endl;
		std::cin >> move;
		return move;
	}
};

