#pragma once
#include <vector>
#include <string>
#include "Game.h"
#include "GamePlayer.h"
#include "Writer.h"

template<class BOARD, class MOVE>
class AbstractGame:public Game
{
private:
	BOARD board;
	MOVE move;

	GamePlayer<BOARD, MOVE>* current_player;

	std::vector<GamePlayer<BOARD, MOVE>*> players;

	Writer& writer;
	
	void execute_round()
	{
		for (auto player : players)
		
			execute_move_for(player);
		
	}

	/// <summary>
	///
	/// 
	/// </summary>
	/// <param name="player"></param>
	void execute_move_for(GamePlayer<BOARD, MOVE>* player)
	{
		if (is_game_over()) return;

		set_current_player(player);
		execute_move_for_current_player();
	}

	void execute_move_for_current_player()
	{


		invoke_current_players_move();

		terminate_move();
	}

	void invoke_current_players_move()
	{
		do 	
			move = current_player->do_move(board);
		while (players_turn_is_invalid());
	}

	bool players_turn_is_invalid() const
	{
		if (is_move_valid()) return false;
		write("Ungueltiger Zug");
		
		return true;
	}
	void terminate_move()
	{
		update_board();
		write_game_over_message_if_game_is_over();
	}

	void write_game_over_message_if_game_is_over()const
	{
		if (is_game_over())
		{
			write(current_player->get_name() + " hat verloren");
		}
	}

	


protected:
	void write(const std::string& message) const
	{
		std::cout << message << std::endl;
	}

	
	GamePlayer<BOARD, MOVE>* get_current_player() const
	{
		return current_player;
	}

	void set_current_player(GamePlayer<BOARD, MOVE>* const current_player)
	{
		this->current_player = current_player;
	}

	std::vector<GamePlayer<BOARD, MOVE>*> get_players() const
	{
		return players;
	}
	
	[[nodiscard]] BOARD get_board() const
	{
		return board;
	}

	void set_board(const BOARD& board)
	{
		this->board = board;
	}

	[[nodiscard]] MOVE get_move() const
	{
		return move;
	}

	void set_move(const MOVE& move)
	{
		this->move = move;
	}

	virtual bool is_game_over() const = 0;
	virtual void update_board() = 0;
	virtual bool is_move_valid() const = 0;

public:

	AbstractGame(Writer& writer)
		: writer(writer)
	{
	}

	void add_player(GamePlayer<BOARD, MOVE>* player)
	{
		players.push_back(player);
	}

		
	void play() override
	{
		while (!is_game_over())
		{
			execute_round();
		}
	}
};

