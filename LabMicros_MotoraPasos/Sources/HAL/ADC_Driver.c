/*
 * ADC_Driver.c
 *
 *  Created on: Sep 29, 2015
 *      Author: Alan
 */


void ADC_Init(pin)
{
    ADC_PIN(pin);   /*pin must be 3 bits*/
}

void ADC_StartConversion(void)
{
    APCTL_ADPC0=1;  /*Enables the control of ADC pin 0+/
}