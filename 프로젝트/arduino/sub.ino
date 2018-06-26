#include <SoftwareSerial.h>

SoftwareSerial mySerial(8, 9); // RX, TX

int cm1 = 0;
int cm2 = 0;
int cm3 = 0;
int cm4 = 0;

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
  pinMode(11, OUTPUT);
  pinMode(10, INPUT);
  pinMode(13, OUTPUT);
  pinMode(12, INPUT);
  pinMode(3, OUTPUT);
  pinMode(2, INPUT);
  Serial.begin(9600);
  mySerial.begin(9600);

  while(!Serial){
    }
}

void loop()
{
  cm1 = 0.01723 * readUltrasonicDistance(6, 5);
  cm2 = 0.01723 * readUltrasonicDistance(11, 10);
  cm3 = 0.01723 * readUltrasonicDistance(13, 12);
  cm4 = 0.01723 * readUltrasonicDistance(3, 2);
  
  if(cm1 < 10)
  {
  mySerial.println("1111");
  delay(500);
  }
  
  if(cm2 < 10)
  {
  mySerial.println("2222");
  delay(500);
  }

  if(cm3 < 10)
  {
  mySerial.println("3333");
  delay(500);
  }
  
  if(cm4 < 10)
  {
  mySerial.println("4444");
  delay(500);
  }

  

  
 delay(100);
   // Wait for 100 millisecond(s)
}

