
import serial
from time import sleep

bluetoothSerial = serial.Serial("/dev/rfcomm0", baudrate=9600)

count = None
while count == None:
    try:
        count = int(input("Please enter the number of times to blink the LED: "))
    except:
        pass

bluetoothSerial.write(bytes(count))
while(1):
    print(bluetoothSerial.readline().decode("utf-8"))
