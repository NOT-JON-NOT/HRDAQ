/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Revision # | Date       | Author      | Notes                                 *
 * ----------------------------------------------------------------------------- *
 * 1.0        | 1/22/2024  | Jon Ho      | Initial release                       *
 *            |            |             |                                       *
 *            |            |             |                                       *
 *                                                                               *
 * Notes:                                                                        *
 * - Purpose: LPS cpp file, holds all functions and declarations                 *
 *                                                                               *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * LIBRARIES, OBJECT, AND HEADER FILE INCLUSIONS & INSTANTIATIONS                *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#include "../../ctrl_panel.h" //Control panel header
#include "LPS.h"              //LPS specific header
ctrl_panel LPS_ctrl_obj;      //Control panel object

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * DATA CONTAINERS                                                               *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
double LPS_init_value_arr[4];   //Array to hold LPS initial values, ordered FL, FR, BL, BR, in mm
double LPS_travel_value_arr[4]; //Array to hold LPS travel values, ordered FL, FR, BL, BR, in mm

/*
 * LPS constructor
 */
LPS::LPS(){}

/*
 * LPS setup function, reads initial LPS values
 */
void LPS::begin(){
  if(LPS_ctrl_obj.LPS_read_enable){
    for(uint8_t i = 0; i<sizeof(LPS_pin_arr)-1; i++){
      LPS_init_value_arr[i] = analogRead(LPS_pin_arr[i]);
    }
  }
}

/*
 * LPS read function, reads from all LPS then stores in LPS_travel_value array
 */
void LPS::read(){
  if(LPS_ctrl_obj.LPS_read_enable){
    for(uint8_t i=0; i<sizeof(LPS_pin_arr); i++){
      LPS_travel_value_arr[i] = analogRead(LPS_pin_arr[i]) - LPS_init_value_arr[i];
      LPS_travel_value_arr[i] = map(LPS_travel_value_arr[i], 0, 1023, 0, LPS_ctrl_obj.LPS_elec_stroke);
    }
  }
}

double LPS::getLPSFL(){return LPS_travel_value_arr[0];}
double LPS::getLPSFR(){return LPS_travel_value_arr[1];}
double LPS::getLPSBL(){return LPS_travel_value_arr[2];}
double LPS::getLPSBR(){return LPS_travel_value_arr[3];}
