/**
 * Header de Echiquier.cpp
 *
 * @file Echiquier.h
 */

#if !defined Echiquier_h
#define Echiquier_h

#include "Piece.h"


 /**
 * @class Echiquier
 * Declaration d'une classe mod�lisant une piece de jeu d'echec.
 */
class Echiquier
{
private:
    /**
    * Les cases de l'echiquier
    */
    Piece* m_cases[64];



public:
    int conversion(int x, int y);
    int conversion(char colonne, int ligne);

    /**
     * Constructeur par d�faut.
     * Initialise � vide l'echiquier.
     */
    Echiquier();
    ~Echiquier();

    /**
   * Recupere la piece situee sur une case.
   *
   * @param x un entier entre 0 et 7
   * @param y un entier entre 0 et 7
   *
   * @return 0 si aucune piece n'est sur cette case et un pointeur
   * vers une piece sinon.
   */
    Piece* getPiece(int x, int y);


    /**
   * Recupere la piece situee sur une case.
   *
   * @param colonne un char entre 'A' et 'H'
   * @param ligne un entier entre 1 et 8
   *
   * @return 0 si aucune piece n'est sur cette case et un pointeur
   * vers une piece sinon.
   */
    Piece* getPiece(char colonne, int ligne);

    /**
     * Place une piece sur l'echiquier, aux coordonnees specifiees dans la piece.
     *
     * @param p un pointeur vers une piece
     *
     * @return 'true' si le placement s'est bien passe, 'false' sinon
     * (case occupee, coordonnees invalides, piece vide )
     */
    bool placer(Piece* p);

    /**
     * Deplace une piece sur l'echiquier, des coordonnees specifiees
     * dans la piece aux coordonnees x,y.
     *
     * @param p un pointeur vers une piece
     * @param x un entier entre 0 et 7
     * @param y un entier entre 0 et 7
     *
     * @return 'true' si le placement s'est bien passe, 'false' sinon
     * (case occupee, coordonnees invalides, piece vide, piece pas
     * presente au bon endroit sur l'echiquier)
     */
    bool deplacer(Piece* p, int x, int y);

    /**
     * Enleve la piece situee sur une case (qui devient vide).
     *
     * @param x un entier entre 0 et 7
     * @param y un entier entre 0 et 7
     *
     * @return 0 si aucune piece n'est sur cette case et le pointeur
     * vers la piece enlevee sinon.
     */
    Piece* enleverPiece(int x, int y);

    /**
     * Affiche l'echiquier avec des # pour les cases noires et . pour
     * les blanches si elles sont vides, et avec B pour les pieces
     * blanches et N pour les pieces noires.
     */
    void Affiche();


private:
    /**
    * Verifie si les coordonn�es donn�es sont dans l'�chiquier
    */
    bool coordonneesValide(const int x, const int y);
    bool coordonneesValide(const char colonne, const int ligne);
};

#endif // !defined Echiquier_h