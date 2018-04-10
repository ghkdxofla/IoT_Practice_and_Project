#define NOTE_C4 262
#define NOTE_D4 294
#define NOTE_E4 330
#define NOTE_F4 349
#define NOTE_G4 392
#define NOTE_A5 440
#define NOTE_B5 494
#define NOTE_C5 523

// BUZZER pin number 35
int pin_BUZZER = 35;
int noteDuration = 250;
int pin_JOY_V = A1;

int notes[8] = {
  NOTE_C4, NOTE_D4, NOTE_E4, NOTE_F4, 
  NOTE_G4, NOTE_A5, NOTE_B5, NOTE_C5 
};

void setup() {
  // buzzer pin Output Setup
  pinMode(pin_BUZZER, OUTPUT);
  Serial.begin(115200);  // same Serial.begin(115200, SERIAL_8N1) 
  pinMode(pin_JOY_V, INPUT);
}

void loop() {

  int JOY_V = analogRead(pin_JOY_V);

  Serial.print(", JOY V :");
  Serial.print(JOY_V);
 
  tone(pin_BUZZER, (JOY_V + 1023) / 3,noteDuration);
      
}
