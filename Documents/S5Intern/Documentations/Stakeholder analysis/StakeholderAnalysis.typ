#set page("a4")
#set heading(numbering: "1. ")
#set text(font: "Times New Roman", size: 14pt)
#set outline(title: [Table of Contents], indent: auto)
#set par(justify:true)
#let gay(content) = {
  set text(fill: gradient.linear(..color.map.rainbow))
  box(content)
}

#text(size: 16pt, font:"JetBrains Mono NL")[
  #align(center)[
    #heading(outlined: false, numbering:none)[Stakeholder Analysis]
  ]
]

#text(font: "Times New Roman", size: 12pt)[
  #outline()
]

= Introduction
#lorem(3)

= Methods
#lorem(15)
Dot Framework blablabla.
== Setup
#lorem(10)
#figure(image("San_Francisco_Bay_Day.png", width: 90%), caption:[
  #text(fill:red)[San]
  #text(fill:green)[Francisco]
  #text(fill: blue, style: "italic", )[Bay]
  during the #gay[day]

])<SF>
If you are #gay[gay] refer to @SF.

