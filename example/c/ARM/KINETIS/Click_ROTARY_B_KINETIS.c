/*
Example for ROTARY_B Click

    Date          : Jul 2018.
    Author        : Nenad Filipovic

Test configuration KINETIS :
    
    MCU              : MK64
    Dev. Board       : HEXIWEAR
    ARM Compiler ver : v6.0.0.0

---

Description :

The application is composed of three sections :

- System Initialization - Initializes peripherals and set pins.
- Application Initialization - Initializes SPI driver, set initial states, set RST logic high and performs device configuration.
- Application Task - (code snippet) Show functionality of Rotary_B Click, rotating and turn on/off led's, using the SPI interface

Additional Functions :

- SPI

*/

#include "Click_ROTARY_B_types.h"
#include "Click_ROTARY_B_config.h"

uint8_t startStatus;
uint8_t stateOld;
uint8_t stateNew;
uint8_t stateOldRotate;
uint8_t stateNewRotate;
uint8_t ledState;
uint16_t ledData;

void systemInit()
{
    mikrobus_gpioInit( _MIKROBUS1, _MIKROBUS_PWM_PIN, _GPIO_INPUT );
    mikrobus_gpioInit( _MIKROBUS1, _MIKROBUS_INT_PIN, _GPIO_INPUT );
    mikrobus_gpioInit( _MIKROBUS1, _MIKROBUS_AN_PIN, _GPIO_INPUT );
    mikrobus_gpioInit( _MIKROBUS1, _MIKROBUS_RST_PIN, _GPIO_OUTPUT );
    mikrobus_gpioInit( _MIKROBUS1, _MIKROBUS_CS_PIN, _GPIO_OUTPUT );

    mikrobus_spiInit( _MIKROBUS1, &_ROTARYB_SPI_CFG[0] );
    Delay_100ms();
}

void applicationInit()
{
    rotaryb_spiDriverInit( (T_ROTARYB_P)&_MIKROBUS1_GPIO, (T_ROTARYB_P)&_MIKROBUS1_SPI );

    ledData = 0x0001;
    stateOld = 0;
    stateNew = 1;
    stateOldRotate = 0;
    stateNewRotate = 1;
}

void applicationTask()
{
    rotaryb_turnOnLedByData( ledData );

    // Push button
    if ( rotaryb_buttonPush() )
    {
        stateNew = 1;
        if ( stateNew == 1 &&  stateOld == 0 )
        {
            stateOld = 1;
            ledState = ( ledState + 1 ) % 5;
            if ( ledState == 4 )
            {
                for ( stateOld=0; stateOld < 17; stateOld++ )
                {
                    rotaryb_turnOnLedByData( 0xAAAA );
                    Delay_100ms();
                    rotaryb_turnOnLedByData( 0x5555 );
                    Delay_100ms();
                }

                for ( stateOld=0; stateOld < 17; stateOld++ )
                {
                    rotaryb_turnOnLedByPosition( stateOld );
                    Delay_100ms();
                }

                ledState = 0;
                ledData = rotaryb_getLedData( ledState );
            }
            else
            {
                ledData = rotaryb_getLedData( ledState );
            }
         }
    }
    else
    {
         stateOld = 0;
    }

    // Rotate Clockwise and CounterClockwise
    if ( rotaryb_getPWMstate() == rotaryb_getANstate() )
    {
        stateOldRotate = 0;
        startStatus = rotaryb_getPWMstate() && rotaryb_getANstate();
    }
    else
    {
        stateNewRotate = 1;
        if ( stateNewRotate != stateOldRotate )
        {
            stateOldRotate = 1;
            if ( startStatus != rotaryb_getPWMstate() )
            {
                 ledData = ( ledData << 1 ) | ( ledData >> 15 );
            }
            else
            {
                 ledData = ( ledData >> 1 ) | ( ledData << 15 );
            }
        }
    }
}

void main()
{
    systemInit();
    applicationInit();

    while (1)
    {
        applicationTask();
    }
}
