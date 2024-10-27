project = paint-arduino.ino

all:
	arduino-cli compile --fqbn arduino:avr:uno ${project}
	arduino-cli upload -p /dev/ttyACM0 --fqbn arduino:avr:uno ${project}
