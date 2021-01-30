#include "Piece.h"

Piece::Piece() : m_position(0, 0), m_couleur(Couleur::BLANC)
{
}

Piece::~Piece()
{
}

Piece::Piece(const Piece& p) : m_position(p.m_position), m_couleur(p.m_couleur), m_deplacementPossible(p.m_deplacementPossible)
{
}

Piece::Piece(const int x, const int y, const Couleur c) : m_couleur(c), m_position(x, y)
{
}

Erreur Piece::deplacement(const int x, const int y)
{
	Erreur e = Erreur::NO_ERREUR;
	if (x < 0 || x > 7 || y < 0 || y > 7)
	{
		e = Erreur::COORDONNEES_INVALIDE;
	}
	else
	{
		m_position = { x,y };
		e = miseAJourDeplacementPossible();
	}
	return e;
}

Erreur Piece::deplacement(const char colonne, const int ligne)
{
	Erreur e = Erreur::NO_ERREUR;

	if (colonne < 'A' || colonne > 'H' || ligne < 1 || ligne > 8)
	{
		e = Erreur::COORDONNEES_INVALIDE;
	}
	else
	{
		int x = colonne - 'A', y = ligne - 1;
		e = deplacement(x, y);
	}

	return e;
}
