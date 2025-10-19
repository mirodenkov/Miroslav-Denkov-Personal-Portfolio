# Timers Output technical report

- *Author* - Miroslav Denkov
- *Student number* - 524298


## Introduction

The following document describes my approach when conducting the Timer Output Assignment.

## Circuit schematics

![[Pasted image 20250505185817.png]]

![[Pasted image 20250511114718.png]]

For the Assignment the STM32 Nucleo F303RE microcontroller was used. The following actuators were used and attached to the pins:

J-deal Micro-Servo motor -> D11(PA7)
LED -> D10(PB6)

For the experiment the actuators were attached to the Arduino connectors as to make it easier for testing with a logic analyzer later, which will be connected to the corresponding morpho pin.

## Code design

For this assignment I went with a traditional modular C structure while trying to separate logic whenever I could.

The application itself is very straightforward. The program starts by calling all the system setup functions, GPIO, timers etc., then calls the LED_breathe function and servo after it in a loop.

![[Pasted image 20250511121223.png]]


## Analysis and testing

Not only could I confirm physically the programs were running based on the actuator reactions, but I also used a logic analyzer to inspect if the signals are running how I would expect

### LED signal
![[Pasted image 20250510155523.png]]

### Servo motor
![[Pasted image 20250510155221.png]]
