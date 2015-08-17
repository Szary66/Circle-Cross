#include "Board.h"

namespace ATH
{
	CBoard::CBoard ( )
	{}


	CBoard::~CBoard ( )
	{}

	void CBoard::operator=( CBoard board )
	{
		for ( int i = 0; i < 4; ++i )
			for ( int k = 0; k < 4; ++k )
				this->board [i] [k] = board.board [i] [k];
	}


	void CBoard::setField ( short x, short y, FIELD field )
	{
		board [x] [y] = field;
	}
}