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
#heading(numbering: none, outlined: false, level: 1)[Stakeholder Analysis]
#heading(numbering: none, outlined: false, level: 2)[Author: Miroslav Denkov]
#outline(title: align(left, text(size: 14pt)[Table of Contents]))
#text()[= Introduction]


In this document you will find information on stakeholders and their connection to the project.
As such please follow the table below.

= Project Description
The project itself consists of the development of a Python API to control the robot arm. The arm must be able to plan its trajectory without colliding with external equipment. The stakeholders want to know if ROS2 could be leveraged for this task.

#figure(image("Lite6.png", width: 65%), caption: [UFactory Robot arm model Lite 6])<rtarm>



= Stakeholder table

#table(
  columns: 4,
  table.header[Name][Role][Description][Expectations],
  [Miroslav Denkov],
  [Developer],
  [*Myself,* the author of this document and the developer working on this project.],
  [],

  [Joris Geurts], [Company Mentor], [], [],
  [Fontys ICT ], [Stakeholder], [], [],
)
