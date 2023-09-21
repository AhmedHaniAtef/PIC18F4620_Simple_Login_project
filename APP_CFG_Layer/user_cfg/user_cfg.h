/**
 * @file user_cfg.h
 * @author Ahmed Hani Atef
 * @brief contains the configurations of hardware components 
 * @date 2023-09-18
*/

#ifndef USER_CFG_H
#define USER_CFG_H

/****************** Start of Section : includes ********************/
#include "../hardware_cfg/hardware_cfg.h"
#include "../display_cfg/display_cfg.h"
/******************* End of Section : includes *********************/



/****************** Start of Section : user type *******************/
typedef enum
{
    USER_NOT_FOUND,
    USER_FOUND,
}user_search_t;

typedef enum
{
    ADMIN_NOT_CONFIRM,
    ADMIN_CONFIRM,
}user_admin_t;

typedef enum
{
    ADMIN = '1',
    SUB_ADMIN = '2',
    NORMAL_USER = '3',
}user_level_t;

typedef struct user_structure
{
    uint8_t username[4];
    led_status_t output_leds[4];
    uint8_t *password;
    uint8_t *level;
    struct user_structure *next_user;
}user_t;


/******************* End of Section : user type ********************/



/************* Start of Section : function declaration *************/

std_returntype user_create(user_t **Users);
std_returntype user_search(user_t *Users, user_search_t *status, user_t **find);
std_returntype user_admin_confirm(user_t *Users, user_admin_t *status, user_t **admin);
std_returntype user_remove(user_t *Users, user_t **new_current_user);
std_returntype user_forget_password (user_t *Users);

/************** End of Section : function declaration **************/

#endif //USER_CFG_H

