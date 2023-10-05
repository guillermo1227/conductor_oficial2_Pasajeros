/*
 * config_adc_p.c
 *
 *  Created on: 16 mar 2021
 *      Author: Jared
 */

#include "sparcommon.h"
#include "wiced_bt_dev.h"
#include "wiced_platform.h"
#include "wiced_bt_trace.h"
#include "wiced_hal_puart.h"
#include "wiced_bt_stack.h"
#include "wiced_rtos.h"
#include "wiced_hal_adc.h"
#include "wiced_bt_ble.h"
#include "wiced_bt_gatt.h"
#include "config_adc_p.h"

/**************************************************************************
 * Function name: set_adc_p
 * Description:   a task is created and the battery adc configurations
 **************************************************************************/
void set_adc_p(void)
{
    //level
	/* Turn on the ADC */
	wiced_hal_adc_init();
	wiced_hal_adc_set_input_range( ADC_RANGE_0_3P6V );

	/* The stack is safely up - create a thread to test out peripherals */
	wiced_thread_t* peripheral_test_thread = wiced_rtos_create_thread();

	wiced_rtos_init_thread(
			peripheral_test_thread,		// Thread handle
			4,                			// Medium Priority
			"App Task",					// Name
			app_task,					// Function
			1024,						// Stack space for the app_task function to use
			NULL );						// Function argument (not used)
    //level

    wiced_hal_puart_print( "**** CYW20819 App Start **** \n\r" );
    WICED_BT_TRACE("{?\r\n");
    WICED_BT_TRACE("{?\r\n");
    WICED_BT_TRACE("{?\r\n");
}
