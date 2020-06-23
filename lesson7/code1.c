#include <MsTimer2.h>     //定时器库的头文件

#define IN1 2
#define IN2 3
#define IN3 4
#define IN4 5
#define S 11

int tick = 0; //计数值
byte income=0;
 
//中断服务程序
void onTimer()
{
  Serial.print("timer ");
  Serial.println(tick%10);
  income = (byte)(tick%10);
  tick+=1;
  income=income-'0';
  digitalWrite(IN1,income&0x1);
  digitalWrite(IN2,(income>>1)&0x1);
  digitalWrite(IN3,(income>>2)&0x1);
  digitalWrite(IN4,(income>>3)&0x1);
}
 
void setup()
{
  pinMode(IN1,OUTPUT);
  pinMode(IN2,OUTPUT);
  pinMode(IN3,OUTPUT);
  pinMode(IN4,OUTPUT);
  digitalWrite(S,LOW);
  Serial.begin(9600); //初始化串口
  
  MsTimer2::set(1000, onTimer); //设置中断，每1000ms进入一次中断服务程序 onTimer()
  MsTimer2::start(); //开始计时
}
 
void loop()
{
  
}
