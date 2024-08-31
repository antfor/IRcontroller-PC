#include <Servo.h>

#define SERVO_DATA_PIN 9
#define LED_PIN 12

Servo myservo; 


void setupOnButton(){

    Serial.println(F(" SERVO START "));

    myservo.attach(SERVO_DATA_PIN);
    pinMode(LED_PIN, OUTPUT);
}

void press(){ 
  unsigned long seconds = 1000L;
  unsigned long time = seconds * 10;

  myservo.write(-90); 
  delay(400);   
  myservo.write(90); 

  digitalWrite(LED_PIN, HIGH);
  delay(time); 
  digitalWrite(LED_PIN, LOW);

}
