/*! **********************************************************************************************
* 2015  ITESM Campus Guadalajara. Laboratorio de Microcontroladores 
*  
*
* @file:      Steper_Manager.c
* @author(s):  Yoku Sashida
*
* @brief (Theory of Operation)
*
**************************************************************************************************/


/*************************************************************************************************/
/*********************						Includes						**********************/
/*************************************************************************************************/
#include "types.h"
#include "HIL\MOTORPORT_String.h"
#include <hidef.h> /* for EnableInterrupts macro */
#include "derivative.h" /* include peripheral declarations */

/*************************************************************************************************/
/*********************						Defines							**********************/
/*************************************************************************************************/
#define INIT_VAL 0x80

#define PIN7 7
#define PIN6 6
#define PIN5 5
#define PIN4 4
#define TYPE_PORT B

#define NumofSteps 8
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
static char StepValues[8] = {0x10, 0x30, 0x20, 0x60, 0x40, 0xC0, 0x80, 0x90}; 
static signed char i = 0;
static char u8StringVal = MOTORPORT_STRING_INIT_CONDITION;

/*************************************************************************************************/
/*********************                  Global Constants                    **********************/
/*************************************************************************************************/

/*************************************************************************************************/
/*********************				   Exported Functions					**********************/
/*************************************************************************************************/
void Set_Pins_Out(void)
{
 
	
	GPIO_CONFIG_PORT_OUT(TYPE_PORT, 4, 4);
	
}

void forward(void) 
{
    // ARRAY_IMPLEMENTATION is defined
	//     Array positions:          0     1     2     3 	 4	  5		6	   7
	//static char StepValues[8] = {0x10, 0x30, 0x20, 0x60, 0x40, 0xC0, 0x80, 0x90}; 
		i++;
		if (i > NumofSteps)	// Loop to rotate to the right
		{
		    i=0;
		}
		
		{
			GPIO_WRITE_PORT (MOTORPORT_STRING_PORT, StepValues[i]);						/*  Write the value to the port  */
		}
}

void reverse(void)
{
		i--;
		if(i<0)
		{
		   i=NumofSteps;
		}
			// Increment to avoid double timing on index 0 (for "rebound" mode) and to neutralise the post-decrement (for "ring" mode)
		{
			GPIO_WRITE_PORT (MOTORPORT_STRING_PORT, StepValues[i]);						/*  Write the value to the port  */
		}
		
}

/*************************************************************************************************/
/*********************				    Private Functions					**********************/
/*************************************************************************************************/
