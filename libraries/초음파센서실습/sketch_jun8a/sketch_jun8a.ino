const int LED =2;
const int BUZZER =3;
const int TRIGGER = 7;
const int ECHO =6;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(LED,OUTPUT);
  pinMode(BUZZER,OUTPUT);
  pinMode(ECHO,INPUT);
  pinMode(TRIGGER,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  float duration, distance;
  digitalWrite(TRIGGER, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGGER, LOW);
  duration = pulseIn(ECHO,HIGH);
  distance = ((340*duration)/1000)/2;
  Serial.println("TIME :"+String(distance)+":,DISTANCE : "+String(distance));
  delay(500);
  if (distance<=50){
    digitalWrite(LED, HIGH);
    digitalWrite(BUZZER, HIGH);
    delay(500);
    digitalWrite(LED, LOW);
    digitalWrite(BUZZER, LOW);
  }
  
}
