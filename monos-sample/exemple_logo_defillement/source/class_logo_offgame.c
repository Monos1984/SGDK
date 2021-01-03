// ======================
// * Class Logo Offgame *
// ======================

// ==================================
// ** Fichier include du programme **
// ==================================
#include "header/main.h"

// =============================
// * Affichage du logo offgame *
// =============================
void p_draw_logo_offgame()
{
  // ----------------------------
  // * Declartion des variables *
  // ----------------------------
  unsigned char i; // Boucle pour le scrolling
  
  // -------------------------
  // * Effacement de l'écran *
  // -------------------------
  VDP_clearTileMapRect	(	0,0,0,320/8,224/8);
  VDP_clearTileMapRect	(	1,0,0,320/8,224/8);
  
  // ---------------------------
  // * Résolution pour le logo *
  // ---------------------------
  VDP_setScreenWidth256(); // 256 px (16 tiles à l'écran)
  VDP_setScreenHeight224 (); // 224px (14 tiles à l'écran)
  
  // --------------------------------
  // * Mise en place taille tilemap *
  // --------------------------------
  VDP_setPlaneSize	(64,32,FALSE); // Tailles virtuel de 64x16 tiles
        
  // ---------------------------------
  // * Mise en mémoire de la palette *
  // ---------------------------------
  VDP_setPalette(0, logo_offgame.palette->data);
  
  // --------------------------------
  // * Mise en route du son Offgame *
  // --------------------------------
  SND_startPlay_PCM	(wav_offgame,sizeof(wav_offgame),SOUND_RATE_11025,SOUND_PAN_CENTER,0);
  
  // ------------
  // * Wait VBL *
  // ------------
  SYS_doVBlankProcess();
  
  // ------------------------------------
  // * Affichage de l'image hors champs *
  // ------------------------------------
  VDP_drawImageEx(0, &logo_offgame, TILE_ATTR_FULL(0, 0, 0, 0, 1),32, 12, 0, CPU);
  
  // ------------
  // * Wait VBL *
  // ------------
  SYS_doVBlankProcess();
  
  // -------------
  // * Scrolling *
  // -------------
  for (i=0;i<25;i++)
  {
    SYS_doVBlankProcess();
    VDP_setHorizontalScroll	(	0,-(i<<3));	
  }
   
  // --------
  // * Wait *
  // --------
  waitMs(2000);
    
  // -------------
  // * Fondu out *
  // -------------
  PAL_fade(0,15,logo_offgame.palette->data,palette_black,30,1);
  PAL_waitFadeCompletion ();
  
  // --------------------------------
  // * Remise à 0 du plan de scroll *
  // --------------------------------
  VDP_setHorizontalScroll	(	0,0);	
}