#pragma once
#include <string>
template<class BOARD, class MOVE>
class GamePlayer
{
public:
	virtual std::string get_name() const = 0;
	virtual MOVE do_move(const BOARD& board) const = 0;
};