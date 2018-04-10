int pin_FLAME_A = A2;
int pin_FLAME_D = 34;

void setup() {
  // UART setup baud 115200, data bit 8, parity None, stop bit 1
  Serial.begin(115200);  // same Serial.begin(115200, SERIAL_8N1) 
  // Flame analog pin Input Setup
  pinMode(pin_FLAME_A, INPUT);
  // Flame digital pin Input Setup
  pinMode(pin_FLAME_D, INPUT);
}

void loop() {
 
  // Flame digital pin Read
  if(digitalRead(pin_FLAME_D) == 0)
  {
    Serial.print("  Flame Detected");
    Serial.print("  ADC Data : ");
    Serial.println(analogRead(pin_FLAME_A));
  }
  else
  {
    Serial.println("  Flame not Detected");
    Serial.println(analogRead(pin_FLAME_A));
  }
  delay(500);
}
