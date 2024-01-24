/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Revision # | Date       | Author      | Notes                                 *
 * ----------------------------------------------------------------------------- *
 * 1.0        | 1/22/2024  | Jon Ho      | Initial release                       *
 *            |            |             |                                       *
 *            |            |             |                                       *
 *                                                                               *
 * Notes:                                                                        *
 * - Purpose: RPM lights cpp file, holds all functions and declarations          *
 *                                                                               *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * LIBRARIES, OBJECT, AND HEADER FILE INCLUSIONS & INSTANTIATIONS                *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#include "../../ctrl_panel.h"     //Control panel header
#include "RPM_lights.h"           //RPM lights specific header
#include <Adafruit_NeoPixel.h>    //Adafruit neopixel library
ctrl_panel RPM_lights_ctrl_obj;   //Control panel object
const uint8_t RPM_lights_pin = 9; //Pin of RPM lights neopixels
Adafruit_NeoPixel RPM_strip = Adafruit_NeoPixel(RPM_lights_ctrl_obj.RPM_lights_num, RPM_lights_pin, NEO_GRB + NEO_KHZ800);

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * DATA CONTAINERS                                                               *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
unsigned long current_blink_time; //Holds RPM lights blink timing variable in ms
unsigned long init_blink_time;    //Holds RPM lights initial time blink in ms

/*
 * RPM_lights constructor
 */
RPM_lights::RPM_lights(){}

/*
 * RPM_lights setup function
 */
void RPM_lights::begin(){
  if(RPM_lights_ctrl_obj.RPM_lights_enable){
    RPM_strip.begin();
    RPM_strip.setBrightness(RPM_lights_ctrl_obj.RPM_lights_brightness);
  }
}


uint32_t getColor(uint16_t RPM){
  if(RPM < RPM_lights_ctrl_obj.RPM_lights_green_limit){
    return RPM_strip.Color(0, 255, 0); //Returns green light
  }
  else if(RPM < RPM_lights_ctrl_obj.RPM_lights_yellow_limit){
    return RPM_strip.Color(255, 255, 0); //Returns yellow light
  }
  else{
    return RPM_strip.Color(255, 0, 0); //Returns red light
  }
}

void blink(){
  current_blink_time = millis();
  if(current_blink_time - init_blink_time >= RPM_lights_ctrl_obj.RPM_lights_interval){
    init_blink_time = current_blink_time;

    static bool blink_state = false;

    if(blink_state){
      RPM_strip.fill(RPM_strip.Color(0, 0, 0)); //Turn off lights
    }
    else{
      RPM_strip.fill(RPM_strip.Color(255, 0, 0)); //Set all RPM lights to red
    }

    blink_state = !blink_state;
    RPM_strip.show();
  }
}

/*
 * RPM_lights set lights function
 */
void RPM_lights::setRPMLights(uint16_t RPM){
  if(RPM_lights_ctrl_obj.RPM_lights_enable){
    if(RPM > RPM_lights_ctrl_obj.RPM_MAX){
      blink();
    }
    else{
      uint8_t pixel_max = RPM_lights_ctrl_obj.RPM_lights_num;
      //Map the number of neopixels to RPM
      uint8_t pixel_num = map(RPM, 0, RPM_lights_ctrl_obj.RPM_MAX, 0, pixel_max);

      //Display RPM lights with gradient
      for(int i = 0; i < pixel_max; i++){
        uint8_t pixel_distance = min(i, pixel_max - 1 - i);
        if(pixel_distance <= pixel_num/2){
          uint32_t pixel_color = getColor(RPM);
          RPM_strip.setPixelColor(i, pixel_color);
        }
        else{
          RPM_strip.setPixelColor(i, RPM_strip.Color(0, 0, 0));
        }
      }
      RPM_strip.show();
    }
  }  
}
