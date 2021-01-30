#include "Roi.h"
#include "Echiquier.h"
#include "Piece.h"
#include <cmath>
#include <iostream>

Roi::Roi(Couleur c)
{
    m_x = 4; // 'E'
    m_y = (c == Couleur::BLANC) ? 0 : 7; //1 pour roi Blanc, 8 pour roi Noir
    m_couleur = c;
}

bool Roi::mouvementValide(Echiquier& e, int x, int y)
{
    bool estValide = false;

    if ((abs(x - m_x) <= 1) && (abs(y - m_y) <= 1))
    {
        //V�rifier si piece pr�sente ou pas sur case d'arriv�e
        if (e.getPiece(x, y) != NULL)
        {
            if (e.getPiece(x, y)->getCouleur() != m_couleur)   //Si pi�ce couleur joueur adverse alors on l'enl�ve !
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
    return (m_couleur == Couleur::BLANC) ? 'R' : 'r';
}
