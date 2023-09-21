/**
 * @file mode_cfg.c
 * @author Ahmed Hani Atef
 * @brief contains the configurations of project and modes of the device
 * @date 2023-09-18
*/

/****************** Start of Section : includes ********************/
#include "mode_cfg.h"
/******************* End of Section : includes *********************/



static std_returntype display_mode_2(lcd_4bit_t *__lcd, user_t *current_user);
static std_returntype hardware_toggle_leds(keypad_cfg_t *__keypad, user_t *current_user);
static std_returntype leds_output_handle();
static std_returntype display_all_users(lcd_4bit_t *__leds, user_t *users);

/************ Start of Section : variables declaration ************/

std_returntype ret = STD_OK;
user_t *users = NULL;
user_t *current_user = NULL;
user_search_t status = USER_NOT_FOUND;
logic_t btn_status = GPIO_LOW;
boolean mode_flag = 0;
uint8_t call_flag = 0;

void (* mode_arr[2])() = {&mode_2 , &mode_3};

void (* mode_ptr)() = &mode_2;
/************* End of Section : variables declaration *************/



/************* Start of Section : function definition *************/

void mode_1()
{
    ret |= display_welcome_message(&lcd);
    ret |= user_create(&users);
    current_user = users;
}

void mode_2()
{
    ret |= hardware_toggle_leds(&keypad, current_user);
    ret |= leds_output_handle(leds, current_user);
    ret |= display_mode_2(&lcd, current_user);
    call_flag = 1;
}

void mode_3()
{
    uint8_t option = 0;
    uint8_t keypad_val = 0;
    user_t *l_current_user = NULL;
    user_t *replaced_user = NULL;
    user_search_t status = USER_NOT_FOUND;
    if(call_flag == 0)
    {
        ret |= display_mode_3_intro(&lcd);
        __delay_ms(200);
        ret |= lcd_4bit_behavior(&lcd, LCD_DISPLAY_CLEAR_BEHAVIOR);
        __delay_ms(100);
        ret |= lcd_4bit_send_string_pos(&lcd, 1, 1, (uint8_t *)"Enter option");
        call_flag = 1;
    }

    ret |= keypad_read(&keypad, &keypad_val);
    


    switch (keypad_val)
    {
    case '1':
        __delay_ms(700);
        ret |= lcd_4bit_behavior(&lcd, LCD_DISPLAY_CLEAR_BEHAVIOR);
        ret |= user_search(users, &status, &l_current_user);
        if (status == USER_FOUND)
        {
            current_user = l_current_user;
        }
        else
        {
            ret |= display_user_not_found_message(&lcd);
        }
        mode_flag = 0;
        mode_ptr = mode_arr[mode_flag];
        call_flag = 0;
        break;
    
    case '2':
        __delay_ms(700);
        ret |= lcd_4bit_behavior(&lcd, LCD_DISPLAY_CLEAR_BEHAVIOR);
        ret |= user_create(&users);
        mode_flag = 0;
        mode_ptr = mode_arr[mode_flag];
        call_flag = 0;
        break;

    case '3':
        __delay_ms(700);
        ret |= lcd_4bit_behavior(&lcd, LCD_DISPLAY_CLEAR_BEHAVIOR);
        ret |= user_remove(users, &replaced_user);
        if (replaced_user != NULL)
        {
            current_user = replaced_user;
        }
        mode_flag = 0;
        mode_ptr = mode_arr[mode_flag];
        call_flag = 0;
        break;

    case '4':
        __delay_ms(700);
        ret |= display_all_users(&lcd, users);
        mode_flag = 0;
        mode_ptr = mode_arr[mode_flag];
        call_flag = 0;
        break;

    case '5':
        __delay_ms(700);
        ret |= user_forget_password(users);
        mode_flag = 0;
        mode_ptr = mode_arr[mode_flag];
        call_flag = 0;
        break;
    
    default:
        break;
    }
}


static std_returntype display_mode_2(lcd_4bit_t *__lcd, user_t *current_user)
{
    std_returntype ret = STD_OK;
    uint8_t led_on_counter = 0;
    uint8_t turned_on_leds = 0;
    uint8_t str[4];
    
    if(NULL == __lcd)
    {
        ret = STD_NOT_OK;
    }
    else
    {
        if(call_flag == 0)
        {
            ret |= lcd_4bit_behavior(__lcd, LCD_DISPLAY_CLEAR_BEHAVIOR);
            ret |= lcd_4bit_behavior(__lcd, LCD_RETURN_HOME_BEHAVIOR);

            ret |= lcd_4bit_send_string_pos(__lcd, 1, 1, (uint8_t *)current_user->username);
            ret |= lcd_4bit_send_string_pos(__lcd, 1, 5, (uint8_t *)"Allowed:");
            
            ret |= lcd_4bit_send_string_pos(__lcd, 2, 1, (uint8_t *)"Turned on:");
        }
        
        switch (*(current_user->level))
        {
        case ADMIN:
            ret |= lcd_4bit_send_string_pos(__lcd, 1, 13, (uint8_t *)"4");
            break;
        case SUB_ADMIN:
            ret |= lcd_4bit_send_string_pos(__lcd, 1, 13, (uint8_t *)"3");
            break;
        case NORMAL_USER:
            ret |= lcd_4bit_send_string_pos(__lcd, 1, 13, (uint8_t *)"2");
            break;
        default:
            ret = STD_NOT_OK;
            break;
        }

        for (led_on_counter = 0; led_on_counter < 4; led_on_counter++)
        {
            if (current_user->output_leds[led_on_counter])
            {
                turned_on_leds++;
            }
        }
        ret |= convert_uint8_to_string(turned_on_leds, str);
        ret |= lcd_4bit_send_string_pos(__lcd, 2, 11, (uint8_t *)str);
    }
    return ret;
}

static std_returntype hardware_toggle_leds(keypad_cfg_t *__keypad, user_t *current_user)
{    
    uint8_t keypad_val;
    uint8_t led_on_counter = 0;
    uint8_t turned_on_leds = 0;
    uint8_t condition = 0;

    if((NULL == __keypad) || (NULL == current_user))
    {
        ret = STD_NOT_OK;
    }
    else
    {
        ret |= keypad_read(__keypad, &keypad_val);

        for (led_on_counter = 0; led_on_counter < 4; led_on_counter++)
        {
            if ((current_user->output_leds[led_on_counter]) == 1)
            {
                turned_on_leds++;
            }
        }
        
        switch (*(current_user->level))
        {
            case ADMIN:
            if (turned_on_leds >= 4)
            {
                condition = 0;
            }
            else 
            {
                condition = 1;
            }
            break;
        
        case SUB_ADMIN:
            if (turned_on_leds >= 3)
            {
                condition = 0;
            }
            else 
            {
                condition = 1;
            }
            break;
        
        case NORMAL_USER:
            if (turned_on_leds >= 2)
            {
                condition = 0;
            }
            else 
            {
                condition = 1;
            }
            break;
        default:
            break;
        }

        switch (keypad_val)
        {
        case '1':
            if ((condition) || (current_user->output_leds[0]))
            {   
                ret |= led_turn_toggle(&leds[0]);
                current_user->output_leds[0] ^= TOGGLE_MASK;
                __delay_ms(500);
            }
            else
            {
                ret |= buzzer_turn_on(&buz);
                __delay_ms(1000);
                ret |= buzzer_turn_off(&buz);
            } 
            break;
        
        case '2':
            if ((condition) || (current_user->output_leds[1]))
            {   
                current_user->output_leds[1] ^= TOGGLE_MASK;
                __delay_ms(500);
            }
            else
            {
                ret |= buzzer_turn_on(&buz);
                __delay_ms(1000);
                ret |= buzzer_turn_off(&buz);
            }
            break;

        case '3':
            if ((condition) || (current_user->output_leds[2]))
            {   
                current_user->output_leds[2] ^= TOGGLE_MASK;
                __delay_ms(500);
            }
            else
            {
                ret |= buzzer_turn_on(&buz);
                __delay_ms(1000);
                ret |= buzzer_turn_off(&buz);
            }
            break;

        case '4':
            if ((condition) || (current_user->output_leds[3]))
            {   
                current_user->output_leds[3] ^= TOGGLE_MASK;
                __delay_ms(500);
            }
            else
            {
                ret |= buzzer_turn_on(&buz);
                __delay_ms(1000);
                ret |= buzzer_turn_off(&buz);
            }
            break;

        default:
            ret = STD_NOT_OK;
            break;
        }

    }
    return ret;
}

static std_returntype leds_output_handle(led_config_t *__leds, user_t *current_user)
{;
    uint8_t counter = 0;

    for (counter = 0; counter < 4; counter++)
    {
        if (current_user->output_leds[counter])
        {
            ret |= led_turn_on(&(__leds[counter]));
        }
        else
        {
            ret |= led_turn_off(&(__leds[counter]));
        }
        
    }


    return ret;
}

static std_returntype display_all_users(lcd_4bit_t *__lcd, user_t *users)
{
    std_returntype ret = STD_OK;
    user_t *user_next_counter = NULL;
    uint8_t led_on_counter = 0;
    uint8_t turned_on_leds = 0;
    uint8_t str[4];
    
    if(NULL == __lcd)
    {
        ret = STD_NOT_OK;
    }
    else
    {
        ret |= lcd_4bit_behavior(__lcd, LCD_DISPLAY_CLEAR_BEHAVIOR);
        ret |= lcd_4bit_behavior(__lcd, LCD_RETURN_HOME_BEHAVIOR);

        ret |= lcd_4bit_send_string_pos(__lcd, 1, 1, (uint8_t *)"User|level|leds");
        for (led_on_counter = 0; led_on_counter < 4; led_on_counter++)
        {
            if ((users->output_leds[led_on_counter]) == 1)
            {
                turned_on_leds++;
            }
        }
        ret |= lcd_4bit_send_string_pos(__lcd, 2, 1, (uint8_t *)users->username);
        ret |= lcd_4bit_send_string_pos(__lcd, 2, 5, (uint8_t *)"|");
        ret |= lcd_4bit_send_string_pos(__lcd, 2, 6, (uint8_t *)users->level);
        ret |= lcd_4bit_send_string_pos(__lcd, 2, 11, (uint8_t *)"|");
        ret |= convert_uint8_to_string(turned_on_leds, str);
        ret |= lcd_4bit_send_string_pos(__lcd, 2, 12, (uint8_t *)str);
        __delay_ms(2000);
        ret |= lcd_4bit_send_string_pos(__lcd, 1, 1, (uint8_t *)"               ");
        user_next_counter = users;

        while (user_next_counter->next_user != NULL)
        {
            turned_on_leds = 0;
            for (led_on_counter = 0; led_on_counter < 4; led_on_counter++)
            {
                if ((users->output_leds[led_on_counter]) == 1)
                {
                    turned_on_leds++;
                }
            }
            ret |= lcd_4bit_send_string_pos(__lcd, 1, 1, (uint8_t *)users->username);
            ret |= lcd_4bit_send_string_pos(__lcd, 1, 5, (uint8_t *)"|");
            ret |= lcd_4bit_send_string_pos(__lcd, 1, 6, (uint8_t *)users->level);
            ret |= lcd_4bit_send_string_pos(__lcd, 1, 11, (uint8_t *)"|");
            ret |= convert_uint8_to_string(turned_on_leds, str);
            ret |= lcd_4bit_send_string_pos(__lcd, 1, 12, (uint8_t *)str);

            user_next_counter = users->next_user;

            turned_on_leds = 0;
            for (led_on_counter = 0; led_on_counter < 4; led_on_counter++)
            {
                if ((user_next_counter->output_leds[led_on_counter]) == 1)
                {
                    turned_on_leds++;
                }
            }
            ret |= lcd_4bit_send_string_pos(__lcd, 2, 1, (uint8_t *)user_next_counter->username);
            ret |= lcd_4bit_send_string_pos(__lcd, 2, 5, (uint8_t *)"|");
            ret |= lcd_4bit_send_string_pos(__lcd, 2, 6, (uint8_t *)user_next_counter->level);
            ret |= lcd_4bit_send_string_pos(__lcd, 2, 11, (uint8_t *)"|");
            ret |= convert_uint8_to_string(turned_on_leds, str);
            ret |= lcd_4bit_send_string_pos(__lcd, 2, 12, (uint8_t *)str);

            users = user_next_counter;

            __delay_ms(2000);
        }
    }
    return ret;
}
/************** End of Section : function definition **************/