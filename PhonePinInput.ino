/*
  Analog input, analog output, serial output

 Reads an analog input pin, maps the result to a range from 0 to 255
 and uses the result to set the pulsewidth modulation (PWM) of an output pin.
 Also prints the results to the serial monitor.

 The circuit:
 * potentiometer connected to analog pin 0.
   Center pin of the potentiometer goes to the analog pin.
   side pins of the potentiometer go to +5V and ground
 * LED connected from digital pin 9 to ground

 created 25 Feb 2016
 modified 25 Feb 2016
 by Corey Wood

 */

// These constants won't change.  They're used to give names
// to the pins used:
const int analogInOZ = A0;  // Analog input pin OZ
const int analogInOT = A1;  // Analog input pin OT
const int RED = 3;
const int GREEN = 5;
const int BLUE = 6;

int sensorValueOZ = 0;        // value read from the pot
int sensorValueOT = 0;
int outputValueOZ = LOW;        // value output to the PWM (analog out)
int outputValueOT = LOW;

void setup() {
  // initialize serial communications at 9600 bps:
  Serial.begin(9600);
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
}

void loop() {
  // read the analog in value:
  sensorValueOZ = analogRead(analogInOZ);
  // map it to the range of the analog out:
  if (sensorValueOZ >= 300) {
    outputValueOZ = HIGH;
  }
  else {
    outputValueOZ = LOW;
  }
  digitalWrite(RED, outputValueOZ);

  sensorValueOT = analogRead(analogInOT);
  if (sensorValueOT <= 300) {
    outputValueOT = HIGH;
  }
  else {
    outputValueOT = LOW;
  }
  digitalWrite(GREEN, outputValueOT);

  // print the results to the serial monitor:
  Serial.print("sensor OZ = ");
  Serial.print(sensorValueOZ);
  Serial.print("\t output OZ = ");
  Serial.println(outputValueOZ);
  Serial.print("sensor OT= ");
  Serial.print(sensorValueOT);
  Serial.print("\t output OT= ");
  Serial.println(outputValueOT);

  // wait 10 milliseconds before the next loop
  // for the analog-to-digital converter to settle
  // after the last reading:
  delay(100);
}
