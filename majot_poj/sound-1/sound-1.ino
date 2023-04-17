// Pin definitions
#define an1 A0
#define an2 A1
#define M0 2
#define M1 3
#define M2 4
#define M3 5
#define M4 6
int count =1;
void setup() {
  // Set the M0 to M4 pins as outputs
  Serial.begin(115200);
  pinMode(M0, OUTPUT);
  pinMode(M1, OUTPUT);
  pinMode(M2, OUTPUT);
  pinMode(M3, OUTPUT);
  pinMode(M4, OUTPUT);

    pinMode(an1,INPUT);
  pinMode(an2, INPUT);

    digitalWrite(M0, HIGH);
  digitalWrite(M1, HIGH);
  digitalWrite(M2, HIGH);
   digitalWrite(M3, HIGH);
  digitalWrite(M4, HIGH);

}

void loop() {
  // Play sound number 1 (binary 001) on the module
  // Serial.println("begin");
int ann1 = analogRead(an1)*5/1024 ;
int ann2=analogRead(an2)*5/1024 ; 
  delay(5000);  // Wait for 5 seconds
  if(count==1){
    // Serial.println("sound1 recording...");
    digitalWrite(M1,LOW);
     delay(5000);
    digitalWrite(M1,HIGH);
    Serial.print(ann1);
    Serial.print(',');
    Serial.print(ann2);
    Serial.print(',');
    
  }
  
Serial.println();
}
