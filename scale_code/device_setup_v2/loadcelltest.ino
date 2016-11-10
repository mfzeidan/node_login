#include "HX711.h"

#define DOUT  12
#define CLK  14

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
