/*! **********************************************************************************************
* 2015  ITESM Campus Guadalajara. Laboratorio de Microcontroladores 
*  
*
* @file:      MTIM.c
* @author(s): Yoku Sashida M�ndez 
* 			  Alan Fridman
*			  Manuel Milan
* @brief (Theory of Operation)
*
**************************************************************************************************/


/*************************************************************************************************/
/*********************						Includes						**********************/
/*************************************************************************************************/
#include "types.h"
#include <hidef.h> /* for EnableInterrupts macro */
#include "derivative.h" /* include peripheral declarations */

/*************************************************************************************************/
/*********************						Defines							**********************/
/*************************************************************************************************/



/*************************************************************************************************/
/*********************						Typedefs						**********************/
/*************************************************************************************************/

/*************************************************************************************************/
/*********************					Function Prototypes					**********************/
/*************************************************************************************************/

/*************************************************************************************************/
/*********************                  Static Variables                    **********************/
/*************************************************************************************************/

/*************************************************************************************************/
/*********************					Global Variables					**********************/
/*************************************************************************************************/

/*************************************************************************************************/
/*********************                  Static Constants                    **********************/
/*************************************************************************************************/
static unsigned long cuentatiempolocal;

/*************************************************************************************************/
/*********************                  Global Constants                    **********************/
/*************************************************************************************************/

/*************************************************************************************************/
/*********************				   Exported Functions					**********************/
/*************************************************************************************************/

void delay_us_MTIM(unsigned short tiempo_us)
{
	cuentatiempolocal=tiempo_us; 

	MTIMCLK=0x02;   /*Set the prescaler for divide the bus clock 4 times and that make the count to 1us*/ 
	MTIMSC_TSTP=0;   /*Start the count*/
	MTIMMOD=2;   	 /**/
	
	do
	{
		do{
			__RESET_WATCHDOG();
		  }while(MTIMSC_TOF==0);  /*The program wait for the flag*/
			
			MTIMSC_TRST=1;  /*First, you reset the clock*/      
	}
	while ((--cuentatiempolocal)!=0); /*Decrease by 1 us*/
	
}


/*************************************************************************************************/
/*********************				    Private Functions					**********************/
/*************************************************************************************************/

