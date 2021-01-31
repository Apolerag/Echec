#include "Cavalier.h"
#include "Echiquier.h"
#include <iostream>

Cavalier::Cavalier(const int x, const int y, const bool c) : Piece(x, y, c)
{}

Cavalier::Cavalier(const char colonne, const int ligne, const bool c) : Piece(colonne - 'A', ligne - 1, c)
{}

bool Cavalier::mouvementValide(Echiquier& e, int x, int y)
{
    bool estValide = false;

    //Vérifier que la case d'arrivée est valide
    if ((abs(x - m_x) == 2 && abs(y - m_y) == 1) || (abs(x - m_x) == 1 && abs(y - m_y) == 2))
    {
        if (e.getPiece(x, y) != NULL)
        {
            if (e.getPiece(x, y)->getCouleur() != m_couleur)
            {
                e.enleverPiece(x, y);
                cout << "Le mouvement du Cavalier est valide." << endl;
                estValide = true;
            }
        }
        else
        {
            cout << "Le mouvement du Cavalier est valide." << endl;
            estValide = true;
        }
    }


    return estValide;
}

char Cavalier::codePiece()
{
    return (m_couleur == BLANC) ? 'C' : 'c';
}