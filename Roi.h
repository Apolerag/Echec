/**
 * Header de Roi.cpp
 *
 * @file Roi.h
 */

#if !defined Roi_h
#define Roi_h

#include "Piece.h"

class Roi : public Piece
{
public:
    Roi(const int x, const int y, const bool c);
    Roi(const char colonne, const int ligne, const bool c);
    bool mouvementValide(Echiquier& e, int x, int y);
    char codePiece();
};

#endif // !defined Roi_h