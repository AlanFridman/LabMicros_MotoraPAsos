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

#include <hidef.h> 					/* for EnableInterrupts macro */
#include "derivative.h" 			/* include peripheral declarations */
#include "types.h" 					/*Include data types */
#include "HIL\MOTORPORT_String.h"7	/**/
#include "HIL\Stepper_Manager.h"	/**/
#include "HIL\Speed_Manager.h"		/**/
#include "HIL\Direction_Manager.h"	/**/


void main(void) 
{
	
#ifndef ARRAY_IMPLEMENTATION
 	EnableInterrupts;	
	Set_Pins_Out();
	Pullup_Init();
	Switch_Init();
	for(;;)  // Loop forever
	{		
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
