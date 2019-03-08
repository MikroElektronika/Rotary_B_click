/*
    __rotaryb_driver.h

-----------------------------------------------------------------------------

  This file is part of mikroSDK.
  
  Copyright (c) 2017, MikroElektonika - http://www.mikroe.com

  All rights reserved.

----------------------------------------------------------------------------- */

/**
@file   __rotaryb_driver.h
@brief    ROTARY_B Driver
@mainpage ROTARY_B Click
@{

@image html libstock_fb_view.jpg

@}

@defgroup   ROTARYB
@brief      ROTARY_B Click Driver
@{

| Global Library Prefix | **ROTARYB** |
|:---------------------:|:-----------------:|
| Version               | **1.0.0**    |
| Date                  | **Jul 2018.**      |
| Developer             | **Nenad Filipovic**     |

*/
/* -------------------------------------------------------------------------- */

#include "stdint.h"

#ifndef _ROTARYB_H_
#define _ROTARYB_H_

/** 
 * @macro T_ROTARYB_P
 * @brief Driver Abstract type 
 */
#define T_ROTARYB_P    const uint8_t*

/** @defgroup ROTARYB_COMPILE Compilation Config */              /** @{ */

   #define   __ROTARYB_DRV_SPI__                            /**<     @macro __ROTARYB_DRV_SPI__  @brief SPI driver selector */
//  #define   __ROTARYB_DRV_I2C__                            /**<     @macro __ROTARYB_DRV_I2C__  @brief I2C driver selector */                                          
// #define   __ROTARYB_DRV_UART__                           /**<     @macro __ROTARYB_DRV_UART__ @brief UART driver selector */ 

                                                                       /** @} */
/** @defgroup ROTARYB_VAR Variables */                           /** @{ */



                                                                       /** @} */
/** @defgroup ROTARYB_TYPES Types */                             /** @{ */



                                                                       /** @} */
#ifdef __cplusplus
extern "C"{
#endif

/** @defgroup ROTARYB_INIT Driver Initialization */              /** @{ */

#ifdef   __ROTARYB_DRV_SPI__
void rotaryb_spiDriverInit(T_ROTARYB_P gpioObj, T_ROTARYB_P spiObj);
#endif
#ifdef   __ROTARYB_DRV_I2C__
void rotaryb_i2cDriverInit(T_ROTARYB_P gpioObj, T_ROTARYB_P i2cObj, uint8_t slave);
#endif
#ifdef   __ROTARYB_DRV_UART__
void rotaryb_uartDriverInit(T_ROTARYB_P gpioObj, T_ROTARYB_P uartObj);
#endif

                                                                       /** @} */
/** @defgroup ROTARYB_FUNC Driver Functions */                   /** @{ */

/**
 * @brief Generic data write function
 *
 * @param[in] dataToWrite Data to write
 *
 * Function turn on led by data
 */
void rotaryb_turnOnLedByData( uint16_t dataToWrite );

/**
 * @brief Turn on led by position
 *
 * @param[in] ledPosition Led position
 *
 * Function turn on led by position
 */
void rotaryb_turnOnLedByPosition( uint8_t ledPosition );

/**
 * @brief Button push state
 *
 * Function return 1 if button is pushed and return 0 if not
 */
uint8_t rotaryb_buttonPush();

/**
 * @brief Get led data state
 *
 * Function return 16-bit data by current led state
 */
uint16_t rotaryb_getLedData( uint8_t Current_Led_State );

/**
 * @brief Reset led
 *
 * Function turn off all led
 */
void rotaryb_resetLed();

/**
 * @brief State AN pin
 *
 * Function return AN state
 */
uint8_t rotaryb_getANstate();

/**
 * @brief State PWM pin
 *
 * Function return PWM state
 */
uint8_t rotaryb_getPWMstate();





                                                                       /** @} */
#ifdef __cplusplus
} // extern "C"
#endif
#endif

/**
    @example Click_ROTARY_B_STM.c
    @example Click_ROTARY_B_TIVA.c
    @example Click_ROTARY_B_CEC.c
    @example Click_ROTARY_B_KINETIS.c
    @example Click_ROTARY_B_MSP.c
    @example Click_ROTARY_B_PIC.c
    @example Click_ROTARY_B_PIC32.c
    @example Click_ROTARY_B_DSPIC.c
    @example Click_ROTARY_B_AVR.c
    @example Click_ROTARY_B_FT90x.c
    @example Click_ROTARY_B_STM.mbas
    @example Click_ROTARY_B_TIVA.mbas
    @example Click_ROTARY_B_CEC.mbas
    @example Click_ROTARY_B_KINETIS.mbas
    @example Click_ROTARY_B_MSP.mbas
    @example Click_ROTARY_B_PIC.mbas
    @example Click_ROTARY_B_PIC32.mbas
    @example Click_ROTARY_B_DSPIC.mbas
    @example Click_ROTARY_B_AVR.mbas
    @example Click_ROTARY_B_FT90x.mbas
    @example Click_ROTARY_B_STM.mpas
    @example Click_ROTARY_B_TIVA.mpas
    @example Click_ROTARY_B_CEC.mpas
    @example Click_ROTARY_B_KINETIS.mpas
    @example Click_ROTARY_B_MSP.mpas
    @example Click_ROTARY_B_PIC.mpas
    @example Click_ROTARY_B_PIC32.mpas
    @example Click_ROTARY_B_DSPIC.mpas
    @example Click_ROTARY_B_AVR.mpas
    @example Click_ROTARY_B_FT90x.mpas
*/                                                                     /** @} */
/* -------------------------------------------------------------------------- */
/*
  __rotaryb_driver.h

  Copyright (c) 2017, MikroElektonika - http://www.mikroe.com

  All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright
   notice, this list of conditions and the following disclaimer.

2. Redistributions in binary form must reproduce the above copyright
   notice, this list of conditions and the following disclaimer in the
   documentation and/or other materials provided with the distribution.

3. All advertising materials mentioning features or use of this software
   must display the following acknowledgement:
   This product includes software developed by the MikroElektonika.

4. Neither the name of the MikroElektonika nor the
   names of its contributors may be used to endorse or promote products
   derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY MIKROELEKTRONIKA ''AS IS'' AND ANY
EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL MIKROELEKTRONIKA BE LIABLE FOR ANY
DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

----------------------------------------------------------------------------- */