#include <Arduino.h>
#include <vehicle.h>
#include <ultrasonic.h>
#include <ESP32Servo.h>

vehicle myCar;

#define leftLED 2
#define rightLED 12
#define Anticlockwise Contrarotate 

void setup()
{
 Serial.begin(115200);
 pinMode(leftLED, OUTPUT);
 pinMode(rightLED, OUTPUT);

 myCar.Init();
}

void loop()
{
  digitalWrite(leftLED, HIGH);
  digitalWrite(rightLED, LOW);
  myCar.Move(Move_Left, 255);
  delay(1000);

  digitalWrite(leftLED, LOW);
  digitalWrite(rightLED, HIGH);
  myCar.Move(Move_Right, 255);
  delay(1000);

}
