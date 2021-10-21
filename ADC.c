/*
 * ADC.c
 *
 *  Created on: Oct 14, 2021
 *      Author: Eslam Mohamed
 */


#include"ADC.h"
#include<avr/io.h>
#include "MACROS.h"

void ADC_init(Reference_Selection ref,Prescaler_Select scale)
{
	ADMUX = 0;				// MUX4:0  = 00000 to choose channel 0 as initialization
	switch(ref)
	{
	case AREF:
		CLEAR_BIT(ADMUX ,REFS1);
		CLEAR_BIT(ADMUX ,REFS0);
		break;
	case AVCC:
		CLEAR_BIT(ADMUX ,REFS1);
		SET_BIT(ADMUX ,REFS0);
		break;
	case Internal:
		SET_BIT(ADMUX ,REFS1);
		SET_BIT(ADMUX ,REFS0);
		break;
	}

	ADCSRA |= (1<<ADEN);

	switch(scale)
	{
	case DiVISION_BY_1:
		ADCSRA|=DiVISION_BY_1;
		break;
	case DiVISION_BY_2:
		ADCSRA|=DiVISION_BY_2;
		break;
	case DiVISION_BY_4:
		ADCSRA|=DiVISION_BY_4;
		break;
	case DiVISION_BY_8:
		ADCSRA|=DiVISION_BY_8;
		break;
	case DiVISION_BY_16:
		ADCSRA|=DiVISION_BY_16;
		break;
	case DiVISION_BY_32:
		ADCSRA|=DiVISION_BY_32;
		break;

	case DiVISION_BY_64:
		ADCSRA|=DiVISION_BY_64;
		break;
	case DiVISION_BY_128:
		ADCSRA|=DiVISION_BY_128;
		break;

	}
}



uint16 ADC_readChannel(uint8 channel_num)
{
	ADMUX&=0XE0;				//clear the older channel that was read 0 0000
	ADMUX|= channel_num;		// Choose the correct channel by setting the channel number in MUX4:0 bits
	SET_BIT(ADCSRA,ADSC);		//start conversion
	while(ADCSRA&(1<<ADSC));	//Wait for conversion to complete
	SET_BIT(ADCSRA,ADIF); 		// Clear ADIF by write '1' to it
	return ADC; 				// Read the digital value from the data register
}

