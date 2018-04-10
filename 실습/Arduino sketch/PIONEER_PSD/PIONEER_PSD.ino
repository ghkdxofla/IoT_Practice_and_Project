
int pin_PSD = A5; // Psd pin number A5 setup

void setup() {
  // UART setup baud 115200, data bit 8, parity None, stop bit 1
  Serial.begin(115200);  // same Serial.begin(115200, SERIAL_8N1)
  
  // PSD pin Input Setup
  pinMode(pin_PSD, INPUT);
}

void loop() {
  long int Dist = 0, ADC_data = 0;
  // PSD pin ADC Read
  ADC_data = analogRead(pin_PSD);
  // Dist =  10000 / ( V * 434 - 46)
  // V = ADC_data * 5 / 1023
  Dist = 10000 / (ADC_data * 434 * 5 / 1023 - 46);

  if(Dist > 80)
  {
    Dist = 80;
  }
  else if(Dist < 10)
  {
    Dist = 10;
  }
  
  Serial.print("ADC Data :");
  Serial.print(ADC_data);
  Serial.print(", Dist :");
  Serial.print(Dist);
  Serial.println("[cm]");
  delay(500);
}

