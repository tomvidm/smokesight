# Chimney mounted spectrography system for detecting pollutants (DRAFT)
## Introduction
In polish cities like Wrocław, Kraków and Katowice, pollution is a big health risk during cold months with little to no wind. Low wind results in pollutants and particles not being transported away and diffused, and instead concentrate around the areas where it originated.

A big source of pollutant in these cities is people burning trash and organic waste in their fireplaces to heat their homes. Although it is illegal, and carries with it high penalties, finding out which fireplaces are burning toxic materials is difficult.

It would be beneficial for the health and wellbeing of  the inhabitants in these (and other) urban areas to address this problem by making it easier for the authorities to detect this practice and to apprehend those responsible. This document describes one solution to this challenge.

## The solution
An encased [sensor system] is mounted on the edge of a chimney. Through a stable connection to a cloud server, periodic measurements are uploaded and processed to determine if the composition of detected smoke shows signs of burning organic waste. If detected, the location and ID of the observing device will be sent with a notification to the [relevant audience].

## Description of system
The chimney mounted device consists of a microcontroller board, with peripheral connectivity devices and sensors. It is encased in such a way to let the system withstand varied environmental conditions such as rain, snow, hot and cold.

On one roof, there can be several devices. Each of these will be interconnected using a local wireless low-power network solution. (LPWAN / Bluetooth) One of these will be equipped with the ability to connect to a mobile network and function as an aggregator for the rest, including itself.

Readings from sensors will periodically be uploaded to a server located in the cloud. The server hosts services responsible for periodically pinging the remote devices, by their IDs, for data. The server will take these readings and process them to determine the presence of [bad smoke].

Detection of [bad smoke] will trigger a message to be sent to the [relevant audience].

The server will also host a database of professionally obtained data for which the decision making process can compare readings with.

In addition, a web interface can be provided to give real time data to the [relevant audience]. This interface will also show the devices along with their geographical data and the possible apartments that is connected through the chimney in question.

## Description of the sensor solution candidates
### Spectral analysis
Simple but possible expensive way to differ gases and particel clouds with different compositions.
### 

## Description of decision making
### If spectral analysis is feasible
Keep a database of spectral readings of real smoke and pollutant emmisions and use this data to compare them with the measured reading. If the spectral content differs to a large degree from that of burning firewood, newspapers and pellets (etc), it can be assumed that something else is burning. 

### If spectral analysis is non-feasible
Hmmmmmmmm

## Design considerations
### Division of the systems
The logical split between the subsystems would be the following

* Chimney mounted system
* * Special purpose computer
* * Sensor
* Server
* * Algorithms and decision making
* * Database
* Client
* * Web interface

### Cost-effective sensors for mass distribution
Spectrometers are prohibitively expensive. An alternative method of detecting high concentrations of pollutants will be needed.
### Detecting spectral signatures
As an educated guess, it is safe to assume that pollutants will have a different electromagnetic profile than that of firewood and other common items used for fireplaces. Based on this, there is a possibility that the hardware required to reliably detect pollutants does not need to be specialized, as  we would only be required to rule out common fireplace fuel rather than detecting specific pollutants. This can greatly reduce the time needed to collect data, but would require extra consideration of the decision making process to avoid false positives.
### Connectivity
The system needs to be able to reliably hold a connection to the internet - possibly using existing 3G/4G technology.

However, in places with ridiculous chimney density, this might be taxing on the capacity of mobile networks, so a simpler system between nearby devices and one to aggregate this to a mobile network can be more feasible - and a lot cheaper.
### Sensor system
The system needs to be able to measure the spectral signature in a narrow cone in a wide band. The spectral band of interest will include the visible spectrum, but also UV and IR. The exact dimensions must be determined based on real data.

Optical diode sensors packed in an array can be feasible, but a ready made and robust solution might be better. Research is needed to find out of there are solutions which are not prohibitively expensive.
### Application of machine learning
If the assumption about spectral signatures being distinct enough to avoid false positives falls flat, an application of machine learning to the decision process can be feasible.
### Power requirements
If the system is to consist of a stationary unit mounted on chimneys, it would be impractical to require the user to periodically replace a battery. Using a low power computer and small solar cells, the system can be independent from manual powering.
## Requirements
### Safety and lifetime
#### Environmental durability
#### Power supply
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

## user stories
* As an end user, I want...
* * to have a clear overview over all the devices in my "owned group" and their operational status through a simple web interface.
* * to have a real-time reading from all the devices in my "owned group"
* * to receive notifications about "alarms" from one of the devices in my "owned group".
* * to be able to - using the web interface - notify authorities about "alarm" levels of "bad smoke"
* As an admin, I want...
* * to have overview over ALL devices, by variying degrees of geographics specificity
* * to have access to debug information from the system and devices.
* As a server, I want...
* * to have all the devices be identifiable thorugh a unique ID
* * to store information about each device, its location, aparments connected to its chimney and more

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

## Ruminations
### For the government
As a first thought, a system like this can be a way to correlate actual air quality readings with the measurements done by these devices in a urban area. This gives the government a simple way to identify the scale of the problem. 

it also gives the authorities a simple way to detect who is burning bad stuff. (Need better wording obviously.) As a result, given public awareness, this can work as a deterrent and hence lead to improved air quality. The socio-economic benefits are obvious in the form of lowered health hazard.

## For cooperatives
jaidsjoadjd