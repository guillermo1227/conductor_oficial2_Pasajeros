/*
 * gap_layer_app.h
 *
 *  Created on: 1 mar 2021
 *      Author: Jared
 */

#ifndef SF_APP_BLE_STACKS_CORES_GAP_LAYER_APP_H_
#define SF_APP_BLE_STACKS_CORES_GAP_LAYER_APP_H_



#define BEACON_EDDYSTONE_TLM 4



/* User defined UUID for iBeacon */
#define UUID_IBEACON     0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f

char datafv_cfb[8]={0x4c,0x41,0x49,0x52,0x44,0x53,0x4c,0x50};
char datafv_cfbV[8]={0x4c,0x41,0x49,0x52,0x44,0x53,0x54,0x56};
char datac_cfb[6];
char dataa_cfb2[14];

extern const wiced_bt_cfg_settings_t app_cfg_settings2;
extern const wiced_bt_cfg_buf_pool_t app_buf_pools2[];

void gap_stack_init(void);
void gap_transferA(void);
void gap_transferB(void);

static void                     beacon_init(void);
static wiced_result_t           beacon_management_callback(wiced_bt_management_evt_t event, wiced_bt_management_evt_data_t *p_event_data);
static void                     beacon_advertisement_stopped(void);
static void                     beacon_set_app_advertisement_data2();
void                            beacon_set_app_advertisement_data3(void);
void                            gap_transferER(void);

extern void	                    config_Transceiver(void);
extern void                     init_config_logs(void);
extern void                     init_mac_logs(void);
extern void                     start_observe(void);

extern void                     set_outPuts(void);
extern void                     set_intPuts(void);
extern void                     register_pin_interrupt(void);
extern void                     event_select_OTA(void);
extern void                     set_adc_p(void);
extern void                     event_select_SPP(void);
extern void                     set_rssi(void);

extern void                     config_clk_timers(void);
//extern void                     start_BTimers(void);



#endif /* SF_APP_BLE_STACKS_CORES_GAP_LAYER_APP_H_ */
