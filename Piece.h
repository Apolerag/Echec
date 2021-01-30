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

/**
 * Declaration d'une classe modélisant une piece de jeu d'echec.
 */
class Piece
{
protected:
	int m_x;
	int m_y;
	Couleur m_couleur;


	virtual bool mouvementValide();


public:
	Piece();
	~Piece();
	Piece(const Piece& p);
	Piece& operator=(const Piece& p);
	Piece(const int x, const int y, const Couleur c);

	void init(int x, int y, Couleur c);
	void deplace(int x, int y);

	int X();
	int Y();
	char Colonne();
	int Ligne();
	Couleur couleur();

	virtual char codePiece();
};

#endif // !defined Piece_h