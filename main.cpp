/**
* main.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
*/

#include <iostream>
#include <typeinfo>

#include "Echiquier.h"
#include "Roi.h"
#include "Fou.h"
#include "Tour.h"
#include "Reine.h"

using namespace std;

int main()
{
    Echiquier e;

    e.Affiche();
    Reine *reine = new Reine(Couleur::NOIR);
    e.placer(reine);
    e.Affiche();

    cerr << reine->Piece::getColonne() << " " << reine->getLigne() << endl;
    
    int x, y;
    bool v;

    x = 0, y = 7;
    v = reine->mouvementValide(e, x, y); //A8

    if (v)
    {
        e.enleverPiece(reine->getX(), reine->getY());
        reine->Fou::deplace(x, y);
        e.deplacer(reine, x, y);
    }
    e.Affiche();
    
    x = 7, y = 7;
    v = reine->mouvementValide(e, x, y); //H8

    if (v)
    {
        e.enleverPiece(reine->getX(), reine->getY());
        reine->Fou::deplace(x, y);
        e.deplacer(reine, x, y);
    }
    e.Affiche();


    x = 7, y = 0;
    v = reine->mouvementValide(e, x, y); //H1

    if (v)
    {
        e.enleverPiece(reine->getX(), reine->getY());
        reine->Fou::deplace(x, y);
        e.deplacer(reine, x, y);
    }
    e.Affiche();


    x = 0, y = 0;
    v = reine->mouvementValide(e, x, y); //A1

    if (v)
    {
        e.enleverPiece(reine->getX(), reine->getY());
        reine->Fou::deplace(x, y);
        e.deplacer(reine, x, y);
    }
    e.Affiche();

    x = 4, y = 4;
    v = reine->mouvementValide(e, x, y); //E5

    if (v)
    {
        e.enleverPiece(reine->getX(), reine->getY());
        reine->Fou::deplace(x, y);
        e.deplacer(reine, x, y);
    }
    e.Affiche();


    Piece r = Roi(Couleur::BLANC);

    delete reine;
}

// Exécuter le programme : Ctrl+F5 ou menu Déboguer > Exécuter sans débogage
// Déboguer le programme : F5 ou menu Déboguer > Démarrer le débogage

// Astuces pour bien démarrer : 
//   1. Utilisez la fenêtre Explorateur de solutions pour ajouter des fichiers et les gérer.
//   2. Utilisez la fenêtre Team Explorer pour vous connecter au contrôle de code source.
//   3. Utilisez la fenêtre Sortie pour voir la sortie de la génération et d'autres messages.
//   4. Utilisez la fenêtre Liste d'erreurs pour voir les erreurs.
//   5. Accédez à Projet > Ajouter un nouvel élément pour créer des fichiers de code, ou à Projet > Ajouter un élément existant pour ajouter des fichiers de code existants au projet.
//   6. Pour rouvrir ce projet plus tard, accédez à Fichier > Ouvrir > Projet et sélectionnez le fichier .sln.
