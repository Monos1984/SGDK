/*
  ***********************************************************
  *                       Moving Sprite                     *
  ***********************************************************
  *          Afficher un tile à l'écran à la mano           *
  *---------------------------------------------------------*
  * Exemple pour le SGDK (1,51)                             * 
  * Par Jean Monos                                          *
  * 18/08/2020                                              *
  ***********************************************************
*/

/*
  * ---------------------------------------------------------------------------------------------
  * Voici un exemple de gestion de sprite réalisé à la mano avec les fonctions de base du SGDK. *
  * Couplé à son deplacement avec le joypad. (Exemple de base)                                  *
  * --------------------------------------------------------------------------------------------*
*/ 


// =======================
// * Les ficier includes *
// =======================
#include <genesis.h>


// ===================================
// * DATA d'une Palette de couleurs. *
// ===================================
const u16 palette_test[16] = 
{
	0x0000,0x00EE,0x0E0E,0x000E,0x0EE0,0x00E0,0x0E00,0x0888,	
	0x0CCC,0x0088,0x0808,0x0008,0x0880,0x0080,0x0800,0x0EEE		
} ;

/*
  **********************************************************************************************
  * La Megadrive permet de mémoriser en même temps, 4 palettes de 16 teintes. (Pal 0 à Pal 3)  *  
  **********************************************************************************************
*/

// ===================
// * DATA d'un TILES *
// ===================
const u32 tiles[8] =
{
	0x11111111, 0x10000001, 0x10000001, 0x10000001, 0x10000001, 0x10000001, 0x10000001, 0x11111111 	
};

/********************************************
  * Voici l'encodage d'un tiles de 8x8pixel *
*********************************************/

// =====================
// *La Fonction main() *
// =====================
int main()
{
  // -----------------------------
  // * Declaration des variables *
  // -----------------------------
  u16 position_x; // Position X du sprite
  u16 position_y; // Position Y du sprite
  
  // ----------------------------------------------------
  // * Configuration de la position de départ du sprite *
  // ----------------------------------------------------
  position_x = 10;
  position_y = 20;
  
  // ---------------------------------
  // * Configuration de la megadrive *
  // ---------------------------------
  
  VDP_setScreenWidth320(); // Passage de l'écran en 320 pixel de large.
  VDP_setScreenHeight224(); // Passage de l'écran en 224 pixel de hauteur. (NTSC compatible PAL)
  VDP_setPlaneSize	(64,32,FALSE); // Configuration du plan virtuel en 64x32 tiles (8x8pixel)
  
  
  // ---------------------------------------
  // * Chargement d'une palette en mémoire *
  // ---------------------------------------
  PAL_setPalette (PAL0, palette_test);
  
  
  /*
    ***************************************************************************************************************
    + ------------------------------------------------------------------------------------------------------------+
    * PAL_setPalette (u16 numPal, const u16 *pal);                                                                *
    + ------------------------------------------------------------------------------------------------------------+
    * Permet d'injecter en Vram une palette de couleurs en entier.                                                *
    * palette_test est tout simplement le nom du tableau que contient les donnés d'une palette.                   *
    * PAL0 est une constante qui indique palette 0. Il existe PAL1,PAL2 et PAL3 pour les trois autres emplacement *
    * des palettes en VRAM.                                                                                       *
    ***************************************************************************************************************
  */
  
  // -------------------------------     
  // * Chargement du tiles en VRAM *
  // -------------------------------
  VDP_loadTileData	(	tiles,32,1,CPU);
  
  /*
    *****************************************************************************************************************
    + --------------------------------------------------------------------------------------------------------------+
    * void VDP_loadTileData	(	const u32 * 	data,u16 	index,u16 	num,TransferMethod 	tm);                          *
    + --------------------------------------------------------------------------------------------------------------+
    * Permet de charger un tableau de tiles en mémoire.                                                             *
    * const u32 est le nom du tableau.                                                                              *
    * index c'est la destination (en numeros de tiles) ou va se trouver le premier tiles à charger.                 *
    * dabs mon exemple, il se trouve à l'emplacement 32.                                                            *
    * num c'est le nombre de tiles à charger en VDP (Moi j'ai qu'un tile dans le tableau)                           *
    * TransferMethod c'est la méthode de chargement. Dans mon exemple j'utilise le CPU mais on peux aussi utiliser  *
    * le DMA par exemple.                                                                                           *
    *****************************************************************************************************************
  */
  
  
  // -----------------------------
  // * Configuration des sprites *
  // -----------------------------
  VDP_allocateSprites	(2);
  
  
  /*
    + ----------------------------------------------------------------------------------------------+
    *  s16 VDP_allocateSprites	(	u16 	num	)	                                                      *
    + ----------------------------------------------------------------------------------------------+
    * VDP_allocateSprites() permet de reserver dans la mémoire de la megadrive un nombre de sprite. *
    * Pour faire simple, si vous faite une VDP_allocateSprites(5),                                  *
    * vous aller pouvoir utiliser 5 sprites dans la megadrive.                                      *
    ************************************************************************************************* 
  */
  
  // --------------------
  // * La Boucle du jeu *
  // --------------------
  while(1)
  {
    
    // ------------------------------------
    // * Gestion du pad pour le mouvement *
    // ------------------------------------
    
    // ------------------------------------
    // +    Mouvement Droite              +
    // ------------------------------------
    if (JOY_readJoypad (JOY_1)&BUTTON_RIGHT)
    {
      position_x = position_x + 1 ;
    }
    
    // ------------------------------------
    // +    Mouvement Gauche              +
    // ------------------------------------
    if (JOY_readJoypad (JOY_1)&BUTTON_LEFT)
    {
      position_x = position_x - 1 ;
    }
    
    // ------------------------------------
    // +    Mouvement Haut                +
    // ------------------------------------
    if (JOY_readJoypad (JOY_1)&BUTTON_UP)
    {
      position_y = position_y - 1 ;
    }
    
    // ------------------------------------
    // +    Mouvement Bas                 +
    // ------------------------------------
    if (JOY_readJoypad (JOY_1)&BUTTON_DOWN)
    {
      position_y = position_y + 1 ;
    }
    
    
    /*
      * --------------------------------- *
      + u16 JOY_readJoypad	(	u16 	joy	)	+
      * --------------------------------- *
      Cette fonction permet de lire l'état du joypad.
      Joy est le numero de la manette. 
      La fonction se couple avec une Macro pour connaitre le bouton utilisé.
      
      Les 4 Directions :
      BUTTON_UP = Haut
      BUTTON_DOWN = BAS
      BUTTON_LEFT = GAUCHE
      BUTTON_RIGHT = DROITE
      
      Et les boutons d'action du pad 3 / 6 boutond.
      BUTTON_A = A 
      BUTTON_B = B 
      BUTTON_C = C 
      BUTTON_START = START 
      BUTTON_X = X 
      BUTTON_Y = Y 
      BUTTON_Z = Z 
      BUTTON_MODE = MODE        
    */
    
    
    // ----------------------------------
    // * Update d'information du sprite *
    // ----------------------------------
    VDP_setSprite	(1,position_x,position_y,SPRITE_SIZE	(1,1),TILE_ATTR_FULL	(0,0,0,0,32));	 
    
    
    /* 
      * ------------------------------------------------------------------------- *
      + void VDP_setSprite	(	u16 	index,s16 	x,s16 	y,u8 	size,u16 	attribut)	+
      * ------------------------------------------------------------------------- *
      * Cette fonction permet de préparer les information d'un sprite à afficher  *
      * a l'écran. Un sprites possède plusieurs informations.                     *   
      * * Index : C'est le numéro du sprite entre 0 et 79.                        * 
      * * x et y : C'est la position à l'écran du sprite. Note :                  *
      *   Le SGDK corrige les coordonnée.                                         *
      *   en haut à gauche de l'écran c'est bien [0,0]                            *
      * * size : c'est la taille du sprite. Une macro existe.                     *
      * * Attribut : Se sont les options du sprite. Une macro existe.             *
      *****************************************************************************
      
      * -------------------------------------------------------------------------*
      + SPRITE_SIZE	(w,h)                                                        +
      * -------------------------------------------------------------------------*
      * Ce macro permet tout simplement de paramétrer la taille du sprite en     *
      * tiles.                                                                   *
      ** w : Largeur du sprite                                                   *
      ** h : Hauteur du sprite                                                   *
      ****************************************************************************
      
      * ------------------------------------------------------------------------ *
      + TILE_ATTR_FULL	(pal,prio,flipV,flipH,index)                             +
      * ------------------------------------------------------------------------ *
      * Comme les tiles, les sprites ont les mêmes attributs                     *
      ** pal : Numero de la palettes à utilise                                   *
      ** prio : Priorité du sprite                                               *
      ** Fliv et FlipH : Symetrie du sprites                                     *
      ** index : Numero du tiles de départ pour le sprite                        *
      ****************************************************************************
      
    */
    
    // -----------------------------------------
    // * Attendre la syncronisation Verticale. *
    // -----------------------------------------
    VDP_waitVSync();
    
    // ------------------------------------------------
    // * Injecter les informations des sprites en VDP *
    // ------------------------------------------------
    VDP_updateSprites(2,DMA);
    
    /*
      * -------------------------------------------------------- *
      + void VDP_updateSprites	(	u16 	num,TransferMethod 	tm ) +
      * -------------------------------------------------------- *
      * Permet d'envoyer les informations des sprites au VDP     *
      * num c'est nombre de sprite à envoyer.                    *
      * 0 = Tout les sprites (80)                                *
      * TransferMethod 	tm c'est la méthode utilisé.             *
      * CPU,DMA...                                               *
      ************************************************************ 
    */
    
  }
  
  /************************************************
    * Une simple boucle infini pour notre exemple *
  *************************************************/
  
}