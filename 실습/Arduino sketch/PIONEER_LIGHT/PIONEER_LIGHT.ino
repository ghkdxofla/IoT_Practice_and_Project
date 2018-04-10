int pin_CDS = A4; // CDS pin number A4 setup

void setup() {
  // UART setup baud 115200, data bit 8, parity None, stop bit 1
  Serial.begin(115200);  // same Serial.begin(115200, SERIAL_8N1) 
  // CDS analog pin Input Setup
  pinMode(pin_CDS, INPUT);
}

void loop() {
  Serial.print("ADC Data :");
  Serial.println(analogRead(pin_CDS));
  delay(500);
}
