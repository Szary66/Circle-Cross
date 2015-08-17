#include "Player.h"

namespace ATH
{
	void CPlayer::doMove ( CBoard* board, CPainter &painter, CUI &UI )const
	{
		int x, y;
		if ( !human && board->emptyFields < 0)
		{
			do
			{
				std::cout << "Cross moves!\n";
				x = rand ( ) % 3 + 1;
				y = rand ( ) % 3 + 1;
			} while ( board->board [y] [x] != CBoard::EMPTY );
		}
		else if (human && board->emptyFields < 0)
		{
			do
			{
				//Clear screen and draw board again
				system ( "cls" );
				painter.drawBoard ( board );

				std::cout << "Circle moves!\n";
				x = UI.choiseX ( );
				y = UI.choiseY ( );
			} while ( board->board [y] [x] != CBoard::EMPTY );
		}
		//Set value
		board->board [y] [x] = this->pChar;
		board->emptyFields--;
	}
}

