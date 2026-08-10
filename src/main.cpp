#include <Arduino.h>
#include <vehicle.h>
#include <ultrasonic.h>
#include <ESP32Servo.h>

vehicle myCar;
Servo myServo;

#define leftLED 2
#define rightLED 12
#define Anticlockwise Contrarotate 
#define buzzer 33
#define servoPin 25 

/*
myCar.Move(Forward, 255):
myCar.Move(Backward, 255):

myCar.Move(Clockwise, 255):
myCar.move(Contrarotate, 255)
myCar.Move(Anticlockwise, 255):

myCar.Move(Move_Left, 255):
myCar.Move(Move_Right, 255):
*/

void setup(){
  myCar.Init();
  myCar.Move(Forward,255);
  delay(750);
  myCar.Move(Clockwise,255);
  delay(750);
  myCar.Move(Forward,255);
  delay(750);
  myCar.Move(Clockwise,255);
  delay(750);
  myCar.Move(Forward,255);
  delay(750);
  myCar.Move(Contrarotate, 255);
  delay(750);
  myCar.Move(Forward,255);
  delay(750);
  myCar.Move(Contrarotate, 255);
  delay(750);
  myCar.Move(Forward,255);
  delay(750);
  myCar.Move(Move_Right,255);
  delay(750);
  myCar.Move(Stop,0);
}

void loop()
{
  //digitalWrite(leftLED, HIGH);
  //digitalWrite(rightLED, LOW);
  //myCar.Move(Move_Left, 255);
  //tone(buzzer, 262);

  //delay(1000);

  //digitalWrite(leftLED, LOW);
  //digitalWrite(rightLED, HIGH);
  //myCar.Move(Move_Right, 255);
  //noTone(buzzer);

  //delay(1000);
}
