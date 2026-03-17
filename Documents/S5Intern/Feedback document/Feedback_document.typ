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
#heading(numbering: none, outlined: false, level: 1)[Feedback document]
#heading(numbering: none, outlined: false, level: 2)[Author: Miroslav Denkov]
#heading(numbering: none, outlined: false, level: 3)[Project: Robotarm]
#set heading(numbering: "1. ")
#outline(title: align(left, text(size: 14pt)[Table of Contents]))

#line(length: 100%)

= Introduction

= Feedpulse Feedback

= Peer Feedback

= First Assesor Feedback

= Final conclusions