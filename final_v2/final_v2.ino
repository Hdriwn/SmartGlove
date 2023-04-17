#include <SoftwareSerial.h>

SoftwareSerial BTserial(0, 1);  // RX | TX
#include <Adafruit_Sensor.h>
// #include <Adafruit_CircuitPlayground.h>

#include <Wire.h>
#include <Adafruit_ADXL345_U.h>

Adafruit_ADXL345_Unified accel = Adafruit_ADXL345_Unified();

const float alpha = 0.65;  // Filter coefficient

float accel_filtered[3] = { 0 };  // Filtered acceleration values


#define F1 A0
#define F2 A1
#define F3 A2
#define F4 A3

const int WINDOW_SIZE = 5;  // number of samples to use for moving average
int buffer1[WINDOW_SIZE] = { 0 };
int buffer2[WINDOW_SIZE] = { 0 };
int buffer3[WINDOW_SIZE] = { 0 };
int buffer4[WINDOW_SIZE] = { 0 };
int index = 0;


void setup() {
  Serial.begin(9600);
  BTserial.begin(38400);

  pinMode(F1, INPUT);
  pinMode(F2, INPUT);
  pinMode(F3, INPUT);
  pinMode(F4, INPUT);

  // analogWrite(F4,LOW);
  if (!accel.begin())

  {

    Serial.println("No valid sensor found");

    while (1)
      ;
  }

  // Serial.print("aaa");
}
void loop() {


  float vv1 = analogRead(F1);
  float vv2 = analogRead(F2);
  float vv3 = analogRead(F3);
  float vv4 = analogRead(F4);
  buffer1[index] = vv1;
  buffer2[index] = vv2;
  buffer3[index] = vv3;
  buffer4[index] = vv4;
  index = (index + 1) % WINDOW_SIZE;
  // calculate moving average
  float v1 = 0;
  float v2 = 0;
  float v3 = 0;
  float v4 = 0;
  for (int i = 0; i < WINDOW_SIZE; i++) {
    v1 += buffer1[i];
    v2 += buffer2[i];
    v3 += buffer3[i];
    v4 += buffer4[i];
  }
  v1 /= WINDOW_SIZE;
  v2 /= WINDOW_SIZE;
  v3 /= WINDOW_SIZE;
  v4 /= WINDOW_SIZE;

  sensors_event_t event;

  accel.getEvent(&event);
  float xx = event.acceleration.x;
  float yy = event.acceleration.y;
  float zz = event.acceleration.z;

  accel_filtered[0] = alpha * accel_filtered[0] + (1 - alpha) * event.acceleration.x;
  accel_filtered[1] = alpha * accel_filtered[1] + (1 - alpha) * event.acceleration.y;
  accel_filtered[2] = alpha * accel_filtered[2] + (1 - alpha) * event.acceleration.z;

  float x = accel_filtered[0];
  float y = accel_filtered[1];
  float z = accel_filtered[2];


  if (v1 >= 16 && v2 <= 12 && v3 <= 14 && v4 <= 14 && x <= -9.00) {
    Serial.println("A");
    delay(4000);
  }

  if (v1 <= 25 && v2 >= 16 && v3 >= 20 && v4 >= 25 && x <= -9.00) {
    Serial.println("B");
    delay(4000);
  }

  if (v1 >= 15 && v1 <= 23 && v2 >= 10 && v2 <= 15 && v3 >= 10 && v3 <= 21 && v4 <= 21 && y <= -1.00 && z <= -3.5) {
    Serial.println("C");
    delay(4000);
  }

  if (v1 >= 13 && v1 <= 20 && v2 >= 18 && v3 <= 15 && v4 <= 15 && x <= -9.00) {
    Serial.println("D");
    delay(4000);
  }


  if (v1 <= 15 && v2 <= 10 && v3 >= 10 && v3 <= 14 && v4 >= 10 && v4 <= 12 && y <= -2.00) {
    Serial.println("E");
    delay(4000);
  }

  if (v1 >= 10 && v1 <= 20 && v2 <= 10 && v3 >= 24 && v3 <= 30 && v4 >= 25 && v4 <= 30) {
    Serial.println("F");
    delay(4000);
  }

  if (v1 >= 19 && v1 <= 26 && v2 >= 19 && v2 <= 22 && v3 >= 10 && v3 <= 14 && v4 >= 10 && v4 <= 17 && y <= -9.0) {
    Serial.println("G");
    delay(4000);
  }

  if (v1 >= 16 && v1 <= 22 && v2 >= 19 && v2 <= 22 && v3 >= 24 && v3 <= 30 && v4 >= 10 && v4 <= 20 && y <= -9.00) {
    Serial.println("H");
    delay(4000);
  }

  if (v1 >= 10 && v1 <= 17 && v2 <= 13 && v3 >= 10 && v3 <= 14 && v4 >= 25 && v4 <= 30 && x <= -8.5) {
    Serial.println("I");
    delay(4000);
  }


  if (v1 >= 10 && v1 <= 17 && v2 <= 13 && v3 >= 10 && v3 <= 14 && v4 >= 25 && v4 <= 30 && y <= -8.00) {
    Serial.println("J");
    delay(4000);
  }


  if (v1 >= 17 && v1 <= 24 && v2 >= 19 && v2 <= 23 && v3 >= 25 && v3 <= 30 && v4 >= 10 && v4 <= 17 && x <= -9.00) {
    Serial.println("K");
    delay(4000);
  }



  // if(v1>=13  && v2>=18 && v3<=15 && v4<=15 && x<=-9.00  && z<=-3.00   )
  // {
  // Serial.println("L");
  // delay(4000);
  // }

  // if(v1>=25 && v1<=30 && v2>=14 && v2<=17 && v3>=15 && v3<=20 && v4>=19 && v4<=25  )
  // {
  // Serial.println("N");
  // delay(4000);
  // }

  if (v1 >= 16 && v1 <= 23 && v2 <= 12 && v3 >= 10 && v3 <= 14 && v4 >= 15 && v4 <= 20) {
    Serial.println("O");
    delay(4000);
  }

  if (v1 >= 20 && v1 <= 26 && v2 >= 19 && v2 <= 25 && v3 >= 15 && v3 <= 22 && v4 >= 14 && v4 <= 17 && z >= 7.00) {
    Serial.println("P");
    delay(4000);
  }

  if (v1 >= 20 && v1 <= 26 && v2 >= 18 && v2 <= 25 && v3 >= 10 && v3 <= 15 && v4 >= 11 && v4 <= 14 && x >= 3.00) {
    Serial.println("Q");
    delay(4000);
  }


  if (v1 >= 21 && v1 <= 30 && v2 >= 21 && v2 <= 30 && v3 >= 23 && v3 <= 35 && v4 >= 15 && v4 <= 25) {
    Serial.println("R");
    delay(4000);
  }

  // if(v1>=20 && v1<=26 && v2<=10 && v2<=15 && v3<=10 && v4>=18 && v4<=15  )
  // {
  // Serial.println("S");
  // delay(4000);
  // }

  // if(v1>=30 &&  v2>=17 && v2<=20 && v3>=17 && v3<=21 && v4>=18 && v4<=23  )
  // {
  // Serial.println("T");
  // delay(4000);
  // }

  if (v1 >= 10 && v1 <= 14 && v2 >= 18 && v2 <= 25 && v3 >= 20 && v4 >= 10 && v4 <= 15) {
    Serial.println("U");
    delay(4000);
  }


  // if(v1>=17 && v1<=24 && v2>=19 && v2<=23 && v3>=25 && v3<=30 && v4>=10 && v4<=17  )
  // {
  // Serial.println("W");
  // delay(4000);
  // }

  if (v1 >= 20 && v1 <= 26 && v2 <= 12 && v3 >= 10 && v3 <= 17 && v4 >= 24 && v4 <= 30) {
    Serial.println("Y");
    delay(4000);
  }



  if (v1 <= 25 && v2 <= 15 && v3 <= 15 && v4 <= 15 && y <= -4.00 && x >= -3.00) {
    Serial.println("I need water");
    delay(4000);
  }

  if (v1 <= 25 && v2 <= 10 && v3 <= 15 && v4 <= 15 && x <= -4.00 && y <= -7.0) {
    Serial.println("I am Ready to do");
    delay(4000);
  }

  if (v1 <= 20 && v2 <= 12 && v3 >= 25 && v4 >= 25 && x <= -7.5 && y <= -2.00) {
    Serial.println("Wonderful job");
    delay(4000);
  }
  delay(1000);
}