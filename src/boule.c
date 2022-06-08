/**
  ******************************************************************************************************************
  * @file    boule.c 
  * @author  IUT Informatique La Rochelle
  * @version v1.2
  * @date    2021
  * @modification
  * @brief   définitions pour la description du bitmap d'une boule
  ******************************************************************************************************************/

#include "ext_globales.h"
#include "GLCD_Config.h"
#include "boule.h"
#include "ext_globales.h"

const unsigned short bmpBoule[HAUTEUR_BOULE*LARGEUR_BOULE]={
	GLCD_COLOR_BLACK ,GLCD_COLOR_BLACK ,GLCD_COLOR_YELLOW,GLCD_COLOR_YELLOW,GLCD_COLOR_YELLOW,GLCD_COLOR_YELLOW,GLCD_COLOR_BLACK ,GLCD_COLOR_BLACK ,
	GLCD_COLOR_BLACK ,GLCD_COLOR_YELLOW,GLCD_COLOR_YELLOW,GLCD_COLOR_YELLOW,GLCD_COLOR_YELLOW,GLCD_COLOR_YELLOW,GLCD_COLOR_YELLOW,GLCD_COLOR_BLACK ,
	GLCD_COLOR_YELLOW,GLCD_COLOR_YELLOW,GLCD_COLOR_YELLOW,GLCD_COLOR_YELLOW,GLCD_COLOR_YELLOW,GLCD_COLOR_YELLOW,GLCD_COLOR_YELLOW,GLCD_COLOR_YELLOW,
	GLCD_COLOR_YELLOW,GLCD_COLOR_YELLOW,GLCD_COLOR_YELLOW,GLCD_COLOR_YELLOW,GLCD_COLOR_YELLOW,GLCD_COLOR_YELLOW,GLCD_COLOR_YELLOW,GLCD_COLOR_YELLOW,
	GLCD_COLOR_YELLOW,GLCD_COLOR_YELLOW,GLCD_COLOR_YELLOW,GLCD_COLOR_YELLOW,GLCD_COLOR_YELLOW,GLCD_COLOR_YELLOW,GLCD_COLOR_YELLOW,GLCD_COLOR_YELLOW,
	GLCD_COLOR_YELLOW,GLCD_COLOR_YELLOW,GLCD_COLOR_YELLOW,GLCD_COLOR_YELLOW,GLCD_COLOR_YELLOW,GLCD_COLOR_YELLOW,GLCD_COLOR_YELLOW,GLCD_COLOR_YELLOW,
	GLCD_COLOR_BLACK ,GLCD_COLOR_YELLOW,GLCD_COLOR_YELLOW,GLCD_COLOR_YELLOW,GLCD_COLOR_YELLOW,GLCD_COLOR_YELLOW,GLCD_COLOR_YELLOW,GLCD_COLOR_BLACK ,
	GLCD_COLOR_BLACK ,GLCD_COLOR_BLACK ,GLCD_COLOR_YELLOW,GLCD_COLOR_YELLOW,GLCD_COLOR_YELLOW,GLCD_COLOR_YELLOW,GLCD_COLOR_BLACK ,GLCD_COLOR_BLACK ,
};
const unsigned short bmpBoucheFermee[HAUTEUR_BOULE*LARGEUR_BOULE]=
{
	GLCD_COLOR_BLACK ,GLCD_COLOR_BLACK ,GLCD_COLOR_YELLOW,GLCD_COLOR_YELLOW,GLCD_COLOR_YELLOW,GLCD_COLOR_YELLOW,GLCD_COLOR_BLACK ,GLCD_COLOR_BLACK ,
	GLCD_COLOR_BLACK ,GLCD_COLOR_YELLOW,GLCD_COLOR_YELLOW,GLCD_COLOR_YELLOW,GLCD_COLOR_YELLOW,GLCD_COLOR_YELLOW,GLCD_COLOR_YELLOW,GLCD_COLOR_BLACK ,
	GLCD_COLOR_YELLOW,GLCD_COLOR_YELLOW,GLCD_COLOR_YELLOW,GLCD_COLOR_YELLOW,GLCD_COLOR_YELLOW,GLCD_COLOR_YELLOW,GLCD_COLOR_YELLOW,GLCD_COLOR_YELLOW,
	GLCD_COLOR_YELLOW,GLCD_COLOR_YELLOW,GLCD_COLOR_YELLOW,GLCD_COLOR_YELLOW,GLCD_COLOR_YELLOW,GLCD_COLOR_YELLOW,GLCD_COLOR_YELLOW,GLCD_COLOR_YELLOW,
	GLCD_COLOR_YELLOW,GLCD_COLOR_YELLOW,GLCD_COLOR_YELLOW,GLCD_COLOR_YELLOW,GLCD_COLOR_YELLOW,GLCD_COLOR_YELLOW,GLCD_COLOR_YELLOW,GLCD_COLOR_YELLOW,
	GLCD_COLOR_YELLOW,GLCD_COLOR_YELLOW,GLCD_COLOR_YELLOW,GLCD_COLOR_YELLOW,GLCD_COLOR_YELLOW,GLCD_COLOR_YELLOW,GLCD_COLOR_YELLOW,GLCD_COLOR_YELLOW,
	GLCD_COLOR_BLACK ,GLCD_COLOR_YELLOW,GLCD_COLOR_YELLOW,GLCD_COLOR_YELLOW,GLCD_COLOR_YELLOW,GLCD_COLOR_YELLOW,GLCD_COLOR_YELLOW,GLCD_COLOR_BLACK ,
	GLCD_COLOR_BLACK ,GLCD_COLOR_BLACK ,GLCD_COLOR_YELLOW,GLCD_COLOR_YELLOW,GLCD_COLOR_YELLOW,GLCD_COLOR_YELLOW,GLCD_COLOR_BLACK ,GLCD_COLOR_BLACK ,
};

const unsigned short bmpBoucheOuverteEst[HAUTEUR_BOULE*LARGEUR_BOULE]=
{
	GLCD_COLOR_BLACK ,GLCD_COLOR_BLACK ,GLCD_COLOR_YELLOW,GLCD_COLOR_YELLOW,GLCD_COLOR_YELLOW,GLCD_COLOR_YELLOW,GLCD_COLOR_BLACK ,GLCD_COLOR_BLACK ,
	GLCD_COLOR_BLACK ,GLCD_COLOR_YELLOW,GLCD_COLOR_YELLOW,GLCD_COLOR_YELLOW,GLCD_COLOR_YELLOW,GLCD_COLOR_YELLOW,GLCD_COLOR_YELLOW,GLCD_COLOR_BLACK ,
	GLCD_COLOR_YELLOW,GLCD_COLOR_YELLOW,GLCD_COLOR_YELLOW,GLCD_COLOR_YELLOW,GLCD_COLOR_YELLOW,GLCD_COLOR_YELLOW,GLCD_COLOR_BLACK ,GLCD_COLOR_BLACK ,
	GLCD_COLOR_YELLOW,GLCD_COLOR_YELLOW,GLCD_COLOR_YELLOW,GLCD_COLOR_YELLOW,GLCD_COLOR_YELLOW,GLCD_COLOR_BLACK ,GLCD_COLOR_BLACK ,GLCD_COLOR_BLACK ,
	GLCD_COLOR_YELLOW,GLCD_COLOR_YELLOW,GLCD_COLOR_YELLOW,GLCD_COLOR_YELLOW,GLCD_COLOR_YELLOW,GLCD_COLOR_BLACK ,GLCD_COLOR_BLACK ,GLCD_COLOR_BLACK ,
	GLCD_COLOR_YELLOW,GLCD_COLOR_YELLOW,GLCD_COLOR_YELLOW,GLCD_COLOR_YELLOW,GLCD_COLOR_YELLOW,GLCD_COLOR_YELLOW,GLCD_COLOR_BLACK ,GLCD_COLOR_BLACK ,
	GLCD_COLOR_BLACK ,GLCD_COLOR_YELLOW,GLCD_COLOR_YELLOW,GLCD_COLOR_YELLOW,GLCD_COLOR_YELLOW,GLCD_COLOR_YELLOW,GLCD_COLOR_YELLOW,GLCD_COLOR_BLACK ,
	GLCD_COLOR_BLACK ,GLCD_COLOR_BLACK ,GLCD_COLOR_YELLOW,GLCD_COLOR_YELLOW,GLCD_COLOR_YELLOW,GLCD_COLOR_YELLOW,GLCD_COLOR_BLACK ,GLCD_COLOR_BLACK ,
};

const unsigned short bmpBoucheOuverteOuest[HAUTEUR_BOULE*LARGEUR_BOULE]=
{
	GLCD_COLOR_BLACK ,GLCD_COLOR_BLACK ,GLCD_COLOR_YELLOW,GLCD_COLOR_YELLOW,GLCD_COLOR_YELLOW,GLCD_COLOR_YELLOW,GLCD_COLOR_BLACK ,GLCD_COLOR_BLACK ,
	GLCD_COLOR_BLACK ,GLCD_COLOR_YELLOW,GLCD_COLOR_YELLOW,GLCD_COLOR_YELLOW,GLCD_COLOR_YELLOW,GLCD_COLOR_YELLOW,GLCD_COLOR_YELLOW,GLCD_COLOR_BLACK ,
	GLCD_COLOR_BLACK ,GLCD_COLOR_BLACK ,GLCD_COLOR_YELLOW,GLCD_COLOR_YELLOW,GLCD_COLOR_YELLOW,GLCD_COLOR_YELLOW,GLCD_COLOR_YELLOW,GLCD_COLOR_YELLOW,
	GLCD_COLOR_BLACK ,GLCD_COLOR_BLACK ,GLCD_COLOR_BLACK ,GLCD_COLOR_YELLOW,GLCD_COLOR_YELLOW,GLCD_COLOR_YELLOW,GLCD_COLOR_YELLOW,GLCD_COLOR_YELLOW,
	GLCD_COLOR_BLACK ,GLCD_COLOR_BLACK ,GLCD_COLOR_BLACK ,GLCD_COLOR_YELLOW,GLCD_COLOR_YELLOW,GLCD_COLOR_YELLOW,GLCD_COLOR_YELLOW,GLCD_COLOR_YELLOW,
	GLCD_COLOR_BLACK ,GLCD_COLOR_BLACK ,GLCD_COLOR_YELLOW,GLCD_COLOR_YELLOW,GLCD_COLOR_YELLOW,GLCD_COLOR_YELLOW,GLCD_COLOR_YELLOW,GLCD_COLOR_YELLOW,
	GLCD_COLOR_BLACK ,GLCD_COLOR_YELLOW,GLCD_COLOR_YELLOW,GLCD_COLOR_YELLOW,GLCD_COLOR_YELLOW,GLCD_COLOR_YELLOW,GLCD_COLOR_YELLOW,GLCD_COLOR_BLACK ,
	GLCD_COLOR_BLACK ,GLCD_COLOR_BLACK ,GLCD_COLOR_YELLOW,GLCD_COLOR_YELLOW,GLCD_COLOR_YELLOW,GLCD_COLOR_YELLOW,GLCD_COLOR_BLACK ,GLCD_COLOR_BLACK ,
};
const unsigned short bmpBoucheOuverteSud[HAUTEUR_BOULE*LARGEUR_BOULE]=
{
	GLCD_COLOR_BLACK ,GLCD_COLOR_BLACK ,GLCD_COLOR_BLACK ,GLCD_COLOR_BLACK ,GLCD_COLOR_BLACK ,GLCD_COLOR_BLACK ,GLCD_COLOR_BLACK ,GLCD_COLOR_BLACK ,
	GLCD_COLOR_BLACK ,GLCD_COLOR_YELLOW,GLCD_COLOR_BLACK ,GLCD_COLOR_BLACK ,GLCD_COLOR_BLACK ,GLCD_COLOR_BLACK ,GLCD_COLOR_YELLOW,GLCD_COLOR_BLACK ,
	GLCD_COLOR_YELLOW,GLCD_COLOR_YELLOW,GLCD_COLOR_YELLOW,GLCD_COLOR_BLACK ,GLCD_COLOR_BLACK ,GLCD_COLOR_YELLOW,GLCD_COLOR_YELLOW,GLCD_COLOR_YELLOW,
	GLCD_COLOR_YELLOW,GLCD_COLOR_YELLOW,GLCD_COLOR_YELLOW,GLCD_COLOR_YELLOW,GLCD_COLOR_YELLOW,GLCD_COLOR_YELLOW,GLCD_COLOR_YELLOW,GLCD_COLOR_YELLOW,
	GLCD_COLOR_YELLOW,GLCD_COLOR_YELLOW,GLCD_COLOR_YELLOW,GLCD_COLOR_YELLOW,GLCD_COLOR_YELLOW,GLCD_COLOR_YELLOW,GLCD_COLOR_YELLOW,GLCD_COLOR_YELLOW,
	GLCD_COLOR_YELLOW,GLCD_COLOR_YELLOW,GLCD_COLOR_YELLOW,GLCD_COLOR_YELLOW,GLCD_COLOR_YELLOW,GLCD_COLOR_YELLOW,GLCD_COLOR_YELLOW,GLCD_COLOR_YELLOW,
	GLCD_COLOR_BLACK ,GLCD_COLOR_YELLOW,GLCD_COLOR_YELLOW,GLCD_COLOR_YELLOW,GLCD_COLOR_YELLOW,GLCD_COLOR_YELLOW,GLCD_COLOR_YELLOW,GLCD_COLOR_BLACK ,
	GLCD_COLOR_BLACK ,GLCD_COLOR_BLACK ,GLCD_COLOR_YELLOW,GLCD_COLOR_YELLOW,GLCD_COLOR_YELLOW,GLCD_COLOR_YELLOW,GLCD_COLOR_BLACK ,GLCD_COLOR_BLACK ,
};

const unsigned short bmpBoucheOuverteNord[HAUTEUR_BOULE*LARGEUR_BOULE]=
{
	GLCD_COLOR_BLACK ,GLCD_COLOR_BLACK ,GLCD_COLOR_YELLOW,GLCD_COLOR_YELLOW,GLCD_COLOR_YELLOW,GLCD_COLOR_YELLOW,GLCD_COLOR_BLACK ,GLCD_COLOR_BLACK ,
	GLCD_COLOR_BLACK ,GLCD_COLOR_YELLOW,GLCD_COLOR_YELLOW,GLCD_COLOR_YELLOW,GLCD_COLOR_YELLOW,GLCD_COLOR_YELLOW,GLCD_COLOR_YELLOW,GLCD_COLOR_BLACK ,
	GLCD_COLOR_YELLOW,GLCD_COLOR_YELLOW,GLCD_COLOR_YELLOW,GLCD_COLOR_YELLOW,GLCD_COLOR_YELLOW,GLCD_COLOR_YELLOW,GLCD_COLOR_YELLOW,GLCD_COLOR_YELLOW,
	GLCD_COLOR_YELLOW,GLCD_COLOR_YELLOW,GLCD_COLOR_YELLOW,GLCD_COLOR_YELLOW,GLCD_COLOR_YELLOW,GLCD_COLOR_YELLOW,GLCD_COLOR_YELLOW,GLCD_COLOR_YELLOW,
	GLCD_COLOR_YELLOW,GLCD_COLOR_YELLOW,GLCD_COLOR_YELLOW,GLCD_COLOR_YELLOW,GLCD_COLOR_YELLOW,GLCD_COLOR_YELLOW,GLCD_COLOR_YELLOW,GLCD_COLOR_YELLOW,
	GLCD_COLOR_YELLOW,GLCD_COLOR_YELLOW,GLCD_COLOR_YELLOW,GLCD_COLOR_BLACK ,GLCD_COLOR_BLACK ,GLCD_COLOR_YELLOW,GLCD_COLOR_YELLOW,GLCD_COLOR_YELLOW,
	GLCD_COLOR_BLACK ,GLCD_COLOR_YELLOW,GLCD_COLOR_BLACK ,GLCD_COLOR_BLACK ,GLCD_COLOR_BLACK ,GLCD_COLOR_BLACK ,GLCD_COLOR_YELLOW,GLCD_COLOR_BLACK ,
	GLCD_COLOR_BLACK ,GLCD_COLOR_BLACK ,GLCD_COLOR_BLACK ,GLCD_COLOR_BLACK ,GLCD_COLOR_BLACK ,GLCD_COLOR_BLACK ,GLCD_COLOR_BLACK ,GLCD_COLOR_BLACK ,
};

const unsigned short bmpNourriture[HAUTEUR_NOURRITURE*LARGEUR_NOURRITURE]=
{
	GLCD_COLOR_BLACK ,GLCD_COLOR_WHITE ,GLCD_COLOR_WHITE ,GLCD_COLOR_BLACK,
	GLCD_COLOR_WHITE ,GLCD_COLOR_WHITE ,GLCD_COLOR_WHITE ,GLCD_COLOR_WHITE,
	GLCD_COLOR_WHITE ,GLCD_COLOR_WHITE ,GLCD_COLOR_WHITE ,GLCD_COLOR_WHITE,
	GLCD_COLOR_BLACK ,GLCD_COLOR_WHITE ,GLCD_COLOR_WHITE ,GLCD_COLOR_BLACK,
};