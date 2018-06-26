#include <SoftwareSerial.h>

SoftwareSerial mySerial(2, 3);
SoftwareSerial bluetoothSerial(0, 1);

int cm5 = 0;
int cm6 = 0;
int cm7 = 0;

long readUltrasonicDistance(int outpin, int inpin)
{
  pinMode(outpin, OUTPUT);  // Clear the trigger
  digitalWrite(outpin, LOW);
  delayMicroseconds(2);
  digitalWrite(outpin, HIGH);
  delayMicroseconds(10);
  digitalWrite(outpin, LOW);
  return pulseIn(inpin, HIGH);
}

void setup()
{
  pinMode(6, OUTPUT);
  pinMode(5, INPUT);
  pinMode(10, OUTPUT);
  pinMode(11, INPUT);
  pinMode(9, OUTPUT);
  pinMode(8, INPUT);
  
  Serial.begin(9600);
  mySerial.begin(9600);
  bluetoothSerial.begin(9600);
}
 
void loop()
{
  cm5 = 0.01723 * readUltrasonicDistance(6, 5);
  if(cm5 < 10)
  {
  Serial.println("5555");
  delay(500);
  }
  cm6 = 0.01723 * readUltrasonicDistance(10, 11);
  if(cm6 < 10)
  {
  Serial.println("6666");
  delay(500);
  }
  cm7 = 0.01723 * readUltrasonicDistance(9, 8);
  if(cm7 < 10)
  {
  Serial.println("7777");
  delay(500);
  }

  mySerial.listen();
  
  while (Serial.available() > 0) {
    bluetoothSerial.listen();
    char inByte = Serial.read();
    bluetoothSerial.write(inByte);
    mySerial.listen();
  }

  mySerial.listen();
  while (mySerial.available() > 0) {
    char inByte = mySerial.read();
    Serial.write(inByte);
  }
  delay(100);
}
