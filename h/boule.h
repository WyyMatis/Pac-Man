/**
  ******************************************************************************************************************
  * @file    boule.h 
  * @author  IUT Informatique La Rochelle
  * @version v1.2
  * @date    2021
  * @modification	rien pour le moment
  * @brief   declarations pour l'affichage du bitmap de la boule 
  ******************************************************************************************************************/


#ifndef __BOULE_H
#define __BOULE_H

#define HAUTEUR_BOULE	8
#define LARGEUR_BOULE	8

extern const unsigned short bmpBoule[HAUTEUR_BOULE*LARGEUR_BOULE];
extern const unsigned short bmpBoucheFermee[HAUTEUR_BOULE*LARGEUR_BOULE];
extern const unsigned short bmpBoucheOuverteEst[HAUTEUR_BOULE*LARGEUR_BOULE];
extern const unsigned short bmpBoucheOuverteOuest[HAUTEUR_BOULE*LARGEUR_BOULE];
extern const unsigned short bmpBoucheOuverteNord[HAUTEUR_BOULE*LARGEUR_BOULE];
extern const unsigned short bmpBoucheOuverteSud[HAUTEUR_BOULE*LARGEUR_BOULE];


#define HAUTEUR_NOURRITURE	4
#define LARGEUR_NOURRITURE	4

extern const unsigned short bmpNourriture[HAUTEUR_NOURRITURE*LARGEUR_NOURRITURE];
#endif
