/**
 * Mise en oeuvre de Pion.h
 *
 * @file Pion.cpp
 */

#include "Pion.h"
#include "Echiquier.h"
#include <iostream>

Pion::Pion() : Piece()
{}

Pion::Pion(const int x, const int y, const bool c) : Piece(x, y, c)
{}

Pion::Pion(const char colonne, const int ligne, const bool c) : Piece(colonne - 'A', ligne - 1, c)
{}

bool Pion::mouvementValide(Echiquier& e, int x, int y)
{
    bool estValide = false;

    // Position de départ du pion, il peut avancer de 2 cases
    if (abs(m_y - y) == 2 && m_x == x && ((m_y == 1 && m_couleur == BLANC) || (m_y == 6 && m_couleur == NOIR)))
    {
        if (e.getPiece(x, y) == NULL) // si la case est libre -> le coup est valide
        {
            estValide = true;
        }
    }
    else if (abs(m_y - y) == 1) //deplacement d'une case en avant
    {
        if (m_x == x) // déplacement tout droit
        {
            if (e.getPiece(x, y) == NULL) // si la case est libre -> le coup est valide
            {
                estValide = true;
            }
        }
        else if ((x == m_x - 1) || (x = m_x + 1)) //déplacement d'une case en diagonale => prise d'une pièce adverse
        {
            if (e.getPiece(x, y) != NULL && e.getPiece(x, y)->getCouleur() != m_couleur) // si la case est occupé par une piece adverse -> le coup est valide
            {
                e.enleverPiece(x, y);
                estValide = true;
            }
        }
    }

    return estValide;
}

char Pion::codePiece()
{
    return (m_couleur == BLANC) ? 'P' : 'p';
}