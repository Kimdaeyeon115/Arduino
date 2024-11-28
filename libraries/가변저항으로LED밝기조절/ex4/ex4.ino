int led =3;
int poten =A1;

void setup() {
  // put your setup code here, to run once:
  pinMode(led, OUTPUT);
  pinMode(poten, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int val = analogRead(poten);
  analogWrite(led, val/10);
  delay(100);
}
