
### Author: Miroslav Denkov
### Student number: 524298


# Introduction
This report shows my work on the "Timers Input" assignment.  


# Circuit Design
![[Pasted image 20250526110231.png]]
Using the Nucleo F303RE I have connected the HC-SR04 UltraSonic sensor on the following pins:

Trigger -> PA6
Echo -> PB6
The sensor is supplied with power from the 5V pin from the board and is connected to its GND pin.

# Code Design

![[Pasted image 20250526111453.png]]
The main program is quite simple. Here is how it works:
### Setup
- We configure the system clock
- We configure the SysTick timer, for delays.
- We setup the GPIOs (B and A)
- We initiate USART2
- We setup the Trigger and Echo timers
### Loop
- We call the function PrintTrigger(), that prints sensor readings, converted to centimeters
- We add a delay() as to not flood the UART too much

# Testing and measurements


![[Pasted image 20250601145047.png]]

During testing, the sensor seemed to be functioning, although a couple problems occured.

- At first the sensor only gave one measurement and then stopped, it turned out there was a problem with the SysTick timer software, it was fixed.
- The sensor seems to be giving accurate readings, but only when the wires are held by hand. This could be a problem with the unit that is being tested.
- Lastly, tests with the logic analyzer on the Trigger pin are impossible, as the sensor seems to freeze whenever I want to read it with the analyzer. The Echo pin does not suffer from this effect, though. I was able to capture some data on it.
![[Pasted image 20250601231107.png]]

