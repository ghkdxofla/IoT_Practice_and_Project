#include <RFduinoBLE.h>

#define Group_ID 10

int pin_TEMP = 2;

// BLE Device Name
char Device_Name[] = "TEMP--";
// Sensor Data -> TTT: Temp_data
char Sensor_data[] = "TTT";


void setup() {
  pinMode(pin_TEMP, INPUT);

  // Group ID Setting
  Device_Name[4] = Group_ID/10 + 0x30; // '1'
  Device_Name[5] = Group_ID%10 + 0x30; // '0'

  // BLE Device Name Setting
  RFduinoBLE.deviceName = Device_Name;
  // BLE advertisement Data Setting
  RFduinoBLE.advertisementData = Sensor_data;
  // BLE Start
  RFduinoBLE.begin();
}

void loop() {
  unsigned long Temp_data = 0;
  char buff = 0;
  
    Temp_data = analogRead(pin_TEMP);
    Temp_data = Temp_data * 1000 / 2047;
  
      
      Sensor_data[0] =  Temp_data/100 + 0x30;
      buff = Temp_data%100 ;
      
      Sensor_data[1] =   buff/10 + 0x30;
      Sensor_data[2] =   buff%10 + 0x30;

      delay(1000);
      // BLE Stop
      RFduinoBLE.end();
      // BLE advertisement Data Setting
      RFduinoBLE.advertisementData = Sensor_data;
      // BLE restart
      RFduinoBLE.begin();
   
  
}
