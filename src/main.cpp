#include <Arduino.h>
#include <vehicle.h>
#include <ESP32Servo.h>
#include <ultrasonic.h>
ultrasonic myUltrasonic;
int UT_distance = 0;

vehicle myCar;
Servo myServo;

#define leftLed 2
#define rightLed 12
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
   /*
  myCar.Move(Forward,255);
  delay(2000);
  myCar.Move(Clockwise,255);
  delay(2000);
  myCar.Move(Forward,255);
  delay(2000);
  myCar.Move(Clockwise,255);
  delay(2000);
  myCar.Move(Forward,255);
  delay(2000);
  myCar.Move(Contrarotate, 255);
  delay(2000);
  myCar.Move(Forward,255);
  delay(2000);
  myCar.Move(Contrarotate, 255);
  delay(2000);
  myCar.Move(Forward,255);
  delay(2000);
  myCar.Move(Move_Right,255);
  delay(2000);
  myCar.Move(Stop,0);
  */

 // lights
  //pinMode(leftLed, OUTPUT);
  //pinMode(rightLed,OUTPUT);

  // eye sensor
  Serial.begin(115200);
  myUltrasonic.Init(13,14);
}

void loop()
{
  /*
  //flash left then right
  digitalWrite(leftLed, HIGH);
  digitalWrite(rightLed, LOW);

  delay(1000);

  digitalWrite(leftLed, LOW);
  digitalWrite(rightLed, HIGH);

  delay(1000);
  */

  //Eye sensor
  UT_distance = myUltrasonic.Ranging();
  if (UT_distance <= 25){
     myCar.Move(Contrarotate, 180);
     Serial.println("avoid");
  }else{
 myCar.Move(Forward,100);   
  }
   
  Serial.print(UT_distance);
  // The serial port shows the distance of ultrasonic detection 
  Serial.println("cm");
  delay(100);
  
}
