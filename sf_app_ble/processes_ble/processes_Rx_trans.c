/*
 * processes_Rx_trans.c
 *
 *  Created on: 12 ene 2021
 *      Author: Jared
 */
#include "wiced_bt_ble.h"
#include "wiced_bt_gatt.h"
#include "wiced_bt_mesh_models.h"
#include "wiced_bt_trace.h"
#include "wiced_timer.h"
#include "wiced_bt_mesh_app.h"
#include "wiced_platform.h"
#include "wiced_rtos.h"
#include "processes_Rx_trans.h"
#include "wiced_hal_wdog.h"
#include "wiced_hal_rand.h"
#include "wiced_hal_nvram.h"
//#include "processes_ports.h"

#ifdef HCI_CONTROL
#include "wiced_transport.h"
#include "hci_control_api.h"
#endif

#include "wiced_memory.h"
#include "wiced_bt_cfg.h"



void process_Write(uint8_t *data_Write)
{
    memcpy(data_f,data_Write ,3);
    if(memcmp(data_WBN, data_f,sizeof(data_f))== 0)
    {
  	  memcpy(data_uuid,&data_Write[3] ,16);
      memcpy(data_bn_save,data_uuid ,16);
      numbytes1 = wiced_hal_write_nvram( WICED_NVRAM_VSID_START, sizeof(data_bn_save), &data_bn_save, &status1 );
      WICED_BT_TRACE("Beacon Name Saved: ");
      for(int i=0;i< sizeof(data_bn_save)-1; i++){wiced_hal_puart_write(data_bn_save[i]);}
      WICED_BT_TRACE( "\n");
		flag1 = 1;
		numbytes2 = wiced_hal_write_nvram( WICED_NVRAM_VSID_START+1, sizeof(flag1), &flag1, &status2 );
		//WICED_BT_TRACE("FLAG1:%d\n", flag1);

     /*if (16 != mesh_nvram_access(WICED_TRUE, NVRAM_ID_LOCAL_UUID, data_uuid, 16, &result))
         {
          // WICED_BT_TRACE("failed to save UUID result:%x UUID:\n", result);
         }
      wiced_rtos_delay_milliseconds( 700, ALLOW_THREAD_TO_SLEEP );
      */
      wiced_hal_wdog_reset_system ();
    }
    else if(memcmp(data_WBF, data_f,sizeof(data_f))== 0)
    {
		flag1 = 0;
		numbytes2 = wiced_hal_write_nvram( WICED_NVRAM_VSID_START+1, sizeof(flag1), &flag1, &status2 );
		wiced_hal_puart_print(BT_LOCAL_NAME2);
		wiced_hal_wdog_reset_system ();
    }
    else if(memcmp(data_WMA, data_f,sizeof(data_f))== 0)
	  {
  	    memcpy(data_uuid,&data_Write[3] ,16);
		memcpy(data_ma_save,data_uuid ,16);
		numbytes3 = wiced_hal_write_nvram( WICED_NVRAM_VSID_START+2, sizeof(data_ma_save), &data_ma_save, &status3 );
		WICED_BT_TRACE("Mac Address Saved: ");
		for(int i=0;i< 6; i++){wiced_hal_puart_write(data_ma_save[i]);}
		WICED_BT_TRACE( "\n");
		flag2 = 1;
		numbytes4 = wiced_hal_write_nvram( WICED_NVRAM_VSID_START+3, sizeof(flag2), &flag2, &status4 );
		//WICED_BT_TRACE("FLAG2:%d\n", flag2);
		flag3 = 0;
		numbytes5 = wiced_hal_write_nvram( WICED_NVRAM_VSID_START+4, sizeof(flag2), &flag3, &status5 );
		//WICED_BT_TRACE("FLAG3:%d\n", flag3);
		init_mac_logs();
		//wiced_hal_wdog_reset_system ();
	  }
    else if(memcmp(data_WiFi, data_f,sizeof(data_f))== 0)
    {
  	  WICED_BT_TRACE("OCS: OK\n");
  	  status_Online = WICED_TRUE;
    }

}

void process_CMA(uint8_t *data_C_MA)
{
    memcpy(data_f,data_C_MA ,3);
    if(memcmp(data_CMA, data_f,sizeof(data_f))== 0)
    {
		flag2 = 0;
		numbytes4 = wiced_hal_write_nvram( WICED_NVRAM_VSID_START+3, sizeof(flag2), &flag2, &status4 );
		//WICED_BT_TRACE("FLAG2:%d\n", flag2);

		flag3 = 1;
		numbytes5 = wiced_hal_write_nvram( WICED_NVRAM_VSID_START+4, sizeof(flag2), &flag3, &status5 );
		//WICED_BT_TRACE("FLAG3:%d\n", flag3);
		wiced_hal_wdog_reset_system ();
    }

}

void process_data_config(uint8_t *data_dc)
{
    memcpy(data_f,data_dc ,3);
    if(memcmp(data_RBN, data_f,sizeof(data_f))== 0)
    {
      /*
		numbytes2 = wiced_hal_read_nvram( WICED_NVRAM_VSID_START+1, sizeof(flag2), &flag1, &status2 );
		WICED_BT_TRACE("FLAG1:%d\n", flag1);
		numbytes1 = wiced_hal_read_nvram( WICED_NVRAM_VSID_START, sizeof(data_bn_save), &data_bn_save, &status1 );
		//for(int i=0;i< sizeof(Msm_MCU)-1; i++){wiced_hal_puart_write(Msm_MCU[i]);}
		WICED_BT_TRACE("BEACON NAME READ: ");
		for(int i=0;i< 8; i++){wiced_hal_puart_write(data_bn_save[i]);}
		WICED_BT_TRACE( "\n");
		*/
	  if(flag1==1)
	   {
	   //------------------------------------------------------------------------------------------
	   numbytes1 = wiced_hal_read_nvram( WICED_NVRAM_VSID_START, sizeof(data_bn_save), &data_bn_save, &status1 );
	   WICED_BT_TRACE( "Name Beacon: ");
	   for(int i=0;i<sizeof(data_bn_save)-1; i++){wiced_hal_puart_write(data_bn_save[i]);}
	   WICED_BT_TRACE( "\n");
	   memcpy(BT_LOCAL_NAME2,data_bn_save,8);
	   //-----------------------------------------------------------------------------------------------
	   }
	   else
	   {
	    WICED_BT_TRACE( "Name Beacon: ");
	    for(int i=0;i<sizeof(BT_LOCAL_NAME_DEFAULT)-1; i++){wiced_hal_puart_write(BT_LOCAL_NAME_DEFAULT[i]);}
	    WICED_BT_TRACE( "\n");
	    memcpy(BT_LOCAL_NAME2,BT_LOCAL_NAME_DEFAULT,8);
	   }
    }

    else if(memcmp(data_RMA, data_f,sizeof(data_f))== 0)
	  {
  	  /*
		numbytes4 = wiced_hal_read_nvram( WICED_NVRAM_VSID_START+3, sizeof(flag2), &flag2, &status4 );
		WICED_BT_TRACE("FLAG2:%d\n", flag2);
		numbytes3 = wiced_hal_read_nvram( WICED_NVRAM_VSID_START+2, sizeof(data_ma_save), &data_ma_save, &status3 );
		//for(int i=0;i< sizeof(Msm_MCU)-1; i++){wiced_hal_puart_write(Msm_MCU[i]);}
	    WICED_BT_TRACE("MAC ADDRESS READ:%B ", data_ma_save);
		//for(int i=0;i< 6; i++){wiced_hal_puart_write(data_ma_save[i]);}
		WICED_BT_TRACE( "\n");
		*/

  	    numbytes4 = wiced_hal_read_nvram( WICED_NVRAM_VSID_START+3, sizeof(flag2), &flag2, &status4 );
  	    //WICED_BT_TRACE("FLAG2:%d\n", flag2);

  	    numbytes5 = wiced_hal_read_nvram( WICED_NVRAM_VSID_START+4, sizeof(flag2), &flag3, &status5 );
  	    //WICED_BT_TRACE("FLAG3:%d\n", flag3);

  	    if(flag2 && flag3)
  	    {
  	  	  numbytes6 = wiced_hal_read_nvram( WICED_NVRAM_VSID_START+5, sizeof(data_ma_save), &data_ma_save, &status6 );
  	  	  //for(int i=0;i< sizeof(Msm_MCU)-1; i++){wiced_hal_puart_write(Msm_MCU[i]);}
  	  	  WICED_BT_TRACE("Mac Address: %s \n", data_ma_save);
  	      //for(int i=0;i< 6; i++){wiced_hal_puart_write(data_ma_save[i]);}

  	    }
  	    else if(!flag2 && flag3)
  	    {
  	      WICED_BT_TRACE("Mac Address Random\n");
  	    }
  	    else if(flag2 && !flag3)
  	    {
  	      //WICED_BT_TRACE("MAC FROM FLAG2\n");
  		  numbytes4 = wiced_hal_read_nvram( WICED_NVRAM_VSID_START+3, sizeof(flag2), &flag2, &status4 );
  		  //WICED_BT_TRACE("FLAG2:%d\n", flag2);
  		  numbytes3 = wiced_hal_read_nvram( WICED_NVRAM_VSID_START+2, sizeof(data_ma_save), &data_ma_save, &status3 );
  		  //for(int i=0;i< sizeof(Msm_MCU)-1; i++){wiced_hal_puart_write(Msm_MCU[i]);}
  	  	  WICED_BT_TRACE("Mac Address: %s\n", data_ma_save);
  	  	  //for(int i=0;i< 6; i++){wiced_hal_puart_write(data_ma_save[i]);}
  	    }
  	    else
  	    {
  	       WICED_BT_TRACE("Mac Address Null\n");
  	    }
	  }
}

void process_ODT(uint8_t *data_ODT)
{
    memcpy(data_f,data_ODT ,3);
      if(memcmp(data_OS, data_f,sizeof(data_f))== 0)
      {
    	  WICED_BT_TRACE("Finish\n");
    	  stop_TOnline();
    	 // wiced_stop_timer(&timer_Online);
    	 // wiced_start_timer( &timer_Online, clock_Online_long);
      }
      else if(memcmp(data_OTA, data_f,sizeof(data_f))== 0)
      {
    	  event_recover_OTA();
      }
}

void process_SOM(uint8_t *data_S_OM)
{
    memcpy(data_f,data_S_OM ,3);
      if(memcmp(data_SOM, data_f,sizeof(data_f))== 0)
      {
    	  WICED_BT_TRACE("Finish\n");
    	  event_select_OTA();
      }
      else if(memcmp(data_SRT, data_f,sizeof(data_f))== 0)
      {
    	   WICED_BT_TRACE("Event SRT\n");
	    	//dataTx_spp1(1);
	    	WICED_BT_TRACE( "Correct Password\n");
	    	flag_pwd=0;
	    	data_rssi_save1[7]=flag_pwd;
  	        memcpy(data_rssi_save1 + sizeof(data_rssi), &d_password1, sizeof(d_password1));
			WICED_BT_TRACE("1FLAG13: %B\n", data_rssi_save1);
			numbytes13 = wiced_hal_write_nvram( WICED_NVRAM_VSID_START+13, sizeof(data_rssi_save1), &data_rssi_save1, &status13 );

			 numbytes13 = wiced_hal_read_nvram( WICED_NVRAM_VSID_START+13, sizeof(data_rssi_save1), &data_rssi_save1, &status13 );
			 WICED_BT_TRACE("2FLAG13: %B\n", data_rssi_save1);
			 WICED_BT_TRACE_ARRAY(data_rssi_save1, 18, "BUFFER LAMPARASA2");
			 event_select_SRT();
      }
      else if(memcmp(data_STV, data_f,sizeof(data_f))== 0)
      {
    	  WICED_BT_TRACE("Event STV\n");
    	  init_event_SER();
		  /*cv1=data_S_OM[3]-48;
		  cv2=data_S_OM[4]-48;
		  //WICED_BT_TRACE("1dat: %d, %d\n", ctv1,ctv2);
		  cv3= ((cv1*10)+cv2);
    	  data_rssi[2] = cv3;
    	  WICED_BT_TRACE("cv3: %d\n", cv3);
    	  memcpy(data_rssi_save,data_rssi ,3);
			WICED_BT_TRACE("1FLAG13: %B\n", data_rssi_save);
			numbytes13 = wiced_hal_write_nvram( WICED_NVRAM_VSID_START+13, sizeof(data_rssi_save), &data_rssi_save, &status13 );

			 numbytes13 = wiced_hal_read_nvram( WICED_NVRAM_VSID_START+13, sizeof(data_rssi_save), &data_rssi_save, &status13 );
			 WICED_BT_TRACE("2FLAG13: %B\n", data_rssi_save);
			 dtv=data_rssi_save[2];
			 WICED_BT_TRACE("RSSI STV %d\n",dtv);*/
      }
      else if(memcmp(data_SLA, data_f,sizeof(data_f))== 0)
      {
    	  if(flag_pwd)
    	  {
    	  WICED_BT_TRACE("Event SLA\n");
		  cv1=data_S_OM[3]-48;
		  cv2=data_S_OM[4]-48;
		  //WICED_BT_TRACE("1dat: %d, %d\n", ctv1,ctv2);
		  cv3= ((cv1*10)+cv2);
    	  data_rssi[0] = cv3;
    	  WICED_BT_TRACE("cv3: %d\n", cv3);
    	  memcpy(data_rssi_save1,data_rssi ,3);
			WICED_BT_TRACE("1FLAG13: %B\n", data_rssi_save1);
			numbytes13 = wiced_hal_write_nvram( WICED_NVRAM_VSID_START+13, sizeof(data_rssi_save1), &data_rssi_save1, &status13 );

			 numbytes13 = wiced_hal_read_nvram( WICED_NVRAM_VSID_START+13, sizeof(data_rssi_save1), &data_rssi_save1, &status13 );
			 WICED_BT_TRACE("2FLAG13: %B\n", data_rssi_save1);
			 dla=data_rssi_save1[0];
			 WICED_BT_TRACE("RSSI SLA %d\n",dla);
			 //dataTx_spp1(4);
    	  }
    	  else
    	    {
    	    	//dataTx_spp1(3);
    	    	WICED_BT_TRACE( "Ingrese el Password\n");
    	    	//event_select_SPP();
    	    }
      }
      else if(memcmp(data_SDB, data_f,sizeof(data_f))== 0)
      {
    	  if(flag_pwd)
    	  {
    	  WICED_BT_TRACE("Event SLB\n");
		  cv1=data_S_OM[3]-48;
		  cv2=data_S_OM[4]-48;
		  //WICED_BT_TRACE("1dat: %d, %d\n", ctv1,ctv2);
		  cv3= ((cv1*10)+cv2);
    	  data_rssi[1]= cv3;
    	  WICED_BT_TRACE("cv3: %d\n", cv3);
    	  memcpy(data_rssi_save1,data_rssi ,3);
			WICED_BT_TRACE("1FLAG13: %B\n", data_rssi_save1);
			numbytes13 = wiced_hal_write_nvram( WICED_NVRAM_VSID_START+13, sizeof(data_rssi_save1), &data_rssi_save1, &status13 );

			 numbytes13 = wiced_hal_read_nvram( WICED_NVRAM_VSID_START+13, sizeof(data_rssi_save1), &data_rssi_save1, &status13 );
			 WICED_BT_TRACE("2FLAG13: %B\n", data_rssi_save1);
			 dlb=data_rssi_save1[1];
			 WICED_BT_TRACE("RSSI SLB %d\n",dlb);
			 //dataTx_spp1(5);
    	  }
    	  else
    	  {
  	    	//dataTx_spp1(3);
  	    	WICED_BT_TRACE( "Ingrese el Password\n");
  	    	//event_select_SPP();
    	  }
      }
      else if(memcmp(data_SBP, data_f,sizeof(data_f))== 0)
      {
    	  if(flag_pwd)
    	  {
    	  WICED_BT_TRACE("Event SDV\n");
    	  //init_event_SER();
		  cv1=data_S_OM[3]-48;
		  cv2=data_S_OM[4]-48;
		  //WICED_BT_TRACE("1dat: %d, %d\n", ctv1,ctv2);
		  cv3= ((cv1*10)+cv2);
    	  data_rssi[2] = cv3;
    	  WICED_BT_TRACE("cv3: %d\n", cv3);
    	  memcpy(data_rssi_save1,data_rssi ,3);
			WICED_BT_TRACE("1FLAG13: %B\n", data_rssi_save1);
			numbytes13 = wiced_hal_write_nvram( WICED_NVRAM_VSID_START+13, sizeof(data_rssi_save1), &data_rssi_save1, &status13 );

			 numbytes13 = wiced_hal_read_nvram( WICED_NVRAM_VSID_START+13, sizeof(data_rssi_save1), &data_rssi_save1, &status13 );
			 WICED_BT_TRACE("2FLAG13: %B\n", data_rssi_save1);
			 dtv=data_rssi_save1[2];
			 WICED_BT_TRACE("RSSI STV %d\n",dtv);
			 //dataTx_spp1(2);
    	  }
    	  else
    	  {
    	    	//dataTx_spp1(3);
    	    	WICED_BT_TRACE( "Ingrese el Password\n");
    	    	//event_select_SPP();
    	  }
      }
      else if(memcmp(data_SSC, data_f,sizeof(data_f))== 0)
      {
    	  WICED_BT_TRACE("Event SSC\n");
    	  init_event_ADC();
      }
      else if(memcmp(data_SAC, data_f,sizeof(data_f))== 0)
      {
    	  WICED_BT_TRACE("Report SAC\n");
    	  init_event_RAC();
      }
      else if(memcmp(data_SER, data_f,sizeof(data_f))== 0)
      {
    	  WICED_BT_TRACE("Report SER\n");
    	  init_event_SER();
      }
      else if(memcmp(data_STS, data_f,sizeof(data_f))== 0)
      {
    	  WICED_BT_TRACE("Report STS\n");
    	  event_mlfb();
      }
      else if(memcmp(data_SSW, data_f,sizeof(data_f))== 0)
      {
    	  if(flag_pwd)
    	  {
    	    memcpy(d_password1,&data_S_OM[3],5);

    	    memcpy(data_rssi_save1 + sizeof(data_rssi), &d_password1, sizeof(d_password1));
			WICED_BT_TRACE("1FLAG13: %B\n", data_rssi_save1);
			numbytes13 = wiced_hal_write_nvram( WICED_NVRAM_VSID_START+13, sizeof(data_rssi_save1), &data_rssi_save1, &status13 );

			 numbytes13 = wiced_hal_read_nvram( WICED_NVRAM_VSID_START+13, sizeof(data_rssi_save1), &data_rssi_save1, &status13 );
			 WICED_BT_TRACE("2FLAG13: %B\n", data_rssi_save1);
			 memcpy(d_password1,&data_rssi_save1[3],5);
		     WICED_BT_TRACE("Password: ");
			 wiced_hal_puart_print(d_password1);
			 WICED_BT_TRACE( "\n");
			 //event_select_SPP();
    	  }
  	    else
  	    {
  	    	//dataTx_spp1(3);
  	    	WICED_BT_TRACE( "Ingrese el Password\n");
  	    }
      }
      else if(memcmp(data_SWD, data_f,sizeof(data_f))== 0)
      {
    	  memcpy(c_password1,&data_S_OM[3],5);

    	    if(memcmp(d_password1, c_password1, sizeof(c_password1))  == 0 ||
    	       memcmp(d_password1, c_password1, sizeof(c_password1))  == 0)
    	    {
    	    	//dataTx_spp1(1);
    	    	WICED_BT_TRACE( "Correct Password\n");
    	    	flag_pwd=1;
    	    	data_rssi_save1[7]=flag_pwd;
        	    memcpy(data_rssi_save1 + sizeof(data_rssi), &d_password1, sizeof(d_password1));
    			WICED_BT_TRACE("1FLAG13: %B\n", data_rssi_save1);
    			numbytes13 = wiced_hal_write_nvram( WICED_NVRAM_VSID_START+13, sizeof(data_rssi_save1), &data_rssi_save1, &status13 );

    			 numbytes13 = wiced_hal_read_nvram( WICED_NVRAM_VSID_START+13, sizeof(data_rssi_save1), &data_rssi_save1, &status13 );
    			 WICED_BT_TRACE("2FLAG13: %B\n", data_rssi_save1);
    			 memcpy(d_password1,&data_rssi_save1[3],5);
    		     WICED_BT_TRACE("Password: ");
    			 wiced_hal_puart_print(d_password1);
    			 WICED_BT_TRACE( "\n");
    			 WICED_BT_TRACE_ARRAY(data_rssi_save1, 18, "BUFFER LAMPARASA2");
    	    	 //event_select_SPP();
    	    }
    	    else
    	    {
    	    	//dataTx_spp1(2);
    	    	WICED_BT_TRACE( "Incorrect Password\n");
    	    	//event_select_SPP();
    	    }
			WICED_BT_TRACE_ARRAY(d_password1, 18, "BUFFER LAMPARASA2");
			WICED_BT_TRACE_ARRAY(c_password1, 18, "BUFFER LAMPARASA3");

      }

}

void gap_transfer(void)
{
	    numbytes11 = wiced_hal_read_nvram( WICED_NVRAM_VSID_START+11, sizeof(flag11), &flag11, &status11 );
	    if(!flag11)
	    {
			WICED_BT_TRACE("FLAG11: %d\n", flag11);
			flag11 = 1;
			numbytes11 = wiced_hal_write_nvram( WICED_NVRAM_VSID_START+11, sizeof(flag11), &flag11, &status11 );
			wiced_hal_puart_print(BT_LOCAL_NAME2);
			wiced_hal_wdog_reset_system ();
	    }
	    else
	    {
	        WICED_BT_TRACE("GAP OUT FLAG11: %d\n", flag11);
	        flag11 = 0;
			numbytes11 = wiced_hal_write_nvram( WICED_NVRAM_VSID_START+11, sizeof(flag11), &flag11, &status11 );
			wiced_hal_puart_print(BT_LOCAL_NAME2);
			wiced_hal_wdog_reset_system ();
	    }
}


void gap_out_f(void)
{
    numbytes11 = wiced_hal_read_nvram( WICED_NVRAM_VSID_START+11, sizeof(flag11), &flag11, &status11 );
    if(flag11)
    {
    WICED_BT_TRACE("GAP OUT FLAG11: %d\n", flag11);
    flag11 = 0;
		numbytes11 = wiced_hal_write_nvram( WICED_NVRAM_VSID_START+11, sizeof(flag11), &flag11, &status11 );
		wiced_hal_puart_print(BT_LOCAL_NAME2);
		wiced_hal_wdog_reset_system ();
    }
}

void                     set_rssi(void)
{
	 numbytes13 = wiced_hal_read_nvram( WICED_NVRAM_VSID_START+13, sizeof(data_rssi_save1), &data_rssi_save1, &status13 );
	 WICED_BT_TRACE("RSSI SAVE: %B\n", data_rssi_save1);

	 dla=data_rssi_save1[0];
	 WICED_BT_TRACE("RSSI SLA %d\n",dla);
	 dlb=data_rssi_save1[1];
	 WICED_BT_TRACE("RSSI SLB %d\n",dlb);
	 dtv=data_rssi_save1[2];
	 WICED_BT_TRACE("RSSI STV %d\n",dtv);

	 if(dla<10){dla=80;};
	 if(dlb<10){dlb=85;};
	 if(dtv<10){dtv=83;};

	 if(flag_pwd)
	 {
	 numbytes13 = wiced_hal_read_nvram( WICED_NVRAM_VSID_START+13, sizeof(data_rssi_save1), &data_rssi_save1, &status13 );
	 WICED_BT_TRACE("2FLAG13: %B\n", data_rssi_save1);
	 memcpy(d_password1,&data_rssi_save1[3],5);
     WICED_BT_TRACE("Password: ");
	 wiced_hal_puart_print(d_password1);
	 WICED_BT_TRACE( "\n");
	 }
	 else
	 {
		 d_password1[0]=0x31;
		 d_password1[1]=0x31;
		 d_password1[2]=0x31;
		 d_password1[3]=0x31;
		 d_password1[4]=0x31;
	     WICED_BT_TRACE("Password: ");
		 wiced_hal_puart_print(d_password1);
		 WICED_BT_TRACE( "\n");
	 }

	 flag_pwd=data_rssi_save1[7];
		WICED_BT_TRACE_ARRAY(data_rssi_save1, 40, "BUFFER PASS PASS");
		//WICED_BT_TRACE_ARRAY(datam_buffer3, 18, "BUFFER LAMPARAS-3");
		 WICED_BT_TRACE("RSSI SLA2 %d\n",dla);
		 WICED_BT_TRACE("RSSI SLB2 %d\n",dlb);
		 WICED_BT_TRACE("RSSI STV2 %d\n",dtv);
}

