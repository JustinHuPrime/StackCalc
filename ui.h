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