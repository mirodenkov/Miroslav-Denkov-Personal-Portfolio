
Hi Firas,  
  
We have the following assignment:

In the context of the Big Chemistry/RobotLab project we are interested in creating a self-driving lab (SDL). In general, we expect to have to deal with both sample transport and the exchange of information. To this end, we are building a demonstrator together with the Eindhoven University of Technology (TU/e). This demonstrator involves sample preparation with a pipetting robot, sample transport with a robot arm and absorption measurements with a plate reader. To communicate with these devices, it is beneficial to use a common communication standard. SILA2 is such a standard. It is designed to enable standardized connectivity of lab equipment in chemistry laboratories ([https://sila-standard.com/standards/](https://eur01.safelinks.protection.outlook.com/?url=https%3A%2F%2Fsila-standard.com%2Fstandards%2F&data=05%7C02%7Cm.denkov%40student.fontys.nl%7C64b4fe9607df4b12da3f08de331e9da6%7Cc66b6765b7944a2b84ed845b341c086a%7C0%7C0%7C639004403730639268%7CUnknown%7CTWFpbGZsb3d8eyJFbXB0eU1hcGkiOnRydWUsIlYiOiIwLjAuMDAwMCIsIlAiOiJXaW4zMiIsIkFOIjoiTWFpbCIsIldUIjoyfQ%3D%3D%7C0%7C%7C%7C&sdata=BLeATIkBzACCU%2FlRTWxqXrksNOpPiMrLF1eWnyGdqps%3D&reserved=0 "Original URL: https://sila-standard.com/standards/. Click or tap if you trust this link.")). 

Assignment

Continue the development of a SILA2 web API protocol to control a Ufactory robot arm. Demonstrate the protocol by moving samples from an Opentron pipetting robot to a Tecan plate reader using the self-developed web API. 

The robot should be able to automatically find its positions and trajectories e.g. when the robot arm has moved and avoid collisions with equipment placed in its neighborhood. Make a connection to the Digital Twin. Provide support in the preparation, execution, and evaluation of the various use-cases of our university chemistry partners. Investigate the appropriate choice of software tools to incorporate path planning under constraints. For example, could it be beneficial to use ROS2 instead of the current built-in tooling provided by UFactory?  

Technologies

Intermachine communication, Python, trajectory planning, inverse kinematics

Contact

This assignment is done as part of NGF2 Big Chemistry Robotlab project. In which Fontys works togethers with TU Eindhoven, Amolf, Rijksuniversiteit Groningen and Radboud University. Lecturers researchers of the research group High Tech Embedded Software are guiding your assignment. The assignment location is at Fontys Rachelsmolen R10.

Contact for this assignment: j.geurts@fontys.nl

  

-------------------------------------

  

I think this might a good match. One thing to note: however, is that this is a continuation of previous work by other interns. Currently, one semester 5 intern is integrating a camera into our setup to automatically locate certain instruments and positions. He is probably not going to be able to include trajectory planning, as that is to far outside his scope.

  

Regards,  
Mark Beks


![[Pasted image 20260309102502.png]]


![[Pasted image 20260309102522.png]]

