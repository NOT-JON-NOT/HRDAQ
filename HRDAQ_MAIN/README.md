# Hartford Racing Formula SAE Custom Data Acquisition System

## Table of Contents

[1. Introduction](#1.-introduction)  
[2. Features](#2.-features)
[3. Construction](#3.-construction)
[3.1. External Hardware](#3.1.-external-hardware)
[3.2. Required Software/Libraries](#3.2.-required-software/libraries)


## 1. Introduction
Hartford Racing (HR) is a student-led Formula SAE (FSAE) team tasked with designing, fabricating, testing, and racing a Formula-style racecar each year to compete at an international competition against universities from around the world. 

This custom data acquisition system (HRDAQ) was developed to obtain FSAE race car telemetry from various sources, monitor systems, provide driver feedback, and numerically validate design decisions/driver practice using recorded and analyzed data. 

## 2. Features
- CAN bus 2.0 data collection
- Various sensors:
  - Brake pressure sensor (BPS)
  - Inertial measurement unit (IMU)
  - Linear position sensor (LPS)
  - Linear strain gauge (120 Ohm) (SG)
  - Fuel level sensor (FLS)
- Wireless telemetry
- RPM lights
- Status lights (battery level status, fuel level status, neutral status, coolant up to temp status, coolant outside temp status)
- SD-card functionality 
- Waterproof casing, small footprint
- 5V fused input compatibility
- 21V digital input compatibility
- 10V analog input compatibility (reserved)
- Multiple 3.3V outputs
- ESD and reverse polarity protection
- Custom pit crew GUI
- USB programming

## 3. Construction
## 3.1. External Hardware
- ECU: PE3-8400 ECU (Can be modified but requires software modification)
- Sensors:
  - BPS: SPT25-20-3000A
  - LPS: PZ12-S-0075-L
  - IMU: GIB-XY-085-V-2A
  - SG: SGD-10/120-LY11
  - FLS: N/A (no available P/N, proprietary)

## 3.2. Required Software/Libraries
- Arduino IDE 2.X
  - TeensyDuino (FlexCAN_t4 & NeoPixel libraries)
- Digi XCTU
- Altium Designer (if redesigning HRDAQ PCB)

## 3.3 Custom Printed Circuit Boards
### 3.3.1. Custom Printed Circuit Boards Design
All PCBs were designed in Altium Designer, refer to the following table for specific rules related to the design of the HRDAQ PCB:

| Rule  | Notes |
| ------------- | ------------- |
| Clearance  | Ignore Pad-to-Pad within footprint |
| Width outside BGA | 0.127mm to 1mm  |
| Width inside BGA | 0.1mm to 0.254mm  |
| Vias outside BGA | 0.48mm diameter, 0.25mm hole |
| Vias inside BGA | 0.654mm to 1mm diameter, 0.254mm to 0.6mm hole, tented vias |
| Plane Connect Style| Direct |
| Plane Clearance | 0.254mm |
| Hole Size | Max=6.3mm (for physical screws) |

The RPM and status LEDs PCBs have standard rulesets. If you are redesigning the HRDAQ, you should create room definitions for the BGA and XBee3 module. This will help with organization and setting custom rules. Generally, you should keep the oscillators away from inductors, inductors away from each other, digitals away from analogs, radio away from everything, and create planes to minimize EMI. BGA routing is not too hard, fanout first then connect. 

Most footprints and symbols are custom. Please contact Hartford Racing, specifically Jon Ho, for related questions.

### 3.3.2. Custom Printed Circuit Boards Manufacturing

Send the included Gerber files within this repository to your preferred PCB manufacturer. Make sure that your PCB manufacturer is capable of manufacturing 0.1mm minimum trace width, 0.25mm minimum drill size, 6-layer PCB, and BGA related manufacturing. 

(Pending PCBWay response for specifics)

## 3.4 Custom 3D-Printed Enclosure
### 3.4.1. Custom 3D-Printed Enclosure Design
3D-Printed enclosure is designed to house HRDAQ. Designed to allow access to the SD-card port, micro-usb port, RF port, and DSUB connector. Fitted with M3 screws and approximately 3mm of clearance between edge of PCB and enclose wall. Contains removable top. 

Pictures to be posted once 3D-printed, validated, and finalized

### 3.4.2. Custom 3D-Printed Enclosure Manufacturing
Refer to the following table for 3D-print settings with your preferred slicer & 3D-printer:

| Setting  | Notes |
| ------------- | ------------- |
| Filament Type | PETG |
| Wall Loops | 3 |
| Infill | 25% |
| Infill Pattern | Rectilinear |

PETG should be used due to the greater UV and impact resistance at a relatively cheaper cost compared to other filaments. Any other engineering grade filament may be used, but PLA is discouraged. Print the enclosure with the top facing upwards.

## 4. Setup
## 4.1. PCB Pinouts
Refer to the following table for the HRDAQ pinout:

| Name  | DSUB Connector Pin |
| ------------- | ------------- |
| CAN HI INPUT | 36 |
| CAN LO INPUT | 35 |
| LPS FL INPUT | 12 |
| LPS FR INPUT | 31 |
| LPS BL INPUT | 30 |
| LPS BR INPUT | 11 |
| BPS INPUT | 13 |
| IMUX INPUT | 14 |
| IMUY INPUT | 32 |
| RPM Lights OUTPUT | 15 |
| Status Lights OUTPUT | 33 |
| SG1 INPUT | 29 |
| SG2 INPUT | 28 |
| SG3 INPUT | 10 |
| SG4 INPUT | 9 |
| SG5 INPUT | 27 |
| FLS INPUT | 16 |
| DIGITAL INPUT 1 | 17 |
| DIGITAL INPUT 2 | 18 |
| DIGITAL OUTPUT 2 | 37 |
| DIGITAL OUTPUT 1 | 19 |
| 5V INPUT | 25,34 |
| 3.3V OUTPUT | 4, 5, 6, 22, 23, 24 |
| GND | 1, 2, 3, 7, 8, 20, 21, 26 |

Refer to the following table for the HRDAQ RPM and status LEDs pinout:
| Name  | Molex Connector Pin |
| ------------- | ------------- |
| Signal | 1 |
| 3.3V INPUT | 2 |
| GND | 3 |

## 4.2. Hardware Setup

The following steps were applied to setup the HRDAQ hardware:

1. Ensure that the dashboard has been sized appropriately to fit all components.
2. Construct and manufacture the enclosure and custom PCBs according to previous section. To attach HRDAQ to enclosure, use M3 screws. Connect an RPSMA antenna and SD-card to their respective ports.
3. Construct the external DSUB connector using standard crimping tools. Ensure that wiring is long enough to reach any sensor position. Connect the DSUB to HRDAQ. 
4. Connect status and RPM LEDs PCBs, chosen sensors, ECU CAN lines, and 5V input according to the pinout. Sensors on the HR24 (Hartford Racing 2024 racecar) use 12V or 3.3V supply. Ensure that sensors are secure

(Pending photos once manufacturing phase has been completed)


## 4.3. Software Setup

The following steps were applied to setup the HRDAQ software:

1. Power the HRDAQ using 5V and connect to the device using a micro-usb
2. Ensure that the device is connected using Windows device manager or related tool
3. Upload "HRDAQ_EEPROM_INIT" to initialize the naming of each csv file in the SD-card
4. Upload "HRDAQ_MAIN"

(Wireless GUI currently being developed, pending instructions)

## 5. Usage

Once you conduct tests, the HRDAQ should collect data and record it onto the SD-card. The SD-card should be taken out to analyze data. The SD-card should reinitialize another dataset recording once the wheel speed identified through CAN becomes 0 (the racecar stops).

(Wireless GUI currently being developed, pending instructions)

## 6. Notes
## 6.1. Hardware Notes
- Used LPS have approximately 0.5 mm measurement error

## 6.2. Software Notes
- Our ECU manufacturer, Performance Electronics, has incorrect documentation regarding their CAN lines, specifically with the PE7 address. Proceed with caution. 
- The MCU uses a 10 bit ADC. If a greater resolution is required, the number of bits may be changed with a Teensy 4.1 library
- Strain gauge equations (taken from Omega) are listed:
  - Equation 1: Vout/Vin = (R3/(R3+R_SG) - R2/(R1+R2))
  - Equation 2: Vr = (Vout/Vin)strained - (Vout/Vin)unstrained, (Vout/Vin)unstrained = 0 ideally
  - Equation 3: Strain = -4Vr/(Gauge_Factor*(1+2*Vr))
  - Gauge factor is typically supplied by the manufacturer on the packaging
- DAQ = refers to data acquisition system as a whole
- MB = all related to flexCAN mailboxes
- PE & PE3 = all related to Performace Electronics
- CAN = controller area network
- OBJ = object
- MSG = message
- RPB = resolution per bit, related to Performance Electronics
- RPM, TPS, MAP, MAF, PWM, etc = acronyms related to CAN bus of Performace Electronics

## 7. Datasheets & Links
- [CAN Transceiver Datasheet](https://www.ti.com/lit/ds/symlink/sn65hvd232.pdf?ts=1697949369432&ref_url=https%253A%252F%252Fwww.ti.com%252Fproduct%252FSN65HVD232)
- [PE3 CAN bus Datasheet](https://pe-ltd.com/assets/AN400_CAN_Protocol_C.pdf)
- [LPS Datasheet](https://cdn.automationdirect.com/static/specs/gefranpz12linpots.pdf)
- [BPS Datasheet](https://cdn.automationdirect.com/static/specs/prosensespt25transmitters.pdf)
- [IMU Datasheet](https://cdn.automationdirect.com/static/specs/gibinclinationsensor.pdf)
- [XBee3 Datasheet](https://www.digi.com/resources/documentation/digidocs/pdfs/90001543.pdf)
- [Sparkfun XBee3 Explorer Schematic](https://cdn.sparkfun.com/datasheets/Wireless/Zigbee/XBee-Explorer-v21b.pdf)
- [Adafruit NeoPixels](https://www.adafruit.com/product/1655)
- [Adafruit Buck Converter Datasheet](https://github.com/adafruit/Adafruit-MPM3610-PCB)
- [General Strain Gauge Usage](https://www.omega.co.uk/techref/pdf/straingage_measurement.pdf)
- [Strain Gauge Datasheet](https://assets.omega.com/pdf/test-and-measurement-equipment/strain-gauges/SGD_LINEAR1-AXIS.pdf)
- [Analogs TVS Diode Datasheet](https://www.mouser.com/datasheet/2/240/media-3322571.pdf)
- [AMD BGA Routing Guide](https://docs.xilinx.com/r/en-US/ug1099-bga-device-design-rules)

## License
[MIT](https://choosealicense.com/licenses/mit/)