/*
 * LCD.c
 *
 *  Created on: Oct 13, 2021
 *      Author: Eslam Mohamed
 */

#include"LCD.h"
#include<util/delay.h>
#include "GPIO.h"
void LCD_init(void)
{
	GPIO_initPinDirection(LCD_RS_PORT, LCD_RS_PIN, PIN_OUTPUT);
	GPIO_initPinDirection(LCD_RW_PORT, LCD_RW_PIN, PIN_OUTPUT);
	GPIO_initPinDirection(LCD_E_PORT, LCD_E_PIN, PIN_OUTPUT);


	GPIO_setupPortDirection(LCD_DATA_PORT,PORT_OUTPUT);

	LCD_sendCommand(LCD_EIGHT_BITS_MODE); /* use 2-line lcd + 8-bit Data Mode + 5*7 dot display Mode */

	LCD_sendCommand(LCD_CURSOR_OFF); /* cursor off */

	LCD_sendCommand(LCD_CLEAR_COMMAND); /* clear LCD at the beginning */
}
void LCD_sendCommand(uint8 command)
{
	GPIO_writePin(LCD_RS_PORT, LCD_RS_PIN, LOGIC_LOW);
	GPIO_writePin(LCD_RW_PORT, LCD_RW_PIN, LOGIC_LOW);
	GPIO_writePin(LCD_E_PORT, LCD_E_PIN, LOGIC_HIGH);
	_delay_ms(1);
	GPIO_writePort(LCD_DATA_PORT, command);
	GPIO_writePin(LCD_E_PORT, LCD_E_PIN, LOGIC_LOW);
	_delay_ms(1);
}

void LCD_displayCharacter(uint8 data)
{
	GPIO_writePin(LCD_RS_PORT, LCD_RS_PIN, LOGIC_HIGH);
	GPIO_writePin(LCD_RW_PORT, LCD_RW_PIN, LOGIC_LOW);
	GPIO_writePin(LCD_E_PORT, LCD_E_PIN, LOGIC_HIGH);
	_delay_ms(1);
	GPIO_writePort(LCD_DATA_PORT, data);
	GPIO_writePin(LCD_E_PORT, LCD_E_PIN, LOGIC_LOW);
	_delay_ms(1);
}

void LCD_displayString(const char *str)
{
	for(int i=0;str[i]!='\0';i++)
	{
		LCD_displayCharacter(str[i]);
	}
}

void LCD_intgerToString(int data)
{
   char buff[16]; /* String to hold the ascii result */
   itoa(data,buff,10); /* Use itoa C function to convert the data to its corresponding ASCII value, 10 for decimal */
   LCD_displayString(buff); /* Display the string */
}

void LCD_clearScreen(void)
{
	LCD_sendCommand(LCD_CLEAR_COMMAND); /* Send clear display command */
}
