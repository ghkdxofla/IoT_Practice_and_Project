int pin_VR = A7; // VR pin number A7 setup

void setup() {
  // UART setup baud 115200, data bit 8, parity None, stop bit 1
  Serial.begin(115200);  // same Serial.begin(115200, SERIAL_8N1) 

  // VR analog pin Input Setup
  pinMode(pin_VR, INPUT);
}

void loop() {
  float Volt = 0.0;
  unsigned int ADC_data = analogRead(pin_VR);

  Volt = (ADC_data *5.0) / 1023;
  Serial.print("ADC Data : ");
  Serial.print(ADC_data);
  Serial.print(", Voltage : ");
  Serial.print(Volt);
  Serial.println("[V]");
  delay(500);
}
