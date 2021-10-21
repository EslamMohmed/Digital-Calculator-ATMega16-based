/*
 * LCD.h
 *
 *  Created on: Oct 13, 2021
 *      Author: Eslam Mohamed
 */
#include"GPIO.h"
#ifndef LCD_H_
#define LCD_H_
/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
/* LCD HW Ports and Pins Ids */
#define LCD_RS_PORT                  PORTC_ID
#define LCD_RS_PIN                   PIN0_ID

#define LCD_RW_PORT                  PORTC_ID
#define LCD_RW_PIN                   PIN1_ID

#define LCD_E_PORT                   PORTC_ID
#define LCD_E_PIN                    PIN2_ID

#define LCD_DATA_PORT                PORTB_ID

/* LCD Commands */
#define LCD_CLEAR_COMMAND              0x01
#define LCD_GO_TO_HOME                 0x02
#define LCD_EIGHT_BITS_MODE 		   0x38
#define LCD_FOUR_BITS_MODE   	       0x28
#define LCD_CURSOR_OFF                 0x0C
#define LCD_CURSOR_ON                  0x0E
#define LCD_SET_CURSOR_LOCATION        0x80


/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/
void LCD_init(void);

void LCD_sendCommand(uint8 command);

void LCD_displayCharacter(uint8 data);

void LCD_displayString(const char *str);

void LCD_intgerToString(int data);

void LCD_clearScreen(void);


#endif /* LCD_H_ */
