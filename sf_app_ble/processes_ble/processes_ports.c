/*
 * processes_ports.c
 *
 *  Created on: 1 mar 2021
 *      Author: Jared
 */





#include "processes_ports.h"
#include "wiced_bt_dev.h"
#include "sparcommon.h"
#include "wiced_rtos.h"
#include "wiced_hal_gpio.h"
#include "wiced_hal_mia.h"
#include "wiced_gki.h"
#include "wiced_platform.h"
#include "wiced_timer.h"
#include "wiced_bt_trace.h"
#include "wiced_hal_puart.h"
#include "wiced_bt_stack.h"
#include "config_ports.h"


/***********************************************************
 * Function name: event_recover_OTA
 * Description: The pin sequence for OTA mode
 *              is activated in the WiFi module
 ***********************************************************/
void event_recover_OTA(void)
{
	/*if( GPIO_PIN_OUTPUT_HIGH == wiced_hal_gpio_get_pin_output(LED_GPIO_06 ) )
	{
		 WICED_BT_TRACE( "PIN6 LOW\n\r" );
		 return;
	}*/
	/*else if( GPIO_PIN_OUTPUT_HIGH == wiced_hal_gpio_get_pin_output(LED_GPIO_13 ) )
	{
		 WICED_BT_TRACE( "PIN113 LOW\n\r" );
		 return;
	}*/

	/*wiced_hal_gpio_set_pin_output( LED_GPIO_06, GPIO_PIN_OUTPUT_LOW);
	 WICED_BT_TRACE( "PIN6 LOW\n\r" );
	 wiced_hal_gpio_set_pin_output( LED_GPIO_13, GPIO_PIN_OUTPUT_LOW);
     WICED_BT_TRACE( "PIN6 LOW\n\r" );
     wiced_rtos_delay_milliseconds( 1000, ALLOW_THREAD_TO_SLEEP );
	 wiced_hal_gpio_set_pin_output( LED_GPIO_13, GPIO_PIN_OUTPUT_HIGH);
     WICED_BT_TRACE( "PIN13 HIGH\n\r" );
     wiced_rtos_delay_milliseconds( 1000, ALLOW_THREAD_TO_SLEEP );
	 wiced_hal_gpio_set_pin_output( LED_GPIO_06, GPIO_PIN_OUTPUT_HIGH);
     WICED_BT_TRACE( "PIN6 HIGH\n\r" );
     wiced_rtos_delay_milliseconds( 500, ALLOW_THREAD_TO_SLEEP );
	 wiced_hal_gpio_set_pin_output( LED_GPIO_06, GPIO_PIN_OUTPUT_LOW);
     WICED_BT_TRACE( "PIN6 LOW\n\r" );
     wiced_rtos_delay_milliseconds( 10000, ALLOW_THREAD_TO_SLEEP );
     wiced_hal_gpio_set_pin_output( LED_GPIO_13, GPIO_PIN_OUTPUT_LOW);
     WICED_BT_TRACE( "PIN13 LOW\n\r" );*/
}

/***********************************************************
 * Function name: prevention_status
 * Description: optional collision detection is disabled
 ***********************************************************/
void prevention_status(void)
{
	//wiced_hal_gpio_set_pin_output( LED_GPIO_03, GPIO_PIN_OUTPUT_HIGH);
}

/*****************************************************************
 * Function name: prevention_status2
 * Description: The optional collision detection is deactivated
 *              alternating the state of the LED
 *****************************************************************/
void prevention_status2(void)
{
	/*if(GPIO_PIN_OUTPUT_HIGH == wiced_hal_gpio_get_pin_output(LED_GPIO_03 ))
	{
	wiced_hal_gpio_set_pin_output( LED_GPIO_03, GPIO_PIN_OUTPUT_LOW);
	}
	else
	{
    wiced_hal_gpio_set_pin_output( LED_GPIO_03, GPIO_PIN_OUTPUT_HIGH);
	}*/
}
