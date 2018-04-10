int pin_SOUND = A6;

void setup() {
  // UART setup baud 115200, data bit 8, parity None, stop bit 1
  Serial.begin(115200);  // same Serial.begin(115200, SERIAL_8N1)
  
  // Sound pin Input Setup
  pinMode(pin_SOUND, INPUT);
}

void loop() {
  int ADC_data = analogRead(pin_SOUND);
  // 0~1023
  
  Serial.print("ADC Data : ");
  Serial.print(ADC_data);
  if(ADC_data > 511)
  {
    Serial.println("  Noise");
  }
  else
  {
    Serial.println("  Quiet");
  }
  delay(500);
}
