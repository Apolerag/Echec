#pragma once
#include "Fou.h"
#include "Tour.h"

class Reine : public Fou, public Tour
{
public:
    Reine(Couleur c);
    bool mouvementValide(Echiquier& e, int x, int y);
    char codePiece();
};

