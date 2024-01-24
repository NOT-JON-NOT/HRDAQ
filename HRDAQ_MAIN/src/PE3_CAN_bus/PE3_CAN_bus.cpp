/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Revision # | Date       | Author      | Notes                                 *
 * ----------------------------------------------------------------------------- *
 * 1.0        | 1/22/2024  | Jon Ho      | Initial release                       *
 *            |            |             |                                       *
 *            |            |             |                                       *
 *                                                                               *
 * Notes:                                                                        *
 * - Purpose: PE3 CAN bus cpp file, holds all functions and declarations         *
 * - CAN Transciever Datasheet: https://www.ti.com/lit/ds/symlink/sn65hvd232.pdf?ts=1697949369432&ref_url=https%253A%252F%252Fwww.ti.com%252Fproduct%252FSN65HVD232
 * - CAN Controller is Teensy 4.1                                                *
 *                                                                               *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * LIBRARIES, OBJECT, AND HEADER FILE INCLUSIONS & INSTANTIATIONS                *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#include "../../ctrl_panel.h"                      //Control panel header
#include "PE3_CAN_bus.h"                           //PE3 CAN bus specific header
#include <FlexCAN_T4.h>                            //FlexCAN_T4 library for CAN bus communication
ctrl_panel CAN_ctrl_obj;                           //Control panel object
FlexCAN_T4<CAN3, RX_SIZE_256, TX_SIZE_16> CAN_obj; //FlexCAN_T4 object instantiation for CAN3, CAN bus rx line = pin 30, CAN bus tx line = pin 31. 
CAN_message_t msg;                                 //FlexCAN_T4 CAN data container

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * DATA CONTAINERS                                                               *
 * - rpb = resolution per bit (multiply converted value from HEX with this value)*
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
double canSniff_temp_rpb;                 //Temporary variable to hold rpb, resolution per bit
double rpm_value;                         //name=PE1, unit=rpm, rpb=1, range=0 to 30000, type=unsigned int 
double tps_value;                         //name=PE1, unit=%, rpb=0.1, range=0 to 100, type=signed int
double fuel_open_time_value;              //name=PE1, unit=ms, rpb=0.01, range=0 to 30, type=signed int
double ignition_angle_value;              //name=PE1, unit=deg, rpb=0.1, range=-20 to 100, type=signed int
double barometer_value;                   //name=PE2, unit=kpa, rpb=0.01, range=0 to 300, type=signed int
double map_value;                         //name=PE2, unit=kpa, rpb=0.01, range=0 to 300, type=signed int
double lambda_value;                      //name=PE2, unit=lambda, rpb=0.01, range=0 to 10, type=signed int
double analog_input_1_value;              //name=PE3, unit=volts, rpb=0.001, range=0 to 5, type=signed int
double analog_input_2_value;              //name=PE3, unit=volts, rpb=0.001, range=0 to 5, type=signed int
double analog_input_3_value;              //name=PE3, unit=volts, rpb=0.001, range=0 to 5, type=signed int
double analog_input_4_value;              //name=PE3, unit=volts, rpb=0.001, range=0 to 5, type=signed int
double analog_input_5_value;              //name=PE4, unit=volts, rpb=0.001, range=0 to 5, type=signed int
double analog_input_6_value;              //name=PE4, unit=volts, rpb=0.001, range=0 to 5, type=signed int
double analog_input_7_value;              //name=PE4, unit=volts, rpb=0.001, range=0 to 5, type=signed int
double analog_input_8_value;              //name=PE4, unit=volts, rpb=0.001, range=0 to 5, type=signed int
double freq_1_value;                      //name=PE5, unit=hz, rpb=0.2, range=0 to 6000, type=signed int
double freq_2_value;                      //name=PE5, unit=hz, rpb=0.2, range=0 to 6000, type=signed int
double freq_3_value;                      //name=PE5, unit=hz, rpb=0.2, range=0 to 6000, type=signed int
double freq_4_value;                      //name=PE5, unit=hz, rpb=0.2, range=0 to 6000, type=signed int
double battery_volt_value;                //name=PE6, unit=volts, rpb=0.01, range=0 to 22, type=signed int
double air_temp_value;                    //name=PE6, unit=fahrenheit, rpb=0.1, range=-1000 to 1000, type=signed int
double coolant_temp_value;                //name=PE6, unit=fahrenheit, rpb=0.1, range=-1000 to 1000, type=signed int
double analog_input_5_therm_value;        //name=PE7, unit=fahrenheit, rpb=0.1, range=-1000 to 1000, type=signed int
double analog_input_7_therm_value;        //name=PE7, unit=fahrenheit, rpb=0.1, range=-1000 to 1000, type=signed int
double version_major_value;               //name=PE7, unit=none, rpb=1, range=0 to 255, type=unsigned char
double version_minor_value;               //name=PE7, unit=none, rpb=1, range=0 to 255, type=unsigned char
double version_build_value;               //name=PE7, unit=none, rpb=1, range=0 to 255, type=unsigned char
double version_com_value;                 //name=PE7, unit=none, rpb=1, range=0 to 255, type=unsigned char
double rpm_rate_value;                    //name=PE8, unit=rpm/sec, rpb=1, range=-10000 to 10000, type=signed int
double tps_rate_value;                    //name=PE8, unit=%/sec, rpb=1, range=-3000 to 3000, type=signed int
double map_rate_value;                    //name=PE8, unit=kpa/sec, rpb=1, range=-3000 to 3000, type=signed int
double maf_rate_value;                    //name=PE8, unit=g/rev/sec, rpb=0.1, range=-300 to 300, type=signed int
double lambda_1_measured_value;           //name=PE9, unit=lambda, rpb=0.001, range=0 to 10, type=signed int
double lambda_2_measured_value;           //name=PE9, unit=lambda, rpb=0.001, range=0 to 10, type=signed int
double target_lambda_value;               //name=PE9, unit=lambda, rpb=0.001, range=0 to 2.5, type=signed int
double pwm_duty_cycle_1_value;            //name=PE10, unit=%, rpb=0.5, range=0 to 100, type=unsigned char
double pwm_duty_cycle_2_value;            //name=PE10, unit=%, rpb=0.5, range=0 to 100, type=unsigned char
double pwm_duty_cycle_3_value;            //name=PE10, unit=%, rpb=0.5, range=0 to 100, type=unsigned char
double pwm_duty_cycle_4_value;            //name=PE10, unit=%, rpb=0.5, range=0 to 100, type=unsigned char
double pwm_duty_cycle_5_value;            //name=PE10, unit=%, rpb=0.5, range=0 to 100, type=unsigned char
double pwm_duty_cycle_6_value;            //name=PE10, unit=%, rpb=0.5, range=0 to 100, type=unsigned char
double pwm_duty_cycle_7_value;            //name=PE10, unit=%, rpb=0.5, range=0 to 100, type=unsigned char
double pwm_duty_cycle_8_value;            //name=PE10, unit=%, rpb=0.5, range=0 to 100, type=unsigned char
double percent_slip_value;                //name=PE11, unit=%, rpb=0.1, range=-3000 to 3000, type=signed int
double driven_wheel_rate_of_change_value; //name=PE11, unit=ft/sec/sec, rpb=0.1, range=-3000 to 3000, type=signed int
double desired_value_value;               //name=PE11, unit=%, rpb=0.1, range=-3000 to 3000, type=signed int
double driven_avg_wheel_speed_value;      //name=PE12, unit=mph, rpb=0.1, range=0 to 3000, type=unsigned int
double non_driven_avg_wheel_speed_value;  //name=PE12, unit=mph, rpb=0.1, range=0 to 3000, type=unsigned int
double ignition_comp_value;               //name=PE12, unit=deg, rpb=0.1, range=0 to 100, type=signed int
double ignition_cut_percent_value;        //name=PE12, unit=%, rpb=1, range=0 to 100, type=signed int
double driven_wheel_speed_1_value;        //name=PE13, unit=ft/sec, rpb=0.1, range=0 to 3000, type=unsigned int
double driven_wheel_speed_2_value;        //name=PE13, unit=ft/sec, rpb=0.1, range=0 to 3000, type=unsigned int
double non_driven_wheel_speed_1_value;    //name=PE13, unit=ft/sec, rpb=0.1, range=0 to 3000, type=unsigned int
double non_driven_wheel_speed_2_value;    //name=PE13, unit=ft/sec, rpb=0.1, range=0 to 3000, type=unsigned int
double fuel_comp_accel_value;             //name=PE14, unit=%, rpb=0.1, range=0 to 500, type=signed int
double fuel_comp_starting_value;          //name=PE14, unit=%, rpb=0.1, range=0 to 500, type=signed int
double fuel_comp_air_temp_value;          //name=PE14, unit=%, rpb=0.1, range=0 to 500, type=signed int
double fuel_comp_coolant_temp_value;      //name=PE14, unit=%, rpb=0.1, range=0 to 500, type=signed int
double fuel_comp_barometer_value;         //name=PE15, unit=%, rpb=0.1, range=0 to 500, type=signed int
double fuel_comp_map_value;               //name=PE15, unit=%, rpb=0.1, range=0 to 500, type=signed int
double ignition_comp_air_temp_value;      //name=PE16, unit=deg, rpb=0.1, range=-20 to 20, type=signed int
double ignition_comp_coolant_temp_value;  //name=PE16, unit=deg, rpb=0.1, range=-20 to 20, type=signed int

/*
 * PE3_CAN_bus constructor
 */
PE3_CAN_bus::PE3_CAN_bus(){}

/*
 * Collects PE3 CAN bus msg data when data enters any mailbox or FIFO
 * CAN_message_t is the type of message in CAN2.0
 * Iterates by 2 for slightly faster execution time and due to 2 byte data length prevalence
 * There are 62 unique data points according to PE3 documentation
 * PE7_ID version and PE10_ID PWM readings will be not be accurate due to iteration
 */
void canSniff(const CAN_message_t &msg){
  for(int msg_index = 0; msg_index < msg.len; msg_index+=2){
    //Set data containers and canSniff_data_arr_index based on msg.id and PE3 madness
    switch(msg.id){
      case PE3_CAN_bus::PE1_ID: 
        //Set PE1 data containers and canSniff_data_arr_index
        switch(msg_index){
          case 0: 
            canSniff_temp_rpb = 1.0; 
            rpm_value = (msg.buf[msg_index+1]*256.0 + msg.buf[msg_index])*canSniff_temp_rpb; 
            break;
          case 2: 
            canSniff_temp_rpb = 0.1; 
            tps_value = (msg.buf[msg_index+1]*256.0 + msg.buf[msg_index])*canSniff_temp_rpb;
            break; 
          case 4: 
            canSniff_temp_rpb = 0.01; 
            fuel_open_time_value = (msg.buf[msg_index+1]*256.0 + msg.buf[msg_index])*canSniff_temp_rpb;
            break;
          case 6: 
            canSniff_temp_rpb = 0.1; 
            ignition_angle_value = (msg.buf[msg_index+1]*256.0 + msg.buf[msg_index])*canSniff_temp_rpb;
            break;
        }
        break;
      case PE3_CAN_bus::PE2_ID:
        //Set PE2 data containers and canSniff_data_arr_index
        switch(msg_index){
          case 0:
            canSniff_temp_rpb = 0.01;
            barometer_value = (msg.buf[msg_index+1]*256.0 + msg.buf[msg_index])*canSniff_temp_rpb;
            break;
          case 2:
            map_value = (msg.buf[msg_index+1]*256.0 + msg.buf[msg_index])*canSniff_temp_rpb;
            break;
          case 4:
            lambda_value = (msg.buf[msg_index+1]*256.0 + msg.buf[msg_index])*canSniff_temp_rpb;
            break;
        }
        break;
      case PE3_CAN_bus::PE3_ID:
        //Set PE3 data containers and canSniff_data_arr_index  
        switch(msg_index){
          case 0:
            canSniff_temp_rpb = 0.001;
            analog_input_1_value = (msg.buf[msg_index+1]*256.0 + msg.buf[msg_index])*canSniff_temp_rpb;
            break;
          case 2:
            analog_input_2_value = (msg.buf[msg_index+1]*256.0 + msg.buf[msg_index])*canSniff_temp_rpb;
            break;
          case 4:
            analog_input_3_value = (msg.buf[msg_index+1]*256.0 + msg.buf[msg_index])*canSniff_temp_rpb;
            break;
          case 6:
            analog_input_4_value = (msg.buf[msg_index+1]*256.0 + msg.buf[msg_index])*canSniff_temp_rpb;
            break;
        }
        break;
      case PE3_CAN_bus::PE4_ID:
        //Set PE4 data containers and canSniff_data_arr_index
        switch(msg_index){
          case 0:
            canSniff_temp_rpb = 0.001;
            analog_input_5_value = (msg.buf[msg_index+1]*256.0 + msg.buf[msg_index])*canSniff_temp_rpb;
            break;
          case 2:
            analog_input_6_value = (msg.buf[msg_index+1]*256.0 + msg.buf[msg_index])*canSniff_temp_rpb;
            break;
          case 4:
            analog_input_7_value = (msg.buf[msg_index+1]*256.0 + msg.buf[msg_index])*canSniff_temp_rpb;
            break;
          case 6:
            analog_input_8_value = (msg.buf[msg_index+1]*256.0 + msg.buf[msg_index])*canSniff_temp_rpb;
            break;
        }
        break;
      case PE3_CAN_bus::PE5_ID:
        //Set PE5 data containers and canSniff_data_arr_index 
        switch(msg_index){
          case 0:
            canSniff_temp_rpb = 0.2;
            freq_1_value = (msg.buf[msg_index+1]*256.0 + msg.buf[msg_index])*canSniff_temp_rpb;
            break;
          case 2:
            freq_2_value = (msg.buf[msg_index+1]*256.0 + msg.buf[msg_index])*canSniff_temp_rpb;
            break;
          case 4:
            freq_3_value = (msg.buf[msg_index+1]*256.0 + msg.buf[msg_index])*canSniff_temp_rpb;
            break;
          case 6:
            freq_4_value = (msg.buf[msg_index+1]*256.0 + msg.buf[msg_index])*canSniff_temp_rpb;
            break;
        }
        break;
      
      case PE3_CAN_bus::PE6_ID:
        //Set PE6 data containers and canSniff_data_arr_index 
        switch(msg_index){
          case 0:
            canSniff_temp_rpb = 0.01;
            battery_volt_value = (msg.buf[msg_index+1]*256.0 + msg.buf[msg_index])*canSniff_temp_rpb;
            break;
          case 2:
            canSniff_temp_rpb = 0.1;
            air_temp_value = (msg.buf[msg_index+1]*256.0 + msg.buf[msg_index])*canSniff_temp_rpb;
            break;
          case 4:
            canSniff_temp_rpb = 0.1;
            coolant_temp_value = (msg.buf[msg_index+1]*256.0 + msg.buf[msg_index])*canSniff_temp_rpb;
            break;
        }
        break;
      case PE3_CAN_bus::PE7_ID: 
        //Set PE7 data containers and canSniff_data_arr_index
        switch(msg_index){
          case 0:
            canSniff_temp_rpb = 0.1;
            analog_input_5_therm_value = (msg.buf[msg_index+1]*256.0 + msg.buf[msg_index])*canSniff_temp_rpb;
            break;
          case 2:
            canSniff_temp_rpb = 0.1;
            analog_input_7_therm_value = (msg.buf[msg_index+1]*256.0 + msg.buf[msg_index])*canSniff_temp_rpb;
            break;
          case 4:
            canSniff_temp_rpb = 1.0;
            version_major_value = msg.buf[msg_index]*canSniff_temp_rpb;
            break;
          case 5:
            canSniff_temp_rpb = 1.0;
            version_minor_value = msg.buf[msg_index]*canSniff_temp_rpb;
            break;
          case 6:
            canSniff_temp_rpb = 1.0;
            version_build_value = msg.buf[msg_index]*canSniff_temp_rpb;
            break;
          case 7:
            canSniff_temp_rpb = 1.0;
            version_com_value = msg.buf[msg_index]*canSniff_temp_rpb;
            break;
        }
        break;
      case PE3_CAN_bus::PE8_ID:
        //Set PE8 data containers and canSniff_data_arr_index 
        switch(msg_index){
          case 0:
            canSniff_temp_rpb = 1.0;
            rpm_rate_value = (msg.buf[msg_index+1]*256.0 + msg.buf[msg_index])*canSniff_temp_rpb;
            break;
          case 2:
            canSniff_temp_rpb = 1.0;
            tps_rate_value = (msg.buf[msg_index+1]*256.0 + msg.buf[msg_index])*canSniff_temp_rpb;
            break;
          case 4:
            canSniff_temp_rpb = 1.0;
            map_rate_value = (msg.buf[msg_index+1]*256.0 + msg.buf[msg_index])*canSniff_temp_rpb;
            break;
          case 6:
            canSniff_temp_rpb = 0.1;
            maf_rate_value = (msg.buf[msg_index+1]*256.0 + msg.buf[msg_index])*canSniff_temp_rpb;
            break;
        }
        break;
      case PE3_CAN_bus::PE9_ID:
        //Set PE9 data containers and canSniff_data_arr_index
        switch(msg_index){
          case 0:
            canSniff_temp_rpb = 0.001;
            lambda_1_measured_value = (msg.buf[msg_index+1]*256.0 + msg.buf[msg_index])*canSniff_temp_rpb;
            break;
          case 2:
            lambda_2_measured_value = (msg.buf[msg_index+1]*256.0 + msg.buf[msg_index])*canSniff_temp_rpb;
            break;
          case 4:
            target_lambda_value = (msg.buf[msg_index+1]*256.0 + msg.buf[msg_index])*canSniff_temp_rpb;
            break;
        }
        break;
      case PE3_CAN_bus::PE10_ID:
        //Set PE10 data containers and canSniff_data_arr_index
        switch(msg_index){
          case 0:
            canSniff_temp_rpb = 0.5;
            pwm_duty_cycle_1_value = msg.buf[msg_index]*canSniff_temp_rpb;
            break;
          case 1:
            pwm_duty_cycle_2_value = msg.buf[msg_index]*canSniff_temp_rpb;
            break;
          case 2:
            pwm_duty_cycle_3_value = msg.buf[msg_index]*canSniff_temp_rpb;
            break;
          case 3:
            pwm_duty_cycle_4_value = msg.buf[msg_index]*canSniff_temp_rpb;
            break;
          case 4:
            pwm_duty_cycle_5_value = msg.buf[msg_index]*canSniff_temp_rpb;
            break;
          case 5:
            pwm_duty_cycle_6_value = msg.buf[msg_index]*canSniff_temp_rpb;
            break;
          case 6:
            pwm_duty_cycle_7_value = msg.buf[msg_index]*canSniff_temp_rpb;
            break;
          case 7:
            pwm_duty_cycle_8_value = msg.buf[msg_index]*canSniff_temp_rpb;
            break;
        }
        break;
      case PE3_CAN_bus::PE11_ID: 
        //Set PE11 data containers and canSniff_data_arr_index
        switch(msg_index){
          case 0:
            canSniff_temp_rpb = 0.1;
            percent_slip_value = (msg.buf[msg_index+1]*256.0 + msg.buf[msg_index])*canSniff_temp_rpb;
            break;
          case 2:
            driven_wheel_rate_of_change_value = (msg.buf[msg_index+1]*256.0 + msg.buf[msg_index])*canSniff_temp_rpb;
            break;
          case 4:
            desired_value_value = (msg.buf[msg_index+1]*256.0 + msg.buf[msg_index])*canSniff_temp_rpb;
            break;
        }
        break;
      case PE3_CAN_bus::PE12_ID: 
        //Set PE12 data containers and canSniff_data_arr_index
        switch(msg_index){
          case 0:
            canSniff_temp_rpb = 0.1;
            driven_avg_wheel_speed_value = (msg.buf[msg_index+1]*256.0 + msg.buf[msg_index])*canSniff_temp_rpb;
            break;
          case 2:
            canSniff_temp_rpb = 0.1;
            non_driven_avg_wheel_speed_value = (msg.buf[msg_index+1]*256.0 + msg.buf[msg_index])*canSniff_temp_rpb;
            break;
          case 4:
            canSniff_temp_rpb = 0.1;
            ignition_comp_value = (msg.buf[msg_index+1]*256.0 + msg.buf[msg_index])*canSniff_temp_rpb;
            break;
          case 6:
            canSniff_temp_rpb = 1.0;
            ignition_cut_percent_value = (msg.buf[msg_index+1]*256.0 + msg.buf[msg_index])*canSniff_temp_rpb;
        }
        break;
      case PE3_CAN_bus::PE13_ID: 
        //Set PE13 data containers and canSniff_data_arr_index
        switch(msg_index){
          case 0:
            canSniff_temp_rpb = 0.1;
            driven_wheel_speed_1_value = (msg.buf[msg_index+1]*256.0 + msg.buf[msg_index])*canSniff_temp_rpb;
            break;
          case 2:
            driven_wheel_speed_2_value = (msg.buf[msg_index+1]*256.0 + msg.buf[msg_index])*canSniff_temp_rpb;
            break;
          case 4:
            non_driven_wheel_speed_1_value = (msg.buf[msg_index+1]*256.0 + msg.buf[msg_index])*canSniff_temp_rpb;
            break;
          case 6:
            non_driven_wheel_speed_2_value = (msg.buf[msg_index+1]*256.0 + msg.buf[msg_index])*canSniff_temp_rpb;
        }
        break;    
      case PE3_CAN_bus::PE14_ID:
        //Set PE14 data containers and canSniff_data_arr_index 
        switch(msg_index){
          case 0:
            canSniff_temp_rpb = 0.1;
            fuel_comp_accel_value = (msg.buf[msg_index+1]*256.0 + msg.buf[msg_index])*canSniff_temp_rpb;
            break;
          case 2:
            fuel_comp_starting_value = (msg.buf[msg_index+1]*256.0 + msg.buf[msg_index])*canSniff_temp_rpb;
            break;
          case 4:
            fuel_comp_air_temp_value = (msg.buf[msg_index+1]*256.0 + msg.buf[msg_index])*canSniff_temp_rpb;
            break;
          case 6:
            fuel_comp_coolant_temp_value = (msg.buf[msg_index+1]*256.0 + msg.buf[msg_index])*canSniff_temp_rpb;
        }
        break;
      case PE3_CAN_bus::PE15_ID: 
        //Set PE15 data containers and canSniff_data_arr_index
        switch(msg_index){
          case 0:
            canSniff_temp_rpb = 0.1;
            fuel_comp_barometer_value = (msg.buf[msg_index+1]*256.0 + msg.buf[msg_index])*canSniff_temp_rpb;
            break;
          case 2:
            fuel_comp_map_value = (msg.buf[msg_index+1]*256.0 + msg.buf[msg_index])*canSniff_temp_rpb;
            break;
        }
        break;
      case PE3_CAN_bus::PE16_ID: 
        //Set PE16 data containers and canSniff_data_arr_index
        switch(msg_index){
          case 0:
            canSniff_temp_rpb = 0.1;
            ignition_comp_air_temp_value = (msg.buf[msg_index+1]*256.0 + msg.buf[msg_index])*canSniff_temp_rpb;
            break;
          case 2:
            ignition_comp_coolant_temp_value = (msg.buf[msg_index+1]*256.0 + msg.buf[msg_index])*canSniff_temp_rpb;
            break;
        }
        break;
    }
  } 
}

/*
 * PE3_CAN_bus setup, includes FlexCAN & Mailbox setup
 */
void PE3_CAN_bus::begin(){
  //Begin FlexCAN_T4 object
  CAN_obj.begin(); 
  CAN_obj.setBaudRate(CAN_ctrl_obj.PE3_CAN_bus_speed);

  //Setup CAN bus mailboxes
  CAN_obj.setMaxMB(MB_max_num);
  for (int MB_num = 1; MB_num <= MB_max_num; MB_num++){
    CAN_obj.setMB((FLEXCAN_MAILBOX)MB_num,RX,EXT);
  }
  CAN_obj.setMBFilter(REJECT_ALL);
  CAN_obj.enableMBInterrupts();
  CAN_obj.onReceive(canSniff);
  for (int MB_num = 1; MB_num <= MB_max_num; MB_num++){
    int PE_arr_counter = MB_num-1;
    CAN_obj.setMBFilter((FLEXCAN_MAILBOX)MB_num, PE_ID_arr[PE_arr_counter]);
  }
}

/*
 * PE3_CAN_bus read function, it reads from CAN and organizes it
 */
void PE3_CAN_bus::read(){
  CAN_obj.events();
}

String PE3_CAN_bus::getColumnHeader(){
  String return_header = "";
  for(String PE_header : PE_header_arr){
    return_header += PE_header;
  }
  return return_header;
}

/*
 * Return functions for all the data collected from the PE3 CAN bus
 */
double PE3_CAN_bus::getRPM(){return rpm_value;}
double PE3_CAN_bus::getTPS(){return tps_value;}
double PE3_CAN_bus::getFuelOpenTime(){return fuel_open_time_value;}
double PE3_CAN_bus::getIgnitionAngle(){return ignition_angle_value;}
double PE3_CAN_bus::getBarometer(){return barometer_value;}
double PE3_CAN_bus::getMAP(){return map_value;}
double PE3_CAN_bus::getLambda(){return lambda_value;}
double PE3_CAN_bus::getAnalogInput1(){return analog_input_1_value;}
double PE3_CAN_bus::getAnalogInput2(){return analog_input_2_value;}
double PE3_CAN_bus::getAnalogInput3(){return analog_input_3_value;}
double PE3_CAN_bus::getAnalogInput4(){return analog_input_4_value;}
double PE3_CAN_bus::getAnalogInput5(){return analog_input_5_value;}
double PE3_CAN_bus::getAnalogInput6(){return analog_input_6_value;}
double PE3_CAN_bus::getAnalogInput7(){return analog_input_7_value;}
double PE3_CAN_bus::getAnalogInput8(){return analog_input_8_value;}
double PE3_CAN_bus::getFreq1(){return freq_1_value;}
double PE3_CAN_bus::getFreq2(){return freq_2_value;}
double PE3_CAN_bus::getFreq3(){return freq_3_value;}
double PE3_CAN_bus::getFreq4(){return freq_4_value;}
double PE3_CAN_bus::getBatteryVolt(){return battery_volt_value;}
double PE3_CAN_bus::getAirTemp(){return air_temp_value;}
double PE3_CAN_bus::getCoolantTemp(){return coolant_temp_value;}
double PE3_CAN_bus::getAnalogInput5Therm(){return analog_input_5_therm_value;}
double PE3_CAN_bus::getAnalogInput7Therm(){return analog_input_7_therm_value;}
double PE3_CAN_bus::getRPMRate(){return rpm_rate_value;}
double PE3_CAN_bus::getTPSRate(){return tps_rate_value;}
double PE3_CAN_bus::getMAPRate(){return map_rate_value;}
double PE3_CAN_bus::getMAFRate(){return maf_rate_value;}
double PE3_CAN_bus::getLambda1Measured(){return lambda_1_measured_value;}
double PE3_CAN_bus::getLambda2Measured(){return lambda_2_measured_value;}
double PE3_CAN_bus::getTargetLambda(){return target_lambda_value;}
double PE3_CAN_bus::getPWMDutyCycle1(){return pwm_duty_cycle_1_value;}
double PE3_CAN_bus::getPWMDutyCycle2(){return pwm_duty_cycle_2_value;}
double PE3_CAN_bus::getPWMDutyCycle3(){return pwm_duty_cycle_3_value;}
double PE3_CAN_bus::getPWMDutyCycle4(){return pwm_duty_cycle_4_value;}
double PE3_CAN_bus::getPWMDutyCycle5(){return pwm_duty_cycle_5_value;}
double PE3_CAN_bus::getPWMDutyCycle6(){return pwm_duty_cycle_6_value;}
double PE3_CAN_bus::getPWMDutyCycle7(){return pwm_duty_cycle_7_value;}
double PE3_CAN_bus::getPWMDutyCycle8(){return pwm_duty_cycle_8_value;}
double PE3_CAN_bus::getPercentSlip(){return percent_slip_value;}
double PE3_CAN_bus::getDrivenWheelRateOfChange(){return driven_wheel_rate_of_change_value;}
double PE3_CAN_bus::getDesiredValue(){return desired_value_value;}
double PE3_CAN_bus::getDrivenAvgWheelSpeed(){return driven_avg_wheel_speed_value;}
double PE3_CAN_bus::getNonDrivenAvgWheelSpeed(){return non_driven_avg_wheel_speed_value;}
double PE3_CAN_bus::getIgnitionComp(){return ignition_comp_value;}
double PE3_CAN_bus::getIgnitionCutPercent(){return ignition_cut_percent_value;}
double PE3_CAN_bus::getDrivenWheelSpeed1(){return driven_wheel_speed_1_value;}
double PE3_CAN_bus::getDrivenWheelSpeed2(){return driven_wheel_speed_2_value;}
double PE3_CAN_bus::getNonDrivenWheelSpeed1(){return non_driven_wheel_speed_1_value;}
double PE3_CAN_bus::getNonDrivenWheelSpeed2(){return non_driven_wheel_speed_2_value;}
double PE3_CAN_bus::getFuelCompAccel(){return fuel_comp_accel_value;}
double PE3_CAN_bus::getFuelCompStarting(){return fuel_comp_starting_value;}
double PE3_CAN_bus::getFuelCompAirTemp(){return fuel_comp_air_temp_value;}
double PE3_CAN_bus::getFuelCompCoolantTemp(){return fuel_comp_coolant_temp_value;}
double PE3_CAN_bus::getFuelCompBarometer(){return fuel_comp_barometer_value;}
double PE3_CAN_bus::getFuelCompMAP(){return fuel_comp_map_value;}
double PE3_CAN_bus::getIgnitionCompAirTemp(){return ignition_comp_air_temp_value;}
double PE3_CAN_bus::getIgnitionCompCoolantTemp(){return ignition_comp_coolant_temp_value;}
