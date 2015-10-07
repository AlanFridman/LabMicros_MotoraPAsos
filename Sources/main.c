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

#include "types.h"
#include <hidef.h> /* for EnableInterrupts macro */
#include "derivative.h" /* include peripheral declarations */
#include "HIL\MOTORPORT_String.h"
#include "HIL\Stepper_Manager.h"
#include "HIL\Speed_Manager.h"
#include "HIL\Direction_Manager.h"


void main(void) 
{
	MOTORPORT_Init();
	Pullup_Init();
	Switch_Init();
	EnableInterrupts;	
	for(;;)  // Loop forever
	{
		__RESET_WATCHDOG();	/* feeds the dog */
		
		if(Switch_IsPressed())
		{
			forward();
			Motor_Speed();
		}
		else
		{
			reverse();
			Motor_Speed();
		}
		
	}
}
