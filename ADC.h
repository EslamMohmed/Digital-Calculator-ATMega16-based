/*
 * ADC.h
 *
 *  Created on: Oct 14, 2021
 *      Author: Eslam Mohamed
 */

#ifndef ADC_H_
#define ADC_H_
#include "std_types.h"

typedef enum
{
	AREF,AVCC,Internal
}Reference_Selection;

typedef enum
{
	DiVISION_BY_1,DiVISION_BY_2,DiVISION_BY_4,DiVISION_BY_8,
	DiVISION_BY_16,DiVISION_BY_32,DiVISION_BY_64,DiVISION_BY_128

}Prescaler_Select ;


/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/
void ADC_init(Reference_Selection ref,Prescaler_Select scale);

uint16 ADC_readChannel(uint8 channel_num);

#endif /* ADC_H_ */
