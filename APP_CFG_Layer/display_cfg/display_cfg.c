/**
 * @file display_cfg.c
 * @author Ahmed Hani Atef
 * @brief contains all displays which will be shown on __lcd
 * @date 2023-09-18
 */


/****************** Start of Section : includes ********************/
#include "display_cfg.h"
/******************* End of Section : includes *********************/


/************* Start of Section : function declaration *************/


/************** End of Section : function declaration **************/




/************* Start of Section : function definition **************/
std_returntype display_welcome_message(lcd_4bit_t *__lcd)
{
    std_returntype ret = STD_OK;
    uint8_t counter = 0;
    if(NULL == __lcd)
    {
        ret = STD_NOT_OK;
    }
    else
    {
        ret |= lcd_4bit_behavior(__lcd, LCD_DISPLAY_CLEAR_BEHAVIOR);
        ret |= lcd_4bit_behavior(__lcd, LCD_RETURN_HOME_BEHAVIOR);
        ret |= lcd_4bit_send_string_pos(__lcd, 1, 6, (uint8_t *)"WELCOME");
        __delay_ms(3000);
        ret |= lcd_4bit_behavior(__lcd, LCD_DISPLAY_CLEAR_BEHAVIOR);
        ret |= lcd_4bit_send_string_pos(__lcd, 1, 1,  (uint8_t *)"Loading");
        for ( counter = 8; counter < 12; counter++)
        {
            ret |= lcd_4bit_send_string_pos(__lcd, 1, counter,  (uint8_t *)".");
            __delay_ms(500);
        }
        ret |= lcd_4bit_send_string_pos(__lcd, 1, 8, (uint8_t *)"     ");
        for ( counter = 8; counter < 12; counter++)
        {
            ret |= lcd_4bit_send_string_pos(__lcd, 1, counter,  (uint8_t *)".");
            __delay_ms(500);
        }
        ret |= lcd_4bit_send_string_pos(__lcd, 1, 8,(uint8_t *) "     ");
        for ( counter = 8; counter < 12; counter++)
        {
            ret |= lcd_4bit_send_string_pos(__lcd, 1, counter,  (uint8_t *)".");
            __delay_ms(500);
        }
        ret |= lcd_4bit_send_string_pos(__lcd, 1, 8, (uint8_t *)"     ");
        for ( counter = 8; counter < 12; counter++)
        {
            ret |= lcd_4bit_send_string_pos(__lcd, 1, counter,  (uint8_t *)".");
            __delay_ms(500);
        }
        ret |= lcd_4bit_behavior(__lcd, LCD_DISPLAY_CLEAR_BEHAVIOR);
    }
    return ret;
}

std_returntype display_level_message(lcd_4bit_t *__lcd)
{
    std_returntype ret = STD_OK;
    
    if(NULL == __lcd)
    {
        ret = STD_NOT_OK;
    }
    else
    {
        lcd_display_shift_cfg_t shift ={
            .configurations.auto_shift_on.duration = 400,
            .configurations.auto_shift_on.step = 4,
            .direction = DISPLAY_SHIFT_LEFT,
            .mode = AUTO_SHIFT_ON
        };
        ret |= lcd_4bit_behavior(__lcd, LCD_DISPLAY_CLEAR_BEHAVIOR);
        ret |= lcd_4bit_behavior(__lcd, LCD_RETURN_HOME_BEHAVIOR);
        ret |= lcd_4bit_send_string_pos(__lcd, 1, 4, (uint8_t *)"Levels Of");
        ret |= lcd_4bit_send_string_pos(__lcd, 2, 2, (uint8_t *)"Accessbility");
        __delay_ms(3000);
        ret |= lcd_4bit_behavior(__lcd, LCD_DISPLAY_CLEAR_BEHAVIOR);
        ret |= lcd_4bit_behavior(__lcd, LCD_RETURN_HOME_BEHAVIOR);
        ret |= lcd_4bit_send_string_pos(__lcd, 1, 1, (uint8_t *)"1-Admin 2-Sub Admin");
        ret |= lcd_4bit_send_string_pos(__lcd, 2, 1, (uint8_t *)"3-Normal User");
        __delay_ms(2000);
        ret |= lcd_4bit_shift(__lcd, &shift);
        shift.direction = DISPLAY_SHIFT_RIGHT;
        ret |= lcd_4bit_shift(__lcd, &shift);
        shift.direction = DISPLAY_SHIFT_LEFT;
        ret |= lcd_4bit_shift(__lcd, &shift);
        shift.direction = DISPLAY_SHIFT_RIGHT;
        ret |= lcd_4bit_shift(__lcd, &shift);
        __delay_ms(2000);
        ret |= lcd_4bit_send_command(__lcd, COMMAND_MERGE(LCD_ADDRESS_COUNTER_INCREMENT, LCD_SHIFT_MODE_OFF));
        ret |= lcd_4bit_behavior(__lcd, LCD_DISPLAY_CLEAR_BEHAVIOR);
        ret |= lcd_4bit_behavior(__lcd, LCD_RETURN_HOME_BEHAVIOR);
    }
    return ret;
}

std_returntype display_admin_register_message(lcd_4bit_t *__lcd)
{
    std_returntype ret = STD_OK;
    
    if(NULL == __lcd)
    {
        ret = STD_NOT_OK;
    }
    else
    {
        ret |= lcd_4bit_behavior(__lcd, LCD_DISPLAY_CLEAR_BEHAVIOR);
        ret |= lcd_4bit_behavior(__lcd, LCD_RETURN_HOME_BEHAVIOR);
        __delay_ms(500);
        ret |= lcd_4bit_send_string_pos(__lcd, 1, 4, (uint8_t *)"WARNING");
        __delay_ms(500);
        ret |= lcd_4bit_behavior(__lcd, LCD_DISPLAY_CLEAR_BEHAVIOR);
        __delay_ms(500);
        ret |= lcd_4bit_send_string_pos(__lcd, 1, 4, (uint8_t *)"WARNING");
        __delay_ms(500);
        ret |= lcd_4bit_behavior(__lcd, LCD_DISPLAY_CLEAR_BEHAVIOR);
        __delay_ms(500);
        ret |= lcd_4bit_send_string_pos(__lcd, 1, 4, (uint8_t *)"WARNING");
        __delay_ms(500);
        ret |= lcd_4bit_behavior(__lcd, LCD_DISPLAY_CLEAR_BEHAVIOR);
        
        ret |= lcd_4bit_send_string_pos(__lcd, 1, 1, (uint8_t *)"This user will");
        ret |= lcd_4bit_send_string_pos(__lcd, 2, 1, (uint8_t *)"be admin.");
        __delay_ms(3000);
        ret |= lcd_4bit_behavior(__lcd, LCD_DISPLAY_CLEAR_BEHAVIOR);
        ret |= lcd_4bit_behavior(__lcd, LCD_RETURN_HOME_BEHAVIOR);
    }
    return ret;
}

std_returntype display_user_not_found_message(lcd_4bit_t *__lcd)
{
    std_returntype ret = STD_OK;
    
    if(NULL == __lcd)
    {
        ret = STD_NOT_OK;
    }
    else
    {
        ret |= lcd_4bit_behavior(__lcd, LCD_DISPLAY_CLEAR_BEHAVIOR);
        ret |= lcd_4bit_behavior(__lcd, LCD_RETURN_HOME_BEHAVIOR);
        ret |= lcd_4bit_send_string_pos(__lcd, 1, 1, (uint8_t *)"User Not Found");
        __delay_ms(3000);
        ret |= lcd_4bit_behavior(__lcd, LCD_DISPLAY_CLEAR_BEHAVIOR);
        ret |= lcd_4bit_behavior(__lcd, LCD_RETURN_HOME_BEHAVIOR);
    }
    return ret;
}

std_returntype display_failed_message(lcd_4bit_t *__lcd)
{
    std_returntype ret = STD_OK;
    
    if(NULL == __lcd)
    {
        ret = STD_NOT_OK;
    }
    else
    {
        ret |= lcd_4bit_behavior(__lcd, LCD_DISPLAY_CLEAR_BEHAVIOR);
        ret |= lcd_4bit_behavior(__lcd, LCD_RETURN_HOME_BEHAVIOR);
        ret |= lcd_4bit_send_string_pos(__lcd, 1, 1, (uint8_t *)"Failed!!");
        __delay_ms(3000);
        ret |= lcd_4bit_behavior(__lcd, LCD_DISPLAY_CLEAR_BEHAVIOR);
        ret |= lcd_4bit_behavior(__lcd, LCD_RETURN_HOME_BEHAVIOR);
    }
    return ret;
}

std_returntype display_try_again_after_x_min(lcd_4bit_t *__lcd, uint8_t x)
{
    std_returntype ret = STD_OK;
    sint8_t min = 0;
    sint8_t sec = 0;
    uint8_t str[4];

    if(NULL == __lcd)
    {
        ret = STD_NOT_OK;
    }
    else
    {
        ret |= lcd_4bit_behavior(__lcd, LCD_DISPLAY_CLEAR_BEHAVIOR);
        ret |= lcd_4bit_behavior(__lcd, LCD_RETURN_HOME_BEHAVIOR);
        ret |= lcd_4bit_send_string_pos(__lcd, 1, 1, (uint8_t *)"Try again");
        ret |= lcd_4bit_send_string_pos(__lcd, 2, 1, (uint8_t *)"after :");
        ret |= convert_uint8_to_string((uint8_t)x , str);
        ret |= lcd_4bit_send_string_pos(__lcd, 2, 8, (uint8_t *)str);
        ret |= lcd_4bit_send_string_pos(__lcd, 2, 10, (uint8_t *)":00");

        ret |= buzzer_turn_on(&buz);
    
        __delay_ms(1000);
        
        for (min = (sint8_t)(x-1); min >= 0; min--)
        {
            ret |= lcd_4bit_send_string_pos(__lcd, 2, 8, (uint8_t *)"        ");
            ret |= convert_uint8_to_string((uint8_t)min , str);
            ret |= lcd_4bit_send_string_pos(__lcd, 2, 8, (uint8_t *)str);

            for (sec = 59; sec >= 0; sec--)
            {
                if(sec == 56)
                {
                    ret |= buzzer_turn_off(&buz);
                }
                ret |= convert_uint8_to_string((uint8_t)sec , str);
                ret |= lcd_4bit_send_string_pos(__lcd, 2, 10, (uint8_t *)":");
                ret |= lcd_4bit_send_string_pos(__lcd, 2, 11, (uint8_t *)"        ");
                ret |= lcd_4bit_send_string_pos(__lcd, 2, 11, (uint8_t *)str);
                __delay_ms(1000);
            }
        }
    }
    return ret;
}

std_returntype display_admin_login_required_message(lcd_4bit_t *__lcd)
{
    std_returntype ret = STD_OK;
    uint8_t counter = 0;
    if(NULL == __lcd)
    {
        ret = STD_NOT_OK;
    }
    else
    {
        ret |= lcd_4bit_behavior(__lcd, LCD_DISPLAY_CLEAR_BEHAVIOR);
        ret |= lcd_4bit_behavior(__lcd, LCD_RETURN_HOME_BEHAVIOR);
        
        ret |= lcd_4bit_send_string_pos(__lcd, 1, 1, (uint8_t *)"Admin must log");
        ret |= lcd_4bit_send_string_pos(__lcd, 2, 1, (uint8_t *)"in to complete");
        __delay_ms(3000);
        ret |= lcd_4bit_behavior(__lcd, LCD_DISPLAY_CLEAR_BEHAVIOR);
        ret |= lcd_4bit_behavior(__lcd, LCD_RETURN_HOME_BEHAVIOR);
    }
    return ret;
}

std_returntype display_mode_3_intro(lcd_4bit_t *__lcd)
{
    std_returntype ret = STD_OK;
    if(NULL == __lcd)
    {
        ret = STD_NOT_OK;
    }
    else
    {
        ret |= lcd_4bit_behavior(__lcd, LCD_DISPLAY_CLEAR_BEHAVIOR);
        ret |= lcd_4bit_behavior(__lcd, LCD_RETURN_HOME_BEHAVIOR);

        ret |= lcd_4bit_send_string_pos(__lcd, 1, 1, (uint8_t *)"Choose an ");
        ret |= lcd_4bit_send_string_pos(__lcd, 2, 1, (uint8_t *)"option");
        __delay_ms(3000);

        ret |= lcd_4bit_behavior(__lcd, LCD_DISPLAY_CLEAR_BEHAVIOR);
        ret |= lcd_4bit_behavior(__lcd, LCD_RETURN_HOME_BEHAVIOR);

        ret |= lcd_4bit_send_string_pos(__lcd, 1, 1, (uint8_t *)"1-Sign in      ");
        ret |= lcd_4bit_send_string_pos(__lcd, 2, 1, (uint8_t *)"2-Add user     ");
        __delay_ms(1000);

        ret |= lcd_4bit_send_string_pos(__lcd, 1, 1, (uint8_t *)"2-Add user     ");
        ret |= lcd_4bit_send_string_pos(__lcd, 2, 1, (uint8_t *)"3-Remove user  ");
        __delay_ms(1000);

        ret |= lcd_4bit_send_string_pos(__lcd, 1, 1, (uint8_t *)"3-Remove user  ");
        ret |= lcd_4bit_send_string_pos(__lcd, 2, 1, (uint8_t *)"4-Show users   ");
        __delay_ms(1000);

        ret |= lcd_4bit_send_string_pos(__lcd, 1, 1, (uint8_t *)"4-Show users   ");
        ret |= lcd_4bit_send_string_pos(__lcd, 2, 1, (uint8_t *)"5-Forget pass");
        __delay_ms(1000);

        ret |= lcd_4bit_send_string_pos(__lcd, 1, 1, (uint8_t *)"3-Remove user  ");
        ret |= lcd_4bit_send_string_pos(__lcd, 2, 1, (uint8_t *)"4-Show users   ");
        __delay_ms(1000);

        ret |= lcd_4bit_send_string_pos(__lcd, 1, 1, (uint8_t *)"2-Add user     ");
        ret |= lcd_4bit_send_string_pos(__lcd, 2, 1, (uint8_t *)"3-Remove user  ");
        __delay_ms(1000);

        ret |= lcd_4bit_send_string_pos(__lcd, 1, 1, (uint8_t *)"1-Sign in      ");
        ret |= lcd_4bit_send_string_pos(__lcd, 2, 1, (uint8_t *)"2-Add user     ");
        __delay_ms(1000);

        ret |= lcd_4bit_send_string_pos(__lcd, 1, 1, (uint8_t *)"2-Add user     ");
        ret |= lcd_4bit_send_string_pos(__lcd, 2, 1, (uint8_t *)"3-Remove user  ");
        __delay_ms(1000);

        ret |= lcd_4bit_send_string_pos(__lcd, 1, 1, (uint8_t *)"3-Remove user  ");
        ret |= lcd_4bit_send_string_pos(__lcd, 2, 1, (uint8_t *)"4-Show users   ");
        __delay_ms(1000);

        ret |= lcd_4bit_send_string_pos(__lcd, 1, 1, (uint8_t *)"4-Show users   ");
        ret |= lcd_4bit_send_string_pos(__lcd, 2, 1, (uint8_t *)"5-Forget pass");
        __delay_ms(1000);

        ret |= lcd_4bit_behavior(__lcd, LCD_DISPLAY_CLEAR_BEHAVIOR);
        ret |= lcd_4bit_behavior(__lcd, LCD_RETURN_HOME_BEHAVIOR);
        
        

    }
    return ret;
}

/************** End of Section : function definition ***************/




