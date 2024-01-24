/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Revision # | Date       | Author      | Notes                                 *
 * ----------------------------------------------------------------------------- *
 * 1.0        | 1/22/2024  | Jon Ho      | Initial release                       *
 *            |            |             |                                       *
 *            |            |             |                                       *
 *                                                                               *
 * Notes:                                                                        *
 * - PE3 CAN bus header                                                          *
 *                                                                               *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#ifndef PE3_CAN_bus_h
#define PE3_CAN_bus_h
#include "Arduino.h"

class PE3_CAN_bus{
  public:
  /* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
   * FUNCTION DECLARATIONS                                                       *
   * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
  PE3_CAN_bus();
  void begin();
  void read();
  String getColumnHeader();
  double getRPM();
  double getTPS();
  double getFuelOpenTime();
  double getIgnitionAngle();
  double getBarometer();
  double getMAP();
  double getLambda();
  double getAnalogInput1();
  double getAnalogInput2();
  double getAnalogInput3();
  double getAnalogInput4();
  double getAnalogInput5();
  double getAnalogInput6();
  double getAnalogInput7();
  double getAnalogInput8();
  double getFreq1();
  double getFreq2();
  double getFreq3();
  double getFreq4();
  double getBatteryVolt();
  double getAirTemp();
  double getCoolantTemp();
  double getAnalogInput5Therm();
  double getAnalogInput7Therm();
  double getRPMRate();
  double getTPSRate();
  double getMAPRate();
  double getMAFRate();
  double getLambda1Measured();
  double getLambda2Measured();
  double getTargetLambda();
  double getPWMDutyCycle1();
  double getPWMDutyCycle2();
  double getPWMDutyCycle3();
  double getPWMDutyCycle4();
  double getPWMDutyCycle5();
  double getPWMDutyCycle6();
  double getPWMDutyCycle7();
  double getPWMDutyCycle8();
  double getPercentSlip();
  double getDrivenWheelRateOfChange();
  double getDesiredValue();
  double getDrivenAvgWheelSpeed();
  double getNonDrivenAvgWheelSpeed();
  double getIgnitionComp();
  double getIgnitionCutPercent();
  double getDrivenWheelSpeed1();
  double getDrivenWheelSpeed2();
  double getNonDrivenWheelSpeed1();
  double getNonDrivenWheelSpeed2();
  double getFuelCompAccel();
  double getFuelCompStarting();
  double getFuelCompAirTemp();
  double getFuelCompCoolantTemp();
  double getFuelCompBarometer();
  double getFuelCompMAP();
  double getIgnitionCompAirTemp();
  double getIgnitionCompCoolantTemp();

  /* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
   * CONSTANTS                                                                   *
   * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
   const uint8_t MB_max_num = 16; //Number of mailboxes created (equal to number of PE IDs)

   const String PE1_header  = "RPM,TPS,Fuel Open Time,Ignition Angle,";
   const String PE2_header  = "Barometer,Map,Lambda,";
   const String PE3_header  = "Analog Input 1,Analog Input 2,Analog Input 3,Analog Input 4,";
   const String PE4_header  = "Analog Input 5,Analog Input 6,Analog Input 7,Analog Input 8,";
   const String PE5_header  = "Frequency 1,Frequency 2,Frequency 3,Frequency 4,";
   const String PE6_header  = "Battery Voltage,Air Temp,Coolant Temp,";
   const String PE7_header  = "Analog Input 5 Thermistor,Analog Input 7 Thermistor,Version Major,Version Minor,Version Build,Version Com,";
   const String PE8_header  = "RPM Rate,TPS Rate,MAP Rate,MAF Load Rate,";
   const String PE9_header  = "Lambda 1 Measured,Lambda 2 Measured,Target Lambda,";
   const String PE10_header = "PWM Duty Cyc 1,PWM Duty Cyc 2,PWM Duty Cyc 3,PWM Duty Cyc 4,PWM Duty Cyc 5,PWM Duty Cyc 6,PWM Duty Cyc 7,PWM Duty Cyc 8,";
   const String PE11_header = "Percent Slip,Driven Wheel RoC,Desired Value,";
   const String PE12_header = "Driven Avg Wheel Speed,Non Driven Avg Wheel Speed,Ignition Compensation,Ignition Cut Percent,";
   const String PE13_header = "Driven Wheel Speed 1,Driven Wheel Speed 2,Non Driven Wheel Speed 1,Non Driven Wheel Speed 2,";
   const String PE14_header = "Fuel Comp Accel,Fuel Comp Starting,Fuel Comp Air Temp,Fuel Comp Coolant Temp,";
   const String PE15_header = "Fuel Comp Barometer,Fuel Comp MAP,";
   const String PE16_header = "Ignition Comp Air Temp,Ignition Comp Coolant Temp,";

   static constexpr uint32_t PE1_ID    = 0x0CFFF048; //CAN ID (HEX) for RPM, TPS, FUEL OPEN TIME, IGNITION ANGLE
   static constexpr uint32_t PE2_ID    = 0x0CFFF148; //CAN ID (HEX) for BAROMETER, MAP, LAMBDA
   static constexpr uint32_t PE3_ID    = 0x0CFFF248; //CAN ID (HEX) for ANALOG INPUT #1, #2, #3, and #4
   static constexpr uint32_t PE4_ID    = 0x0CFFF348; //CAN ID (HEX) for ANALOG INPUT #5, #6, #7, and #8
   static constexpr uint32_t PE5_ID    = 0x0CFFF448; //CAN ID (HEX) for Frequency #1, #2, #3, and #4
   static constexpr uint32_t PE6_ID    = 0x0CFFF548; //CAN ID (HEX) for BATTERY VOLTAGE, AIR TEMP, COOLANT TEMP
   static constexpr uint32_t PE7_ID    = 0x0CFFF648; //CAN ID (HEX) for ANALOG INPUT #5 THERMISTOR, #7 THERMISTOR, and VERSION DATA
   static constexpr uint32_t PE8_ID    = 0x0CFFF748; //CAN ID (HEX) for RPM RATE, TPS RATE, MAP RATE, MAF LOAD RATE
   static constexpr uint32_t PE9_ID    = 0x0CFFF848; //CAN ID (HEX) for LAMBDA #1 MEASURED, LAMBDA #2 MEASURED, and TARGET LAMBDA
   static constexpr uint32_t PE10_ID   = 0x0CFFF948; //CAN ID (HEX) for PWM DUTY CYCLE #1-#8
   static constexpr uint32_t PE11_ID   = 0x0CFFFA48; //CAN ID (HEX) for PERCENT SLIP, DRIVEN WHEEL RATE OF CHANGE, and DESIRED VALUE
   static constexpr uint32_t PE12_ID   = 0x0CFFFB48; //CAN ID (HEX) for DRIVEN AVG WHEEL SPEED, NON-DRIVEN, IGNITION COMPENSATION, and IGNITION CUT PERCENT
   static constexpr uint32_t PE13_ID   = 0x0CFFFC48; //CAN ID (HEX) for DRIVEN WHEEL SPEED #1, #2, and NON-DRIVEN WHEEL SPEED #1, #2
   static constexpr uint32_t PE14_ID   = 0x0CFFFD48; //CAN ID (HEX) for FUEL COMP ACCEL, STARTING, AIR TEMP, and COOLANT TEMP
   static constexpr uint32_t PE15_ID   = 0x0CFFFE48; //CAN ID (HEX) for FUEL COMP BAROMETER and MAP
   static constexpr uint32_t PE16_ID   = 0x0CFFD048; //CAN ID (HEX) for IGNITION COMP AIR TEMP and COOLANT TEMP

   const String PE_header_arr[16] = {PE1_header, PE2_header, PE3_header, PE4_header, 
                                     PE5_header, PE6_header, PE7_header, PE8_header, 
                                     PE9_header, PE10_header, PE11_header, PE12_header, 
                                     PE13_header, PE14_header, PE15_header, PE16_header};

   const uint32_t PE_ID_arr[16] = {PE1_ID, PE2_ID, PE3_ID, PE4_ID, 
                                   PE5_ID, PE6_ID, PE7_ID, PE8_ID, 
                                   PE9_ID, PE10_ID, PE11_ID, PE12_ID, 
                                   PE13_ID, PE14_ID, PE15_ID, PE16_ID};
};
#endif