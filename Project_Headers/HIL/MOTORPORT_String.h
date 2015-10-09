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
#define MOTORPORT_STRING_NUMBER_OF_PORT	4	/* Specify the number of LEDs on the string */
#define MOTORPORT_STRING_PORT			B	/* Specify the digital port where the MOTOR string is connected */
#define MOTORPORT_STRING_PIN_START		0   /* Specify the starting pin on the digital port where the b MOTOR String is connected */
//#define PORT_STRING_USE_MACROS		 /*Uncomment this define if you want the driver to use macros instead of function calls */


#if (MOTORPORT_STRING_PIN_START + MOTORPORT_STRING_NUMBER_OF_PORT > 8)
#error "MOTORPORT_String.h. MOTORPORT_STRING_PIN_START + MOTORPORT_STRING_NUMBER_OF_LEDS must be less than 9, since digital ports are 8-bits wide";
#endif

/* These should not be modified by the user */
#define MOTORPORT_STRING_MASK  (  ( 0xFF >> (8 - MOTORPORT_STRING_NUMBER_OF_PORT) )  << MOTORPORT_STRING_PIN_START  )
#define MOTORPORT_STRING_INIT_CONDITION  (0x01 << MOTORPORT_STRING_PIN_START)


/*************************************************************************************************/
/*********************						Typedefs						**********************/
/*************************************************************************************************/

/*************************************************************************************************/
/*********************			 	 Functions Like Macros					**********************/
/*************************************************************************************************/


/*************************************************************************************************/
/*********************					Extern Variables					**********************/
/*************************************************************************************************/

/*************************************************************************************************/
/*********************                  Extern Constants                    **********************/
/*************************************************************************************************/

/*************************************************************************************************/
/*********************					Function Prototypes					**********************/
/*************************************************************************************************/
/*!*-----------------------------------------------------------------------------------------------
* \name     MOTORPORT_String_SetValue
* \brief    Initalizes the GPIO pins used for the STEPS String and it sets it to the initial condition
*           which is the LSb of the array ON.
* \param    void
* \return   void
-------------------------------------------------------------------------------------------------*/
void MOTORPORT_String_SetValue(char u8Value);

/*!*-----------------------------------------------------------------------------------------------
* \name     MOTORPORT_String_GetValue
* \brief    Read de actual value to make masks 
* \param    void
* \return   u8 value contain the value of the STEP string. The bit that don't correspond to the string are returned as zero
-------------------------------------------------------------------------------------------------*/
char MOTORPORT_String_GetValue(void);


/*************************************************************************************************/
#endif /* LED_STRING_H_ */
