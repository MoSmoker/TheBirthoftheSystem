const int PingPinSensor_1 = 2;
const int echoSensor_1 = 3;

const int PingPinSensor_2 = 4;
const int echoSensor_2 = 5;

const int PingPinSensor_3 = 6;
const int echoSensor_3 = 7;

const int PingPinSensor_4 = 8;
const int echoSensor_4 = 9;

long duration, cm;
float distance;

#define CHAMPER_WIDTH 5.0
#define CHAMPER_LENGTH 6.0

void setup() 
{
  // put your setup code here, to run once:
}

void loop() 
{
  // put your main code here, to run repeatedly:
  float distances[4], x, y;
  for(int i = 0; i < 4 ; i++)
  {
    distances[i] = GetDistance((2 * i) + 2, (2 * i) + 3);
    if(distances[i] == -1)
    {
      Serial.print("Out of Range");
    }
    else{}
    Serial.print("Distance ");
    Serial.printf(i);
    Serial.print("= ");
    Serial.print(distances[i]);
    Serial.print("\n");
    delay(100);

  }

  Coordinates(distances, x, y);
  Serial.print("X: ");
  Serial.print(x);
  Serial.print("\t");
  Serial.print("Y: ");
  Serial.print(y);

  delay(2000);
}

float GetDistance(int trigglePin , int echoPin)
{
  pinMode(trigglePin, OUTPUT);
  digitalWrite(trigglePin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigglePin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigglePin, LOW);
  pinMode(echoPin, INPUT);
  duration = pulseIn(echoPin, HIGH);
  cm = ((duration/2)/29);
  distance = cm/100;

  if(8 < distance)
  {
    return -1;
  }
  else
  {
    return distance;
  }
}

void Coordinates(float distances[4], float &x, float &y)
{
  float alpha;
  float beta;
  float A;
  float B;

  alpha = atan2(distances[0], distances[1]);
  beta = atan2(distances[2], distances[3]);

  A = squrt(distances[0] * distances[1]);
  B = squrt(distances[2] * distances[3]);

  x = ( (A * sin(alpha)) + CHAMPER_WIDTH - (b * sin(beta)) );
  y = ( (A * cos(alpha)) + CHAMPER_LENGTH - (b * cos(beta)) );
}
