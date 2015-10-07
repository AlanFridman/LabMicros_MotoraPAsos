/*! **********************************************************************************************
* 2015  ITESM Campus Guadalajara. Laboratorio de Microcontroladores 
*  
*
* @file:      ADC.c
* @author(s):  
*
* @brief (Theory of Operation)
*
**************************************************************************************************/


/*************************************************************************************************/
/*********************						Includes						**********************/
/*************************************************************************************************/
#include "types.h"
#include <hidef.h> /* for EnableInterrupts macro */
#include "derivative.h" /* include peripheral declarations */
#include "HAL\ADC_Driver.h"
/*************************************************************************************************/
/*********************						Defines							**********************/
/*************************************************************************************************/
#define REGISTER_SET_ZERO 0

/*************************************************************************************************/
/*********************						Typedefs						**********************/
/*************************************************************************************************/

/*************************************************************************************************/
/*********************					Function Prototypes					**********************/
/*************************************************************************************************/
u8 ADC_Read(void)
{
	static u8 valueADC;

    ADCSC1= REGISTER_SET_ZERO | ADC_CHANNEL; /* pin 0 por default */

    while (ADCSC1_COCO==0) 
    {
    }
    valueADC = ADCRL;
    return valueADC;
}


void ADC_Init(void)
{
    ADCCFG=	REGISTER_SET_ZERO; /* Configures the ADC clock to 1M Hz, 8 bits, bus clck */
    ADCSC2= REGISTER_SET_ZERO;
    APCTL1= 1 << ADC_CHANNEL;  /*Enables the control of ADC pin 0*/
}
/*************************************************************************************************/
/*********************                  Static Variables                    **********************/
/*************************************************************************************************/

/*************************************************************************************************/
/*********************					Global Variables					**********************/
/*************************************************************************************************/

/*************************************************************************************************/
/*********************                  Static Constants                    **********************/
/*************************************************************************************************/

/*************************************************************************************************/
/*********************                  Global Constants                    **********************/
/*************************************************************************************************/

/*************************************************************************************************/
/*********************				   Exported Functions					**********************/
/*************************************************************************************************/

/*************************************************************************************************/
/*********************				    Private Functions					**********************/
/*************************************************************************************************/

