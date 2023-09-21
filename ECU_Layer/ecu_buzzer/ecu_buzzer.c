
#include "ecu_buzzer.h"



std_returntype buzzer_initialize (buzzer_config_t *__buzzer)
{
    std_returntype ret = STD_OK;

    if (NULL == __buzzer)
    {
        ret = STD_NOT_OK;
    }
    else
    {
        pin_cofig_t buzzer = { .port = __buzzer->port,
                            .pin = __buzzer->pin,
                            .direction = GPIO_OUTPUT,
                            .logic = __buzzer->status};
        
        ret = gpio_pin_initialize(&buzzer, GPIO_OUTPUT, __buzzer->status);
    }

    return ret;
}

std_returntype buzzer_turn_on (buzzer_config_t *__buzzer)
{
    std_returntype ret = STD_OK;

    if (NULL == __buzzer)
    {
        ret = STD_NOT_OK;
    }
    else
    {
        pin_cofig_t buzzer = { .port       = __buzzer->port,
                            .pin        = __buzzer->pin,
                            .direction  = GPIO_OUTPUT,
                            .logic      = __buzzer->status};
        
        ret = gpio_pin_write(&buzzer, GPIO_HIGH);
    }

    return ret;
}

std_returntype buzzer_turn_off (buzzer_config_t *__buzzer)
{
    std_returntype ret = STD_OK;

    if (NULL == __buzzer)
    {
        ret = STD_NOT_OK;
    }
    else
    {
        pin_cofig_t buzzer = { .port       = __buzzer->port,
                            .pin        = __buzzer->pin,
                            .direction  = GPIO_OUTPUT,
                            .logic      = __buzzer->status};
        
        ret = gpio_pin_write(&buzzer, GPIO_LOW);
    }

    return ret;
}
