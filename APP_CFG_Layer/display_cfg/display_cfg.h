/**
 * @file display_cfg.h
 * @author Ahmed Hani Atef
 * @brief contains the configurations of hardware components 
 * @date 2023-09-18
*/

#ifndef DISPLAY_CFG_H
#define DISPLAY_CFG_H

/****************** Start of Section : includes ********************/
#include "../hardware_cfg/hardware_cfg.h"
#include "../user_cfg/user_cfg.h"
/******************* End of Section : includes *********************/



/************ Start of Section : components declaration ************/


/************* End of Section : components declaration *************/



/************* Start of Section : function declaration *************/

std_returntype display_welcome_message(lcd_4bit_t *__lcd);
std_returntype display_level_message(lcd_4bit_t *__lcd);
std_returntype display_admin_register_message(lcd_4bit_t *__lcd);
std_returntype display_admin_login_required_message(lcd_4bit_t *__lcd);
std_returntype display_user_not_found_message(lcd_4bit_t *__lcd);
std_returntype display_failed_message(lcd_4bit_t *__lcd);
std_returntype display_try_again_after_x_min(lcd_4bit_t *__lcd, uint8_t x);
std_returntype display_mode_3_intro(lcd_4bit_t *__lcd);

std_returntype display_username_input(lcd_4bit_t *__lcd, uint8_t *username);
std_returntype display_password_input(lcd_4bit_t *__lcd, uint8_t *password);
std_returntype display_level_input(lcd_4bit_t *__lcd, uint8_t level);

/************** End of Section : function declaration **************/


#endif