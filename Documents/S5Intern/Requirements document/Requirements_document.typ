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
#heading(numbering: none, outlined: false, level: 1)[Requirments document]
#heading(numbering: none, outlined: false, level: 2)[Author: Miroslav Denkov]
#outline(title: align(left, text(size: 14pt)[Table of Contents]))
#line(length: 100%)

#figure(
  table(
    columns: 4,
    table.header()[Date][Version][Changes][Status],
    [18/03/2026], [1], [- Created document], [Draft],
  ),
  caption: [Change log],
)<changelog>

= Introduction
This document serves the purpose of providing information in the requirements of the project, to be developed by Miroslav Denkov(author of this document).
= Assignment Description
The assignment consists in the continuation of a self-developed API protocol for controlling the Ufactory Lite 6 robot arm. The arm should be able to execute its tasks without making collisions with the other equipment in the lab. The arm must be able to walk through its trajectory unempeded. The demonstration includes the arm calibrateing itself and pick up the small plastic boxes, where the solutions would be placed. The Technologies involved are trajectory planning, inverse kinematics,Intermachine Communication, ROS2 framework and Python.

= Scope
#figure(
  table(
    columns: 2,
    table.header()[The Project includes][The project does not include],
    [Research on ROS2 and similar technology], [Explicit development on SILA2],
    [Decision and consultation with backed-up evicence on which techonolgy is better-suited for the task at hand.],
    [Works on connecting the other equipment],

    [Implementation of path trajectory algorithm using either default tooling or ROS2], [],
    [Demonstration of the robotarm’s capabilities to safely deliver payload from point A to B.], [],
  ),
  caption: [Project Scope],
)<ProjectScope>
= Requirements
#figure(
  table(
    columns: 2,
    table.header()[Functional Requirements][Non-functional Requirements],
    //Cell 1x1
    [
      - The arm must be able to position itself(calibration).
      - The arm must NOT collide with surrounding equipment or itself(over-reaching).
      - The arm must be able to find its trajectory.
      - The arm must pick the small container up and put it on its destination.
    ],
    //Cell 1x2
    [
      - A conclusion towards tooling. Should the default tooling from Ufactory or ROS framework be used?
      - Conclude if it is beneficial to use ROS2’s MoveIT library for trajectory planning(Part of ROS framework implementation experiments).
      - Conclude what calibration implementation would be the most beneficial. QR-target-based or something else.
      - Version control with Git.
      - Research topics with DOT.
    ],

  ),
  caption: [Functional and Non-functional requirements],
)<FuncAndNonfuncReq>

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
