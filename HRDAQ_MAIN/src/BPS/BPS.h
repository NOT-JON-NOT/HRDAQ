/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Revision # | Date       | Author      | Notes                                 *
 * ----------------------------------------------------------------------------- *
 * 1.0        | 1/22/2024  | Jon Ho      | Initial release                       *
 *            |            |             |                                       *
 *            |            |             |                                       *
 *                                                                               *
 * Notes:                                                                        *
 * - BPS header                                                                  *
 *                                                                               *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#ifndef BPS_h
#define BPS_h
#include "Arduino.h"

class BPS{
  public:
  /* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
   * FUNCTION DECLARATIONS                                                       *
   * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
  BPS();
  void begin();
  void read();
  double getBPS();

  /* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
   * CONSTANTS                                                                   *
   * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
  const uint8_t BPS_pin = A4; //Analog pin BPS
};
#endif