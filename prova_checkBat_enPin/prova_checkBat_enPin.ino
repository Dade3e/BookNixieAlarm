/*
  AnalogReadSerial

  Reads an analog input on pin 0, prints the result to the Serial Monitor.
  Graphical representation is available using Serial Plotter (Tools > Serial Plotter menu).
  Attach the center pin of a potentiometer to pin A0, and the outside pins to +5V and ground.

  This example code is in the public domain.

  https://www.arduino.cc/en/Tutorial/BuiltInExamples/AnalogReadSerial
*/
#define CHECKBAT A1
#define BATEN A2
#define BAT0 digitalWrite(BATEN, LOW)
#define BAT1 digitalWrite(BATEN, HIGH)
// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(115200);
  pinMode(BATEN, OUTPUT);
  pinMode(CHECKBAT, INPUT);
}

// the loop routine runs over and over again forever:
void loop() {
  // read the input on analog pin 0:
  BAT1;
  delay(10);
  int sensorValue = analogRead(CHECKBAT);
  BAT0;
  // print out the value you read:
  Serial.print(sensorValue);
  Serial.print(" ");
  Serial.println((sensorValue - 200)/3);
  delay(100);  // delay in between reads for stability
}
