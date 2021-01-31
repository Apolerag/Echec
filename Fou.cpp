/**
 * Mise en oeuvre de Fou.h
 *
 * @file Fou.cpp
 */

#include "Fou.h"
#include <iostream>
#include "Echiquier.h"

Fou::Fou(const int x, const int y, const bool c) : Piece(x, y, c)
{
}

Fou::Fou(const char colonne, const int ligne, const bool c) : Piece(colonne - 'A', ligne - 1, c)
{
}

bool Fou::mouvementValide(Echiquier& e, int x, int y)
{
    int xDepart = this->getX(); //Récupération du départ de la pièce
    int yDepart = this->getY();
    bool estValide = false;
    int ecartX = x - xDepart;
    int ecartY = y - yDepart;

    int pasX = (ecartX > 0) ? 1 : -1;
    int pasY = (ecartY > 0) ? 1 : -1;

    //vérifier si pièce sur chemin et vérifier si pièce sur case d'arrivée et sa couleur
    if (ecartX == ecartY || ecartX == -ecartY)   //pour aller en diagonale
    {

        while (xDepart != x && yDepart != y)
        {
            xDepart += pasX;
            yDepart += pasY;

            if (e.getPiece(xDepart, yDepart) != NULL)
            {
                if (xDepart != x || yDepart != y) // il y a une piece sur le chemin
                {
                    break;
                }
                else if (xDepart == x && yDepart == y && e.getPiece(x, y)->getCouleur() != this->getCouleur())   //Si pièce couleur joueur adverse alors on l'enlève !
                {
                    e.enleverPiece(x, y);
                    estValide = true;
                    break;
                }
            }
            else if (xDepart == x && yDepart == y)
            {
                estValide = true;
                break;
            }

        }

    }
    return estValide;
}

char
Fou::codePiece()
{
    return (m_couleur == BLANC) ? 'F' : 'f';
}
