# Air Pollution Detector

An Embedded System project created with the objective to monitor air pollution using CO (Carbon Monoxide) and Sn02 (Tin Dioxide) sensors.
When the percentage level of one or both these gases crosses a certain threshold level then the sensors detect it and send appropriate signals to microprocessor. The micro controller interprets these signals and displays a message on the LCD screen. The appropriate LED for the gas sensor which has sent the signal is lit up and a buzzer beeps, to indicate that there is an increased level of pollution in the surrounding environment.

## Purpose
As the amount of pollution has tremendously increased in the past few years, measures must be taken to control and monitor the amount of toxic gases emitted by industries as these gases adversely affect the environment and the livelihood of wildlife and human beings. As Sn02 and CO are the most toxic of gases released by industries, this detector can be used to monitor the level of these gases emitted in exhaust pipes in factories.

## Components Used 

1. Sn02 (Tin Dioxide)  Gas Sensor
2. CO (Carbon Monoxide) Gas Sensor
3. 8051 Microcontoller Circuit Board
4. 8051 Microcontoller : AT89C51 (by Atmel)
5. 16 * 2 LCD Display
6. Buzzer
7. Two LEDs

## Features of the gas detectors

* Good sensitivity to the Harmful gases in wide range.
* Long life and low cost.
* Simple drive circuit.

## Softwares Used

* Kiel uVision4 : For writing and compiling code.
* Flash Magic: To burn the hex file into the micro controller.