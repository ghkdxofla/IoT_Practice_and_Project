// 1 or 2상  스텝각 11.25도 (1 바퀴당 32 스텝)
// 기어비 1:64

// 1 or 2상 제어는 32 x 64 = 2048


// /B, /A, B, A
int pin_STEP[4] = {40, 41, 42, 43};

void setup()
{  // STEP pin OUTPUT setup
  for(int i=0; i<4; i++) 
       pinMode(pin_STEP[i], OUTPUT);
}

void loop()
{
  // 2상 제어 시계방향 회전 
  for(int i=0; i<512; i++)
  {
    digitalWrite(pin_STEP[3], 1);
    digitalWrite(pin_STEP[2], 1);
    digitalWrite(pin_STEP[1], 0);
    digitalWrite(pin_STEP[0], 0);
    delay(3);

    digitalWrite(pin_STEP[3], 0);
    digitalWrite(pin_STEP[2], 1);
    digitalWrite(pin_STEP[1], 1);
    digitalWrite(pin_STEP[0], 0);
    delay(3);

    digitalWrite(pin_STEP[3], 0);
    digitalWrite(pin_STEP[2], 0);
    digitalWrite(pin_STEP[1], 1);
    digitalWrite(pin_STEP[0], 1);
    delay(3);

    digitalWrite(pin_STEP[3], 1);
    digitalWrite(pin_STEP[2], 0);
    digitalWrite(pin_STEP[1], 0);
    digitalWrite(pin_STEP[0], 1);
    delay(3);
  }
  digitalWrite(pin_STEP[3], 0);
  digitalWrite(pin_STEP[2], 0);
  digitalWrite(pin_STEP[1], 0);
  digitalWrite(pin_STEP[0], 0);
  delay(2000);

  // 2상 제어 반시계방향 회전 
  for(int i=0; i<512; i++)
  {
     digitalWrite(pin_STEP[3], 1);
    digitalWrite(pin_STEP[2], 0);
    digitalWrite(pin_STEP[1], 0);
    digitalWrite(pin_STEP[0], 1);
    delay(3);

    digitalWrite(pin_STEP[3], 0);
    digitalWrite(pin_STEP[2], 0);
    digitalWrite(pin_STEP[1], 1);
    digitalWrite(pin_STEP[0], 1);
    delay(3);

     digitalWrite(pin_STEP[3], 0);
    digitalWrite(pin_STEP[2], 1);
    digitalWrite(pin_STEP[1], 1);
    digitalWrite(pin_STEP[0], 0);
    delay(3);

    digitalWrite(pin_STEP[3], 1);
    digitalWrite(pin_STEP[2], 1);
    digitalWrite(pin_STEP[1], 0);
    digitalWrite(pin_STEP[0], 0);
    delay(3);
  }
  digitalWrite(pin_STEP[0], 0);
  digitalWrite(pin_STEP[1], 0);
  digitalWrite(pin_STEP[2], 0);
  digitalWrite(pin_STEP[3], 0);
  delay(2000);
}

