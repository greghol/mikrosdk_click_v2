/****************************************************************************
** Copyright (C) 2020 MikroElektronika d.o.o.
** Contact: https://www.mikroe.com/contact
**
** Permission is hereby granted, free of charge, to any person obtaining a copy
** of this software and associated documentation files (the "Software"), to deal
** in the Software without restriction, including without limitation the rights
** to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
** copies of the Software, and to permit persons to whom the Software is
** furnished to do so, subject to the following conditions:
** The above copyright notice and this permission notice shall be
** included in all copies or substantial portions of the Software.
**
** THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
** EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
** OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
** IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
** DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT
** OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE
**  USE OR OTHER DEALINGS IN THE SOFTWARE.
****************************************************************************/

/*!
 * @file buttonr.h
 * @brief This file contains API for Button R Click Driver.
 */

#ifndef BUTTONR_H
#define BUTTONR_H

#ifdef __cplusplus
extern "C"{
#endif

#include "drv_digital_out.h"
#include "drv_digital_in.h"
#include "drv_pwm.h"

/*!
 * @addtogroup buttonr Button R Click Driver
 * @brief API for configuring and manipulating Button R Click driver.
 * @{
 */

/**
 * @defgroup buttonr_set Button R PWM Settings
 * @brief Settings for configuration of Button R Click driver.
 */

/**
 * @addtogroup buttonr_cfg
 * @{
 */

/**
 * @brief Button R default PWM frequency.
 * @details Specified setting for setting default PWM frequency of Button R Click driver.
 */
#define BUTTONR_DEF_FREQ     500

/*! @} */ // buttonr_cfg

/**
 * @defgroup buttonr_map Button R MikroBUS Map
 * @brief MikroBUS pin mapping of Button R Click driver.
 */

/**
 * @addtogroup buttonr_map
 * @{
 */

/**
 * @brief MikroBUS pin mapping.
 * @details Mapping pins of Button R Click to the selected MikroBUS.
 */
#define BUTTONR_MAP_MIKROBUS( cfg, mikrobus ) \
    cfg.pwm = MIKROBUS( mikrobus, MIKROBUS_PWM ); \
    cfg.int_pin = MIKROBUS( mikrobus, MIKROBUS_INT )

/*! @} */ // buttonr_map
/*! @} */ // buttonr

/**
 * @brief Button R Click driver selector.
 * @details Selects target driver interface of Button R Click driver.
 */

/**
 * @brief Button R Click context object.
 * @details Context object definition of Button R Click driver.
 */
typedef struct
{
    digital_in_t int_pin;       /**< Interrupt pin. */

    // Modules
    pwm_t pwm;                  /**< PWM driver object. */

    // ctx variable
    uint32_t pwm_freq;          /**< PWM frequency value. */

} buttonr_t;

/**
 * @brief Button R Click configuration object.
 * @details Configuration object definition of Button R Click driver.
 */
typedef struct
{
    // Communication gpio pins
    pin_name_t pwm;          /**< PWM pin. */

    pin_name_t int_pin;      /**< Interrupt pin. */

    // Static variable
    uint32_t dev_pwm_freq;   /**< PWM frequency value. */

} buttonr_cfg_t;

/**
 * @brief Button R Click return value data.
 * @details Predefined enum values for driver return values.
 */
typedef enum
{
   BUTTONR_OK = 0,
   BUTTONR_ERROR = -1

} buttonr_return_value_t;

/*!
 * @addtogroup buttonr Button R Click Driver
 * @brief API for configuring and manipulating Button R Click driver.
 * @{
 */

/**
 * @brief Button R configuration object setup function.
 * @details This function initializes click configuration structure to initial
 * values.
 * @param[out] cfg : Click configuration structure.
 * See #buttonr_cfg_t object definition for detailed explanation.
 * @return Nothing.
 * @note The all used pins will be set to unconnected state.
 */
void buttonr_cfg_setup ( buttonr_cfg_t *cfg );

/**
 * @brief Button R initialization function.
 * @details This function initializes all necessary pins and peripherals used
 * for this click board.
 * @param[out] ctx : Click context object.
 * See #buttonr_t object definition for detailed explanation.
 * @param[in] cfg : Click configuration structure.
 * See #buttonr_cfg_t object definition for detailed explanation.
 * @return @li @c  0 - Success,
 *         @li @c -1 - Error.
 *
 * See #err_t definition for detailed explanation.
 * @note None.
 */
err_t buttonr_init ( buttonr_t *ctx, buttonr_cfg_t *cfg );

/**
 * @brief Button R sets PWM duty cycle.
 * @details This function sets the PWM duty cycle in percentages ( Range[ 0..1 ] ).
 * @param[out] ctx : Click context object.
 * See #buttonr_t object definition for detailed explanation.
 * @param[in] duty_ratio : PWM duty_ratio.
 * @return @li @c  0 - Success,
 *         @li @c -1 - Error.
 *
 * See #err_t definition for detailed explanation.
 * @note None.
 */
err_t buttonr_set_duty_cycle ( buttonr_t *ctx, float duty_cycle );

/**
 * @brief Button R stop PWM module.
 * @details This function stops the PWM moudle output.
 * @param[out] ctx : Click context object.
 * See #buttonr_t object definition for detailed explanation.
 * @return @li @c  0 - Success,
 *         @li @c -1 - Error.
 *
 * See #err_t definition for detailed explanation.
 * @note None.
 */
err_t buttonr_pwm_stop ( buttonr_t *ctx );

/**
 * @brief Button R start PWM module.
 * @details This function starts the PWM moudle output.
 * @param[out] ctx : Click context object.
 * See #buttonr_t object definition for detailed explanation.
 * @return @li @c  0 - Success,
 *         @li @c -1 - Error.
 *
 * See #err_t definition for detailed explanation.
 * @note None.
 */
err_t buttonr_pwm_start ( buttonr_t *ctx );

/**
 * @brief Button R get button state function.
 * @details This function reads the digital signal from the INT pin which tells us whether 
 * the button has been pressed or not.
 * @param[out] ctx : Click context object.
 * See #buttonr_t object definition for detailed explanation.
 * @return Function returns pin logical state (1 or 0).
 *
 * See #err_t definition for detailed explanation.
 * @note None.
 */
uint8_t buttonr_get_button_state ( buttonr_t *ctx );

#ifdef __cplusplus
}
#endif
#endif // BUTTONR_H

/*! @} */ // buttonr

// ------------------------------------------------------------------------ END
