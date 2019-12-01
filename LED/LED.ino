void setup()
{
  // put your setup code here, to run once:
  pinMode(2,OUTPUT);//greenLED @ D2
  pinMode(3,OUTPUT);//redLED @ D3
  pinMode(4,OUTPUT);//yellowLED @ D4
  
}

void loop()
{
  // put your main code here, to run repeatedly:
  digitalWrite(2,HIGH);
  digitalWrite(4,LOW);
  delay(500);// break 1000ms = 1s
  digitalWrite(2,LOW);
  digitalWrite(3,HIGH);
  delay(500);// break 1000ms = 1s
  digitalWrite(3,LOW);
  digitalWrite(4,HIGH);
  delay(500);// break 1000ms = 1s
}
