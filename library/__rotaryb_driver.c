/*
    __rotaryb_driver.c

-----------------------------------------------------------------------------

  This file is part of mikroSDK.

  Copyright (c) 2017, MikroElektonika - http://www.mikroe.com

  All rights reserved.

----------------------------------------------------------------------------- */

#include "__rotaryb_driver.h"
#include "__rotaryb_hal.c"

/* ------------------------------------------------------------------- MACROS */



/* ---------------------------------------------------------------- VARIABLES */

#ifdef   __ROTARYB_DRV_I2C__
static uint8_t _slaveAddress;
#endif

/* -------------------------------------------- PRIVATE FUNCTION DECLARATIONS */



/* --------------------------------------------- PRIVATE FUNCTION DEFINITIONS */



/* --------------------------------------------------------- PUBLIC FUNCTIONS */

#ifdef   __ROTARYB_DRV_SPI__

void rotaryb_spiDriverInit(T_ROTARYB_P gpioObj, T_ROTARYB_P spiObj)
{
    hal_spiMap( (T_HAL_P)spiObj );
    hal_gpioMap( (T_HAL_P)gpioObj );

    hal_gpio_csSet(0);
    hal_gpio_rstSet(1);
}

#endif
#ifdef   __ROTARYB_DRV_I2C__

void rotaryb_i2cDriverInit(T_ROTARYB_P gpioObj, T_ROTARYB_P i2cObj, uint8_t slave)
{
    _slaveAddress = slave;
    hal_i2cMap( (T_HAL_P)i2cObj );
    hal_gpioMap( (T_HAL_P)gpioObj );

    // ... power ON
    // ... configure CHIP
}

#endif
#ifdef   __ROTARYB_DRV_UART__

void rotaryb_uartDriverInit(T_ROTARYB_P gpioObj, T_ROTARYB_P uartObj)
{
    hal_uartMap( (T_HAL_P)uartObj );
    hal_gpioMap( (T_HAL_P)gpioObj );

    // ... power ON
    // ... configure CHIP
}

#endif


/* ----------------------------------------------------------- IMPLEMENTATION */

/* Generic data write function */
void rotaryb_turnOnLedByData( uint16_t dataToWrite )
{
    uint8_t temp_buffer[ 2 ];
    temp_buffer[ 0 ] = dataToWrite;
    temp_buffer[ 1 ] = dataToWrite >> 8;

    hal_gpio_csSet( 0 );
    hal_spiWrite( temp_buffer, 2 );
    Delay_10us();
    hal_gpio_csSet( 1 );
}

/* Generic data write function by led position */
void rotaryb_turnOnLedByPosition( uint8_t ledPosition )
{
    rotaryb_turnOnLedByData( 1 << ledPosition );
}

/* Button push state */
uint8_t rotaryb_buttonPush()
{
    return hal_gpio_intGet();
}

/* Get led data state */
uint16_t rotaryb_getLedData( uint8_t Current_Led_State )
{
      switch ( Current_Led_State )
      {
          case 0 : return 0x0001;                      // One LED
          break;
          case 1 : return 0x0101;                      // Two LED
          break;
          case 2 : return 0x1111;                      // Four LED
          break;
          case 3 : return 0x5555;                      // Eight LED
          break;
          default : return 0x0001;                     // One LED
          break;
      }
}

/* Reset led */
void rotaryb_resetLed()
{
    rotaryb_turnOnLedByData( 0x0000 );
}

/* State AN pin */
uint8_t rotaryb_getANstate()
{
    return hal_gpio_anGet();
}

/* State PWM pin */
uint8_t rotaryb_getPWMstate()
{
    return hal_gpio_pwmGet();
}





/* -------------------------------------------------------------------------- */
/*
  __rotaryb_driver.c

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