/*
 * adc_run_p.c
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
#include "cycfg.h"
#include "adc_run_p.h"


//level
void app_task( uint32_t arg )
{
	extern void send_level_p(uint8_t *p_dlevel);
	uint32_t Vddio, Vmeas, Rtherm, por_cien;
	 uint8_t datav_level;

    while( 1 )
    {
    	Vddio = wiced_hal_adc_read_voltage( ADC_INPUT_VDDIO );
    	Vmeas = wiced_hal_adc_read_voltage( ADC_INPUT_P12 );

    	/*
    	 * Rtherm calculation for thermistor:
    	 *
    	 *			---		Vddio
    	 *			 \		^
    	 *			 /		|
    	 *	Rtherm	 \		|
    	 *			 /		|
    	 *			 \		|
    	 *			---		| Vmeas
    	 *			 /		| ^
    	 *			 \		| |
    	 *	BALANCE	 /		| |
     	 *		 	 \		| |
    	 *			 /		| |
    	 *			---		v v Ground
    	 */

    	Rtherm = ((Vddio - Vmeas) * BALANCE_RESISTANCE) / Vmeas;
		//WICED_BT_TRACE( "Vin12_Vmeas = %d v\n\r", Vmeas );
        por_cien=((Vmeas)*por_cent)/level_refer;


        datav_level=por_cien & 0x000000ff;
        send_level_p(datav_level);


     	//WICED_BT_TRACE( "Porciento0 = %X \n\r",datav_level);

        /* Send the thread to sleep for a specified number of milliseconds */
        wiced_rtos_delay_milliseconds( 45000, ALLOW_THREAD_TO_SLEEP );
    }
}


//level
