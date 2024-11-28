#include <SPI.h>
#include <MFRC522.h>
#include <Servo.h>

Servo servo;

const int BUZZER =3;
const int RST_PIN = 9;
const int SS_A = 10;

MFRC522 mfrc(SS_A, RST_PIN);

void setup() {
  Serial.begin(9600);
  pinMode(BUZZER, OUTPUT);
  servo.attach(5);
  SPI.begin(); 
  mfrc.PCD_Init();
}
byte pw[] = {192, 24, 239, 159};
void loop() {
  
  if(!mfrc.PICC_IsNewCardPresent() || !mfrc.PICC_ReadCardSerial()) {
    delay(500);
    return;
  }
  Serial.print("ID : ");
  for(int i=0 ; i<4; i++) {
    Serial.print(mfrc.uid.uidByte[i]);
    Serial.print(" ");
    
    if (mfrc.uid.uidByte[i]==pw[i]){
      Serial.println(pw[i]+"pw값");
      int rnd = random(0,180);
      servo.write(rnd);
      Serial.println(servo.read());
      digitalWrite(BUZZER,HIGH);
      delay(100);
      digitalWrite(BUZZER,LOW);
    }
  }
  Serial.println();
  
}
