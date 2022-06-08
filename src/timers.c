/**
  ******************************************************************************************************************
  * @file    timers.c 
  * @author  IUT Informatique La Rochelle
  * @version v2.0
  * @date    2021
  * @modification	rien pour le moment
  * @brief   configurations des timers
  ******************************************************************************************************************/

#include "stm32f10x.h"                  /* STM32F10x.h definitions            */
#include "GLCD_Config.h"
#include "boule.h"
#include "ext_globales.h"
#include "timers.h"
#include "registres.h"

/**
  * @brief  configuration du timer1 pour générer des interruptions
  * @param  None
  * @retval None
  */
void cfgTimer1(void){
		RCC->APB2ENR |= (1<<11); // fourniture de l'horloge sur le périphérique TMR1
    
		TIM1->PSC = 71; // prescaler de 72
    TIM1->ARR = 10000; // autoReload pour 10ms

    TIM1->DIER |= UIE; // autorisation des interruptions sur Timer1
    TIM1->CR1  |= CEN; // autorisation du comptage 
    
    SETENA0 = (1<<25); // bit 25 pour activation IRQ Timer1 Up
}

void TIM1_UP_TIM10_IRQHandler (void){
//    LEDS_PORTB ^= (1<<8);
	static int cnt=0;
    if ( TIM1->SR & UIF ){  // apparemment inevitable de faire ce test car sinon, le CPU est capable de se dérouter
                            // dans la routine d'interruption alors que le drapeau n'est pas levé
        TIM1->SR &= ~UIF;
				mangeur.tick=(mangeur.tick+1)%mangeur.periodeTickDep;
				if ( mangeur.tick == 0 ){
					switch ( mangeur.dir ){
						case EST :
							mangeur.x++;
							if ( mangeur.x+mangeur.l >= GLCD_WIDTH-1 ){
								mangeur.x=GLCD_WIDTH-1-mangeur.l;
								mangeur.dir = ARRET;
								mangeur.bmp = mangeur.bmpOuverte;
								mangeur.bDessine=1;
							}
							break;
						case OUEST :
							mangeur.x--;
							if ( mangeur.x <= 0 ){
								mangeur.x=0;
								mangeur.dir = ARRET;
								mangeur.bmp = mangeur.bmpOuverte;
								mangeur.bDessine=1;
							}
							break;
						case NORD :
							mangeur.y--;
							if ( mangeur.y <= 0 ){
								mangeur.y=0;
								mangeur.dir = ARRET;
								mangeur.bmp = mangeur.bmpOuverte;
								mangeur.bDessine=1;
							}
							break;
						case SUD :
							mangeur.y++;
							if ( mangeur.y+mangeur.h >= GLCD_HEIGHT-1 ){
								mangeur.y=GLCD_HEIGHT-1-mangeur.h;
								mangeur.dir = ARRET;
								mangeur.bmp = mangeur.bmpOuverte;
								mangeur.bDessine=1;
							}
							break; // juste pour enlever le warning
						default: // juste pour enlever le warning
							break; // juste pour enlever le warning
					}

					
					if ( mangeur.dir != ARRET ){
						mangeur.cntBouche=(mangeur.cntBouche+1)%mangeur.periodeCntBouche; // modulo 1/5ème de seconde
						if ( mangeur.cntBouche == 0 ){
							if ( mangeur.bmp == mangeur.bmpOuverte ){
								mangeur.bmp = (unsigned char *) bmpBoucheFermee;
							}else{
								mangeur.bmp = mangeur.bmpOuverte;
							}
						}
					}
				}
    }
							
}
void cfgTimer2(void){ // tempo de debounce
		RCC->APB1ENR |= (1<<0); // fourniture de l'horloge sur le périphérique TMR2
    
		TIM2->PSC = 71; // prescaler de 72
    TIM2->ARR = 1000; // autoReload pour 1ms
	
    TIM2->DIER |= UIE; // autorisation des interruptions sur Timer1

  	SETENA0 = (1<<28); // bit 28 pour activation IRQ Timer2
}


void TIM2_IRQHandler (void){
    if ( TIM2->SR & UIF ){  // apparemment inevitable de faire ce test car sinon, le CPU est capable de se dérouter
                            // dans la routine d'interruption alors que le drapeau n'est pas levé
        TIM2->SR  &= ~UIF; // abaissement drapeau
				TIM2->CR1 &= ~CEN; // arret du timer (arret du comptage)
				
				EXTI->PR  |= (1<<15)|(1<<14)|(1<<13)|(1<<3); // abaissement de tous les drapeaux
				EXTI->IMR |= (1<<15)|(1<<14)|(1<<13)|(1<<3); //demasquage de toutes les interruptions sur GPIO
			
			
    }
}


