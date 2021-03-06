#pragma once

/**
 * Header de Piece.cpp
 *
 * @file Piece.h
 */

#if !defined Piece_h
#define Piece_h

#include "Couleur.h"

class Echiquier;

using namespace std;

/**
 * @class Piece
 * Declaration d'une classe modelisant une piece de jeu d'echec.
 */
class Piece
{
protected:
    int m_x;
    int m_y;
    bool m_couleur;



public:
    Piece();
    virtual ~Piece();
    Piece(const Piece& p);
    Piece& operator=(const Piece& p);
    Piece(const int x, const int y, const bool c);

    void init(int x, int y, bool c);
    void deplace(int x, int y);

    int getX();
    int getY();
    char getColonne();
    int getLigne();
    bool getCouleur();

    virtual char codePiece();
    virtual bool mouvementValide(Echiquier& e, int x, int y);
};

#endif // !defined Piece_h