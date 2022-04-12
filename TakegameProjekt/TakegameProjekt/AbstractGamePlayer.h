#pragma once

#include "GamePlayer.h"
template<class BOARD, class MOVE>
class AbstractGamePlayer :
	public GamePlayer<BOARD,MOVE>
{
	std::string name;

public:


	AbstractGamePlayer(const std::string& name) :name(name)
	{


	}

	std::string get_name() const override
	{
		return name;
	}
};

