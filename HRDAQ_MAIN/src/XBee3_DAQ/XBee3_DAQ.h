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
  void sendRPM(String msg);
  void sendTPS(String msg);
  void sendFuelOpenTime(String msg);
  void sendIgnitionAngle(String msg);
  void sendBarometer(String msg);
  void sendMAP(String msg);
  void sendLambda(String msg);
  void sendAnalogInput1(String msg);
  void sendAnalogInput2(String msg);
  void sendAnalogInput3(String msg);
  void sendAnalogInput4(String msg);
  void sendAnalogInput5(String msg);
  void sendAnalogInput6(String msg);
  void sendAnalogInput7(String msg);
  void sendAnalogInput8(String msg);
  void sendFreq1(String msg);
  void sendFreq2(String msg);
  void sendFreq3(String msg);
  void sendFreq4(String msg);
  void sendBatteryVolt(String msg);
  void sendAirTemp(String msg);
  void sendCoolantTemp(String msg);
  void sendAnalogInput5Therm(String msg);
  void sendAnalogInput7Therm(String msg);
  void sendRPMRate(String msg);
  void sendTPSRate(String msg);
  void sendMAPRate(String msg);
  void sendMAFRate(String msg);
  void sendLambda1Measured(String msg);
  void sendLambda2Measured(String msg);
  void sendTargetLambda(String msg);
  void sendPWMDutyCycle1(String msg);
  void sendPWMDutyCycle2(String msg);
  void sendPWMDutyCycle3(String msg);
  void sendPWMDutyCycle4(String msg);
  void sendPWMDutyCycle5(String msg);
  void sendPWMDutyCycle6(String msg);
  void sendPWMDutyCycle7(String msg);
  void sendPWMDutyCycle8(String msg);
  void sendPercentSlip(String msg);
  void sendDrivenWheelRateOfChange(String msg);
  void sendDesiredValue(String msg);
  void sendDrivenAvgWheelSpeed(String msg);
  void sendNonDrivenAvgWheelSpeed(String msg);
  void sendIgnitionComp(String msg);
  void sendIgnitionCutPercent(String msg);
  void sendDrivenWheelSpeed1(String msg);
  void sendDrivenWheelSpeed2(String msg);
  void sendNonDrivenWheelSpeed1(String msg);
  void sendNonDrivenWheelSpeed2(String msg);
  void sendFuelCompAccel(String msg);
  void sendFuelCompStarting(String msg);
  void sendFuelCompAirTemp(String msg);
  void sendFuelCompCoolantTemp(String msg);
  void sendFuelCompBarometer(String msg);
  void sendFuelCompMAP(String msg);
  void sendIgnitionCompAirTemp(String msg);
  void sendIgnitionCompCoolantTemp(String msg);
  void sendBPS(String msg);
  void sendIMUX(String msg);
  void sendIMUY(String msg);
  void sendLPSFL(String msg);
  void sendLPSFR(String msg);
  void sendLPSBL(String msg);
  void sendLPSBR(String msg);
  void sendSG1(String msg);
  void sendSG2(String msg);
  void sendSG3(String msg);
  void sendSG4(String msg);
  void sendSG5(String msg);
  void sendSG6(String msg);
  void sendSG7(String msg);
  void sendSG8(String msg);
  void sendSG9(String msg);
  void sendSG10(String msg);

  /* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
   * CONSTANTS                                                                   *
   * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
  const String rpm_ID = "01";
  const String tps_ID = "02";
  const String fuel_open_time_ID = "03";
  const String ignition_angle_ID = "04";
  const String barometer_ID = "05";
  const String map_ID = "06";
  const String lambda_ID = "07";
  const String analog_input_1_ID = "08";
  const String analog_input_2_ID = "09";
  const String analog_input_3_ID = "10";
  const String analog_input_4_ID = "11";
  const String analog_input_5_ID = "12";
  const String analog_input_6_ID = "13";
  const String analog_input_7_ID = "14";
  const String analog_input_8_ID = "15";
  const String freq_1_ID = "16";
  const String freq_2_ID = "17";
  const String freq_3_ID = "18";
  const String freq_4_ID = "19";
  const String battery_volt_ID = "20";
  const String air_temp_ID = "21";
  const String coolant_temp_ID = "22";
  const String analog_input_5_therm_ID = "23";
  const String analog_input_7_therm_ID = "24";
  const String version_major_ID = "25";
  const String version_minor_ID = "26";
  const String version_build_ID = "27";
  const String version_com_ID = "28";
  const String rpm_rate_ID = "29";
  const String tps_rate_ID = "30";
  const String map_rate_ID = "31";
  const String maf_rate_ID = "32";
  const String lambda_1_measured_ID = "33";
  const String lambda_2_measured_ID = "34";
  const String target_lambda_ID = "35";
  const String pwm_duty_cycle_1_ID = "36";
  const String pwm_duty_cycle_2_ID = "37";
  const String pwm_duty_cycle_3_ID = "38";
  const String pwm_duty_cycle_4_ID = "39";
  const String pwm_duty_cycle_5_ID = "40";
  const String pwm_duty_cycle_6_ID = "41";
  const String pwm_duty_cycle_7_ID = "42";
  const String pwm_duty_cycle_8_ID = "43";
  const String percent_slip_ID = "44";
  const String driven_wheel_rate_of_change_ID = "45";
  const String desired_value_ID = "46";
  const String driven_avg_wheel_speed_ID = "47";
  const String non_driven_avg_wheel_speed_ID = "48";
  const String ignition_comp_ID = "49";
  const String ignition_cut_percent_ID = "50";
  const String driven_wheel_speed_1_ID = "51";
  const String driven_wheel_speed_2_ID = "52";
  const String non_driven_wheel_speed_1_ID = "53";
  const String non_driven_wheel_speed_2_ID = "54";
  const String fuel_comp_accel_ID = "55";
  const String fuel_comp_starting_ID = "56";
  const String fuel_comp_air_temp_ID = "57";
  const String fuel_comp_coolant_temp_ID = "58";
  const String fuel_comp_barometer_ID = "59";
  const String fuel_comp_map_ID = "60";
  const String ignition_comp_air_temp_ID = "61";
  const String ignition_comp_coolant_temp_ID = "62";
  const String BPS_ID = "63";
  const String IMU_X_ID = "64";
  const String IMU_Y_ID = "65";
  const String LPS_FL_ID = "66";
  const String LPS_FR_ID = "67";
  const String LPS_BL_ID = "68";
  const String LPS_BR_ID = "69";
  const String SG_1_ID = "70";
  const String SG_2_ID = "71";
  const String SG_3_ID = "72";
  const String SG_4_ID = "73";
  const String SG_5_ID = "74";
  const String SG_6_ID = "75";
  const String SG_7_ID = "76";
  const String SG_8_ID = "77";
  const String SG_9_ID = "78";
  const String SG_10_ID = "79";
};
#endif