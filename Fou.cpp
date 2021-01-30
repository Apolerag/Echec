#include "Fou.h"
#include <iostream>
#include "Echiquier.h"

Fou::Fou(Couleur c, bool left) : Piece(left ? 2 : 5, (c == Couleur::BLANC) ? 0 : 7, c)
{
}

bool Fou::mouvementValide(Echiquier& e, int x, int y)
{
    int xDepart = this->getX(); //Récupération du départ de la pièce
    int yDepart = this->getY();
    Couleur couleurFou = this->getCouleur();
    bool estValide = false;
    int ecartX = x - xDepart;
    int ecartY = y - yDepart;

    int pasX = (ecartX > 0) ? 1 : -1;
    int pasY = (ecartY > 0) ? 1 : -1;

    //vérifier si pièce sur chemin et vérifier si pièce sur case d'arrivée et sa couleur
    if (ecartX == ecartY || ecartX == -ecartY)   //pour aller en diagonale
    {

        while (xDepart != x && yDepart != y) //ET ou OU
        {
            xDepart += pasX;
            yDepart += pasY;

            if (e.getPiece(yDepart, yDepart) != NULL)
            {
                if (xDepart == x && yDepart == y && e.getPiece(x, y)->getCouleur() != couleurFou)   //Si pièce couleur joueur adverse alors on l'enlève !
                {
                    e.enleverPiece(x, y);
                    cout << "Le mouvement du Fou est valide : déplacement" << endl;
                    estValide = true;
                }
            }
            else if (xDepart == x && yDepart == y && estValide == false)
            {
                cout << "Le mouvement du Fou est valide : déplacement" << endl;
                estValide = true;
            }

        }

    }
    return estValide;
}

char
Fou::codePiece()
{
    return (m_couleur == Couleur::BLANC) ? 'F' : 'f';
}