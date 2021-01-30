#pragma once
#include "Piece.h"
class Tour : public Piece
{
public:
	Tour(Couleur c, bool left);
	bool mouvementValide(Echiquier& e, int x, int y);
	char codePiece();
};

