#include <Servo.h>
#include <Keypad.h>

const int BUZZER = 13;
int count =0;
int pwtrue = 0;
char save[4];
char pw[4]={'a','b','f','k'};
const char keys[4][4]={
  {'a','b','c','d'},
  {'e','f','g','h'},
  {'i','j','k','l'},
  {'m','n','o','p'}
};

const byte rowPins[4] = {5,4,3,2};
const byte colPins[4] = {9,8,7,6};

Keypad keypad(makeKeymap(keys),rowPins,colPins,4,4);

Servo servo;


void setup() {
  // put your setup code here, to run once:
  servo.attach(10);
  Serial.begin(9600);
  randomSeed(analogRead(0));
  pinMode(BUZZER,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  char key = keypad.getKey();
  Serial.println(key);
  if(key){
    if(key==pw[count]){
      save[count]=key;
      count++;
      Serial.println(count);
      pwtrue++;
      Serial.println(pwtrue);
    }else{
      count++;
    }
    if(key=='p'){
      
      if(count==5){
        if(pwtrue==4){
          Serial.println("성공");
          for(int i=0; i<=180; i++){
            servo.write(i);
            delay(10);
          }
          delay(1000);
          int rnd = random(0,180);
          servo.write(rnd);
          Serial.println(servo.read());
          delay(1000);
        }else{
          Serial.println("실패");
          digitalWrite(BUZZER,HIGH);
          delay(500);
          digitalWrite(BUZZER,LOW);
        }
      }
    }
    
    if(key=='m'){
      for(int j=0;j<count;j++){
        Serial.print(save[j]);
      }
    
        
    }
    if(key=='n'){
      save[4]={};
      count=0;
      pwtrue=0;
    }
     
  }
  delay(100);
 
}
