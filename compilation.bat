echo off
echo =========================================
echo * Compilation pour la megadrive/genesis *
echo =========================================

Rem ======================================================
Rem * Configuration des liens vers le dossier du SGDK    *
Rem * Attention le GDK_WIN utilise des \ et le GDK des / *
Rem ======================================================

set GDK_WIN=W:\SGDK
set GDK=W:/SGDK
set Lgens=..\..\kmod\gens.exe
set Lprojet=..\projets\prisonnier\out\rom.bin

Rem ===========================
Rem * Commande de compilation *
Rem ===========================
%GDK_WIN%\bin\make -f %GDK_WIN%\makefile.gen

Rem ============================
Rem * Lancement de l'émulateur *
Rem ============================
%Lgens% %Lprojet%

pause