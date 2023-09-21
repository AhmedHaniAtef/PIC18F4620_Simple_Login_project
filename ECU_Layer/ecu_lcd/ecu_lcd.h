/**
 * @file ecu_lcd.h
 * @author Ahmed Hani Atef
 * @brief contains the interface of LCD module 
 * @version 0.1
 * @date 2023-09-15
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef ECU_LCD_H
#define ECU_LCD_H


/****************** Start of Section : includes ********************/
#include "../../MCAL_Layer/hal_gpio/hal_gpio.h"
#include "ecu_lcd_cfg.h"
/******************* End of Section : includes *********************/


/****************** Start of Section : Defines *********************/

/*------------ COMMANDS OF LCD MICROCONTROLLER ------------*/
#define MODE_4BIT   (4)
#define MODE_8BIT   (8)
/* Very Important note: when using command merging function you should 
take your care of which commands can be merge together otherwise you 
can corrupt the command and the lcd functionality */

/* 
It is recommended to use merge COMMAND_MERGE function with a whole command of one instruction 
for example : 
COMMAND_MERGE(LCD_BUS_MODE_8_BIT, COMMAND(LCD_DISPLAY_MODE_2_LINE, LCD_FORMAT_DISPLAY_MODE_5_8)
this is a whole configuration of one instruction which means :
lcd will be in 8 bit mode connection to microcontroller with 2 line mode and a 5x8 format for each character
*/

#define LCD_DISPLAY_CLEAR                   (0x01)

#define LCD_RETURN_HOME                     (0x02)

// Entry Mode Set
#define LCD_ADDRESS_COUNTER_INCREMENT       (0x06)
#define LCD_ADDRESS_COUNTER_DECREMENT       (0x04)
#define LCD_SHIFT_MODE_OFF                  (0x04)
#define LCD_SHIFT_MODE_ON                   (0x05)

// Display ON/OFF Control   
#define LCD_DISPLAY_OFF                     (0x08)
#define LCD_DISPLAY_ON                      (0x0C)
#define LCD_UNDERLINE_OFF                   (0x08)
#define LCD_UNDERLINE_ON                    (0x0A)
#define LCD_CURSOR_BLINK_OFF                (0x08)
#define LCD_CURSOR_BLINK_ON                 (0x09)

// Cursor or Display Shift ---> it will be useful when use LCD_SHIFT_MODE_ON define
#define LCD_CURSOR_SHIFT                    (0x10)
#define LCD_DISPLAY_SHIFT                   (0x18)
#define LCD_SHIFT_LEFT                      (0x10)
#define LCD_SHIFT_RIGHT                     (0x14)

// Function Set
#define LCD_BUS_MODE_8_BIT                  (0x30)
#define LCD_BUS_MODE_4_BIT                  (0x20)
#define LCD_DISPLAY_MODE_1_LINE             (0x20)
#define LCD_DISPLAY_MODE_2_LINE             (0x28)
#define LCD_FORMAT_DISPLAY_MODE_5_8         (0x20)
#define LCD_FORMAT_DISPLAY_MODE_5_11        (0x24)

/*------------ LCD RESOLUTIONS ------------*/
#ifdef LCD_16_1
#define ROW1            (1)
#define ROW1_ADDRESS    (0x80)
#endif
/*--------------------------------------*/
#ifdef LCD_16_2
#define ROW1            (1)
#define ROW2            (2)
#define ROW1_ADDRESS    (0x80)
#define ROW2_ADDRESS    (0xC0)
#endif
/*--------------------------------------*/
#ifdef LCD_16_4
#define ROW1            (1)
#define ROW2            (2)
#define ROW3            (3)
#define ROW4            (4)
#define ROW1_ADDRESS    (0x80)
#define ROW2_ADDRESS    (0xC0)
#define ROW3_ADDRESS    (0x95)
#define ROW4_ADDRESS    (0xD5)
#endif
/*--------------------------------------*/
#ifdef LCD_20_2
#define ROW1            (1)
#define ROW2            (2)
#define ROW1_ADDRESS    (0x80)
#define ROW2_ADDRESS    (0xC0)
#endif
/*--------------------------------------*/
#ifdef LCD_20_4
#define ROW1            (1)
#define ROW2            (2)
#define ROW3            (3)
#define ROW4            (4)
#define ROW1_ADDRESS    (0x80)
#define ROW2_ADDRESS    (0xC0)
#define ROW3_ADDRESS    (0x95)
#define ROW4_ADDRESS    (0xD5)
#endif
/*--------------------------------------*/
#ifdef LCD_32_2
#define ROW1            (1)
#define ROW2            (2)
#define ROW1_ADDRESS    (0x80)
#define ROW2_ADDRESS    (0xC0)
#endif
/*--------------------------------------*/
#ifdef LCD_40_2
#define ROW1            (1)
#define ROW2            (2)
#define ROW1_ADDRESS    (0x80)
#define ROW2_ADDRESS    (0xC0)
#endif

/*------------ CGRAM ADDRESS ------------*/
#define CGRAM_START_ADDRESS (0x40)

/********************** End of Section :Defines ********************/


/*************** Start of Section : macro functions ****************/

#define COMMAND_MERGE(__first, __second)        ((__first) | (__second))

/****************** End of Section :macro functions ****************/


/*************** Start of Section : new data types *****************/
typedef struct 
{
    pin_cofig_t data_pin[MODE_4BIT];
    pin_cofig_t rs_pin;
    pin_cofig_t en_pin;
}lcd_4bit_t;

typedef struct 
{
    pin_cofig_t data_pin[MODE_8BIT];
    pin_cofig_t rs_pin;
    pin_cofig_t en_pin;
}lcd_8bit_t;

/*--------------------------------------*/
typedef enum
{
    DISPLAY_SHIFT_LEFT,
    DISPLAY_SHIFT_RIGHT,
}lcd_display_shift_direction_t;

typedef enum
{
    AUTO_SHIFT_OFF,
    AUTO_SHIFT_ON,
}lcd_display_shift_auto_t;

typedef struct 
{
    uint8_t step;
    uint16_t duration;
}lcd_display_shift_on_t;

typedef struct 
{
    uint8_t step;
}lcd_display_shift_off_t;

typedef union 
{
    lcd_display_shift_on_t auto_shift_on;
    lcd_display_shift_off_t auto_shift_off;
}lcd_display_shift_mode_t;

typedef struct 
{
    lcd_display_shift_auto_t mode;
    lcd_display_shift_mode_t configurations;
    lcd_display_shift_direction_t direction;
}lcd_display_shift_cfg_t;
/*--------------------------------------*/

typedef enum
{
    LCD_DISPLAY_CLEAR_BEHAVIOR,
    LCD_DISPLAY_ON_BEHAVIOR,
    LCD_DISPLAY_OFF_BEHAVIOR,
    LCD_RETURN_HOME_BEHAVIOR,
    LCD_NEXT_CHAR_INCREMENT,
    LCD_NEXT_CHAR_DECREMENT,
    LCD_SHOW_UNDERLINE_CURSOR,
    LCD_HIDE_UNDERLINE_CURSOR,
    LCD_SHOW_CURSOR_BLINK,
    LCD_HIDE_CURSOR_BLINK,
}lcd_behavior_t;
/****************** End of Section :new data types *****************/


/************ Start of Section : function declaration **************/
std_returntype lcd_4bit_initialize (lcd_4bit_t *__lcd);
std_returntype lcd_4bit_send_command(lcd_4bit_t *__lcd, uint8_t __command);
std_returntype lcd_4bit_send_data(lcd_4bit_t *__lcd, uint8_t __data);
std_returntype lcd_4bit_send_char(lcd_4bit_t *__lcd, uint8_t __character);
std_returntype lcd_4bit_send_char_pos(lcd_4bit_t *__lcd, uint8_t __row, uint8_t __column, uint8_t __character);
std_returntype lcd_4bit_send_string(lcd_4bit_t *__lcd, uint8_t *str);
std_returntype lcd_4bit_send_string_pos(lcd_4bit_t *__lcd, uint8_t __row, uint8_t __column, uint8_t *str);
std_returntype lcd_4bit_send_custom_char_pos(lcd_4bit_t *__lcd, uint8_t __row, uint8_t __column, uint8_t __ch[], uint8_t __mem_pos);
std_returntype lcd_4bit_shift(lcd_4bit_t *__lcd, lcd_display_shift_cfg_t *__shift);
std_returntype lcd_4bit_behavior(lcd_4bit_t *__lcd, lcd_behavior_t __behavior);

std_returntype lcd_8bit_initialize (lcd_8bit_t *__lcd);
std_returntype lcd_8bit_send_command(lcd_8bit_t *__lcd, uint8_t __command);
std_returntype lcd_8bit_send_data(lcd_8bit_t *__lcd, uint8_t __data);
std_returntype lcd_8bit_send_char(lcd_8bit_t *__lcd, uint8_t __character);
std_returntype lcd_8bit_send_char_pos(lcd_8bit_t *__lcd, uint8_t __row, uint8_t __column, uint8_t __character);
std_returntype lcd_8bit_send_string(lcd_8bit_t *__lcd, uint8_t *str);
std_returntype lcd_8bit_send_string_pos(lcd_8bit_t *__lcd, uint8_t __row, uint8_t __column, uint8_t *str);
std_returntype lcd_8bit_send_custom_char_pos(lcd_8bit_t *__lcd, uint8_t __row, uint8_t __column, uint8_t __ch[], uint8_t __mem_pos);
std_returntype lcd_8bit_shift(lcd_8bit_t *__lcd, lcd_display_shift_cfg_t *__shift);
std_returntype lcd_8bit_behavior(lcd_8bit_t *__lcd, lcd_behavior_t __behavior);

std_returntype convert_uint8_to_string(uint8_t value, uint8_t *str);
std_returntype convert_uint16_to_string(uint16_t value, uint8_t *str);
std_returntype convert_uint32_to_string(uint32_t value, uint8_t *str);
/************ End of Section :  function declaration ***************/



#endif // ECU_LCD_H