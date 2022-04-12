#pragma once

#include "AbstractGamePlayer.h"

class AbstractNimgamePlayer :
    public AbstractGamePlayer<int,int>
{
	

public:

	
	AbstractNimgamePlayer(const std::string& name) :AbstractGamePlayer<int, int>(name)

	{


	}

	
};

