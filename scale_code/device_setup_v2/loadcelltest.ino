#include "HX711.h"

#define DOUT  12
#define CLK  14

// INSTRUCTIONS
// HOW TO CALIBRATE YOUR SCALE

// Call set_scale() with no parameter
// Call Tare() with no parameter
// Place a known weight on the scale and call get_units(10)
// Divide the result in step 3 to your known weight. This will give you the parameter you need to pass to set_scale()
// Adjust the parameter above until you get an accurate reading



HX711 scale(DOUT, CLK);

void setup(){

   Serial.begin(9600);

   scale.set_scale();

   scale.tare();

   Serial.println("place weight on scale");
   while (!Serial.available()) {};

   float x = scale.get_units(10);
   Serial.print ("Set scale value is ");
   Serial.println(x);
  
}

void loop(){
  
}
