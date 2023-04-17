#include <SoftwareSerial.h>

SoftwareSerial BTserial(0, 1); // RX | TX

void setup()
{
   Serial.begin(9600);
   BTserial.begin(38400);
   Serial.println("Bluetooth receive test.");
}

void loop()
{
  // BTserial.write('a');
  // Serial.println("a");
  delay(1000);
  BTserial.write('what');
  Serial.println("vishnu alakuntla");
  //  if (BTserial.available())
  //  {
  //     char incomingByte = BTserial.read();
  //     Serial.print("Received: ");
  //     Serial.println(incomingByte);
  //  }
  delay(1000);
}




#include <SoftwareSerial.h>

SoftwareSerial BTserial(0, 1); // RX | TX
#include <Adafruit_Sensor.h> 
// #include <Adafruit_CircuitPlayground.h>

#include <Wire.h> 
#include <Adafruit_ADXL345_U.h>

Adafruit_ADXL345_Unified accel = Adafruit_ADXL345_Unified();


#define F1 A0 
#define F2 A1 
#define F3 A2 
#define F4 A3 

void setup() { 
Serial.begin(9600); 
BTserial.begin(38400);

pinMode(F1, INPUT); 
pinMode(F2, INPUT); 
pinMode(F3, INPUT);
pinMode(F4, INPUT); 

// analogWrite(F4,LOW);
// if(!accel.begin())

//    {

//       Serial.println("No valid sensor found");

//       while(1);

// }

// Serial.print("aaa");
} 
void loop() { 
  

float v1 = analogRead(F1); 
float v2 = analogRead(F2); 
float v3 = analogRead(F3); 
float v4 = analogRead(F4); 
// float v4 = analogRead(F5);
Serial.print("Valuel :"); 
Serial.println(v1); 
Serial.print("Value2 :"); 
Serial.println(v2); 
Serial.print("Value3 :"); 
Serial.println(v3); 
Serial.print("Value4 :"); 
Serial.println(v4); 
// Serial.print("Value5 :"); 
// Serial.println(v5); 
int sum=v1+v2+v3+v4; 
Serial.print("sum :"); 
Serial.println(sum); 
// sensors_event_t event; 

//    accel.getEvent(&event);

//    Serial.print("X: "); Serial.print(event.acceleration.x); Serial.print("  ");

//    Serial.print("Y: "); Serial.print(event.acceleration.y); Serial.print("  ");

//    Serial.print("Z: "); Serial.print(event.acceleration.z); Serial.print("  ");

//    Serial.println("m/s^2 ");
//   float x = event.acceleration.x;
//   float y = event.acceleration.y;
//   float z = event.acceleration.z;

if(v1>=18 && v2<=10 && v3<=14 && v4<=14  ) 
{
Serial.println("A");  
delay(4000);
}

if(v1<=25 && v2>=20 && v3>=25 && v4>=25  ) 
{
Serial.println("B");  
delay(4000);
}

if(v1>=15 && v1<=23 && v2>=10 && v2<=15 && v3>=10 && v3<=21 &&  v4<=21  ) 
{
Serial.println("C");  
delay(4000);
}

if(v1>=15 && v1<=20 && v2>=20 && v3<=15 && v4<=15  ) 
{
Serial.println("D");  
delay(4000);
}


if(v1<=15  && v2<=10  && v3>=10 && v3<=14 && v4>=10 && v4<=12  ) 
{
Serial.println("E");  
delay(4000);
}

if(v1>=10 && v1<=20 && v2<=10  && v3>=25 && v3<=30 && v4>=25 && v4<=30  ) 
{
Serial.println("F");  
delay(4000);
}

if(v1>=20 && v1<=26 && v2>=19 && v2<=22 && v3>=10 && v3<=14 && v4>=10 && v4<=17  ) 
{
Serial.println("G");  
delay(4000);
}

if(v1>=19 && v1<=22 && v2>=19 && v2<=22 && v3>=25 && v3<=30 && v4>=15 && v4<=20  ) 
{
Serial.println("H");  
delay(4000);
}

if(v1>=10 && v1<=17  && v2<=13 && v3>=10 && v3<=14 && v4>=25 && v4<=30  ) 
{
Serial.println("I");  
delay(4000);
}

if(v1>=25 && v1<=30 && v2>=14 && v2<=17 && v3>=15 && v3<=20 && v4>=19 && v4<=25  ) 
{
Serial.println("N");  
delay(4000);
}

if(v1>=16 && v1<=23 &&  v2<=12 && v3>=10 && v3<=14 && v4>=15 && v4<=20  ) 
{
Serial.println("O");  
delay(4000);
}

if(v1>=20 && v1<=26 && v2>=19 && v2<=25 && v3>=18 && v3<=22 && v4>=14 && v4<=17  ) 
{
Serial.println("P");  
delay(4000);
}

if(v1>=25 && v1<=30 && v2>=25 && v2<=30 && v3>=27 && v3<=35 && v4>=15 && v4<=25  ) 
{
Serial.println("R");  
delay(4000);
}

if(v1>=20 && v1<=26 && v2>=10 && v2<=15 && v3>=16 && v3<=18 && v4>=18 && v4<=20  ) 
{
Serial.println("S");  
delay(4000);
}

if(v1>=30 &&  v2>=17 && v2<=20 && v3>=17 && v3<=21 && v4>=18 && v4<=23  ) 
{
Serial.println("T");  
delay(4000);
}

if(v1>=20 && v1<=26 && v2>=22 && v2<=28 && v3>=30  && v4>=20 && v4<=24  ) 
{
Serial.println("U");  
delay(4000);
}


if(v1>=17 && v1<=24 && v2>=19 && v2<=23 && v3>=25 && v3<=30 && v4>=10 && v4<=17  ) 
{
Serial.println("W");  
delay(4000);
}

if(v1>=20 && v1<=26 && v2<=12 && v3>=10 && v3<=17 && v4>=24 && v4<=30  ) 
{
Serial.println("Y");  
delay(4000);
}
delay(1000); 
}