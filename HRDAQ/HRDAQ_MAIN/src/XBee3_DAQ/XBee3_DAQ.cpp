/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Revision # | Date       | Author      | Notes                                 *
 * ----------------------------------------------------------------------------- *
 * 1.0        | 1/22/2024  | Jon Ho      | Initial release                       *
 *            |            |             |                                       *
 *            |            |             |                                       *
 *                                                                               *
 * Notes:                                                                        *
 * - Purpose: XBee3_DAQ cpp file, holds all functions and declarations           *
 * - This is silly, there is a better way to do this, but I'm scared about wireless comms working
 *                                                                               *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * LIBRARIES, OBJECT, AND HEADER FILE INCLUSIONS & INSTANTIATIONS                *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#include "../../ctrl_panel.h"  //Control panel header
#include "XBee3_DAQ.h"         //XBee3_DAQ specific header
ctrl_panel XBee3_DAQ_ctrl_obj; //Control panel object

/*
 * XBee3_DAQ constructor
 */
XBee3_DAQ::XBee3_DAQ(){}

/*
 * XBee3_DAQ setup function, initializes XBee3_DAQ baud rate
 * XBee3 baud rate must be the same as XBee module baud rate
 */
void XBee3_DAQ::begin(){
  if(XBee3_DAQ_ctrl_obj.XBee3_DAQ_enable){
    Serial1.begin(XBee3_DAQ_ctrl_obj.serial_speed);
  }
}

void XBee3_DAQ::sendRPM(String msg){
  //Print specific ID
  for(uint32_t i = 0; i<2; i++){
    Serial1.print(rpm_ID[i]);
  }
  //Print specific msg
  for(uint32_t i = 0; i<msg.length(); i++){
    Serial1.print(msg[i]);
  }
}

void XBee3_DAQ::sendTPS(String msg){
  //Print specific ID
  for(uint32_t i = 0; i<2; i++){
    Serial1.print(tps_ID[i]);
  }
  //Print specific msg
  for(uint32_t i = 0; i<msg.length(); i++){
    Serial1.print(msg[i]);
  }
}

void XBee3_DAQ::sendFuelOpenTime(String msg){
  //Print specific ID
  for(uint32_t i = 0; i<2; i++){
    Serial1.print(fuel_open_time_ID[i]);
  }
  //Print specific msg
  for(uint32_t i = 0; i<msg.length(); i++){
    Serial1.print(msg[i]);
  }
}

void XBee3_DAQ::sendIgnitionAngle(String msg){
  //Print specific ID
  for(uint32_t i = 0; i<2; i++){
    Serial1.print(ignition_angle_ID[i]);
  }
  //Print specific msg
  for(uint32_t i = 0; i<msg.length(); i++){
    Serial1.print(msg[i]);
  }
}

void XBee3_DAQ::sendBarometer(String msg){
  //Print specific ID
  for(uint32_t i = 0; i<2; i++){
    Serial1.print(barometer_ID[i]);
  }
  //Print specific msg
  for(uint32_t i = 0; i<msg.length(); i++){
    Serial1.print(msg[i]);
  }
}

void XBee3_DAQ::sendMAP(String msg){
  //Print specific ID
  for(uint32_t i = 0; i<2; i++){
    Serial1.print(map_ID[i]);
  }
  //Print specific msg
  for(uint32_t i = 0; i<msg.length(); i++){
    Serial1.print(msg[i]);
  }
}

void XBee3_DAQ::sendLambda(String msg){
  //Print specific ID
  for(uint32_t i = 0; i<2; i++){
    Serial1.print(lambda_ID[i]);
  }
  //Print specific msg
  for(uint32_t i = 0; i<msg.length(); i++){
    Serial1.print(msg[i]);
  }
}

void XBee3_DAQ::sendAnalogInput1(String msg){
  //Print specific ID
  for(uint32_t i = 0; i<2; i++){
    Serial1.print(analog_input_1_ID[i]);
  }
  //Print specific msg
  for(uint32_t i = 0; i<msg.length(); i++){
    Serial1.print(msg[i]);
  }
}

void XBee3_DAQ::sendAnalogInput2(String msg){
  //Print specific ID
  for(uint32_t i = 0; i<2; i++){
    Serial1.print(analog_input_2_ID[i]);
  }
  //Print specific msg
  for(uint32_t i = 0; i<msg.length(); i++){
    Serial1.print(msg[i]);
  }
}

void XBee3_DAQ::sendAnalogInput3(String msg){
  //Print specific ID
  for(uint32_t i = 0; i<2; i++){
    Serial1.print(analog_input_3_ID[i]);
  }
  //Print specific msg
  for(uint32_t i = 0; i<msg.length(); i++){
    Serial1.print(msg[i]);
  }
}

void XBee3_DAQ::sendAnalogInput4(String msg){
  //Print specific ID
  for(uint32_t i = 0; i<2; i++){
    Serial1.print(analog_input_4_ID[i]);
  }
  //Print specific msg
  for(uint32_t i = 0; i<msg.length(); i++){
    Serial1.print(msg[i]);
  }
}

void XBee3_DAQ::sendAnalogInput5(String msg){
  //Print specific ID
  for(uint32_t i = 0; i<2; i++){
    Serial1.print(analog_input_5_ID[i]);
  }
  //Print specific msg
  for(uint32_t i = 0; i<msg.length(); i++){
    Serial1.print(msg[i]);
  }
}

void XBee3_DAQ::sendAnalogInput6(String msg){
  //Print specific ID
  for(uint32_t i = 0; i<2; i++){
    Serial1.print(analog_input_6_ID[i]);
  }
  //Print specific msg
  for(uint32_t i = 0; i<msg.length(); i++){
    Serial1.print(msg[i]);
  }
}

void XBee3_DAQ::sendAnalogInput7(String msg){
  //Print specific ID
  for(uint32_t i = 0; i<2; i++){
    Serial1.print(analog_input_7_ID[i]);
  }
  //Print specific msg
  for(uint32_t i = 0; i<msg.length(); i++){
    Serial1.print(msg[i]);
  }
}

void XBee3_DAQ::sendAnalogInput8(String msg){
  //Print specific ID
  for(uint32_t i = 0; i<2; i++){
    Serial1.print(analog_input_8_ID[i]);
  }
  //Print specific msg
  for(uint32_t i = 0; i<msg.length(); i++){
    Serial1.print(msg[i]);
  }
}

void XBee3_DAQ::sendFreq1(String msg){
  //Print specific ID
  for(uint32_t i = 0; i<2; i++){
    Serial1.print(freq_1_ID[i]);
  }
  //Print specific msg
  for(uint32_t i = 0; i<msg.length(); i++){
    Serial1.print(msg[i]);
  }
}

void XBee3_DAQ::sendFreq2(String msg){
  //Print specific ID
  for(uint32_t i = 0; i<2; i++){
    Serial1.print(freq_2_ID[i]);
  }
  //Print specific msg
  for(uint32_t i = 0; i<msg.length(); i++){
    Serial1.print(msg[i]);
  }
}

void XBee3_DAQ::sendFreq3(String msg){
  //Print specific ID
  for(uint32_t i = 0; i<2; i++){
    Serial1.print(freq_3_ID[i]);
  }
  //Print specific msg
  for(uint32_t i = 0; i<msg.length(); i++){
    Serial1.print(msg[i]);
  }
}

void XBee3_DAQ::sendFreq4(String msg){
  //Print specific ID
  for(uint32_t i = 0; i<2; i++){
    Serial1.print(freq_4_ID[i]);
  }
  //Print specific msg
  for(uint32_t i = 0; i<msg.length(); i++){
    Serial1.print(msg[i]);
  }
}

void XBee3_DAQ::sendBatteryVolt(String msg){
  //Print specific ID
  for(uint32_t i = 0; i<2; i++){
    Serial1.print(battery_volt_ID[i]);
  }
  //Print specific msg
  for(uint32_t i = 0; i<msg.length(); i++){
    Serial1.print(msg[i]);
  }
}

void XBee3_DAQ::sendAirTemp(String msg){
  //Print specific ID
  for(uint32_t i = 0; i<2; i++){
    Serial1.print(air_temp_ID[i]);
  }
  //Print specific msg
  for(uint32_t i = 0; i<msg.length(); i++){
    Serial1.print(msg[i]);
  }
}

void XBee3_DAQ::sendCoolantTemp(String msg){
  //Print specific ID
  for(uint32_t i = 0; i<2; i++){
    Serial1.print(coolant_temp_ID[i]);
  }
  //Print specific msg
  for(uint32_t i = 0; i<msg.length(); i++){
    Serial1.print(msg[i]);
  }
}

void XBee3_DAQ::sendAnalogInput5Therm(String msg){
  //Print specific ID
  for(uint32_t i = 0; i<2; i++){
    Serial1.print(analog_input_5_therm_ID[i]);
  }
  //Print specific msg
  for(uint32_t i = 0; i<msg.length(); i++){
    Serial1.print(msg[i]);
  }
}

void XBee3_DAQ::sendAnalogInput7Therm(String msg){
  //Print specific ID
  for(uint32_t i = 0; i<2; i++){
    Serial1.print(analog_input_7_therm_ID[i]);
  }
  //Print specific msg
  for(uint32_t i = 0; i<msg.length(); i++){
    Serial1.print(msg[i]);
  }
}

void XBee3_DAQ::sendRPMRate(String msg){
  //Print specific ID
  for(uint32_t i = 0; i<2; i++){
    Serial1.print(rpm_rate_ID[i]);
  }
  //Print specific msg
  for(uint32_t i = 0; i<msg.length(); i++){
    Serial1.print(msg[i]);
  }
}

void XBee3_DAQ::sendTPSRate(String msg){
  //Print specific ID
  for(uint32_t i = 0; i<2; i++){
    Serial1.print(tps_rate_ID[i]);
  }
  //Print specific msg
  for(uint32_t i = 0; i<msg.length(); i++){
    Serial1.print(msg[i]);
  }
}

void XBee3_DAQ::sendMAPRate(String msg){
  //Print specific ID
  for(uint32_t i = 0; i<2; i++){
    Serial1.print(map_rate_ID[i]);
  }
  //Print specific msg
  for(uint32_t i = 0; i<msg.length(); i++){
    Serial1.print(msg[i]);
  }
}

void XBee3_DAQ::sendMAFRate(String msg){
  //Print specific ID
  for(uint32_t i = 0; i<2; i++){
    Serial1.print(maf_rate_ID[i]);
  }
  //Print specific msg
  for(uint32_t i = 0; i<msg.length(); i++){
    Serial1.print(msg[i]);
  }
}

void XBee3_DAQ::sendLambda1Measured(String msg){
  //Print specific ID
  for(uint32_t i = 0; i<2; i++){
    Serial1.print(lambda_1_measured_ID[i]);
  }
  //Print specific msg
  for(uint32_t i = 0; i<msg.length(); i++){
    Serial1.print(msg[i]);
  }
}

void XBee3_DAQ::sendLambda2Measured(String msg){
  //Print specific ID
  for(uint32_t i = 0; i<2; i++){
    Serial1.print(lambda_2_measured_ID[i]);
  }
  //Print specific msg
  for(uint32_t i = 0; i<msg.length(); i++){
    Serial1.print(msg[i]);
  }
}

void XBee3_DAQ::sendTargetLambda(String msg){
  //Print specific ID
  for(uint32_t i = 0; i<2; i++){
    Serial1.print(target_lambda_ID[i]);
  }
  //Print specific msg
  for(uint32_t i = 0; i<msg.length(); i++){
    Serial1.print(msg[i]);
  }
}

void XBee3_DAQ::sendPWMDutyCycle1(String msg){
  //Print specific ID
  for(uint32_t i = 0; i<2; i++){
    Serial1.print(pwm_duty_cycle_1_ID[i]);
  }
  //Print specific msg
  for(uint32_t i = 0; i<msg.length(); i++){
    Serial1.print(msg[i]);
  }
}

void XBee3_DAQ::sendPWMDutyCycle2(String msg){
  //Print specific ID
  for(uint32_t i = 0; i<2; i++){
    Serial1.print(pwm_duty_cycle_2_ID[i]);
  }
  //Print specific msg
  for(uint32_t i = 0; i<msg.length(); i++){
    Serial1.print(msg[i]);
  }
}

void XBee3_DAQ::sendPWMDutyCycle3(String msg){
  //Print specific ID
  for(uint32_t i = 0; i<2; i++){
    Serial1.print(pwm_duty_cycle_3_ID[i]);
  }
  //Print specific msg
  for(uint32_t i = 0; i<msg.length(); i++){
    Serial1.print(msg[i]);
  }
}

void XBee3_DAQ::sendPWMDutyCycle4(String msg){
  //Print specific ID
  for(uint32_t i = 0; i<2; i++){
    Serial1.print(pwm_duty_cycle_4_ID[i]);
  }
  //Print specific msg
  for(uint32_t i = 0; i<msg.length(); i++){
    Serial1.print(msg[i]);
  }
}

void XBee3_DAQ::sendPWMDutyCycle5(String msg){
  //Print specific ID
  for(uint32_t i = 0; i<2; i++){
    Serial1.print(pwm_duty_cycle_5_ID[i]);
  }
  //Print specific msg
  for(uint32_t i = 0; i<msg.length(); i++){
    Serial1.print(msg[i]);
  }
}

void XBee3_DAQ::sendPWMDutyCycle6(String msg){
  //Print specific ID
  for(uint32_t i = 0; i<2; i++){
    Serial1.print(pwm_duty_cycle_6_ID[i]);
  }
  //Print specific msg
  for(uint32_t i = 0; i<msg.length(); i++){
    Serial1.print(msg[i]);
  }
}

void XBee3_DAQ::sendPWMDutyCycle7(String msg){
  //Print specific ID
  for(uint32_t i = 0; i<2; i++){
    Serial1.print(pwm_duty_cycle_7_ID[i]);
  }
  //Print specific msg
  for(uint32_t i = 0; i<msg.length(); i++){
    Serial1.print(msg[i]);
  }
}

void XBee3_DAQ::sendPWMDutyCycle8(String msg){
  //Print specific ID
  for(uint32_t i = 0; i<2; i++){
    Serial1.print(pwm_duty_cycle_8_ID[i]);
  }
  //Print specific msg
  for(uint32_t i = 0; i<msg.length(); i++){
    Serial1.print(msg[i]);
  }
}

void XBee3_DAQ::sendPercentSlip(String msg){
  //Print specific ID
  for(uint32_t i = 0; i<2; i++){
    Serial1.print(percent_slip_ID[i]);
  }
  //Print specific msg
  for(uint32_t i = 0; i<msg.length(); i++){
    Serial1.print(msg[i]);
  }
}

void XBee3_DAQ::sendDrivenWheelRateOfChange(String msg){
  //Print specific ID
  for(uint32_t i = 0; i<2; i++){
    Serial1.print(driven_wheel_rate_of_change_ID[i]);
  }
  //Print specific msg
  for(uint32_t i = 0; i<msg.length(); i++){
    Serial1.print(msg[i]);
  }
}

void XBee3_DAQ::sendDesiredValue(String msg){
  //Print specific ID
  for(uint32_t i = 0; i<2; i++){
    Serial1.print(desired_value_ID[i]);
  }
  //Print specific msg
  for(uint32_t i = 0; i<msg.length(); i++){
    Serial1.print(msg[i]);
  }
}

void XBee3_DAQ::sendDrivenAvgWheelSpeed(String msg){
  //Print specific ID
  for(uint32_t i = 0; i<2; i++){
    Serial1.print(driven_avg_wheel_speed_ID[i]);
  }
  //Print specific msg
  for(uint32_t i = 0; i<msg.length(); i++){
    Serial1.print(msg[i]);
  }
}

void XBee3_DAQ::sendNonDrivenAvgWheelSpeed(String msg){
  //Print specific ID
  for(uint32_t i = 0; i<2; i++){
    Serial1.print(non_driven_avg_wheel_speed_ID[i]);
  }
  //Print specific msg
  for(uint32_t i = 0; i<msg.length(); i++){
    Serial1.print(msg[i]);
  }
}

void XBee3_DAQ::sendIgnitionComp(String msg){
  //Print specific ID
  for(uint32_t i = 0; i<2; i++){
    Serial1.print(ignition_comp_ID[i]);
  }
  //Print specific msg
  for(uint32_t i = 0; i<msg.length(); i++){
    Serial1.print(msg[i]);
  }
}

void XBee3_DAQ::sendIgnitionCutPercent(String msg){
  //Print specific ID
  for(uint32_t i = 0; i<2; i++){
    Serial1.print(ignition_cut_percent_ID[i]);
  }
  //Print specific msg
  for(uint32_t i = 0; i<msg.length(); i++){
    Serial1.print(msg[i]);
  }
}

void XBee3_DAQ::sendDrivenWheelSpeed1(String msg){
  //Print specific ID
  for(uint32_t i = 0; i<2; i++){
    Serial1.print(driven_wheel_speed_1_ID[i]);
  }
  //Print specific msg
  for(uint32_t i = 0; i<msg.length(); i++){
    Serial1.print(msg[i]);
  }
}

void XBee3_DAQ::sendDrivenWheelSpeed2(String msg){
  //Print specific ID
  for(uint32_t i = 0; i<2; i++){
    Serial1.print(driven_wheel_speed_2_ID[i]);
  }
  //Print specific msg
  for(uint32_t i = 0; i<msg.length(); i++){
    Serial1.print(msg[i]);
  }
}

void XBee3_DAQ::sendNonDrivenWheelSpeed1(String msg){
  //Print specific ID
  for(uint32_t i = 0; i<2; i++){
    Serial1.print(non_driven_wheel_speed_1_ID[i]);
  }
  //Print specific msg
  for(uint32_t i = 0; i<msg.length(); i++){
    Serial1.print(msg[i]);
  }
}

void XBee3_DAQ::sendNonDrivenWheelSpeed2(String msg){
  //Print specific ID
  for(uint32_t i = 0; i<2; i++){
    Serial1.print(non_driven_wheel_speed_2_ID[i]);
  }
  //Print specific msg
  for(uint32_t i = 0; i<msg.length(); i++){
    Serial1.print(msg[i]);
  }
}

void XBee3_DAQ::sendFuelCompAccel(String msg){
  //Print specific ID
  for(uint32_t i = 0; i<2; i++){
    Serial1.print(fuel_comp_accel_ID[i]);
  }
  //Print specific msg
  for(uint32_t i = 0; i<msg.length(); i++){
    Serial1.print(msg[i]);
  }
}

void XBee3_DAQ::sendFuelCompStarting(String msg){
  //Print specific ID
  for(uint32_t i = 0; i<2; i++){
    Serial1.print(fuel_comp_starting_ID[i]);
  }
  //Print specific msg
  for(uint32_t i = 0; i<msg.length(); i++){
    Serial1.print(msg[i]);
  }
}

void XBee3_DAQ::sendFuelCompAirTemp(String msg){
  //Print specific ID
  for(uint32_t i = 0; i<2; i++){
    Serial1.print(fuel_comp_air_temp_ID[i]);
  }
  //Print specific msg
  for(uint32_t i = 0; i<msg.length(); i++){
    Serial1.print(msg[i]);
  }
}

void XBee3_DAQ::sendFuelCompCoolantTemp(String msg){
  //Print specific ID
  for(uint32_t i = 0; i<2; i++){
    Serial1.print(fuel_comp_coolant_temp_ID[i]);
  }
  //Print specific msg
  for(uint32_t i = 0; i<msg.length(); i++){
    Serial1.print(msg[i]);
  }
}

void XBee3_DAQ::sendFuelCompBarometer(String msg){
  //Print specific ID
  for(uint32_t i = 0; i<2; i++){
    Serial1.print(fuel_comp_barometer_ID[i]);
  }
  //Print specific msg
  for(uint32_t i = 0; i<msg.length(); i++){
    Serial1.print(msg[i]);
  }
}

void XBee3_DAQ::sendFuelCompMAP(String msg){
  //Print specific ID
  for(uint32_t i = 0; i<2; i++){
    Serial1.print(fuel_comp_map_ID[i]);
  }
  //Print specific msg
  for(uint32_t i = 0; i<msg.length(); i++){
    Serial1.print(msg[i]);
  }
}

void XBee3_DAQ::sendIgnitionCompAirTemp(String msg){
  //Print specific ID
  for(uint32_t i = 0; i<2; i++){
    Serial1.print(ignition_comp_air_temp_ID[i]);
  }
  //Print specific msg
  for(uint32_t i = 0; i<msg.length(); i++){
    Serial1.print(msg[i]);
  }
}

void XBee3_DAQ::sendIgnitionCompCoolantTemp(String msg){
  //Print specific ID
  for(uint32_t i = 0; i<2; i++){
    Serial1.print(ignition_comp_coolant_temp_ID[i]);
  }
  //Print specific msg
  for(uint32_t i = 0; i<msg.length(); i++){
    Serial1.print(msg[i]);
  }
}

void XBee3_DAQ::sendBPS(String msg){
  //Print specific ID
  for(uint32_t i = 0; i<2; i++){
    Serial1.print(BPS_ID[i]);
  }
  //Print specific msg
  for(uint32_t i = 0; i<msg.length(); i++){
    Serial1.print(msg[i]);
  }
}

void XBee3_DAQ::sendIMUX(String msg){
  //Print specific ID
  for(uint32_t i = 0; i<2; i++){
    Serial1.print(IMU_X_ID[i]);
  }
  //Print specific msg
  for(uint32_t i = 0; i<msg.length(); i++){
    Serial1.print(msg[i]);
  }
}

void XBee3_DAQ::sendIMUY(String msg){
  //Print specific ID
  for(uint32_t i = 0; i<2; i++){
    Serial1.print(IMU_Y_ID[i]);
  }
  //Print specific msg
  for(uint32_t i = 0; i<msg.length(); i++){
    Serial1.print(msg[i]);
  }
}

void XBee3_DAQ::sendLPSFL(String msg){
  //Print specific ID
  for(uint32_t i = 0; i<2; i++){
    Serial1.print(LPS_FL_ID[i]);
  }
  //Print specific msg
  for(uint32_t i = 0; i<msg.length(); i++){
    Serial1.print(msg[i]);
  }
}

void XBee3_DAQ::sendLPSFR(String msg){
  //Print specific ID
  for(uint32_t i = 0; i<2; i++){
    Serial1.print(LPS_FR_ID[i]);
  }
  //Print specific msg
  for(uint32_t i = 0; i<msg.length(); i++){
    Serial1.print(msg[i]);
  }
}

void XBee3_DAQ::sendLPSBL(String msg){
  //Print specific ID
  for(uint32_t i = 0; i<2; i++){
    Serial1.print(LPS_BL_ID[i]);
  }
  //Print specific msg
  for(uint32_t i = 0; i<msg.length(); i++){
    Serial1.print(msg[i]);
  }
}

void XBee3_DAQ::sendLPSBR(String msg){
  //Print specific ID
  for(uint32_t i = 0; i<2; i++){
    Serial1.print(LPS_BR_ID[i]);
  }
  //Print specific msg
  for(uint32_t i = 0; i<msg.length(); i++){
    Serial1.print(msg[i]);
  }
}

void XBee3_DAQ::sendSG1(String msg){
  //Print specific ID
  for(uint32_t i = 0; i<2; i++){
    Serial1.print(SG_1_ID[i]);
  }
  //Print specific msg
  for(uint32_t i = 0; i<msg.length(); i++){
    Serial1.print(msg[i]);
  }
}

void XBee3_DAQ::sendSG2(String msg){
  //Print specific ID
  for(uint32_t i = 0; i<2; i++){
    Serial1.print(SG_2_ID[i]);
  }
  //Print specific msg
  for(uint32_t i = 0; i<msg.length(); i++){
    Serial1.print(msg[i]);
  }
}

void XBee3_DAQ::sendSG3(String msg){
  //Print specific ID
  for(uint32_t i = 0; i<2; i++){
    Serial1.print(SG_3_ID[i]);
  }
  //Print specific msg
  for(uint32_t i = 0; i<msg.length(); i++){
    Serial1.print(msg[i]);
  }
}

void XBee3_DAQ::sendSG4(String msg){
  //Print specific ID
  for(uint32_t i = 0; i<2; i++){
    Serial1.print(SG_4_ID[i]);
  }
  //Print specific msg
  for(uint32_t i = 0; i<msg.length(); i++){
    Serial1.print(msg[i]);
  }
}

void XBee3_DAQ::sendSG5(String msg){
  //Print specific ID
  for(uint32_t i = 0; i<2; i++){
    Serial1.print(SG_5_ID[i]);
  }
  //Print specific msg
  for(uint32_t i = 0; i<msg.length(); i++){
    Serial1.print(msg[i]);
  }
}

void XBee3_DAQ::sendSG6(String msg){
  //Print specific ID
  for(uint32_t i = 0; i<2; i++){
    Serial1.print(SG_6_ID[i]);
  }
  //Print specific msg
  for(uint32_t i = 0; i<msg.length(); i++){
    Serial1.print(msg[i]);
  }
}

void XBee3_DAQ::sendSG7(String msg){
  //Print specific ID
  for(uint32_t i = 0; i<2; i++){
    Serial1.print(SG_7_ID[i]);
  }
  //Print specific msg
  for(uint32_t i = 0; i<msg.length(); i++){
    Serial1.print(msg[i]);
  }
}

void XBee3_DAQ::sendSG8(String msg){
  //Print specific ID
  for(uint32_t i = 0; i<2; i++){
    Serial1.print(SG_8_ID[i]);
  }
  //Print specific msg
  for(uint32_t i = 0; i<msg.length(); i++){
    Serial1.print(msg[i]);
  }
}

void XBee3_DAQ::sendSG9(String msg){
  //Print specific ID
  for(uint32_t i = 0; i<2; i++){
    Serial1.print(SG_9_ID[i]);
  }
  //Print specific msg
  for(uint32_t i = 0; i<msg.length(); i++){
    Serial1.print(msg[i]);
  }
}

void XBee3_DAQ::sendSG10(String msg){
  //Print specific ID
  for(uint32_t i = 0; i<2; i++){
    Serial1.print(SG_10_ID[i]);
  }
  //Print specific msg
  for(uint32_t i = 0; i<msg.length(); i++){
    Serial1.print(msg[i]);
  }
}
