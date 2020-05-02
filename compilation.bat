echo off
echo =========================================
echo * Compilation pour la megadrive/genesis *
echo =========================================


Rem ======================================================
Rem * Configuration des liens vers le dossier du SGDK    *
Rem * Attention le GDK_WIN utilise des \ et le GDK des / *
Rem ======================================================

set GDK_WIN=I:\0-megadrive\SGDK
set GDK=I:/0-megadrive/SGDK


Rem ===========================
Rem * Commande de compilation *
Rem ===========================
%GDK_WIN%\bin\make -f %GDK_WIN%\makefile.gen


pause