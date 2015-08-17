#ifndef UI_H
#define UI_H
#pragma once
#include <iostream>
#include "Board.h"

namespace ATH
{
	//Class present user interface
	class CUI
	{
	public:
		CUI ( );
		~CUI ( );
		//main menu game
		unsigned short menu ( )const;
		// new game menu
		unsigned short newGame ( )const;
		//Show winner and congratulation
		void showWinner ( CBoard::FIELD );
		//Choose x and return it
		unsigned short choiseX ( )const;
		//Choose y and return it
		unsigned short choiseY ( )const;
	};
}
#endif