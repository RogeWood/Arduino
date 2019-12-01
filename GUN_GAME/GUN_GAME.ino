#include <Servo.h>

Servo myservo; // 建立Servo物件，控制伺服馬達

int grade = 0,dir = 0;
long Time = 0; //時間控制
bool GameStart = false;

void setup() {
  pinMode(A0,INPUT);//感光器
  pinMode(2,OUTPUT);//紅燈
  pinMode(3,OUTPUT);//黃燈
  pinMode(4,OUTPUT);//綠燈
  myservo.attach(9);
  Serial.begin(9600);
  myservo.write(0);
  delay(500);
}

void loop() {
  if(GameStart == true)//遊戲中
  {
    Time = Time+1;
    if(Time >= 30000)//遊戲結束
    {
      digitalWrite(4,HIGH);
      digitalWrite(2,HIGH);
      digitalWrite(3,HIGH);
      Serial.println("Time STOP!!!!!");
      Serial.print("Your grade:");
      Serial.println(grade);
      delay(5000);
      digitalWrite(4,LOW);
      digitalWrite(3,LOW);
      digitalWrite(2,LOW);
      GameStart = false;
    }
    // put your main code here, to run repeatedly:
    //Serial.println(analogRead(A0));
    
    if(analogRead(A0) < 40)
    {
      digitalWrite(4,LOW);
      digitalWrite(2,HIGH);
      digitalWrite(3,LOW);
      grade = grade + 10;
      Serial.println("Brove!!!+10");
      myservo.write(random(0,180));
      delay(500);
      Time += 500;
    }
    else if(analogRead(A0) < 90)
    {
      digitalWrite(4,LOW);
      digitalWrite(2,LOW);
      digitalWrite(3,HIGH);
      grade+= 1;
      Serial.println("Close!!+1");
      myservo.write(random(0,180));
      delay(500);
      Time += 500;
    }
    else if(analogRead(A0) < 110)
    {
      digitalWrite(2,LOW);
      digitalWrite(3,LOW);
      digitalWrite(4,HIGH);
      Serial.println("Too far!");
      delay(500);
      Time += 500;
    }
    else
    {
      digitalWrite(4,LOW);
      digitalWrite(3,LOW);
      digitalWrite(2,LOW);
    }
  }
  else//遊戲未開始
  {
    if(analogRead(A0) < 100)//擊中一次使遊戲開始
    {
      Time = 0;
      grade = 0;
       Serial.println("Start!!!!");
       Serial.println("3");
       digitalWrite(2,HIGH);
       delay(1000);
       Serial.println("2");
       digitalWrite(3,HIGH);
       digitalWrite(2,LOW);
       delay(1000);
       Serial.println("1");
       digitalWrite(4,HIGH);
       digitalWrite(3,LOW);
       delay(1000);
       Serial.println("GO!!");
       digitalWrite(4,HIGH);
       digitalWrite(2,HIGH);
       digitalWrite(3,HIGH);
       delay(500);
       digitalWrite(4,LOW);
       digitalWrite(2,LOW);
       digitalWrite(3,LOW);
       GameStart = true;
    }
  }
}
