/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Revision # | Date       | Author      | Notes                                 *
 * ----------------------------------------------------------------------------- *
 * 1.0        | 1/22/2024  | Jon Ho      | Initial release                       *
 *            |            |             |                                       *
 *            |            |             |                                       *
 *                                                                               *
 * Notes:                                                                        *
 * - Purpose: BPS cpp file, holds all functions and declarations                 *
 *                                                                               *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * LIBRARIES, OBJECT, AND HEADER FILE INCLUSIONS & INSTANTIATIONS                *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#include "../../ctrl_panel.h" //Control panel header
#include "BPS.h"              //BPS specific header
ctrl_panel BPS_ctrl_obj;      //Control panel object

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * DATA CONTAINERS                                                               *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
double BPS_value; //Double to hold BPS value, in psig

/*
 * BPS constructor
 */
BPS::BPS(){}

/*
 * BPS setup function
 */
void BPS::begin(){
  if(BPS_ctrl_obj.BPS_read_enable){
    //Nothing here to initialize yet
  }
}

/*
 * BPS read function, reads from all BPS then stores in BPS_travel_value
 */
void BPS::read(){
  if(BPS_ctrl_obj.BPS_read_enable){
    BPS_value = map(analogRead(BPS_pin), 0, 1023, 0, BPS_ctrl_obj.BPS_max_pres);
  }
}

double BPS::getBPS(){return BPS_value;}
