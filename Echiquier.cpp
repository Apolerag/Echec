/**
 * Mise en oeuvre de Echiquier.h
 *
 * @file Echiquier.cpp
 */

#include <iostream>
#include "Echiquier.h"
#include "Piece.h"

int Echiquier::conversion(int x, int y)
{
	return x * 8 + y;
}

int Echiquier::conversion(char colonne, int ligne)
{
	return conversion(colonne - 'A', ligne - 1);
}

Echiquier::Echiquier()
{
	for (int i = 0; i < 64; i++)
	{
		m_cases[i] = NULL;
	}
}

Echiquier::~Echiquier()
{
	for (int i = 0; i < 64; i++)
	{
		if (m_cases[i] != NULL)
		{
			delete m_cases[i];
		}
	}
}

/**
 * Recupere la piece situee sur une case.
 *
 * @param x un entier entre 0 et 7
 * @param y un entier entre 0 et 7
 *
 * @return 0 si aucune piece n'est sur cette case et un pointeur
 * vers une piece sinon.
 */
Piece* Echiquier::getPiece(int x, int y)
{
	if (coordonneesValide(x, y))
		return m_cases[conversion(x - 1, y - 1)];
	return NULL;
}

/**
* Recupere la piece situee sur une case.
*
* @param colonne un char entre 'A' et 'H'
* @param ligne un entier entre 1 et 8
*
* @return 0 si aucune piece n'est sur cette case et un pointeur
* vers une piece sinon.
*/
Piece* Echiquier::getPiece(char colonne, int ligne)
{
	if (coordonneesValide(colonne, ligne))
		return getPiece(colonne - 'A', ligne - 1);
	return NULL;
}

/**
 * Place une piece sur l'echiquier, aux coordonnees specifiees dans la piece.
 *
 * @param p un pointeur vers une piece
 *
 * @return 'true' si le placement s'est bien passe, 'false' sinon
 * (case occupee, coordonnees invalides, piece vide )
 */
bool Echiquier::placer(Piece* p)
{
	bool result = false;
	if (p == NULL) return false;
	int position = conversion(p->X(), p->Y());
	if (coordonneesValide(p->X(), p->Y()) && m_cases[position] == NULL)
	{
		m_cases[position] = p;
		result = true;
	}
	return result;
}

/**
 * Deplace une piece sur l'echiquier, des coordonnees specifiees
 * dans la piece aux coordonnees x,y.
 *
 * @param p un pointeur vers une piece
 * @param x un entier entre 0 et 7
 * @param y un entier entre 0 et 7
 *
 * @return 'true' si le placement s'est bien passe, 'false' sinon
 * (case occupee, coordonnees invalides, piece vide, piece pas
 * presente au bon endroit sur l'echiquier)
 */

bool Echiquier::deplacer(Piece* p, int x, int y)
{
	bool result = false;
	int xDepart = p->X();
	int yDepart = p->Y();

	if (coordonneesValide(x, y))
	{
		enleverPiece(xDepart, yDepart);
		p->deplace(x, y);
		placer(p);
		result = true;
	}

	return result;
}

/**
 * Enleve la piece situee sur une case (qui devient vide).
 *
 * @param x un entier entre 0 et 7
 * @param y un entier entre 0 et 7
 *
 * @return 0 si aucune piece n'est sur cette case et le pointeur
 * vers la piece enlevee sinon.
 */
Piece* Echiquier::enleverPiece(int x, int y)
{
	Piece* p = NULL;
	if (coordonneesValide(x, y) && getPiece(x, y) != NULL)
	{
		p = m_cases[conversion(x, y)];
		m_cases[conversion(x, y)] = NULL;
	}
	return p;
}

/**
 * Affiche l'echiquier avec des # pour les cases noires et . pour
 * les blanches si elles sont vides, et avec B pour les pieces
 * blanches et N pour les pieces noires.
 */
void Echiquier::Affiche()
{
	cout << endl << "  ABCDEFGH" << endl;
	for (int y = 0; y < 8; ++y)
	{
		cout << y+1 << " ";
		for (int x = 0; x < 8; ++x)
		{
			char c;
			Piece* p = getPiece(x, y);
			if (p == NULL)
			{
				c = ((x + y) % 2) == 0 ? '#' : '.';
			}
			else
			{
				c = p->codePiece();   //isWhite() ? 'B' : 'N';
			}
			cout << c;
		}
		cout << " " << y+1 << endl;
	}
	cout << "  ABCDEFGH" << endl;
}

/**
* Verifie si les coordonnées données sont dans l'échiquier
*/
bool Echiquier::coordonneesValide(const int x, const int y)
{
	return (x < 0 || x > 7 || y < 0 || y > 7) ? false : true;
}

bool Echiquier::coordonneesValide(const char colonne, const int ligne)
{
	return coordonneesValide(colonne - 'A', ligne - 1);
}
