/**
 * Mise en oeuvre de Partie.h
 *
 * @file Partie.cpp
 */

#include <iostream>
#include "Couleur.h"
#include "Partie.h"
#include "Roi.h"
#include "Reine.h"
#include "Fou.h"
#include "Cavalier.h"
#include "Tour.h"
#include "Pion.h"

Partie::Partie() :e(), joueurActuel(BLANC), x(0), y(0)
{
}

Partie::~Partie()
{
}

void Partie::verifCoordonnees()
{
    char colonne = 0;
    int ligne = 0;
    while (true)
    {
        cout << "\nX = ";
        cin >> colonne;
        cout << "\nY = ";
        cin >> ligne;

        x = colonne - 'A';
        y = ligne - 1;

        if ((x >= 0) && (x <= 7) && (y >= 0) && (y <= 7))
        {
            break;
        }
        else
        {
            cout << "\nCoordonnees incorrectes. Ressaisissez les valeurs :";
        }
    }
}


int Partie::JoueurActuelEnEchec()
{
    int caseEchec = -1;
    //int rbX, rbY, rnX, rnY;
    Piece* RoiBlanc = NULL;
    Piece* RoiNoir = NULL;

    //RECUPERER COORDONNEES DES 2 ROIS
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (e.getPiece(i, j) != NULL)
            {
                //On vérifier si la pièce est un roi, si oui on récupère ses coordonnées
                if (e.getPiece(i, j)->codePiece() == 'R')
                {
                    RoiBlanc = e.getPiece(i, j);
                }
                else if (e.getPiece(i, j)->codePiece() == 'r')
                {
                    RoiNoir = e.getPiece(i, j);
                }
            }

            if (RoiBlanc != NULL && RoiNoir != NULL)
            {
                i = j = 8;
            }

        }
    }

//    //VERIFIER SI PIECE JOUEUR ACTUEL PEUT SE DEPLACER SUR ROI ADVERSAIRE
//    for (int k = 1; k <= 8; k++) {
//        for (int l = 1; l <= 8; l++) {
//            if (e.getPiece(k, l) != NULL)
//            {
//                cout << "\n TEST 1";
//                if (joueurActuel) //joueur blanc
//                {
//                    cout << "\n TEST 2";
//                    if (e.getPiece(k, l)->isWhite())
//                    {
//                        if (e.getPiece(k, l)->mouvementValide(e, rnX, rnY))
//                        {
//                            caseEchec = 2;
//
//                            //VERIFIER SI ROI ADVERSAIRE PEUT SE DEPLACER
//                            for (int m = rnX - 1; rnX + 1; rnX++)
//                            {
//                                for (int n = rnY - 1; rnY + 1; rnY++)
//                                {
//                                    if (e.getPiece(rnX, rnY)->mouvementValide(e, m, n))
//                                    {
//                                        caseEchec = 3;
//                                        goto fin;
//                                    }
//                                }
//                            }
//                        }
//                    }
//                }
//                else
//                {
//                    if (e.getPiece(k, l)->mouvementValide(e, rbX, rbY))
//                    {
//                        caseEchec = 2
//                            //VERIFIER SI ROI ADVERSAIRE PEUT SE DEPLACER
//                            for (int m = rnX - 1; rnX + 1; rnX++)
//                            {
//                                for (int n = rnY - 1; rnY + 1; rnY++)
//                                {
//                                    if (e.getPiece(rnX, rnY)->mouvementValide(e, m, n))
//                                    {
//                                        caseEchec = 3;
//                                        goto fin;
//                                    }
//                                }
//                            }
//                    }
//                }
//            }
//        }
//    }
//
//fin:
//    return (caseEchec);

    return false;
}

void Partie::jouerPartie()
{
    /** DECLARATION DE VARIABLES ET INITIALISATIONS **/
        /**JoueurBlanc jb = JoueurBlanc();
        JoueurNoir jn = JoueurNoir();
        Echiquier e = Echiquier();**/
    joueurActuel = true;    //true = jb, false = jn
    bool mouvementValide = false;
    int yaEchec = 0;
    bool partieFinie = false;
    //int xDep;
    //int yDep;
    //char typePiece;

    /**CREATION PIECES**/
    Roi rb('E',1,BLANC);                 //ROIS
    Roi rn('E', 8, NOIR);
    Reine db('D', 1, BLANC);               //REINES
    Reine dn('D', 8, NOIR);
    Tour tb1('A',1,BLANC);         //TOURS
    Tour tn1('A', 8, NOIR);
    Tour tb2('H', 1, BLANC);
    Tour tn2('H', 8, NOIR);
    Fou fb1('C', 1, BLANC);          //FOUS
    Fou fn1('C', 8, NOIR);
    Fou fb2('F', 1, BLANC);
    Fou fn2('F', 8, NOIR);
    Cavalier cb1('B', 1, BLANC);     //CAVALIERS
    Cavalier cn1('B', 8, NOIR);
    Cavalier cb2('G', 1, BLANC);
    Cavalier cn2('G', 8, NOIR);

    Pion PionNoir[8];
    Pion PionBlanc[8];
    for (int i = 0; i < 8; i++)
    {
        PionBlanc[0] = Pion('A' + i, 2, BLANC);
        PionNoir[0] = Pion('A' + i, 7, NOIR);
    }

    /**PLACEMENT PIECES**/
    e.placer(&rb);  //ROIS
    e.placer(&rn);
    e.placer(&db);  //REINES
    e.placer(&dn);
    e.placer(&tb1);  //TOURS
    e.placer(&tn1);
    e.placer(&tb2);
    e.placer(&tn2);
    e.placer(&fb1);  //FOUS
    e.placer(&fn1);
    e.placer(&fb2);
    e.placer(&fn2);
    e.placer(&cb1);  //CAVALIERS
    e.placer(&cn1);
    e.placer(&cb2);
    e.placer(&cn2);


    for (int i = 0; i < 8; i++)
    {
        e.placer(&PionBlanc[i]);
        e.placer(&PionNoir[i]);
    }

    e.Affiche();
}