/*
 * calculator.c
 *
 *  Created on: Oct 14, 2021
 *      Author: Eslam Mohamed
 */

#include"calculator.h"
#include<util/delay.h>

#include "LCD.h"
char sign=0;
uint8 calc_getOperand()
{
	uint8 temp =0 , operand=0 ;

	uint8 valid = TRUE ;

	while(valid)
	{
		temp = KEYPAD_getPressedKey();
		if(temp =='/'|| temp =='*'||temp =='-'||temp =='+')
		{
			sign = temp ;
			LCD_displayCharacter(sign) ;
			valid =FALSE;

		}
		else if(temp =='=')
		{
			LCD_displayCharacter('=');
			valid =FALSE;
		}
		else if (temp ==13)
		{
			LCD_clearScreen();


		}
		else
		{
			LCD_intgerToString(temp);
			operand=10*operand + temp;
		}
		_delay_ms(250);
	}
	return operand;
}

/*uint8 calc_getOperand()
{

	uint16 temp ='A',operand=0 ;
	//uint8 valid = TRUE ;


	while(temp=='A')
	{
		temp = Keypad_getkey();
	}

	if (temp =='?')
	{
		LCD_clearScreen();
	}
	else
	{
		//LCD_intgerToString(temp-48);
		LCD_intgerToString(temp);

		//to print numbers as you want as if you entered
 * temp=10, operand=10*0+10=10
 * temp=5,operand=10*10+5=105
 * temp=8,operand=10*105+8=1058

		operand=10*operand + temp;

	}
	_delay_ms(250);

	return operand;
}*/
void calc(uint16 first , uint16 second)
{
	uint16 result;
	switch(sign)
	{
	case '+':

		result = first + second;
		break;
	case '-':

		result = first - second;
		break;
	case '/':
		result = first/second;
		break;
	case '*':
		result = first * second;
		break;
	}
	LCD_intgerToString(result);
}
