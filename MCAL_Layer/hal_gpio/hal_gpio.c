#include "hal_gpio.h"

volatile uint8_t *tris_reg[] = {&TRISA, &TRISB, &TRISC, &TRISD, &TRISE};
volatile uint8_t *lat_reg[] = {&LATA, &LATB, &LATC, &LATD, &LATE};
volatile uint8_t *port_reg[] = {&PORTA, &PORTB, &PORTC, &PORTD, &PORTE};

/**
 * @brief initialize a pin as input or output
 *
 * @param __pin a pointer to the pin
 * @param __direction desired direction of the pin
 * @return std_returntype
 * @retval (STD_OK)     : if the function run successfully
 * @retval (STD_NOT_OK) : if something goes wrong
 */
std_returntype gpio_pin_direction_initialize(const pin_cofig_t *__pin, gpio_direction_t __direction)
{
    std_returntype ret = STD_OK;
    if ((NULL == __pin) || (__pin->pin >= MAX_PIN))
    {
        ret = STD_NOT_OK;
    }
    else
    {
        switch (__direction)
        {
        case GPIO_OUTPUT:
            CLEAR_BIT(tris_reg[__pin->port], __pin->pin);
            break;

        case GPIO_INPUT:
            SET_BIT(tris_reg[__pin->port], __pin->pin);
            break;

        default:
            ret = STD_NOT_OK;
            break;
        }
    }

    return ret;
}

/**
 * @brief get the status of the pin if it is input or output
 *
 * @param __pin a pointer to the pin
 * @param __direction a pointer to where the status will be stored
 * @return std_returntype
 * @retval (STD_OK)     : if the function run successfully
 * @retval (STD_NOT_OK) : if something goes wrong
 */
std_returntype gpio_pin_direction_status(const pin_cofig_t *__pin, gpio_direction_t *__direction)
{
    std_returntype ret = STD_OK;
    if ((NULL == __pin) || (__pin->pin >= MAX_PIN) || (NULL == __direction))
    {
        ret = STD_NOT_OK;
    }
    else
    {
        *__direction = (gpio_direction_t)READ_BIT(tris_reg[__pin->port], __pin->pin);
    }

    return ret;
}

/**
 * @brief read the logic of the pin
 *
 * @param __pin a pointer to the pin
 * @param __logic a pointer to where the logic will be stored
 * @return std_returntype
 * @retval (STD_OK)     : if the function run successfully
 * @retval (STD_NOT_OK) : if something goes wrong
 */
std_returntype gpio_pin_read(const pin_cofig_t *__pin, gpio_logic_t *__logic)
{
    std_returntype ret = STD_OK;
    if ((NULL == __pin) || (__pin->pin >= MAX_PIN) || (NULL == __logic))
    {
        ret = STD_NOT_OK;
    }
    else
    {
        *__logic = (gpio_logic_t)READ_BIT(port_reg[__pin->port], __pin->pin);
    }

    return ret;
}

/**
 * @brief write a logic on a pin
 *
 * @param __pin a pointer to the pin
 * @param __logic the desired logic to be written
 * @return std_returntype
 * @retval (STD_OK)     : if the function run successfully
 * @retval (STD_NOT_OK) : if something goes wrong
 */
std_returntype gpio_pin_write(const pin_cofig_t *__pin, gpio_logic_t __logic)
{
    std_returntype ret = STD_OK;
    if ((NULL == __pin) || (__pin->pin >= MAX_PIN))
    {
        ret = STD_NOT_OK;
    }
    else
    {
        switch (__logic)
        {
        case GPIO_HIGH:
            SET_BIT(lat_reg[__pin->port], __pin->pin);
            break;

        case GPIO_LOW:
            CLEAR_BIT(lat_reg[__pin->port], __pin->pin);
            break;

        default:
            ret = STD_NOT_OK;
            break;
        }
    }

    return ret;
}

/**
 * @brief toggle a logic of a pin
 *
 * @param __pin a pointer to the pin
 * @return std_returntype
 * @retval (STD_OK)     : if the function run successfully
 * @retval (STD_NOT_OK) : if something goes wrong
 */
std_returntype gpio_pin_toggle(const pin_cofig_t *__pin)
{
    std_returntype ret = STD_OK;
    if ((NULL == __pin) || (__pin->pin >= MAX_PIN))
    {
        ret = STD_NOT_OK;
    }
    else
    {
        TOGGLE_BIT(lat_reg[__pin->port], __pin->pin);
    }

    return ret;
}

/**
 * @brief initialize a pin with direction and logic if it is output
 *
 * @param __pin a pointer to the pin
 * @param __direction the desired direction
 * @param __logic the desired logic to be written if it is output
 * @return std_returntype
 * @retval (STD_OK)     : if the function run successfully
 * @retval (STD_NOT_OK) : if something goes wrong
 */
std_returntype gpio_pin_initialize(const pin_cofig_t *__pin, gpio_direction_t __direction, gpio_logic_t __logic)
{
    std_returntype ret = STD_OK;
    if ((NULL == __pin) || (__pin->pin >= MAX_PIN))
    {
        ret = STD_NOT_OK;
    }
    else
    {
        switch (__direction)
        {
        case GPIO_OUTPUT:
            gpio_pin_direction_initialize(__pin, __direction);
            gpio_pin_write(__pin,__pin->logic);
            break;

        case GPIO_INPUT:
            gpio_pin_direction_initialize(__pin, __direction);
            break;

        default:
            ret = STD_NOT_OK;
            break;
        }
    }

    return ret;
}

/**
 * @brief initialize a port with direction
 *
 * @param __port the index of the port
 * @param __direction the desired direction of the port
 * @return std_returntype
 * @retval (STD_OK)     : if the function run successfully
 * @retval (STD_NOT_OK) : if something goes wrong
 */
std_returntype gpio_port_direction_initialize(const port_index_t __port, uint8_t __direction)
{
    std_returntype ret = STD_OK;
    if (__port >= MAX_PORT)
    {
        ret = STD_NOT_OK;
    }
    else
    {
        HWREG(tris_reg[__port]) = __direction;
    }

    return ret;
}

/**
 * @brief get the direction of the port
 *
 * @param __port the index of the port
 * @param __direction a pointer to where the direction will be stored
 * @return std_returntype
 * @retval (STD_OK)     : if the function run successfully
 * @retval (STD_NOT_OK) : if something goes wrong
 */
std_returntype gpio_port_direction_status(const port_index_t __port, uint8_t *__direction)
{
    std_returntype ret = STD_OK;
    if ((NULL == __direction) || (__port >= MAX_PORT))
    {
        ret = STD_NOT_OK;
    }
    else
    {
        *__direction = HWREG(tris_reg[__port]);
    }

    return ret;
}

/**
 * @brief read the logic of the port
 *
 * @param __port the index of the port
 * @param __logic a pointer to where the logic will be stored
 * @return std_returntype
 * @retval (STD_OK)     : if the function run successfully
 * @retval (STD_NOT_OK) : if something goes wrong
 */
std_returntype gpio_port_read(const port_index_t __port, gpio_logic_t *__logic)
{
    std_returntype ret = STD_OK;
    if ((NULL == __logic) || (__port >= MAX_PORT))
    {
        ret = STD_NOT_OK;
    }
    else
    {
        *__logic = HWREG(port_reg[__port]);
    }

    return ret;
}

/**
 * @brief write a logic on a port
 *
 * @param __port the index of the port
 * @param __logic logic will be written
 * @return std_returntype
 * @retval (STD_OK)     : if the function run successfully
 * @retval (STD_NOT_OK) : if something goes wrong
 */
std_returntype gpio_port_write(const port_index_t __port, gpio_logic_t __logic)
{
    std_returntype ret = STD_OK;
    if (__port >= MAX_PORT)
    {
        ret = STD_NOT_OK;
    }
    else
    {
        HWREG(lat_reg[__port]) = __logic;
    }

    return ret;
}

/**
 * @brief toggle a logic on a port
 *
 * @param __port the index of the port
 * @return std_returntype
 * @retval (STD_OK)     : if the function run successfully
 * @retval (STD_NOT_OK) : if something goes wrong
 */
std_returntype gpio_port_toggle(const port_index_t __port)
{
    std_returntype ret = STD_OK;
    if (__port >= MAX_PORT)
    {
        ret = STD_NOT_OK;
    }
    else
    {
        HWREG(lat_reg[__port]) ^= REG_MASK;
    }

    return ret;
}

/**
 * @brief initialize a port with a direction and a logic of each output pin
 *
 * @param __port the index of the port
 * @param __direction the desired direction
 * @param __logic the desired logic of each output pin
 * @return std_returntype
 * @retval (STD_OK)     : if the function run successfully
 * @retval (STD_NOT_OK) : if something goes wrong
 */
std_returntype gpio_port_initialize(const port_index_t __port, uint8_t __direction, gpio_logic_t __logic)
{
    std_returntype ret = STD_OK;
    if (__port >= MAX_PORT)
    {
        ret = STD_NOT_OK;
    }
    else
    {
        switch (__direction)
        {
        case GPIO_OUTPUT:
            gpio_port_direction_initialize(__port, __direction);
            gpio_port_write(__port, __logic);
            break;

        case GPIO_INPUT:
            gpio_port_direction_initialize(__port, __direction);
            break;

        default:
            ret = STD_NOT_OK;
            break;
        }
    }

    return ret;
}
