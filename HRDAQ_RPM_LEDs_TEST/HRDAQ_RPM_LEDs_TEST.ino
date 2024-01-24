/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * HARTFORD RACING FSAE                                                          *
 * Author: Jon Ho, CompE & EE 24'                                                *
 *                                                                               *
 * Required libraries:                                                           *
 * - https://www.pjrc.com/teensy/td_download.html (Teensyduino)                  *
 *                                                                               *
 * Notes:                                                                        *
 * - Purpose: Test code for RPM_LEDs_PCB                                         *
 * - Use a potentiometer and connect it to A0 of a bare Teensy 4.1               *
 * - Use standard Neopixel libraries to test Status_LEDs_PCB                     *
 *                                                                               *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#include <Adafruit_NeoPixel.h>
int RPM_LEDs_pin        = 10;  //Pin connected to RPM_LEDs PCB
int RPM_LEDs_brightness = 255; //Brightness of all Neopixels on RPM_LEDs PCB
int pot_pin             = A0;  //Analog pin of pot to test RPM_LEDs PCB
#define NUMPIXELS      10      //Number of Neopixels on RPM_LEDs PCB
#define MAX_RPM        255     //Maximum RPM of car
#define MIN_RPM        0       //Minimum RPM of car

Adafruit_NeoPixel RPM_LEDs = Adafruit_NeoPixel(NUMPIXELS, RPM_LEDs_pin, NEO_GRB + NEO_KHZ800);

unsigned long last_update_time = 0;
unsigned long blink_interval   = 100; //Blink rate in milliseconds

void setup(){
  RPM_LEDs.begin();
  RPM_LEDs.show(); //Initialize all pixels to 'off'
  RPM_LEDs.setBrightness(RPM_LEDs_brightness);
}

void loop(){
  int rpm = analogRead(pot_pin);

  if(rpm > MAX_RPM){blinkRed();} 
  else{
    int num_pixels = map(rpm, MIN_RPM, MAX_RPM, 0, NUMPIXELS);

    //Display the RPM on the Neopixels with color gradient
    for(int i = 0; i < NUMPIXELS; i++) {
      //Calculate the distance of the pixel from the nearest edge
      int edge_distance = min(i, NUMPIXELS - 1 - i);

      //Map the LEDs based on the distance and RPM
      if(edge_distance <= num_pixels / 2){
        uint32_t color = mapColor(rpm);
        RPM_LEDs.setPixelColor(i, color);
      } 
      else{
        RPM_LEDs.setPixelColor(i, RPM_LEDs.Color(0, 0, 0)); //Turn off the remaining pixels
      }
    }
    RPM_LEDs.show();
  }
}

//Function to map color based on RPM
uint32_t mapColor(int rpm) {
  // Adjust these values based on your RPM range
  if(rpm < 50){
    return RPM_LEDs.Color(0, 255, 0); //Green
  } 
  else if(rpm < 150){
    return RPM_LEDs.Color(255, 255, 0); //Yellow
  } 
  else{
    return RPM_LEDs.Color(255, 0, 0); //Red
  }
}

//Function to make all Neopixels blink in red
void blinkRed(){
  unsigned long current_time = millis();

  if(current_time - last_update_time >= blink_interval){
    last_update_time = current_time;
    static bool is_red = false;

    if(is_red){RPM_LEDs.fill(RPM_LEDs.Color(0, 0, 0));} 
    else{RPM_LEDs.fill(RPM_LEDs.Color(255, 0, 0));}

    is_red = !is_red;
    RPM_LEDs.show();
  }
}
