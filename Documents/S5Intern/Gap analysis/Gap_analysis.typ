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
#show "logo_lib": name => box[
  #box(image(
    "../../../Logos/Logo-library.png",
    height: 0.7em,
  ))
]
#show "DOT": name => box[
  #box(image(
    "../../../Logos/DOT-Framework-1f52362b.jpg",
    height: 0.7em,
  ))
  #name
]
#show "logo_opentrons": name => box[
  #box(image(
    "../../../Logos/Opentrons'_Logo.png",
    height: 0.7em,
  ))
]
#show "UFactory": name => box[
  #box(image(
    "../../../Logos/X-ARM_logo.gif",
    height: 0.7em,
  ))
  #name
]
#let hocean = rgb("#70f2e1")

#show "Github": name => box[
  #box(image(
    "../../../Logos/GitHub_Invertocat_Black_Clearspace.png",
    height: 1.30em,
  ))
  #name
]
#show "logo_field": name => box[
  #box(image(
    "../../../Logos/Logo-field.png",
    height: 0.7em,
  ))

]
#show "logo_lab": name => box[
  #box(image(
    "../../../Logos/Logo-lab.png",
    height: 0.7em,
  ))
]

#show "logo_showroom": name => box[
  #box(image(
    "../../../Logos/Logo-showroom.png",
    height: 0.7em,
  ))
]
#show "logo_workshop": name => box[
  #box(image(
    "../../../Logos/Logo-workshop.png",
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
= What is the Scope & Objectives? logo_field
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
= How the current state measures up to standard?logo_lib logo_field
The current state of the system is in acceptable condition, though it is far from the final product that is to be used by end users for any kind of scientific research

= What is the desired state? logo_field
The desired state of the system is it being able to carry payload from an Opentron pipetting robot to a Tecan plate analyzer, without collision. The arm must be aware of its positioning in 3D space and calibrate itself to compensate for changes of space, distance and position.
= What are the gaps? logo_lib logo_field
From the point we find ourselves in, point A, we must reach point B, which would be the desired state of the product by the end of the project.

#figure(
  image(
    "../../../Tables and diagrams/Project_Timeline.drawio.png",
  ),
  caption: [Base project trajectory],
)<basetr>

Now as seen in @basetr, the arm is currently in a functioning state. UFactory supplies their robots with a Python API and a development environment, to write software for the robot arm. It has a built-in simulator and can communicate with the real hardware with minimal latency. The current problem lies in trajectory planning, because the process is not automated by default and the developers must make it happen. Fortunetly, built-in security protocols against collision exist in the default pipeline. Lastly, for trajectory planning , operating the arm using ROS would be beneficial, since it contains libraries for it, which makes the development process simpler. The caveat being that the arm needs to be set up to work with ROS. Now the project's trajectory would become much larger.

#figure(
  image("../../../Tables and diagrams/Updated_project_timeline.drawio.png"),
  caption: [Trajectory in more detail],
)<updtr>

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
    [Critical],
    [Gap that requires immediate attention and is essential to be done, usually more complex problems that require more time.],
    [2 weeks],
    [
      + No environment for ROS, nor simulation.
      + No ROS support.
    ],
    //Row 2
    [High],
    [Gaps that are in high priority and are to be addressed as quick as possible.],
    [1 week],
    [
      + No trajectory planning implemented.
    ],
    // Row 3
    [Medium],
    [Gaps that are lesser priority than high and but attention is not needed immediately.],
    [less than a week],
    [],
    // Row 4
    [Low], [Gaps that need to be closed the last(after medium priority gaps)], [less than half a week], [],
  ),
  caption: [Priority Matrix],
)<prmatrix>
= What do I recommend?
I recommend to start addressing the development environment and simulation for ROS. Then move onto trajectory planning solutions

= Appendix <appendix>

= Bibliography


== DOT table
In this document, you will see icons such as  logo_field, without any follow-up text like Python. This is done to maximize information output with minimal lexical hindrance.

The following table explains all DOT research methods and combines them with their icon so that the reader may easily find and reference. The aim of the DOT symbols specifically is to show what research methods were involved without cluttering the text with unnecessary noise and to avoid repetition.
The descriptions are taken from the official source #link("https://ictresearchmethods.nl/")[(click here)].
Please study the table to learn about the symbols used herein:

#table(
  columns: 3,
  [*DOT Method*], [*Description*], [*Symbol*],
  inset: 10pt,

  // Row 1
  [Library],
  ["Library research is done to explore what is already done and what guidelines and theories exist that could help you further your design. Since the advent of the internet library research is also called desk research."],
  [logo_lib],

  // Row 2
  [Field],
  ["Field research is done to explore the application context. You apply a field strategy to get to know your end users, their needs, desires and limitations as organizational and physical contexts in which they will use your product."],
  [logo_field],

  // Row 3
  [Lab],
  ["Lab research is done to test your ideas with the users of your product. You use lab research to learn if things work out the way you intended them."],
  [logo_lab],

  // Row 4
  [Showroom],
  ["Showroom research is done to test your ideas in relation to existing work. Showing your prototype to experts can be a form of showroom research or spelling out how your product is different from the competition."],
  [logo_showroom],

  // Row 5
  [Workshop],
  ["Workshop research is done to explore opportunities. Prototyping, sketching and co-creation activities are all ways to gain insights in what is possible and how things could work."],
  [logo_workshop],
)

