#include <EEPROM.h>

/*
 * Initializes address 0 of EEPROM in HRDAQ. Should only be run once, after assembly
 * address 0 will be used for the naming of each csv file in the sd card
 */
void setup(){EEPROM.write(0, 1000);}
void loop(){}
