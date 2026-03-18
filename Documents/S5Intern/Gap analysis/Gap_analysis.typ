#set page("a4")
#set heading(numbering: "1. ")
#set text(font: "Times New Roman")
#show "Python": name => box[
  #box(image(
    "../../../Logos/python-logo-only.png",
    height: 0.8em,
  ))
  #name
]
#show "ROS": name => box[
  #box(image(
    "../../../Logos/RosLogo.png",
    height: 0.7em,
  ))

]
#let hocean = rgb("#70f2e1")
#show heading.where(numbering: none, level: 1): it => align(center, text(size: 24pt, it.body))
#show heading.where(numbering: none, level: 2): it => align(center, text(size: 20pt, it.body))
#show heading.where(numbering: none, level: 3): it => align(center, text(size: 16pt, it.body))
#heading(numbering: none, outlined: false, level: 1)[Gap Analysis]
#heading(numbering: none, outlined: false, level: 2)[Author: Miroslav Denkov]
#heading(numbering: none, outlined: false, level: 3)[Project: Robotarm]
#set heading(numbering: "1. ")
#outline(title: align(left, text(size: 14pt)[Table of Contents]))

#line(length: 100%)
= Executive Summary
The purpose of this analysis is to determine the gap between the current state of the project and what actions must be undertaken to close it(More information about the project is in the Project Plan).
= Scope & Objectives
The current scope of the project is to automate and secure the trajectory planning of the arm, by providing a solution to the algorithm.

#figure(
  table(
    columns: 4,
    table.header[*Must*][*Should*][*Could*][*Won't*],
    //Row 1
    [The system must plan its trajectory ], [The system should have automatic positioning calibration], [], [],
    //Row 2
    [The system must plan its trajectory ], [], [], [],
    // Row 3
    [The system must be able to detect joint movement limit], [], [], [],
    //Row 4
    [The system must be able to detect joint movement limit],
    [],
    [],
    [The system should have automatic positioning calibration],
  ),
  caption: [MoSCoW table],
)<moscow>
= Current State Assesment
The currentstate of the system is in acceptable condition, though it is far from the final product that is to be used by end users for any kind of scientific research

= Desired State
The desired state of the system is it being able to carry payload from an Opentron pippeting robot to a Tecan plate analyzer, without collision. The arm must be able to orient itself in 3D space and calibrate it's position to compensate in changes of space, distance and position.
= Gap Analysis
From the point we find ourselves in, point A, we must reach point B, which would be the desired state of the product by the end of the project.

#figure(
  image(
    "../../../Tables and diagrams/Project_Timeline.drawio.png",
  ),
  caption: [Base project trajectory],
)<basetr>

Now as seen in @basetr, the arm is currently in a functioning state. UFactory supplies their robots with a Python API and a development environment, to write software for the robot arm. It has a built-in simulator and can communicate with the real hardware with minimal latency. The current problem lies in trajectory planning, because the process is not automated by default and the developers must make it happen. Fortunetly, built-in security protocols against collision exist in the default pipeline. Lastly, for trajectory planning , operating the arm using ROS would be beneficial, since it contains libraries for trajectory planning, which makes the development process simpler, the caveat being that the arm needs to be set up to work with ROS. Now the project's trajectory would become much larger.

#figure(image("../../../Tables and diagrams/Updated_project_timeline.drawio.png"), caption:[Trajectory in more detail])<updtr>

Based on @updtr, we can deduce the gaps to the following:
+ No trajectory planning implemented.<no_trajectory>
+ No ROS support. <no_ros>
+ No environment for ROS, nor simulation.<no_sim>


= Priority Matrix
As the project evolves so must the plan to tackle each challenge evolve with it. Making sure that the most important actions are prioritized to breach the gap between un-finished and finished product.

#figure(
  table(
    columns: 4,
    table.header[*Priority*][*Description*][*Timeframe*][*Gap*],
    //Row 1
    [Critical],[Gap that requires immediate attention and is essential to be done, usually more complex problems that require more time.],[2 weeks],[+ No environment for ROS, nor simulation.
    + No ROS support.],
    //Row 2
    [High],[Gaps that are in high priority and are to be adressed as quick as possible.],[1 week],[+ No trajectory planning implemented.
    ],
    // Row 3
    [Medium],[Gaps that are lesser priority than high and but attention is not needed immediately.],[less than a week],[],
    // Row 4
    [Low],[Gaps that need to be closed the last(after medium priority gaps)],[less than half a week],[],
  ),caption: [Priority Matrix]
)<prmatrix>
= Recommendations
I recommend to start addressing the development environment and simulation for ROS. Then move onto trajectory planning solutions

