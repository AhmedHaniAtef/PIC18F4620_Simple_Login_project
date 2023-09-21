/* 
 * File:   mcal_std_types.h
 * Author: Ahmed Hani Atef
 *
 * Created on September 2, 2023, 4:51 PM
 */

#ifndef MCAL_STD_TYPES_H
#define	MCAL_STD_TYPES_H

/******************* Start of Section :    defines *******************/

#define EXIT_STATUS_SUCCESS (0)
#define EXIT_STATUS_FAILED  (1)

#define STD_OK      ((std_returntype) 0)
#define STD_NOT_OK  ((std_returntype) 1)

#define __8_BIT_ARC_MICROCONTROLLER_

/******************** End of Section :    defines ********************/


/***************** Start of Section :  new data types ****************/

#ifdef __8_BIT_ARC_MICROCONTROLLER_ 

typedef unsigned char   boolean;
typedef unsigned char   uint8_t;
typedef unsigned short  uint16_t;
typedef unsigned long   uint32_t;
typedef signed char     sint8_t;
typedef signed int      sint16_t;
typedef signed long     sint32_t;
typedef float           float32_t;

#elif  __16_BIT_ARC_MICROCONTROLLER_ 

#elif  __32_BIT_ARC_MICROCONTROLLER_ 

#else 

#endif

typedef uint8_t std_returntype;

typedef enum {
    GPIO_LOW = 0,   
    GPIO_HIGH
}logic_t;

typedef enum {
    PIN0 = 0,   
    PIN1,
    PIN2,
    PIN3,
    PIN4,
    PIN5,
    PIN6,
    PIN7
}pin_index_t;

typedef enum {
    GPIO_OUTPUT = 0,   
    GPIO_INPUT
}direction_t;

typedef enum {
    PORTA_I = 0,
    PORTB_I,
    PORTC_I,
    PORTD_I,
    PORTE_I
}port_index_t;

typedef enum {
    IDLE = 0,
    ACTIVE
}status_t;


/****************** End of Section :  new data types *****************/


#endif	/* MCAL_STD_TYPES_H */



/********************************************************************************
 * log
 * ******************************************************************************
 * author               date            details
 * ******************************************************************************
 * Ahmed Hani Atef      02-09-2023      - creating new data types 
 */

