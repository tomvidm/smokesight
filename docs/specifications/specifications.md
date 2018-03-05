# Chimney mounted spectrography system for detecting pollutant (DRAFT)
## Introduction
In polish cities like Wrocław, Kraków and Katowice, pollution is a big health risk during cold months with little to no wind. Low wind results in pollutants and particles not being transported away and diffused, and instead concentrate around the areas where it originated.

A big source of pollutant in these cities is people burning trash and organic waste in their fireplaces to heat their homes. Although it is illegal, and carries with it high penalties, finding out which fireplaces are burning toxic materials is difficult.

It would be beneficial for the health and wellbeing of  the inhabitants in these (and other) urban areas to address this problem by making it easier for the authorities to detect this practice and to apprehend those responsible. This document describes one solution to this challenge.

## The solution
A simple spectrometer will be mounted on the top of a chimney. A small energy efficient computer will be encased in a container which can withstand smoke, with wifi/mobile network connectivity. When smoke is detected, a process will run on the computer and actively monitor the spectral content of the particles. Data will be sent to a server along with the ID of the device and the data will be tested against known spectral signatures of common firewood etc. If the system determines that someone is burning non-traditional fuel in the fireplace, a notice will be sent to landlord/police.
[some words about "cooperatives"]

## Design considerations
### Division of the systems
The logical split between the subsystems would be the following

* Chimney mounted system
* * Special purpose computer
* * Spectrometer
* Server
* * Algorithms and decision making
* * Database
* Client
* * Web interface

### Detecting spectral signatures
As an educated guess, it is safe to assume that pollutants will have a different electromagnetic profile than that of firewood and other common items used for fireplaces. Based on this, there is a possibility that the hardware required to reliably detect pollutants does not need to be specialized, as  we would only be required to rule out common fireplace fuel rather than detecting specific pollutants. This can greatly reduce the time needed to collect data, but would require extra consideration of the decision making process to avoid false positives.
### Connectivity
The system needs to be able to reliably hold a connection to the internet - possibly using existing 3G/4G technology.
### Sensor system
The system needs to be able to measure the spectral signature in a narrow cone in a wide band. The spectral band of interest will include the visible spectrum, but also UV and IR. The exact dimensions must be determined based on real data.

Optical diode sensors packed in an array can be feasible, but a ready made and robust solution might be better. Research is needed to find out of there are solutions which are not prohibitively expensive.
### Application of machine learning
If the assumption about spectral signatures being distinct enough to avoid false positives falls flat, an application of machine learning to the decision process can be feasible.
### Power requirements
If the system is to consist of a stationary unit mounted on chimneys, it would be impractical to require the user to periodically replace a battery. Using a low power computer and small solar cells, the system can be independent from manual powering.
## Requirements
### Hardware
#### Sensor
#### MCU / Small computer
#### Server
#### Web interface
### Interfaces
#### Client-Server interface
To interface the webapp and the server
#### Server-to-Devices interface
To interface the server and the individual devices
#### MCU-to-spectrometer interface
To interface with the spectrometer

## Roadmap
* Phase 1 - Planning
* * Determine feasbility
* * Obtain real world spectral signatures of burning material
* * Run simulations on test data using Octave/Matlab
* Phase 2 - Prototyping
* * Somehow obtain a working spectrometer / instrument which measures desired range of frequencies
* * Interface it with a microcontroller / computer-on-a-board / RaspberryPI
* * Run tests on data and verify that it works withing desired specs
* Phase 3
* * Put data and decision making stuff on a server
* * Make sure all interfaces are working
* * Make sure it works
* * Get numbers
* * Advertise to idiot beaurucrats / seduce them with numbers or the prospect of shekels
* Phase 4
* * Field testing
* * Bug quashing
* Phase 5
* * Get money
* * Advertise to idiot beaurucrats in Prague or something
* * Repeat