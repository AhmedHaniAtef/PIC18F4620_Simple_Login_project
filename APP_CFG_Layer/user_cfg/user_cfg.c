/**
 * @file user_cfg.c
 * @author Ahmed Hani Atef
 * @brief contains the creation and removing users 
 * @date 2023-09-18
 */


/****************** Start of Section : includes ********************/
#include "user_cfg.h"
/******************* End of Section : includes *********************/


/************* Start of Section : function declaration *************/

static user_t *create_one_user(uint8_t *UserName, uint8_t *Password, uint8_t *Level);
static uint8_t *get_username(keypad_cfg_t *KeyPad);
static uint8_t *get_password(keypad_cfg_t *KeyPad);
static user_level_t get_level(keypad_cfg_t *KeyPad);

/************** End of Section : function declaration **************/




/************* Start of Section : function definition **************/

std_returntype user_create(user_t **Users)
{
    std_returntype ret = STD_OK;
    uint8_t *l_UserName = NULL;
    uint8_t *l_Password = NULL;
    user_t *temp = NULL;
    user_t *l_users_counter = NULL;
    user_t *l_users_admin = NULL;
    user_admin_t status = ADMIN_NOT_CONFIRM;

    if (NULL == *Users)
    {
        
        ret |= display_admin_register_message(&lcd);
        l_UserName = get_username(&keypad);
        __delay_ms(500);
        l_Password = get_password(&keypad);
        __delay_ms(500);
        user_level_t *l_Level = (user_level_t *)ADMIN;
        temp = create_one_user(l_UserName, l_Password, (uint8_t *)&l_Level);

        *Users = temp;
    }
    else
    {
        l_UserName = get_username(&keypad);
        __delay_ms(500);
        l_Password = get_password(&keypad);
        __delay_ms(500);
        ret |= display_level_message(&lcd);
        user_level_t l_Level = get_level(&keypad);

        __delay_ms(500);

        if (l_Level == ADMIN)
        {
            ret |= display_admin_login_required_message(&lcd);
            ret |= user_admin_confirm(*Users, &status, &l_users_admin);
        }

        

        if ((status == ADMIN_CONFIRM) && (l_Level == ADMIN))
        {
            temp = create_one_user(l_UserName, l_Password, (uint8_t *)&l_Level);
        }
        else if ((status != ADMIN_CONFIRM) && (l_Level == ADMIN))
        {
            ret |= display_failed_message(&lcd);
        }
        else
        {
            temp = create_one_user(l_UserName, l_Password, (uint8_t *)&l_Level);
        }


        l_users_counter = *Users;
        while (l_users_counter->next_user != NULL)
        {
            l_users_counter = l_users_counter->next_user;
        }
        l_users_counter->next_user = temp;
    }
    return ret;
}

std_returntype user_search(user_t *Users, user_search_t *status, user_t **find)
{
    std_returntype ret = STD_OK;

    user_t *l_users_counter = NULL;

    uint8_t *UserName = get_username(&keypad);
    __delay_ms(500);
    uint8_t *Password = get_password(&keypad);
    __delay_ms(500);

    if (NULL == Users)
    {
        *status = USER_NOT_FOUND;
        *find = NULL;
        ret = STD_NOT_OK;
    }
    else
    {
        l_users_counter = Users;
        while (l_users_counter != NULL)
        {
            if ((0 == strcmp((const char *)(l_users_counter->username) , (const char *)UserName)) && (0 == strcmp((const char *)(l_users_counter->password) , (const char *)Password)))
            {
                *status = USER_FOUND;
                *find = l_users_counter;
                break;
            }
            else
            {
                *status = USER_NOT_FOUND;
                *find = NULL;
                l_users_counter = l_users_counter->next_user;
            }  
        }
    }
    return ret;
}

std_returntype user_admin_confirm(user_t *Users, user_admin_t *status, user_t **admin)
{
    std_returntype ret = STD_OK;

    user_t *l_users_counter = NULL;

    uint8_t *UserName =get_username(&keypad);
    __delay_ms(500);
    uint8_t *Password = get_password(&keypad);
    __delay_ms(500);

    if (NULL == Users)
    {
        *status = ADMIN_NOT_CONFIRM;
        ret = STD_NOT_OK;
    }
    else
    {
        l_users_counter = Users;
        while (l_users_counter != NULL)
        {
            if ((0 == strcmp((const char *)(l_users_counter->username) , (const char *)UserName)) && (0 == strcmp((const char *)(l_users_counter->password) , (const char *)Password)))
            {
                if ((0 == strcmp((const char *)(l_users_counter->level) , (const char *)"1")))
                {
                    *status = ADMIN_CONFIRM;
                    *admin = l_users_counter;
                }
                else
                {
                    *status = ADMIN_NOT_CONFIRM;
                    *admin = l_users_counter;
                }
                break;
            }
            else
            {
                *status = ADMIN_NOT_CONFIRM;
                *admin = l_users_counter;
                l_users_counter = l_users_counter->next_user;
            }  
        }
    }
    return ret;
}

std_returntype user_remove(user_t *Users, user_t **new_current_user)
{
    std_returntype ret = STD_OK;
    user_admin_t confirm = ADMIN_NOT_CONFIRM;
    user_t *l_users_counter = NULL;
    user_t *l_users_remove = NULL;
    uint8_t found_flag = 0;
    uint8_t try = 0;
    boolean first_con = 0;
    boolean second_con = 0;
    uint8_t *UserName = get_username(&keypad);
    __delay_ms(500);
    uint8_t *Password = get_password(&keypad);
    __delay_ms(500);

    if (NULL == Users)
    {
        ret = STD_NOT_OK;
    }
    else
    {
        l_users_counter = Users;
        while (l_users_counter->next_user != NULL)
        {
            first_con  = (0 == strcmp((const char *)((l_users_counter->next_user)->username) , (const char *)UserName));
            second_con = (0 == strcmp((const char *)((l_users_counter->next_user)->password) , (const char *)Password));
            if (first_con && second_con)
            { 
                ret |= display_admin_login_required_message(&lcd);
                ret |= user_admin_confirm(Users , &confirm, new_current_user);
                if (confirm)
                {
                    l_users_remove = (l_users_counter->next_user);
                    (l_users_counter->next_user) = (l_users_remove->next_user);
                    (l_users_remove->next_user) = NULL;
                    (l_users_remove->output_leds[0]) = LED_OFF;
                    (l_users_remove->output_leds[1]) = LED_OFF;
                    (l_users_remove->output_leds[2]) = LED_OFF;
                    (l_users_remove->output_leds[3]) = LED_OFF;
                    free(l_users_remove->username);
                    free(l_users_remove->password);
                    (l_users_remove->password) = NULL;
                    free(l_users_remove->level);
                    (l_users_remove->level) = NULL;
                    found_flag = 1;

                    break;
                }
                else
                {
                    try++;
                    if (try >= 4)
                    {
                        ret |= display_failed_message(&lcd);
                        *new_current_user = NULL;
                        break;
                    }
                    else
                    {        
                        ret |= display_try_again_after_x_min(&lcd, try);
                    }   
                }
            }
            else
            {
                l_users_counter = l_users_counter->next_user;
            }  
        }

        if (!found_flag)
        {
            ret |= display_user_not_found_message(&lcd);
        }
    }
    return ret;
}

std_returntype user_forget_password (user_t *Users)
{
    std_returntype ret = STD_OK;
    user_admin_t confirm = ADMIN_NOT_CONFIRM;
    user_t *l_users_counter = NULL;
    user_t **new_current_user = NULL;
    uint8_t try = 0;
    uint8_t found_flag = 0;

    uint8_t *Password = NULL;
    uint8_t *UserName = get_username(&keypad);
    __delay_ms(500);
    
    
    if (NULL == Users)
    {

        ret = STD_NOT_OK;
    }
    else
    {
        l_users_counter = Users;
        while (l_users_counter != NULL)
        {
            if ((0 == strcmp((const char *)(l_users_counter->username) , (const char *)UserName)))
            {   
                ret |= display_admin_login_required_message(&lcd);
                ret |= user_admin_confirm(Users , &confirm, new_current_user);
                if (confirm)
                {
                    free(l_users_counter->password);
                    l_users_counter->password = NULL;
                    Password = get_password(&keypad);
                    __delay_ms(500);
                    l_users_counter->password = Password;
                    found_flag = 1;
                    break;
                }
                else
                {
                    try++;
                    if (try >= 4)
                    {
                        ret |= display_failed_message(&lcd);
                        *new_current_user = NULL;
                        break;
                    }
                    else
                    {        
                        ret |= display_try_again_after_x_min(&lcd, try);
                    }   
                }
            }
            else
            {
                l_users_counter = l_users_counter->next_user;
            }  
        }
    
        if (!found_flag)
        {
            ret |= display_user_not_found_message(&lcd);
        }
    }
    return ret;
}

static uint8_t *get_username(keypad_cfg_t *KeyPad)
{
    std_returntype ret = STD_OK;

    uint8_t *UserName = (uint8_t *)calloc(4, sizeof(uint8_t));
    uint8_t KeyPad_val = '\0';
    uint8_t counter = 0;

    ret |= lcd_4bit_behavior(&lcd, LCD_DISPLAY_CLEAR_BEHAVIOR);
    ret |= lcd_4bit_send_string_pos(&lcd, 1, 1, (uint8_t *)"Enter ID:");
    do
    {
        ret |= keypad_read(KeyPad , &KeyPad_val);
        
        if ((KeyPad_val != '\0') && (KeyPad_val != '=') && (KeyPad_val != 'C') && (counter < 3))
        { 
           UserName[counter] = KeyPad_val;
           counter++;
           UserName[counter] = '\0';
           KeyPad_val = '\0';
           __delay_ms(500);
        }
        else if(KeyPad_val == 'C')
        {
            uint8_t temp_counter = 0;
            for (temp_counter = 0; temp_counter<4; temp_counter++)
            {
                UserName[temp_counter] = '\0';
                ret |= lcd_4bit_send_string_pos(&lcd , 2, temp_counter+1 , (uint8_t *)" ");
            }
            counter = 0;
        }
        ret |= lcd_4bit_send_string_pos(&lcd , 2, 1, UserName);
    } while ((KeyPad_val != '=') && (counter <= 3));
    UserName[counter] = '\0';
    ret |= lcd_4bit_send_string_pos(&lcd , 2, 1, UserName);
    KeyPad_val = '\0';
    return UserName;
}

static uint8_t *get_password(keypad_cfg_t *KeyPad)
{
    std_returntype ret = STD_OK;

    uint8_t *Password = NULL;
    uint8_t KeyPad_val = '\0';
    uint8_t counter = 0;

    Password = (uint8_t *)calloc(counter + 1, sizeof(uint8_t));

    ret |= lcd_4bit_behavior(&lcd, LCD_DISPLAY_CLEAR_BEHAVIOR);
    ret |= lcd_4bit_send_string_pos(&lcd, 1, 1, (uint8_t *)"Enter Password:");
    do
    {
        
        ret |= keypad_read(KeyPad , &KeyPad_val);
        
        if ((KeyPad_val != '\0') && (KeyPad_val != '=') && (KeyPad_val != 'C'))
        { 
            counter++;
            Password = (uint8_t *)realloc(Password, (counter + 1) * sizeof(uint8_t));
            Password[counter-1] = KeyPad_val;
            Password[counter] = '\0';
            KeyPad_val = '\0';
            ret |= lcd_4bit_send_string_pos(&lcd , 2, counter + 1, (uint8_t *)"*");
            __delay_ms(500);
        }
        else if(KeyPad_val == 'C')
        {
            uint8_t temp_counter = 0;
            for (temp_counter = 0; temp_counter< counter+1 ; temp_counter++)
            {
                Password[temp_counter] = '\0';
                ret |= lcd_4bit_send_string_pos(&lcd , 2, temp_counter+1 ,(uint8_t *)" ");
            }
            counter = 0;
        }
    } while ((KeyPad_val != '='));

    Password[counter] = '\0';
    KeyPad_val = '\0';
    return Password;
}

static user_level_t get_level(keypad_cfg_t *KeyPad)
{
    std_returntype ret = STD_OK;
    user_level_t Level[2];
    uint8_t KeyPad_val = '\0';

    ret |= lcd_4bit_behavior(&lcd, LCD_DISPLAY_CLEAR_BEHAVIOR);
    ret |= lcd_4bit_send_string_pos(&lcd, 1, 1, (uint8_t *)"Enter Level:");
    do
    {
        ret |= lcd_4bit_send_string_pos(&lcd , 2, 1, (uint8_t *)Level);
        ret |= keypad_read(KeyPad , &KeyPad_val);
        
        if ((KeyPad_val != '\0') && (KeyPad_val != '='))
        { 
            switch (KeyPad_val)
            {
            case '1':
                *Level = ADMIN;
                break;
            case '2':
                *Level = SUB_ADMIN;
                break;
            case '3':
                *Level = NORMAL_USER;
                break;
            default:
                break;
            }
            KeyPad_val = '\0';
            __delay_ms(500);
        }
    } while ((KeyPad_val != '='));
    *(Level + 1) = '\0';
    ret |= lcd_4bit_send_string_pos(&lcd , 2, 1, (uint8_t *)Level);
    KeyPad_val = '\0';
    return *Level;
}

static user_t *create_one_user(uint8_t *UserName, uint8_t *Password, uint8_t *Level)
{
    user_t *User = NULL;

    User = (user_t *)calloc (1, sizeof(user_t));
    memcpy((User->username), (const char *)UserName,4);
    User->password = (uint8_t *)calloc(strlen((const char *)Password), sizeof(uint8_t));
    strcpy((char *)(User->password), (const char *)Password);
    User->level = (uint8_t *)calloc(2, sizeof(uint8_t));
    *((User->level) + 0) = *(Level + 0);
    User->next_user = NULL;
    User->output_leds[0] = LED_OFF;
    User->output_leds[1] = LED_OFF;
    User->output_leds[2] = LED_OFF;
    User->output_leds[3] = LED_OFF;

    return User;
}
/************** End of Section : function definition ***************/






