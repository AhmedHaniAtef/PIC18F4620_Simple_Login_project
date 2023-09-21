/**
 * @file ecu_keypad.h
 * @author Ahmed Hani Atef
 * @brief contains the interface of the keypad
 * @date 2023-09-17
 * 
 */


#ifndef ECU_KEYPAD_H
#define ECU_KEYPAD_H

/****************** Start of Section : includes ********************/
#include "../../MCAL_Layer/hal_gpio/hal_gpio.h"
#include "ecu_keypad_cfg.h"
/******************* End of Section : includes *********************/


/****************** Start of Section : Defines *********************/

/******************* End of Section : Defines **********************/


/*************** Start of Section : macro functions ****************/

/****************** End of Section :macro functions ****************/


/*************** Start of Section : new data types *****************/

typedef struct 
{
    uint8_t keys_value[KEYPAD_ROW_NUM][KEYPAD_COLUMN_NUM];
}keypad_keys_t;

typedef struct 
{
    pin_cofig_t rows[KEYPAD_ROW_NUM];
    pin_cofig_t columns[KEYPAD_COLUMN_NUM];
    keypad_keys_t *keypad;
}keypad_cfg_t;

/****************** End of Section :new data types *****************/


/************ Start of Section : function declaration **************/
std_returntype keypad_initialize(keypad_cfg_t *__keypad);
std_returntype keypad_read(keypad_cfg_t *__keypad, uint8_t *__value);
/************ End of Section :  function declaration ***************/


#endif //ECU_KEYPAD_H
