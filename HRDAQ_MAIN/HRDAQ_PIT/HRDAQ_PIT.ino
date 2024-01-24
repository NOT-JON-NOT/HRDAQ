/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * HARTFORD RACING FSAE                                                          *
 * Author: Jon Ho, CompE & EE 24'                                                *
 * Repo: https://github.com/N0T-J0N/HRDAQ                                        *
 *                                                                               *
 * Revision # | Date       | Author      | Notes                                 *
 * ----------------------------------------------------------------------------- *
 * 1.0        | 1/22/2024  | Jon Ho      | Initial release                       *
 *            |            |             |                                       *
 *            |            |             |                                       *
 *            |            |             |                                       *
 *                                                                               *
 *                                                                               *
 * Required libraries:                                                           *
 * - https://www.pjrc.com/teensy/td_download.html (Teensyduino)                  *
 *                                                                               *
 * Notes:                                                                        *
 * - Purpose: Serves as "main" and "subscriber" to DAQ onboard HR24              *
 *                                                                               *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * LIBRARIES, OBJECT, AND HEADER FILE INCLUSIONS & INSTANTIATIONS                *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#include "src/XBee3_DAQ/XBee3_DAQ.h" //Custom XBee3 library
#include "EEPROM.h"                  //Arduino EEPROM library for memory after shutdown
XBee3_DAQ XBee3_DAQ_obj;             //XBee3 object instantiation

/*
 * XBee3_DAQ setup function, initializes XBee3_DAQ baud rate
 * XBee3 baud rate must be the same as XBee module baud rate
 */
void setup(){
  XBee3_DAQ_obj.begin();
}

void loop(){
  XBee3_DAQ_obj.read();
}
