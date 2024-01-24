/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Revision # | Date       | Author      | Notes                                 *
 * ----------------------------------------------------------------------------- *
 * 1.0        | 1/22/2024  | Jon Ho      | Initial release                       *
 *            |            |             |                                       *
 *            |            |             |                                       *
 *                                                                               *
 * Notes:                                                                        *
 * - Purpose: Status lights cpp file, holds all functions and declarations       *
 *                                                                               *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * LIBRARIES, OBJECT, AND HEADER FILE INCLUSIONS & INSTANTIATIONS                *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#include "../../ctrl_panel.h"        //Control panel header
#include "Status_lights.h"           //Status lights specific header
#include <Adafruit_NeoPixel.h>       //Adafruit neopixel library
ctrl_panel status_lights_ctrl_obj;   //Control panel object
const uint8_t status_lights_pin = 6; //Pin of Status lights neopixels
Adafruit_NeoPixel status_strip = Adafruit_NeoPixel(status_lights_ctrl_obj.status_lights_num, status_lights_pin, NEO_GRB + NEO_KHZ800);

/*
 * status_lights constructor
 */
Status_lights::Status_lights(){}

/*
 * status_lights setup function
 */
void Status_lights::begin(){
  if(status_lights_ctrl_obj.status_lights_enable){
    status_strip.begin();
    status_strip.setBrightness(status_lights_ctrl_obj.status_lights_brightness);
    pinMode(FLS_pin, INPUT);
  }
}

/*
 * status_lights set lights function dependent on battery voltage
 */
void Status_lights::setBattLight(uint8_t battery_voltage){
  if(status_lights_ctrl_obj.status_lights_enable && battery_voltage < status_lights_ctrl_obj.battery_limit){
    status_strip.setPixelColor(0, status_strip.Color(255, 165, 0)); //Set to orange
  }
  else{
    status_strip.setPixelColor(0, status_strip.Color(0, 0, 0)); //Set off
  }
  status_strip.show();
}

/*
 * status_lights set lights function dependent on coolant temperature
 */
void Status_lights::setCoolLight(uint8_t coolant_temperature){
  if(status_lights_ctrl_obj.status_lights_enable && coolant_temperature > status_lights_ctrl_obj.coolant_temp_limit){
    status_strip.setPixelColor(1, status_strip.Color(255, 165, 0)); //Set to orange
  }
  else{
    status_strip.setPixelColor(1, status_strip.Color(0, 0, 0)); //Set off
  }
  status_strip.show();
}

/*
 * status_lights set lights function dependent on air temperature
 */
void Status_lights::setAirLight(uint8_t air_temperature){
  if(status_lights_ctrl_obj.status_lights_enable && air_temperature > status_lights_ctrl_obj.air_temp_limit){
    status_strip.setPixelColor(2, status_strip.Color(255, 165, 0)); //Set to orange
  }
  else{
    status_strip.setPixelColor(2, status_strip.Color(0, 0, 0)); //Set off
  }
  status_strip.show();
}

/*
 * status_lights set lights function dependent on FLS
 */
void Status_lights::setFLSLight(){
  if(status_lights_ctrl_obj.status_lights_enable && status_lights_ctrl_obj.FLS_read_enable && !digitalRead(FLS_pin)){
    status_strip.setPixelColor(3, status_strip.Color(255, 165, 0)); //Set to orange
  }
}
