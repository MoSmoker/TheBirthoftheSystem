#include <Wire.h>

#define switch1 3
#define switch2 4

int sw1 = 0;
int sw2 = 0;

void setup() {
  // put your setup code here, to run once:
  Wire.begin(10);
  Serial.begin(9600);
  Wire.onRequest(pused_button);
  pinMode(switch1, INPUT);
  pinMode(switch2, INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  sw1 = digitalRead(switch1);
  sw2 = digitalRead(switch2);
}

void pused_button()
{
  if((sw1 == HIGH) && (sw2 == HIGH))
  {
    Wire.write(3);
    Serial.print("Glitch\n");
    delay(1000);
  }
  else if((sw1 == HIGH) && (sw2 == LOW))
  {
    Wire.write(1);
    Serial.print("Vector focused\n");
    delay(1000);
  }
  else if((sw2 == HIGH) && (sw1 == LOW))
  {
    Wire.write(2);
    Serial.print("Vector distracted\n");
    delay(1000);
  }
  else
  {
    Wire.write(0);
    Serial.print("No Message\n");
    delay(1000);
  }

  sw1 = 0;
  sw2 = 0;
}