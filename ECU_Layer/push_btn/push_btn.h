/* 
 * File:   push_btn.h
 * Author: Ahmed Hani Atef
 *
 * Created on September 4, 2023, 1:41 PM
 */

#ifndef PUSH_BTN_H
#define	PUSH_BTN_H

/****************** Start of Section : includes ********************/
#include "../../MCAL_Layer/hal_gpio/hal_gpio.h"
/******************* End of Section : includes *********************/

/*************** Start of Section : new data types *****************/


typedef struct 
{
    uint8_t port : 4;
    uint8_t pin : 4;
}push_btn_config_t;


/****************** End of Section :new data types *****************/


/************ Start of Section : function declaration **************/

std_returntype push_btn_initialize (push_btn_config_t *__btn);
std_returntype push_btn_read (push_btn_config_t *__btn, logic_t *__status);

/************ End of Section :  function declaration ***************/


#endif	/* PUSH_BTN_H */

