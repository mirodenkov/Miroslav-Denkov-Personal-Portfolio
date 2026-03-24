#set page("a4")
#set heading(numbering: "1. ")
#set text(font: "Times New Roman")


#align(center, text(size: 20pt)[Trajectory Planning])
#align(center,text(size:17.5pt)[Author: Miroslav Denkov])

#outline(title: "Table of Contents")
#line(length: 100%)

#let appendix(body) = {
  set heading(numbering: "A", supplement: [Appendix])
  counter(heading).update(0)
  body
}
#set heading(numbering: "1")
= Abstract
= Introduction
 
= Conclusion
For more info, see @app1. 

#show: appendix

= Sources <app1>
= Tables and Data <app2>

#outline(target: heading.where(supplement: [Appendix]), title: [Appendix])