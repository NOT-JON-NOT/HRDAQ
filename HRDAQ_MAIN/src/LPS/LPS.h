/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Revision # | Date       | Author      | Notes                                 *
 * ----------------------------------------------------------------------------- *
 * 1.0        | 1/22/2024  | Jon Ho      | Initial release                       *
 *            |            |             |                                       *
 *            |            |             |                                       *
 *                                                                               *
 * Notes:                                                                        *
 * - LPS header                                                                  *
 *                                                                               *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#ifndef LPS_h
#define LPS_h
#include "Arduino.h"

class LPS{
  public:
  /* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
   * FUNCTION DECLARATIONS                                                       *
   * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
  LPS();
  void begin();
  void read();
  double getLPSFL();
  double getLPSFR();
  double getLPSBL();
  double getLPSBR();

  /* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
   * CONSTANTS                                                                   *
   * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
  const uint8_t LPS_FL_pin = A0; //Analog pin of front left suspension LPS
  const uint8_t LPS_FR_pin = A1; //Analog pin of front right suspension LPS
  const uint8_t LPS_BL_pin = A2; //Analog pin of back left suspension LPS
  const uint8_t LPS_BR_pin = A3; //Analog pin of back right suspension LPS

  const uint8_t LPS_pin_arr[4] = {LPS_FL_pin, LPS_FR_pin, LPS_BL_pin, LPS_BR_pin};
};
#endif