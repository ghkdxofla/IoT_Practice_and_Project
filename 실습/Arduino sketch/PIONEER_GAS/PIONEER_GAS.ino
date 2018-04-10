int pin_GAS = A3; // GAS pin number A3 setup

void setup() {
  // UART setup baud 115200, data bit 8, parity None, stop bit 1
  Serial.begin(115200);  // same Serial.begin(115200, SERIAL_8N1) 

  // GAS analog pin Input Setup
  pinMode(pin_GAS, INPUT);
}

void loop() {
  Serial.print("ADC Data : ");
  Serial.println(analogRead(pin_GAS));
  delay(500);
}
