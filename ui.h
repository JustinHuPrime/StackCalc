// Copyright 2018 Justin Hu
//
// This file is part of StackCalc.
//
// StackCalc is free software: you can redistribute it and / or modify it under
// the terms of the GNU General Public License as published by the Free Software
// Foundation, either version 3 of the License, or (at your option) any later
// version.
//
// StackCalc is distributed in the hope that it will be useful, but WITHOUT ANY
// WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR
// A PARTICULAR PURPOSE.  See the GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License along with
// StackCalc.  If not, see <https://www.gnu.org/licenses/>.

#ifndef UI_H
#define UI_H

#include "numberStack.h"
#include <string>
using std::string;
using CustomADT::NumberStack;

void init (); //initializes ncurses
void uninit (); //ends ncurses
void draw (const NumberStack&, const string&); //draws the stack area
void drawPrompt (const string&); //updates the prompt
void drawError ();

#endif /* UI_H */