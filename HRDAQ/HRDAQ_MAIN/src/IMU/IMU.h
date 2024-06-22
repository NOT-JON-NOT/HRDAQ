/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Revision # | Date       | Author      | Notes                                 *
 * ----------------------------------------------------------------------------- *
 * 1.0        | 1/22/2024  | Jon Ho      | Initial release                       *
 *            |            |             |                                       *
 *            |            |             |                                       *
 *                                                                               *
 * Notes:                                                                        *
 * - IMU header                                                                  *
 *                                                                               *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#ifndef IMU_h
#define IMU_h
#include "Arduino.h"

class IMU{
  public:
  /* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
   * FUNCTION DECLARATIONS                                                       *
   * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
  IMU();
  void begin();
  void read();
  double getIMUX();
  double getIMUY();

  /* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
   * CONSTANTS                                                                   *
   * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
  const uint8_t IMU_X_pin = A5;    //Analog pin IMU for x-axis
  const uint8_t IMU_Y_pin = A6;    //Analog pin IMU for y-axis
  const int IMU_min_XY_tilt = -45; //Minimum tilt angle for IMU in degrees
  const int IMU_max_XY_tilt = 45;  //Maximum tilt angle for IMU in degrees
};
#endif