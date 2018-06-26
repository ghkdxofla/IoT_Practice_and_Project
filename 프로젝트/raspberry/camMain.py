import pygame
import pygame.camera
from pygame.locals import *
import serial
from time import sleep

def bluetoothConn():
	


	bluetoothSerial = serial.Serial("/dev/rfcomm0", baudrate=9600)

	#count = None
	#while count == None:
	#	try:
	#		count = int(input("Please enter the number of times to blink the LED: "))
	#	except:
	#		pass

	#bluetoothSerial.write(bytes(count))
	while(1):
		bluetoothSerial.readline().decode("utf-8")


def camstream():
	bluetoothSerial = serial.Serial("/dev/rfcomm0", baudrate=9600)
	pygame.init()
	pygame.camera.init()

	DEVICE = pygame.camera.list_cameras()
	SIZE = (640, 480)
	FILENAME = 'capture.png'
	
	display = pygame.display.set_mode(SIZE, 0)
	camera = pygame.camera.Camera(DEVICE[0], SIZE)
	camera.start()
	screen = pygame.surface.Surface(SIZE, 0, display)
	capture = True
	while capture:
		screen = camera.get_image(screen)
		display.blit(screen, (0,0))
		pygame.display.flip()
		isStealed = bluetoothSerial.readline().decode("utf-8")
        #for event in pygame.event.get():
        #    if event.type == QUIT:
        #        capture = False
        #    elif event.type == KEYDOWN and event.key == K_s:
        #        pygame.image.save(screen, FILENAME)
		if isStealed == "1111" or "2222" or "3333" or "4444" or "5555" or "6666" or "7777":
			pygame.image.save(screen, FILENAME)
	camera.stop()
	pygame.quit()
	return

if __name__ == '__main__':
    camstream()
