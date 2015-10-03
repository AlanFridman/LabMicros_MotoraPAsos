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
#include <hidef.h> /* for EnableInterrupts macro */
#include "derivative.h" /* include peripheral declarations */
#include "HIL\MOTORPORT_String.h"

#include "Types.h"

#ifndef MOTORPORT_STRING_USE_MACROS

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
static unsigned char i = 0;
static u8 u8StringVal = MOTORPORT_STRING_INIT_CONDITION;


/*************************************************************************************************/
/*********************					Global Variables					**********************/
/*************************************************************************************************/

/*************************************************************************************************/
/*********************                  Static Constants                    **********************/
/*************************************************************************************************/
static u8 StepValues[4] = {0x01, 0x03, 0x02, 0x06, 0x04, 0x0C, 0x08}; 

/*************************************************************************************************/
/*********************                  Global Constants                    **********************/
/*************************************************************************************************/

/*************************************************************************************************/
/*********************				   Exported Functions					**********************/
/*************************************************************************************************/
void forward(void) 
{
    // ARRAY_IMPLEMENTATION is defined
	// Array positions:          0     1     2     3 	 4	  5		6	   7
	// const u8 kaValues[8] = {0x01, 0x03, 0x02, 0x06, 0x04, 0x0C, 0x08, 0x0A};	
		i = i & 0xFF;   // Mask it so only values from 0 to 7 are valid
		while (i < 8)	// Loop to rotate to the right
		{
			u8 u8PortVal = GPIO_READ_PORT(MOTORPORT_STRING_PORT) & !MOTORPORT_STRING_MASK;	/*  Read the port and keep all the bits that are not part of the string, so those bits are not modified  */
			u8StringVal = StepValues[i++] & MOTORPORT_STRING_MASK;								/*  Set the internal variable to the value passed as parameter.  */		
			GPIO_WRITE_PORT (MOTORPORT_STRING_PORT, u8StringVal);						/*  Write the value to the port  */
			
			VEL_MOTOR();
		}
		i--;  			// Neutralise the last post-increment (which takes the index out of bounds of the array)
}

void reverse(void)
{
		while (i > 0) 	// Switch is pressed => "rebound" mode => rotate to the left. Otherwise, "ring mode" and let it begin again
		{
			u8 u8PortVal = GPIO_READ_PORT(MOTORPORT_STRING_PORT) & !MOTORPORT_STRING_MASK;	/*  Read the port and keep all the bits that are not part of the string, so those bits are not modified  */
			u8StringVal = StepValues[i--] & MOTORPORT_STRING_MASK;								/*  Set the internal variable to the value passed as parameter.  */		
			GPIO_WRITE_PORT (MOTORPORT_STRING_PORT, u8StringVal);						/*  Write the value to the port  */
			
			VEL_MOTOR();
		}
		i++;			// Increment to avoid double timing on index 0 (for "rebound" mode) and to neutralise the post-decrement (for "ring" mode)
		
		__RESET_WATCHDOG();	/* feeds the dog */
	}

/*************************************************************************************************/
/*********************				    Private Functions					**********************/
/*************************************************************************************************/

