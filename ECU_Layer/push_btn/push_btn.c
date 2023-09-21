#include "push_btn.h"

std_returntype push_btn_initialize (push_btn_config_t *__btn)
{
    std_returntype ret = STD_OK;
    if (NULL == __btn)
    {
        ret = STD_NOT_OK;
    }
    else 
    {
        pin_cofig_t btn = { .port       = __btn->port,
                            .pin        = __btn->pin,
                            .direction  = GPIO_INPUT,
                            .logic      = GPIO_LOW};

        ret = gpio_pin_direction_initialize(&btn, GPIO_INPUT);
    }

    return ret;
}

std_returntype push_btn_read (push_btn_config_t *__btn, logic_t *__status)
{
    std_returntype ret = STD_OK;
    if ((NULL == __btn) || (NULL == __status))
    {
        ret = STD_NOT_OK;
    }
    else 
    {
        pin_cofig_t btn = { .port       = __btn->port,
                            .pin        = __btn->pin,
                            .direction  = GPIO_INPUT,
                            .logic      = GPIO_LOW};
        ret = gpio_pin_read(&btn, __status);

        logic_t __real_status = GPIO_LOW;
        do 
        {
            ret |= gpio_pin_read(&btn, __status);
            if (*__status)
            {
                __real_status = GPIO_HIGH;
            }
        }while (*__status);

        *__status = __real_status;
    }

    return ret;
}

