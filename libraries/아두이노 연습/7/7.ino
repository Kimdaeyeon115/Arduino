const int LED1=2;
const int LED2=3;
const int LED3=4;
const int CDS = A0;

void setup() {
  // put your setup code here, to run once:
  pinMode(LED1,OUTPUT);
  pinMode(LED2,OUTPUT);
  pinMode(LED3,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int val = analogRead(CDS);
  int normsl_val = map(val,0,1023,0,255);
  Serial.println(val);
  
  if(val<500){
    digitalWrite(LED3,HIGH);
    delay(100);
    digitalWrite(LED3,LOW);
    digitalWrite(LED2,HIGH);
    delay(100);
    digitalWrite(LED2,LOW);
    digitalWrite(LED1,HIGH);
    delay(100);
    digitalWrite(LED1,LOW);
  }else if(val>640){
    digitalWrite(LED2,HIGH);
    delay(100);
    digitalWrite(LED2,LOW);
  }
  delay(300);
}
