
#include "ecu_led.h"



std_returntype led_initialize (led_config_t *__led)
{
    std_returntype ret = STD_OK;

    if (NULL == __led)
    {
        ret = STD_NOT_OK;
    }
    else
    {
        pin_cofig_t led = { .port = __led->port,
                            .pin = __led->pin,
                            .direction = GPIO_OUTPUT,
                            .logic = __led->status};
        
        ret = gpio_pin_initialize(&led, GPIO_OUTPUT, __led->status);
    }

    return ret;
}

std_returntype led_turn_on (led_config_t *__led)
{
    std_returntype ret = STD_OK;

    if (NULL == __led)
    {
        ret = STD_NOT_OK;
    }
    else
    {
        pin_cofig_t led = { .port       = __led->port,
                            .pin        = __led->pin,
                            .direction  = GPIO_OUTPUT,
                            .logic      = __led->status};
        
        ret = gpio_pin_write(&led, GPIO_HIGH);
    }

    return ret;
}

std_returntype led_turn_off (led_config_t *__led)
{
    std_returntype ret = STD_OK;

    if (NULL == __led)
    {
        ret = STD_NOT_OK;
    }
    else
    {
        pin_cofig_t led = { .port       = __led->port,
                            .pin        = __led->pin,
                            .direction  = GPIO_OUTPUT,
                            .logic      = __led->status};
        
        ret = gpio_pin_write(&led, GPIO_LOW);
    }

    return ret;
}

std_returntype led_turn_toggle (led_config_t *__led)
{
    std_returntype ret = STD_OK;

    if (NULL == __led)
    {
        ret = STD_NOT_OK;
    }
    else
    {
        pin_cofig_t led = { .port       = __led->port,
                            .pin        = __led->pin,
                            .direction  = GPIO_OUTPUT,
                            .logic      = __led->status};
        
        ret = gpio_pin_toggle(&led);
    }

    return ret;
}

