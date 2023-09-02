/* Provided link below refer to the simulation of circuit - ckeck it out  
   https://www.tinkercad.com/things/iBejP99Cd3p
*/

#include <Wire.h>

#define LED 11

int recieve = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Wire.begin();
  pinMode(LED, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  Wire.requestFrom(10, 1);
  
  recieve = Wire.read();
  {
    if(3 == recieve)
    {
      //I used PWM technique just in this state
      for(int i=0; i < 255; i++)
      {
      analogWrite(LED, i);
      }
      Serial.print("Glitch\n");
      delay(1000);
    }
    else if(1 ==  recieve)
    {
      //As noticed I only used analogWrite() func straight forward
      analogWrite(LED, 128);
      Serial.print("Vector focused\n");
      delay(1000);
    }
    else if(2 ==  recieve)
    {
      //here as well without PWM technique 
      analogWrite(LED, 192);
      Serial.print("Vector distracted\n");
      delay(1000);
    }
    else
    {
      analogWrite(LED, 0);
      Serial.print("No Message\n");
      delay(1000);
    }
  }

}
