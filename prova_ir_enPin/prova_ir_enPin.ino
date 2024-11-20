/*
  AnalogReadSerial

  Reads an analog input on pin 0, prints the result to the Serial Monitor.
  Graphical representation is available using Serial Plotter (Tools > Serial Plotter menu).
  Attach the center pin of a potentiometer to pin A0, and the outside pins to +5V and ground.

  This example code is in the public domain.

  https://www.arduino.cc/en/Tutorial/BuiltInExamples/AnalogReadSerial
*/
#define IR 11
#define ENIR 12
#define IR0 digitalWrite(ENIR, LOW)
#define IR1 digitalWrite(ENIR, HIGH)
// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(115200);
  pinMode(ENIR, OUTPUT);
  pinMode(IR, INPUT);
}

// the loop routine runs over and over again forever:
void loop() {
  // read the input on analog pin 0:
  IR1;
  delay(1);
  int sensorValue = digitalRead(IR);
  IR0;
  // print out the value you read:
  Serial.println(sensorValue);
  delay(100);  // delay in between reads for stability
}
