/**
 * Header de Roi.cpp
 *
 * @file Roi.h
 */

#if !defined Roi_h
#define Roi_h


#include "Piece.h"
class Roi : public Piece
{
	virtual Erreur miseAJourDeplacementPossible();
};

#endif // !defined Roi_h