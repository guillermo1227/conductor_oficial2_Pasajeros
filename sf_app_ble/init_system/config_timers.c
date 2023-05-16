/*
 * config_timers.c
 *
 *  Created on: 2 mar 2021
 *      Author: Jared
 */




#include "wiced_hal_wdog.h"
#include "wiced_hal_rand.h"
#include "wiced_hal_nvram.h"

#include "wiced_bt_trace.h"
//#include "wiced_bt_cfg.h"
#if ( defined(CYW20706A2) || defined(CYW20719B1) || defined(CYW20719B0) || defined(CYW20721B1) || defined(CYW20735B0) || defined(CYW43012C0) )
#include "wiced_bt_app_common.h"
#endif
#include "wiced_bt_stack.h"
#include "wiced_timer.h"
#include "wiced_bt_beacon.h"
#include "string.h"
#include "sparcommon.h"
//#include "GeneratedSource/cycfg_gatt_db.h"
#ifndef CYW43012C0
#include "wiced_bt_ota_firmware_upgrade.h"
#endif
#include "wiced_hal_puart.h"
#include "wiced_platform.h"
#include "wiced_transport.h"

#include <malloc.h>

#include "wiced_bt_mesh_models.h"
#include "wiced_bt_mesh_app.h"
#include "wiced_bt_mesh_core.h"
#include "config_timers.h"

wiced_timer_t timer_Online;
wiced_timer_t timer_st_Online;
wiced_timer_t timer_inspection;
wiced_timer_t timer_contM;
wiced_timer_t timer_Clear;
wiced_timer_t timer_Clear10;
wiced_timer_t timer_gap;
wiced_timer_t timer_return;
wiced_timer_t timer_returnfA;
wiced_timer_t timer_returnfAV;
wiced_timer_t timer_returnfB;
wiced_timer_t timer_alrm;
wiced_timer_t timer_EA;
wiced_timer_t timer_er;
wiced_timer_t timer_ach;
wiced_timer_t timer_cer;

void config_clk_timers(void)
{
	wiced_init_timer( &timer_Online, f_timer_Online, 0, WICED_MILLI_SECONDS_TIMER );
    wiced_init_timer( &timer_st_Online, f_timer_st_Online, 0, WICED_MILLI_SECONDS_TIMER );
    wiced_init_timer(&timer_inspection, f_timer_inspection, 0, WICED_SECONDS_TIMER);
    wiced_init_timer( &timer_contM, f_timer_contM, 0, WICED_MILLI_SECONDS_TIMER );
    wiced_init_timer( &timer_Clear, f_clear, 0, WICED_SECONDS_TIMER );
    wiced_init_timer( &timer_Clear10, f_clear10, 0, WICED_SECONDS_TIMER );
    wiced_init_timer( &timer_gap, f_gap, 0, WICED_SECONDS_TIMER );
    wiced_init_timer(&timer_return, f_timer_return, 0, WICED_SECONDS_TIMER);
    wiced_init_timer(&timer_returnfA, f_timer_returnfA, 0, WICED_MILLI_SECONDS_TIMER);
    wiced_init_timer(&timer_returnfAV, f_timer_returnfAV, 0, WICED_MILLI_SECONDS_TIMER);
    wiced_init_timer(&timer_returnfB, f_timer_returnfB, 0, WICED_SECONDS_TIMER);
    wiced_init_timer(&timer_alrm, f_timer_alrm, 0, WICED_MILLI_SECONDS_TIMER);
    wiced_init_timer(&timer_EA,  f_timer_EA, 0, WICED_SECONDS_TIMER);
    wiced_init_timer( &timer_er, f_timer_er, 0, WICED_SECONDS_TIMER );
    wiced_init_timer( &timer_ach, f_timer_ach, 0, WICED_MILLI_SECONDS_TIMER );
    wiced_init_timer( &timer_cer, f_timer_CER, 0, WICED_MILLI_SECONDS_TIMER );
}

void start_BTimers(void)
{
    wiced_start_timer( &timer_Online, 3000);
    //wiced_start_timer( &timer_st_Online, clock_st_Online);
	wiced_start_timer( &timer_contM, 4000);
}


void start_TOnline(void)
{
	 wiced_start_timer( &timer_Online, clock_Online);
}

void start_TOnline_long(void)
{
	//wiced_start_timer( &timer_st_Online, clock_st_Online);
}

void stop_TOnline(void)
{
	wiced_stop_timer(&timer_Online);
	wiced_start_timer( &timer_Online, clock_Online_long);
}

void prevention_inspection(void)
{
	  /* if (wiced_init_timer(&timer_inspection, f_timer_inspection, 0, WICED_SECONDS_TIMER) == WICED_SUCCESS)
	    {
		   WICED_BT_TRACE("Init timer inspection\n");
		   wiced_start_timer( &timer_inspection, clock_inspection);
	    }*/
	   WICED_BT_TRACE("Init timer inspection\n");
	   wiced_start_timer( &timer_inspection, clock_inspection);
}

void stop_timer_st_online(void)
{
	wiced_stop_timer( &timer_st_Online);
}

void Start_TimerCont(void)
{
	wiced_start_timer( &timer_contM, 4000);
}
void   timer_clr01(void)
{
	wiced_start_timer( &timer_Clear, clock_clear5);
	//wiced_stop_timer( &timer_Online);
	//wiced_start_timer( &timer_Online, clock_Online);
}

void   timer_clr10(void)
{
	wiced_start_timer( &timer_Clear10, clock_clear5);
	//wiced_stop_timer( &timer_Reportcxn_ncr);
	//wiced_start_timer( &timer_Reportcxn_ncr, clock_cxn_ncr1);
}

void   init_gap(void)
{
	wiced_start_timer( &timer_gap, clock_gap1);
}

void start_Treturn(void)
{
	wiced_start_timer( &timer_return, clock_return5);
}

void start_TreturnfA(void)
{
	wiced_start_timer( &timer_returnfA, 1000);
}

void start_TreturnfAR(void)
{
	wiced_start_timer( &timer_returnfA, 6000);
}

void start_TreturnfAV(void)
{
	wiced_start_timer( &timer_returnfAV, 1000);
}

void start_TreturnfAVR(void)
{
	wiced_start_timer( &timer_returnfAV, 6000);
}

void start_TreturnfB(void)
{
	wiced_start_timer( &timer_returnfB, 10);
}

void start_alrm(void)
{
	wiced_start_timer( &timer_alrm, clock_alrm);
}

void stop_alrm(void)
{
	 wiced_stop_timer( &timer_alrm);
}

void start_TreturnEA(void)
{
	wiced_start_timer( &timer_EA, clock_EA);
}

void init_event_er(void)
{
	wiced_start_timer( &timer_er, clock_gap1);
}

void Start_Timerach(void)
{
	wiced_start_timer( &timer_ach, 1000);
}
void Stop_Timerach(void)
{
	wiced_stop_timer( &timer_ach);
}

void start_TreturnCER(void)
{
	wiced_start_timer( &timer_cer, 7000);
}
