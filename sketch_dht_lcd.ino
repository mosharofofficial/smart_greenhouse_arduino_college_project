#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <DHT.h>
#define DHTTYPE DHT11

DHT dht(2,DHTTYPE);

LiquidCrystal_I2C lcd(0x27,16,2);

int soil;
int moisture;

 void setup()
 {
//LCD Screen
  lcd.init();
  lcd.backlight();

  // lcd.setCursor(0,10);

  //DHT
  dht.begin();

  //serial
  // Serial.begin(9600);
 }

 void loop(){
  int hum = (int)dht.readHumidity();
  int tmp = (int)dht.readTemperature();
//DHT LCD
  lcd.setCursor(0,0);
  lcd.print("");
  lcd.setCursor(0,1);
  lcd.print("                   ");
  //after reset
  lcd.setCursor(0,0);
  lcd.print("Hu=");
  lcd.print(hum);
  lcd.print(" ");
  lcd.print("%");
  lcd.print(" ");
  lcd.print("Tmp=");
  lcd.print(tmp);
  lcd.print(" ");
  lcd.print("C");
//YL-69 LCD
  soil = analogRead(A3);
  moisture = map(soil,0,1023,100,0);
  lcd.setCursor(0,1);
  lcd.print("SoHu=");
  lcd.print(moisture);
  lcd.print("%");

//serial
// Serial.println(soil);

  delay(500);

 }
