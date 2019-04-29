/*
  AnalogReadSerial

  Reads an analog input on pin 0, prints the result to the Serial Monitor.
  Graphical representation is available using Serial Plotter (Tools > Serial Plotter menu).
  Attach the center pin of a potentiometer to pin A0, and the outside pins to +5V and ground.

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/AnalogReadSerial
*/

// the setup routine runs once when you press reset:

void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
}

// the loop routine runs over and over again forever:
void loop() {
  // read the input on analog pin 0:
  int sensorValue1 = analogRead(A1);
  int sensorValue2 = analogRead(A2);
  int sensorValue3 = analogRead(A3);
  int sensorValue4 = analogRead(A4);
  int sensorValue5 = analogRead(A5);

  int averageVal = (sensorValue1 + sensorValue2 + sensorValue3 + sensorValue4 + sensorValue5)/5;
  // print out the value you read:
  Serial.print(sensorValue1);  Serial.print(";");  Serial.print(sensorValue2); Serial.print(";");Serial.print(sensorValue3); Serial.print(";");Serial.print(sensorValue4); Serial.print(";");Serial.println(sensorValue5);
  
  Serial.println(averageVal);

  if (averageVal>200){
    digitalWrite(9, HIGH);
    digitalWrite(10, LOW);
    digitalWrite(11, LOW);
    }
    else if (averageVal>150 && averageVal <200){
    digitalWrite(9, LOW);
    digitalWrite(10, HIGH);
    digitalWrite(11, LOW);
      }
    else {
    digitalWrite(9, LOW);
    digitalWrite(10, LOW);
    digitalWrite(11, HIGH);
    }
  
  delay(10);        // delay in between reads for stability
}
