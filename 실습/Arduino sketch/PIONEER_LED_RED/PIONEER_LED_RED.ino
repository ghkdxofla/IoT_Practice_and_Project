// Red Led pin number 11
int pin_LED_R = 11;
// Green Led pin number 12
int pin_LED_G = 12;
// Blue Led pin number 13
int pin_LED_B = 13;

void setup() {
  // Red Led pin Output Setup
  pinMode(pin_LED_R, OUTPUT);
}

void loop() {
  // Red Led ON
  digitalWrite(pin_LED_R, HIGH);
  // wait 1 second
  delay(1000);
  // Red Led OFF
  digitalWrite(pin_LED_R, LOW);
  // wait 1 second
  delay(1000);
}
