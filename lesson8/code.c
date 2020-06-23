int sensorValue = 0;  //定义一个int类型的变量sensorValue 

int outputValue = 0;  //定义一个int类型的变量outputValue 

void setup()
{
  pinMode(A0, INPUT);   // 设置A0引脚为输入 
  pinMode(9, OUTPUT);  //设置数字引脚9为输出 
  Serial.begin(9600);  //开启串口，取波特率为9600 

}

void loop()
{
  sensorValue = analogRead(A0);  //从A0引脚读取数值并赋值给变量sensorValue 
  
  outputValue = map(sensorValue, 0, 1023, 0, 255); //将变量sensorValue值根据范围比例变换后将结果存入变量outputValue 

  analogWrite(9, outputValue);  //将模拟数值outputValue写进引脚9，给该引脚一个固定频率的PWM信号 

  Serial.print("sensor = ");   // 从串口输出字符串sensor = 
  Serial.print(sensorValue);   //从串口输出变量sensorValue的值 
  Serial.print("\t output = ");//跳到下一个制表符位置，从串口输出字符串 output = 
  Serial.println(outputValue); //以十进制形式从串口输出变量outputValue的ASCII编码值并同时跟随一个回车和换行符 

  delay(2); //暂停等待2ms 
}
