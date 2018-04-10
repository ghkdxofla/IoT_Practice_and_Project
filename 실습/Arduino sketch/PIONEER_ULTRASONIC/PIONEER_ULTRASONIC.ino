// Triger pin number 7 setup
int pin_UL_TRIG = 7;
// Echo pin number 8 setup
int pin_UL_OUT = 8;

void setup() {
  // UART setup baud 115200, data bit 8, parity None, stop bit 1
  Serial.begin(115200);  // same Serial.begin(115200, SERIAL_8N1) 
  // Out pin Input Setup
  pinMode(pin_UL_OUT, INPUT);
  // Trig pin Output Setup
  pinMode(pin_UL_TRIG, OUTPUT);
  digitalWrite(pin_UL_TRIG, 0);
}

void loop() {
  unsigned long microseconds, distance_cm;
  // Ultrasonic wave transmission
  digitalWrite(pin_UL_TRIG, 0); // Output pin_ULTRASONIC_T to LOW
  delayMicroseconds(2);
  // pull the Trig pin to high level for more than 10us impulse 
  digitalWrite(pin_UL_TRIG, 1); // Output pin_ULTRASONIC_T to HIGH       
  delayMicroseconds(10);
  digitalWrite(pin_UL_TRIG, 0); // Output pin_ULTRASONIC_T to LOW
  
  // waits for the pin to go HIGH, and returns the length of the pulse in microseconds
  microseconds = pulseIn(pin_UL_OUT, 1, 24000);
  // time to dist
  distance_cm = microseconds * 17/1000;
  
  Serial.print("Time :");
  Serial.print(microseconds);
  Serial.print("[us], Dist :");
  Serial.print(distance_cm);
  Serial.println("[cm]");
  delay(1000);
}
