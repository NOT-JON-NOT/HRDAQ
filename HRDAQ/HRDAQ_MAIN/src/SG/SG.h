/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Revision # | Date       | Author      | Notes                                 *
 * ----------------------------------------------------------------------------- *
 * 1.0        | 1/22/2024  | Jon Ho      | Initial release                       *
 *            |            |             |                                       *
 *            |            |             |                                       *
 *                                                                               *
 * Notes:                                                                        *
 * - SG header                                                                   *
 *                                                                               *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#ifndef SG_h
#define SG_h
#include "Arduino.h"

class SG{
  public:
  /* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
   * FUNCTION DECLARATIONS                                                       *
   * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
  SG();
  void begin();
  void read();
  double getSG1();
  double getSG2();
  double getSG3();
  double getSG4();
  double getSG5();
  double getSG6();
  double getSG7();
  double getSG8();
  double getSG9();
  double getSG10();

  /* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
   * CONSTANTS                                                                   *
   * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
  const uint8_t SG_1_pin = A7; //Analog pin of strain gauge 1
  const uint8_t SG_2_pin = A8; //Analog pin of strain gauge 2
  const uint8_t SG_3_pin = A9; //Analog pin of strain gauge 3
  const uint8_t SG_4_pin = A10; //Analog pin of strain gauge 4
  const uint8_t SG_5_pin = A11; //Analog pin of strain gauge 5
  const uint8_t SG_6_pin = A12; //Analog pin of strain gauge 6
  const uint8_t SG_7_pin = A13; //Analog pin of strain gauge 7
  const uint8_t SG_8_pin = A14; //Analog pin of strain gauge 8
  const uint8_t SG_9_pin = A15; //Analog pin of strain gauge 9
  const uint8_t SG_10_pin = A16; //Analog pin of strain gauge 10

  const uint8_t SG_pin_arr[10] = {SG_1_pin, SG_2_pin, SG_3_pin, SG_4_pin, SG_5_pin, 
                                   SG_6_pin, SG_7_pin, SG_8_pin, SG_9_pin, SG_10_pin};
};
#endif