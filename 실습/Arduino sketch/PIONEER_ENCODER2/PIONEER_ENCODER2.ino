// DC A pin number 4
int pin_DC_A = 4;
// DC B pin number 5
int pin_DC_B = 5;
// Encoder A pin number 2
int pin_ENCA = 2;
// Encoder B pin number 3
int pin_ENCB = 3;
unsigned int Encoder_Count = 0;

char ClockWise=0;


// Encoder Count & Motor Direction
void ENCODERA_ISR(void)
{  
  char ENCA, ENCB;

  ENCA = digitalRead(pin_ENCA) ;
  if (ENCA==1 ) {
        ENCB = digitalRead(pin_ENCB);
       if(ENCB==1) ClockWise = 1;
       else        ClockWise = 0;
  }    
  Encoder_Count++;
}


void ENCODERB_ISR(void)
{  
   Encoder_Count++;
}


// DC Motor control
// Motor CW
void Motor_CW(int Speed)
{  
  digitalWrite(pin_DC_A, LOW);
  analogWrite(pin_DC_B, Speed);
}

// Motor CCW
void Motor_CCW(int Speed)
{  
  digitalWrite(pin_DC_B, LOW);
  analogWrite(pin_DC_A, Speed);
}

// Motor Stop
void Stop(void)
{  
  digitalWrite(pin_DC_A, LOW);
  digitalWrite(pin_DC_B, LOW);
}

void setup() {
  // UART setup baud 115200, data bit 8, parity None, stop bit 1
  Serial.begin(115200);  // same Serial.begin(115200, SERIAL_8N1)
  
   // DC A pin Output Setup
  pinMode(pin_DC_A, OUTPUT);

  // DC B pin Output Setup
  pinMode(pin_DC_B, OUTPUT);

   // Encoder A pin Input Setup
  pinMode(pin_ENCA, INPUT);
  // Encoder B pin Input Setup
  pinMode(pin_ENCB, INPUT);
  
  // External interrupt setup
  // source : pin_ENCA, ISR: ENCODER_ISR, mode : RISING
  attachInterrupt(digitalPinToInterrupt(pin_ENCA), ENCODERA_ISR, CHANGE);
  

  // source : pin_ENCB, ISR: ENCODER_ISR, mode : RISING
  attachInterrupt(digitalPinToInterrupt(pin_ENCB), ENCODERB_ISR, CHANGE);

  // Motor CW, CCW
   //Motor_CW(200); // CW 방향 모터 구동
   
   Motor_CCW(200); // CCW 방향 모터 구동
  delay(1000);
}

void loop() {
  Serial.print("Encoder Count : ");
  Serial.println(Encoder_Count);
  Encoder_Count = 0;
   delay(1000);
  if(ClockWise==1) Serial.println("CW");
  else             Serial.println("CCW");
}

