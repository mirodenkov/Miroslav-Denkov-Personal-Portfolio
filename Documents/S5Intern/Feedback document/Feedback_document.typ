#set page("a4")
#set heading(numbering: "1. ")
#set text(font: "Times New Roman", size: 16.5pt)
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

#figure(
  table(
    columns: 4,
    table.header()[Date][Version][Changes][Status],
    [18/03/2026], [1],[ - Added feedpulse trail],[Draft],
  ),
  caption: [Change log],
)<changelog>

= Introduction
In this document a trail of any feedback received will be documented and reflected upon. Expect the document to be updated regularly as new feedback is received. For changes refer to
#text[#highlight[@changelog]].

#text(size: 18pt)[]
= Peer Feedback collection
To be added
= First Assesor Feedback collection
To be added
= Final conclusions
Final reflection will be added after all evidence is collected, the document will be updated.