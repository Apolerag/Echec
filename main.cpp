/**
* main.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
*/

#include <iostream>
#include <typeinfo>

#include "Echiquier.h"
#include "Roi.h"
#include "Fou.h"

using namespace std;

int main()
{
    Echiquier e;
    
    e.Affiche();
    Fou f(Couleur::BLANC, true);
    e.placer(&f);
    e.Affiche();

    bool v = f.mouvementValide(e, 0, 2); //A3

    if (v)
    {
        e.enleverPiece(f.getX(), f.getY());
        f.deplace(0, 2);
        e.deplacer(&f, 0, 2);
    }
    e.Affiche();

    v = f.mouvementValide(e, 3, 5); //D6

    if (v)
    {
        e.enleverPiece(f.getX(), f.getY());
        f.deplace(3, 5);
        e.deplacer(&f, 3, 5);
    }
    e.Affiche();


    v = f.mouvementValide(e, 5, 3); //F4

    if (v)
    {
        e.enleverPiece(f.getX(), f.getY());
        f.deplace(5, 3);
        e.deplacer(&f, 5, 3);
    }
    e.Affiche();

    v = f.mouvementValide(e, 2, 0); //C2

    if (v)
    {
        e.enleverPiece(f.getX(), f.getY());
        f.deplace(2, 0);
        e.deplacer(&f, 2, 0);
    }
    e.Affiche();

    cout << f.codePiece() << endl;
    cout << e.conversion('A',7) << endl;

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
