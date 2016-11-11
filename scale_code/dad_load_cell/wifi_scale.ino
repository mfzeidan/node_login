#include "HX711.h"

#define DOUT  14
#define CLK  12

//3.3V —- VCC

//GPIO14 — SCK

//GPIO12 — DT

//GND —- GND




//https://www.youtube.com/watch?v=ldwCY-koNyA
//https://www.youtube.com/watch?v=nGUpzwEa4vg
// INSTRUCTIONS
// HOW TO CALIBRATE YOUR SCALE

// Call set_scale() with no parameter
// Call Tare() with no parameter
// Place a known weight on the scale and call get_units(10)
// Divide the result in step 3 to your known weight. This will give you the parameter you need to pass to set_scale()
// Adjust the parameter above until you get an accurate reading


// The first time you get this you should get a number like -44000.00 or something
// for example, if you placed 10gs on this, you would do

// -44000/10 and will give you X

// Pass X into  scale.set_scale(X);



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
  
   
   //after you get your seed value, remove cale.set_scale(); from above and put cale.set_scale(seed_X);
   // then remove scale.tare(); from above and paste it here
   //Serial.println(//variable);
   delay(500);
   
}
