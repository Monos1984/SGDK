/*********************************************************
  *                       Draw_Tiles                      *
  *********************************************************
  *          Afficher un tile à l'écran à la mano         *
  *-------------------------------------------------------*
  * Exemple pour le SGDK (1,51)                           * 
  * Par Jean Monos                                        *
  * 17/08/2020                                            *
*********************************************************/

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

/**********************************************************************************************
  * La Megadrive permet de mémoriser en même temps, 4 palettes de 16 teintes. (Pal 0 à Pal 3)  *  
**********************************************************************************************/

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
  
  
  /****************************************************************************************************************
    + ------------------------------------------------------------------------------------------------------------+
    * PAL_setPalette (u16 numPal, const u16 *pal);                                                                *
    + ------------------------------------------------------------------------------------------------------------+
    * Permet d'injecter en Vram une palette de couleurs en entier.                                                *
    * palette_test est tout simplement le nom du tableau que contient les donnés d'une palette.                   *
    * PAL0 est une constante qui indique palette 0. Il existe PAL1,PAL2 et PAL3 pour les trois autres emplacement *
    * des palettes en VRAM.                                                                                       *
  *****************************************************************************************************************/
  
  // -------------------------------     
  // * Chargement du tiles en VRAM *
  // -------------------------------
  VDP_loadTileData	(	tiles,32,1,CPU);
  
  /******************************************************************************************************************
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
  *******************************************************************************************************************/
  
  
  // ----------------------------------
  // * Affichage d'un tiles à l'écran *
  // ----------------------------------
  VDP_setTileMapXY	(	BG_B,TILE_ATTR_FULL	(0,0,0,0,32) ,0, 0);
  
  
  /**********************************************************************************************************************
    + ------------------------------------------------------------------------------------------------------------------+
    * void VDP_setTileMapXY	(	VDPPlane 	plane,u16 	tile,u16 	x, u16 	y);                                               *
    + ------------------------------------------------------------------------------------------------------------------+
    *  cette fonction permet d'afficher un tiles à l'écran.                                                             *
    *  Le VDPPPlane permt de cibler un des trois plan de la megadrive :                                                 *
    *  - BG_A                                                                                                           *
    *  - BG_B                                                                                                           *
    *  - WINDOW                                                                                                         *
    *                                                                                                                   *
    *  tile permet de définir l'attribue du tiles sur le plan. Une macro permet de vous simplifier la vie.              *
    *  X et Y permet de choisir la position du Tiles sur la tilemap.                                                    *
    *                                                                                                                   *
    *  voici le Macro pour les tiles :                                                                                  *
    + ------------------------------------------------------------------------------------------------------------------+
    *  TILE_ATTR_FULL	(pal,prio,flipV,flipH,index)                                                                      *
    + ------------------------------------------------------------------------------------------------------------------+
    *  pal c'est le numeros de palette que le tile va utiliser. (0 à 3)                                                 *
    *  prio c'est la priorité du tile par apport au sprite.                                                             *
    *  flip v et H est deux propriété sympathique qui permet de retourner le tiles sur un axe verticale et horizontale. *
    *  index est le  numeros du partern en VDP à afficher sur la tilemap.                                               *
    *********************************************************************************************************************/
  
  // --------------------
  // * La Boucle du jeu *
  // --------------------
  while(1){}
  
  /************************************************
    * Une simple boucle infini pour notre exemple *
  *************************************************/
   
}