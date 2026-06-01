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
#show heading.where(numbering: none, level: 3): it => align(center, text(size: 16pt, it.body))
#heading(numbering: none, outlined: false, level: 1)[Project Report]
#heading(numbering: none, outlined: false, level: 2)[Author: Miroslav Denkov]
#heading(numbering: none, outlined: false, level: 3)[Project: Robotarm]
#set heading(numbering: "1. ")
#outline(title: align(left, text(size: 14pt)[Table of Contents]))

#line(length: 100%)

= Abstract

= Introduction
What you are seeing here is the final project report for Miroslav Denkov, now working as an intern at Fontys ICT Research. The project consists of developing a trajectory solution for a UFactory Robot arm; model Lite 6. 


= Conclusions

= Appendix
== DOT table
== Citations