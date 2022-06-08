/**
  ******************************************************************************************************************
  * @file    timers.h 
  * @author  R.NOHE     IUT Informatique La Rochelle
  * @version v1.0
  * @date    7 mai 2014
  * @modification	rien pour le moment
  * @brief   configurations des timers
  ******************************************************************************************************************/

#ifndef __TIMERS_H
#define __TIMERS_H

#include "stm32f10x.h"                  /* STM32F10x.h definitions            */

#define UIE (1<<0)
#define UIF (1<<0)
#define CEN (1<<0)


/**
  * @brief  configuration du timer1 pour g�n�rer des interruptions
  * @param  None
  * @retval None
  */
void cfgTimer1(void);
void cfgTimer2(void);
#endif

