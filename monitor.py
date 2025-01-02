# Importing necessary modules
import serial # type: ignore
import time

# Initialize serial communication
arduino = serial.Serial(port='COM3', baudrate=9600, timeout=1)

def write_read(x):
    arduino.write(bytes(x, 'utf-8'))  # Send data to Arduino
    time.sleep(0.05)                 # Short delay
    data = arduino.readline()        # Read data from Arduino
    return data

while True:
    blink_status = write_read("blink_status")
    if blink_status.decode('utf-8').strip() == "DROWSY":
        print("Warning: Driver is drowsy! Take action immediately.")
    else:
        print("Driver is alert.")
