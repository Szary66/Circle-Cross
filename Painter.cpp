#include "Painter.h"

namespace ATH
{
	CPainter::CPainter ( CBoard* board )
	{
		clear ( board );
	}


	void CPainter::drawBoard ( CBoard* board )const
	{
		using namespace std;
		system ( "cls" );

		cout << "  0 1 2" << endl
			<< " -------";

		for ( int i = 0; i < 3; i++ )
		{
			cout << endl << i << "|";
			for ( int k = 0; k < 3; k++ )
			{
				switch ( board->board [i] [k] )
				{
				case CBoard::CROSS:
					cout << "X|";
					break;
				case CBoard::CIRCLE:
					cout << "O|";
					break;
				default:
					cout << " |";
					break;
				}
			}
			cout << endl << " -------";
		}
	}


	void CPainter::clear ( CBoard* board )const
	{
		for ( int i = 0; i < 3; ++i )
			for ( int k = 0; k < 3; ++k )
				board->board [i] [k] = CBoard::EMPTY;
	}


	void CPainter::showWinner ( CBoard* board,  CBoard::FIELD winner )const
	{
		//clear screen and draw board
		system ( "cls" );
		drawBoard ( board ); 
				
		//show winner and congratulation
		std::cout << "THE WINNER IS: ";
		if ( winner == CBoard::CIRCLE )
			std::cout << "O! GOOD JOB!" << std::endl;
		else if ( winner == CBoard::CROSS )
			std::cout << "X! GOOD JOB!";
	}
}