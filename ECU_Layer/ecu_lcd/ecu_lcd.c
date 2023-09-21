/**
 * @file ecu_lcd.c
 * @author Ahmed Hani Atef
 * @brief contains the interface of LCD module
 * @version 0.1
 * @date 2023-09-15
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "ecu_lcd.h"

static std_returntype lcd_send_4bit(lcd_4bit_t *__lcd, uint8_t __bits);
static std_returntype lcd_4bit_send_enable_signal(lcd_4bit_t *__lcd);
static std_returntype lcd_4bit_set_cursor(lcd_4bit_t *__lcd, uint8_t __row, uint8_t __column);

static std_returntype lcd_8bit_send_enable_signal(lcd_8bit_t *__lcd);
static std_returntype lcd_8bit_set_cursor(lcd_8bit_t *__lcd, uint8_t __row, uint8_t __column);

std_returntype lcd_4bit_initialize(lcd_4bit_t *__lcd)
{
    std_returntype ret = STD_OK;
    if (NULL == __lcd)
    {
        ret = STD_NOT_OK;
    }
    else
    {
        ret |= gpio_pin_initialize(&(__lcd->rs_pin), (__lcd->rs_pin.direction), (__lcd->rs_pin.logic));
        ret |= gpio_pin_initialize(&(__lcd->en_pin), (__lcd->en_pin.direction), (__lcd->en_pin.logic));
        ret |= gpio_pin_initialize(&(__lcd->data_pin[0]), (__lcd->data_pin[0].direction), (__lcd->data_pin[0].logic));
        ret |= gpio_pin_initialize(&(__lcd->data_pin[1]), (__lcd->data_pin[1].direction), (__lcd->data_pin[1].logic));
        ret |= gpio_pin_initialize(&(__lcd->data_pin[2]), (__lcd->data_pin[2].direction), (__lcd->data_pin[2].logic));
        ret |= gpio_pin_initialize(&(__lcd->data_pin[3]), (__lcd->data_pin[3].direction), (__lcd->data_pin[3].logic));

        ret |= lcd_4bit_send_command(__lcd, COMMAND_MERGE(LCD_BUS_MODE_8_BIT, COMMAND_MERGE(LCD_DISPLAY_MODE_2_LINE, LCD_DISPLAY_MODE_2_LINE)));
        __delay_ms(20);
        ret |= lcd_4bit_send_command(__lcd, COMMAND_MERGE(LCD_BUS_MODE_8_BIT, COMMAND_MERGE(LCD_DISPLAY_MODE_2_LINE, LCD_DISPLAY_MODE_2_LINE)));
        __delay_ms(5);
        ret |= lcd_4bit_send_command(__lcd, COMMAND_MERGE(LCD_BUS_MODE_8_BIT, COMMAND_MERGE(LCD_DISPLAY_MODE_2_LINE, LCD_DISPLAY_MODE_2_LINE)));
        __delay_us(150);
        ret |= lcd_4bit_send_command(__lcd, LCD_DISPLAY_CLEAR);
        ret |= lcd_4bit_send_command(__lcd, LCD_RETURN_HOME);
        ret |= lcd_4bit_send_command(__lcd, COMMAND_MERGE(LCD_ADDRESS_COUNTER_INCREMENT, LCD_SHIFT_MODE_OFF));
        ret |= lcd_4bit_send_command(__lcd, COMMAND_MERGE(LCD_DISPLAY_ON, COMMAND_MERGE(LCD_UNDERLINE_OFF, LCD_CURSOR_BLINK_OFF)));
        ret |= lcd_4bit_send_command(__lcd, COMMAND_MERGE(LCD_BUS_MODE_4_BIT, COMMAND_MERGE(LCD_DISPLAY_MODE_2_LINE, LCD_DISPLAY_MODE_2_LINE)));
        ret |= lcd_4bit_send_command(__lcd, 0x80);
    }
    return ret;
}

std_returntype lcd_4bit_send_command(lcd_4bit_t *__lcd, uint8_t __command)
{
    std_returntype ret = STD_OK;
    if (NULL == __lcd)
    {
        ret = STD_NOT_OK;
    }
    else
    {
        ret |= gpio_pin_write(&(__lcd->rs_pin), GPIO_LOW);
        ret |= lcd_send_4bit(__lcd, ((__command >> 4) & 0x0F)); // at first we should send the most 4 bits
        ret |= lcd_4bit_send_enable_signal(__lcd);
        ret |= lcd_send_4bit(__lcd, ((__command >> 0) & 0x0F)); // then we send the least 4 bits
        ret |= lcd_4bit_send_enable_signal(__lcd);
    }
    return ret;
}

std_returntype lcd_4bit_send_data(lcd_4bit_t *__lcd, uint8_t __data)
{
    std_returntype ret = STD_OK;
    if (NULL == __lcd)
    {
        ret = STD_NOT_OK;
    }
    else
    {
        ret |= gpio_pin_write(&(__lcd->rs_pin), GPIO_HIGH);
        ret |= lcd_send_4bit(__lcd, ((__data >> 4) & 0x0F)); // at first we should send the most 4 bits
        ret |= lcd_4bit_send_enable_signal(__lcd);
        ret |= lcd_send_4bit(__lcd, ((__data >> 0) & 0x0F)); // then we send the least 4 bits
        ret |= lcd_4bit_send_enable_signal(__lcd);
    }
    return ret;
}

std_returntype lcd_4bit_send_char(lcd_4bit_t *__lcd, uint8_t __character)
{
    std_returntype ret = STD_OK;
    if (NULL == __lcd)
    {
        ret = STD_NOT_OK;
    }
    else
    {
        ret |= lcd_4bit_send_data(__lcd, __character);
    }
    return ret;
}

std_returntype lcd_4bit_send_char_pos(lcd_4bit_t *__lcd, uint8_t __row, uint8_t __column, uint8_t __character)
{
    std_returntype ret = STD_OK;
    if (NULL == __lcd)
    {
        ret = STD_NOT_OK;
    }
    else
    {
        ret |= lcd_4bit_set_cursor(__lcd, __row, __column);
        ret |= lcd_4bit_send_data(__lcd, __character);
    }
    return ret;
}

std_returntype lcd_4bit_send_string(lcd_4bit_t *__lcd, uint8_t *str)
{
    std_returntype ret = STD_OK;
    if ((NULL == __lcd) || (NULL == str))
    {
        ret = STD_NOT_OK;
    }
    else
    {
        while (*str != '\0')
        {
            ret |= lcd_4bit_send_data(__lcd, *str++);
        }
    }
    return ret;
}

std_returntype lcd_4bit_send_string_pos(lcd_4bit_t *__lcd, uint8_t __row, uint8_t __column, uint8_t *str)
{
    std_returntype ret = STD_OK;
    if ((NULL == __lcd) || (NULL == str))
    {
        ret = STD_NOT_OK;
    }
    else
    {
        ret |= lcd_4bit_set_cursor(__lcd, __row, __column);
        while (*str != '\0')
        {
            ret |= lcd_4bit_send_data(__lcd, *str++);
        }
    }
    return ret;
}

std_returntype lcd_4bit_send_custom_char_pos(lcd_4bit_t *__lcd, uint8_t __row, uint8_t __column, uint8_t __ch[], uint8_t __mem_pos)
{
    std_returntype ret = STD_OK;
    if (NULL == __lcd)
    {
        ret = STD_NOT_OK;
    }
    else
    {
        __mem_pos--;
        ret |= lcd_4bit_send_command(__lcd, (CGRAM_START_ADDRESS + (__mem_pos * 8)));
        ret |= lcd_4bit_send_data(__lcd, __ch[0]);
        ret |= lcd_4bit_send_data(__lcd, __ch[1]);
        ret |= lcd_4bit_send_data(__lcd, __ch[2]);
        ret |= lcd_4bit_send_data(__lcd, __ch[3]);
        ret |= lcd_4bit_send_data(__lcd, __ch[4]);
        ret |= lcd_4bit_send_data(__lcd, __ch[5]);
        ret |= lcd_4bit_send_data(__lcd, __ch[6]);
        ret |= lcd_4bit_send_data(__lcd, __ch[7]);
        ret |= lcd_4bit_send_char_pos(__lcd, __row, __column, __mem_pos);
    }
    return ret;
}

std_returntype lcd_4bit_shift(lcd_4bit_t *__lcd, lcd_display_shift_cfg_t *__shift)
{
    std_returntype ret = STD_OK;
    uint8_t shift_counter = 0;
    uint16_t duration_counter = 0;
    if (NULL == __lcd)
    {
        ret = STD_NOT_OK;
    }
    else
    {
        ret |= lcd_4bit_send_command(__lcd, COMMAND_MERGE(LCD_ADDRESS_COUNTER_INCREMENT, LCD_SHIFT_MODE_ON));
        switch (__shift->mode)
        {
        case AUTO_SHIFT_ON:
            for (shift_counter = 0; 
                 shift_counter <__shift->configurations.auto_shift_off.step; 
                 shift_counter++)
            {
                if (__shift->direction == DISPLAY_SHIFT_LEFT)
                {
                    ret |= lcd_4bit_send_command(__lcd, COMMAND_MERGE(LCD_DISPLAY_SHIFT, LCD_SHIFT_LEFT));
                }
                else
                {
                    ret |= lcd_4bit_send_command(__lcd, COMMAND_MERGE(LCD_DISPLAY_SHIFT, LCD_SHIFT_RIGHT));
                }
                for(duration_counter = 0; duration_counter < __shift->configurations.auto_shift_on.duration; duration_counter++)
                {
                    __delay_ms(1);
                }
            }
            break;

        case AUTO_SHIFT_OFF:
            for (shift_counter = 0; 
                 shift_counter <__shift->configurations.auto_shift_off.step; 
                 shift_counter++)
            {
                if (__shift->direction == DISPLAY_SHIFT_LEFT)
                {
                    ret |= lcd_4bit_send_command(__lcd, COMMAND_MERGE(LCD_DISPLAY_SHIFT, LCD_SHIFT_LEFT));
                }
                else
                {
                    ret |= lcd_4bit_send_command(__lcd, COMMAND_MERGE(LCD_DISPLAY_SHIFT, LCD_SHIFT_RIGHT));
                }
            }
            break;
        default:
            ret = STD_NOT_OK;
            break;
        }
    }
    return ret;
}

std_returntype lcd_4bit_behavior(lcd_4bit_t *__lcd, lcd_behavior_t __behavior)
{
    std_returntype ret = STD_OK;
    if (NULL == __lcd)
    {
        ret = STD_NOT_OK;
    }
    else
    {
        switch (__behavior)
        {
        case LCD_DISPLAY_CLEAR_BEHAVIOR:
            ret |= lcd_4bit_send_command(__lcd, LCD_DISPLAY_CLEAR);
            break;
        case LCD_DISPLAY_ON_BEHAVIOR:
            ret |= lcd_4bit_send_command(__lcd, LCD_DISPLAY_ON);
            break;
        case LCD_DISPLAY_OFF_BEHAVIOR:
            ret |= lcd_4bit_send_command(__lcd, LCD_DISPLAY_OFF);
            break;
        case LCD_RETURN_HOME_BEHAVIOR:
            ret |= lcd_4bit_send_command(__lcd, LCD_RETURN_HOME);
            break;
        case LCD_NEXT_CHAR_INCREMENT:
            ret |= lcd_4bit_send_command(__lcd, LCD_ADDRESS_COUNTER_INCREMENT);
            break;
        case LCD_NEXT_CHAR_DECREMENT:
            ret |= lcd_4bit_send_command(__lcd, LCD_ADDRESS_COUNTER_DECREMENT);
            break;
        case LCD_SHOW_UNDERLINE_CURSOR:
            ret |= lcd_4bit_send_command(__lcd, COMMAND_MERGE(LCD_DISPLAY_ON, LCD_UNDERLINE_ON));
            break;
        case LCD_HIDE_UNDERLINE_CURSOR:
            ret |= lcd_4bit_send_command(__lcd, COMMAND_MERGE(LCD_DISPLAY_ON, LCD_UNDERLINE_OFF));
            break;
        case LCD_SHOW_CURSOR_BLINK:
            ret |= lcd_4bit_send_command(__lcd, COMMAND_MERGE(LCD_DISPLAY_ON, LCD_CURSOR_BLINK_ON));
            break;
        case LCD_HIDE_CURSOR_BLINK:
            ret |= lcd_4bit_send_command(__lcd,  COMMAND_MERGE(LCD_DISPLAY_ON, LCD_CURSOR_BLINK_OFF));
            break;
        default:
            ret |= STD_NOT_OK;
            break;
        }
    }
    return ret;
}



std_returntype lcd_8bit_initialize(lcd_8bit_t *__lcd)
{
    std_returntype ret = STD_OK;
    if (NULL == __lcd)
    {
        ret = STD_NOT_OK;
    }
    else
    {
        ret |= gpio_pin_initialize(&(__lcd->rs_pin), (__lcd->rs_pin.direction), (__lcd->rs_pin.logic));
        ret |= gpio_pin_initialize(&(__lcd->en_pin), (__lcd->en_pin.direction), (__lcd->en_pin.logic));
        ret |= gpio_pin_initialize(&(__lcd->data_pin[0]), (__lcd->data_pin[0].direction), (__lcd->data_pin[0].logic));
        ret |= gpio_pin_initialize(&(__lcd->data_pin[1]), (__lcd->data_pin[1].direction), (__lcd->data_pin[1].logic));
        ret |= gpio_pin_initialize(&(__lcd->data_pin[2]), (__lcd->data_pin[2].direction), (__lcd->data_pin[2].logic));
        ret |= gpio_pin_initialize(&(__lcd->data_pin[3]), (__lcd->data_pin[3].direction), (__lcd->data_pin[3].logic));
        ret |= gpio_pin_initialize(&(__lcd->data_pin[4]), (__lcd->data_pin[4].direction), (__lcd->data_pin[4].logic));
        ret |= gpio_pin_initialize(&(__lcd->data_pin[5]), (__lcd->data_pin[5].direction), (__lcd->data_pin[5].logic));
        ret |= gpio_pin_initialize(&(__lcd->data_pin[6]), (__lcd->data_pin[6].direction), (__lcd->data_pin[6].logic));
        ret |= gpio_pin_initialize(&(__lcd->data_pin[7]), (__lcd->data_pin[7].direction), (__lcd->data_pin[7].logic));

        ret |= lcd_8bit_send_command(__lcd, COMMAND_MERGE(LCD_BUS_MODE_8_BIT, COMMAND_MERGE(LCD_DISPLAY_MODE_2_LINE, LCD_DISPLAY_MODE_2_LINE)));
        __delay_ms(20);
        ret |= lcd_8bit_send_command(__lcd, COMMAND_MERGE(LCD_BUS_MODE_8_BIT, COMMAND_MERGE(LCD_DISPLAY_MODE_2_LINE, LCD_DISPLAY_MODE_2_LINE)));
        __delay_ms(5);
        ret |= lcd_8bit_send_command(__lcd, COMMAND_MERGE(LCD_BUS_MODE_8_BIT, COMMAND_MERGE(LCD_DISPLAY_MODE_2_LINE, LCD_DISPLAY_MODE_2_LINE)));
        __delay_us(150);
        ret |= lcd_8bit_send_command(__lcd, LCD_DISPLAY_CLEAR);
        ret |= lcd_8bit_send_command(__lcd, LCD_RETURN_HOME);
        ret |= lcd_8bit_send_command(__lcd, COMMAND_MERGE(LCD_ADDRESS_COUNTER_INCREMENT, LCD_SHIFT_MODE_OFF));
        ret |= lcd_8bit_send_command(__lcd, COMMAND_MERGE(LCD_DISPLAY_ON, COMMAND_MERGE(LCD_UNDERLINE_OFF, LCD_CURSOR_BLINK_OFF)));
        ret |= lcd_8bit_send_command(__lcd, COMMAND_MERGE(LCD_BUS_MODE_8_BIT, COMMAND_MERGE(LCD_DISPLAY_MODE_2_LINE, LCD_DISPLAY_MODE_2_LINE)));
        ret |= lcd_8bit_send_command(__lcd, 0x80);
    }
    return ret;
}

std_returntype lcd_8bit_send_command(lcd_8bit_t *__lcd, uint8_t __command)
{
    std_returntype ret = STD_OK;
    if (NULL == __lcd)
    {
        ret = STD_NOT_OK;
    }
    else
    {
        ret |= gpio_pin_write(&(__lcd->rs_pin), GPIO_LOW);
        ret |= gpio_pin_write(&(__lcd->data_pin[0]), ((__command >> 0) & 0x01));
        ret |= gpio_pin_write(&(__lcd->data_pin[1]), ((__command >> 1) & 0x01));
        ret |= gpio_pin_write(&(__lcd->data_pin[2]), ((__command >> 2) & 0x01));
        ret |= gpio_pin_write(&(__lcd->data_pin[3]), ((__command >> 3) & 0x01));
        ret |= gpio_pin_write(&(__lcd->data_pin[4]), ((__command >> 4) & 0x01));
        ret |= gpio_pin_write(&(__lcd->data_pin[5]), ((__command >> 5) & 0x01));
        ret |= gpio_pin_write(&(__lcd->data_pin[6]), ((__command >> 6) & 0x01));
        ret |= gpio_pin_write(&(__lcd->data_pin[7]), ((__command >> 7) & 0x01));
        ret |= lcd_8bit_send_enable_signal(__lcd);
    }
    return ret;
}

std_returntype lcd_8bit_send_data(lcd_8bit_t *__lcd, uint8_t __data)
{
    std_returntype ret = STD_OK;
    if (NULL == __lcd)
    {
        ret = STD_NOT_OK;
    }
    else
    {
        ret |= gpio_pin_write(&(__lcd->rs_pin), GPIO_HIGH);
        ret |= gpio_pin_write(&(__lcd->data_pin[0]), ((__data >> 0) & 0x01));
        ret |= gpio_pin_write(&(__lcd->data_pin[1]), ((__data >> 1) & 0x01));
        ret |= gpio_pin_write(&(__lcd->data_pin[2]), ((__data >> 2) & 0x01));
        ret |= gpio_pin_write(&(__lcd->data_pin[3]), ((__data >> 3) & 0x01));
        ret |= gpio_pin_write(&(__lcd->data_pin[4]), ((__data >> 4) & 0x01));
        ret |= gpio_pin_write(&(__lcd->data_pin[5]), ((__data >> 5) & 0x01));
        ret |= gpio_pin_write(&(__lcd->data_pin[6]), ((__data >> 6) & 0x01));
        ret |= gpio_pin_write(&(__lcd->data_pin[7]), ((__data >> 7) & 0x01));
        ret |= lcd_8bit_send_enable_signal(__lcd);
    }
    return ret;
}

std_returntype lcd_8bit_send_char(lcd_8bit_t *__lcd, uint8_t __character)
{
    std_returntype ret = STD_OK;
    if (NULL == __lcd)
    {
        ret = STD_NOT_OK;
    }
    else
    {
        ret |= lcd_8bit_send_data(__lcd, __character);
    }
    return ret;
}

std_returntype lcd_8bit_send_char_pos(lcd_8bit_t *__lcd, uint8_t __row, uint8_t __column, uint8_t __character)
{
    std_returntype ret = STD_OK;
    if (NULL == __lcd)
    {
        ret = STD_NOT_OK;
    }
    else
    {
        ret |= lcd_8bit_set_cursor(__lcd, __row, __column);
        ret |= lcd_8bit_send_data(__lcd, __character);
    }
    return ret;
}

std_returntype lcd_8bit_send_string(lcd_8bit_t *__lcd, uint8_t *str)
{
    std_returntype ret = STD_OK;
    if ((NULL == __lcd) || (NULL == str))
    {
        ret = STD_NOT_OK;
    }
    else
    {
        while (*str != '\0')
        {
            ret |= lcd_8bit_send_data(__lcd, *str++);
        }
    }
    return ret;
}

std_returntype lcd_8bit_send_string_pos(lcd_8bit_t *__lcd, uint8_t __row, uint8_t __column, uint8_t *str)
{
    std_returntype ret = STD_OK;
    if ((NULL == __lcd) || (NULL == str))
    {
        ret = STD_NOT_OK;
    }
    else
    {
        ret |= lcd_8bit_set_cursor(__lcd, __row, __column);
        while (*str != '\0')
        {
            ret |= lcd_8bit_send_data(__lcd, *str++);
        }
    }
    return ret;
}

std_returntype lcd_8bit_send_custom_char_pos(lcd_8bit_t *__lcd, uint8_t __row, uint8_t __column, uint8_t __ch[], uint8_t __mem_pos)
{
    std_returntype ret = STD_OK;
    if (NULL == __lcd)
    {
        ret = STD_NOT_OK;
    }
    else
    {
        __mem_pos--;
        ret |= lcd_8bit_send_command(__lcd, (CGRAM_START_ADDRESS + (__mem_pos * 8)));
        ret |= lcd_8bit_send_data(__lcd, __ch[0]);
        ret |= lcd_8bit_send_data(__lcd, __ch[1]);
        ret |= lcd_8bit_send_data(__lcd, __ch[2]);
        ret |= lcd_8bit_send_data(__lcd, __ch[3]);
        ret |= lcd_8bit_send_data(__lcd, __ch[4]);
        ret |= lcd_8bit_send_data(__lcd, __ch[5]);
        ret |= lcd_8bit_send_data(__lcd, __ch[6]);
        ret |= lcd_8bit_send_data(__lcd, __ch[7]);
        ret |= lcd_8bit_send_char_pos(__lcd, __row, __column, __mem_pos);
    }
    return ret;
}

std_returntype lcd_8bit_shift(lcd_8bit_t *__lcd, lcd_display_shift_cfg_t *__shift)
{
    std_returntype ret = STD_OK;
    uint8_t shift_counter = 0;
    uint16_t duration_counter = 0;
    if (NULL == __lcd)
    {
        ret = STD_NOT_OK;
    }
    else
    {
        ret |= lcd_8bit_send_command(__lcd, COMMAND_MERGE(LCD_ADDRESS_COUNTER_INCREMENT, LCD_SHIFT_MODE_ON));
        switch (__shift->mode)
        {
        case AUTO_SHIFT_ON:
            for (shift_counter = 0; 
                 shift_counter <__shift->configurations.auto_shift_off.step; 
                 shift_counter++)
            {
                if (__shift->direction == DISPLAY_SHIFT_LEFT)
                {
                    ret |= lcd_8bit_send_command(__lcd, COMMAND_MERGE(LCD_DISPLAY_SHIFT, LCD_SHIFT_LEFT));
                }
                else
                {
                    ret |= lcd_8bit_send_command(__lcd, COMMAND_MERGE(LCD_DISPLAY_SHIFT, LCD_SHIFT_RIGHT));
                }
                for(duration_counter = 0; duration_counter < __shift->configurations.auto_shift_on.duration; duration_counter++)
                {
                    __delay_ms(1);
                }
            }
            break;

        case AUTO_SHIFT_OFF:
            for (shift_counter = 0; 
                 shift_counter <__shift->configurations.auto_shift_off.step; 
                 shift_counter++)
            {
                if (__shift->direction == DISPLAY_SHIFT_LEFT)
                {
                    ret |= lcd_8bit_send_command(__lcd, COMMAND_MERGE(LCD_DISPLAY_SHIFT, LCD_SHIFT_LEFT));
                }
                else
                {
                    ret |= lcd_8bit_send_command(__lcd, COMMAND_MERGE(LCD_DISPLAY_SHIFT, LCD_SHIFT_RIGHT));
                }
            }
            break;
        default:
            ret = STD_NOT_OK;
            break;
        }
    }
    return ret;
}

std_returntype lcd_48it_behavior(lcd_8bit_t *__lcd, lcd_behavior_t __behavior)
{
    std_returntype ret = STD_OK;
    if (NULL == __lcd)
    {
        ret = STD_NOT_OK;
    }
    else
    {
    std_returntype ret = STD_OK;
    if (NULL == __lcd)
    {
        ret = STD_NOT_OK;
    }
    else
    {
        switch (__behavior)
        {
        case LCD_DISPLAY_CLEAR_BEHAVIOR:
            ret |= lcd_8bit_send_command(__lcd, LCD_DISPLAY_CLEAR);
            break;
        case LCD_DISPLAY_ON_BEHAVIOR:
            ret |= lcd_8bit_send_command(__lcd, LCD_DISPLAY_ON);
            break;
        case LCD_DISPLAY_OFF_BEHAVIOR:
            ret |= lcd_8bit_send_command(__lcd, LCD_DISPLAY_OFF);
            break;
        case LCD_RETURN_HOME_BEHAVIOR:
            ret |= lcd_8bit_send_command(__lcd, LCD_RETURN_HOME);
            break;
        case LCD_NEXT_CHAR_INCREMENT:
            ret |= lcd_8bit_send_command(__lcd, LCD_ADDRESS_COUNTER_INCREMENT);
            break;
        case LCD_NEXT_CHAR_DECREMENT:
            ret |= lcd_8bit_send_command(__lcd, LCD_ADDRESS_COUNTER_DECREMENT);
            break;
        case LCD_SHOW_UNDERLINE_CURSOR:
            ret |= lcd_8bit_send_command(__lcd, COMMAND_MERGE(LCD_DISPLAY_ON, LCD_UNDERLINE_ON));
            break;
        case LCD_HIDE_UNDERLINE_CURSOR:
            ret |= lcd_8bit_send_command(__lcd, COMMAND_MERGE(LCD_DISPLAY_ON, LCD_UNDERLINE_OFF));
            break;
        case LCD_SHOW_CURSOR_BLINK:
            ret |= lcd_8bit_send_command(__lcd, COMMAND_MERGE(LCD_DISPLAY_ON, LCD_CURSOR_BLINK_ON));
            break;
        case LCD_HIDE_CURSOR_BLINK:
            ret |= lcd_8bit_send_command(__lcd,  COMMAND_MERGE(LCD_DISPLAY_ON, LCD_CURSOR_BLINK_OFF));
            break;
        default:
            ret |= STD_NOT_OK;
            break;
        }
    }
    return ret;
    }
    return ret;
}



static std_returntype lcd_send_4bit(lcd_4bit_t *__lcd, uint8_t __bits)
{
    std_returntype ret = STD_OK;
    if (NULL == __lcd)
    {
        ret = STD_NOT_OK;
    }
    else
    {
        ret |= gpio_pin_write(&(__lcd->data_pin[0]), ((__bits >> 0) & 0x01));
        ret |= gpio_pin_write(&(__lcd->data_pin[1]), ((__bits >> 1) & 0x01));
        ret |= gpio_pin_write(&(__lcd->data_pin[2]), ((__bits >> 2) & 0x01));
        ret |= gpio_pin_write(&(__lcd->data_pin[3]), ((__bits >> 3) & 0x01));
    }
    return ret;
}

static std_returntype lcd_4bit_send_enable_signal(lcd_4bit_t *__lcd)
{
    std_returntype ret = STD_OK;
    if (NULL == __lcd)
    {
        ret = STD_NOT_OK;
    }
    else
    {
        ret |= gpio_pin_write(&(__lcd->en_pin), GPIO_HIGH);
        __delay_us(5);
        ret |= gpio_pin_write(&(__lcd->en_pin), GPIO_LOW);
    }
    return ret;
}

static std_returntype lcd_4bit_set_cursor(lcd_4bit_t *__lcd, uint8_t __row, uint8_t __column)
{
    std_returntype ret = STD_OK;
    if (NULL == __lcd)
    {
        ret = STD_NOT_OK;
    }
    else
    {
        __column--;
        switch (__row)
        {
#if (defined LCD_16_1 || defined LCD_16_2 || defined LCD_16_4 || defined LCD_20_2 || defined LCD_20_4 || defined LCD_32_2 || defined LCD_40_2)
        case ROW1:
            ret |= lcd_4bit_send_command(__lcd, (ROW1_ADDRESS + __column));
            break;
#endif

#if (defined LCD_16_2 || defined LCD_16_4 || defined LCD_20_2 || defined LCD_20_4 || defined LCD_32_2 || defined LCD_40_2)
        case ROW2:
            ret |= lcd_4bit_send_command(__lcd, (ROW2_ADDRESS + __column));
            break;
#endif

#if (defined LCD_16_4 || defined LCD_20_4)
        case ROW3:
            ret |= lcd_4bit_send_command(__lcd, (ROW3_ADDRESS + __column));
            break;
#endif

#if (defined LCD_16_4 || defined LCD_20_4)
        case ROW4:
            ret |= lcd_4bit_send_command(__lcd, (ROW4_ADDRESS + __column));
            break;
#endif
        default:
            ret = STD_NOT_OK;
            break;
        }
    }
    return ret;
}

static std_returntype lcd_8bit_send_enable_signal(lcd_8bit_t *__lcd)
{
    std_returntype ret = STD_OK;
    if (NULL == __lcd)
    {
        ret = STD_NOT_OK;
    }
    else
    {
        ret |= gpio_pin_write(&(__lcd->en_pin), GPIO_HIGH);
        __delay_us(5);
        ret |= gpio_pin_write(&(__lcd->en_pin), GPIO_LOW);
    }
    return ret;
}

static std_returntype lcd_8bit_set_cursor(lcd_8bit_t *__lcd, uint8_t __row, uint8_t __column)
{
    std_returntype ret = STD_OK;
    if (NULL == __lcd)
    {
        ret = STD_NOT_OK;
    }
    else
    {
        __column--;
        switch (__row)
        {
#if (defined LCD_16_1 || defined LCD_16_2 || defined LCD_16_4 || defined LCD_20_2 || defined LCD_20_4 || defined LCD_32_2 || defined LCD_40_2)
        case ROW1:
            ret |= lcd_8bit_send_command(__lcd, (ROW1_ADDRESS + __column));
            break;
#endif

#if (defined LCD_16_2 || defined LCD_16_4 || defined LCD_20_2 || defined LCD_20_4 || defined LCD_32_2 || defined LCD_40_2)
        case ROW2:
            ret |= lcd_8bit_send_command(__lcd, (ROW2_ADDRESS + __column));
            break;
#endif

#if (defined LCD_16_4 || defined LCD_20_4)
        case ROW3:
            ret |= lcd_8bit_send_command(__lcd, (ROW3_ADDRESS + __column));
            break;
#endif

#if (defined LCD_16_4 || defined LCD_20_4)
        case ROW4:
            ret |= lcd_8bit_send_command(__lcd, (ROW4_ADDRESS + __column));
            break;
#endif
        default:
            ret = STD_NOT_OK;
            break;
        }
    }
    return ret;
}



std_returntype convert_uint8_to_string(uint8_t value, uint8_t *str)
{
    std_returntype ret = STD_OK;
    if (str == NULL)
    {
        ret = STD_NOT_OK;
    }
    else
    {
        memset(str, '\0', 4);
        sprintf((char *)str, "%i", (int)value);
    }
    return ret;
}

std_returntype convert_uint16_to_string(uint16_t value, uint8_t *str)
{
    std_returntype ret = STD_OK;
    if (str == NULL)
    {
        ret = STD_NOT_OK;
    }
    else
    {
        memset(str, '\0', 6);
        sprintf((char *)str, "%i", (int)value);
    }
    return ret;
}

std_returntype convert_uint32_to_string(uint32_t value, uint8_t *str)
{
    std_returntype ret = STD_OK;
    if (str == NULL)
    {
        ret = STD_NOT_OK;
    }
    else
    {
        memset(str, '\0', 11);
        sprintf((char *)str, "%i", (int)value);;
    }
    return ret;
}


