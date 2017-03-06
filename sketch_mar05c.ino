int interval = 1000;
unsigned long previousMillis = millis();
int pulseState = LOW;
#include <LIDARLite.h>
#include <Wire.h>

LIDARLite myLidarLite;

void setup() {
  // put your setup code here, to run once:
  pinMode(2, OUTPUT);
  pinMode(4, OUTPUT);
  Serial.begin(115200);
  myLidarLite.begin(0, true);
}

void loop() {
  // put your main code here, to run repeatedly:
  unsigned int currentMillis = millis();
  
  Serial.println(myLidarLite.distance(false));
  
  int lidarDistance = myLidarLite.distance(false);
  
  interval = 500 + lidarDistance;
  
  if(currentMillis - previousMillis >= interval){
    previousMillis = currentMillis;

    if(pulseState == LOW){
      pulseState = HIGH;
    }
    else {
      pulseState = LOW;
    }
    digitalWrite(2, pulseState);
  }
  if(lidarDistance < 100){
    digitalWrite(4, HIGH);
  }
  else
    {digitalWrite(4, LOW);}
}
