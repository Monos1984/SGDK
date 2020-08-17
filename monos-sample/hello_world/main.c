/*********************************************************
 *                       Hello World                     *
 *********************************************************
 *          Afficher du Text sur Sega Megadrive          *
 *-------------------------------------------------------*
 * Exemple pour le SGDK (1.51)                           * 
 * Par Jean Monos                                        *
 * 11/08/2020                                            *
 *********************************************************/

// =======================
// * Les ficier includes *
// =======================
#include <genesis.h>

// ==========
// * main() *
// ==========
int main()
{
  // -------------------------------------
  // * Choix de la palette pour le texte *
  // -------------------------------------

  VDP_setTextPalette (1);

  
  /*********************************************************************
   * La Fonction  VDP_setTextPalette (u16 palette);                    *
   * permet de choisir une des 4 palettes disponibles sur la megadrive *
   * pour afficher du texte. De base, les fonts sur SGDK utilise       *
   * la dernière couleur de la palette. (15)                           *
   *********************************************************************/  
  
  // ------------------------------
  // * Afficher le text à l'écran *
  // ------------------------------
  VDP_drawTextBG	(0,"Hello World ",6,0);
   
  /**************************************************************
   * VDP_drawTextBG	(PLAN,TEXT,PX,PY);                          *
   * Cette fonction permet d'afficher un simple text à l'ecran. *
   * On paramètre le plan ou s'affiche le texte, le texte,      *
   * et sa position X et Y exprimé en case.                     *
   **************************************************************/   
        
  // --------------------
  // * La Boucle du jeu *
  // --------------------
  while(1){}
  
  /***********************************************
   * Une simple boucle infini pour notre exemple *
   ***********************************************/
  
  
}