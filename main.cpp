/**
* main.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
*/

#include <iostream>
#include <typeinfo>

#include "Echiquier.h"
#include "Roi.h"
#include "Fou.h"
#include "Tour.h"

using namespace std;

int main()
{
    Echiquier e;

    e.Affiche();
    Tour t(Couleur::NOIR, true);
    e.placer(&t);
    e.Affiche();

    int x, y;
    bool v;

    x = 0, y = 7;
    v = t.mouvementValide(e, x, y); //A8

    if (v)
    {
        e.enleverPiece(t.getX(), t.getY());
        t.deplace(x, y);
        e.deplacer(&t, x, y);
    }
    e.Affiche();

    x = 7, y = 7;
    v = t.mouvementValide(e, x, y); //H8

    if (v)
    {
        e.enleverPiece(t.getX(), t.getY());
        t.deplace(x, y);
        e.deplacer(&t, x, y);
    }
    e.Affiche();


    x = 7, y = 0;
    v = t.mouvementValide(e, x, y); //H1

    if (v)
    {
        e.enleverPiece(t.getX(), t.getY());
        t.deplace(x, y);
        e.deplacer(&t, x, y);
    }
    e.Affiche();


    x = 0, y = 0;
    v = t.mouvementValide(e, x, y); //A1

    if (v)
    {
        e.enleverPiece(t.getX(), t.getY());
        t.deplace(x, y);
        e.deplacer(&t, x, y);
    }
    e.Affiche();

    cout << t.codePiece() << endl;
    cout << e.conversion('A', 7) << endl;

    Piece r = Roi(Couleur::BLANC);
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
