#define IN1 2
#define IN2 3
#define IN3 4
#define IN4 5

#define S1 8
#define S2 9
#define S3 10
#define S4 11

#define LT 6
#define BT 7
void setup()
{
  pinMode(LT,OUTPUT);
  pinMode(BT,OUTPUT);
  pinMode(S1,OUTPUT);
  pinMode(S2,OUTPUT);
  pinMode(S3,OUTPUT);
  pinMode(S4,OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  Serial.begin(9600);
  digitalWrite(LT,HIGH);
  digitalWrite(BT,HIGH);
  digitalWrite(S1,HIGH);
  digitalWrite(S2,HIGH);
  digitalWrite(S3,HIGH);
  digitalWrite(S4,HIGH);
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,LOW);
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,LOW);
}
byte income=0;
void loop()
{  
  if(Serial.available()>0)
  {
    digitalWrite(LT,HIGH);
    digitalWrite(BT,HIGH);
    digitalWrite(S4,LOW);
  	income=Serial.read();
    
    income=income-'0';
    digitalWrite(IN1,income&0x1);
    digitalWrite(IN2,(income>>1)&0x1);
    digitalWrite(IN3,(income>>2)&0x1);
    digitalWrite(IN4,(income>>3)&0x1);
  	delay(10);
  }
}
