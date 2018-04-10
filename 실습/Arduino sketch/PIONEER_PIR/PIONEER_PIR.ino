int pin_PIR = 18; // Pir pin number 18 setup
char  PIR_flag = 0; 

void PIR_ISR(void)
{  
  PIR_flag=1;
}
void setup() {
  // UART setup baud 115200, data bit 8, parity None, stop bit 1
  Serial.begin(115200);  // same Serial.begin(115200, SERIAL_8N1)
  
  // PIR pin Input Setup
  pinMode(pin_PIR, INPUT);
  // External interrupt setup
  // source : pin_PIR, ISR: PIR_ISR, mode : RISING
  attachInterrupt(digitalPinToInterrupt(pin_PIR), PIR_ISR, RISING);
}

void loop() {
 if(PIR_flag==1) {
             Serial.println("Detected");
             PIR_flag = 0;
  }
 else if(PIR_flag==0)  {
      Serial.println("Not Detected");  
  }
 delay(500);
}

