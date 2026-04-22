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
#show heading.where(numbering: none, level: 1): it => align(center, text(size: 24pt, it.body))
#show heading.where(numbering: none, level: 2): it => align(center, text(size: 20pt, it.body))
#heading(numbering: none, outlined: false, level: 1)[Stakeholder Analysis]
#heading(numbering: none, outlined: false, level: 2)[Author: Miroslav Denkov]
#outline(title: align(left, text(size: 14pt)[Table of Contents]))
#text()[= Introduction]


In this document you will find information on stakeholders and their connection to the project. You will find stakeholders and their expectations at @shtable

= Project Description
The project itself consists of the development of a Python API to control the robot arm. The arm must be able to plan its trajectory without colliding with external equipment. The stakeholders want to know if ROS2 could be leveraged for this task.

#figure(image("Lite6.png", width: 65%), caption: [UFactory Robot arm model Lite 6])<rtarm>



= Stakeholder table

#figure(
  table(
    columns: 4,
    table.header[Name][Role][Description][Expectations],

    [Joris Geurts], [Company Mentor], [Mentor and educator in the Robotlab at Fontys ICT. ], [He is to provide guidance and feedback during the course of the project and make sure the intern's solutions stay in line of the project's goals],
  
  ),
  caption: [Stakeholder Table],
)<shtable>
NB: For project requirements and details refer to Project Plan and Requirements Document.

= What solution would be logical for stakeholders?logo_field logo_lib
Stakeholders desire for this robot to be used in an automated lab environment. UFactory provides software solutions for writing code for the arm and integrating it in various scenarios and circumstances(see #link("@appendix")[Appendix] for citations).
\
Investigating the Python SDK and ROS packages, shipping from UFactory would be the most logical solution, from there building a practical solution would follow.

= Appendix <appendix>

== Bibliography
HBO-i. “ICT Research Methods — Methods Pack for Research in ICT.” ICT Research Methods, https://ictresearchmethods.nl/. Accessed 22 Apr. 2026.
\
xArm-Developer/xArm-Python-SDK. 21 Nov. 2018, Python. UFACTORY, 16 Apr. 2026. GitHub, https://github.com/xArm-Developer/xArm-Python-SDK.
\
xArm-Developer/Xarm_ros2. 15 June 2021, Python. UFACTORY, 21 Apr. 2026. GitHub, https://github.com/xArm-Developer/xarm_ros2.


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





