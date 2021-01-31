#include "Roi.h"
#include "Echiquier.h"
#include "Piece.h"
#include <cmath>
#include <iostream>

Roi::Roi(const int x, const int y, const bool c) :Piece(x, y, c)
{
}

Roi::Roi(const char colonne, const int ligne, const bool c) : Piece(colonne-'A', ligne-1, c)
{
}

bool Roi::mouvementValide(Echiquier& e, int x, int y)
{
    bool estValide = false;

    if ((abs(x - m_x) <= 1) && (abs(y - m_y) <= 1))
    {
        //Vérifier si piece présente ou pas sur case d'arrivée
        if (e.getPiece(x, y) != NULL)
        {
            if (e.getPiece(x, y)->getCouleur() != m_couleur)   //Si pièce couleur joueur adverse alors on l'enlève !
            {
                e.enleverPiece(x, y);
                cout << "Le mouvement du Roi est valide" << endl;
                estValide = true;
            }
        }
        else
        {
            cout << "Le mouvement du Roi est valide" << endl;
            estValide = true;
        }
    }

    return estValide;
}

char Roi::codePiece()
{
    return (m_couleur == BLANC) ? 'R' : 'r';
}
