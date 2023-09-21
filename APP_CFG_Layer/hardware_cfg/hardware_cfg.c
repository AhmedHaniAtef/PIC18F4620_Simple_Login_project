/**
 * @file hardware_cfg.c
 * @author Ahmed Hani Atef
 * @brief contains the configurations of hardware components 
 * @date 2023-09-18
*/


/****************** Start of Section : includes ********************/
#include "hardware_cfg.h"
/******************* End of Section : includes *********************/



/************ Start of Section : components declaration ************/
lcd_4bit_t lcd = {
    .rs_pin.port        = PORTC_I,
    .rs_pin.pin         = PIN0,
    .rs_pin.direction   = GPIO_OUTPUT,
    .rs_pin.logic       = GPIO_LOW,

    .en_pin.port        = PORTC_I,
    .en_pin.pin         = PIN1,
    .en_pin.direction   = GPIO_OUTPUT,
    .en_pin.logic       = GPIO_LOW,

    .data_pin[0].port        = PORTC_I,
    .data_pin[0].pin         = PIN2,
    .data_pin[0].direction   = GPIO_OUTPUT,
    .data_pin[0].logic       = GPIO_LOW,

    .data_pin[1].port        = PORTC_I,
    .data_pin[1].pin         = PIN3,
    .data_pin[1].direction   = GPIO_OUTPUT,
    .data_pin[1].logic       = GPIO_LOW,

    .data_pin[2].port        = PORTC_I,
    .data_pin[2].pin         = PIN4,
    .data_pin[2].direction   = GPIO_OUTPUT,
    .data_pin[2].logic       = GPIO_LOW,

    .data_pin[3].port        = PORTC_I,
    .data_pin[3].pin         = PIN5,
    .data_pin[3].direction   = GPIO_OUTPUT,
    .data_pin[3].logic       = GPIO_LOW,
};

keypad_keys_t keys = { 
    .keys_value = { {'7', '8', '9', '/'},
                    {'4', '5', '6', '*'},
                    {'1', '2', '3', '-'},
                    {'C', '0', '=', '+'},} };

keypad_cfg_t keypad = {
    .rows[0].port = PORTD_I,
    .rows[0].pin  = PIN0,

    .rows[1].port = PORTD_I,
    .rows[1].pin  = PIN1,

    .rows[2].port = PORTD_I,
    .rows[2].pin  = PIN2,

    .rows[3].port = PORTD_I,
    .rows[3].pin  = PIN3,

    .columns[0].port = PORTD_I,
    .columns[0].pin  = PIN4,

    .columns[1].port = PORTD_I,
    .columns[1].pin  = PIN5,

    .columns[2].port = PORTD_I,
    .columns[2].pin  = PIN6,

    .columns[3].port = PORTD_I,
    .columns[3].pin  = PIN7,

    .keypad = &keys,
};

led_config_t leds[4] ={
    {.port   = PORTB_I,
     .pin    = PIN0,
     .status = LED_OFF,},

    {.port   = PORTB_I,
     .pin    = PIN1,
     .status = LED_OFF,},

    {.port   = PORTB_I,
     .pin    = PIN2,
     .status = LED_OFF,},

    {.port   = PORTB_I,
     .pin    = PIN3,
     .status = LED_OFF,},
};

push_btn_config_t btn = {
    .port = PORTC_I,
    .pin  = PIN6,
};

buzzer_config_t buz = {
    .port   = PORTC_I,
    .pin    = PIN7,
    .status = BUZZER_OFF,
};

/************* End of Section : components declaration *************/



/************* Start of Section : function declaration *************/
std_returntype hardware_initialize()
{
    std_returntype ret = STD_OK;
    uint8_t counter = 0;

    ret |= lcd_4bit_initialize(&lcd);
    ret |= keypad_initialize(&keypad);

    for (counter = 0; counter < 4; counter++)
    {
        ret |= led_initialize(&leds[counter]);
    }

    ret |= push_btn_initialize(&btn);
    ret |= buzzer_initialize(&buz);
    
    if (STD_NOT_OK == ret)
    {
        while(1);
    }
    return ret;
}


/************** End of Section : function declaration **************/




