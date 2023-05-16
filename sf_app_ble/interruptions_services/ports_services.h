/*
 * ports_services.h
 *
 *  Created on: 1 mar 2021
 *      Author: Jared
 */

#ifndef SF_APP_BLE_INTERRUPTIONS_SERVICES_PORTS_SERVICES_H_
#define SF_APP_BLE_INTERRUPTIONS_SERVICES_PORTS_SERVICES_H_

wiced_bool_t gap_er=WICED_FALSE;
extern wiced_bool_t gap_t1;
extern wiced_bool_t value_gap;

void button_cback_26( void *data, uint8_t port_pin );
void button_cback_4( void *data, uint8_t port_pin );
void init_event_SER(void);
void init_event_RAC(void);

extern void stop_process(void);
extern void gap_transfer(void);
extern void init_event_gap(void);
extern void gap_transferA(void);
extern void gap_transferB(void);
extern void init_gap(void);
extern void init_event_er(void);

#endif /* SF_APP_BLE_INTERRUPTIONS_SERVICES_PORTS_SERVICES_H_ */
