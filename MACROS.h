/*
 * MACROS.h
 *
 *  Created on: Oct 13, 2021
 *      Author: Eslam Mohamed
 */

#ifndef MACROS_H_
#define MACROS_H_

/* Set a certain bit in any register */
#define SET_BIT(REG,BIT) (REG|=(1<<BIT))

/* Clear a certain bit in any register */
#define CLEAR_BIT(REG,BIT) (REG&=(~(1<<BIT)))

/* Toggle a certain bit in any register */
#define TOGGLE_BIT(REG,BIT) (REG^=(1<<BIT))

#define GET_BIT(REG,BIT)	  ((REG>>BIT)&0x01)


#endif /* MACROS_H_ */
