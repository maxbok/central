Simple IoT project to control lights from different devices such as a local hosted website, an iOS app or sensors.

Each connected device will be equipped with an Atmega328P and a NRF24L01.  
The NRF24L01 is used to communicate with the server.

A RaspberryPi will be used as the server and will also be connected to a NRF24L01 to receive and send messages to the devices.  
The server will also provide actions and info of the connected devices.

# Communication

NRF24L01 with mesh.

Devices will ping the server every seconds with their current state: battery, intensity…

# Devices

Atmega328P and a NRF24L01 powered by a battery.

## List

### Incandescent light

Endless potentiometer to control brightness  

### LED light

~10W RGB LED  
~10W bright white LED  
~10W warm white LED  
Switch to go from white to rgb  
Endless potentiometer to control brightness  
Endless potentiometer to control color


### Sensor

Move sensor  
Temperature sensor  
Light sensor

**Optional**  
Gas sensor

# References

http://hack.lenotta.com/arduino-raspberry-pi-switching-light-with-nrf24l01/  
http://www.homautomation.org/2014/06/11/communicating-from-low-power-arduino-to-raspberry-pi-via-nrf24l01/

##### Arduino
http://www.home-automation-community.com/arduino-low-power-how-to-run-atmega328p-for-a-year-on-coin-cell-battery/  
http://www.instructables.com/id/Wireless-Remote-Using-24-Ghz-NRF24L01-Simple-Tutor/?ALLSTEPS  
http://www.instructables.com/id/NRF24L01-ATmega328P-PU-Radio-Sensor/?ALLSTEPS

##### RaspberryPi
https://tmrh20.github.io/RF24/RPi.html

