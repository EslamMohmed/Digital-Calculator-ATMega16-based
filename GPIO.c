/*
 * GPIO.c
 *
 *  Created on: Oct 13, 2021
 *      Author: Eslam Mohamed
 */

#include"GPIO.h"
#include<avr/io.h>
#include <avr/iom16.h>
//determine if it input or output
void GPIO_initPinDirection(uint8 port_num, uint8 pin_num, GPIO_PinDirectionType direction)
{

	switch(port_num)
	{
	case PORTA_ID:
		if(direction == PIN_OUTPUT)
		{
			SET_BIT(DDRA,pin_num);
		}
		else
		{
			CLEAR_BIT(DDRA,pin_num);
		}
		break;
	case PORTB_ID:
		if(direction == PIN_OUTPUT)
		{
			SET_BIT(DDRB,pin_num);
		}
		else
		{
			CLEAR_BIT(DDRB,pin_num);
		}
		break;
	case PORTC_ID:
		if(direction == PIN_OUTPUT)
		{
			SET_BIT(DDRC,pin_num);
		}
		else
		{
			CLEAR_BIT(DDRC,pin_num);
		}
		break;
	case PORTD_ID:
		if(direction == PIN_OUTPUT)
		{
			SET_BIT(DDRD,pin_num);
		}
		else
		{
			CLEAR_BIT(DDRD,pin_num);
		}
		break;
	}
}
//determine if it HIGH or LOW
void GPIO_writePin(uint8 port_num, uint8 pin_num, uint8 value)
{
	switch(port_num)
	{
	case PORTA_ID:
		if(value == LOGIC_HIGH)
		{
			SET_BIT(PORTA,pin_num);
		}
		else
		{
			CLEAR_BIT(PORTA,pin_num);
		}
		break;
	case PORTB_ID:
		if(value == LOGIC_HIGH)
		{
			SET_BIT(PORTB,pin_num);
		}
		else
		{
			CLEAR_BIT(PORTB,pin_num);
		}
		break;
	case PORTC_ID:
		if(value == LOGIC_HIGH)
		{
			SET_BIT(PORTC,pin_num);
		}
		else
		{
			CLEAR_BIT(PORTC,pin_num);
		}
		break;
	case PORTD_ID:
		if(value == LOGIC_HIGH)
		{
			SET_BIT(PORTD,pin_num);
		}
		else
		{
			CLEAR_BIT(PORTD,pin_num);
		}
		break;
	}
}

uint8 GPIO_readPin(uint8 port_num, uint8 pin_num)
{
	uint8 pin_value = LOGIC_LOW;

	switch(port_num)
	{
	case PORTA_ID:
		pin_value=GET_BIT(PINA,pin_num);
		break;
	case PORTB_ID:
		pin_value=GET_BIT(PINB,pin_num);
		break;
	case PORTC_ID:
		pin_value=GET_BIT(PINC,pin_num);
		break;
	case PORTD_ID:
		if(GET_BIT(PIND,pin_num))
			pin_value=GET_BIT(PIND,pin_num);
		break;
	}
	return pin_value;
}


void GPIO_setupPortDirection(uint8 port_num, GPIO_PortDirectionType direction)
{
	switch(port_num)
	{
	case PORTA_ID:
		DDRA = direction;
		break;
	case PORTB_ID:
		DDRB = direction;
		break;
	case PORTC_ID:
		DDRC = direction;
		break;
	case PORTD_ID:
		DDRD = direction;
		break;
	}
}

void GPIO_writePort(uint8 port_num, uint8 value)
{
	/*
	 * Check if the input number is greater than NUM_OF_PORTS value.
	 * In this case the input is not valid port number
	 */

	/* Write the port value as required */
	switch(port_num)
	{
	case PORTA_ID:
		PORTA = value;
		break;
	case PORTB_ID:
		PORTB = value;
		break;
	case PORTC_ID:
		PORTC = value;
		break;
	case PORTD_ID:
		PORTD = value;
		break;
	}
}
