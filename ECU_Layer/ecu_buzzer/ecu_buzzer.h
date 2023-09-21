/* 
 * File:   ecu_buzzer.h
 * Author: ahmed
 *
 * Created on September 2, 2023, 4:57 PM
 */

#ifndef ECU_BUZZER_H
#define	ECU_BUZZER_H


/****************** Start of Section : includes ********************/
#include "../../MCAL_Layer/hal_gpio/hal_gpio.h"
/******************* End of Section : includes *********************/

/*************** Start of Section : new data types *****************/

typedef enum
{
    BUZZER_OFF = 0,
    BUZZER_ON,
}buzzer_status_t;


typedef struct 
{
    uint8_t port : 4;
    uint8_t pin : 3;
    uint8_t status : 1; 
}buzzer_config_t;

/****************** End of Section :new data types *****************/



/************ Start of Section : function declaration **************/

std_returntype buzzer_initialize (buzzer_config_t *__buzzer);
std_returntype buzzer_turn_on (buzzer_config_t *__buzzer);
std_returntype buzzer_turn_off (buzzer_config_t *__buzzer);

/************ End of Section :  function declaration ***************/


#endif	/* ECU_BUZZER_H */

