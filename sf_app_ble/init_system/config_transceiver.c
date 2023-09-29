/*
 * config_transceiver.c
 *
 *  Created on: 1 mar 2021
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
#include "wiced_rtos.h"
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
#include "config_transceiver.h"

/*
 * Function name: config_Transceiver
 * Description:  uart transceiver configuration
 */
void	config_Transceiver(void)
{
    //-----------------------------------------------------------------------------------------------
    wiced_hal_puart_init();
    wiced_hal_puart_flow_off();
    wiced_hal_puart_enable_tx();
    wiced_hal_puart_register_interrupt( rx_cback );
    wiced_hal_puart_set_watermark_level( 1 );
    wiced_hal_puart_enable_rx();
    //-----------------------------------------------------------------------------------------------
}
