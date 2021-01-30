#include "Reine.h"
#include "Piece.h"
#include <iostream>

Reine::Reine(Couleur c) : Tour(c, true), Fou(c, true)
{
    this->Tour::m_x = 3;
    this->Tour::m_y = (c == Couleur::BLANC) ? 0 : 7;
    this->Tour::m_couleur = c;
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
    return (Tour::m_couleur == Couleur::BLANC) ? 'Q' : 'q';
}
