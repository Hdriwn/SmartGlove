// Pin definitions
#define an1 A0
#define an2 A1
#define M0 2
#define M1 3
#define M2 4
#define M3 5
#define M4 6

void setup() {
  // Set the M0 to M4 pins as outputs
  pinMode(M0, OUTPUT);
  pinMode(M1, OUTPUT);
  pinMode(M2, OUTPUT);
  pinMode(M3, OUTPUT);
  pinMode(M4, OUTPUT);

  digitalWrite(M0, HIGH);
  digitalWrite(M1, HIGH);
  digitalWrite(M2, HIGH);
  digitalWrite(M3, HIGH);
  digitalWrite(M4, HIGH);

  // Start serial communication
  Serial.begin(115200);

  // Wait for serial monitor to open
  while (!Serial) {
    ; // Do nothing
  }
}

void loop() {
  // Record and play sounds
  for (int i = 0; i < 5; i++) {
    Serial.print("Recording sound ");
    Serial.println(i + 1);

    // Set the corresponding M pin to LOW to start recording
    digitalWrite(i + 2, LOW);

    // Wait for 5 seconds to record
    delay(5000);

    // Set the corresponding M pin to HIGH to stop recording
    digitalWrite(i + 2, HIGH);

    // Play the recorded sound
    Serial.print("Playing sound ");
    Serial.println(i + 1);

    // Set the corresponding M pin to LOW to play the recorded sound
    digitalWrite(i + 2, LOW);

    // Wait for 5 seconds to play the sound
    delay(5000);

    // Set the corresponding M pin to HIGH to stop playing the sound
    digitalWrite(i + 2, HIGH);
  }

  // Plot analog signals on the serial plotter
  int ann1 = analogRead(an1);
  int ann2 = analogRead(an2) ;

  Serial.print(ann1);
  Serial.print(',');
  Serial.print(ann2);
  Serial.println();

  // Wait for 1 second
  delay(1000);
}
