/*! **********************************************************************************************
* 2015  ITESM Campus Guadalajara. Laboratorio de Microcontroladores 
*  
*
* @file:      main.c
* @author(s):  
*
* @brief (Theory of Operation)
*
**************************************************************************************************/

#include <hidef.h> /* for EnableInterrupts macro */
#include "derivative.h" /* include peripheral declarations */
#include "types.h"
#include "HIL\MOTORPORT_String.h"
#include "HIL\Stepper_Manager.h"
#include "HIL\Speed_Manager.h"
#include "HIL\Direction_Manager.h"

#define INIT_VAL 0x80


void main(void) 
{
	
#ifndef ARRAY_IMPLEMENTATION
v 	EnableInterrupts;	
	Set_Pins_Out();
	Pullup_Init();
	Switch_Init();
	for(;;)  // Loop forever
	{
		__RESET_WATCHDOG();	/* feeds the dog */
		
		if(Switch_IsPressed()==1)
		{
			forward();
			Motor_Speed();
		}
		else
		{
			reverse();
			Motor_Speed();
		}
		__RESET_WATCHDOG();	/* feeds the dog */

	}
#endif

}
