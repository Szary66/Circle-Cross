#ifndef BOARD_H
#define BOARD_H
#pragma once

namespace ATH
{
	//Class pressent board and her field's state
	class CBoard
	{
	public:
		//Friend deklaration with Pointer
		friend class CPainter;
		//Friend deklaration with Player
		friend class CPlayer;
		//Field state
		enum FIELD { EMPTY, CROSS, CIRCLE };

		CBoard ( );
		~CBoard ( );

		friend void save ( CBoard* );
		
		//Check is win and who is winner
		bool checkWin ( bool );
		//Set new board 
		void operator=( CBoard );

		//Set board's field
		void setField ( short, short, FIELD );

		//Get how many empthy fields are in the board
		int getEmpthy ()const
		{ return emptyFields; }

		//Serialize for boost library
		template<class Archive>
		void serialize ( Archive & ar, const unsigned int version )
		{
			ar &board;
		}
	private:
		int board [3] [3];
		int emptyFields;
	};
}

#endif