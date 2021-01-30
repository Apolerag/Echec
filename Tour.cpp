#include "Tour.h"
#include "Echiquier.h"
#include <iostream>

Tour::Tour(Couleur c, bool left) : Piece(left ? 0 : 7, (c == Couleur::BLANC ? 0 : 7), c)
{
}

bool Tour::mouvementValide(Echiquier& e, int x, int y)
{
	bool estValide = false;
	int i = 0;  //pour indice de boucle


	//v�rifier si pi�ce sur chemin et v�rifier si pi�ce sur case d'arriv�e et sa couleur
	if (x == m_x && y != m_y && y >= 0 && y <= 7)
	{
		int pasY = (m_y < y) ? 1 : -1;
		i = m_y;

		do
		{
			i += pasY;
			if (e.getPiece(x, i) != NULL)
			{
				if (i == y && e.getPiece(x, i)->getCouleur() != m_couleur)   //Si pi�ce couleur joueur adverse alors on l'enl�ve !
				{
					e.enleverPiece(x, y);
					cout << "Le mouvement de la Tour est valide : deplacement colonne" << endl;
					estValide = true;
					break;
				}
			}
			else if (i == y)
			{
				cout << "Le mouvement de la Tour est valide : deplacement colonne" << endl;
				estValide = true;
				break;
			}

		} while (i != y);

	}
	else if (y == m_y && x != m_x && x >= 0 && x <= 7)
	{
		int pasX = (m_x < x) ? 1 : -1;
		i = m_x;

		do
		{
			i += pasX;
			if (e.getPiece(i, y) != NULL)
			{
				if (i == x && e.getPiece(i, y)->getCouleur() != m_couleur)   //Si pi�ce couleur joueur adverse alors on l'enl�ve !
				{
					e.enleverPiece(x, y);
					cout << "Le mouvement de la Tour est valide : deplacement Droit" << endl;
					estValide = true;
					break;
				}
			}
			else if (i == x)
			{
				cout << "Le mouvement de la Tour est valide : deplacement ligne" << endl;
				estValide = true;
				break;
			}
		} while (i != x);
	}

	return estValide;
}

char Tour::codePiece()
{
	return (m_couleur == Couleur::BLANC) ? 'T' : 't';
}
