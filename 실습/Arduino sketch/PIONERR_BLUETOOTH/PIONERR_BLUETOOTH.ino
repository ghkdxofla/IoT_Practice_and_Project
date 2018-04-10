void setup() {
  // Bluetooth(UART3) setup baud 9600, data bit 8, parity None, stop bit 1
  Serial3.begin(9600);  // same Serial3.begin(9600, SERIAL_8N1)
}

void loop() {
  // When receiving Bluetooth data
  if(Serial3.available() > 0)
  {
    // Bluetooth data receive
    char recv = Serial3.read();
    // Bluetooth data transmission
    Serial3.write(recv);
  }
}
