/* 
 * File:   ecu_led.h
 * Author: ahmed
 *
 * Created on September 2, 2023, 4:57 PM
 */

#ifndef ECU_LED_H
#define	ECU_LED_H


/****************** Start of Section : includes ********************/
#include "../../MCAL_Layer/hal_gpio/hal_gpio.h"
/******************* End of Section : includes *********************/

/*************** Start of Section : new data types *****************/

typedef enum
{
    LED_OFF = 0,
    LED_ON,
}led_status_t;


typedef struct 
{
    uint8_t port : 4;
    uint8_t pin : 3;
    uint8_t status : 1; 
}led_config_t;

/****************** End of Section :new data types *****************/



/************ Start of Section : function declaration **************/

std_returntype led_initialize (led_config_t *__led);
std_returntype led_turn_on (led_config_t *__led);
std_returntype led_turn_off (led_config_t *__led);
std_returntype led_turn_toggle (led_config_t *__led);

/************ End of Section :  function declaration ***************/


#endif	/* ECU_LED_H */

