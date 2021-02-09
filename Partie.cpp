/**
 * Mise en oeuvre de Partie.h
 *
 * @file Partie.cpp
 */

#include <iostream>
#include <vector>
#include "Couleur.h"
#include "Partie.h"
#include "Roi.h"
#include "Reine.h"
#include "Fou.h"
#include "Cavalier.h"
#include "Tour.h"
#include "Pion.h"

Partie::Partie() :m_e(), m_joueurActuel(BLANC), m_PiecesBlanche(), m_PiecesNoires(), m_RoiBlanc(NULL),m_RoiNoir(NULL)
{
}

Partie::~Partie()
{
}

void Partie::getCoordonnees(int& x, int& y)
{
    char colonne = 0;
    int ligne = 0;
    string coordonnees = "";
    while (true)
    {
        while (true)
        {
            cin >> coordonnees;
            if (coordonnees.length() != 2)
            {
                cout << "Coordonnees incorrectes. Ressaisissez les valeurs :\n";
            }
            else
            {
                colonne = coordonnees[0];
                ligne = coordonnees[1];
                break;
            }
        }

        x = colonne - 'A';
        y = ligne - '1';

        if ((x >= 0) && (x <= 7) && (y >= 0) && (y <= 7))
        {
            break;
        }
        else
        {
            cout << "Coordonnees incorrectes. Ressaisissez les valeurs :\n";
        }
    }
}


int Partie::Echec()
{
    int enEchec = 0;
    Piece* roiAdverse = NULL;
    vector<Piece*> pieceJoueur;

    //RECUPERER COORDONNEES DES 2 ROIS
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (m_e.getPiece(i, j) != NULL)
            {
                Piece* p = m_e.getPiece(i, j);
                //On vérifier si la pièce est un roi, si oui on récupère ses coordonnées
                if (p->getCouleur() == m_joueurActuel)
                {
                    pieceJoueur.push_back(p);
                }
            }

        }
    }

    roiAdverse = (m_joueurActuel == NOIR) ? m_RoiBlanc : m_RoiNoir;


    //  VERIFIER SI PIECE JOUEUR ACTUEL PEUT SE DEPLACER SUR ROI ADVERSAIRE
    for (unsigned int i = 0; i < pieceJoueur.size(); i++)
    {
        Piece* p = pieceJoueur[i];

        if (p->mouvementValide(m_e, roiAdverse->getX(), roiAdverse->getY()) != false)
        {
            enEchec = 1;
            break;
        }
    }

    // VERIFIER SI ECHEC ET MAT
    if (enEchec == 1)
    {
        // TODO
    }

    return enEchec;
}

bool Partie::Pat()
{
    //TODO
    return false;

}

void Partie::jouerPartie()
{
    /** DECLARATION DE VARIABLES ET INITIALISATIONS **/
        /**JoueurBlanc jb = JoueurBlanc();
        JoueurNoir jn = JoueurNoir();
        Echiquier e = Echiquier();**/
    m_joueurActuel = true;    //true = jb, false = jn
    bool mouvementValide = false;
    int enEchec = 0;
    bool partieFinie = false;
    int xDepart = 0;
    int yDepart = 0;
    int xArrivee = 0;
    int yArrivee = 0;
    //char typePiece;

    /**CREATION PIECES**/
    Roi rb('E', 1, BLANC);                 //ROIS
    Roi rn('E', 8, NOIR);
    Reine db('D', 1, BLANC);               //REINES
    Reine dn('D', 8, NOIR);
    Tour tb1('A', 1, BLANC);         //TOURS
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
        PionBlanc[i] = Pion(i, 1, BLANC);
        PionNoir[i] = Pion(i, 6, NOIR);
    }

    /**PLACEMENT PIECES**/
    m_e.placer(&rb);  //ROIS
    m_e.placer(&rn);
    m_RoiBlanc = &rb;
    m_RoiNoir = &rn;

    m_e.placer(&db);  //REINES
    m_e.placer(&dn);
    m_e.placer(&tb1);  //TOURS
    m_e.placer(&tn1);
    m_e.placer(&tb2);
    m_e.placer(&tn2);
    m_e.placer(&fb1);  //FOUS
    m_e.placer(&fn1);
    m_e.placer(&fb2);
    m_e.placer(&fn2);
    m_e.placer(&cb1);  //CAVALIERS
    m_e.placer(&cn1);
    m_e.placer(&cb2);
    m_e.placer(&cn2);


    for (int i = 0; i < 8; i++)
    {
        m_e.placer(&PionBlanc[i]);
        m_e.placer(&PionNoir[i]);
    }


    while (partieFinie == false)
    {
        mouvementValide = false;
        enEchec = 0;
        m_e.Affiche();    //on affiche le plateau à chaque nouvelle action

        if (Pat() != false)
        {
            cout << "Pat ! Match Nul !" << endl;
            partieFinie = true;
            break;
        }

        if (m_joueurActuel == BLANC)
        {
            cout << "\nAu blanc de jouer." << endl;
        }
        else
        {
            cout << "\nAu Noir de jouer." << endl;
        }

        cout << "Choisissez les coordonnees de la piece a deplacer." << endl;
        getCoordonnees(xDepart, yDepart);


        while (mouvementValide == false)
        {
            cout << "Choisissez les coordonnees de la case d'arrivee." << endl;
            getCoordonnees(xArrivee, yArrivee);

            if (m_e.getPiece(xDepart, yDepart)->mouvementValide(m_e, xArrivee, yArrivee))
            {
                mouvementValide = true;

                m_e.deplacer(m_e.getPiece(xDepart, yDepart), xArrivee, yArrivee);
            }

            enEchec = Echec();

            if (enEchec == 1)
            {
                cout << "Echec !" << endl;
            }
            else if (enEchec == 2)
            {
                cout << "Echec et Mat ! " << endl;
                if (m_joueurActuel == BLANC)
                {
                    cout << "Les Blancs ";
                }
                else
                {
                    cout << "Les Noirs ";
                }
                cout << "ont gagné !" << endl;
                partieFinie = true;
            }

            m_joueurActuel = !m_joueurActuel;
        }


    }
}