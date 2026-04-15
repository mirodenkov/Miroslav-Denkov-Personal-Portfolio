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
#heading(
  numbering: none,
  outlined: false,
  level: 1,
)[Trajectory Planning for the UFactory Lite 6 Robot Arm via the Official Python SDK]
#heading(numbering: none, outlined: false, level: 2)[Author: Miroslav Denkov]
#outline(title: align(left, text(size: 14pt)[Table of Contents]))
#line(length: 100%)


= Abstract

= Introduction
This document aims to shed light on the workflow and intricacies involved in writing software used to for trajectory planning and job execution for the _UFactory Robot arm_, model _Lite 6_. We will be looking at it from the context of the Big Chemistry project. In the following chapters, you will notice the different types of DOT research methods that come into play for the duration of the project's task.
= What is UFactory Lite 6 Robot arm?logo_lib logo_field
As the name suggests, the machine is a mechanized non-humanoid arm that is operated with manufacturer's own software or can be programatically set to execute instructions using, again, a Standard Development Kit from UFactory(manufacturer). The program instructions are written in Python and UFactory provides a web interface that connect's to the arm's server, which includes a Python IDE, and allows a developer to write logic for the robot, much like how one would write software for an Arduino, using their API.

= Why the Lite 6?logo_field logo_lib
The job of the arm is to transport low-weight payload(a small spot plate) from an logo_opentronsOpentrons Pippeting Robot, to a Tecan Spark plate reader. The scientists that will use this setup for their daily lab activites must have reliable equipment that allows them to handle chemical substances with great care.
The Lite 6 model is one of the best budget options UFactory provides and its low-weight payload handling(up to 600 grams) is a great match for what the robot's function will be.All with having a cost of 4200\$ for an entire set(gripper, vacuum gripper etc.),quite cheap compared to other models.

As mentioned above, UFactory also provides users with a Python SDK that allows engineers to control and automate arm functions with code.
The SDK can be accessed through the SDK(by setting up a Python virtual environment). Additionally, the software is open-source and transparent and can be accessed by anyone from UFactory's website, leading to their Github page. 

= How the Python SDK can be leveraged for trajecotry planning for UFactory Lite 6?logo_lib logo_field logo_lab


= Conclusion

= Appendix

== DOT Framework symbols
In this document, you will see icons such as  logo_field, without any follow-up text like Python. This is done to maximize information output with minimal lexical hindrance.

The following table explains all DOT research methods and combines them with their icon so that the reader may easily find and reference. The aim of the DOT symbols specifically is to show what research methods were involved without cluttering the text with unnecessary noise and to avoid repetition.
The descriptions are taken from the official #link("https://ictresearchmethods.nl/")[source].
Please study the table to learn about the symbols used herein:

#table(
  columns: 3,
  [*DOT Method*], [*Description*], [*Symbol*],
  inset: 10pt,

  // Row 1
  [Library], ["Library research is done to explore what is already done and what guidelines and theories exist that could help you further your design. Since the advent of the internet library research is also called desk research."], [logo_lib],

  // Row 2
  [Field], ["Field research is done to explore the application context. You apply a field strategy to get to know your end users, their needs, desires and limitations as organizational and physical contexts in which they will use your product."], [logo_field],

  // Row 3
  [Lab], ["Lab research is done to test your ideas with the users of your product. You use lab research to learn if things work out the way you intended them."], [logo_lab],

  // Row 4
  [Showroom], ["Showroom research is done to test your ideas in relation to existing work. Showing your prototype to experts can be a form of showroom research or spelling out how your product is different from the competition."], [logo_showroom],

  // Row 5
  [Workshop], ["Workshop research is done to explore opportunities. Prototyping, sketching and co-creation activities are all ways to gain insights in what is possible and how things could work."], [logo_workshop],
)

== Bibliography 
#bibliography("references.bib", title: none )
#cite(<vogel_ict>)






