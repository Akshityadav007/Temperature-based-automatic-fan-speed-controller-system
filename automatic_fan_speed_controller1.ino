#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

int val;
float TEMP;
int motorPin = 6;
int speed = 0;

void setup() {
  lcd.begin(16, 2);
  pinMode(motorPin,OUTPUT);
  
  analogWrite(motorPin,speed);
  lcd.clear();
  speed = 0;
  analogWrite(motorPin,speed); 
  delay(1000);
  lcd.setCursor(0,0);
  lcd.print("MICRO CONTROLLER");
  lcd.setCursor(0,1);
  lcd.print("BASED AUTOMATIC");
  delay(3000);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("FAN SPEED");
  lcd.setCursor(0,1);	
  lcd.print("CONTROLLER");
  delay(3000);
  lcd.clear();
  
}

void loop() {
  val = analogRead(0);
  float TmV = (val/1024.0)*5000;
  float TEMP = TmV/10;
  lcd.setCursor(0,0);lcd.print("Temperature:");
  lcd.setCursor(0,1);lcd.print(TEMP);
  delay(1000);
  
  if(TEMP > 20 && TEMP < 30){
    speed = 80;
    analogWrite(motorPin,speed);
    delay(1000);
  }
  
  else if(TEMP > 30 && TEMP < 40){
    speed = 100;
    analogWrite(motorPin, speed);
    delay(1000);
  }
  
  else if(TEMP > 40 && TEMP < 50){
    speed = 120;
    analogWrite(motorPin,speed);
    delay(1000);
  }
  
  else if(TEMP >50 && TEMP < 60){
    speed = 140;
    analogWrite(motorPin,speed);
    delay(1000);
  }
  
  else if(TEMP > 60 && TEMP < 80){
    speed = 160;
    analogWrite(motorPin,speed);
    delay(1000);
  }
  
  else if(TEMP > 80 && TEMP < 100){
    speed = 180;
    analogWrite(motorPin,speed);
    delay(1000);
  }
  else if(TEMP > 100 && TEMP < 120){
    speed = 200;
    analogWrite(motorPin,speed);
    delay(1000);
  }
  else{
    speed = 255;
    analogWrite(motorPin,speed);
    delay(1000);
  }
  
  
}
 