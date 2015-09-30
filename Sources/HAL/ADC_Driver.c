/*
 * ADC_Driver.c
 *
 *  Created on: Sep 29, 2015
 *      Author: Alan
 */



u8 ADC_Read(void)
{
    while (!ADCSC_COCO) {
    }
    return ADCRL;
}


void ADC_Init(void)
{
    ADCCFG=0b01000000; /* Configures the ADC clock to 1M Hz, 8 bits, bus clck */
    ADCSC2= 0;
    ADCSC1 = 0b01100000 | ADC_CHANNEL; /* pin 0 por defaul */
    APCTL1 = 1 << ADC_CHANNEL;  /*Enables the control of ADC pin 0*/
}