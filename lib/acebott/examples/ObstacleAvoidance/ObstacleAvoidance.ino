#include <Motor.h>
#include <SR04.h>
#include <ESP32_Servo.h>                                      

motor Motor;
sr04 SR04;
Servo MYservo;

int MYservo_PIN = 25;
int leftDistance = 0;
int middleDistance = 0;
int rightDistance = 0;
uint16_t angle = 90;
int UT_distance = 0;

void setup()
{
    Serial.begin(115200);
    SR04.SR04_int();
    Motor._74HC595D();
    MYservo.attach(MYservo_PIN);
    MYservo.write(angle);
    Motor.Motor(Stop, 0);
}

void loop()
{
    UT_distance = SR04.SR04(Trig_PIN, Echo_PIN);
    //Serial.print("UT_distance:  ");
    //Serial.println(UT_distance);delay(1000);
    middleDistance = UT_distance;

    if (middleDistance <= 25) 
    {
        Motor.Motor(Stop, 0);
        MYservo.write(10); 
        delay(100);
        rightDistance = SR04.SR04(Trig_PIN, Echo_PIN);
        //Serial.print("rightDistance:  ");
        //Serial.println(rightDistance);
        delay(1000);
        MYservo.write(170);
        delay(100);
        leftDistance = SR04.SR04(Trig_PIN, Echo_PIN);
        //Serial.print("leftDistance:  ");
        //Serial.println(leftDistance);
        delay(1000);
        MYservo.write(90);
        if((rightDistance < 10) && (leftDistance < 10))
        {
            Motor.Motor(Backward, 180);
            delay(500);
            Motor.Motor(Contrarotate, 180);
            delay(500); 
        }
        else if(rightDistance < leftDistance) 
        {
            Motor.Motor(Backward, 180);
            delay(500);
            Motor.Motor(Contrarotate, 180);
            delay(500);
        }
        else if(rightDistance > leftDistance)
        {
            Motor.Motor(Backward, 180);
            delay(500);
            Motor.Motor(Clockwise, 180); 
            delay(500);
        }
        else
        {
            Motor.Motor(Backward, 180);
            delay(500);
            Motor.Motor(Clockwise, 180); 
            delay(500);
        }
    }
    else 
    {
        Motor.Motor(Forward, 150);
    }
}
