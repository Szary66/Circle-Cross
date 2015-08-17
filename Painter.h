#ifndef PAINTER_H
#define PAINTER_H
#pragma once
#include "Painter.h"
#include "Board.h"
#include <iostream>

namespace ATH 
{
	//Class draw end clear board
	class CPainter
	{
	public:
		//Set all values on 0
		CPainter ( CBoard* );
		CPainter ( ){};
		~CPainter ( ){};

		//Draw board on screen
		void drawBoard ( CBoard* )const;
		//Set all values board on 0
		void clear ( CBoard* )const;

		//Show board and winner
		void showWinner ( CBoard*, CBoard::FIELD )const;
	};
}
#endif