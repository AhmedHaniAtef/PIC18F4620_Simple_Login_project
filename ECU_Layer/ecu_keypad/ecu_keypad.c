/**
 * @file ecu_keypad.c
 * @author Ahmed Hani Atef
 * @brief contains the interface of keypad
 * @date 2023-09-17
 * 
 */


/****************** Start of Section : includes ********************/
#include "ecu_keypad.h"
/******************* End of Section : includes *********************/


/************ Start of Section : function definition ***************/

std_returntype keypad_initialize(keypad_cfg_t *__keypad)
{
    std_returntype ret = STD_OK;
    uint8_t counter = 0;
    if (NULL == __keypad)
    {
        ret = STD_NOT_OK;
    }
    else
    {
        for (counter = 0; counter < KEYPAD_ROW_NUM; counter++)
        {
            ret |= gpio_pin_initialize(&(__keypad->rows[counter]), GPIO_INPUT, GPIO_LOW);
        }

        for (counter = 0; counter < KEYPAD_COLUMN_NUM; counter++)
        {
            ret |= gpio_pin_initialize(&(__keypad->columns[counter]), GPIO_OUTPUT, GPIO_LOW);
        }
    }
    return ret;
}

std_returntype keypad_read(keypad_cfg_t *__keypad, uint8_t *__value)
{
    std_returntype ret = STD_OK;
    uint8_t row_counter = 0;
    uint8_t column_counter = 0;
    logic_t button_status = GPIO_LOW;
    if ((NULL == __keypad) || (NULL == __value))
    {
        ret = STD_NOT_OK;
    }
    else
    {
        *__value = '\0';
        for (column_counter = 0; column_counter < KEYPAD_COLUMN_NUM; column_counter++)
        {
            ret |= gpio_pin_write(&(__keypad->columns[column_counter]), GPIO_HIGH);

            for (row_counter = 0; row_counter < KEYPAD_ROW_NUM; row_counter++)
            {
                ret |= gpio_pin_read(&(__keypad->rows[row_counter]), &button_status);
                if (GPIO_HIGH == button_status)
                {
                    *__value = __keypad->keypad->keys_value[row_counter][column_counter];
                    break;
                }
            }

            ret |= gpio_pin_write(&(__keypad->columns[column_counter]), GPIO_LOW);
            
            if (GPIO_HIGH == button_status)
            {
                break;
            }
        }
    }
    return ret;
}

/************ End of Section :  function definition ****************/