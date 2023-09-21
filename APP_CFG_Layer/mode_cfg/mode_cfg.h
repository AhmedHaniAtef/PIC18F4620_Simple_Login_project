/**
 * @file mode_cfg.h
 * @author Ahmed Hani Atef
 * @brief contains the configurations of hardware components 
 * @date 2023-09-18
*/

#ifndef MODE_CFG_H
#define MODE_CFG_H

/****************** Start of Section : includes ********************/
#include "../hardware_cfg/hardware_cfg.h"
#include "../user_cfg/user_cfg.h"
#include "../display_cfg/display_cfg.h"
/******************* End of Section : includes *********************/


/****************** Start of Section : defines ********************/

#define TOGGLE_MASK (0x01)

/******************* End of Section : defines *********************/


/************ Start of Section : components declaration ************/

extern std_returntype ret ;
extern user_t *users;
extern user_t *current_user;
extern user_search_t status;
extern logic_t btn_status;
extern boolean mode_flag;
extern uint8_t call_flag;

extern void (* mode_ptr)();
extern void (* mode_arr[2])();
/************* End of Section : components declaration *************/



/************* Start of Section : function declaration *************/

void mode_1();
void mode_2();
void mode_3();



/************** End of Section : function declaration **************/



#endif //MODE_CFG_H