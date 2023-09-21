/* 
 * File:   pic18f4620.h
 * Author: Ahmed Hani Atef
 *
 * Created on September 2, 2023, 4:55 PM
 */

#ifndef PIC18F4620_H
#define	PIC18F4620_H

/********************* Start of Section : Defines ******************** */

#define _XTAL_FREQ 8000000

/* module : GPIO
 * creating defines for TRIS registers for each port using their address in memory
 * TRIS register used to configure the port as input or output 
 * 0 : output   1 : intput
 * Replace (x) by (A, B, ... E) to access a specific register*/
#define TRISx

#ifdef TRISx

#define TRISA   (*((volatile unsigned char *)0x92))
#define TRISB   (*((volatile unsigned char *)0x93))
#define TRISC   (*((volatile unsigned char *)0x94))
#define TRISD   (*((volatile unsigned char *)0x95))
#define TRISE   (*((volatile unsigned char *)0x96))

#endif //TRISx


/* module : GPIO
 * creating defines for LAT registers for each port using their address in memory
 * LAT register used to write the port if it is configured as output
 * 0 : low   1 : high
 * Replace (x) by (A, B, ... E) to access a specific register*/
#define LATx

#ifdef LATx

#define LATA    (*((volatile unsigned char *)0x89))
#define LATB    (*((volatile unsigned char *)0x8A))
#define LATC    (*((volatile unsigned char *)0x8B))
#define LATD    (*((volatile unsigned char *)0x8C))
#define LATE    (*((volatile unsigned char *)0x8D))

#endif //LATx


/* module : GPIO
 * creating defines for PORT registers for each port using their address in memory
 * PORT register used to read the port if it is configured as input
 * 0 : low   1 : high
 * Replace (x) by (A, B, ... E) to access a specific register*/
#define PORTx

#ifdef PORTx

#define PORTA   (*((volatile unsigned char *)0x80))
#define PORTB   (*((volatile unsigned char *)0x81))
#define PORTC   (*((volatile unsigned char *)0x82))
#define PORTD   (*((volatile unsigned char *)0x83))
#define PORTE   (*((volatile unsigned char *)0x84))

#endif //PORTx

#define MAX_PIN     (8)
#define MAX_PORT    (5)
#define REG_MASK    (0xFF)

/********************** End of Section : Defines ********************* */


/***************** Start of Section : macro functions **************** */

#define HWREG(reg)  (*((volatile unsigned char *)reg)) // access a 8-bit register

#define READ_BIT(reg, bit_position)     (((HWREG(reg) & (1 << bit_position)) >> bit_position)) // read a bit
#define SET_BIT(reg, bit_position)      (HWREG(reg) |= (1 << bit_position))      // sets a bit
#define TOGGLE_BIT(reg, bit_position)   (HWREG(reg) ^= (1 << bit_position))      // toggle a bit
#define CLEAR_BIT(reg, bit_position)    (HWREG(reg) &= ~(1 << bit_position))     // clears a bit

/****************** End of Section : macro functions ***************** */

#endif	/* PIC18F4620_H */


/********************************************************************************
 * log
 * ******************************************************************************
 * author               date            details
 * ******************************************************************************
 * Ahmed Hani Atef      02-09-2023      - creating defines for GPIO registers
 * Ahmed Hani Atef      03-09-2023      - creating macro function to access a
 *                                        8-bit register
 *                                      - create macro functions to set, clear 
 *                                        and toggle a specific bit
 * 
 */

