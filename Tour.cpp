#include "Tour.h"
#include "Echiquier.h"
#include <iostream>

Tour::Tour(const int x, const int y, const bool c) : Piece(x, y, c)
{
}

Tour::Tour(const char colonne, const int ligne, const bool c) : Piece(colonne - 'A', ligne - 1, c)
{
}

bool Tour::mouvementValide(Echiquier& e, int x, int y)
{
    int xDepart = this->getX(); //R�cup�ration du d�part de la pi�ce
    int yDepart = this->getY();
    bool estValide = false;

    int pasX = 0;// (ecartX > 0) ? 1 : -1;
    int pasY = 0;// (ecartY > 0) ? 1 : -1;

    if (xDepart == x && yDepart != y)
    {
        pasY = (m_y < y) ? 1 : -1;
    }

    if (yDepart == y && xDepart != x)
    {
        pasX = (m_x < x) ? 1 : -1;
    }


    //v�rifier si pi�ce sur chemin et v�rifier si pi�ce sur case d'arriv�e et sa couleur
    if ((pasX != 0 && pasY == 0) || (pasX == 0 && pasY != 0))
    {
        while ((xDepart == x && yDepart == y) == false)
        {
            xDepart += pasX;
            yDepart += pasY;

            if (e.getPiece(xDepart, yDepart) != NULL)
            {
                if (xDepart != x || yDepart != y) // il y a une piece sur le chemin
                {
                    break;
                }
                else if (xDepart == x && yDepart == y && e.getPiece(x, y)->getCouleur() != m_couleur)   //Si pi�ce couleur joueur adverse alors on l'enl�ve !
                {
                    e.enleverPiece(x, y);
                    cout << "Le mouvement de la Tour est valide : d�placement" << endl;
                    estValide = true;
                    break;
                }
            }
            else if (xDepart == x && yDepart == y)
            {
                cout << "Le mouvement de la Tour est valide : d�placement" << endl;
                estValide = true;
                break;
            }
        }

    }

    return estValide;
}

char Tour::codePiece()
{
    return (m_couleur == BLANC) ? 'T' : 't';
}
