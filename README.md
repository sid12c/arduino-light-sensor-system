# Arduino Light Sensor System
> Worker productivity is an assessment of the efficiency of a worker and is greatly impacted by the brightness of their working environment. Employers must balance the usage of lighting in a room to improve productivity while maintaining energy efficient practices to minimize costs. The main objective of this project is to create a sensor system which can detect when a room is actively being used and is dark enough to need additional lighting in order to conserve energy and ensure the workplace has a healthy amount of light. This system utilizes light dependent resistors to detect the ambient light levels of the room, PIR motion sensors to detect whether a room is being used, a microcontroller to process and handle the information from the sensors, and a bluetooth module to connect the system with a phone to control the lights manually. The system works well in the testing environment and is capable of accomplishing its purpose with minimal human interaction.
<hr>

# Table of Contents
* [Problem Identification](#problem-identification)
* [Sensors Selection](#sensors-selection)
* [Signal Processing](#signal-processing)
* [Physical Considerations](#physical-considerations)
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
# <a name="physical-considerations"></a>Physical Considerations
# <a name="sfa"></a>Sensor Fusion Algorithm
# <a name="r"></a>Results
# <a name="pr"></a>Personal Reflections
# <a name="ref"></a>References
# <a name="a"></a>Appendix
