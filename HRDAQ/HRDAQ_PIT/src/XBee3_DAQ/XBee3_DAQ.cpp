/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Revision # | Date       | Author      | Notes                                 *
 * ----------------------------------------------------------------------------- *
 * 1.0        | 1/22/2024  | Jon Ho      | Initial release                       *
 *            |            |             |                                       *
 *            |            |             |                                       *
 *                                                                               *
 * Notes:                                                                        *
 * - Purpose: XBee3_DAQ cpp file, holds all functions and declarations           *
 *                                                                               *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * LIBRARIES, OBJECT, AND HEADER FILE INCLUSIONS & INSTANTIATIONS                *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#include "XBee3_DAQ.h"        //XBee3_DAQ specific header
uint32_t serial_speed = 9600; //Serial monitor speed

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * CONSTANTS                                                                     *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
const uint8_t rpm_ID = 1;
const uint8_t tps_ID = 2;
const uint8_t fuel_open_time_ID = 3;
const uint8_t ignition_angle_ID = 4;
const uint8_t barometer_ID = 5;
const uint8_t map_ID = 6;
const uint8_t lambda_ID = 7;
const uint8_t analog_input_1_ID = 8;
const uint8_t analog_input_2_ID = 9;
const uint8_t analog_input_3_ID = 10;
const uint8_t analog_input_4_ID = 11;
const uint8_t analog_input_5_ID = 12;
const uint8_t analog_input_6_ID = 13;
const uint8_t analog_input_7_ID = 14;
const uint8_t analog_input_8_ID = 15;
const uint8_t freq_1_ID = 16;
const uint8_t freq_2_ID = 17;
const uint8_t freq_3_ID = 18;
const uint8_t freq_4_ID = 19;
const uint8_t battery_volt_ID = 20;
const uint8_t air_temp_ID = 21;
const uint8_t coolant_temp_ID = 22;
const uint8_t analog_input_5_therm_ID = 23;
const uint8_t analog_input_7_therm_ID = 24;
const uint8_t version_major_ID = 25;
const uint8_t version_minor_ID = 26;
const uint8_t version_build_ID = 27;
const uint8_t version_com_ID = 28;
const uint8_t rpm_rate_ID = 29;
const uint8_t tps_rate_ID = 30;
const uint8_t map_rate_ID = 31;
const uint8_t maf_rate_ID = 32;
const uint8_t lambda_1_measured_ID = 33;
const uint8_t lambda_2_measured_ID = 34;
const uint8_t target_lambda_ID = 35;
const uint8_t pwm_duty_cycle_1_ID = 36;
const uint8_t pwm_duty_cycle_2_ID = 37;
const uint8_t pwm_duty_cycle_3_ID = 38;
const uint8_t pwm_duty_cycle_4_ID = 39;
const uint8_t pwm_duty_cycle_5_ID = 40;
const uint8_t pwm_duty_cycle_6_ID = 41;
const uint8_t pwm_duty_cycle_7_ID = 42;
const uint8_t pwm_duty_cycle_8_ID = 43;
const uint8_t percent_slip_ID = 44;
const uint8_t driven_wheel_rate_of_change_ID = 45;
const uint8_t desired_value_ID = 46;
const uint8_t driven_avg_wheel_speed_ID = 47;
const uint8_t non_driven_avg_wheel_speed_ID = 48;
const uint8_t ignition_comp_ID = 49;
const uint8_t ignition_cut_percent_ID = 50;
const uint8_t driven_wheel_speed_1_ID = 51;
const uint8_t driven_wheel_speed_2_ID = 52;
const uint8_t non_driven_wheel_speed_1_ID = 53;
const uint8_t non_driven_wheel_speed_2_ID = 54;
const uint8_t fuel_comp_accel_ID = 55;
const uint8_t fuel_comp_starting_ID = 56;
const uint8_t fuel_comp_air_temp_ID = 57;
const uint8_t fuel_comp_coolant_temp_ID = 58;
const uint8_t fuel_comp_barometer_ID = 59;
const uint8_t fuel_comp_map_ID = 60;
const uint8_t ignition_comp_air_temp_ID = 61;
const uint8_t ignition_comp_coolant_temp_ID = 62;
const uint8_t BPS_ID = 63;
const uint8_t IMU_X_ID = 64;
const uint8_t IMU_Y_ID = 65;
const uint8_t LPS_FL_ID = 66;
const uint8_t LPS_FR_ID = 67;
const uint8_t LPS_BL_ID = 68;
const uint8_t LPS_BR_ID = 69;
const uint8_t SG_1_ID = 70;
const uint8_t SG_2_ID = 71;
const uint8_t SG_3_ID = 72;
const uint8_t SG_4_ID = 73;
const uint8_t SG_5_ID = 74;
const uint8_t SG_6_ID = 75;
const uint8_t SG_7_ID = 76;
const uint8_t SG_8_ID = 77;
const uint8_t SG_9_ID = 78;
const uint8_t SG_10_ID = 79;

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * DATA CONTAINERS                                                               *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
String XBee3_read_ID;
uint8_t XBee3_read_ID_counter;
char XBee3_read_byte;
String XBee3_read_msg;
double rpm_value;
double tps_value;
double fuel_open_time_value;
double ignition_angle_value;
double barometer_value;
double map_value;
double lambda_value;
double analog_input_1_value;
double analog_input_2_value;
double analog_input_3_value;
double analog_input_4_value;
double analog_input_5_value;
double analog_input_6_value;
double analog_input_7_value;
double analog_input_8_value;
double freq_1_value;
double freq_2_value;
double freq_3_value;
double freq_4_value;
double battery_volt_value;
double air_temp_value;
double coolant_temp_value;
double analog_input_5_therm_value;
double analog_input_7_therm_value;
double version_major_value;
double version_minor_value;
double version_build_value;
double version_com_value;
double rpm_rate_value;
double tps_rate_value;
double map_rate_value;
double maf_rate_value;
double lambda_1_measured_value;
double lambda_2_measured_value;
double target_lambda_value;
double pwm_duty_cycle_1_value;
double pwm_duty_cycle_2_value;
double pwm_duty_cycle_3_value;
double pwm_duty_cycle_4_value;
double pwm_duty_cycle_5_value;
double pwm_duty_cycle_6_value;
double pwm_duty_cycle_7_value;
double pwm_duty_cycle_8_value;
double percent_slip_value;
double driven_wheel_rate_of_change_value;
double desired_value_value;
double driven_avg_wheel_speed_value;
double non_driven_avg_wheel_speed_value;
double ignition_comp_value;
double ignition_cut_percent_value;
double driven_wheel_speed_1_value;
double driven_wheel_speed_2_value;
double non_driven_wheel_speed_1_value;
double non_driven_wheel_speed_2_value;
double fuel_comp_accel_value;
double fuel_comp_starting_value;
double fuel_comp_air_temp_value;
double fuel_comp_coolant_temp_value;
double fuel_comp_barometer_value;
double fuel_comp_map_value;
double ignition_comp_air_temp_value;
double ignition_comp_coolant_temp_value;
double BPS_value;
double IMUX_value;
double IMUY_value;
double LPSFL_value;
double LPSFR_value;
double LPSBL_value;
double LPSBR_value;
double SG1_value;
double SG2_value;
double SG3_value;
double SG4_value;
double SG5_value;
double SG6_value;
double SG7_value;
double SG8_value;
double SG9_value;
double SG10_value;

/*
 * XBee3_DAQ constructor
 */
XBee3_DAQ::XBee3_DAQ(){}

/*
 * XBee3_DAQ setup function, initializes XBee3_DAQ baud rate
 * XBee3 baud rate must be the same as XBee module baud rate
 */
void XBee3_DAQ::begin(){
  Serial1.begin(serial_speed);
}

/*
 * XBee3_DAQ read function, reads first two char as ID, then message until >
 */
void XBee3_DAQ::read(){
  //Reset ID and data container
  XBee3_read_ID = "";
  XBee3_read_byte = '\0';
  XBee3_read_ID_counter = 0;
  XBee3_read_msg = "";

  //Read msg until data char equals termination char
  while(Serial1.available()>0){
    XBee3_read_byte = Serial1.read();
    if(XBee3_read_byte == '>'){
      //Exit once termination char read
      break;
    }
    else if(XBee3_read_ID_counter<2){
      //Construct ID
      XBee3_read_ID += XBee3_read_byte;
      XBee3_read_ID_counter++;
    }
    else{
      //Construct msg
      XBee3_read_msg += XBee3_read_byte;
    }
  }

  //Set data containers depending on ID, all cases are related to "ID"
  switch(XBee3_read_ID.toInt()){
    case rpm_ID:
      rpm_value = XBee3_read_msg.toFloat();
      break;
    case tps_ID:
      tps_value = XBee3_read_msg.toFloat();
      break;
    case fuel_open_time_ID:
      fuel_open_time_value = XBee3_read_msg.toFloat();
      break;
    case ignition_angle_ID:
      ignition_angle_value = XBee3_read_msg.toFloat();
      break;
    case barometer_ID:
      barometer_value = XBee3_read_msg.toFloat();
      break;
    case map_ID:
      map_value = XBee3_read_msg.toFloat();
      break;
    case lambda_ID:
      lambda_value = XBee3_read_msg.toFloat();
      break;
    case analog_input_1_ID:
      analog_input_1_value = XBee3_read_msg.toFloat();
      break;
    case analog_input_2_ID:
      analog_input_2_value = XBee3_read_msg.toFloat();
      break;
    case analog_input_3_ID:
      analog_input_3_value = XBee3_read_msg.toFloat();
      break;
    case analog_input_4_ID:
      analog_input_4_value = XBee3_read_msg.toFloat();
      break;
    case analog_input_5_ID:
      analog_input_5_value = XBee3_read_msg.toFloat();
      break;
    case analog_input_6_ID:
      analog_input_6_value = XBee3_read_msg.toFloat();
      break;
    case analog_input_7_ID:
      analog_input_7_value = XBee3_read_msg.toFloat();
      break;
    case analog_input_8_ID:
      analog_input_8_value = XBee3_read_msg.toFloat();
      break;
    case freq_1_ID:
      freq_1_value = XBee3_read_msg.toFloat();
      break;
    case freq_2_ID:
      freq_2_value = XBee3_read_msg.toFloat();
      break;
    case freq_3_ID:
      freq_3_value = XBee3_read_msg.toFloat();
      break;
    case freq_4_ID:
      freq_4_value = XBee3_read_msg.toFloat();
      break;
    case battery_volt_ID:
      battery_volt_value = XBee3_read_msg.toFloat();
      break;
    case air_temp_ID:
      air_temp_value = XBee3_read_msg.toFloat();
      break;
    case coolant_temp_ID:
      coolant_temp_value = XBee3_read_msg.toFloat();
      break;
    case analog_input_5_therm_ID:
      analog_input_5_therm_value = XBee3_read_msg.toFloat();
      break;
    case analog_input_7_therm_ID:
      analog_input_7_therm_value = XBee3_read_msg.toFloat();
      break;
    case rpm_rate_ID:
      rpm_rate_value = XBee3_read_msg.toFloat();
      break;
    case tps_rate_ID:
      tps_rate_value = XBee3_read_msg.toFloat();
      break;
    case map_rate_ID:
      map_rate_value = XBee3_read_msg.toFloat();
      break;
    case maf_rate_ID:
      maf_rate_value = XBee3_read_msg.toFloat();
      break;
    case lambda_1_measured_ID:
      lambda_1_measured_value = XBee3_read_msg.toFloat();
      break;
    case lambda_2_measured_ID:
      lambda_2_measured_value = XBee3_read_msg.toFloat();
      break;
    case target_lambda_ID:
      target_lambda_value = XBee3_read_msg.toFloat();
      break;
    case pwm_duty_cycle_1_ID:
      pwm_duty_cycle_1_value = XBee3_read_msg.toFloat();
      break;
    case pwm_duty_cycle_2_ID:
      pwm_duty_cycle_2_value = XBee3_read_msg.toFloat();
      break;
    case pwm_duty_cycle_3_ID:
      pwm_duty_cycle_3_value = XBee3_read_msg.toFloat();
      break;
    case pwm_duty_cycle_4_ID:
      pwm_duty_cycle_4_value = XBee3_read_msg.toFloat();
      break;
    case pwm_duty_cycle_5_ID:
      pwm_duty_cycle_5_value = XBee3_read_msg.toFloat();
      break;
    case pwm_duty_cycle_6_ID:
      pwm_duty_cycle_6_value = XBee3_read_msg.toFloat();
      break;
    case pwm_duty_cycle_7_ID:
      pwm_duty_cycle_7_value = XBee3_read_msg.toFloat();
      break;
    case pwm_duty_cycle_8_ID:
      pwm_duty_cycle_8_value = XBee3_read_msg.toFloat();
      break;
    case percent_slip_ID:
      percent_slip_value = XBee3_read_msg.toFloat();
      break;
    case driven_wheel_rate_of_change_ID:
      driven_wheel_rate_of_change_value = XBee3_read_msg.toFloat();
      break;
    case desired_value_ID:
      desired_value_value = XBee3_read_msg.toFloat();
      break;
    case driven_avg_wheel_speed_ID:
      driven_avg_wheel_speed_value = XBee3_read_msg.toFloat();
      break;
    case non_driven_avg_wheel_speed_ID:
      non_driven_avg_wheel_speed_value = XBee3_read_msg.toFloat();
      break;
    case ignition_comp_ID:
      ignition_comp_value = XBee3_read_msg.toFloat();
      break;
    case ignition_cut_percent_ID:
      ignition_cut_percent_value = XBee3_read_msg.toFloat();
      break;
    case driven_wheel_speed_1_ID:
      driven_wheel_speed_1_value = XBee3_read_msg.toFloat();
      break;
    case driven_wheel_speed_2_ID:
      driven_wheel_speed_2_value = XBee3_read_msg.toFloat();
      break;
    case non_driven_wheel_speed_1_ID:
      non_driven_wheel_speed_1_value = XBee3_read_msg.toFloat();
      break;
    case non_driven_wheel_speed_2_ID:
      non_driven_wheel_speed_2_value = XBee3_read_msg.toFloat();
      break;
    case fuel_comp_accel_ID:
      fuel_comp_accel_value = XBee3_read_msg.toFloat();
      break;
    case fuel_comp_starting_ID:
      fuel_comp_starting_value = XBee3_read_msg.toFloat();
      break;
    case fuel_comp_air_temp_ID:
      fuel_comp_air_temp_value = XBee3_read_msg.toFloat();
      break;
    case fuel_comp_coolant_temp_ID:
      fuel_comp_coolant_temp_value = XBee3_read_msg.toFloat();
      break;
    case fuel_comp_barometer_ID:
      fuel_comp_barometer_value = XBee3_read_msg.toFloat();
      break;
    case fuel_comp_map_ID:
      fuel_comp_map_value = XBee3_read_msg.toFloat();
      break;
    case ignition_comp_air_temp_ID:
      ignition_comp_air_temp_value = XBee3_read_msg.toFloat();
      break;
    case ignition_comp_coolant_temp_ID:
      ignition_comp_coolant_temp_value = XBee3_read_msg.toFloat();
      break;
    case BPS_ID:
      BPS_value = XBee3_read_msg.toFloat();
      break;
    case IMU_X_ID:
      IMUX_value = XBee3_read_msg.toFloat();
      break;
    case IMU_Y_ID:
      IMUY_value = XBee3_read_msg.toFloat();
      break;
    case LPS_FL_ID:
      LPSFL_value = XBee3_read_msg.toFloat();
      break;
    case LPS_FR_ID:
      LPSFR_value = XBee3_read_msg.toFloat();
      break;
    case LPS_BL_ID:
      LPSBL_value = XBee3_read_msg.toFloat();
      break;
    case LPS_BR_ID:
      LPSBR_value = XBee3_read_msg.toFloat();
      break;
    case SG_1_ID:
      SG1_value = XBee3_read_msg.toFloat();
      break;
    case SG_2_ID:
      SG2_value = XBee3_read_msg.toFloat();
      break;
    case SG_3_ID:
      SG3_value = XBee3_read_msg.toFloat();
      break;
    case SG_4_ID:
      SG4_value = XBee3_read_msg.toFloat();
      break;
    case SG_5_ID:
      SG5_value = XBee3_read_msg.toFloat();
      break;
    case SG_6_ID:
      SG6_value = XBee3_read_msg.toFloat();
      break;
    case SG_7_ID:
      SG7_value = XBee3_read_msg.toFloat();
      break;
    case SG_8_ID:
      SG8_value = XBee3_read_msg.toFloat();
      break;
    case SG_9_ID:
      SG9_value = XBee3_read_msg.toFloat();
      break;
    case SG_10_ID:
      SG10_value = XBee3_read_msg.toFloat();
      break;
    default:
      break;
  }
}

double XBee3_DAQ::getRPM(){return rpm_value;}
double XBee3_DAQ::getTPS(){return tps_value;}
double XBee3_DAQ::getFuelOpenTime(){return fuel_open_time_value;}
double XBee3_DAQ::getIgnitionAngle(){return ignition_angle_value;}
double XBee3_DAQ::getBarometer(){return barometer_value;}
double XBee3_DAQ::getMAP(){return map_value;}
double XBee3_DAQ::getLambda(){return lambda_value;}
double XBee3_DAQ::getAnalogInput1(){return analog_input_1_value;}
double XBee3_DAQ::getAnalogInput2(){return analog_input_2_value;}
double XBee3_DAQ::getAnalogInput3(){return analog_input_3_value;}
double XBee3_DAQ::getAnalogInput4(){return analog_input_4_value;}
double XBee3_DAQ::getAnalogInput5(){return analog_input_5_value;}
double XBee3_DAQ::getAnalogInput6(){return analog_input_6_value;}
double XBee3_DAQ::getAnalogInput7(){return analog_input_7_value;}
double XBee3_DAQ::getAnalogInput8(){return analog_input_8_value;}
double XBee3_DAQ::getFreq1(){return freq_1_value;}
double XBee3_DAQ::getFreq2(){return freq_2_value;}
double XBee3_DAQ::getFreq3(){return freq_3_value;}
double XBee3_DAQ::getFreq4(){return freq_4_value;}
double XBee3_DAQ::getBatteryVolt(){return battery_volt_value;}
double XBee3_DAQ::getAirTemp(){return air_temp_value;}
double XBee3_DAQ::getCoolantTemp(){return coolant_temp_value;}
double XBee3_DAQ::getAnalogInput5Therm(){return analog_input_5_therm_value;}
double XBee3_DAQ::getAnalogInput7Therm(){return analog_input_7_therm_value;}
double XBee3_DAQ::getRPMRate(){return rpm_rate_value;}
double XBee3_DAQ::getTPSRate(){return tps_rate_value;}
double XBee3_DAQ::getMAPRate(){return map_rate_value;}
double XBee3_DAQ::getMAFRate(){return maf_rate_value;}
double XBee3_DAQ::getLambda1Measured(){return lambda_1_measured_value;}
double XBee3_DAQ::getLambda2Measured(){return lambda_2_measured_value;}
double XBee3_DAQ::getTargetLambda(){return target_lambda_value;}
double XBee3_DAQ::getPWMDutyCycle1(){return pwm_duty_cycle_1_value;}
double XBee3_DAQ::getPWMDutyCycle2(){return pwm_duty_cycle_2_value;}
double XBee3_DAQ::getPWMDutyCycle3(){return pwm_duty_cycle_3_value;}
double XBee3_DAQ::getPWMDutyCycle4(){return pwm_duty_cycle_4_value;}
double XBee3_DAQ::getPWMDutyCycle5(){return pwm_duty_cycle_5_value;}
double XBee3_DAQ::getPWMDutyCycle6(){return pwm_duty_cycle_6_value;}
double XBee3_DAQ::getPWMDutyCycle7(){return pwm_duty_cycle_7_value;}
double XBee3_DAQ::getPWMDutyCycle8(){return pwm_duty_cycle_8_value;}
double XBee3_DAQ::getPercentSlip(){return percent_slip_value;}
double XBee3_DAQ::getDrivenWheelRateOfChange(){return driven_wheel_rate_of_change_value;}
double XBee3_DAQ::getDesiredValue(){return desired_value_value;}
double XBee3_DAQ::getDrivenAvgWheelSpeed(){return driven_avg_wheel_speed_value;}
double XBee3_DAQ::getNonDrivenAvgWheelSpeed(){return non_driven_avg_wheel_speed_value;}
double XBee3_DAQ::getIgnitionComp(){return ignition_comp_value;}
double XBee3_DAQ::getIgnitionCutPercent(){return ignition_cut_percent_value;}
double XBee3_DAQ::getDrivenWheelSpeed1(){return driven_wheel_speed_1_value;}
double XBee3_DAQ::getDrivenWheelSpeed2(){return driven_wheel_speed_2_value;}
double XBee3_DAQ::getNonDrivenWheelSpeed1(){return non_driven_wheel_speed_1_value;}
double XBee3_DAQ::getNonDrivenWheelSpeed2(){return non_driven_wheel_speed_2_value;}
double XBee3_DAQ::getFuelCompAccel(){return fuel_comp_accel_value;}
double XBee3_DAQ::getFuelCompStarting(){return fuel_comp_starting_value;}
double XBee3_DAQ::getFuelCompAirTemp(){return fuel_comp_air_temp_value;}
double XBee3_DAQ::getFuelCompCoolantTemp(){return fuel_comp_coolant_temp_value;}
double XBee3_DAQ::getFuelCompBarometer(){return fuel_comp_barometer_value;}
double XBee3_DAQ::getFuelCompMAP(){return fuel_comp_map_value;}
double XBee3_DAQ::getIgnitionCompAirTemp(){return ignition_comp_air_temp_value;}
double XBee3_DAQ::getIgnitionCompCoolantTemp(){return ignition_comp_coolant_temp_value;}
double XBee3_DAQ::getBPS(){return BPS_value;}
double XBee3_DAQ::getIMUX(){return IMUX_value;}
double XBee3_DAQ::getIMUY(){return IMUY_value;}
double XBee3_DAQ::getLPSFL(){return LPSFL_value;}
double XBee3_DAQ::getLPSFR(){return LPSFR_value;}
double XBee3_DAQ::getLPSBL(){return LPSBL_value;}
double XBee3_DAQ::getLPSBR(){return LPSBR_value;}
double XBee3_DAQ::getSG1(){return SG1_value;}
double XBee3_DAQ::getSG2(){return SG2_value;}
double XBee3_DAQ::getSG3(){return SG3_value;}
double XBee3_DAQ::getSG4(){return SG4_value;}
double XBee3_DAQ::getSG5(){return SG5_value;}
double XBee3_DAQ::getSG6(){return SG6_value;}
double XBee3_DAQ::getSG7(){return SG7_value;}
double XBee3_DAQ::getSG8(){return SG8_value;}
double XBee3_DAQ::getSG9(){return SG9_value;}
double XBee3_DAQ::getSG10(){return SG10_value;}