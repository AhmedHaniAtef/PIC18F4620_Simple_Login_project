/*
 * File:   application.c
 * Author: Ahmed Hani Atef
 *
 * Created on September 17, 2023, 11:36 PM
 */


#include "application.h"


void main(void) {
    
    ret |= hardware_initialize();
    mode_1();
    
    
    while (1)
    {
        ret |= push_btn_read(&btn, &btn_status);
        if (btn_status)
        {
            mode_flag ^= TOGGLE_MASK;
            mode_ptr = mode_arr[mode_flag];
            call_flag = 0;
        }
        
        mode_ptr();
    }
    return;
}
