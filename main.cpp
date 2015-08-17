#include <fstream>
#include "Painter.h"
#include "Player.h"
#include "UI.h"
#include <boost\archive\text_oarchive.hpp>
#include <boost\archive\text_iarchive.hpp>

//Save board to file
void save ( ATH::CBoard* board );

//Load board from file
ATH::CBoard load ( );

//Create players
//Players list
//bool - first player is human and second player is human
void createPlayers ( ATH::CPlayer* [], bool, bool );

auto main ( int arg, char** args )-> int
{
	std::srand ( time ( nullptr ) );

	ATH::CBoard* board = new ATH::CBoard ( );
	ATH::CPainter painter ( board );
	ATH::CUI UI;
	
	//Flag choise
	unsigned short choise;

	//Players
	ATH::CPlayer* players [2];

	//Main loop menu
	do
	{
		choise = UI.menu ( );
		if ( choise == 1 )      //New game
		{
			if ( UI.newGame ( ) == 1 ) //one human and PC
				createPlayers ( players, true, false );
			else                       //Two humans
				createPlayers ( players, true, true );
		}
		else if ( choise == 2 ) //Load game
			*board = load ( );
		else
			return EXIT_SUCCESS;

		//Flag winner
		bool win;
		if ( choise < 3 )
			win = false;
		else
			win = true;
		
		//Main loop gameplay
		while ( !win && board->getEmpthy() < 0)
		{
			players [0]->doMove ( board, painter, UI );
			players [1]->doMove ( board, painter, UI );

			//save
			painter.drawBoard ( board );
			//check win
			//if win cout << winner
		}
	}while( choise != 3 );

	//Clear memory
	delete [] players;
	delete board;

	return EXIT_SUCCESS;
}


void save ( ATH::CBoard* board )
{
	std::ofstream ofs ( "..\save.ath" );
	boost::archive::text_oarchive oa ( ofs );
	oa << board;
}


ATH::CBoard load ( )
{
	ATH::CBoard board;

	std::ifstream ifs ( "..\save.ath" );
	boost::archive::text_iarchive ia ( ifs );
	ia >> board;

	return board;
}


void createPlayers ( ATH::CPlayer* players[] , bool human1, bool human2 )
{
	players [0] = new ATH::CPlayer ( ATH::CBoard::CROSS, human1 );
	players [1] = new ATH::CPlayer ( ATH::CBoard::CIRCLE, human2 );
}
