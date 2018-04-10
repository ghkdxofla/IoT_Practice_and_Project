int pin_JOY_H = A0; // Joy_H pin number A0 setup
int pin_JOY_V = A1; // Joy_V pin number A1 setup
int pin_UP = 45;    // Up pin number 45 setup
int pin_DOWN = 46;  // Down pin number 46 setup
int pin_LEFT = 47;  // Left pin number 47 setup
int pin_RIGHT = 48; // Right pin number 48 setup
int pin_SEL = 49;   // SEL pin number 49 setup

void setup() {
  // UART setup baud 115200, data bit 8, parity None, stop bit 1
  Serial.begin(115200);  // same Serial.begin(115200, SERIAL_8N1) 
  
  // Joy_H analog pin Input Setup
  pinMode(pin_JOY_H, INPUT);
  // Joy_V analog pin Input Setup
  pinMode(pin_JOY_V, INPUT);
  
  // Up pin Input Setup
  pinMode(pin_UP, INPUT);
  // Down pin Input Setup
  pinMode(pin_DOWN, INPUT);
  // Left pin Input Setup
  pinMode(pin_LEFT, INPUT);
  // Right pin Input Setup
  pinMode(pin_RIGHT, INPUT);
  
  // Sel pin Input Setup
  pinMode(pin_SEL, INPUT);
}

void loop() {
  Serial.print("JOY H :");
  Serial.print(analogRead(pin_JOY_H));
  Serial.print(", JOY V :");
  Serial.print(analogRead(pin_JOY_V));
  Serial.print(", UP :");
  Serial.print(digitalRead(pin_UP));
  Serial.print(", DOWN :");
  Serial.print(digitalRead(pin_DOWN));
  Serial.print(", LEFT :");
  Serial.print(digitalRead(pin_LEFT));
  Serial.print(", RIGHT :");
  Serial.print(digitalRead(pin_RIGHT));
  Serial.print(", SEL :");
  Serial.println(digitalRead(pin_SEL));
  delay(500);
}
