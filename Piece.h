/**
 * Header de Piece.cpp
 *
 * @file Piece.h
 */

#if !defined Piece_h
#define Piece_h

#include <utility>
#include <vector>

#include "Erreur.h"

using namespace std;

enum class _Couleur
{
	BLANC,
	NOIR
};
typedef _Couleur Couleur;

typedef pair<int, int> Position;

class Piece
{
protected:
	Position m_position;
	Couleur m_couleur;
	vector<Position> m_deplacementPossible;
public:
	Piece();
	~Piece();
	Piece(const Piece& p);
	Piece(const int x, const int y, const Couleur c);

protected:
	virtual Erreur miseAJourDeplacementPossible() = 0;

public:
	Erreur deplacement(const int x, const int y);
	Erreur deplacement(const char colonne, const int ligne);
};

#endif // !defined Piece_h