/**
  ******************************************************************************************************************
  * @file    registres.h 
  * @author  IUT Informatique La Rochelle
  * @version v1.0
  * @date    2021
  * @modification	rien pour le moment
  * @brief   configurations des timers
  ******************************************************************************************************************/

#ifndef __REGISTRES_H
#define __REGISTRES_H

#define AFIO_EXTICR1 	(*(volatile unsigned long *)0x40010008)
#define AFIO_EXTICR4 	(*(volatile unsigned long *)0x40010014)

#define SETENA0 			(*(volatile unsigned long *)0xE000E100)
#define SETENA1 			(*(volatile unsigned long *)0xE000E104)
//#define SETENA2 (*(volatile unsigned long *)0xE000E108)

#endif
