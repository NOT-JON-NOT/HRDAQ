# Hartford Racing Formula SAE Custom Data Acquisition & Driver Feedback System

## Table of Contents

1. [Introduction](#1-introduction)  
2. [Features](#2-features)
3. [Construction](#3-construction)
- 3.1. [External Hardware](#31-external-hardware)
- 3.2. [Required Software/Libraries](#32-required-softwarelibraries)
- 3.3. [Custom Printed Circuit Boards](#33-custom-printed-circuit-boards)
    - 3.3.1. [Custom Printed Circuit Boards Design](#331-custom-printed-circuit-boards-design)
    - 3.3.2. [Custom Printed Circuit Boards Manufacturing](#332-custom-printed-circuit-boards-manufacturing)
- 3.4. [Custom 3D-Printed Enclosure](#34-custom-3d-printed-enclosure)
    - 3.4.1. [Custom 3D-Printed Enclosure Design](#341-custom-3d-printed-enclosure-design)
    - 3.4.2. [Custom 3D-Printed Enclosure Manufacturing](#342-custom-3d-printed-enclosure-manufacturing)
4. [Setup](#4-setup)
- 4.1. [Software Setup](#41-software-setup)
- 4.2. [PCB Pinouts](#42-pcb-pinouts)
- 4.3. [Hardware Setup](#43-hardware-setup)
5. [Usage](#5-usage)
6. [Notes](#6-notes)
- 6.1. [Hardware Notes](#61-hardware-notes)
- 6.2. [Software Notes](#62-software-notes)
7. [Datasheets & Links](#7-datasheets--links)

## 1. Introduction
Hartford Racing (HR) is a student-led Formula SAE (FSAE) team tasked with designing, fabricating, testing, and racing a Formula-style racecar each year to compete at an international competition against universities from around the world. 

This custom data acquisition system (HRDAQ) and driver feedback system was developed to obtain FSAE race car telemetry from various sources, monitor systems, provide driver feedback, and numerically validate design decisions/driver practice using recorded and analyzed data. 

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
- Small footprint enclosure
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

The purpose of designing custom PCBs for the RPM LEDs, status LEDs, and HRDAQ is to fit data acquisition and driver feedback components within a small and lightweight package while maintaining only necessary features. The HRDAQ PCB also removes unnecessary features from the MCUs it is based on, the Teensy 4.1 and XBee3. To reduce the chance of ESD damage, multiple TVS diodes and ferrite inductors were included within the design. To enable reverse polarity protection, two DMG2305UX-13 mosfets were included within the design. 

From the [Teensy 4.1](https://www.pjrc.com/store/teensy41.html), the VHST section, battery section, PSRAM, Flash, DP83825 chip and supporting capacitors, and VUSB from an auxiliary USB were all removed. None are used within the prototype design of the HRDAQ.

USB programming was kept for both the Serial to SMD XBee3 and MIMXRT1062DVJ6B BGA. Programming both devices while powered by a 5V input should be safe. Reset buttons for programming were also kept. These features were kept for convenience of troubleshooting. 

The digital inputs design was based on a 21V to 3.3V [buck converter design](https://github.com/adafruit/Adafruit-MPM3610-PCB) produced and manufactured by Adafruit. The analog inputs design is a voltage divider with included TVS diodes. Since signal speeds for this MCU are low frequency, there (seems to be) no need to overcomplicate the analogs step down circuit.

The RPM LEDs and status LEDs PCBs are designed to be mounted with M2 screws, while the HRDAQ is designed to be mounted with M3 screws. Small screws were chosen due to the overall size of each PCB. 

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
| Hole Size | Max = 6.3mm (for physical screws) |

The RPM and status LEDs PCBs have standard rulesets. 

If you are redesigning the HRDAQ, you should create room definitions for the BGA and XBee3 module. This will help with organization and setting custom rules. Generally, you should keep the oscillators away from inductors, inductors away from each other, digitals away from analogs, radio away from everything, and create planes to minimize EMI. BGA routing is not too hard, fanout first then connect. Refer to the [XBee3 design considerations](https://www.digi.com/resources/documentation/digidocs/90001543/#reference/r_design_notes_smt_rf.htm?TocPath=Design%2520notes%257C_____5) when designing for the SMD XBee3. 

Photos of HRDAQ, RPM LEDs, and Status LEDs PCBs:

![HRDAQ_PCB_IMG_1](/HRDAQ_IMGs/HRDAQ_PCB_IMG_1.PNG)
![HRDAQ_PCB_IMG_2](/HRDAQ_IMGs/HRDAQ_PCB_IMG_2.PNG)
![HRDAQ_PCB_IMG_3](/HRDAQ_IMGs/HRDAQ_PCB_IMG_3.PNG)
![HRDAQ_PCB_IMG_4](/HRDAQ_IMGs/HRDAQ_PCB_IMG_4.PNG)
![HRDAQ_RPM_LEDs_PCB_IMG_1](/HRDAQ_IMGs/HRDAQ_RPM_LEDs_PCB_IMG_1.PNG)
![HRDAQ_RPM_LEDs_PCB_IMG_2](/HRDAQ_IMGs/HRDAQ_RPM_LEDs_PCB_IMG_2.PNG)
![HRDAQ_Status_LEDs_PCB_IMG_1](/HRDAQ_IMGs/HRDAQ_Status_LEDs_PCB_IMG_1.PNG)
![HRDAQ_Status_LEDs_PCB_IMG_2](/HRDAQ_IMGs/HRDAQ_Status_LEDs_PCB_IMG_2.PNG)

Most footprints and symbols are custom. Please contact Hartford Racing, specifically Jon Ho, for related questions.

### 3.3.2. Custom Printed Circuit Boards Manufacturing

Send the included Gerber files within this repository to your preferred PCB manufacturer. Make sure that your PCB manufacturer is capable of manufacturing 0.1mm minimum trace width, 0.25mm minimum drill size, 6-layer PCB, and BGA related manufacturing. 

Additionally, send the Teensy 4.1 [bootloader](https://www.pjrc.com/store/ic_mkl02_t4.html) to the manufacturer. Without this IC, the board will fail to initialize. 

*An error was discovered by the manufacturer related to the RP-SMA connector. Replace the initial RP-SMA connector with another that has a 1.6mm gap

## 3.4 Custom 3D-Printed Enclosure
### 3.4.1. Custom 3D-Printed Enclosure Design

3D-Printed enclosure is designed to house HRDAQ. The enclosure is designed to allow access to the SD-card port, micro-USB port, RF port, and DSUB connector. It also allows HRDAQ to be secured with M3 screws and has approximately 3mm of clearance between edge of PCB and enclose wall. The enclosure contains removable top. 

Photos of HRDAQ in 3D-printed enclosure:
![HRDAQ_PHYSICAL_1](/HRDAQ_IMGs/HRDAQ_PHYSICAL_1.jpg)
![HRDAQ_PHYSICAL_2](/HRDAQ_IMGs/HRDAQ_PHYSICAL_2.jpg)

### 3.4.2. Custom 3D-Printed Enclosure Manufacturing
Refer to the following table for 3D-print settings with your preferred slicer & 3D-printer:

| Setting  | Notes |
| ------------- | ------------- |
| Filament Type | PETG |
| Wall Loops | 3 |
| Infill | 25% |
| Infill Pattern | Rectilinear |

PETG should be used due to the greater UV and impact resistance at a relatively cheaper cost compared to other filaments. Any other engineering grade filament may be used, but PLA is discouraged. Print the enclosure with the top facing upwards. Wall loops help prevent water from entering the enclosure, but epoxy or similar compound should be used to further prevent water from entering.

## 4. Setup
## 4.1. Software Setup

The following steps were applied to setup the HRDAQ software:

1. Power the HRDAQ using 5V and connect to the device using a micro-USB
2. Ensure that all require software related to Arduino 2.X is downloaded
3. Ensure that the device is connected using Windows device manager or related tool
4. Upload "HRDAQ_EEPROM_INIT" to initialize the naming of each csv file in the SD-card
5. Upload "HRDAQ_MAIN"

(Wireless GUI currently under refinement, pending instructions)

## 4.2. PCB Pinouts
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

## 4.3. Hardware Setup

The following steps were applied to setup the HRDAQ hardware:

1. Ensure that the dashboard has been sized appropriately to fit all components.
2. Construct and manufacture the enclosure and custom PCBs according to previous section. To attach HRDAQ to the enclosure, use M3 screws; To attach the RPM LEDs and status LEDs PCBs, use M2 screws. Connect an RPSMA antenna and SD-card to their respective ports. To secure the enclosure, use (TBD) screws.
3. Construct the external DSUB connector using standard crimping tools. Ensure that wiring is long enough to reach any sensor position. Connect the DSUB to HRDAQ. 
4. Connect status and RPM LEDs PCBs, chosen sensors, ECU CAN lines, and 5V input according to the pinout. Sensors on the HR24 (Hartford Racing 2024 racecar) use 12V or 3.3V supply. Ensure that sensors are secure.

## 5. Usage

Once you conduct tests, the HRDAQ should collect data and record it onto the SD-card and should be taken out to analyze data. The SD-card should reinitialize another dataset recording once the wheel speed identified through CAN becomes 0 (the racecar stops).

(Wireless GUI currently under refinement, pending instructions)

## 6. Notes
## 6.1. Hardware Notes
- Used LPS have approximately 0.5 mm measurement error
- Bill of materials is included within this repository
- Supporting bill of materials is included within this repository for parts outside the PCBs not including sensors. Sensors are listed in section 7.

## 6.2. Software Notes
- Our ECU manufacturer, Performance Electronics, has incorrect documentation regarding their CAN lines, specifically with the PE7 address. Proceed with caution. 
- The MCU uses a 10-bit ADC. If a greater resolution is required, the number of bits may be changed with a Teensy 4.1 library.
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
- [SMD XBee3 Design Notes](https://www.digi.com/resources/documentation/digidocs/90001543/#reference/r_design_notes_smt_rf.htm?TocPath=Design%2520notes%257C_____5)
- [Sparkfun XBee3 Explorer Schematic](https://cdn.sparkfun.com/datasheets/Wireless/Zigbee/XBee-Explorer-v21b.pdf)
- [Adafruit NeoPixels](https://www.adafruit.com/product/1655)
- [Adafruit Buck Converter Datasheet](https://github.com/adafruit/Adafruit-MPM3610-PCB)
- [General Strain Gauge Usage](https://www.omega.co.uk/techref/pdf/straingage_measurement.pdf)
- [Strain Gauge Datasheet](https://assets.omega.com/pdf/test-and-measurement-equipment/strain-gauges/SGD_LINEAR1-AXIS.pdf)
- [Analogs TVS Diode Datasheet](https://www.mouser.com/datasheet/2/240/media-3322571.pdf)
- [AMD BGA Routing Guide](https://docs.xilinx.com/r/en-US/ug1099-bga-device-design-rules)

## License
[MIT](https://choosealicense.com/licenses/mit/)

