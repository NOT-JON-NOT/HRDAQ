/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Revision # | Date       | Author      | Notes                                 *
 * ----------------------------------------------------------------------------- *
 * 1.0        | 1/22/2024  | Jon Ho      | Initial release                       *
 *            |            |             |                                       *
 *            |            |             |                                       *
 *                                                                               *
 * Notes:                                                                        *
 * - Purpose: SG cpp file, holds all functions and declarations                  *
 * - Referernces:                                                                *
 *   - https://www.omega.co.uk/techref/pdf/straingage_measurement.pdf            *
 *   - https://www.omega.com/en-us/resources/strain-gauge-technical-data         *
 * - Equation 1: Vout/Vin = (R3/(R3+R_SG) - R2/(R1+R2))                          *
 * - Equation 2: Vr = (Vout/Vin)strained - (Vout/Vin)unstrained, (Vout/Vin)unstrained = 0 ideally
 * - Equation 3: Strain = -4*Vr/(Gauge_Factor*(1+2*Vr))                          *
 *                                                                               *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * LIBRARIES, OBJECT, AND HEADER FILE INCLUSIONS & INSTANTIATIONS                *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#include "../../ctrl_panel.h" //Control panel header
#include "SG.h"               //SG specific header
ctrl_panel SG_ctrl_obj;       //Control panel object

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * DATA CONTAINERS                                                               *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
double SG_value_arr[10]; //Array to hold SG values, ordered from 1 to 10

/*
 * SG constructor
 */
SG::SG(){}

/*
 * SG setup function
 */
void SG::begin(){
  if(SG_ctrl_obj.SG_read_enable){
    //Nothing here to initialize yet
  }
}

/*
 * SG read function, reads from all SG then stores in SG_value array
 */
void SG::read(){
  if(SG_ctrl_obj.SG_read_enable){
    for(uint8_t i=0; i<sizeof(SG_pin_arr); i++){
      SG_value_arr[i] = map(analogRead(SG_pin_arr[i]), 0, 1023, 0, SG_ctrl_obj.SG_resistance);
    }
  }
}

double SG::getSG1(){return SG_value_arr[0];}
double SG::getSG2(){return SG_value_arr[1];}
double SG::getSG3(){return SG_value_arr[2];}
double SG::getSG4(){return SG_value_arr[3];}
double SG::getSG5(){return SG_value_arr[4];}
double SG::getSG6(){return SG_value_arr[5];}
double SG::getSG7(){return SG_value_arr[6];}
double SG::getSG8(){return SG_value_arr[7];}
double SG::getSG9(){return SG_value_arr[8];}
double SG::getSG10(){return SG_value_arr[9];}
