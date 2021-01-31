#include "Piece.h"

Piece::Piece() : m_x(0), m_y(0), m_couleur(BLANC)
{
}

Piece::~Piece()
{
}

Piece::Piece(const Piece& p) : m_x(p.m_x), m_y(p.m_y), m_couleur(p.m_couleur)
{
}

Piece& Piece::operator=(const Piece& p)
{
    m_x = p.m_x;
    m_y = p.m_y;
    m_couleur = p.m_couleur;
    return *this;
}

Piece::Piece(const int x, const int y, const bool c) : m_x(x), m_y(y), m_couleur(c)
{
}

void Piece::init(int x, int y, bool c)
{
    m_x = x;
    m_y = y;
    m_couleur = c;
}

void Piece::deplace(int x, int y)
{
    m_x = x;
    m_y = y;
}

int Piece::getX()
{
    return m_x;
}

int Piece::getY()
{
    return m_y;
}

char Piece::getColonne()
{
    return m_x + 'A';
}

int Piece::getLigne()
{
    return m_y + 1;
}

bool Piece::getCouleur()
{
    return m_couleur;
}

bool Piece::mouvementValide()
{
    return false;
}

char Piece::codePiece()
{
    return (m_couleur == BLANC) ? 'B' : 'N';
}