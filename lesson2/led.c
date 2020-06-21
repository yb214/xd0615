int i,j;
void setup()
{
  for(i=0;i<7;i++){
  pinMode(i, OUTPUT);
  }
  for(j=0;j<7;j++){
  pinMode(j, OUTPUT);
  }
}

void loop()
{
  for(i=0;i<8;i++){
    digitalWrite(i, HIGH);
    delay(1000); // Wait for 1000 millisecond(s)
    digitalWrite(i, LOW);
    delay(500); // Wait for 1000 millisecond(s)
    for(j=0;j<8;j=i++){
        digitalWrite(j, HIGH);
        delay(1000); // Wait for 1000 millisecond(s)
        digitalWrite(j, LOW);
        delay(500); // Wait for 1000 millisecond(s)
    }
  }
}