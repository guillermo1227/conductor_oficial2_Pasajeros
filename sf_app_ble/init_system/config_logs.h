/*
 * config_logs.h
 *
 *  Created on: 1 mar 2021
 *      Author: Jared
 */

#ifndef SF_APP_BLE_INIT_SYSTEM_CONFIG_LOGS_H_
#define SF_APP_BLE_INIT_SYSTEM_CONFIG_LOGS_H_

extern wiced_result_t  status1;

extern uint8_t flag1;
extern uint8_t flag2;
extern uint8_t flag3;
extern uint8_t flag4;
extern uint8_t flag5;
extern uint8_t flag6;
extern uint8_t flag11;

uint8_t Uart_u8TxBuffer[1];
uint8_t Adc_value[1];

volatile uint8_t* Uart_pu8PutTx=&Uart_u8TxBuffer[0];
volatile uint8_t* Uart_pu8GetTx=&Uart_u8TxBuffer[0];



extern wiced_result_t  status1;
extern uint16_t        numbytes1;

extern wiced_result_t  status2;
extern uint16_t        numbytes2;

extern wiced_result_t  status3;
extern uint16_t        numbytes3;

extern wiced_result_t  status4;
extern uint16_t        numbytes4;

extern wiced_result_t  status5;
extern uint16_t        numbytes5;

extern wiced_result_t  status6;
extern uint16_t        numbytes6;

extern wiced_result_t  status7;
extern uint16_t        numbytes7;

extern wiced_result_t  status8;
extern uint16_t        numbytes8;

extern wiced_result_t  status11;
extern uint16_t        numbytes11;

wiced_result_t  status12;
uint16_t        numbytes12;


extern uint8_t         BT_LOCAL_NAME2[64];


extern unsigned char data_bn_save[10];
extern unsigned char data_ma_save[12];

#define BT_LOCAL_NAME_DEFAULT  "L4SEC BLE8"
#define BT_LOCAL_NAME_DEFAULT2 "L4sec BLE8"

#define BT_LOCAL_NAME_DEFAULTaG  "LAIRD BL05"
#define BT_LOCAL_NAME_DEFAULTRS  "LAIRD BLRS"

#define BT_LOCAL_NAME_DEFAULTa0  "L4SEC BL05"
#define BT_LOCAL_NAME_DEFAULTa1  "L4SEC BLE1"
#define BT_LOCAL_NAME_DEFAULTa2  "L4SEC BLE2"
#define BT_LOCAL_NAME_DEFAULTa3  "L4SEC BLE3"
#define BT_LOCAL_NAME_DEFAULTa4  "L4SEC BLE4"
#define BT_LOCAL_NAME_DEFAULTa5  "L4SEC BLE5"
#define BT_LOCAL_NAME_DEFAULTa6  "L4SEC BLE6"
#define BT_LOCAL_NAME_DEFAULTa7  "L4SEC BLE7"
#define BT_LOCAL_NAME_DEFAULTa8  "L4SEC BLE8"
#define BT_LOCAL_NAME_DEFAULTa9  "L4SEC BLE9"
#define BT_LOCAL_NAME_DEFAULTa10 "L4SEC BL10"

#define BT_LOCAL_NAME_DEFAULTT0  "L4SEC VT05"
#define BT_LOCAL_NAME_DEFAULTT1  "L4SEC VTE1"
#define BT_LOCAL_NAME_DEFAULTT2  "L4SEC VTE2"
#define BT_LOCAL_NAME_DEFAULTT3  "L4SEC VTE3"
#define BT_LOCAL_NAME_DEFAULTT4  "L4SEC VTE4"
#define BT_LOCAL_NAME_DEFAULTT5  "L4SEC VTE5"
#define BT_LOCAL_NAME_DEFAULTT6  "L4SEC VTE6"
#define BT_LOCAL_NAME_DEFAULTT7  "L4SEC VTE7"
#define BT_LOCAL_NAME_DEFAULTT8  "L4SEC VTE8"
#define BT_LOCAL_NAME_DEFAULTT9  "L4SEC VTE9"
#define BT_LOCAL_NAME_DEFAULTT10 "L4SEC VT10"

#define BT_LOCAL_NAME_DEFAULTTA  "L41RD BL05"

void   init_config_logs(void);
void   init_mac_logs(void);
void   init_macCTR_logs(void);

extern             void prevention_inspection(void);
extern void filt_cfb(uint8_t *data_cfb2);



#endif /* SF_APP_BLE_INIT_SYSTEM_CONFIG_LOGS_H_ */
