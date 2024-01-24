/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Revision # | Date       | Author      | Notes                                 *
 * ----------------------------------------------------------------------------- *
 * 1.0        | 1/22/2024  | Jon Ho      | Initial release                       *
 *            |            |             |                                       *
 *            |            |             |                                       *
 *                                                                               *
 * Notes:                                                                        *
 * - Purpose: IMU cpp file, holds all functions and declarations                 *
 *                                                                               *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * LIBRARIES, OBJECT, AND HEADER FILE INCLUSIONS & INSTANTIATIONS                *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#include "../../ctrl_panel.h" //Control panel header
#include "IMU.h"              //IMU specific header
ctrl_panel IMU_ctrl_obj;      //Control panel object

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * DATA CONTAINERS                                                               *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
double IMU_X_value; //Double to hold x-axis value of IMU
double IMU_Y_value; //Double to hold y-axis value of IMU

/*
 * IMU constructor
 */
IMU::IMU(){}

/*
 * IMU setup function
 */
void IMU::begin(){
  if(IMU_ctrl_obj.IMU_read_enable){

  }
}

/*
 * IMU read function, reads from each axis of IMU then stores
 */
void IMU::read(){
  if(IMU_ctrl_obj.IMU_read_enable){
    IMU_X_value = map(analogRead(IMU_X_pin), 0, 1023, IMU_min_XY_tilt, IMU_max_XY_tilt);
    IMU_Y_value = map(analogRead(IMU_Y_pin), 0, 1023, IMU_min_XY_tilt, IMU_max_XY_tilt);
  }
}

double IMU::getIMUX(){return IMU_X_value;}
double IMU::getIMUY(){return IMU_Y_value;}
