#include "Reine.h"
#include "Piece.h"
#include <iostream>

Reine::Reine(const int x, const int y, const bool c) : Piece(x, y, c), Fou(x,y,c), Tour(x,y,c)
{
}

Reine::Reine(const char colonne, const int ligne, const bool c): Piece(colonne-'A',ligne-1,c), Fou(colonne - 'A', ligne - 1, c),
                                                  Tour(colonne - 'A', ligne - 1, c)
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
    return (Piece::m_couleur == BLANC) ? 'Q' : 'q';
}

