/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Revision # | Date       | Author      | Notes                                 *
 * ----------------------------------------------------------------------------- *
 * 1.0        | 1/22/2024  | Jon Ho      | Initial release                       *
 *            |            |             |                                       *
 *            |            |             |                                       *
 *                                                                               *
 * Notes:                                                                        *
 * - Purpose: DAQ Control Panel                                                  *
 *                                                                               *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#ifndef ctrl_panel_h
#define ctrl_panel_h
#include "Arduino.h"

class ctrl_panel{
  public:
    //General 
    uint32_t serial_speed = 9600;            //Serial monitor speed
    bool serial_enable = true;               //If serial monitor is turned on
    bool SD_write_enable = true;             //If write to SD card

    //PE3 CAN bus
    uint32_t PE3_CAN_bus_speed = 250000;     //Sets CAN bus speed, 1000000 = 1000kB/s (kB/S SET IN PE3 MONITOR SOFTWARE)

    //Linear position sensor
    bool LPS_read_enable = true;             //Sets if read linear position sensor
    double LPS_elec_stroke = 75;             //Effective electrical length of the LPS taken from datasheet in mm

    //XBee transmitter
    bool XBee3_DAQ_enable = true;            //Sets if XBee send is enabled

    //Strain gauge
    bool SG_read_enable = true;              //Sets if read strain gauge
    uint8_t SG_gauge_factor = 2;             //Sets gauge factor of strain gauge, usually 2 or specified by manufacturer
    uint8_t SG_resistance = 120;             //Sets strain gauge resistance specified by manufacturer

    //Fuel level sensor 
    bool FLS_read_enable = true;             //Sets if read fuel level sensor

    //Brake pressure sensor
    bool BPS_read_enable = true;             //Sets if read brake pressure sensor
    uint16_t BPS_max_pres = 3000;            //Maximum presure of the BPS taken from datasheet in psig

    //Inertial measurement unit
    bool IMU_read_enable = true;             //Sets if read inertial measurement unit

    //RPM lights
    bool RPM_lights_enable = true;           //Sets if RPM lights on
    uint8_t RPM_lights_num = 10;             //Number of RPM lights
    uint16_t RPM_MAX = 8000;                 //Maximum RPM, triggers blinking, typically redline
    unsigned long RPM_lights_interval;       //Blink interval of RPM_lights
    uint8_t RPM_lights_brightness = 255;     //RPM lights brightness, 0-255, low to high
    uint16_t RPM_lights_green_limit = 3000;  //RPM lights RPM limit for green lights
    uint16_t RPM_lights_yellow_limit = 7000; //RPM lights RPM limit for yellow lights

    //Status lights
    bool status_lights_enable = true;        //Sets if battery, air temp, and coolant temp status lights on
    uint8_t status_lights_num = 4;           //Number of status lights
    uint8_t status_lights_brightness = 100;  //RPM lights brightness, 0-255, low to high
    uint8_t battery_limit = 12;              //Battery limit; if less than this value, status light on
    uint8_t coolant_temp_limit = 12;         //Coolant temp limit; if greater than this value, status light on
    uint8_t air_temp_limit = 12;             //Air temp limit; if greater than this value, status light on
    
};
#endif
