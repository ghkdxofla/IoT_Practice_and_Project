// DC A pin number 4
int pin_DC_A = 4;
// DC B pin number 5
int pin_DC_B = 5;


void setup() {
  
  // DC A pin Output Setup
  pinMode(pin_DC_A, OUTPUT);
  // DC B pin Output Setup
  pinMode(pin_DC_B, OUTPUT);
 }


// DC Motor control
// Motor CW
void Motor_CW(unsigned char Speed)
{  
  digitalWrite(pin_DC_A, LOW);
  analogWrite(pin_DC_B, Speed);
}

// Motor CCW
void Motor_CCW(unsigned char Speed)
{  
  digitalWrite(pin_DC_B, LOW);
  analogWrite(pin_DC_A, Speed);
}

// Stop
void Stop(void)
{  
  digitalWrite(pin_DC_A, LOW);
  digitalWrite(pin_DC_B, LOW);
}

void loop() {
 int Speed;

 for(Speed=0; Speed <512; Speed++)
 {
   Motor_CW(Speed);
   delay(20);
 }

  delay(1000);
  Stop();
  delay(200);

 for(Speed=0; Speed <512; Speed++)
 {
   Motor_CCW(Speed);
   delay(20);
  }

  delay(1000);
  Stop();
  delay(200);
}

