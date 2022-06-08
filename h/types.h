/**
  ******************************************************************************************************************
  * @file    types.h 
  * @author  IUT Informatique La Rochelle
  * @version v1.0
  * @date    2021
  * @modification	rien pour le moment
  * @brief   définitions des types spécifiques
  ******************************************************************************************************************/


#ifndef __TYPES_H
#define __TYPES_H

typedef enum { ARRET, OUEST, NORD, EST, SUD } Direction;

typedef struct {
	int x;
	int xClone;
	int xOld;
	int y;
	int yClone;
	int yOld;
	int l;
	int h;
	Direction dir;
	int tick; //
	int periodeTickDep; // definira le nbre de tick au bout duquel la figure est autorisee a bouger
	int cntBouche;
	int periodeCntBouche;
	int bDessine; // booleen pour forcer le dessin
	unsigned char * bmpOuverte;  // permet de stocker le bitmap lorsque la bouche est ouverte
	unsigned char * bmp;
} Figure;

#endif

