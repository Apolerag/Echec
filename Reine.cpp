#include "Reine.h"
#include "Piece.h"
#include <iostream>

Reine::Reine(Couleur c) : Piece(3, (c == Couleur::BLANC) ? 0 : 7, c), Tour(3, (c == Couleur::BLANC) ? 0 : 7, c), Fou(3, (c == Couleur::BLANC) ? 0 : 7, c)
{
}

bool Reine::mouvementValide(Echiquier& e, int x, int y)
{
    bool mouvementOk = false;

    if (Tour::mouvementValide(e, x, y) || Fou::mouvementValide(e, x, y))
    {
        cout << "\nLe mouvement de la Reine est valide." << endl;
        mouvementOk = true;
    }

    return (mouvementOk);
}

char Reine::codePiece()
{
    return (Piece::m_couleur == Couleur::BLANC) ? 'Q' : 'q';
}

