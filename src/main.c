/**
  ******************************************************************************************************************
  * @file    main.c 
  * @author  IUT Informatique La Rochelle
  * @version v1.1
  * @date    2021
  * @modification	rien pour le moment
  * @brief   template pour piloter l'afficheur LCD des cartes MCBSTM32EXL
  ******************************************************************************************************************/

#include "stm32f10x.h"                  /* STM32F10x.h definitions            */
#include "GLCD_Config.h"
#include "boule.h"
#include "globales.h"
#include "ext_globales.h"
#include "timers.h"
#include "boutons.h"

// Fonction qui detecte si deux figures se touchent
unsigned int collision(volatile Figure * figA, volatile Figure * figB){
	if ( figA->x + figA->l <= figB->x )
		return 0;
	if ( figA->x >= figB->x + figB->l )
		return 0;

	if ( figA->y + figA->h <= figB->y )
		return 0;
	if ( figA->y >= figB->y + figB->h )
		return 0;	

	return 1;
}
/*----------------------------------------------------------------------------
  Main Program
 *----------------------------------------------------------------------------*/
int main (void) {   
	
	Figure nourriture;  // est immobile donc peut être locale au main
	
 /* Initialize graphical LCD display   */
  	GLCD_Initialize();                          
  	GLCD_SetBackgroundColor(GLCD_COLOR_BLACK);
	  GLCD_SetForegroundColor(GLCD_COLOR_WHITE);

/* Clear graphical LCD display        */
	GLCD_ClearScreen();     
	
// initialisation du mangeur
	mangeur.l=LARGEUR_BOULE;
	mangeur.h=HAUTEUR_BOULE;
	mangeur.dir=ARRET;
	mangeur.tick=0;
	mangeur.periodeTickDep=1; // tous les 1 ticks, il aura le droit de se déplacer
	mangeur.cntBouche=0;
	mangeur.periodeCntBouche=20; // tous les 20 ticks => 1/5s ouverture/fermeture bouche
	mangeur.bDessine=1;
	mangeur.bmpOuverte=(unsigned char *)bmpBoucheOuverteEst;
	mangeur.bmp=mangeur.bmpOuverte;
	
	cfgIO();
	cfgTimer1(); // pour la gestion du deplacement à 1pixel tous les 10ms
	cfgTimer2(); // tempo de debounce des BPs
	
	GLCD_SetFont(&GLCD_Font_16x24);
	GLCD_SetForegroundColor(GLCD_COLOR_WHITE);
	GLCD_DrawString (30, 82,"Appuyer sur le");
	GLCD_DrawString (10, 112, "centre du joystick");
	while ( GPIOG->IDR & (1<<7) ); // attente appui sur PG7 (Joystick Select)
	srand(TIM1->CNT); // decalage de la séquence pseudo aléatoire en fonction du timer1
										// pour avoir vraiment de l'aléatoire
	GLCD_ClearScreen();    
	
	// positionnement aléatoire du mangeur
	mangeur.x = rand()% (GLCD_WIDTH -mangeur.l);
	mangeur.y = rand()% (GLCD_HEIGHT-mangeur.h);
	
	mangeur.xClone=mangeur.x;
	mangeur.xOld  =mangeur.x; 
	
	nourriture.bmp=(unsigned char *)bmpNourriture;
	nourriture.l=LARGEUR_NOURRITURE;
	nourriture.h=HAUTEUR_NOURRITURE;
	
	do{
		nourriture.x = rand()% (GLCD_WIDTH -LARGEUR_NOURRITURE);
		nourriture.y = rand()% (GLCD_HEIGHT -HAUTEUR_NOURRITURE);
	}while( collision(&nourriture, &mangeur) );
	
	//affichage de la nourriture
	GLCD_DrawBitmap ( nourriture.x , nourriture.y ,
						 nourriture.l , nourriture.h ,
						 nourriture.bmp);
	while(1){
			if ( mangeur.x > mangeur.xOld ){
			mangeur.xClone=mangeur.x; // on se depeche de cloner le champ x
			//suppression de la trace à gauche
			GLCD_DrawBargraph(mangeur.xOld, mangeur.yClone, 
										mangeur.xClone-mangeur.xOld, mangeur.h, 0);			
			mangeur.xOld=mangeur.xClone; // on ne memorise que la partie qui vient d'être effacée au cas 
															// où mangeur aurait été modifiee entre temps
			mangeur.bDessine=1;
		} else if ( mangeur.x < mangeur.xOld ){
			mangeur.xClone=mangeur.x; // on se depeche de cloner le champ x
			//suppression de la trace à droite
			GLCD_DrawBargraph(mangeur.xClone+mangeur.l, mangeur.yClone,
										mangeur.xOld-mangeur.xClone, mangeur.h, 0);
			mangeur.xOld=mangeur.xClone; // on ne memorise que la partie qui vient d'être effacée au cas 
															// où mangeur aurait été modifiee entre temps
			mangeur.bDessine=1;
		}
		
		if ( mangeur.y > mangeur.yOld ){
			mangeur.yClone=mangeur.y; // on se depeche de cloner le champ y
			//suppression de la trace en haut
			GLCD_DrawBargraph(mangeur.xClone, mangeur.yOld, mangeur.l,
										mangeur.yClone-mangeur.yOld, 0);
			mangeur.yOld=mangeur.yClone; // on ne memorise que la partie qui vient d'être effacée au cas 
															// où mangeur aurait été modifiee entre temps
			mangeur.bDessine=1;
		} else if ( mangeur.y < mangeur.yOld ){
			mangeur.yClone=mangeur.y; // on se depeche de cloner le champ y
			//suppression de la trace en bas
			GLCD_DrawBargraph(mangeur.xClone, mangeur.yClone+mangeur.h,
										mangeur.l, mangeur.yOld-mangeur.yClone, 0);
			mangeur.yOld=mangeur.yClone; // on ne memorise que la partie qui vient d'être effacée au cas 
															// où mangeur aurait été modifiee entre temps
			mangeur.bDessine=1;
		}
		
		if ( mangeur.bDessine ){
			mangeur.bDessine=0;
			// affichage du mangeur
			GLCD_DrawBitmap( mangeur.xClone, mangeur.yClone ,
								 mangeur.l , mangeur.h,
								 mangeur.bmp);
		}	

		if ( collision(&nourriture, &mangeur) ){
			//emetSon(); // non bloquant car par ISR
			GLCD_SetForegroundColor(GLCD_COLOR_GREEN);
			GLCD_DrawString (30, 82,"GAGNE");
		
			while(1);
		}
	}
	
}
	

