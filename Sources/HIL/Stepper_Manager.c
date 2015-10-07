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
static char i = 0;
static u8 u8StringVal = MOTORPORT_STRING_INIT_CONDITION;


/*************************************************************************************************/
/*********************					Global Variables					**********************/
/*************************************************************************************************/

/*************************************************************************************************/
/*********************                  Static Constants                    **********************/
/*************************************************************************************************/
static u8 StepValues[8] = {0x01, 0x03, 0x02, 0x06, 0x04, 0x0C, 0x08}; 

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
		
		i++;
		if (i < 8)	// Loop to rotate to the right
		{
		    i=0;
		}
			u8 u8PortVal = GPIO_READ_PORT(MOTORPORT_STRING_PORT) & !MOTORPORT_STRING_MASK;	/*  Read the port and keep all the bits that are not part of the string, so those bits are not modified  */
			u8StringVal = StepValues[i] & MOTORPORT_STRING_MASK;								/*  Set the internal variable to the value passed as parameter.  */		
			GPIO_WRITE_PORT (MOTORPORT_STRING_PORT, u8StringVal);						/*  Write the value to the port  */
			
}

void reverse(void)
{
		i = i & 0xFF;   // Mask it so only values from 0 to 7 are valid

		i--;
		if(i<0)
		{
		   i=7;
		}			// Increment to avoid double timing on index 0 (for "rebound" mode) and to neutralise the post-decrement (for "ring" mode)
			u8 u8PortVal = GPIO_READ_PORT(MOTORPORT_STRING_PORT) & !MOTORPORT_STRING_MASK;	/*  Read the port and keep all the bits that are not part of the string, so those bits are not modified  */
			u8StringVal = StepValues[i--] & MOTORPORT_STRING_MASK;								/*  Set the internal variable to the value passed as parameter.  */		
			GPIO_WRITE_PORT (MOTORPORT_STRING_PORT, u8StringVal);						/*  Write the value to the port  */
		
}

/*************************************************************************************************/
/*********************				    Private Functions					**********************/
/*************************************************************************************************/
#endif   
