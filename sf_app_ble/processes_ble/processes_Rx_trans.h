/*
 * processes_Rx_trans.h
 *
 *  Created on: 1 mar 2021
 *      Author: Jared
 */

#ifndef SF_APP_BLE_PROCESSES_BLE_PROCESSES_RX_TRANS_H_
#define SF_APP_BLE_PROCESSES_BLE_PROCESSES_RX_TRANS_H_

wiced_result_t  status1;
uint16_t        numbytes1;

wiced_result_t  status2;
uint16_t        numbytes2;

wiced_result_t  status3;
uint16_t        numbytes3;

wiced_result_t  status4;
uint16_t        numbytes4;

wiced_result_t  status5;
uint16_t        numbytes5;

wiced_result_t  status6;
uint16_t        numbytes6;

wiced_result_t  status7;
uint16_t        numbytes7;

wiced_result_t  status8;
uint16_t        numbytes8;

wiced_result_t  status11;
uint16_t        numbytes11;

wiced_result_t  status13;
uint16_t        numbytes13;

uint8_t data_f[3];


#define data_WBN "WBN"
#define data_WBF "WBF"
#define data_WMA "WMA"
#define data_RBN "RBN"
#define data_RMA "RMA"
#define data_CMA "CMA"
#define data_WiFi "WiF"
#define data_OS  "OCS"
#define data_OTA "OTA"
#define data_SOM "SOM"
#define data_SSC "SSC"
#define data_SAC "SAC"
#define data_SER "SER"
#define data_RTS "RTS"
#define data_STS "STS"
#define data_SRT "SRT"
#define data_STV "STV"
#define data_SLA "SLA"
#define data_SLB "SLB"
#define data_SBP "SBP"
#define data_SDV "SDV"
#define data_SSW "SSW"
#define data_SWD "SWD"
#define data_SDA "SDA"
#define data_SDB "SDB"
#define data_SFM "SFM"
#define data_SRM "SRM"

#define BT_LOCAL_NAME_DEFAULT "L4SEC BLE"


uint8_t flag1  = 0;
uint8_t flag2  = 0;
uint8_t flag3  = 0;
uint8_t flag4  = 0;
uint8_t flag5  = 0;
uint8_t flag6  = 0;
uint8_t flag11 = 0;
uint8_t flag13 = 0;
uint8_t flag_pwd = 0;

uint8_t dla = 0;
uint8_t dlb = 0;
uint8_t dtv = 0;

int cv1,cv2,cv3;

unsigned char data_bn_save[10];
unsigned char data_ma_save[12];
unsigned char data_flash[20];
unsigned char data_rssi_save1[10];
uint8_t data_uuid[16];
uint8_t data_rssi[3];
uint8_t d_password1[7];
uint8_t c_password1[7];
uint8_t datac_cfbf[6];


void process_Write(uint8_t *data_Write);
void process_CMA(uint8_t *data_C_MA);
void process_data_config(uint8_t *data_dc);
void process_OCS(uint8_t *data_OCS);
void gap_transfer(void);
void gap_out_f(void);


extern uint8_t BT_LOCAL_NAME2[64];
extern wiced_bool_t status_Online;
extern void stop_TOnline(void);
extern void event_recover_OTA(void);
extern void event_select_OTA(void);

extern void init_event_RAC(void);
extern void init_mac_logs(void);
extern void init_event_SER(void);
extern void event_mlfb(void);
extern void set_rssi(void);
extern void dataTx_spp1(int select);
extern void event_select_SPP(void);
extern void filt_cfb(uint8_t *data_cfb2);
extern void filt_cfb_log(uint8_t *data_cfb3);



#endif /* SF_APP_BLE_PROCESSES_BLE_PROCESSES_RX_TRANS_H_ */
