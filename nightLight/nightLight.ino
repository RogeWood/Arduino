void setup() {
  // put your setup code here, to run once:
  pinMode(A0,INPUT);
  pinMode(2,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(analogRead(A0));
  delay(100);
  if(analogRead(A0) > 400)
  {
    digitalWrite(2,HIGH);
  }
  else
  {
    digitalWrite(2,LOW);
  }
}
