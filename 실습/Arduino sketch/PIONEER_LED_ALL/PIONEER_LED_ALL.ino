// Red, Green, Blue LED
int pin_LED[3] = {11, 12, 13};

void setup() {
  // Led pin Output Setup
  char  i;
  for(i=0; i<3; i++)
  {
    pinMode(pin_LED[i], OUTPUT);
  }
}
void loop() {
 
    //R,G,B LED control
  digitalWrite(pin_LED[0],1);
  digitalWrite(pin_LED[1],1);
  digitalWrite(pin_LED[2],1);
  delay(500);
  
  digitalWrite(pin_LED[0],0);
  digitalWrite(pin_LED[1],0);
  digitalWrite(pin_LED[2],0);
  delay(500);
}
