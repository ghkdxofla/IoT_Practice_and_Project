#define NOTE_C4 33
#define NOTE_D4 75
#define NOTE_E4 165
#define NOTE_F4 349
#define NOTE_G4 784
#define NOTE_A5 1760
#define NOTE_B5 3951
#define NOTE_C5 8372

// BUZZER pin number 35
int pin_BUZZER = 35;
int noteDuration = 250;

int notes[8] = {
  NOTE_C4, NOTE_D4, NOTE_E4, NOTE_F4, 
  NOTE_G4, NOTE_A5, NOTE_B5, NOTE_C5 
};

void setup() {
  // buzzer pin Output Setup
  pinMode(pin_BUZZER, OUTPUT);
  Serial.begin(9600);
}

void loop() {

  if (Serial.available()){
    byte data = Serial.read();
    if (data >= '1' && data <= '8') {
      tone(pin_BUZZER, notes[data - '1'],noteDuration);
      Serial.println(data);
    }
  }
}
