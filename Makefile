project = paint-arduino.ino

port = ${shell find /dev/ttyACM*}

all: kill compile upload monitor


compile: 
	arduino-cli compile --fqbn arduino:avr:uno ${project}

upload: 
	arduino-cli upload -p ${port} --fqbn arduino:avr:uno ${project}

monitor: upload
	arduino-cli monitor -p ${port} --config 115200

kill:
	ps aux | grep arduino | awk '{print $2}' | xargs kill
