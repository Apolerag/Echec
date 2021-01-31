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
#include "Pion.h"
#include "Cavalier.h"

using namespace std;

int main()
{
    Echiquier e;

    Reine reine = Reine('D', 1, BLANC);
    e.placer(&reine);
    e.Affiche();

    cerr << reine.getColonne() << " " << reine.getLigne() << endl;

    Tour tour('A', 1, BLANC);
    e.placer(&tour);
    Tour tour2('A', 8, NOIR);
    e.placer(&tour2);

    Fou fou('C', 1, BLANC);
    e.placer(&fou);

    Roi roi = Roi('E', 1, BLANC);
    e.placer(&roi);

    Pion pion = Pion('A', 2, BLANC);
    e.placer(&pion);

    Cavalier cavalier = Cavalier('B', 1, BLANC);
    e.placer(&cavalier);

    e.Affiche();

    int x = 2, y = 2;
    bool v;
    v = cavalier.mouvementValide(e, x, y);
    if (v)
    {
        e.enleverPiece(cavalier.getX(), cavalier.getY());
        cavalier.deplace(x, y);
        e.deplacer(&cavalier, x, y);
    }

    x = 4, y = 4;
    v = cavalier.mouvementValide(e, x, y);
    if (v)
    {
        e.enleverPiece(cavalier.getX(), cavalier.getY());
        cavalier.deplace(x, y);
        e.deplacer(&cavalier, x, y);
    }
    e.Affiche();


    return 0;
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
