// BUZZER pin number 35
int pin_BUZZER = 35; 
void setup() {
  // buzzer pin Output Setup
  pinMode(pin_BUZZER, OUTPUT);
}

void loop() {
  // Buzzer ON
  digitalWrite(pin_BUZZER, HIGH);
  // wait 1 second
  delay(1000);
  // Buzzer OFF
  digitalWrite(pin_BUZZER, LOW);
  // wait 1 second
  delay(1000);
}
