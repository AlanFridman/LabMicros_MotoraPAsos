
 /*! **********************************************************************************************
 * 2014  ITESM Campus Guadalajara. Laboratorio de Microcontroladores
 *
 * @file:      SpeedDelayManager.h
 * @author(s): 	Yoku Sashida Mendez / Alan Fridman

 *
 * @brief (User's Manual):
 *    This is a simple GPIO driver for the 9S08QG8 MCU. It provides only macro-like functions to
 *    reduce code footprint.
 *
 **************************************************************************************************/

#ifndef SPEED_MANAGER_H_
#define SPEED_MANAGER_H_

#include "derivative.h" /* include peripheral declarations */

/*************************************************************************************************/
/*********************						Includes						**********************/
/*************************************************************************************************/
#include "types.h"

/*************************************************************************************************/
/*********************						Defines							**********************/
/*************************************************************************************************/

/*************************************************************************************************/
/*********************						Typedefs						**********************/
/*************************************************************************************************/

/*************************************************************************************************/
/*********************			 	 Functions Like Macros					**********************/
/*************************************************************************************************/

/* DO NOT MODIFY OR USE THESE ********************************************************************/

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
* \name     Motor_Speed
* \brief    Make the convertion from the analog read and make the delay to control the speed.
* \param    void
* \return   void
-------------------------------------------------------------------------------------------------*/
void Motor_Speed(void);


/*************************************************************************************************/
#endif /* SPEEDDELAYMANAGER_H_ */
 
