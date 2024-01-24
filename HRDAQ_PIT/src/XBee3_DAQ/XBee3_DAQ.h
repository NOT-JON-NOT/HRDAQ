/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Revision # | Date       | Author      | Notes                                 *
 * ----------------------------------------------------------------------------- *
 * 1.0        | 1/22/2024  | Jon Ho      | Initial release                       *
 *            |            |             |                                       *
 *            |            |             |                                       *
 *                                                                               *
 * Notes:                                                                        *
 * - XBee3_DAQ header                                                            *
 *                                                                               *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#ifndef XBee3_DAQ_h
#define XBee3_DAQ_h
#include "Arduino.h"

class XBee3_DAQ{
  public:
  /* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
   * FUNCTION DECLARATIONS                                                       *
   * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
  XBee3_DAQ();
  void begin();
  void read();
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
  double getBPS();
  double getIMUX();
  double getIMUY();
  double getLPSFL();
  double getLPSFR();
  double getLPSBL();
  double getLPSBR();
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
};
#endif