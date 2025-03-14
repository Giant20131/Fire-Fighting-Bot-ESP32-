#include <ESP32Servo.h>
#include "BluetoothSerial.h"
#include <Arduino.h>

Servo myServo;
BluetoothSerial serialBT;

//Bluetooth signal Store in this variable
char btSignal;

//initial Speed of the Bot
int Speed = 100;

/*FOR RIGHT MOTOR*/
int RPWM = 13;

/*FOR LEFT MOTOR*/
int LPWM = 25 ;

//declare channel for pwm Output
#define R 0
#define L 1

//Define in1/in2/in3/in4 pin
int IN1 = 12;
int IN2 = 14;
int IN3 = 27;
int IN4 = 26;
int Waterpump = 15;

void setup() {
  Serial.begin(115200);
  myServo.attach(32);
  //Bluetooth Name
  serialBT.begin("Manthan's BT ROBOT ");

  //output pin declare
  pinMode(RPWM, OUTPUT);
  pinMode(LPWM, OUTPUT);

  // Setup PWM channels
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(Waterpump, OUTPUT);

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);

}
void relay_on() {
    digitalWrite(Waterpump, LOW);
  }

  void relay_off() {
    digitalWrite(Waterpump, HIGH);
  }

  void servo() {
    delay(600);
      myServo.write(0);
      delay(600);
      myServo.write(75);
      delay(600);
      myServo.write(0);
      delay(600);
      myServo.write(75);
      delay(600);
      myServo.write(0);
      delay(600);
      myServo.write(75);
      delay(600);
      myServo.write(0);
      delay(600);
      myServo.write(75);
  }

void loop() {
  
    while (serialBT.available()) {
    btSignal = serialBT.read();
    Serial.println(btSignal);

    if (btSignal == 'F') {  //forward
      digitalWrite(RPWM, HIGH);
      digitalWrite(LPWM, HIGH);
      digitalWrite(IN1, HIGH);
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, HIGH);
      digitalWrite(IN4, LOW);
    } else if (btSignal == 'B') {  //backward
      digitalWrite(RPWM, HIGH);
      digitalWrite(LPWM, HIGH);
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, HIGH);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, HIGH);
    } else if (btSignal == 'L') {  //LEFT
      digitalWrite(RPWM, HIGH);
      digitalWrite(LPWM, HIGH);
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, HIGH);
    } else if (btSignal == 'R') {  //RIGHT
      digitalWrite(RPWM, HIGH);
      digitalWrite(LPWM, HIGH);
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, HIGH);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, LOW);
    } else if (btSignal == 'S') {  //STOP
      digitalWrite(RPWM, HIGH);
      digitalWrite(LPWM, HIGH);
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, LOW);
    } else if (btSignal == 'V') {
      relay_on();
      servo();
      relay_off();
    } else {
      relay_off();
    }
  }
  
}