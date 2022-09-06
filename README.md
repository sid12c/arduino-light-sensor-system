# Arduino Light Sensor System
> Worker productivity is an assessment of the efficiency of a worker and is greatly impacted by the brightness of their working environment. Employers must balance the usage of lighting in a room to improve productivity while maintaining energy efficient practices to minimize costs. The main objective of this project is to create a sensor system which can detect when a room is actively being used and is dark enough to need additional lighting in order to conserve energy and ensure the workplace has a healthy amount of light. This system utilizes light dependent resistors to detect the ambient light levels of the room, PIR motion sensors to detect whether a room is being used, a microcontroller to process and handle the information from the sensors, and a bluetooth module to connect the system with a phone to control the lights manually. The system works well in the testing environment and is capable of accomplishing its purpose with minimal human interaction.
<hr>

# Table of Contents
* [Problem Identification](#problem-identification)
* [Sensors Selection](#sensors-selection)
* [Signal Processing](#signal-processing)
* [Physical Considerations](#physical-considerations)
* [Logic Implementation](#li)
* [Sensor Fusion Algorithms](#sfa)
* [Results](#r)
* [Personal Reflections](#pr)
* [References](#ref)
* [Appendix](#a)
# <a name="problem-identification"></a>Problem Identification
In homes and workplaces, lighting is often human driven, and requires human interaction to turn on and off. The first issue occurs when a room is lit by natural light, and as the sun sets the room becomes darker. When this happens, people already in the room will not notice exactly when it is no longer bright enough to achieve maximum productivity as they will be accustomed to the gradual change in lighting. An optimal light level for offices is 250 lux while an optimal level for the most detailed tasks is around 500 lux [2]. Thus the first step of this project is to design a sensor system which detects the level of light in a room ranging from 0 to 500 lux. The next issue occurs when the lights in a room are left on for an extended duration of time with no people in the room. This leads to an unnecessary increase in costs and is harmful to the environment [6]. The second step of this project is to use a sensor system which accurately detects whether a person is using a room or area. Finally a microcontroller must be used to process the information from the two sensor systems and decide the state of the room’s lighting.
# <a name="sensors-selection"></a>Sensor Selection
In this project, LDRs or Light Dependent Resistors were used to measure the brightness in the room. A light dependent resistor is a variable resistor whose resistance varies depending on the amount of light falling on its surface. The working principle of the LDR is photoconductivity, the tendency of the substance to conduct electricity to an extent that depends on the intensity of light-radiant energy striking the surface of the sample. When light falls on the surface of the LDR, the light photons are absorbed by the semiconductor, which then breaks free some of the electrons to conduct electricity. As more light falls on the surface of the LDR, the less resistance it has. To test the LDRs, the resistance of the LDR and the brightness of the room was measured in order to see how the sensor responded without any processing. To measure the brightness, a phone’s ambient light sensor was used through the app Arduino Science Journal. This measured the room brightness in Lux, and gave an accurate independent variable to test the sensor.
[Appendix Section A.1](#a1) shows the raw data collected and also includes the curve of the resistance by light levels. In order to see the curve clearly, the first data point was omitted from the graph. 
As seen in Figure 1, there are three other options for light sensing. For this project, LDRs are the best option. Since this project revolves around low light levels, phototransistors can be ruled out, and since the system only needs to detect visible light over long periods of time, photodiodes can also be ruled out. The photoresistor is tuned better for visible light, has no leakage current, and has the added benefit of being the cheapest option.

![Screenshot 2022-09-06 112843](https://user-images.githubusercontent.com/74881981/188675253-928a6c78-6ef7-41c0-bef2-0d131eb510c4.png)

# <a name="signal-processing"></a>Signal Processing
From the data collected, the three point method resulted in a resistor value to linearize the sensor as follows:

![Screenshot 2022-09-06 113842](https://user-images.githubusercontent.com/74881981/188677472-6473290f-6aea-4221-815f-619583ca5cea.png)

The resistance of the linearized system at a brightness that would be dark enough for the lights to turn on was checked, and a Wheatstone Bridge with the same R2 value was created. two resistors of similar resistance for the R1 and R3 values were used, then the Vout when the room was at its brightest and darkest was determined. Finally the project utilizes a LM324N quad op-amp to bring the voltage range to [0,5]V so the microprocessor (Arduino Uno) could take the signal.
After implementing the circuit design as shown in Figure 3, the sensor had to be calibrated to make sure the circuit functioned as intended. The output of the circuit had to be 0 V when the room lights were off, and 5 V when the lights were on maximum brightness. In order to achieve this output, the system uses a voltage divider off the 5 volt source using potentiometers, using potentiometers that were placed to bias the final output. Finally the room brightness was lowered to a level at which the lights should turn on and the output of the circuit was found to be used in the code later. The final equation from this system as shown in Figure 4 is V(L) = 0.013L.

![Screenshot 2022-09-06 114008](https://user-images.githubusercontent.com/74881981/188677763-b2762ac5-61fa-4b44-8fec-17b2b0991d73.png)

![Screenshot 2022-09-06 114041](https://user-images.githubusercontent.com/74881981/188677880-fffe2470-906b-4f13-8104-2454a44b3c90.png)

# <a name="physical-considerations"></a>Physical Considerations
When planning the sensor system, the effects of the environment must be taken into account when considering the sensors to use. Since this system is to be used indoors, The environment will not be very humid, will have little to no water exposure, be within 60 and 70 °F, and will not be exposed to anything that would not be found in a house (such as radiation, corrosive materials, and harmful gasses). The datasheet for the LDR shows that the ambient temperature ranges from -22 to  158 °F. Thus the sensor can be used safely and accurately in this environment. The data sheet for the LDR can be found in [Appendix Section A.4](#a4) and the full checklist and Bill of Materials can be found in [Appendix Section A.5](#a5).
# <a name="li"></a>Logic Implementation
This system uses a microcontroller to process the data from the sensors and implement the logic needed. The Arduino Uno Rev3 was chosen for its low cost, flexible power supplies, and easy programmability. The microcontroller follows the flowchart in [Appendix Section A.2](#a2), provided that the controller has received the on string from the bluetooth module. For each of the LDR systems as shown in [Appendix Section A.3](#a3), the microcontroller checks to see if there are any inaccurate sensors, then proceeds to make its decision and activates or deactivates the lights accordingly. The code used for the final system can be found in [Update 3](Project_Update_3/Project_Update_3.ino).
# <a name="sfa"></a>Sensor Fusion Algorithm
In this project, the most important issue that needed to be solved was implementing a sensor system which would not be impacted by the lighting from the system. Since any sensor near the work area has to detect when the light levels were low, a low pass filter was implemented. For the sensors that were farther away from the work area and the lighting, a high pass filter was implemented. These complementary filters allowed for the system to sense the light level of the room with little effect from the lighting that would turn on when the sensors detected darkness.
# <a name="r"></a>Results
This project provides a solution to the problem presented and accomplishes the goals outlined in the beginning. As seen in Appendix Section A.1, the LDR has a nonlinear curve, but after the signal processing, had a linear output that ranged [0,5] V. The Motion Sensor worked as intended and when assembled with the LDR systems as shown in Appendix Section A.3, provided the necessary data needed for the microcontroller to function. Finally, the Bluetooth module allows for the system to start or stop manually.
The final setup is shown below. Figure 5 shows the Arduino and its connections. Figure 6 is the PIR Motion Sensor. Figure 7 shows the farthest LDR sensor system with the high pass filter. Figure 8 shows the closest LDR sensor system with the low pass filter. Finally, Figure 9 shows the bluetooth module and Figure 10 shows the LED lighting.

![Screenshot 2022-09-06 114555](https://user-images.githubusercontent.com/74881981/188679051-31e24a82-45a3-4aba-8399-1afbf0b0f6c4.png)

The videos showing the progress of this project are shown below:
### Update 1
https://youtu.be/QUmd0tf2fik
### Update 2
https://youtu.be/JcJ33M_6lLg
### Update 3
https://youtu.be/-QiBxlEldE0

# <a name="pr"></a>Personal Reflections
This project proved to be a challenge but was still enjoyable as I learned many new ways to use my existing knowledge about circuits to make systems with an actual impact in my life. Playing around with the sensors and writing the code to have them function correctly when activating the lights was the most pleasant part of the project. One of the least enjoyable parts of this project was not having the right parts and tools to build this system from the start, and having to purchase them as needed resulted in many trips to stores near my home. In future iterations of this project, I would make sure to plan out the tools needed before beginning and purchasing them all at once. Another revision I would do would be to solder my components onto a board and 3D print cases for the whole system, that way the final product would look much cleaner and get more accurate results.
# <a name="ref"></a>References
When implementing the LDR sensor system, the physics and understanding of the sensor was taken from [1], however, the example given in the article was using a simple voltage divider to measure light levels. To get more accurate data, a Wheatstone Bridge was used instead. When using the PIR Motion Sensor, article [4] was referenced, but due to the different models of the sensors, none of the hardware or software from the example was used. 

[1] Agnihotri, N. (n.d.). What are the different types of light sensors? Engineers Garage. Retrieved June 12, 2022, from https://www.engineersgarage.com/light-sensors-ldr-photodiode-phototransistor-solar-cell/#:~:text=LDRs%20or%20photoresistors%20have%20a,visible%20and%20infra%2Dred%20lights.

[2] Dennis. (2018, March 10). A GUIDE TO LUX LEVELS. Saving Light Bulbs - The Energy Saving LED Specialists. Retrieved July 31, 2022, from https://www.saving-light-bulbs.co.uk/blog/a-guide-to-lux-levels/#:~:text=The%20living%20and%20dining%20rooms,500%20LUX%20and%20300LUX%20respectively.

[3] Giang, V. (2020, December 2). How lighting affects the productivity of your workers. UNC. Retrieved July 31, 2022, from https://onlinemba.unc.edu/news/how-lighting-affects-productivity/

[4] PIR motion sensor: How to use PIRS W/ Arduino & Raspberry Pi. Arduino Project Hub. (n.d.). Retrieved July 16, 2022, from https://create.arduino.cc/projecthub/electropeak/pir-motion-sensor-how-to-use-pirs-w-arduino-raspberry-pi-18d7fa

[5] Shawn. (2020, June 5). What is a light sensor? types, uses, Arduino Guide. Latest Open Tech From Seeed. Retrieved June 27, 2022, from https://www.seeedstudio.com/blog/2020/01/08/what-is-a-light-sensor-types-uses-arduino-guide/

[6] US Department of Energy. (n.d.). When to turn off your lights. Energy.gov. Retrieved July 31, 2022, from https://www.energy.gov/energysaver/when-turn-your-lights 

# <a name="a"></a>Appendix
## <a name="a1"></a>Section A.1
### Raw Light Dependent Resistor Data

![Screenshot 2022-09-06 120924](https://user-images.githubusercontent.com/74881981/188684125-e1a770ef-1298-42a9-b7d2-44602562e82c.png)
## <a name="a2"></a>Section A.2
### Microcontroller Flowchart

![Screenshot 2022-09-06 121017](https://user-images.githubusercontent.com/74881981/188684391-8611ec82-1884-4b5a-807b-629257fb7cd3.png)
## <a name="a3"></a>Section A.3
### Sensor Systems Pin Layout

![Screenshot 2022-09-06 121251](https://user-images.githubusercontent.com/74881981/188684753-a3801074-d25d-4aca-99ec-156afe9e0f2f.png)
## <a name="a4"></a>Section A.4
### Light Dependent Resistor Datasheet

![Screenshot 2022-09-06 121349](https://user-images.githubusercontent.com/74881981/188684966-1e78d941-c855-4838-a6aa-2f7b1811c713.png)
## <a name="a5"></a>Section A.5
### Sensors Checklist

[Sensors Check List.xlsx](https://github.com/sid12c/arduino-light-sensor-system/files/9498797/Sensors.Check.List.xlsx)
