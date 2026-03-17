
# Changes to be made research 

- [ ] **Revise research question**
      How does **ROS2 MoveIT library** compare to the **standard toolkit provided by UFactory** in terms of effectively implementing a **trajectory planning algorithm?**
		What software solution will best be applied to a UFactory Lite 6 arm robot, for trajectory planning and calibration in 3D space? (Variant 2)
		
- [ ] 


- [ ] **Sub-questions**
	 What are the benefits of using the standard toolkit provided by UFactory? 
		 ***Library research:***
		 Read through official documentations and compile deductions from multiple sources.
		 ***Lab research:***
		  Design and execute scripts and monitor the development process on several factors such as; intuitivity, ease-of-use, skill-required, flexibility and control.
		 ***Field research:***
		  Conducting interviews with co-workers and peers and documenting relevant findings.
	 What are the benefits of using ROS2?
		 ***Library research:***
		 Read official documentation and compile information on the functionality and benefits of ROS2.
		 ***Field research:*** 
		 Conduct interviews with co-workers and previous interns and collect opinions on the benefits of ROS2 (or its downsides)
		 ***Lab research:***
		 Develop a small prototype and compare results with the default toolkit, across the several factors mentioned above; intuitivity, ease-of-use, skill-required, flexibility and control.
	 What is a trajectory-finding algorithm ?
		 ***Library research:*** 
		 Read and research sources online (websites, libraries etc. ) for theoretical information.
		 ***Workshop research:***
		 Prototype a path-finding algorithm for the arm, making sure to test both in simulation and on real hardware.
		 ***Lab research:***
		 Test limits of the algorithm, as well as security testing (document findings on whether the arm can stop at joint limits, doesn't break external equipment and can orient itself well in 3D space. )
		How to implement a trajectory-planning algorithm for the UFactory Lite 6 robot arm?
		***Library research:***
		Deep-dive into trajectory planning theory.
		***Field research:***
		Conduct an interview with a previous intern and acquire more information on what they produced during their time so that it would benefit the decision making factor.
		***Lab research:***
		Develop an effective trajectory-planning solution for the robot arm and test it by moving payloads between two positions.
		***Workshop research:***
		Develop a demonstration of the algorithm and present to associates to evaluate its effectiveness.
	 Which of the two technologies are better suited for path-finding?
		Note: This may be a good conclusion, rather than a sub-question.  
	 

Show Joris and Gayatri

Trajectory algorithm is focus


## Requirements 

### Functional
*What the system does?*
Plan trajectory to a user-given position.
Pick payload from position X and drop at position Y.
The system must calibrate and orient itself in 3D space.
The system must hold and never drop the payload until it has reached final destination
Movement must happen collision-free.
The system detects joint limits and doesn't over-turn.

### Non-functional
*How well the system does it?*
The system shall stop within 500 ms of any fault detection.
The arm should be able to operate a full working day (8-10 hours), without needing restart.
The system shall achieve position sufficient for the safe delivery of payload.


# Requirements theory

![[Pasted image 20260309141756.png]]

https://stackoverflow.com/questions/16475979/what-is-the-difference-between-functional-and-non-functional-requirements

