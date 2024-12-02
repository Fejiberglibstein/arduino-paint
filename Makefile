project = arduino-paint.ino

port = ${shell find /dev/ttyACM*}

all: compile upload monitor


compile: 
	arduino-cli compile --fqbn arduino:avr:uno ${project}
	touch compile

.PHONY: upload
upload: compile
	arduino-cli upload -p ${port} --fqbn arduino:avr:uno ${project}

.PHONY: monitor
monitor: upload
	arduino-cli monitor -p ${port} --config 115200

.PHONY: kill
kill:
	ps aux | grep arduino | awk '{print $$2}' | xargs kill -9
