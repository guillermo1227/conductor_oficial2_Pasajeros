/*
 * config_logs.c
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
#include "config_logs.h"


void   init_config_logs(void)
{
	 numbytes2 = wiced_hal_read_nvram( WICED_NVRAM_VSID_START+1, sizeof(flag1), &flag1, &status2 );
	 numbytes11 = wiced_hal_read_nvram( WICED_NVRAM_VSID_START+11, sizeof(flag11), &flag11, &status11 );
	  numbytes12 = wiced_hal_read_nvram( WICED_NVRAM_VSID_START+12, sizeof(Uart_pu8PutTx), &Uart_pu8PutTx, &status12 );
	//WICED_BT_TRACE("FLAG1:%d\n", flag1);
	 if(flag1==1 && flag11==0)
	 {
    //------------------------------------------------------------------------------------------
    numbytes1 = wiced_hal_read_nvram( WICED_NVRAM_VSID_START, sizeof(data_bn_save), &data_bn_save, &status1 );
	 WICED_BT_TRACE( "Name Beacon: ");
	 for(int i=0;i<sizeof(data_bn_save)-1; i++){wiced_hal_puart_write(data_bn_save[i]);}
	 WICED_BT_TRACE( "\n");
	 memcpy(BT_LOCAL_NAME2,data_bn_save,10);
	 //-----------------------------------------------------------------------------------------------
	 }
	 else if(flag1==0 && flag11==0)
	 {
	  WICED_BT_TRACE( "Name Beacon: ");
	  //for(int i=0;i<sizeof(BT_LOCAL_NAME_DEFAULT)-1; i++){wiced_hal_puart_write(BT_LOCAL_NAME_DEFAULT[i]);}
	  WICED_BT_TRACE( "\n");


     //memcpy(BT_LOCAL_NAME2,BT_LOCAL_NAME_DEFAULT,10);
	 //WICED_BT_TRACE( "Porciento3 = %X \n\r",Uart_pu8PutTx);
	 //WICED_BT_TRACE( "Porciento4 = %d \n\r",Uart_pu8PutTx);
	 if(Uart_pu8PutTx >= 0 && Uart_pu8PutTx < 10)
	 {
		   memcpy(BT_LOCAL_NAME2,BT_LOCAL_NAME_DEFAULTRS,10);
		   //for(int i=0;i<sizeof(BT_LOCAL_NAME_DEFAULTa0)-1; i++){wiced_hal_puart_write(BT_LOCAL_NAME_DEFAULTa0[i]);}
	 }

	 else if(Uart_pu8PutTx >= 10 && Uart_pu8PutTx < 20)
	 {
		   memcpy(BT_LOCAL_NAME2,BT_LOCAL_NAME_DEFAULTRS,10);
	 }
	 else if(Uart_pu8PutTx >= 20 && Uart_pu8PutTx < 30)
	 {
		   memcpy(BT_LOCAL_NAME2,BT_LOCAL_NAME_DEFAULTRS,10);
	 }
	 else if(Uart_pu8PutTx >= 30 && Uart_pu8PutTx < 40)
	 {
		   memcpy(BT_LOCAL_NAME2,BT_LOCAL_NAME_DEFAULTRS,10);
	 }
	 else if(Uart_pu8PutTx >= 40 && Uart_pu8PutTx < 50)
	 {
		   memcpy(BT_LOCAL_NAME2,BT_LOCAL_NAME_DEFAULTRS,10);
	 }
	 else if(Uart_pu8PutTx >= 50 && Uart_pu8PutTx < 60)
	 {
		   memcpy(BT_LOCAL_NAME2,BT_LOCAL_NAME_DEFAULTRS,10);
	 }
	 else if(Uart_pu8PutTx >= 60 && Uart_pu8PutTx < 70)
	 {
		   memcpy(BT_LOCAL_NAME2,BT_LOCAL_NAME_DEFAULTRS,10);
	 }
	 else if(Uart_pu8PutTx >= 70 && Uart_pu8PutTx < 80)
	 {
		   memcpy(BT_LOCAL_NAME2,BT_LOCAL_NAME_DEFAULTRS,10);
	 }
	 else if(Uart_pu8PutTx >= 80 && Uart_pu8PutTx < 90)
	 {
		   memcpy(BT_LOCAL_NAME2,BT_LOCAL_NAME_DEFAULTRS,10);
	 }
	 else if(Uart_pu8PutTx >= 90 && Uart_pu8PutTx < 100)
	 {
		   memcpy(BT_LOCAL_NAME2,BT_LOCAL_NAME_DEFAULTRS,10);
	 }
	 memcpy(BT_LOCAL_NAME2,BT_LOCAL_NAME_DEFAULTRS,10);

     for(int i=0;i< 10; i++){wiced_hal_puart_write(BT_LOCAL_NAME2[i]);}
     WICED_BT_TRACE( "\n");

	 }
	 else
	 {
		 //---------------------------------------------
		 if(Uart_pu8PutTx >= 0 && Uart_pu8PutTx < 10)
		 {
			   memcpy(BT_LOCAL_NAME2,BT_LOCAL_NAME_DEFAULTTA,10);
			   //for(int i=0;i<sizeof(BT_LOCAL_NAME_DEFAULTa0)-1; i++){wiced_hal_puart_write(BT_LOCAL_NAME_DEFAULTa0[i]);}
		 }

		 else if(Uart_pu8PutTx >= 10 && Uart_pu8PutTx < 20)
		 {
			   memcpy(BT_LOCAL_NAME2,BT_LOCAL_NAME_DEFAULTTA,10);
		 }
		 else if(Uart_pu8PutTx >= 20 && Uart_pu8PutTx < 30)
		 {
			   memcpy(BT_LOCAL_NAME2,BT_LOCAL_NAME_DEFAULTTA,10);
		 }
		 else if(Uart_pu8PutTx >= 30 && Uart_pu8PutTx < 40)
		 {
			   memcpy(BT_LOCAL_NAME2,BT_LOCAL_NAME_DEFAULTTA,10);
		 }
		 else if(Uart_pu8PutTx >= 40 && Uart_pu8PutTx < 50)
		 {
			   memcpy(BT_LOCAL_NAME2,BT_LOCAL_NAME_DEFAULTTA,10);
		 }
		 else if(Uart_pu8PutTx >= 50 && Uart_pu8PutTx < 60)
		 {
			   memcpy(BT_LOCAL_NAME2,BT_LOCAL_NAME_DEFAULTTA,10);
		 }
		 else if(Uart_pu8PutTx >= 60 && Uart_pu8PutTx < 70)
		 {
			   memcpy(BT_LOCAL_NAME2,BT_LOCAL_NAME_DEFAULTTA,10);
		 }
		 else if(Uart_pu8PutTx >= 70 && Uart_pu8PutTx < 80)
		 {
			   memcpy(BT_LOCAL_NAME2,BT_LOCAL_NAME_DEFAULTTA,10);
		 }
		 else if(Uart_pu8PutTx >= 80 && Uart_pu8PutTx < 90)
		 {
			   memcpy(BT_LOCAL_NAME2,BT_LOCAL_NAME_DEFAULTTA,10);
		 }
		 else if(Uart_pu8PutTx >= 90 && Uart_pu8PutTx < 100)
		 {
			   memcpy(BT_LOCAL_NAME2,BT_LOCAL_NAME_DEFAULTTA,10);
		 }

		 //-------------------------------------------
		  prevention_inspection();

		  WICED_BT_TRACE( "Name Beacon2: \n");
		  for(int i=0;i< 10; i++){wiced_hal_puart_write(BT_LOCAL_NAME2[i]);}
		  WICED_BT_TRACE( "\n");
		  //for(int i=0;i<sizeof(BT_LOCAL_NAME_DEFAULT2)-1; i++){wiced_hal_puart_write(BT_LOCAL_NAME_DEFAULT2[i]);}
		  WICED_BT_TRACE( "\n");
	     //memcpy(BT_LOCAL_NAME2,BT_LOCAL_NAME_DEFAULT2,10);
	     //memcpy(BT_LOCAL_NAME2 +10,&Uart_pu8GetTx,sizeof(Uart_pu8GetTx));
	 }
}

void init_mac_logs(void)
{
	   wiced_bt_device_address_t bda;
	    numbytes4 = wiced_hal_read_nvram( WICED_NVRAM_VSID_START+3, sizeof(flag2), &flag2, &status4 );
	    //WICED_BT_TRACE("FLAG2:%d\n", flag2);

	    numbytes5 = wiced_hal_read_nvram( WICED_NVRAM_VSID_START+4, sizeof(flag2), &flag3, &status5 );
	    //WICED_BT_TRACE("FLAG3:%d\n", flag3);

	    if(flag2 && flag3 )
	    {
	  	  numbytes6 = wiced_hal_read_nvram( WICED_NVRAM_VSID_START+5, sizeof(data_ma_save), &data_ma_save, &status6 );
	  	  //for(int i=0;i< sizeof(Msm_MCU)-1; i++){wiced_hal_puart_write(Msm_MCU[i]);}
	  	  WICED_BT_TRACE("Mac Address: %B ", data_ma_save);
	      //for(int i=0;i< 6; i++){wiced_hal_puart_write(data_ma_save[i]);}
	  	  WICED_BT_TRACE( "\n");
	      bda[0]=data_ma_save[0];
	      bda[1]=data_ma_save[1];
	      bda[2]=data_ma_save[2];
	      bda[3]=data_ma_save[3];
	      bda[4]=data_ma_save[4];
	      bda[5]=data_ma_save[5];
	    }
	    else if(!flag2 && flag3)
	    {
	      WICED_BT_TRACE("Mac Address Random\n");
		  bda[0]=wiced_hal_rand_gen_num();
		  bda[1]=wiced_hal_rand_gen_num();
		  bda[2]=wiced_hal_rand_gen_num();
		  bda[3]=wiced_hal_rand_gen_num();
		  bda[4]=wiced_hal_rand_gen_num();
		  bda[5]=wiced_hal_rand_gen_num();

		  flag2 = 1;
		  numbytes4 = wiced_hal_write_nvram( WICED_NVRAM_VSID_START+3, sizeof(flag2), &flag2, &status4 );
		 // WICED_BT_TRACE("FLAG2:%d\n", flag2);

		  memcpy(data_ma_save,bda ,16);
		  numbytes6 = wiced_hal_write_nvram( WICED_NVRAM_VSID_START+5, sizeof(data_ma_save), &data_ma_save, &status6 );
		  WICED_BT_TRACE("Mac Address Random: %B\n", data_ma_save);

	    }
	    else if(flag2 && !flag3)
	    {
	      //WICED_BT_TRACE("MAC FROM FLAG2\n");
		  numbytes4 = wiced_hal_read_nvram( WICED_NVRAM_VSID_START+3, sizeof(flag2), &flag2, &status4 );
		  //WICED_BT_TRACE("FLAG2:%d\n", flag2);
		  numbytes3 = wiced_hal_read_nvram( WICED_NVRAM_VSID_START+2, sizeof(data_ma_save), &data_ma_save, &status3 );
		  //for(int i=0;i< sizeof(Msm_MCU)-1; i++){wiced_hal_puart_write(Msm_MCU[i]);}
	  	  WICED_BT_TRACE("Mac Address: %B ", data_ma_save);
	  	  //for(int i=0;i< 6; i++){wiced_hal_puart_write(data_ma_save[i]);}
		  WICED_BT_TRACE( "\n");
	      bda[0]=data_ma_save[0];
	      bda[1]=data_ma_save[1];
	      bda[2]=data_ma_save[2];
	      bda[3]=data_ma_save[3];
	      bda[4]=data_ma_save[4];
	      bda[5]=data_ma_save[5];

	    }
	    else
	    {
	      WICED_BT_TRACE("Mac Address Null\n");
	      bda[0]=0x04;
	      bda[1]=0x23;
	      bda[2]=0x23;
	      bda[3]=0x23;
	      bda[4]=0x31;
	      bda[5]=0x41;
	    }

		wiced_bt_ble_address_type_t  macc= BLE_ADDR_PUBLIC_ID;

	    wiced_bt_set_local_bdaddr(bda,macc);

}

void send_level_p(uint8_t *p_dlevel)
{
	//WICED_BT_TRACE( "Porciento1 = %X \n\r",p_dlevel);
	//WICED_BT_TRACE( "Porciento2 = %d \n\r",p_dlevel);
	Uart_pu8PutTx = p_dlevel;
	Uart_pu8GetTx = p_dlevel;
	//WICED_BT_TRACE( "Porciento3 = %X \n\r",Uart_pu8PutTx);
	//WICED_BT_TRACE( "Porciento4 = %d \n\r",Uart_pu8PutTx);
	numbytes12 = wiced_hal_write_nvram( WICED_NVRAM_VSID_START+12, sizeof(Uart_pu8PutTx), &Uart_pu8PutTx, &status12 );
}
