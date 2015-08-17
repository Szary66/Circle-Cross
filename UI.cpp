#include "UI.h"

namespace ATH
{
	CUI::CUI ( )
	{}


	CUI::~CUI ( )
	{}


	unsigned short CUI::menu ( )const
	{
		using namespace std;

		while ( true )
		{
			cout << "NEW GAME: 1" << endl
				<< "LOAD GAME: 2" << endl
				<< "EXIT GAME: 3" << endl;

			unsigned short choise;
			cin >> choise;
			if ( choise < 4 )
				return choise;
		}
	}


	unsigned short CUI::newGame ( )const
	{
		using namespace std;

		while ( true )
		{
			cout << "ONE PLAYER: 1" << endl
				<< "TWO PLAYER: 2" << endl
				<< "BACK: 3" << endl;

			unsigned short choise;
			cin >> choise;

			if ( choise < 4 )
				return choise;
		}
	}


	unsigned short CUI::choiseX ( )const
	{
		std::cout << "\nWybierz kolumne: ";
		unsigned short x;
		std::cin >> x;
		return x;
	}


	unsigned short CUI::choiseY ( )const
	{
		std::cout << "Wybierz szereg: ";
		unsigned short y;
		std::cin >> y;
		return y;
	}
}