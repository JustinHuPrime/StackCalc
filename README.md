# StackCalc

Stack based command line interface calculator.

This program comes with ABSOLUTELY NO WARRANTY. This is free software, and you are welcome to redistribute it under certain conditions. For more detail see the  LICENSE file that should have been included with this program.

## Getting Started

This calculator is written in C++17, and compiled using g++. However, this project should be able to be built on any system. The included makefile is set up to compile the interpreter on a Linux/Unix-like system using g++.

### Prerequisites

This project requires ncurses, and that's it.

## Using the Calculator

The calculator does not take command line arguments. Within the calculator, the calculator allows you to enter a number as a decimal, and also recognizes some control keys:

* q: quits the calculator
* p: raises the first number to the power of the second. The first number is the one closer to the active end of the stack
* +, -, *, /: performs an arithmetic operation, with the first being the right hand side
* DEL: drops one element from the stack
* UP: swaps the positions of the first and second elements

## Copyright

Copyright 2018 [Justin Hu](mailto:justin.hu@alumni.ubc.ca).