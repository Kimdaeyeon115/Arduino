#include <Stepper.h>

Stepper stepper(2048,9,11,8,10);

const int TRIGGER = 7;
const int ECHO = 6;
const int BUZZER = 3;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(ECHO,INPUT);
  pinMode(TRIGGER,OUTPUT);
  pinMode(BUZZER,OUTPUT);
  stepper.setSpeed(3);
}

void loop() {
  // put your main code here, to run repeatedly:
  float duration, distance;
  
  digitalWrite(TRIGGER,HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGGER,LOW);
  duration = pulseIn(ECHO,HIGH);
  distance = ((340*duration)/1000)/2;
  Serial.println("TIME : "+String(duration)+", DISTANCE : "+String(distance));
  
  
  
  if(distance<100){
    digitalWrite(BUZZER,HIGH);
    delay(50);
    digitalWrite(BUZZER,LOW);
    stepper.step(0);
    
  }else if(distance<150){
    digitalWrite(BUZZER,HIGH);
    delay(100);
    digitalWrite(BUZZER,LOW);
   
    stepper.step(50);
  }else{
    digitalWrite(BUZZER,HIGH);
    delay(150);
    digitalWrite(BUZZER,LOW);
    
    stepper.step(50);
  }
  delay(100);
}
