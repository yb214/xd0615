int sensorValue = 0;  //����һ��int���͵ı���sensorValue 

int outputValue = 0;  //����һ��int���͵ı���outputValue 

void setup()
{
  pinMode(A0, INPUT);   // ����A0����Ϊ���� 
  pinMode(9, OUTPUT);  //������������9Ϊ��� 
  Serial.begin(9600);  //�������ڣ�ȡ������Ϊ9600 

}

void loop()
{
  sensorValue = analogRead(A0);  //��A0���Ŷ�ȡ��ֵ����ֵ������sensorValue 
  
  outputValue = map(sensorValue, 0, 1023, 0, 255); //������sensorValueֵ���ݷ�Χ�����任�󽫽���������outputValue 

  analogWrite(9, outputValue);  //��ģ����ֵoutputValueд������9����������һ���̶�Ƶ�ʵ�PWM�ź� 

  Serial.print("sensor = ");   // �Ӵ�������ַ���sensor = 
  Serial.print(sensorValue);   //�Ӵ����������sensorValue��ֵ 
  Serial.print("\t output = ");//������һ���Ʊ��λ�ã��Ӵ�������ַ��� output = 
  Serial.println(outputValue); //��ʮ������ʽ�Ӵ����������outputValue��ASCII����ֵ��ͬʱ����һ���س��ͻ��з� 

  delay(2); //��ͣ�ȴ�2ms 
}
