/**
 * @file hardware_cfg.h
 * @author Ahmed Hani Atef
 * @brief contains the configurations of hardware components 
 * @date 2023-09-18
*/

#ifndef HARDWARE_CFG_H
#define HARDWARE_CFG_H

/****************** Start of Section : includes ********************/
#include "../../ECU_Layer/ecu_lcd/ecu_lcd.h"
#include "../../ECU_Layer/ecu_keypad/ecu_keypad.h"
#include "../../ECU_Layer/ecu_led/ecu_led.h"
#include "../../ECU_Layer/push_btn/push_btn.h"
#include "../../ECU_Layer/ecu_buzzer/ecu_buzzer.h"
/******************* End of Section : includes *********************/



/************ Start of Section : components declaration ************/
extern lcd_4bit_t lcd;
extern keypad_cfg_t keypad;
extern led_config_t leds[4];
extern push_btn_config_t btn;
extern buzzer_config_t buz;

/************* End of Section : components declaration *************/



/************* Start of Section : function declaration *************/
std_returntype hardware_initialize();
/************** End of Section : function declaration **************/


#endif //HARDWARE_CFG_H

