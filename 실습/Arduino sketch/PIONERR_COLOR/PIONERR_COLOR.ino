#include <TimerOne.h>

int pin_COLOR_OUT = 3; // TCS3200 출력 
int pin_COLOR_S0 = 35;
int pin_COLOR_S1 = 36;
int pin_COLOR_S2 = 37;
int pin_COLOR_S3 = 38;
int pin_COLOR_LED = 39; // HIGH

char  color = 0; // 0 ->R , 1-> G, 2->B
unsigned int countR = 0, countG = 0, countB = 0;
unsigned int counter=0;


void Detect_Color( char c)
{
 if (c== 0 ) { // RED
      digitalWrite(pin_COLOR_S2, 0);
      digitalWrite(pin_COLOR_S3, 0); 
 }
 else if(c==1) { //GREEN
    digitalWrite(pin_COLOR_S2, 1);
    digitalWrite(pin_COLOR_S3, 1);   
 }
 else if(c==2) { //BLUE
    digitalWrite(pin_COLOR_S2, 0);
    digitalWrite(pin_COLOR_S3, 1); 
 }
  
}

void ISR_INT()
{
  counter ++ ;
}

void timerIsr()
{
if(color== 0 ) { // RED
   countR = counter ;
   color=1; // Request Green
   Detect_Color(color); // S2 = 1, S3 = 1
   }
 else if(color==1) { //Green
   countG = counter ;
   color = 2 ; // Request Blue
   Detect_Color(color); //S2 = 0, S3 = 1
  }
 else if(color==2) { //BLUE
   countB = counter ;
   color = 0; // Request Red
   Detect_Color(color); // S2=0, S3 = 0;
  }
 counter = 0;

}

void setup()
{  // UART setup baud 115200, data bit 8, parity None, stop bit 1
 Serial.begin(115200);

 pinMode(pin_COLOR_S0, OUTPUT);
 pinMode(pin_COLOR_S1, OUTPUT);
 pinMode(pin_COLOR_S2, OUTPUT);
 pinMode(pin_COLOR_S3, OUTPUT);
 pinMode(pin_COLOR_OUT, INPUT);
 pinMode(pin_COLOR_LED, OUTPUT);

 digitalWrite(pin_COLOR_LED, 1); // Enable LED
 
 // OUTPUT FREQUENCY SCALING 2%
  digitalWrite(pin_COLOR_S0, 0);
  digitalWrite(pin_COLOR_S1, 1); 
  color = 0 ;
  Detect_Color(color);
   
   attachInterrupt(digitalPinToInterrupt(pin_COLOR_OUT), ISR_INT, RISING );
   Timer1.initialize(1000000);
   Timer1.attachInterrupt( timerIsr);

}




void loop()
{
   
    Serial.print("red = ");
    Serial.print(countR);
     Serial.print(" green = ");
    Serial.print(countG);
     Serial.print(" blue = ");
    Serial.println(countB);
    
    delay(1000);
    
}






 
