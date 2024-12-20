/*
  AnalogReadSerial

  Reads an analog input on pin 0, prints the result to the Serial Monitor.
  Graphical representation is available using Serial Plotter (Tools > Serial Plotter menu).
  Attach the center pin of a potentiometer to pin A0, and the outside pins to +5V and ground.

  This example code is in the public domain.

  https://www.arduino.cc/en/Tutorial/BuiltInExamples/AnalogReadSerial
*/
#define POT A0
#define ENPOT 10
#define POT0 digitalWrite(ENPOT, LOW)
#define POT1 digitalWrite(ENPOT, HIGH)
// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(115200);
  pinMode(ENPOT, OUTPUT);
  pinMode(POT, INPUT);
}

// the loop routine runs over and over again forever:
void loop() {
  // read the input on analog pin 0:
  POT1;
  delay(1);
  int sensorValue = analogRead(POT);
  POT0;
  // print out the value you read:
  Serial.println(sensorValue);
  delay(100);  // delay in between reads for stability
}
