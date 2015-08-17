#ifndef PLAYER_H
#define PLAYER_H
#include "Painter.h"
#include "UI.h"
#include <ctime>
#include <cstdlib>
#pragma once

namespace ATH
{
	class CPlayer
	{
	public:
		CPlayer ( CBoard::FIELD pChar, bool human )
			:pChar ( pChar ), human ( human ){};
		~CPlayer ( ){};

		//Set x, y and check if field is empthy set char
		void doMove ( CBoard*, CPainter&, CUI& )const;

		const CBoard::FIELD pChar;
	private:
		bool human;
	};
}
#endif