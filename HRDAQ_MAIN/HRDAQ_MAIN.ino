/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * HARTFORD RACING FSAE                                                          *
 * Author: Jon Ho, CompE & EE 24'                                                *
 * Repo: https://github.com/N0T-J0N/HRDAQ                                        *
 *                                                                               *
 * Revision # | Date       | Author      | Notes                                 *
 * ----------------------------------------------------------------------------- *
 * 1.0        | 1/22/2024  | Jon Ho      | Initial release                       *
 *            |            |             |                                       *
 *            |            |             |                                       *
 *            |            |             |                                       *
 *                                                                               *
 * Abv Name        | QTY | Full Name                 | Manufacturer Part Number  *
 * ----------------------------------------------------------------------------- *
 * LPS             |  4  | Linear Position Sensor    | PZ12-S-0075-L             *
 * BPS             |  1  | Brake Pressure Sensor     | SPT25-20-3000A            *
 * IMU             |  1  | Inertial Measurement Unit | GIB-XY-085-V-2A           *
 * XBEE3           |  2  | Digi XBee 3 Module RP-SMA | Digi XBee 3 Module RP-SMA *
 * NeoPixels       |  15 | Adafruit NeoPixels        | NeoPixel 5050 RGB LED     *
 * SG              |  10 | (Linear) Strain Gauge     | SGD-10/120-LY11           *
 * FLS             |  1  | Fuel Level Sensor         | N/A                       *
 *                 |     |                           |                           *
 *                                                                               *
 * Required libraries:                                                           *
 * - https://www.pjrc.com/teensy/td_download.html (Teensyduino)                  *
 *                                                                               *
 * Notes:                                                                        *
 * - Purpose: Serves as "main"                                                   *
 * - CAN Transciever Datasheet: https://www.ti.com/lit/ds/symlink/sn65hvd232.pdf?ts=1697949369432&ref_url=https%253A%252F%252Fwww.ti.com%252Fproduct%252FSN65HVD232
 * - LPS Datasheet: https://cdn.automationdirect.com/static/specs/gefranpz12linpots.pdf
 *  - Approximately 0.5 mm measurement error                                     *
 * - BPS Datasheet: https://cdn.automationdirect.com/static/specs/prosensespt25transmitters.pdf
 *  - Check datasheet for wiring and load resistance calculation: R_L = (V_L - 9VDC)/0.022A, if V_L = 12V, R_L = 137 Ohms
 * - IMU Datasheet: https://cdn.automationdirect.com/static/specs/gibinclinationsensor.pdf
 * - XBee 3 Datasheet: https://www.digi.com/resources/documentation/digidocs/pdfs/90001543.pdf
 * - Adafruit NeoPixels: https://www.adafruit.com/product/1655                   *
 * - General Strain Gauge Usage: https://www.omega.co.uk/techref/pdf/straingage_measurement.pdf
 * - Omega Strain Gauge Datasheet: https://assets.omega.com/pdf/test-and-measurement-equipment/strain-gauges/SGD_LINEAR1-AXIS.pdf
 *                                                                               *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * LIBRARIES, OBJECT, AND HEADER FILE INCLUSIONS & INSTANTIATIONS                *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#include "ctrl_panel.h"                      //Control panel header
#include <SD.h>                              //SD card library for SD card read/write
#include <SPI.h>                             //SPI library for SPI & SD card communication 
#include "src/PE3_CAN_bus/PE3_CAN_bus.h"     //Custom PE3 CAN bus library
#include "src/LPS/LPS.h"                     //Custom linear position sensor library
#include "src/BPS/BPS.h"                     //Custom brake pressure sensor library
#include "src/IMU/IMU.h"                     //Custom inertial measurement unit library
#include "src/RPM_lights/RPM_lights.h"       //Custom RPM lights library
#include "src/Status_lights/Status_lights.h" //Custom status lights library
#include "src/SG/SG.h"                       //Custom strain gauge library
#include "src/XBee3_DAQ/XBee3_DAQ.h"         //Custom XBee3 library
#include "EEPROM.h"                          //Arduino EEPROM library for memory after shutdown
PE3_CAN_bus PE3_CAN_bus_obj;                 //PE3 CAN bus object instantiation
LPS LPS_obj;                                 //LPS object instantiation
BPS BPS_obj;                                 //BPS object instantiation
IMU IMU_obj;                                 //IMU object instantiation
RPM_lights RPM_lights_obj;                   //RPM lights object instantiation
Status_lights Status_lights_obj;             //Status lights object instantiation
SG SG_obj;                                   //Strain gauge object instantiation
XBee3_DAQ XBee3_DAQ_obj;                     //XBee3 object instantiation
ctrl_panel ctrl_obj;                         //Control panel object instantiation
File SD_file;                                //SD card object instantiation

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * DATA CONTAINERS                                                               *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
String SD_data          = "";   //String to hold data to write to SD card
String SD_column_header = "";   //String to hold column headers of data
String SD_filename      = "";   //String to hold unique filename of SD data file
uint32_t SD_count;              //Unsigned int to hold SD count from EEPROM
bool DAQ_reset_trigger  = true; //Bool to trigger a new DAW file/test run
unsigned long DAQ_init_time;    //Unsigned long to hold DAQ initialization time
unsigned long CAN_read_time;    //Unsigned long to hold CAN individual message read time
unsigned long LPS_read_time;    //Unsigned long to hold LPS individual message read time
unsigned long BPS_read_time;    //Unsigned long to hold BPS individual message read time
unsigned long IMU_read_time;    //Unsigned long to hold IMU individual message read time
unsigned long SG_read_time;     //Unsigned long to hold SG individual message read time

/*
 * Starts a new DAQ file due to trigger/new test run
 */
void makeDAQFile(){
  //Setup SD card column headers
  SD_column_header += "Time," + PE3_CAN_bus_obj.getColumnHeader();

  //Generates unique ID using SD count from EEPROM, then increments
  SD_count = EEPROM.read(0);
  SD_filename = "DAQ_DATALOG_" + String(SD_count) + ".csv";
  EEPROM.write(0, SD_count++);

  //Write column headers to SD card and setup SD card file name
  SD_file = SD.open(SD_filename.c_str(), FILE_WRITE);
  SD_file.println(SD_column_header);
  SD_file.close();
}

/*
 * Used for all instantiations, setup time does not have to be optimized
 */
void setup(){
  //Setup serial communication
  if(ctrl_obj.serial_enable){
    Serial.begin(ctrl_obj.serial_speed);
    while(!Serial){}
  }

  //Setup SD card
  if(!SD.begin(BUILTIN_SDCARD)){
    ctrl_obj.SD_write_enable = false;
    Serial.println("SD CARD FAILED TO INITIALIZE");
  }

  PE3_CAN_bus_obj.begin(); //Setup PE3 CAN bus comunication
  LPS_obj.begin(); //Setup LPS
  BPS_obj.begin(); //Setup BPS
  IMU_obj.begin(); //Setup IMU  
  SG_obj.begin(); //Setup SG
  RPM_lights_obj.begin(); //Setup RPM lights
  Status_lights_obj.begin(); //Setup Status lights
  XBee3_DAQ_obj.begin(); //Setup XBee3
}

/*
 * Looks for events
 */
void loop(){
  //Trigger new DAQ file
  if(DAQ_reset_trigger){
    DAQ_reset_trigger = false;
    DAQ_init_time = millis();
    makeDAQFile();
  }

  //Read from PE3 CAN bus
  CAN_read_time = millis() - DAQ_init_time;
  PE3_CAN_bus_obj.read();

  //Read from LPS
  LPS_read_time = millis() - DAQ_init_time;
  LPS_obj.read();

  //Read from BPS
  BPS_read_time = millis() - DAQ_init_time;
  BPS_obj.read();

  //Read from IMU
  IMU_read_time = millis() - DAQ_init_time;
  IMU_obj.read();

  //Read from all SG
  SG_read_time = millis() - DAQ_init_time;
  SG_obj.read();

  //Output RPM & Status lights
  RPM_lights_obj.setRPMLights(PE3_CAN_bus_obj.getRPM());
  Status_lights_obj.setBattLight(PE3_CAN_bus_obj.getBatteryVolt());
  Status_lights_obj.setCoolLight(PE3_CAN_bus_obj.getCoolantTemp());
  Status_lights_obj.setAirLight(PE3_CAN_bus_obj.getAirTemp());
  Status_lights_obj.setFLSLight();


/*
  //Construct main SD data String from SD_data_arr
  SD_data_arr[canSniff_data_arr_index] = SD_temp_data;
  SD_main_data += String(canSniff_read_time) + ",";
  for(String SD_data : SD_data_arr){
    SD_main_data += SD_data;
  }
  //Print SD data onto SD card
  if(SD_write && !canSniff_init_trigger){//TEMPORARYTEMPORARY TEMPORARYTEMPORARY TEMPORARYTEMPORARY TEMPORARYTEMPORARY TEMPORARYTEMPORARY
    SD_file = SD.open(SD_filename.c_str(), FILE_WRITE);
    SD_file.println(SD_main_data);
    SD_file.close();
  }
*/
}
