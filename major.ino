#include <Adafruit_Sensor.h> 
// #include <Adafruit_CircuitPlayground.h>
#include<LiquidCrystal.h> 
#include <Wire.h> 

#include <Adafruit_ADXL345_U.h> 
Adafruit_ADXL345_Unified accel = Adafruit_ADXL345_Unified();

#define FL 7 
#define F2 A0 
#define F3 A1 
#define F4 A2 
#define F5 A3 

#define audio1 2 
#define audio2 3 
#define audio3 4 
#define audio4 5 
#define audio5 6 
LiquidCrystal lcd(8,9,10,11,12,13); 
void setup() { 
Serial.begin(9600); 
lcd.begin(16,2); 
if(!accel.begin()) 
{
Serial.println("No ADXL345 sensor detected."); 
while(1);
} 
lcd.setCursor(0,0); 
lcd.print("Smart Glove For"); 
lcd.setCursor(0,1); 
lcd.print("Deaf and Dump People"); 
pinMode(audio1, OUTPUT); 
pinMode(audio2, OUTPUT); 

pinMode(audio3, OUTPUT); 
pinMode(audio4, OUTPUT); 
pinMode(audio5, OUTPUT); 
digitalWrite(audio1, HIGH); 
digitalWrite(audio2, HIGH); 
digitalWrite(audio3, HIGH); 
digitalWrite(audio4, HIGH); 
digitalWrite(audio5, HIGH); 
} 
void loop() { 
digitalWrite(audio1, HIGH); 
digitalWrite(audio2, HIGH); 
digitalWrite(audio3, HIGH); 
digitalWrite(audio4, HIGH); 
digitalWrite(audio5, HIGH); 
sensors_event_t event; 
accel.getEvent(&event); 
Serial.print("X: "); 
Serial.print(event.acceleration.x); 
Serial.print(" "); 
Serial.print("Y: "); 
Serial.print(event.acceleration.y); 
Serial.print(" "); 
Serial.print("Z: "); 
Serial.print(event.acceleration.z); 
Serial.print(" "); 
Serial.println("m/s^2 "); 
// float x=0,y=0,z=0;
float x = event.acceleration.x; 
float y = event.acceleration.y; 
float z = event.acceleration.z; 
double roll = (((atan2(y,z) * 180)/3.14) + 180); 
Serial.print("Roll = "); 
Serial.println(roll); 
int v1 = analogRead(FL); 
int v2 = analogRead(F2); 
int v3 = analogRead(F3); 
int v4 = analogRead(F4); 
int v5 = analogRead(F5);
Serial.print("Valuel :"); 
Serial.println(v1); 
Serial.print("Value2 :"); 
Serial.println(v1); 
Serial.print("Value3 :"); 
Serial.println(v3); 
Serial.print("Value4 :"); 
Serial.println(v4); 
Serial.print("Value5 :"); 
Serial.println(v5); 
int sum=v1+v2+v3+v4+v5; 
Serial.print("sum :"); 
Serial.println(sum); 
if(v5>=25 && v4<=22 && x<2) 
{
Serial.println("I need water"); 
lcd.clear(); 
lcd.print("I need water"); 
digitalWrite(audio1, LOW); 
delay(4000);
}
if(v5>=29 && v4>=25 && v3<=23 && x<-3) 
{
Serial.println(" I need some help"); 
lcd.clear(); 
lcd.print(" I need some help"); 
digitalWrite(audio2, LOW); 
delay(4000); 
} 
else 
{
}
if(v2>=26&&v3>=26&&v4>=25&&v5>=28 && x>0)
{ 
Serial.println("Emergency"); 
lcd.clear(); 
lcd.print(" Emergency"); 
digitalWrite(audio3, LOW); 
delay(4000); 
} 
if(v2>=25&&v3>=25&&v4<=20&&v5<=22) 
{ 
Serial.println("Wonderful Job"); 
lcd.clear(); 
lcd.print(" Wonderful Job"); 
digitalWrite(audio4, LOW); 
delay(4000); 
}
else{
  lcd.clear(); 
lcd.print(" Wonderful Job"); 
digitalWrite(audio4, LOW); 
delay(4000); 
}
delay(2000); 
}