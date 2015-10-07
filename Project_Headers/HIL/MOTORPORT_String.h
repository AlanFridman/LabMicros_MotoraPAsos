/*! **********************************************************************************************
* 2014  ITESM Campus Guadalajara. Laboratorio de Microcontroladores 
*
*
* @file:      MOTORPORT_String.h
* @author(s): Mauricio Capistrán Garza Jiras
* Editado:    Yoku Sashida Méndez 
* @brief (User's Manual)
*	This manager controls which LEDs are turned on or off on a string of LEDs. It requires for all
*	LEDs to be on the same PORT and in consecutive PINs. At Init, it turns on the LSb of string.
*	It uses positive logic to turn LEDs on (1 on the port = ON)
*	This manager has been tested on the following Freescale MCUs:
*	   + MC9S08QG8
**************************************************************************************************/

#ifndef MOTORPORT_STRING_H_
#define MOTORPORT_STRING_H_

/*************************************************************************************************/
/*********************						Includes						**********************/
/*************************************************************************************************/
#include "HAL\GPIO.h"
#include "types.h"

/*************************************************************************************************/
/*********************						Defines							**********************/
/*************************************************************************************************/

/* Driver configuration. The user should modify these values */
#define MOTORPORT_STRING_NUMBER_OF_LEDS	8	/* Specify the number of LEDs on the string */
#define MOTORPORT_STRING_PORT			B	/* Specify the digital port where the MOTOR string is connected */
#define MOTORPORT_STRING_PIN_START		0   /* Specify the starting pin on the digital port where the b MOTOR String is connected */
#define PORT_STRING_USE_MACROS		 /*Uncomment this define if you want the driver to use macros instead of function calls */


#if (MOTORPORT_STRING_PIN_START + MOTORPORT_STRING_NUMBER_OF_LEDS > 8)
#error "MOTORPORT_String.h. MOTORPORT_STRING_PIN_START + MOTORPORT_STRING_NUMBER_OF_LEDS must be less than 9, since digital ports are 8-bits wide";
#endif

/* These should not be modified by the user */
#define MOTORPORT_STRING_MASK  (  ( 0xFF >> (8 - MOTORPORT_STRING_NUMBER_OF_MOTORPORT) )  << MOTORPORT_STRING_PIN_START  )
#define MOTORPORT_STRING_INIT_CONDITION  (0x01 << MOTORPORT_STRING_PIN_START)


/*************************************************************************************************/
/*********************						Typedefs						**********************/
/*************************************************************************************************/

/*************************************************************************************************/
/*********************			 	 Functions Like Macros					**********************/
/*************************************************************************************************/

#ifdef MOTORPORT_STRING_USE_MACROS

#define _MOTORPORT_String_Bits				(GPIO_READ_PORT(MOTORPORT_STRING_PORT) &  MOTORPORT_STRING_MASK)   	// Read the port and mask out any bits not part of the MOTOR String
#define _MOTORPORT_String_Complementary_Bits	(GPIO_READ_PORT(MOTORPORT_STRING_PORT) & !MOTORPORT_STRING_MASK)	// Read the port and mask out any bits part of the MOTOR String
#define _MOTORPORT_String_Bits_Shifted_Rigth  ((_MOTORPORT_String_Bits >> 1) & MOTORPORT_STRING_MASK )			// Shift the bits of the MOTOR String to the right and mask them out
#define _MOTORPORT_String_Bits_Shifted_Left   ((_MOTORPORT_String_Bits << 1) & MOTORPORT_STRING_MASK )			// Shift the bits of the MOTOR String to the left and mask them out


// See the descriptions of the functions and parameters in the "Function Prototypes" section.

#define MOTORPORT_String_Init() 		GPIO_WRITE_PORT (MOTORPORT_STRING_PORT, MOTORPORT_STRING_INIT_CONDITION);  \
								GPIO_CONFIG_PORT_OUT(MOTORPORT_STRING_PORT, MOTORPORT_STRING_PIN_START, MOTORPORT_STRING_NUMBER_OF_LEDS)

/*#define LED_String_RotateRight()   	GPIO_WRITE_PORT (LED_STRING_PORT, ( _LED_String_Bits_Shifted_Rigth | _LED_String_Complementary_Bits) ) 

  #define LED_String_RotateLeft()   	GPIO_WRITE_PORT (LED_STRING_PORT, ( _LED_String_Bits_Shifted_Left | _LED_String_Complementary_Bits) ) */

#define MOTORPORT_String_SetValue(val)	GPIO_WRITE_PORT (MOTORPORT_STRING_PORT, ((val & MOTORPORT_STRING_MASK) | _MOTORPORT_String_Complementary_Bits) )		

#define MOTORPORT_String_GetValue()		_MOTORPORT_String_Bits


#endif  // #ifdef MOTORPORT_STRING_USE_MACROS

/*************************************************************************************************/
/*********************					Extern Variables					**********************/
/*************************************************************************************************/

/*************************************************************************************************/
/*********************                  Extern Constants                    **********************/
/*************************************************************************************************/

/*************************************************************************************************/
/*********************					Function Prototypes					**********************/
/*************************************************************************************************/
#ifndef MOTORPORT_STRING_USE_MACROS
/*!*-----------------------------------------------------------------------------------------------
* \name     MOTORPORT_Init
* \brief    Initalizes the GPIO pins used for the STEPS String and it sets it to the initial condition
*           which is the LSb of the array ON.
* \param    void
* \return   void
-------------------------------------------------------------------------------------------------*/
void MOTORPORT_String_Init(void);


void MOTORPORT_String_SetValue(u8 u8Value);

/*!*-----------------------------------------------------------------------------------------------
* \name     Digital_WritePin
* \brief    Returns the last value written to the STEP string
* \param    void
* \return   u8 value contain the value of the STEP string. The bit that don't correspond to the string are returned as zero
-------------------------------------------------------------------------------------------------*/
u8 Digital_GetValue(void);

#endif  // #ifndef LED_STRING_USE_MACROS

/*************************************************************************************************/
#endif /* LED_STRING_H_ */
