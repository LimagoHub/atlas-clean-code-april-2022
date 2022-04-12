#pragma once

#include "AbstractGame.h"
#include "ConsolenWriter.h"


class NimgameImpl: public AbstractGame<int, int>
{
	
protected:
	bool is_game_over() const override
	{
		return get_board() < 1  || get_players().empty();
	}
	void update_board()  override
	{
		set_board(get_board() - get_move());
	}
	bool is_move_valid() const  override
	{
		return get_move() >= 1 && get_move() <= 3;
	}

public:


	NimgameImpl(Writer& writer)
		: AbstractGame<int, int>(writer)
	{
		set_board(23);
	}

	

	
};
