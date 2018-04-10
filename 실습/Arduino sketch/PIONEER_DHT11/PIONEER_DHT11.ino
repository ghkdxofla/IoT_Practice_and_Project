#include <dht11.h>
dht11 DHT11; 
int pin_DHT11 = 6;

void setup()
{  
  // UART setup baud 115200, data bit 8, parity None, stop bit 1
  Serial.begin(115200);  // same Serial.begin(115200, SERIAL_8N1) 
}
void loop()
{  
  // temp & humi Read
  int chk = DHT11.read(pin_DHT11);
  switch (chk)
  {
    //normal operation
    case DHTLIB_OK: 
      Serial.print("Temperature : ");
      Serial.print(DHT11.temperature);
      Serial.print("[C] Humidity : ");
      Serial.print(DHT11.humidity);
      Serial.println("[%]");
      break;
    //error message 
    case DHTLIB_ERROR_CHECKSUM: 
      Serial.println("Checksum error"); 
      break;
    case DHTLIB_ERROR_TIMEOUT: 
      Serial.println("Time out error"); 
      break;
    default: 
      Serial.println("Unknown error"); 
      break;
  }
  delay(1000);
}
