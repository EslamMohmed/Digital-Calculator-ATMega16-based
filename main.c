/*
 * main.c
 *
 *  Created on: Oct 14, 2021
 *      Author: Eslam Mohamed
 */

#include<avr/io.h>
#include<util/delay.h>
#include"KEYPAD.h"
#include "std_types.h"
uint16 num1,num2;
uint16 key_pressed;
int main()
{
	LCD_init();
	while(1)
	{
		num1=calc_getOperand();
		num2=calc_getOperand();
		calc(num1, num2);
	}
}
/*LCD_init();
	Keypad_init();
	while(1)
	{
		key_pressed=Keypad_getkey();
		switch(key_pressed)
		{
		case'A':
			break;
		case'?':
			LCD_clearScreen();
			break;
		default:
			LCD_displayCharacter (key_pressed);

		}
	}*/

/*int main()
{
	Keypad_init();
	LCD_init();
	uint32 input1 =0;
	uint32 input2 =0;
	uint8 op,current_key='A';
	while(current_key=='A')
	{
		current_key = Keypad_getkey();
	}
	while(TRUE)
	{
		current_key=Keypad_getkey();
		LCD_displayCharacter(current_key);
		if(current_key == '+' || current_key == '-' || current_key == 'x' || current_key == '/')
		{
			op = current_key;
			while(TRUE)
			{
				Keypad_getkey();
				LCD_displayCharacter(current_key);
				if(current_key == '=')break;
				input2 = (current_key-48) + input2*10;
			}

			switch(op)
			{
			case '+' :
				LCD_displayCharacter(input1 + input2);
				break;
			case '-' :
				LCD_displayCharacter(input1 - input2);
				break;
			case 'x' :
				LCD_displayCharacter(input1 * input2);
				break;
			case '/' :
				if(input2 == 0)
				{
					LCD_clearScreen();
					LCD_displayString("Error!");
				}
				else
				{
					LCD_displayCharacter((int)input1 / input2);
					LCD_displayString(".");
					int reminder = (int)(((float)(input1 % input2)/input2)*100);
					LCD_displayCharacter(reminder);
				}
				break;
			}
		}
	}
}*/


