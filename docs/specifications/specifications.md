# Aerial system for remote spectrography of smoke pillars (DRAFT)
## Introduction
In polish cities like Wrocław, Kraków and Katowice, pollution is a big health risk during cold months with little to no wind. Low wind results in pollutants and particles not being transported away and diffused, and instead concentrate around the areas where it originated.

A big source of pollutant in these cities is people burning trash and organic waste in their fireplaces to heat their homes. Although it is illegal, and carries with it high penalties, finding out which fireplaces are burning toxic materials is difficult.

It would be beneficial for the health and wellbeing of  the inhabitants in these (and other) urban areas to address this problem by making it easier for the authorities to detect this practice and to apprehend those responsible. As a solution to this problem, we propose a system for detecting pollutants in smoke columns using a combination of simple diode sensors, UAVs with mounted cameras and an algorithm for correlating measured data with expected data.

## Design considerations
### Division of the systems
The logical split between the subsystems would be the following

* Aerial system
* * On-board computer w/ mobile networking (OAB)
* * UAV
* * Spectrometer
* * Mounted camera
* Server
* * Algorithms and decision making
* * Database
* Client
* * Web interface

### Detecting spectral signatures
As an educated guess, it is safe to assume that pollutants will have a different electromagnetic profile than that of firewood and other common items used for fireplaces. Based on this, there is a possibility that the hardware required to reliably detect pollutants does not need to be specialized, as  we would only be required to rule out common fireplace fuel rather than detecting specific pollutants. This can greatly reduce the time needed to collect data, but would require extra consideration of the decision making process to avoid false positives.
### Connectivity
To maintain control and to ensure the safety of both the equipment and people, the system needs to be able to reliably hold a connection to the internet - possibly using existing 3G/4G technology. 
### Response in case of a faulty OAB
In case of a fault on the OAB, a security measure should be put in place to quickly bypass the OAB when controlling the UAV. The server should periodically interface with the UAV directly, and in case of corrupted or lack of responses from the OAB, the server should maintain direct control of the UAV.
### Who controls the UAV?
One idea is to have the on-board computer receive commands from the server, which in turn receives it from the user side. It is unknown if the extra latency is significant at all. If so, control over the UAV should be given more directly to the user, and potentially let the on-board computer interface with the UAV to retrieve positioning data etc.
### On-board computer
This component needs to be able to keep a connection using mobile networks.
Embedded linux can be enough for the purposes of this design, as the majority of the computational work will be done serverside. The OAB should:

* Receive (Possibly encrypted) requests from the server and pass these to the appropriate service
* Send (Possible encrypted) requests and responses to the server
* Run background services for continuous monitoring of the peripherals
* * uav-service
* * camera-service
* * spectrometer-service
* Be responsible to packing streaming data and transmitting it
### Sensor system
The system needs to be able to measure the spectral signature in a narrow cone in a wide band. The spectral band of interest will include the visible spectrum, but also UV and IR. The exact dimensions must be determined based on real data.

Optical diode sensors packed in an array can be feasible, but their angular sensitivity must be minimized.
## Requirements
### Interfaces

#### OBC-UAV interface
To control and monitor the state of the UAV
#### OBC-Camera interface
To control and to receive streams from the camera
#### OBC-Spectrometer interface
To receive streams from the spectrometer
#### webapp-server interface
To send and receive data between the client and the server.
#### server-OBC interface
To send and receive data between the server and the on-board computer.
#### human-webapp interface

## User scenarios

* 001 - as a user, I want to reliably and quickly analyze a smoke pillar from a distance 20m - 50m to determine whether or not the smoke is caused by firewood or commercially and commonly available pellets.
* 002 - as a user, I want the system to compare measured data against a database of professionally obtained data.
* 003 - as a user, I want to remotely control the UAV and the viewing angle of the camera with low latency.
* 004 - as a user, I want to remotely stream video from the UAV mounted camera, as well as raw data from the remote sensing device.
* 005 - as a user, I want the position of the UAV to be continuously monitored.
* 006 - as a user, I want to easily mark addresses using the UAV position and the camera output for geographic pinpointing.
* 007 - as a user, I want to use a web application for visualization and monitoring of the state of the system.
* 008 - as a user, I want to be able to report false positives to customer support through the web interface.

## Roadmap
* Phase 1 - Planning
* * Determined feasbility
* * Sketch the system and map out scenarios
* * Obtain real world spectral signatures of burning material
* * Run simulations on test data using Octave/Matlab
* Phase 2 - Prototyping
* * Build a working spectrometer
* * Interface with a Raspberry PI
* * Run tests on data and verify that it works withing desired specs
* Phase 3
* * Develop an on-board computer and connect peripherals
* * Use on-board services to interface with peripherals
* * Build a client-server model which interfaces with on-board computer
* * Make sure all interfaces are working
* * Advertise to idiot beaurucrats
* Phase 4
* * Field testing
* * Bug quashing
* Phase 5
* * Get money
* * 