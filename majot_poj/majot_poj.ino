// #include <Adafruit_Sensor.h> 
// #include <Adafruit_CircuitPlayground.h>

#include <Wire.h> 

#define F1 A0 
#define F2 A1 
#define F3 A2 
#define F4 A3 
#define F5 A4 

float alpha = 0.1; // smoothing factor between 0 and 1
float v1_smooth = 0;
float v2_smooth = 0;
float v3_smooth = 0;
float v4_smooth = 0;
float v5_smooth = 0;



void setup() { 
Serial.begin(9600); 


pinMode(F1, INPUT); 
pinMode(F2, INPUT); 
pinMode(F3, INPUT); 
pinMode(F4, INPUT); 
pinMode(F5, INPUT); 


} 


void loop() { 

float v1 = analogRead(F1); 
float v2 = analogRead(F2); 
float v3 = analogRead(F3); 
float v4 = analogRead(F4); 
float v5 = analogRead(F5);
v1_smooth = alpha * v1 + (1 - alpha) * v1_smooth;
v2_smooth = alpha * v2 + (1 - alpha) * v2_smooth;
v3_smooth = alpha * v3 + (1 - alpha) * v3_smooth;
v4_smooth = alpha * v4 + (1 - alpha) * v4_smooth;
v5_smooth = alpha * v5 + (1 - alpha) * v5_smooth;
Serial.println(v1); 
Serial.print(','); 
Serial.println(v1_smooth); 
Serial.print(','); 

Serial.println(v2); 
Serial.print(','); 
Serial.println(v2_smooth); 
Serial.print(','); 

Serial.println(v3); 
Serial.print(','); 
Serial.println(v3_smooth); 
Serial.print(','); 

Serial.println(v4); 
Serial.print(','); 
Serial.println(v4_smooth); 
Serial.print(','); 

Serial.println(v5); 
Serial.print(','); 
Serial.println(v5_smooth); 
Serial.print(','); 

// Serial.println(v1_smooth); 
// Serial.print("Value3 :"); 
// Serial.println(v3); 
// Serial.print("Value4 :"); 
// Serial.println(v4); 
// Serial.print("Value5 :"); 
// Serial.println(v5); 
// int sum=v1+v2+v3+v4+v5; 
// Serial.print("sum :"); 
// Serial.println(sum); 
Serial.println();

delay(500); 
}