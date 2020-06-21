String data = "";
#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  lcd.begin(16, 2);
  lcd.setCursor(0,0);
  lcd.print("hello, world!");
  Serial.begin(9600);
}

void loop() {
  if(Serial.available()>0){
    delay(100);
    data = Serial.readString();
    lcd.setCursor(0,1);
    lcd.print(data);
  }
}