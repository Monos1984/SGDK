/*
  ***********************************************************
  *           Charger des tiles a partir d'une image        *
  ***********************************************************
  *          Afficher un tile à l'écran à la mano           *
  *---------------------------------------------------------*
  * Exemple pour le SGDK (1,51)                             * 
  * Par Jean Monos                                          *
  * 19/08/2020                                              *
  ***********************************************************
*/

/*
  * ------------------------------------------------------------------------------------------- *
  * Voici un exemple pour charger des tiles en VDP via un fichier image avec Rescomp            *
  * ------------------------------------------------------------------------------------------- *
*/ 


// ===========
// * Rescomp *
// ===========
/*
  
  ********************************************************************************************************************
  Rescomp est un logiciel puissant qui permet formater des images, des wav,VGM,Binaire... dans un format lissible par
  le SDGK et la megadrive.
  Nous allons voir un exemple d'utilisation pour transformer une image en Data tiles et récupérer sa palette
  de couleur !
  *********************************************************************************************************************
  
  Dans le dossier de votre projet, fait un dossier res. (Il existe peut être déja). C'est dans ce dossier que vous
  aller déposer vos ressources. (Musique,Image,Bin...). Vous pouvez créer des sous dossiers pour votre organisation.
  
  Dans ce dossier, créer un fichier qui a pour extenssion un .res 
  exemple resources.res
  C'est dans ce fichier que nous allons ecrire des petites lignes de commandes pour rescomp. Pas de panique, c'est simple.
  
  ============================
  * Le Tileset               *
  ============================
  Pour transformer une image en tilset. (Votre image est découpés en tiles de 8x8 pixel pour se loger dans le VDP), la Commande est tout simplement TILESET suivie d'une étiquette que vous souhaitez donner, puis du lien de votre ressource entre guillemet et enfin une petite valeur de compression. Exemple dans cette exemple :
  
  TILSET tileset_tuto "tilset_tutp.bmp" 0
  rescomp va prendre l'image tilset_tuto.bmp, et la découper. Les DATA porterons le nom de tilset_tuto.
  
  Les valeurs de compression possible sont :
  -1 : meilleurs et automatique
  0  : pas de compression donc ultra rapide à charger en mémoire.
  1  : avec APLIB. Une bonne compression mais lente à charger.
  2  : avec LZ4W.  Compression moyenne mais plus rapide à charger.
  
  Note : Pour les data compressé la fonction seul  VDP_setTileMapXY	() ne fonctionne pas.
  
  Attention votre image doit être au format BMP ou PNG avec une indexer en 8 bit.
  
  
  ==============
  * La Palette *
  ==============
  La commande rescomp pour la palette c'est tout simplement :
  PALETTE  suivie d'une etiquette et le lien de votre image entre guillemet.
  Soit pour l'exemple :
  PALETTE palette_tuto "tileset_tuto.bmp" 
  Il n'y pas de compression pour une palette de couleur.
  
  Attention votre image doit être au format BMP ou PNG avec une indexer en 8 bit.
*/



// ========================
// * Les ficiers includes *
// ========================
#include <genesis.h>


// ---------------------------------
// * Le fichier include resource.h *
// ---------------------------------
#include <resources.h>


/*
  ***********************************************************************************************************
  Il contient les definitions externe des noms de vos ressources. Il porte le même nom que votre fichier .res 
  sans le .res remplacé par le .h. Il est possible d'avoir plusieurs fichier .h et .res en fonction de votre
  orgnisation.
  Vous n'avez pas besoin de relier le .h du res en format directe avec les guillemet. Le SGDK est capable de
  trouver tout seul l'emplacement votre .h à la racine du dossier res. Donc vous pouvez utiliser les < >
  ***********************************************************************************************************
*/  



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
  // * Chargement des tiles en mémoire VDP *
  // ---------------------------------------
  VDP_loadTileData((const u32*) tileset_tuto.tiles,32,5,DMA);
  
  
  /*
    Au lieu de cibler notre tableau de data vu dans d'autre sample, avec un (const u32*) puis le nom donné en étiquette 
    de votre fichier image suivie d'un .tiles cible les données de votre tilset pour les mémoriser en VDP !!! 
  */
  
  
  
  // ----------------------------
  // * Chargement de la palette *
  // ----------------------------
  VDP_setPalette(0,palette_tuto.data);
  
  /*
    ********************************************************************************************************************
    Comme les tiles, au lieu de cibler le tableau de data vu dans d'autre sample, le nom de l'étiquette de votre image
    suivie d'un .data injecte la palette de l'image dans la mégadrive dans la palette voulue !   
    ********************************************************************************************************************
  */
  
  
  // --------------------------------------
  // * Affichage de tiles pour l'exemples *
  // --------------------------------------
  VDP_setTileMapXY	(	BG_B,TILE_ATTR_FULL	(0,0,0,0,32) ,1, 1); // Le tiles noir / Transparent juste pour l'exemple.
  VDP_setTileMapXY	(	BG_B,TILE_ATTR_FULL	(0,0,0,0,33) ,3, 1);
  VDP_setTileMapXY	(	BG_B,TILE_ATTR_FULL	(0,0,0,0,34) ,5, 1);
  VDP_setTileMapXY	(	BG_B,TILE_ATTR_FULL	(0,0,0,0,35) ,7, 1);
  VDP_setTileMapXY	(	BG_B,TILE_ATTR_FULL	(0,0,0,0,36) ,9, 1);
  
  /*
    ***********************************************************************************
    Utilisation simple de la commande VDP_setTileMapXY() pour poser un tiles à l'écran.
    ***********************************************************************************
    
  */
  
  // --------------------
  // * La Boucle du jeu *
  // --------------------
  while(1)
  {
    
    
    
    // -----------------------------------------
    // * Attendre la syncronisation Verticale. *
    // -----------------------------------------
    VDP_waitVSync();
    
    
    
  }
  
  /************************************************
    * Une simple boucle infini pour notre exemple *
  *************************************************/
  
}